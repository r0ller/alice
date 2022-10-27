package com.bitroller.hi;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
import android.net.Uri;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.util.Log;
import android.webkit.ConsoleMessage;
import android.webkit.WebChromeClient;
import android.webkit.WebMessage;
import android.webkit.WebMessagePort;
import android.webkit.WebResourceRequest;
import android.webkit.WebResourceResponse;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UTFDataFormatException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedHashMap;
import java.util.Map;

/*import org.mozilla.geckoview.GeckoResult;
import org.mozilla.geckoview.GeckoRuntime;
import org.mozilla.geckoview.GeckoRuntimeSettings;
import org.mozilla.geckoview.GeckoSession;
import org.mozilla.geckoview.GeckoView;
import org.mozilla.geckoview.WebExtension;
import org.mozilla.geckoview.WebExtensionController;*/

public class MainActivity extends AppCompatActivity {
    //Concept for MainActivity is to make a singleton of it as much as possible since only one activity
    //is needed to display webview that presents the Qt UI.
    //1. in manifest, set android:launchMode="singleTask" (?singleInstance, singleTop?)
    //2. set all app specific variables to static (private or public as needed) to make sure that each instance uses the same state of the app
    //3. set all app specific public methods to static to be able to call them from other classes instead of the intent broadcasting mess
    private static final int PERMISSION_REQUEST_READ_CONTACTS = 1;
    private static final int PERMISSION_REQUEST_CALL_PHONE = 2;
    private static final int PERMISSION_REQUEST_SEND_SMS = 3;
    private static final int PERMISSION_REQUEST_READ_PHONE_STATE = 4;
    //type of analysis flags (toa):
    public static final int HI_MORPHOLOGY = 1;
    public static final int HI_SYNTAX = 2;
    public static final int HI_SEMANTICS = 4;
    //contextual reference handling (crh) flags:
    public static final int HI_VERB = 1;
    public static final int HI_PRONOUN = 2;
    private static native byte[] jhi(String text, String language, String dbUri, int toa, int crh);//added static
    private static native byte[] jhi_transcribe(String analyses);//added static
    private static WebView mWebView;
    private static jsi jsi=null;//added static
    private static boolean qmlInitDone=false;//added static
    private static Context context;
    private static WebMessagePort port;//added static
    private static boolean testspeaker=false;//added static
    protected static final int REQUEST_OK = 1;
    private static ActivityResultLauncher<Intent> mStartActivityForResult;//added private static
    private static ArrayList<String> recognisedTexts;//added static
    private static String recognisedText="";
    private static String lastFailure="";//added static
    private static AnalysisParser analysisParser=null;//added static
    private static String commandScript;//added static
    private static String originalSendMsgText="";
    private static byte[] commandBytes=null;//added static
    private static String dataDir="";//added static
    private static JSONObject msg;//added private static
    public static int toa=HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS;
    public static int crh=0;

    /*private GeckoView mWebView;
    private GeckoSession session;
    private static GeckoRuntime runtime;
    private WebExtension.Port mPort;*/

    private BroadcastReceiver mBroadcastReceiver = new BroadcastReceiver(){
        @Override
        public void onReceive(Context context, Intent intent){
            if(intent!=null&&intent.hasExtra("setText")==true){
                setText("hi",intent.getStringExtra("setText"));
            }
        }
    };

    public static String getRecognisedText(){
        return recognisedText;
    }

    public static String getOriginalSendMsgText(){
        return originalSendMsgText;
    }

    public static WebView getWebView(){
        return mWebView;
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
            System.loadLibrary("foma");
            //System.loadLibrary("hisqlite3");
            //System.loadLibrary("hilib");
            System.loadLibrary("jhi");
        }
        catch (java.lang.UnsatisfiedLinkError e){
            e.getMessage();
        }
    }

    private boolean copyAssetFolder(AssetManager assetManager, String fromAssetPath, String toPath) {
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

    private boolean copyAsset(AssetManager assetManager, String fromAssetPath, String toPath) {
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

    private void copyFile(InputStream in, OutputStream out) throws IOException {
        byte[] buffer = new byte[1024];
        int read;
        while((read = in.read(buffer)) != -1){
            out.write(buffer, 0, read);
        }
    }

    private void copyAssets(){
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
                long diff=dbModified.getTime()-BuildConfig.buildTime.getTime();
//				Toast.makeText(this, "diff:"+diff, Toast.LENGTH_LONG).show();
                copyAsset(am, "hi.db", toPath + "/hi.db");
                DatabaseHelper hiDb=new DatabaseHelper();
                hiDb.open("hi.db");
                String[] dbTables=hiDb.exec_sql("SELECT name FROM sqlite_master WHERE type='table' AND name='SETTINGS';");
                if(dbTables==null){
//					Toast.makeText(this, "creating settings", Toast.LENGTH_LONG).show();
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

    private void setupWebView(){
        mWebView = (WebView) findViewById(R.id.webview);
        mWebView = findViewById(R.id.webview);
        mWebView.getSettings().setJavaScriptEnabled(true);
        mWebView.setFocusableInTouchMode(false);//hide softkeyboard
        mWebView.setFocusable(false);//hide softkeyboard
        mWebView.setWebChromeClient(new WebChromeClient(){
            public boolean onConsoleMessage(ConsoleMessage cm) {
                if(cm.message().contentEquals("qml: started")&&qmlInitDone==false){
                    qmlInitDone = true;
                    final WebMessagePort[] channel=mWebView.createWebMessageChannel();

                    port=channel[0];
                    port.setWebMessageCallback(new WebMessagePort.WebMessageCallback() {
                        @Override
                        public void onMessage(WebMessagePort port, WebMessage message) {
                            Log.i("onMessage", message.getData());
                            //JSONObject jsonObject=new JSONObject();
                            try {
                                msg=new JSONObject(message.getData());
                                switch (msg.optJSONObject("params").getString("action")){//Android specific cases
                                    case "assertSend":
                                        //Log.i("hi",msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        jsi.assertSend(msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        break;
                                    case "call":
                                        //Log.i("hi",msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        jsi.call(msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        break;
                                    case "fetchContacts":
                                        //Log.i("hi",msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        jsi.fetchContacts(msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        break;
                                    case "openUrl":
                                        //Log.i("hi",msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        jsi.openUrl(msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        break;
                                    case "sendMessage":
                                        //Log.i("hi",msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString());
                                        //Log.i("hi",msg.getJSONObject("params").getJSONArray("actionParams").get(1).toString());
                                        jsi.sendMessage(msg.getJSONObject("params").getJSONArray("actionParams").get(0).toString(),msg.getJSONObject("params").getJSONArray("actionParams").get(1).toString());
                                        break;
                                    case "setSTTLanguage":
                                        String language=msg.optJSONObject("params").getString("language");
                                        LanguageChecker.getInstance().setLanguage(language);
                                        break;
                                    default://STT+interpreter
                                        //TODO: call STT
                                        triggerSpeechRecoginzer();
                                        //byte[] responseBytes=jhi("","","");
                                        //String response = new String(responseBytes, "UTF-8");
                                        //port.postMessage(new WebMessage(response));
                                        //jsonObject.put("text","test");
                                        //if(testspeaker==true){
                                        //jsonObject.put("speaker","hi");
                                        //testspeaker=false;
                                        //}
                                        //else{
                                        //jsonObject.put("speaker","you");
                                        //testspeaker=true;
                                        //}
                                }
                            } catch (JSONException e) {
                                e.printStackTrace();
                            }
                            //catch (UnsupportedEncodingException e) {
                            //    Log.e("utf8", "conversion", e);
                            //}
//                            port.postMessage(new WebMessage(jsonObject.toString()));
////                            byte[] responseBytes=callBackend(message.getData());
//                            byte[] responseBytes=jhi("","","");
//                            try{
//                                String response = new String(responseBytes, "UTF-8");
//                                port.postMessage(new WebMessage(response));
//                            }
//                            catch (UnsupportedEncodingException e) {
//                                Log.e("utf8", "conversion", e);
//                            }
                        }
                    });

                    mWebView.postWebMessage(new WebMessage("test", new WebMessagePort[]{channel[1]}), Uri.EMPTY);
                }
                Log.i("MyApplication", cm.message() + " -- From line "
                        + cm.lineNumber() + " of "
                        + cm.sourceId() );
                return true;
            }
        });
        mWebView.setWebViewClient(new WebViewClient(){
            @Override
            public void onPageFinished(WebView view, String url) {
            }
            @Override
            public WebResourceResponse shouldInterceptRequest(WebView view,WebResourceRequest request) {
                String path = request.getUrl().getLastPathSegment();

                try {
                    String mime;
                    AssetManager assetManager = getAssets();

                    if (path.endsWith(".html")) mime = "text/html";
                    else if (path.endsWith(".wasm")) mime = "application/wasm";
                    else if (path.endsWith(".js")) mime = "text/javascript";
                    else if (path.endsWith(".svg")) mime = "image/svg+xml";
                    else
                        return super.shouldInterceptRequest(view, request);

                    InputStream input = assetManager.open("www/" + path);
                    return new WebResourceResponse(mime, "utf-8", input);
                } catch (IOException e) {
                    e.printStackTrace();
                    ByteArrayInputStream result = new ByteArrayInputStream
                            (("X:" + path + " E:" + e.toString()).getBytes());
                    return new WebResourceResponse("text/plain", "utf-8", result);
                }
            }
        });
        //mWebView.loadData("<html><body>Hello World</body></html>", "text/html; charset=UTF-8", "UTF-8");
        //mWebView.loadUrl("file:///android_asset/hi_qml_ui.html");
        mWebView.loadUrl("https://appassets.androidplatform.net/hi_qml_ui.html");
    }

    private void setupGeckoView(){//does not work yet
/*
        //https://www.raywenderlich.com/1381698-android-tutorial-for-geckoview-getting-started
        //https://firefox-source-docs.mozilla.org/mobile/android/geckoview/consumer/web-extensions.html
        //background script:
        //https://searchfox.org/mozilla-central/source/mobile/android/examples/port_messaging_example/app/src/main/java/org/mozilla/geckoview/example/messaging/MainActivity.java
        //content script:
        //https://searchfox.org/mozilla-central/source/mobile/android/examples/messaging_example
        //the accepted answer suggests how to connect html, js and webextension:
        //https://stackoverflow.com/questions/63048951/native-messaging-with-web-content-using-geckoview-android
        mWebView = findViewById(R.id.geckoview);
        session = new GeckoSession();
        if(runtime==null) {
            GeckoRuntimeSettings settings=new GeckoRuntimeSettings.Builder().javaScriptEnabled(true).consoleOutput(true).build();
            runtime = GeckoRuntime.create(this,settings);
        }
        WebExtension.PortDelegate portDelegate = new WebExtension.PortDelegate() {
            @Override
            public void onPortMessage(final @NonNull Object message,
                                      final @NonNull WebExtension.Port port) {
                Log.d("PortDelegate", "Received message from extension: "
                        + message);
            }

            @Override
            public void onDisconnect(final @NonNull WebExtension.Port port) {
                // This port is not usable anymore.
                if (port == mPort) {
                    mPort = null;
                }
            }
        };

        WebExtension.MessageDelegate messageDelegate = new WebExtension.MessageDelegate() {
            @Override
            @Nullable
            public void onConnect(final @NonNull WebExtension.Port port) {
                mPort = port;
                mPort.setDelegate(portDelegate);
            }
        };


        runtime.getWebExtensionController()
                .ensureBuiltIn("resource://android/assets/www/", "messaging@example.com")
                .accept(
                        // Register message delegate for background script
                        extension -> extension.setMessageDelegate(messageDelegate, "com.bitroller.hi_qml"),
                        e -> Log.e("MessageDelegate", "Error registering WebExtension", e)
                );
        session.open(runtime);
        mWebView.setSession(session);
        session.loadUri("resource://android/assets/www/qmlwasm1.html");
*/
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //TODO: https://developer.android.com/guide/topics/search/search-dialog#ReceivingTheQuery
        //based on the action in the intent (Intent.ACTION_SEARCH.equals(i.getAction()))
        //it can be decided if the main activity was launched by voice or not.
        //Another possibility would be to create and trigger a different activity for the voice search
        //but it seems superfluous.
        context=this;
        jsi=new jsi(this);
        mStartActivityForResult = registerForActivityResult(new ActivityResultContracts.StartActivityForResult(),
                new ActivityResultCallback<ActivityResult>() {
                    @Override
                    public void onActivityResult(ActivityResult result) {
                        if (result.getResultCode() == Activity.RESULT_OK) {
                            Intent intent = result.getData();
                            recognisedTexts=intent.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
                            recognisedText=recognisedTexts.get(0);
                            interpret(recognisedText,toa,crh);
                            /*setText("you", recognisedText);
                            Intent callingIntent = new Intent(context, MainActivity.class);
                            callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
                            callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
                            callingIntent.putExtra("tryagain", "true");
                            context.startActivity(callingIntent);*/
                        }
                    }
                });
        //There are two ways to add a webview: in onCreate via setContentView or later by findViewById
        setContentView(R.layout.activity_main);
        copyAssets();
        setupWebView();
    }

    @Override
    public void onStart(){
        toa=HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS;
        crh=0;
        super.onStart();
    }

    @Override
    public void onStop(){
        toa=HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS;
        crh=0;
        super.onStop();
    }

    private void triggerSpeechRecoginzer(){
//beginSilentDebug
		//LanguageChecker.getInstance().setLanguage("en-US");
        LanguageChecker.getInstance().setLanguage("hu-HU");
        if(recognisedText.isEmpty()==true) recognisedText="üzenem péternek hogy tesztsms";
        else recognisedText="küldd";
        interpret(recognisedText,toa,crh);
		/*Intent callingIntent = new Intent(context, MainActivity.class);
		callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
		callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
        callingIntent.putExtra("action", msg.params.action);
		//callingIntent.putExtra("tryagain", "true");
		context.startActivity(callingIntent);*/
        //endSilentDebug

//beginNormalDebug
/*        Intent i = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        //TODO: add EXTRA_ENABLE_FORMATTING to get punctuation
        i.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
        //Turn off offline voice recognition due to returning a misleading network error
        //on certain devices even when there's network access:
        //https://support.google.com/assistant/thread/2438314?hl=en
////		i.putExtra(RecognizerIntent.EXTRA_PREFER_OFFLINE, true);
        i.putExtra(RecognizerIntent.EXTRA_LANGUAGE, "en-US");//LanguageChecker.getInstance().getDefaultLanguage());
        mStartActivityForResult.launch(i);
        //try {
            //startActivityForResult(i, REQUEST_OK);
        //} catch (Exception e) {
        //    Toast.makeText(this, "Error initializing speech to text engine.", Toast.LENGTH_LONG).show();
        //}
//endNormalDebug*/
    }

    private static String getScript(String recognisedText,int toa, int crh){
        String script="";
        String language="";
        if(LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") {
            language = "HUN";
        }
        else language = "ENG";
        byte[] analysesBytes = jhi(recognisedText + "\n", language,dataDir+"/hi.db",HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS,0);
        String analyses="";
        try{
            if (analysesBytes != null) {//if normal analysis succeeded
                analyses = new String(analysesBytes, "UTF-8");
                JSONObject jsonAnalyses = new JSONObject(analyses);
                if(jsonAnalyses.optJSONArray("errors")==null){
                    byte[] scriptBytes = jhi_transcribe(analyses);
                    if (scriptBytes != null) {
                        script = new String(scriptBytes, "UTF-8");
                    }
                }
                else{//check if there's a verb in the failed analyses morphology;
                    //if yes, try dependency semantics without crh
                    //if no, try dependency semantics with crh
                    boolean verbFound=false;
                    JSONArray morphology=jsonAnalyses.getJSONArray("morphology");
                    for(int i=0;i<morphology.length();++i){
                        String gcat=morphology.getJSONObject(i).get("gcat").toString();
                        if(gcat.contentEquals("V")||gcat.contentEquals("Verb")){
                            verbFound=true;
                            break;
                        }
                    }
                    if(verbFound==true){
                        analysesBytes = jhi(recognisedText + "\n", language,dataDir+"/hi.db",HI_MORPHOLOGY|HI_SEMANTICS,0);
                        analyses="";
                        if (analysesBytes != null) {
                            analyses = new String(analysesBytes, "UTF-8");
                            jsonAnalyses = new JSONObject(analyses);
                            if(jsonAnalyses.optJSONArray("errors")==null){
                                byte[] scriptBytes = jhi_transcribe(analyses);
                                if (scriptBytes != null) {
                                    script = new String(scriptBytes, "UTF-8");
                                }
                            }
                        }
                    }
                    else{
                        analysesBytes = jhi(recognisedText + "\n", language,dataDir+"/hi.db",HI_MORPHOLOGY|HI_SEMANTICS,HI_VERB);
                        analyses="";
                        if (analysesBytes != null) {
                            analyses = new String(analysesBytes, "UTF-8");
                            jsonAnalyses = new JSONObject(analyses);
                            if(jsonAnalyses.optJSONArray("errors")==null){
                                byte[] scriptBytes = jhi_transcribe(analyses);
                                if (scriptBytes != null) {
                                    script = new String(scriptBytes, "UTF-8");
                                }
                            }
                        }
                    }
                }
            }
        }
        catch (UnsupportedEncodingException | JSONException e) {
            Log.e("utf8", "conversion", e);
        }
        return script;
    }

    public static void interpret(String recognisedText,int toa, int crh){
        setText("you", recognisedText);
        if(LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") {
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
            }
            else{
                if(recognisedText.indexOf(" hogy ")>0){
                    originalSendMsgText=recognisedText;
                    //remove message part as it's irrelevant from the analysis point of view
                    recognisedText=recognisedText.substring(0,recognisedText.indexOf(" hogy "));
                    //add 'x' as mock message otherwise the sentence w/o the removed message would be incorrect
                    recognisedText+=" hogy x";
                }
                else originalSendMsgText="";
            }
        }
        MainActivity.recognisedText=recognisedText;
        String script=getScript(recognisedText,toa,crh);
        if(script.isEmpty()==false){
            JSONObject jmsg=new JSONObject();
            try{
                jmsg.put("type","script");
                jmsg.put("data",script);
            } catch (JSONException e) {
                e.printStackTrace();
            }
            port.postMessage(new WebMessage(jmsg.toString()));
        }
        else{
            if(LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") setText("hi", "Bocs, ezt nem tudom értelmezni.");
            else setText("hi", "Sorry, couldn't interpret it.");
        }
    }

    @Override
    protected void onNewIntent(Intent intent) {
        //TODO: implement check for search intent of voice search -see onCreate()
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
                            setText("hi","Várj, egy másik elemzést még megpróbálok.");
                        }
                        else{
                            setText("hi","Wait, I'll try yet another analysis.");
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
                            setText("hi","Bocs, ezt nem tudtam értelmezni.");
                        }
                        else{
                            setText("hi","Sorry, couldn't interpret it.");
                        }
                        if(message.length()>0) setText("hi", message.toString());
                    }
                }
                else if(recognisedText.isEmpty()==false&&recognisedText.contentEquals(lastFailure)==true){
                    recognisedText="";
                    if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
                        setText("hi","Bocs, ezt még most sem tudom értelmezni.");
                    }
                    else{
                        setText("hi","Sorry, I still can't interpret it.");
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
                    else{
                        if(recognisedText.indexOf(" hogy ")>0){
                            originalSendMsgText=recognisedText;
                            //remove message part as it's irrelevant from the analysis point of view
                            recognisedText=recognisedText.substring(0,recognisedText.indexOf(" hogy "));
                            //add 'x' as mock message otherwise the sentence w/o the removed message would be incorrect
                            recognisedText+=" hogy x";
                        }
                        else originalSendMsgText="";
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
                    if(recognisedText.contentEquals(oText)==false){
                        if(originalSendMsgText.isEmpty()==true) {
                            setText("hi",recognisedText);
                        }
                        else{
                            String mock=recognisedText.substring(0,recognisedText.length()-1);
                            setText("hi",mock);
                        }
                    }
                    String language;
                    if(LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") {
                        language = "HUN";
                    }
                    else language = "ENG";
                    commandBytes = jhi(recognisedText + "\n", language,dataDir+"/hi.db",0,0);
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
                            //mWebView.loadData("<html><head></head><body><script type=\"text/javascript\">" + commandScript + "</script></body></html>", "text/html; charset=UTF-8", "UTF-8");
                            //TODO: figure out what is better: pass script as webmessage or call evaluate directly?
                            //1) webview evaluate must run on ui thread but it can return values so calling back via android js
                            //interface can be avoided
                            //2) qml js engine has eval() as well and it seems that eval() can return
                            //values so instead of android js interface passing stuff there and back can be solved
                            //3) adding a new invisible webview and using loadData() just as before is also an option
                            //mWebView.evaluateJavascript(commandScript,null);
                            //port.postMessage(new WebMessage(commandScript));
                            //port.postMessage(new WebMessage("mouseArea.dummy();"));
                            port.postMessage(new WebMessage("console.log('hello');"));
                        }
                        else{
                            lastFailure=oText;
                            if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
                                setText("hi","Bocs, ezt nem tudtam értelmezni.");
                            }
                            else{
                                setText("hi","Sorry, couldn't interpret it.");
                            }
                            if(message.length()>0) setText("hi",message.toString());
                        }
                    } else{
                        lastFailure=oText;
                        if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU"){
                            setText("hi","Bocs, ezt nem értettem.");
                        }
                        else{
                            setText("hi","Sorry, didn't get it.");
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
    public static Context getContext(){
        return context;
    }

    public static void setText(String speaker, String message){
        JSONObject jmsg1=new JSONObject();
        JSONObject jmsg2=new JSONObject();
        try{
            jmsg2.put("text",message);
            jmsg2.put("speaker",speaker);
            jmsg1.put("type","text");
            jmsg1.put("data",jmsg2);
        } catch (JSONException e) {
            e.printStackTrace();
        }
        port.postMessage(new WebMessage(jmsg1.toString()));
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String permissions[], int[] grantResults) {
//	TODO: ?add RECORD_AUDIO permission handling?
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case PERMISSION_REQUEST_READ_CONTACTS: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    if (ContextCompat.checkSelfPermission(this, Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {
                        ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CALL_PHONE}, PERMISSION_REQUEST_CALL_PHONE);
                    } else {
                        Intent intent = new Intent("jsi_permission");
                        intent.putExtra("granted", "read_contacts");
                        context.sendBroadcast(intent);
                        //LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
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
                        context.sendBroadcast(intent);
                        //LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
                    }

                } else {

                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }
            /*case PERMISSION_REQUEST_SEND_SMS: {
                if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    if (ContextCompat.checkSelfPermission(this, Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED) {
                        ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.SEND_SMS}, PERMISSION_REQUEST_SEND_SMS);
                    } else {
                        Intent intent = new Intent("jsi_permission");
                        intent.putExtra("granted", "send_sms");
                        context.sendBroadcast(intent);
                        //LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
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
                        context.sendBroadcast(intent);
                        //LocalBroadcastManager.getInstance(this).sendBroadcast(intent);
                    }

                } else {

                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }*/
        }
    }
}