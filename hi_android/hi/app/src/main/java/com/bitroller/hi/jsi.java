package com.bitroller.hi;

import android.Manifest;
import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.BroadcastReceiver;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.net.Uri;
import android.provider.ContactsContract;
import android.provider.ContactsContract.Contacts;
import android.support.v4.content.ContextCompat;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.LocalBroadcastManager;
import android.telephony.SmsManager;
import android.telephony.SubscriptionInfo;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.webkit.JavascriptInterface;
import android.webkit.ValueCallback;
import android.webkit.WebResourceError;
import android.webkit.WebResourceRequest;
import android.webkit.WebResourceResponse;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.Vector;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static android.Manifest.permission.READ_PHONE_STATE;

public class jsi {
    private static final int PERMISSION_REQUEST_READ_CONTACTS = 1;
    private static final int PERMISSION_REQUEST_CALL_PHONE = 2;
    private static final int PERMISSION_REQUEST_SEND_SMS = 3;
    private static final int PERMISSION_REQUEST_READ_PHONE_STATE = 4;
    Context mContext;
    Runnable mOneShotTask;
    List<String> callContext;
    String messageText;
    String messageContactName;
    String messageContactNumber;
    List<String> simNumbers;
    String dialogStep="0";
    int simId=-1;
    private BroadcastReceiver mMessageReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if ("jsi_permission".equals(intent.getAction())) {
                if (intent.hasExtra("granted") == true) {
                    Activity activity = (Activity) mContext;
                    activity.runOnUiThread(mOneShotTask);
                }
            }
        }
    };

    /**
     * Instantiate the interface and set the context
     */
    jsi(Context c) {
        mContext = c;
        callContext = new ArrayList<String>();
        messageText = "";
        messageContactName = "";
        messageContactNumber = "";
    }

    public void registerLocalBroadcastReceiver() {
        IntentFilter filter = new IntentFilter("jsi_permission");
        LocalBroadcastManager.getInstance(mContext).registerReceiver(mMessageReceiver, filter);
    }

    public void unregisterLocalBroadcastReceiver() {
        LocalBroadcastManager.getInstance(mContext).unregisterReceiver(mMessageReceiver);
    }

    @JavascriptInterface
    public void fetchContacts(String contactName) {
        class OneShotTask implements Runnable {
            private String mContactName;

            public OneShotTask(String str) {
                mContactName = str;
            }

            @Override
            public void run() {
                String message = "";
                String[] contactName = {mContactName};
                Map<String, List<String>> Contacts=getContacts(contactName);
                if (Contacts.isEmpty() == false) {
                    callContext.clear();
                    String contactListMsg = convertToContactList(Contacts, callContext);
                    message+=contactListMsg;
                } else {
                    if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                        message = "Nem találtam senkit. Mondd újra a nevet akár egyenként, betűvel.";
                    else
                        message = "Sorry, no contact found. Please, repeat the name.";
                }
                Intent setText = new Intent("hiBroadcast");
                setText.putExtra("setText", message);
                mContext.sendBroadcast(setText);
            }
        }
        Activity activity = (Activity) mContext;
        if (ContextCompat.checkSelfPermission(activity, Manifest.permission.READ_CONTACTS) != PackageManager.PERMISSION_GRANTED) {
            mOneShotTask = new OneShotTask(contactName);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.READ_CONTACTS}, PERMISSION_REQUEST_READ_CONTACTS);
        } else {
            //As JS runs on UI thread, performing any operations on variables
            //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
            //The only workaround seems to be to do such things on UIthread and store results in private attributes.
            activity.runOnUiThread(new OneShotTask(contactName));
        }
    }

    public Map<String, List<String>> findContact(String contactName) {
        Uri CONTENT_URI = ContactsContract.Contacts.CONTENT_URI;
        String _ID = ContactsContract.Contacts._ID;
        String DISPLAY_NAME = Contacts.DISPLAY_NAME;
        String HAS_PHONE_NUMBER = ContactsContract.Contacts.HAS_PHONE_NUMBER;
        Uri PhoneCONTENT_URI = ContactsContract.CommonDataKinds.Phone.CONTENT_URI;
        String Phone_CONTACT_ID = ContactsContract.CommonDataKinds.Phone.CONTACT_ID;
        String NUMBER = ContactsContract.CommonDataKinds.Phone.NUMBER;
        String Selection = Contacts.DISPLAY_NAME + " LIKE ?";
        String[] SelectionArgs = {"%" + contactName + "%"};

        Map<String, List<String>> Contacts = new LinkedHashMap<String, List<String>>();
        if (contactName.isEmpty() == false) {
            ContentResolver contentResolver = mContext.getContentResolver();
            Cursor phoneCursor = contentResolver.query(PhoneCONTENT_URI, null, Selection, SelectionArgs, null);
            List<String> phoneNumbers = new Vector<String>();
            String name = "";
            String phoneNumber = "";
            String nextName = "";
            while (phoneCursor.moveToNext()) {
                nextName = phoneCursor.getString(phoneCursor.getColumnIndex(DISPLAY_NAME));
                if (name.isEmpty() == true) name = nextName;
                if (nextName.isEmpty() == false && name.equals(nextName) == false) {
                    Contacts.put(name, phoneNumbers);
                    name = nextName;
                    if (Contacts.containsKey(name) == true) phoneNumbers = Contacts.get(name);
                    else phoneNumbers = new Vector<String>();
                }
                phoneNumber = phoneCursor.getString(phoneCursor.getColumnIndex(NUMBER));
                if (phoneNumber.isEmpty() == false && phoneNumbers.contains(phoneNumber) == false)
                    phoneNumbers.add(phoneNumber);
            }
            phoneCursor.close();
            if (name.isEmpty() == false && Contacts.containsKey(name) == false && phoneNumbers.isEmpty() == false)
                Contacts.put(name, phoneNumbers);
        }
        return Contacts;
    }

    @JavascriptInterface
    public void Call(String Contact) {
        class OneShotTask implements Runnable {
            private String mContact;

            public OneShotTask(String str) {
                mContact = str;
            }

            @Override
            public void run() {
                int nrOfDigits = 0;
                for (int i = 0; i < mContact.length(); ++i)
                    if (Character.isDigit(mContact.charAt(i)) == true) ++nrOfDigits;
                mContact=convertToNumber(mContact);
                if (mContact.matches("^[0-9 ]+$") == true && nrOfDigits > 2) {
                    Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    callIntent.setData(Uri.parse("tel:" + mContact));
                    mContext.startActivity(callIntent);
                } else if (mContact.matches("^[0-9]+[.]$") == true || mContact.matches("^[0-9]+$") == true && nrOfDigits < 3) {
                    int index = 0;
                    if (mContact.endsWith(".") == true)
                        index = Integer.valueOf(mContact.substring(0, mContact.length() - 1));
                    else index = Integer.valueOf(mContact);
                    if (index == 0) {
                        index = callContext.size();
                    }
                    if (callContext.isEmpty() == false && callContext.size() >= index) {
                        String phoneNumber = callContext.get(index - 1);
                        Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                        callIntent.setData(Uri.parse("tel:" + phoneNumber));
                        mContext.startActivity(callIntent);
                    } else {
                        Intent setText = new Intent("hiBroadcast");
                        if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                            setText.putExtra("setText", mContact + "-ként nem találtam senkit.");
                        else
                            setText.putExtra("setText", "Sorry, no contact found as " + mContact + " entry.");
                        mContext.sendBroadcast(setText);
                    }
                } else {
                    String[] contactName = {mContact};
                    Map<String, List<String>> Contacts=getContacts(contactName);
                    if (Contacts.isEmpty() == false) {
                        String phoneNumber = getExactContact(Contacts, contactName[0]);
                        if (phoneNumber.isEmpty() == false) {
                            Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                            callIntent.setData(Uri.parse("tel:" + phoneNumber));
                            mContext.startActivity(callIntent);
                        } else {
                            String message = "";
                            callContext.clear();
                            String contactListMsg = convertToContactList(Contacts, callContext);
                            message+=contactListMsg;
                            Intent setText = new Intent("hiBroadcast");
                            setText.putExtra("setText", message);
                            mContext.sendBroadcast(setText);
                        }
                    } else {
                        Intent setText = new Intent("hiBroadcast");
                        if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                            setText.putExtra("setText", "Nem találtam senkit. Mondd újra a nevet akár egyenként, betűvel.");
                        else
                            setText.putExtra("setText", "Sorry, no contact found. Please, repeat the name.");
                        mContext.sendBroadcast(setText);
                        Intent callingIntent = new Intent(MainActivity.getContext(), MainActivity.class);
                        callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
                        callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
                        callingIntent.putExtra("tryagain", "true");
                        callingIntent.putExtra("nextAnalysis", "true");
                        MainActivity.getContext().startActivity(callingIntent);
                    }
                }
            }
        }
        Activity activity = (Activity) mContext;

        if (ContextCompat.checkSelfPermission(activity, Manifest.permission.READ_CONTACTS) != PackageManager.PERMISSION_GRANTED) {
            mOneShotTask = new OneShotTask(Contact);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.READ_CONTACTS}, PERMISSION_REQUEST_READ_CONTACTS);
        } else if (ContextCompat.checkSelfPermission(activity, Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {
            mOneShotTask = new OneShotTask(Contact);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.CALL_PHONE}, PERMISSION_REQUEST_CALL_PHONE);
        } else {
            //As JS runs on UI thread, performing any operations on variables
            //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
            //The only workaround seems to be to do such things on UIthread and store results in private attributes.
            activity.runOnUiThread(new OneShotTask(Contact));
        }
    }

    @JavascriptInterface
    public void Toast(String text) {
        class OneShotTask implements Runnable {
            private String mText;

            public OneShotTask(String str) {
                mText = str;
            }

            @Override
            public void run() {
                Toast.makeText(mContext, mText, Toast.LENGTH_LONG).show();
            }
        }
        Activity activity = (Activity) mContext;
        //As JS runs on UI thread, performing any operations on variables
        //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
        //The only workaround seems to be to do such things on UIthread and store results in private attributes.
        activity.runOnUiThread(new OneShotTask(text));
    }

    @JavascriptInterface
    public void Log(String text) {
        class OneShotTask implements Runnable {
            private String mText;

            public OneShotTask(String str) {
                mText = str;
            }

            @Override
            public void run() {
                Log.i("hi", mText);
            }
        }
        Activity activity = (Activity) mContext;
        //As JS runs on UI thread, performing any operations on variables
        //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
        //The only workaround seems to be to do such things on UIthread and store results in private attributes.
        activity.runOnUiThread(new OneShotTask(text));
    }

    @JavascriptInterface
    public void openUrl(String text) {
        WebView webView = MainActivity.getWebView();
        webView.setWebViewClient(new WebViewClient() {
            @Override
            public void onReceivedError(WebView view, WebResourceRequest request, WebResourceError error) {
                //TODO: Handle error
            }

            @Override
            public void onReceivedHttpError(WebView view, WebResourceRequest request, WebResourceResponse errorResponse) {
                //TODO: Handle error
            }

            @Override
            public boolean shouldOverrideUrlLoading(WebView view, String url) {//TODO: String url got deprecated in api level 24, need to differentiate
                view.loadUrl(url);
                return false;
            }

            @Override
            public void onPageFinished(WebView view, String url) {
                super.onPageFinished(view, url);
                //https://stackoverflow.com/questions/59037366/how-to-convert-htmlcollection-to-string
                String js = "(function() { var inputList=document.getElementsByTagName('input');inputArray=Array.from(inputList);var inputJSON={};for(var i=0;i<inputArray.length;++i){inputJSON['i'+i]=inputArray[i].outerHTML;} return JSON.stringify(inputJSON); })();";
//				String js="(function() { return 'this'; })();";
                view.evaluateJavascript(js, new ValueCallback<String>() {
                    @Override
                    public void onReceiveValue(String s) {
                        //https://stackoverflow.com/questions/19788294/how-does-evaluatejavascript-work
//						JsonReader reader = new JsonReader(new StringReader(s));
//						// Must set lenient to parse single values
//						reader.setLenient(true);
//						try {
//							if(reader.peek() != JsonToken.NULL) {
//								if(reader.peek() == JsonToken.STRING) {
//									String msg = reader.nextString();
//									if(msg != null) {
//										//Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_LONG).show();
//										setText(msg);
//									}
//								}
//							}
//						} catch (IOException e) {
//							Log.e("TAG", "MainActivity: IOException", e);
//						} finally {
//							try {
//								reader.close();
//							} catch (IOException e) {
//								// NOOP
//							}
//						}
                        Intent setText = new Intent("hiBroadcast");
                        setText.putExtra("setText", s);
                        mContext.sendBroadcast(setText);
                    }
                });
//				view.loadUrl(js);
            }
        });
        webView.loadUrl("http://freemail.hu");
    }

    @JavascriptInterface
    public void sendMessage(String contact, String text) {
        class OneShotTask implements Runnable {
            private String mContact;
            private String mText;

            public OneShotTask(String contact, String text) {
                messageContactName = contact;
                messageContactNumber="";
                messageText = text;
                simId=-1;
            }

            @Override
            public void run() {
                dialogStep="0";
                if(messageContactName.contentEquals(MainActivity.getRecognisedText())) messageContactName="";
                String originalText=MainActivity.getOriginalSendMsgText();
                if(originalText.indexOf(" hogy ")>0) {
                    messageText = originalText.substring(MainActivity.getRecognisedText().length() - 1);
                }
                else{
                    Intent setText = new Intent("hiBroadcast");
                    if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") setText.putExtra("setText","Bocs, ezt nem tudtam értelmezni.");
                    else setText.putExtra("setText","Sorry, couldn't interpret it.");
                    mContext.sendBroadcast(setText);
                    return;
                }
                callContext.clear();
                Intent setText = new Intent("hiBroadcast");
                if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                    setText.putExtra("setText", messageText + "\n\nEzt értettem. Üzenetküldés jóváhagyásához, mondd: küldd");
                else
                    setText.putExtra("setText", messageText + "\nThat's how I got it. Confirm sending by saying: send");
                mContext.sendBroadcast(setText);
            }
        }
        Activity activity = (Activity) mContext;
        //As JS runs on UI thread, performing any operations on variables
        //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
        //The only workaround seems to be to do such things on UIthread and store results in private attributes.
        activity.runOnUiThread(new OneShotTask(contact, text));
    }

    @JavascriptInterface
    public void assertSend(String send) {
        class OneShotTask implements Runnable {
            private String mSend;

            public OneShotTask(String send) {
                mSend = send;
            }

            @Override
            public void run() {
                if(dialogStep=="0"){
                    if (mSend.contentEquals("false")) messageText = "";
                    else if(mSend.contentEquals("true")&&messageContactName.isEmpty()==true){
                        dialogStep="1";
                        Intent setText = new Intent("hiBroadcast");
                        if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                            setText.putExtra("setText", "Nem értettem, hogy kinek küldenéd. Mondd újra a nevet akár egyenként, betűvel.");
                        else
                            setText.putExtra("setText", "Sorry, couldn't get who you would send it. Please, repeat the name.");
                        mContext.sendBroadcast(setText);
                    }
                    else if (mSend.contentEquals("true") && messageText.isEmpty() == false) {
                        assertSendNext();
                    }
                    else{
                        //Shall never happen.
                    }
                }
                else if(dialogStep=="1"){
                    if(mSend.contentEquals("false")==false&&mSend.contentEquals("true")==false){
                        messageContactName=mSend;
                        mSend="true";
                        assertSendNext();
                    }
                }
                else if(dialogStep=="2.1"){
                    String simIdToConvert=mSend;
                    mSend="true";
                    simId=convertToSimId(simIdToConvert);
                    assertSendNext();
                }
                else if(dialogStep=="2.2"){
                    assertSend_2_2(mSend);
                }
                else{
                    //Shall never happen.
                }
            }
        }
        Activity activity = (Activity) mContext;
        //As JS runs on UI thread, performing any operations on variables
        //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
        //The only workaround seems to be to do such things on UIthread and store results in private attributes.
        if (ContextCompat.checkSelfPermission(activity, Manifest.permission.READ_PHONE_STATE) != PackageManager.PERMISSION_GRANTED) {
            mOneShotTask = new OneShotTask(send);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.READ_PHONE_STATE}, PERMISSION_REQUEST_READ_PHONE_STATE);
        } else if (ContextCompat.checkSelfPermission(activity, Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED) {
            mOneShotTask = new OneShotTask(send);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.SEND_SMS}, PERMISSION_REQUEST_SEND_SMS);
        }
        else {
            //As JS runs on UI thread, performing any operations on variables
            //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
            //The only workaround seems to be to do such things on UIthread and store results in private attributes.
            activity.runOnUiThread(new OneShotTask(send));
        }
    }

    public Map<String, List<String>> getContacts(String[] contactName) {
        String mContactName=contactName[0];
        String contactName2 = "";
        String contactName3 = "";
        Map<String, List<String>> Contacts = new LinkedHashMap<String, List<String>>();
        if (mContactName.isEmpty() == false) {
            if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU") {
                if (mContactName.endsWith("á") == true)
                    contactName2 = mContactName.substring(0, mContactName.length() - 1) + "a";
                else if (mContactName.endsWith("é") == true)
                    contactName2 = mContactName.substring(0, mContactName.length() - 1) + "e";
                else if (mContactName.endsWith("í") == true)
                    contactName2 = mContactName.substring(0, mContactName.length() - 1) + "i";
                else if (mContactName.endsWith("ó") == true)
                    contactName2 = mContactName.substring(0, mContactName.length() - 1) + "o";
                else if (mContactName.endsWith("ő") == true)
                    contactName2 = mContactName.substring(0, mContactName.length() - 1) + "ö";
                else if (mContactName.endsWith("ú") == true)
                    contactName2 = mContactName.substring(0, mContactName.length() - 1) + "u";
                else if (mContactName.endsWith("ű") == true)
                    contactName2 = mContactName.substring(0, mContactName.length() - 1) + "ü";
                else if (mContactName.endsWith("a") == true)
                    contactName3 = mContactName.substring(0, mContactName.length() - 1);
                else if (mContactName.endsWith("e") == true)
                    contactName3 = mContactName.substring(0, mContactName.length() - 1);
                else if (mContactName.endsWith("i") == true)
                    contactName3 = mContactName.substring(0, mContactName.length() - 1);
                else if (mContactName.endsWith("o") == true)
                    contactName3 = mContactName.substring(0, mContactName.length() - 1);
                else if (mContactName.endsWith("ö") == true)
                    contactName3 = mContactName.substring(0, mContactName.length() - 1);
                else if (mContactName.endsWith("u") == true)
                    contactName3 = mContactName.substring(0, mContactName.length() - 1);
                else if (mContactName.endsWith("ü") == true)
                    contactName3 = mContactName.substring(0, mContactName.length() - 1);
            }
            Contacts = findContact(mContactName);
            if (Contacts.isEmpty() == true && contactName2.isEmpty() == false) {
                Contacts = findContact(contactName2);
                contactName[0]=contactName2;
            }
            if (Contacts.isEmpty() == true && contactName3.isEmpty() == false) {
                Contacts = findContact(contactName3);
                contactName[0]=contactName3;
            }
        }
        return Contacts;
    }

    public String getExactContact(Map<String, List<String>> Contacts, String contactName){
        String phoneNumber = "";
        if (Contacts.isEmpty() == false) {
            Set<String> contactKeys = Contacts.keySet();
            String exactContact = "";
            Iterator<String> contactKey = contactKeys.iterator();
            while (contactKey.hasNext()) {
                String contactKeyItem = contactKey.next();
                if (contactKeyItem.equalsIgnoreCase(contactName) == true || contactKeyItem.equalsIgnoreCase(contactName) == false && Contacts.size() == 1) {
                    exactContact = contactKeyItem;
                    contactName = contactKeyItem;
                    break;
                }
            }
            if (exactContact.isEmpty() == false) {
                Iterator<Map.Entry<String, List<String>>> contactList = Contacts.entrySet().iterator();
                List<String> contactNumbers = null;
                while (contactList.hasNext()) {
                    Entry<String, List<String>> contactListItem = contactList.next();
                    if (contactListItem.getKey().equalsIgnoreCase(contactName) == true) {
                        contactNumbers = contactListItem.getValue();
                        break;
                    }
                }
                if (contactNumbers != null && contactNumbers.isEmpty() == false) {
                    TelephonyManager tm = (TelephonyManager) mContext.getSystemService(Context.TELEPHONY_SERVICE);
                    String nwCountryCode = tm.getNetworkCountryIso();
                    TelephonyInfo telephonyInfo = TelephonyInfo.getInstance(mContext);
                    String callingCode = telephonyInfo.convertCountryCode(nwCountryCode.toUpperCase(Locale.getDefault()));
                    Iterator<String> phoneNumberList = contactNumbers.iterator();
                    while (phoneNumberList.hasNext()) {
                        phoneNumber = (String) phoneNumberList.next();
                        if (phoneNumber.startsWith("+" + callingCode) == true || phoneNumber.startsWith("00" + callingCode) == true) {
                            break;
                        }
                    }
                }
            }
        }
        return phoneNumber;
    }

    public String convertToContactList(Map<String, List<String>> Contacts, List<String> contactList){
        String message="";
        if (Contacts.isEmpty() == false) {
            Iterator<Map.Entry<String, List<String>>> iContactList = Contacts.entrySet().iterator();
            List<String> contactNumbers = null;
            int numberCounter = 0;
            while (iContactList.hasNext()) {
                Entry<String, List<String>> contactListItem = iContactList.next();
                message += contactListItem.getKey() + "\n";
                contactNumbers = contactListItem.getValue();
                Iterator<String> contactNumber = contactNumbers.iterator();
                while (contactNumber.hasNext()) {
                    ++numberCounter;
                    String phoneNumber = contactNumber.next();
                    message += String.valueOf(numberCounter) + ")" + phoneNumber + "\n";
                    contactList.add(phoneNumber);
                }
            }
        }
        return message;
    }

    public String convertToNumber(String mContact){
        if (LanguageChecker.getInstance().getDefaultLanguage() != "hu-HU") {
            if (mContact.matches(".*\\d.*") == true) {
                if (mContact.matches("\\d*st(?=\\s|$)") == true) {
                    mContact = mContact.replace("st", ".");
                } else if (mContact.matches("\\d*nd(?=\\s|$)") == true) {
                    mContact = mContact.replace("nd", ".");
                } else if (mContact.matches("\\d*rd(?=\\s|$)") == true) {
                    mContact = mContact.replace("rd", ".");
                } else if (mContact.matches("\\d*th(?=\\s|$)") == true) {
                    mContact = mContact.replace("th", ".");
                } else if (mContact.matches("\\d*\\..+") == true) {
                    mContact = mContact.substring(0, mContact.indexOf('.') + 1);
                }
            } else {
                if (mContact.contentEquals("i")) mContact = "1.";
                else if (mContact.contentEquals("ii")) mContact = "2.";
                else if (mContact.contentEquals("iii")) mContact = "3.";
                else if (mContact.contentEquals("iv")) mContact = "4.";
                else if (mContact.contentEquals("v")) mContact = "5.";
                else if (mContact.contentEquals("vi")) mContact = "6.";
            }
        }
        return mContact;
    }

    public void assertSendNext(){
        String phoneNumber=messageContactNumber;
        Map<String, List<String>> Contacts = null;
        String[] contactName = {messageContactName};
        if(messageContactNumber.isEmpty()==true) {
            Contacts = getContacts(contactName);
            if(Contacts.isEmpty()==false) {
                phoneNumber = getExactContact(Contacts, contactName[0]);
            }
            else{
                dialogStep="1";
                Intent setText = new Intent("hiBroadcast");
                if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                    setText.putExtra("setText", "Nem értettem, hogy kinek küldenéd. Mondd újra a nevet akár egyenként, betűvel.");
                else
                    setText.putExtra("setText", "Sorry, couldn't get who you would send it. Please, repeat the name.");
                mContext.sendBroadcast(setText);
                return;
            }
        }
        if (phoneNumber.isEmpty() == false) {
            messageContactNumber = phoneNumber;
            List<SubscriptionInfo> subscriptionInfoList;
            subscriptionInfoList = getSimId();
            if (simId == -1){
                simNumbers = new ArrayList<String>();
                String message = "";
                if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                    message = "Melyik SIMről küldjem?\n";
                else
                    message = "Which SIM shall I use?\n";
                for (SubscriptionInfo subscriptionInfo : subscriptionInfoList) {
                    simId = subscriptionInfo.getSubscriptionId();
                    String simNumber = subscriptionInfo.getNumber();
                    simNumbers.add(simNumber);
                    message += String.valueOf(subscriptionInfo.getSimSlotIndex() + 1) + ") " + simNumber + "\n";
                }
                if (simNumbers.size() > 1) {
                    dialogStep = "2.1";
                    Intent setText = new Intent("hiBroadcast");
                    setText.putExtra("setText", message);
                    mContext.sendBroadcast(setText);
                    return;
                }
            }
            int subscriptionId=subscriptionInfoList.get(simId-1).getSubscriptionId();
            SmsManager smsManager = SmsManager.getSmsManagerForSubscriptionId(subscriptionId);
            //TODO: get/Multipart/SMSIntent() could be called as well to make use of the intent that reports success or failure
            if(messageText.length()>160){
                ArrayList<String> parts = smsManager.divideMessage (messageText);
                smsManager.sendMultipartTextMessage(phoneNumber, null, parts, null, null);
            }
            else {
                smsManager.sendTextMessage(phoneNumber, null, messageText, null, null);
            }
            Intent setText = new Intent("hiBroadcast");
            if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                setText.putExtra("setText", "Elküldtem.");
            else
                setText.putExtra("setText", "Sent.");
            mContext.sendBroadcast(setText);
        }
        else{
            dialogStep="2.2";
            String message = "";
            if (LanguageChecker.getInstance().getDefaultLanguage() == "hu-HU")
                message = "Többet találtam. Kinek küldjem?\n";
            else
                message = "Found more than one. Who shall I send it?\n";
            callContext.clear();
            String contactListMsg = convertToContactList(Contacts, callContext);
            message+=contactListMsg;
            Intent setText = new Intent("hiBroadcast");
            setText.putExtra("setText", message);
            mContext.sendBroadcast(setText);
        }
    }

    public List<SubscriptionInfo> getSimId(){
        //https://stackoverflow.com/questions/55391153/app-crashes-while-sending-sms-via-smsmanager
        //SubscriptionManager subscriptionManager = SubscriptionManager.from(mContext);
        SubscriptionManager subscriptionManager = (SubscriptionManager) mContext.getSystemService("telephony_subscription_service");
        List<SubscriptionInfo> subscriptionInfoList = subscriptionManager.getActiveSubscriptionInfoList();
        return subscriptionInfoList;
    }

    public void assertSend_2_2(String number){
        //TODO: handle in the langugae model:
        //- küldd az elsőnek/másodiknak/.../utolsónak
        //- üzenem csnév1 csnév2 csnév3 ... knév1 knév2 knév3 ... péternek, hogy x
        int nrOfDigits = 0;
        for (int i = 0; i < number.length(); ++i)
            if (Character.isDigit(number.charAt(i)) == true) ++nrOfDigits;
        String mContact=convertToNumber(number);
        if (mContact.matches("^[0-9 ]+$") == true && nrOfDigits > 2) {
            //TODO: trigger intent to send message to the specified phone number once the
            //language model supports it
        }
        else if (mContact.matches("^[0-9]+[.]$") == true || mContact.matches("^[0-9]+$") == true && nrOfDigits < 3) {
            int index = 0;
            if (mContact.endsWith(".") == true)
                index = Integer.valueOf(mContact.substring(0, mContact.length() - 1));
            else index = Integer.valueOf(mContact);
            if (index == 0) {
                index = callContext.size();
            }
            if (callContext.isEmpty() == false && callContext.size() >= index) {
                messageContactNumber = callContext.get(index - 1);
                assertSendNext();
            }
            else {
                //Shall never happen.
            }
        }
    }

    public int convertToSimId(String text){
        int simId=0;
        int nrOfDigits = 0;
        for (int i = 0; i < text.length(); ++i)
            if (Character.isDigit(text.charAt(i)) == true) ++nrOfDigits;
        String strSimId=convertToNumber(text);
        if (nrOfDigits < 3 && strSimId.endsWith(".")) {
            simId=Integer.parseInt(String.valueOf(strSimId.charAt(0)));
            return simId;
        }
        else{
            return -1;
        }
    }
}
