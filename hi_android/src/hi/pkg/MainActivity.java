package hi.pkg;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Date;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
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

public class MainActivity extends Activity implements OnClickListener {
    private native byte[] jhi(String text, String language, byte[] error);
    private WebView mWebView;
    private String commandScript;
    private byte[] commandBytes;
    private String recognisedText;
    private ArrayList<String> recognisedTexts;
    private int nrOfTrials=0;
    private String commandPartOk;

    static {
    	System.loadLibrary("sqlite");
    	System.loadLibrary("foma");
        System.loadLibrary("hilib");
        System.loadLibrary("jhi");
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
        setContentView(R.layout.activity_main);
        findViewById(R.id.button1).setOnClickListener(this);
        mWebView = (WebView) findViewById(R.id.webview);
        mWebView.getSettings().setJavaScriptEnabled(true);
        mWebView.addJavascriptInterface(new jsi(this), "Android");
        mWebView.setWebChromeClient(new WebChromeClient());
		mWebView.setWebViewClient(new WebViewClient(){
			@Override
		    public void onPageFinished(WebView view, String url){   
//		        view.loadUrl("javascript:Android.execute();");
        		view.loadUrl("javascript:"+commandScript);
		    }           
		});
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
	  protected void onNewIntent(Intent intent) {
		  if (intent!=null && intent.getExtras()!=null) {
		    String lid=intent.getStringExtra("LID");
//		    Toast.makeText(this, "LID:"+lid, Toast.LENGTH_LONG).show();
		    if(nrOfTrials>0){
		    	if(lid.contentEquals("HUN")==true){
		    		if(recognisedText.contains("betűvel")==true||recognisedText.contains("szóval")==true){
			    		String trimmedInput=recognisedText.replace("betűvel","");
			    		trimmedInput=recognisedText.replace("szóval","");
			    		trimmedInput=recognisedText.replace(" ","");
			    		if(trimmedInput.isEmpty()==false){
				    		ArrayList<Integer> spellStarts=new ArrayList<Integer>();
			    			int spellStart=recognisedText.indexOf("betűvel");
				    		while(spellStart<recognisedText.length()&&spellStart!=-1){
				    			spellStarts.add(spellStart);
				    			spellStart=recognisedText.indexOf("betűvel",spellStart+"betűvel".length());
				    		}
				    		ArrayList<Integer> spellEnds=new ArrayList<Integer>();
				    		int spellEnd=recognisedText.indexOf("szóval");
				    		while(spellEnd<recognisedText.length()&&spellEnd!=-1){
				    			spellEnds.add(spellEnd);
				    			spellEnd=recognisedText.indexOf("szóval",spellEnd+"szóval".length());
				    		}
				    		if(spellStarts.isEmpty()==true&&spellEnds.isEmpty()==false){
				    			trimmedInput=recognisedText.replace("szóval","");
				    			while(trimmedInput.contentEquals(trimmedInput.replace("  "," "))==false){
				    				trimmedInput=trimmedInput.replace("  "," ");
				    			}
				    		}
				    		else if(spellStarts.isEmpty()==false&&spellEnds.isEmpty()==true){
				    			trimmedInput=recognisedText.replace("betűvel","");
				    			while(trimmedInput.contentEquals(trimmedInput.replace("  "," "))==false){
				    				trimmedInput=trimmedInput.replace("  "," ");
				    			}
				    			if(trimmedInput.startsWith(" ")==true) trimmedInput=trimmedInput.substring(1);
				    			if(trimmedInput.endsWith(" ")==false) trimmedInput+=" ";
				    			int nrOfLettersCut=0;
				    			int nextSpace=0;
				    			while(nextSpace>=0&&nrOfLettersCut+1<trimmedInput.length()){
					    			nextSpace=trimmedInput.indexOf(" ",nrOfLettersCut+1);
			    					if(nrOfLettersCut>0) trimmedInput=trimmedInput.substring(0,nrOfLettersCut)+trimmedInput.charAt(nrOfLettersCut+1)+trimmedInput.substring(nextSpace);
			    					else trimmedInput=trimmedInput.charAt(0)+trimmedInput.substring(nextSpace);
				    				++nrOfLettersCut;
				    			}
				    			recognisedText=commandPartOk+" "+trimmedInput;
				    		}
				    		else if(spellStarts.isEmpty()==false&&spellEnds.isEmpty()==false||spellStarts.isEmpty()==true&&spellEnds.isEmpty()==true){
						    	//TODO: implement alternating sections of spelled and worded text, do nothing for the time being
				    			recognisedText=commandPartOk+" "+recognisedText;
				    		}
			    		}
		    		}
		    		else{
				    	recognisedText=commandPartOk+" "+recognisedText;
		    		}
		    	}
		    	else{
		    		recognisedText=commandPartOk+" "+recognisedText;
		    	}
		    }
		    Toast.makeText(this, "command:"+recognisedText, Toast.LENGTH_LONG).show();
		    byte[] error= new byte[1024];
		    commandBytes=jhi(recognisedText+"\n",lid,error);
		    try{
			    String errortext=new String(error,"UTF-8");
			    Toast.makeText(this, "error:"+errortext, Toast.LENGTH_LONG).show();
			    if(errortext.contains("/")==true){
				    ++nrOfTrials;
				    String okPart=errortext.substring(0,errortext.indexOf("/"));
//				    Toast.makeText(this, "okPart:"+okPart, Toast.LENGTH_LONG).show();
				    commandPartOk=recognisedText.substring(0,recognisedText.indexOf(okPart)+okPart.length());
//				    Toast.makeText(this, "Ok:"+commandPartOk, Toast.LENGTH_LONG).show();

//beginSilentDebug
//				    recognisedText="betűvel aladár levente ilona zoltán tibor";
////			    	recognisedTexts.add(command);//TODO:check why this makes the app dump
//					((TextView)findViewById(R.id.text1)).setText(recognisedText);
//			    	//Get default (primary) language set for voice input 
//			        Intent i = new Intent(RecognizerIntent.ACTION_GET_LANGUAGE_DETAILS);
//			        LanguageChecker langCheckerBroadcastReceiver=LanguageChecker.getInstance();
//			        sendOrderedBroadcast(i, null, langCheckerBroadcastReceiver, null, Activity.RESULT_OK, null, null);
//endSilentDebug

				    Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
			    	try {
			    		startActivityForResult(i, REQUEST_OK);
			        } catch (Exception e) {
			        	Toast.makeText(this, "Error initializing speech to text engine.", Toast.LENGTH_LONG).show();
			        }
			    }
		    }
		    catch(UnsupportedEncodingException e){
		    	Log.e("utf8", "conversion", e);
		    }
			if(commandBytes!=null){
			    try{
			    	commandScript=new String(commandBytes,"UTF-8");
			    }
			    catch(UnsupportedEncodingException e){
			    	Log.e("utf8", "conversion", e);
			    }
				((TextView)findViewById(R.id.text2)).setText(commandScript);
		    	mWebView.loadData("<html><head></head><body></body></html>","text/html", "UTF-8");
		    }
	    }
	    else {
	  	    Toast.makeText(this, "LID unknown", Toast.LENGTH_LONG).show();
	    }
	    super.onNewIntent(intent);
	  }

//	  @Override
//	  protected void onResume() { 
//	    super.onResume();   
//	    if (getIntent()!=null && getIntent().getExtras()!=null) {
//	    	Toast.makeText(this, "onResume:"+getIntent().getExtras().getString("LID"), Toast.LENGTH_LONG).show();
//	    }
//	      else {
//	  	    Toast.makeText(this, "onResume:empty", Toast.LENGTH_LONG).show();
//	    }
//	  }

//	  public ArrayList<String> getRecognisedTexts(){
//		  return recognisedTexts;
//	  }

	@Override
    public void onClick(View v){
//beginSilentDebug
//		nrOfTrials=0;
//		recognisedText="hívd fel a liszt";
////    	recognisedTexts.add(command);//TODO:check why this makes the app dump
//		((TextView)findViewById(R.id.text1)).setText(recognisedText);
//    	//Get default (primary) language set for voice input 
//        Intent intent = new Intent(RecognizerIntent.ACTION_GET_LANGUAGE_DETAILS);
//        LanguageChecker langCheckerBroadcastReceiver=LanguageChecker.getInstance();
//        sendOrderedBroadcast(intent, null, langCheckerBroadcastReceiver, null, Activity.RESULT_OK, null, null);
//endSilentDebug

		nrOfTrials=0;
		Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
    	try {
    		startActivityForResult(i, REQUEST_OK);
        } catch (Exception e) {
        	Toast.makeText(this, "Error initializing speech to text engine.", Toast.LENGTH_LONG).show();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
            super.onActivityResult(requestCode, resultCode, data);
            if (requestCode==REQUEST_OK  && resultCode==RESULT_OK) {
            	recognisedTexts=data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
            	recognisedText=recognisedTexts.get(0);
        		((TextView)findViewById(R.id.text1)).setText(recognisedText);
            	//Get default (primary) language set for voice input 
                Intent intent = new Intent(RecognizerIntent.ACTION_GET_LANGUAGE_DETAILS);
                LanguageChecker langCheckerBroadcastReceiver=LanguageChecker.getInstance();
                sendOrderedBroadcast(intent, null, langCheckerBroadcastReceiver, null, Activity.RESULT_OK, null, null);
            }
        }
}
