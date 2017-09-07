package com.bitroller.hi;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.TextView;
import android.widget.Toast;
import android.content.BroadcastReceiver;
import android.content.IntentFilter;
import android.text.method.ScrollingMovementMethod;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

public class MainActivity extends Activity implements OnClickListener {
    private native byte[] jhi(String text, String language, byte[] error);
    private WebView mWebView;
    private String commandScript;
    private byte[] commandBytes;
    private String recognisedText="";
    private ArrayList<String> recognisedTexts;
    private String commandPartOk="";
    private static Context context;
	private BroadcastReceiver mBroadcastReceiver;

    static {
//    	System.loadLibrary("sqlite");
    	System.loadLibrary("foma");
        System.loadLibrary("hilib");
        System.loadLibrary("jhi");
    }

    public static Context getContext(){
    	return context;
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
		((TextView)findViewById(R.id.texter)).setMovementMethod(new ScrollingMovementMethod());
        findViewById(R.id.texter).setOnClickListener(this);
        mWebView = (WebView) findViewById(R.id.webview);
        mWebView.getSettings().setJavaScriptEnabled(true);
        mWebView.getSettings().setDefaultTextEncodingName("UTF-8");
        mWebView.addJavascriptInterface(new jsi(this), "Android");
        mWebView.setWebChromeClient(new WebChromeClient());
		mWebView.setWebViewClient(new WebViewClient());
		if(mBroadcastReceiver==null){
			mBroadcastReceiver=new BroadcastReceiver(){
				@Override
				public void onReceive(Context context, Intent intent){
					if(intent!=null&&intent.hasExtra("setText")==true){
						((TextView)findViewById(R.id.texter)).append(intent.getStringExtra("setText")+"\n\n");
					}
				}
			};
		}
        PackageManager m = getPackageManager();
        String s = getPackageName();
        try {
            PackageInfo p = m.getPackageInfo(s, 0);
            String toPath = p.applicationInfo.dataDir;
            AssetManager am = getAssets();
           	String[] assetsPath = am.list("");
           	if(assetsPath==null) finishAffinity();
           	String assetPath="";
           	for(String assetIterator : assetsPath){
           	    if(assetIterator.contentEquals("hi.db")){
           	    	assetPath=assetIterator;
//                   	File dbAsset=getFileStreamPath(assetPath);
//                   	if(dbAsset.exists()==false) finishAffinity();
//                   	Date dbAssetLastModified=new Date(dbAsset.lastModified());
//                   	File dbDataDir=getFileStreamPath(toPath+"/hi.db");
//                   	if(dbDataDir.exists()==false) finishAffinity();
//                   	Date dbDataDirLastModified=new Date(dbDataDir.lastModified());
//                   	if(dbDataDirLastModified.before(dbAssetLastModified)==true){
                   		copyAsset(am,"hi.db",toPath+"/hi.db");
//                   	}
           	        break;
           	    }
           	}
           	if(assetPath.isEmpty()==true) finishAffinity();
           	assetPath="";
           	for(String assetIterator : assetsPath){
           	    if(assetIterator.endsWith(".fst")==true){
           	    	assetPath=assetIterator;
//                   	File fstAsset=getFileStreamPath(assetPath);
//                   	if(fstAsset.exists()==false) finishAffinity();
//                   	Date fstAssetLastModified=new Date(fstAsset.lastModified());
                   	String fstName=assetPath;//As assetsPath was set to empty string "", it lists purely the file names and assetPath contains that
//                   	File fstDataDir=getFileStreamPath(toPath+fstName);
//                   	if(fstDataDir.exists()==true){
//	                   	Date fstDataDirLastModified=new Date(fstDataDir.lastModified());
//	                   	if(fstDataDirLastModified.before(fstAssetLastModified)==true){
	                   		//TODO: open hi.db as asset and copy not only *.fst files but the ones configured in the customizing table
	                   		copyAsset(am,fstName.substring(0),toPath+"/"+fstName);
//	                   	}
//                   	}
//                   	else{
//                   		//TODO: open hi.db as asset and copy not only *.fst files but the ones configured in the customizing table
//                   		copyAsset(am,fstName.substring(1),toPath+fstName);
//                   	}
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
		triggerSpeechRecoginzer();
	}

	public void onResume() {
		super.onResume();
		IntentFilter intentFilter = new IntentFilter("hiBroadcast");
		registerReceiver(mBroadcastReceiver,intentFilter);
	}

	public void onPause() {
		super.onPause();
		unregisterReceiver(mBroadcastReceiver);
	}

	@Override
	  protected void onNewIntent(Intent intent) {
		  if (intent!=null && intent.getExtras()!=null){
//			  Bundle extras=intent.getExtras();
//			  for(String key : extras.keySet()){
//				  extras.getCharSequence(key);
//			  }
			  if(intent.hasExtra("lid")==true){
				  String lid=intent.getStringExtra("lid");
//				    Toast.makeText(this, "LID:"+lid, Toast.LENGTH_LONG).show();
					if(lid.contentEquals("HUN")==true){
						recognisedText=recognisedText.toLowerCase();
						if(recognisedText.matches(".*\\d.*")==true){
							ArrayList<huNumHandler> handlers=huNumHandler.getNumbers(recognisedText);
							for(huNumHandler handler:handlers){
								String textToReplace=" "+handler.number()+" "+handler.suffix();
								String textToInsert=" "+handler.numText()+" ";
								recognisedText=recognisedText.replace(textToReplace,textToInsert);
							}
							((TextView)findViewById(R.id.texter)).append(recognisedText+"\n\n");
						}
						if(commandPartOk.isEmpty()==false) {
							if (recognisedText.startsWith("betűvel") == true && recognisedText.length() > "betűvel".length()) {
								String trimmedInput = recognisedText.substring(7);
								trimmedInput = trimmedInput.replace("  ", " ");
								int spaceIndex = trimmedInput.indexOf(' ');
								String letters = new String();
								while (spaceIndex >= 0 && spaceIndex < trimmedInput.length()) {
									letters += trimmedInput.charAt(++spaceIndex);
									spaceIndex = trimmedInput.indexOf(' ', spaceIndex);
								}
								if (letters.isEmpty() == false) {
									if(commandPartOk.endsWith(" a")==true||commandPartOk.endsWith(" az")==true){
										commandPartOk=commandPartOk.substring(0,commandPartOk.lastIndexOf(" a"));
									}
									recognisedText = commandPartOk + " " + letters;
								}
							}
							else if(recognisedText.startsWith("mondom") == true && recognisedText.length() > "mondom".length()) {
								String trimmedInput = recognisedText.substring(6);
								if(commandPartOk.endsWith(" a")==true||commandPartOk.endsWith(" az")==true){
									commandPartOk=commandPartOk.substring(0,commandPartOk.lastIndexOf(" a"));
								}
								recognisedText = commandPartOk + trimmedInput;
							}
							else if(recognisedText.contains("első")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("1)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("második")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("2)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("harmadik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("3)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("negyedik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("4)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("ötödik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("5)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("hatodik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("6)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("hetedik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("7)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("nyolcadik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("8)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("kilencedik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("9)")+2;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
							else if(recognisedText.contains("tizedik")==true){
								String texter=((TextView)findViewById(R.id.texter)).getText().toString();
								int numberIndex=texter.lastIndexOf("10)")+3;
								String phoneNumber=texter.substring(numberIndex,texter.indexOf('\n',numberIndex)-1);
								Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
								callIntent.setData(Uri.parse("tel:" + phoneNumber));
								startActivity(callIntent);
								recognisedText="";
							}
						}
					}
					if(recognisedText.isEmpty()==false) {
						byte[] error = new byte[1024];
						//Toast.makeText(this, "command:"+recognisedText, Toast.LENGTH_LONG).show();
						commandBytes = jhi(recognisedText + "\n", lid, error);
						try {
							if (commandBytes != null) {
								commandPartOk = "";
								commandScript = new String(commandBytes, "UTF-8");
								//Just for debugging, show the script to be executed
								//((TextView)findViewById(R.id.texter)).append(commandScript+"\n\n");
								mWebView.loadData("<html><head></head><body><script type=\"text/javascript\">" + commandScript + "</script></body></html>", "text/html; charset=UTF-8", "UTF-8");
							} else if (error[0] != 0) {
								String errortext = new String(error, "UTF-8");
								//Toast.makeText(this, "error:" + errortext, Toast.LENGTH_LONG).show();
								if (errortext.contains("/") == true) {
									String okPart = errortext.substring(0, errortext.indexOf("/"));
									String errorPart = errortext.substring(errortext.indexOf("/") + 1, errortext.indexOf(0));
									//						    Toast.makeText(this, "okPart:"+okPart, Toast.LENGTH_LONG).show();
									commandPartOk = recognisedText.substring(0, recognisedText.indexOf(okPart) + okPart.length());
									//						    Toast.makeText(this, "Ok:"+commandPartOk, Toast.LENGTH_LONG).show();
									((TextView) findViewById(R.id.texter)).append("Ennyit értettem:\n" + okPart + "\n\n" + "Ezt nem:\n" + errorPart + "\n\n");
								}
							}
						} catch (UnsupportedEncodingException e) {
							Log.e("utf8", "conversion", e);
						}
					}
			  }
			  else if(intent.hasExtra("repeat")==true){
				  String toRepeat=intent.getStringExtra("repeat");
				  while(recognisedText.contains(toRepeat)==false&&toRepeat.isEmpty()==false){
					  toRepeat=toRepeat.substring(0,toRepeat.length()-1);
				  }
				  if(toRepeat.isEmpty()==false) {
					  commandPartOk = recognisedText.substring(0, recognisedText.indexOf(toRepeat));
					  commandPartOk = commandPartOk.replaceAll(" +$", "");
				  }
				  else commandPartOk="";
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
//		if(commandPartOk.isEmpty()==true||recognisedText.isEmpty()==true) recognisedText="hívd fel leventét";
//		else recognisedText="mondom leventét";
//		((TextView)findViewById(R.id.texter)).append(recognisedText+"\n\n");
//        Intent intent = new Intent(RecognizerIntent.ACTION_GET_LANGUAGE_DETAILS);//Get default (primary) language set for voice input
//        LanguageChecker langCheckerBroadcastReceiver=LanguageChecker.getInstance();
//        sendOrderedBroadcast(intent, null, langCheckerBroadcastReceiver, null, Activity.RESULT_OK, null, null);
//endSilentDebug

//beginNormalDebug
		Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
		i.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
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
                LanguageChecker langCheckerBroadcastReceiver=LanguageChecker.getInstance();
                sendOrderedBroadcast(intent, null, langCheckerBroadcastReceiver, null, Activity.RESULT_OK, null, null);
            }
        }
}
