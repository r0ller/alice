package hi.pkg;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

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
    private native byte[] jhi(String text);
    private WebView mWebView;
    private String commandScript;
    private byte[] commandBytes;
    
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
            copyAsset(am,"english.fst",toPath+"/english.fst");
            copyAsset(am,"hi.db",toPath+"/hi.db");
//            Log.i("Files", "Path: " + toPath);
//            File cwd = new File(toPath);
//            File file[] = cwd.listFiles();
//            if(file.length==0) Log.i("hi","no files found");
//            for (int i=0; i < file.length; i++)
//            {
//                Log.i("Files", "FileName:" + file[i].getName());
//            }
        } catch (PackageManager.NameNotFoundException e) {
            Log.w("hi", "Error: Package name not found ", e);
        }
    }

    @Override
    public void onClick(View v){
//    	commandBytes=jhi("list contacts with peter\n");
//    	if(commandBytes!=null){
//		    try{
//		    	commandScript=new String(commandBytes,"UTF-8");
//		    }
//		    catch(UnsupportedEncodingException e){
//		    	Log.e("utf8", "conversion", e);
//		    }
//		  	((TextView)findViewById(R.id.text2)).setText(commandScript);
//			mWebView.loadData("<html><head></head><body></body></html>","text/html", "UTF-8");
//    	}
    	Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
             i.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, "en-US");
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
            		ArrayList<String> command = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
            		((TextView)findViewById(R.id.text1)).setText(command.get(0));
            		commandBytes=jhi(command.get(0)+"\n");
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
        }
}
