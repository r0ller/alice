package com.bitroller.hi;

import android.Manifest;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.content.res.AssetManager;
import android.graphics.Point;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.LocalBroadcastManager;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;
import android.content.BroadcastReceiver;
import android.content.IntentFilter;
import android.text.method.ScrollingMovementMethod;

import org.json.JSONObject;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.zip.ZipFile;

public class MainActivity extends Activity implements OnClickListener {
	private static final int PERMISSION_REQUEST_READ_CONTACTS = 1;
	private static final int PERMISSION_REQUEST_CALL_PHONE = 2;

	private native byte[] jhi(String text, String language, String dbUri);
    private WebView mWebView;
    private jsi jsi=null;
    private String commandScript;
    private byte[] commandBytes=null;
    private String recognisedText="";
	private String lastFailure="";
    private ArrayList<String> recognisedTexts;
    private static Context context;
    private String dataDir="";
    private AnalysisParser analysisParser=null;
	private BroadcastReceiver mBroadcastReceiver = new BroadcastReceiver(){
		@Override
		public void onReceive(Context context, Intent intent){
			if(intent!=null&&intent.hasExtra("setText")==true){
				setText(intent.getStringExtra("setText"));
			}
		}
	};

    static {
//    	System.loadLibrary("sqlite");
    	System.loadLibrary("foma");
        System.loadLibrary("hilib");
        System.loadLibrary("jhi");
    }

    public static Context getContext(){
    	return context;
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
			if(dbModified.before(BuildConfig.buildTime)==true||dbModified==new Date(0)){
				copyAsset(am, "hi.db", toPath + "/hi.db");
			}
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
		triggerSpeechRecoginzer();
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
						if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN"){
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
						if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN"){
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
					if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN"){
						setText("Bocs, ezt még most sem tudom értelmezni.");
					}
					else{
						setText("Sorry, I still can't interpret it.");
					}
				}
				if(LanguageChecker.getInstance().getDefaultLanguage()=="HUN"){
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
					commandBytes = jhi(recognisedText + "\n", LanguageChecker.getInstance().getDefaultLanguage(),dataDir+"/hi.db");
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
							if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN"){
								setText("Bocs, ezt nem tudtam értelmezni.");
							}
							else{
								setText("Sorry, couldn't interpret it.");
							}
							if(message.length()>0) setText(message.toString());
						}
					} else{
						lastFailure=oText;
						if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN"){
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

	private void triggerSpeechRecoginzer(){
//beginSilentDebug
//		if(recognisedText.isEmpty()==true) recognisedText="keress névjegyeket robival";
//		((TextView)findViewById(R.id.texter)).append(recognisedText+"\n\n");
//        Intent intent = new Intent(RecognizerIntent.ACTION_GET_LANGUAGE_DETAILS);//Get default (primary) language set for voice input
//		PackageManager pm=getPackageManager();
//		List<ResolveInfo> matches=pm.queryBroadcastReceivers(intent, 0);
//		if(matches!=null&&matches.isEmpty()==false) {
//			ResolveInfo intentResolver = matches.get(0);//matches is sorted from best to worst, so take the best
//			ComponentName cn=new ComponentName(intentResolver.activityInfo.applicationInfo.packageName,intentResolver.activityInfo.name);
//			intent.setComponent(cn);
//			intent.putExtra(RecognizerIntent.EXTRA_ONLY_RETURN_LANGUAGE_PREFERENCE, true);
//			LanguageChecker langCheckerBroadcastReceiver = LanguageChecker.getInstance();
//			sendOrderedBroadcast(intent, null, langCheckerBroadcastReceiver, null, Activity.RESULT_OK, null, null);
//		}
//		else{
//			Toast.makeText(this, "Error: the intent ACTION_GET_LANGUAGE_DETAILS could not be resolved.", Toast.LENGTH_LONG).show();
//		}
//endSilentDebug

//beginNormalDebug
		Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
		i.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
		i.putExtra(RecognizerIntent.EXTRA_PREFER_OFFLINE, true);
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
			Intent intent = new Intent(RecognizerIntent.ACTION_GET_LANGUAGE_DETAILS);//Get default (primary) language set for voice input
			//This is a workaround needed for Android Oreo and above to set the component name for the intent
			//otherwise the intent won't be correctly resolved and the broadcastreceiver will get as a result only null.
			//Fortunately, this does not seem to break backward compatibility for <8.0 systems.
			//https://stackoverflow.com/questions/48653654/sendorderedbroadcast-setpackage-requirement-in-oreo
			PackageManager pm=getPackageManager();
			List<ResolveInfo> matches=pm.queryBroadcastReceivers(intent, 0);
			if(matches!=null&&matches.isEmpty()==false) {
				ResolveInfo intentResolver = matches.get(0);//matches is sorted from best to worst, so take the best
				ComponentName cn = new ComponentName(intentResolver.activityInfo.applicationInfo.packageName, intentResolver.activityInfo.name);
				intent.setComponent(cn);
				intent.putExtra(RecognizerIntent.EXTRA_ONLY_RETURN_LANGUAGE_PREFERENCE, true);
				LanguageChecker langCheckerBroadcastReceiver = LanguageChecker.getInstance();
				sendOrderedBroadcast(intent, null, langCheckerBroadcastReceiver, null, Activity.RESULT_OK, null, null);
			}
			else{
				Toast.makeText(this, "Error: the intent ACTION_GET_LANGUAGE_DETAILS could not be resolved.", Toast.LENGTH_LONG).show();
			}
		}
	}

	@Override
	public void onRequestPermissionsResult(int requestCode, String permissions[], int[] grantResults) {
		switch (requestCode) {
			case PERMISSION_REQUEST_READ_CONTACTS: {
				// If request is cancelled, the result arrays are empty.
				if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
					if(ContextCompat.checkSelfPermission(this, Manifest.permission.CALL_PHONE)!= PackageManager.PERMISSION_GRANTED){
						ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CALL_PHONE}, PERMISSION_REQUEST_CALL_PHONE);
					}
					else {
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
					if(ContextCompat.checkSelfPermission(this, Manifest.permission.READ_CONTACTS)!= PackageManager.PERMISSION_GRANTED){
						ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.READ_CONTACTS}, PERMISSION_REQUEST_READ_CONTACTS);
					}
					else {
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
		}
	}

}
