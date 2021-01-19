package com.bitroller.hi;

import android.Manifest;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
import android.graphics.Point;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.LocalBroadcastManager;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.ScrollView;
import android.widget.TextView;
import android.content.BroadcastReceiver;
import android.content.IntentFilter;
import android.text.method.ScrollingMovementMethod;
import android.widget.Toast;

import org.json.JSONObject;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedHashMap;
import java.util.Map;

public class MainActivity extends Activity implements OnClickListener {
	private static final int PERMISSION_REQUEST_READ_CONTACTS = 1;
	private static final int PERMISSION_REQUEST_CALL_PHONE = 2;
	private static final int PERMISSION_REQUEST_SEND_SMS = 3;
	private static final int PERMISSION_REQUEST_READ_PHONE_STATE = 4;

	private native byte[] jhi(String text, String language, String dbUri);
    private static WebView mWebView;
    private jsi jsi=null;
    private String commandScript;
    private byte[] commandBytes=null;
    private static String recognisedText="";
    private static String originalText="";
	private String lastFailure="";
    private ArrayList<String> recognisedTexts;
    private static Context context;
    private String dataDir="";
    private AnalysisParser analysisParser=null;
    private Menu optionsMenu;
	private BroadcastReceiver mBroadcastReceiver = new BroadcastReceiver(){
		@Override
		public void onReceive(Context context, Intent intent){
			if(intent!=null&&intent.hasExtra("setText")==true){
				setText(intent.getStringExtra("setText"));
			}
		}
	};

	public static String getRecognisedText(){
		return recognisedText;
	}

	public static String getOriginalText(){
		return originalText;
	}

	static {
		try {
			//Native libraries must have SONAME, check:
			//readelf --dynamic libWithSoName.so | grep SONAME
			//If not, crosscompile them on the native platform with: -Wl,-soname,libWithSoName.so
			//Native libraries must not have path in their names, only filename, check:
			//readelf --dynamic libSample.so | grep NEEDED
			//Native libraries must not have relocated text, check:
			//readelf --dynamic libTextRel.so | grep TEXTREL
			//Native libraries must have (non zero) section headers, check:
			//readelf --header libBroken.so | grep 'section headers'
//    		System.loadLibrary("sqlite");
    		System.loadLibrary("foma");
    		System.loadLibrary("hilib");
			System.loadLibrary("jhi");
		}
		catch (java.lang.UnsatisfiedLinkError e){
			e.getMessage();
		}
    }

    public static Context getContext(){
    	return context;
    }

	public static WebView getWebView(){
		return mWebView;
	}

	private void setText(String message){
		((TextView)findViewById(R.id.texter)).append(message+"\n\n");
		final ScrollView scroll=(ScrollView)findViewById(R.id.content_scroll);
		scroll.post(new Runnable() {
			@Override
			public void run() {
				scroll.fullScroll(View.FOCUS_DOWN);
			}
		});

	}

	private static boolean copyAssetFolder(AssetManager assetManager,
             String fromAssetPath, String toPath) {
         try {
             String[] files = assetManager.list(fromAssetPath);
             new File(toPath).mkdirs();
             boolean res = true;
             for (String file : files){
                 if (file.contains("."))
                     res &= copyAsset(assetManager, 
                             fromAssetPath + "/" + file,
                             toPath + "/" + file);
                 else 
                     res &= copyAssetFolder(assetManager, 
                             fromAssetPath + "/" + file,
                             toPath + "/" + file);
             }
             return res;
         } catch (Exception e) {
             e.printStackTrace();
             return false;
         }
     }

     private static boolean copyAsset(AssetManager assetManager,
             String fromAssetPath, String toPath) {
         InputStream in = null;
         OutputStream out = null;
         try {
           in = assetManager.open(fromAssetPath);
           new File(toPath).createNewFile();
           out = new FileOutputStream(toPath);
           copyFile(in, out);
           in.close();
           in = null;
           out.flush();
           out.close();
           out = null;
           return true;
         } catch(Exception e) {
             e.printStackTrace();
             return false;
         }
     }

     private static void copyFile(InputStream in, OutputStream out) throws IOException {
         byte[] buffer = new byte[1024];
         int read;
         while((read = in.read(buffer)) != -1){
           out.write(buffer, 0, read);
         }
     }

    protected static final int REQUEST_OK = 1;
    @SuppressLint("SetJavaScriptEnabled")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	context=this;
        setContentView(R.layout.activity_main);
        TextView texter=(TextView)findViewById(R.id.texter);
		getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
		Point size = new Point();
		getWindowManager().getDefaultDisplay().getSize(size);
		//((TextView)findViewById(R.id.texter)).setHeight(size.y); ->automatic scrolling to bottom does not work with this
		int minLines=size.y/(texter.getLineHeight()*(int)texter.getLineSpacingMultiplier()+(int)texter.getLineSpacingExtra());
		((TextView)findViewById(R.id.texter)).setMinLines(minLines);
		((TextView)findViewById(R.id.texter)).setMovementMethod(new ScrollingMovementMethod());
        findViewById(R.id.texter).setOnClickListener(this);
        mWebView = (WebView) findViewById(R.id.webview);
        mWebView.getSettings().setJavaScriptEnabled(true);
		mWebView.getSettings().setDomStorageEnabled(true);
        mWebView.getSettings().setDefaultTextEncodingName("UTF-8");
        jsi=new jsi(this);
        mWebView.addJavascriptInterface(jsi, "Android");
        mWebView.setWebChromeClient(new WebChromeClient());
		mWebView.setWebViewClient(new WebViewClient());
        PackageManager m = getPackageManager();
        String s = getPackageName();
        try {
            PackageInfo p = m.getPackageInfo(s, 0);
			dataDir=p.applicationInfo.dataDir;
            String toPath = dataDir;
			File cwd = new File(toPath);
			File file[] = cwd.listFiles();
			Map<String,Long> fstModified=new LinkedHashMap<String,Long>();
			Date dbModified=new Date(0);
            for (int i=0; i < file.length; i++)
            {
                if(file[i].getName().endsWith(".fst")==true) fstModified.put(file[i].getName(),file[i].lastModified());
				if(file[i].getName().contentEquals("hi.db")==true) dbModified=new Date(file[i].lastModified());
            }
            AssetManager am = getAssets();
           	String[] assetsPath = am.list("");
           	if(assetsPath==null) finishAffinity();
			//if(dbModified==new Date(0)){
			//if(dbModified==new Date(0)){
			if(dbModified.before(BuildConfig.buildTime)==true||dbModified==new Date(0)){
				copyAsset(am, "hi.db", toPath + "/hi.db");
			}
			DatabaseHelper hiDb=new DatabaseHelper();
			hiDb.open("hi.db");
			String[] dbTables=hiDb.exec_sql("SELECT name FROM sqlite_master WHERE type='table' AND name='{settings}';");
			if(dbTables==null){
				hiDb.exec_sql("CREATE TABLE settings(key text primary key,value text);");
				if(hiDb.error_message()!=null){
					finishAffinity();
				}
				hiDb.exec_sql("INSERT INTO settings values('language','en-US');");
				if(hiDb.error_message()!=null){
					finishAffinity();
				}
			}
			hiDb.close();
			String assetPath="";
			for (String assetIterator : assetsPath) {
				if (assetIterator.endsWith(".fst") == true) {
					assetPath = assetIterator;
					String fstName = assetPath;//As assetsPath was set to empty string "", it lists purely the file names and assetPath contains that
					Date fstLastModified=new Date(0);
					if(fstModified.containsKey(fstName)==true) fstLastModified=new Date(fstModified.get(fstName));
					if(fstLastModified.before(BuildConfig.buildTime)==true||fstLastModified==new Date(0)){
					//TODO: open hi.db as asset and copy not only *.fst files but the ones configured in the customizing table
						copyAsset(am, fstName, toPath + "/" + fstName);
					}
				}
			}
			if(assetPath.isEmpty()==true) finishAffinity();
//            Log.i("Files", "Path: " + toPath);
//            File cwd = new File(toPath);
//            File file[] = cwd.listFiles();
//            if(file.length==0) Log.i("hi","no files found");
//            for (int i=0; i < file.length; i++)
//            {
//                Log.i("Files", "FileName:" + file[i].getName());
//            }
        }
        catch (PackageManager.NameNotFoundException e) {
            Log.w("hi", "Error: Package name not found ", e);
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

	@Override
	public void onStart() {
		super.onStart();
		registerReceiver(mBroadcastReceiver,new IntentFilter("hiBroadcast"));
		jsi.registerLocalBroadcastReceiver();
//		if(ContextCompat.checkSelfPermission(this, Manifest.permission.RECORD_AUDIO)!= PackageManager.PERMISSION_GRANTED) {
//			ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.RECORD_AUDIO}, PERMISSION_REQUEST_RECORD_AUDIO);
//		}
		triggerSpeechRecoginzer();
//		//test new web scenario: nyisd meg a freemail.hu oldalt
//		mWebView.setWebViewClient(new WebViewClient() {
//			@Override
//			public void onReceivedError(WebView view, WebResourceRequest request, WebResourceError error) {
//				//TODO: Handle error
//			}
//			@Override
//			public void onReceivedHttpError(WebView view, WebResourceRequest request, WebResourceResponse errorResponse){
//				//TODO: Handle error
//			}
//			@Override
//			public boolean shouldOverrideUrlLoading(WebView view, String url) {//TODO: String url got deprecated in api level 24, need to differentiate
//				view.loadUrl(url);
//				return false;
//			}
//			@Override
//			public void onPageFinished(WebView view, String url) {
//				super.onPageFinished(view, url);
//				//https://stackoverflow.com/questions/59037366/how-to-convert-htmlcollection-to-string
//				String js="(function() { var inputList=document.getElementsByTagName('input');inputArray=Array.from(inputList);var inputJSON={};for(var i=0;i<inputArray.length;++i){inputJSON['i'+i]=inputArray[i].outerHTML;} return JSON.stringify(inputJSON); })();";
////				String js="(function() { return 'this'; })();";
//				view.evaluateJavascript(js, new ValueCallback<String>() {
//					@Override
//					public void onReceiveValue(String s) {
//						//https://stackoverflow.com/questions/19788294/how-does-evaluatejavascript-work
////						JsonReader reader = new JsonReader(new StringReader(s));
////						// Must set lenient to parse single values
////						reader.setLenient(true);
////						try {
////							if(reader.peek() != JsonToken.NULL) {
////								if(reader.peek() == JsonToken.STRING) {
////									String msg = reader.nextString();
////									if(msg != null) {
////										//Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_LONG).show();
////										setText(msg);
////									}
////								}
////							}
////						} catch (IOException e) {
////							Log.e("TAG", "MainActivity: IOException", e);
////						} finally {
////							try {
////								reader.close();
////							} catch (IOException e) {
////								// NOOP
////							}
////						}
//					setText(s);
//					}
//				});
////				view.loadUrl(js);
//			}
//		});
//		mWebView.loadUrl("http://freemail.hu");
	}

	public void onResume() {
		super.onResume();
	}

	public void onPause() {
		super.onPause();
	}

	public void onStop() {
		super.onStop();
		unregisterReceiver(mBroadcastReceiver);
		jsi.unregisterLocalBroadcastReceiver();
	}

	@Override
	protected void onNewIntent(Intent intent) {
		if (intent!=null && intent.getExtras()!=null){
			//Bundle extras=intent.getExtras();
			//for(String key : extras.keySet()){
			//extras.getCharSequence(key);
			//}
			if(intent.hasExtra("tryagain")==true && intent.getStringExtra("tryagain").contentEquals("true")){
				recognisedText=recognisedText.toLowerCase();
				String oText=recognisedText;
				if(intent.hasExtra("prependWord")==true){
					String prependedFailure=intent.getStringExtra("prependWord")+" "+lastFailure;
					if(recognisedText.contentEquals(prependedFailure)==true) recognisedText="";
					else recognisedText=intent.getStringExtra("prependWord")+" "+recognisedText;
				}
				else if(intent.hasExtra("nextAnalysis")==true&&analysisParser!=null){
					StringBuilder message=new StringBuilder();
					commandScript=analysisParser.getCommandScript(message);
					if(commandScript.isEmpty()==false) {
						if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
							setText("Várj, egy másik elemzést még megpróbálok.");
						}
						else{
							setText("Wait, I'll try yet another analysis.");
						}
						mWebView.loadData("<html><head></head><body><script type=\"text/javascript\">" + commandScript + "</script></body></html>", "text/html; charset=UTF-8", "UTF-8");
						super.onNewIntent(intent);
						return;
					}
					else{
						//lastFailure=oText;
						analysisParser=null;
						recognisedText="";
						if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
							setText("Bocs, ezt nem tudtam értelmezni.");
						}
						else{
							setText("Sorry, couldn't interpret it.");
						}
						if(message.length()>0) setText(message.toString());
					}
				}
				else if(recognisedText.isEmpty()==false&&recognisedText.contentEquals(lastFailure)==true){
					recognisedText="";
					if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
						setText("Bocs, ezt még most sem tudom értelmezni.");
					}
					else{
						setText("Sorry, I still can't interpret it.");
					}
				}
				if(LanguageChecker.getInstance().getDefaultLanguage()=="hu-HU"){
					if(recognisedText.matches(".*\\d.*")==true){
						ArrayList<huNumHandler> handlers=huNumHandler.getNumbers(recognisedText);
						for(huNumHandler handler:handlers){
							String textToReplace=" "+handler.number()+" "+handler.suffix();
							String textToInsert=" "+handler.numText()+" ";
							recognisedText=recognisedText.replace(textToReplace,textToInsert);
						}
						if(recognisedText.matches(".*\\d$")==true){
							ArrayList<huNumHandler> endNumHandler=huNumHandler.getNumbers(recognisedText);
							for(huNumHandler handler:endNumHandler){
								String textToReplace=" "+handler.number();
								String textToInsert=" "+handler.numText();
								recognisedText=recognisedText.replace(textToReplace,textToInsert);
							}
						}
						//((TextView)findViewById(R.id.texter)).append(recognisedText+"\n\n");
					}
					else if(recognisedText.indexOf(" hogy ")>0){
						originalText=recognisedText;
						recognisedText=recognisedText.substring(0,recognisedText.indexOf(" hogy "));
						recognisedText+=" hogy x";
					}
				}
				String trimmedInput = recognisedText;
				trimmedInput = trimmedInput.replace("  ", " ");
				String spelledLetters=trimmedInput.replaceAll(" ","");
				if(spelledLetters.length()==trimmedInput.length()-spelledLetters.length()+1){
					recognisedText=spelledLetters;
					oText=recognisedText;
				}
				if(recognisedText.isEmpty()==false){
					if(recognisedText.contentEquals(oText)==false) setText(recognisedText);
					String language;
					if(LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") {
						language = "HUN";
					}
					else language = "ENG";
					commandBytes = jhi(recognisedText + "\n", language,dataDir+"/hi.db");
				}
				try {
					if (commandBytes != null) {
						commandScript = new String(commandBytes, "UTF-8");
						commandBytes=null;
						//Just for debugging, show the script to be executed
						//((TextView)findViewById(R.id.texter)).append(commandScript+"\n\n");
						JSONObject analyses=new JSONObject(commandScript);
						analysisParser=new AnalysisParser(analyses);
						StringBuilder message=new StringBuilder();
						commandScript=analysisParser.getCommandScript(message);
						if(commandScript.isEmpty()==false) {
							mWebView.loadData("<html><head></head><body><script type=\"text/javascript\">" + commandScript + "</script></body></html>", "text/html; charset=UTF-8", "UTF-8");
						}
						else{
							lastFailure=oText;
							if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
								setText("Bocs, ezt nem tudtam értelmezni.");
							}
							else{
								setText("Sorry, couldn't interpret it.");
							}
							if(message.length()>0) setText(message.toString());
						}
					} else{
						lastFailure=oText;
						if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
							setText("Bocs, ezt nem értettem.");
						}
						else{
							setText("Sorry, didn't get it.");
						}
					}
				}
				catch (UnsupportedEncodingException e) {
					Log.e("utf8", "conversion", e);
				}
				catch (org.json.JSONException e){
					Log.e("utf8", "conversion", e);
				}
			}
		}
		super.onNewIntent(intent);
	}

	@Override
    public void onClick(View v) {
		triggerSpeechRecoginzer();
	}

	public boolean onCreateOptionsMenu(Menu menu) {
    	optionsMenu=menu;
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.main, menu);
		String language=LanguageChecker.getInstance().getDefaultLanguage();
		if(language=="hu-HU"){
			optionsMenu.findItem(R.id.hu_HU).setChecked(true);
		}
		else if(language=="en-GB"){
			optionsMenu.findItem(R.id.en_GB).setChecked(true);
		}
		else{
			optionsMenu.findItem(R.id.en_US).setChecked(true);
		}
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		recognisedText="";
		lastFailure="";
		for(int i=0;i<optionsMenu.size();++i){
			optionsMenu.getItem(i).setChecked(false);
		}
		switch (item.getItemId()) {
			case R.id.en_GB:
				item.setChecked(true);
				LanguageChecker.getInstance().setLanguage("en-GB");
				return true;
			case R.id.en_US:
				item.setChecked(true);
				LanguageChecker.getInstance().setLanguage("en-US");
				return true;
			case R.id.hu_HU:
				item.setChecked(true);
				LanguageChecker.getInstance().setLanguage("hu-HU");
				return true;
			default:
				return super.onOptionsItemSelected(item);
		}
	}

	private void triggerSpeechRecoginzer(){
//beginSilentDebug
//		LanguageChecker.getInstance().setLanguage("hu-HU");
//		if(recognisedText.isEmpty()==true) recognisedText="üzenem péternek hogy búék";
//		((TextView)findViewById(R.id.texter)).append(recognisedText+"\n\n");
//		Intent callingIntent = new Intent(context, MainActivity.class);
//		callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
//		callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
//		callingIntent.putExtra("tryagain", "true");
//		context.startActivity(callingIntent);
//endSilentDebug

//beginNormalDebug
		Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
		i.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
		//Turn off offline voice recognition due to returning a misleading network error
		//on certain devices even when there's network access:
		//https://support.google.com/assistant/thread/2438314?hl=en
////		i.putExtra(RecognizerIntent.EXTRA_PREFER_OFFLINE, true);
		i.putExtra(RecognizerIntent.EXTRA_LANGUAGE, LanguageChecker.getInstance().getDefaultLanguage());
    	try {
    		startActivityForResult(i, REQUEST_OK);
        } catch (Exception e) {
			Toast.makeText(this, "Error initializing speech to text engine.", Toast.LENGTH_LONG).show();
		}
//endNormalDebug
	}

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		if (requestCode==REQUEST_OK  && resultCode==RESULT_OK) {
			recognisedTexts=data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
			recognisedText=recognisedTexts.get(0);
			((TextView)findViewById(R.id.texter)).append(recognisedText+"\n\n");
			Intent callingIntent = new Intent(context, MainActivity.class);
			callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
			callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
			callingIntent.putExtra("tryagain", "true");
			context.startActivity(callingIntent);
		}
	}

	@Override
	public void onRequestPermissionsResult(int requestCode, String permissions[], int[] grantResults) {
//	TODO: add RECORD_AUDIO permission handling
		switch (requestCode) {
			case PERMISSION_REQUEST_READ_CONTACTS: {
				// If request is cancelled, the result arrays are empty.
				if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
					if (ContextCompat.checkSelfPermission(this, Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {
						ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CALL_PHONE}, PERMISSION_REQUEST_CALL_PHONE);
					} else {
						Intent intent = new Intent("jsi_permission");
						intent.putExtra("granted", "read_contacts");
						LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
					}

				} else {

					// permission denied, boo! Disable the
					// functionality that depends on this permission.
				}
				return;
			}
			case PERMISSION_REQUEST_CALL_PHONE: {
				if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
					if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_CONTACTS) != PackageManager.PERMISSION_GRANTED) {
						ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.READ_CONTACTS}, PERMISSION_REQUEST_READ_CONTACTS);
					} else {
						Intent intent = new Intent("jsi_permission");
						intent.putExtra("granted", "call_phone");
						LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
					}

				} else {

					// permission denied, boo! Disable the
					// functionality that depends on this permission.
				}
				return;
			}
			case PERMISSION_REQUEST_SEND_SMS: {
				if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
					if (ContextCompat.checkSelfPermission(this, Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED) {
						ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.SEND_SMS}, PERMISSION_REQUEST_SEND_SMS);
					} else {
						Intent intent = new Intent("jsi_permission");
						intent.putExtra("granted", "send_sms");
						LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
					}

				} else {

					// permission denied, boo! Disable the
					// functionality that depends on this permission.
				}
				return;
			}
			case PERMISSION_REQUEST_READ_PHONE_STATE: {
				if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
					if (ContextCompat.checkSelfPermission(this, Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED) {
						ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.READ_PHONE_STATE}, PERMISSION_REQUEST_READ_PHONE_STATE);
					} else {
						Intent intent = new Intent("jsi_permission");
						intent.putExtra("granted", "read_phone_state");
						LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
					}

				} else {

					// permission denied, boo! Disable the
					// functionality that depends on this permission.
				}
				return;
			}
		}
	}

}
