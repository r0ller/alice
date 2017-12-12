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
import android.telephony.TelephonyManager;
import android.util.Log;
import android.webkit.JavascriptInterface;
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

public class jsi {
    private static final int PERMISSION_REQUEST_READ_CONTACTS = 1;
    private static final int PERMISSION_REQUEST_CALL_PHONE = 2;
    Context mContext;
    Runnable mOneShotTask;
    List<String> callContext;
    private BroadcastReceiver mMessageReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if(intent.hasExtra("granted")==true){
                Activity activity = (Activity) mContext;
                activity.runOnUiThread(mOneShotTask);
            }
        }
    };

    /** Instantiate the interface and set the context */
    jsi(Context c) {
        mContext = c;
        callContext=new ArrayList<String>();
    }

    public void registerLocalBroadcastReceiver(){
        LocalBroadcastManager.getInstance(mContext).registerReceiver(mMessageReceiver,
                new IntentFilter("jsi_permission"));
    }

    public void unregisterLocalBroadcastReceiver(){
        LocalBroadcastManager.getInstance(mContext).unregisterReceiver(mMessageReceiver);
    }

    @JavascriptInterface
    public void fetchContacts(String contactName){
       	class OneShotTask implements Runnable{
       		private String mContactName;
       		public OneShotTask(String str) { mContactName = str; }
			@Override
			public void run(){
       		    if(mContactName.isEmpty()==true) mContactName="%";
				Map<String, List<String>> Contacts=findContact(mContactName);
                String message="";
				if(Contacts.isEmpty()==false){
                    Iterator<Map.Entry<String, List<String>>> contactList = Contacts.entrySet().iterator();
                    List<String> contactNumbers = null;
                    int numberCounter = 0;
                    while (contactList.hasNext()) {
                        Entry<String, List<String>> contactListItem = contactList.next();
                        message += contactListItem.getKey() + "\n";
                        contactNumbers = contactListItem.getValue();
                        Iterator<String> contactNumber = contactNumbers.iterator();
                        while (contactNumber.hasNext()) {
                            ++numberCounter;
                            String phoneNumber=contactNumber.next();
                            message += String.valueOf(numberCounter) + ")" + phoneNumber + "\n";
                        }
                    }
                }
                else{
                    message="Nothing found.\n";
                }
                Intent setText = new Intent("hiBroadcast");
                setText.putExtra("setText", message);
                mContext.sendBroadcast(setText);
			}
       	}
		Activity activity = (Activity) mContext;
        if(ContextCompat.checkSelfPermission(activity, Manifest.permission.READ_CONTACTS)!= PackageManager.PERMISSION_GRANTED){
            mOneShotTask=new OneShotTask(contactName);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.READ_CONTACTS}, PERMISSION_REQUEST_READ_CONTACTS);
        }
        else {
            //As JS runs on UI thread, performing any operations on variables
            //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
            //The only workaround seems to be to do such things on UIthread and store results in private attributes.
            activity.runOnUiThread(new OneShotTask(contactName));
        }
    }
    
    public Map<String, List<String>> findContact(String contactName){
        Uri CONTENT_URI = ContactsContract.Contacts.CONTENT_URI;
        String _ID = ContactsContract.Contacts._ID;
        String DISPLAY_NAME = Contacts.DISPLAY_NAME;
        String HAS_PHONE_NUMBER = ContactsContract.Contacts.HAS_PHONE_NUMBER;
        Uri PhoneCONTENT_URI = ContactsContract.CommonDataKinds.Phone.CONTENT_URI;
        String Phone_CONTACT_ID = ContactsContract.CommonDataKinds.Phone.CONTACT_ID;
        String NUMBER = ContactsContract.CommonDataKinds.Phone.NUMBER;
        String Selection=Contacts.DISPLAY_NAME+" LIKE ?";
        String[] SelectionArgs={"%"+contactName+"%"};

		Map<String, List<String>> Contacts = new LinkedHashMap<String, List<String>>();
        if(contactName.isEmpty()==false) {
			ContentResolver contentResolver = mContext.getContentResolver();
			Cursor phoneCursor = contentResolver.query(PhoneCONTENT_URI, null, Selection, SelectionArgs, null);
			List<String> phoneNumbers = new Vector<String>();
			String name="";
			String phoneNumber="";
			String nextName="";
			while (phoneCursor.moveToNext()) {
				nextName=phoneCursor.getString(phoneCursor.getColumnIndex( DISPLAY_NAME ));
				if(name.isEmpty()==true)name=nextName;
				if(nextName.isEmpty()==false&&name.equals(nextName)==false){
					Contacts.put(name, phoneNumbers);
					name=nextName;
					if(Contacts.containsKey(name)==true)phoneNumbers=Contacts.get(name);
					else phoneNumbers = new Vector<String>();
				}
				phoneNumber = phoneCursor.getString(phoneCursor.getColumnIndex(NUMBER));
				if(phoneNumber.isEmpty()==false&&phoneNumbers.contains(phoneNumber)==false)phoneNumbers.add(phoneNumber);
			}
			phoneCursor.close();
			if(name.isEmpty()==false&&Contacts.containsKey(name)==false&&phoneNumbers.isEmpty()==false)Contacts.put(name, phoneNumbers);
		}
    	return Contacts;
    }
    
    @JavascriptInterface
    public void Call(String Contact){
       	class OneShotTask implements Runnable{
       		private String mContact;
       		public OneShotTask(String str) { mContact = str; }
			@Override
			public void run() {
                //legösszetettebb magyar pl:"Hívd fel Minta Lacit [a magyar számán [a magyar szám[om]ról]]!"
                if (mContact.matches("^[0-9]+$") == true) {
                    Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    callIntent.setData(Uri.parse("tel:" + mContact));
                    mContext.startActivity(callIntent);
                }
                else if(mContact.matches("^[0-9]+[.]$") == true){
                    int index=Integer.valueOf(mContact.substring(0,mContact.length()-1));
                    if(index==0){
                        index=callContext.size();
                    }
                    if(callContext.isEmpty()==false&&callContext.size()>=index) {
                        String phoneNumber = callContext.get(index - 1);
                        Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                        callIntent.setData(Uri.parse("tel:" + phoneNumber));
                        mContext.startActivity(callIntent);
                    }
                    else{
                        Intent setText = new Intent("hiBroadcast");
                        if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN")
                            setText.putExtra("setText", mContact+"-ként nem találtam senkit.");
                        else
                            setText.putExtra("setText", "Sorry, no contact found as "+mContact+" entry.");
                        mContext.sendBroadcast(setText);
                    }
                }
                else{
                    String contactName = "";
                    String contactName2 = "";
                    String contactName3 = "";
                    if (LanguageChecker.getInstance().getDefaultLanguage()=="HUN") {
                        if (mContact.endsWith("á") == true)
                            contactName2 = mContact.substring(0, mContact.length() - 1) + "a";
                        else if (mContact.endsWith("é") == true)
                            contactName2 = mContact.substring(0, mContact.length() - 1) + "e";
                        else if (mContact.endsWith("í") == true)
                            contactName2 = mContact.substring(0, mContact.length() - 1) + "i";
                        else if (mContact.endsWith("ó") == true)
                            contactName2 = mContact.substring(0, mContact.length() - 1) + "o";
                        else if (mContact.endsWith("ő") == true)
                            contactName2 = mContact.substring(0, mContact.length() - 1) + "ö";
                        else if (mContact.endsWith("ú") == true)
                            contactName2 = mContact.substring(0, mContact.length() - 1) + "u";
                        else if (mContact.endsWith("ű") == true)
                            contactName2 = mContact.substring(0, mContact.length() - 1) + "ü";
                        else if (mContact.endsWith("a") == true)
                            contactName3 = mContact.substring(0, mContact.length() - 1);
                        else if (mContact.endsWith("e") == true)
                            contactName3 = mContact.substring(0, mContact.length() - 1);
                        else if (mContact.endsWith("i") == true)
                            contactName3 = mContact.substring(0, mContact.length() - 1);
                        else if (mContact.endsWith("o") == true)
                            contactName3 = mContact.substring(0, mContact.length() - 1);
                        else if (mContact.endsWith("ö") == true)
                            contactName3 = mContact.substring(0, mContact.length() - 1);
                        else if (mContact.endsWith("u") == true)
                            contactName3 = mContact.substring(0, mContact.length() - 1);
                        else if (mContact.endsWith("ü") == true)
                            contactName3 = mContact.substring(0, mContact.length() - 1);
                    }
                    Map<String, List<String>> Contacts = findContact(mContact);
                    if (Contacts.isEmpty() == false) contactName = mContact;
                    if (Contacts.isEmpty() == true && contactName2.isEmpty() == false) {
                        Contacts = findContact(contactName2);
                        contactName = contactName2;
                    }
                    if (Contacts.isEmpty() == true && contactName3.isEmpty() == false) {
                        Contacts = findContact(contactName3);
                        contactName = contactName3;
                    }
                    if (Contacts.isEmpty() == false) {
                        Set<String> contactKeys = Contacts.keySet();
                        String exactContact = "";
                        Iterator<String> contactKey = contactKeys.iterator();
                        while (contactKey.hasNext()) {
                            String contactKeyItem = contactKey.next();
                            if (contactName.equalsIgnoreCase(contactKeyItem) == true) {
                                exactContact = contactKeyItem;
                                break;
                            }
                        }
                        if (exactContact.isEmpty() == false) {
                            Iterator<Map.Entry<String, List<String>>> contactList = Contacts.entrySet().iterator();
                            List<String> contactNumbers = null;
                            while (contactList.hasNext()) {
                                Entry<String, List<String>> contactListItem = contactList.next();
                                if (contactListItem.getKey().toLowerCase(Locale.getDefault()).contentEquals(contactName) == true
                                        || contactListItem.getKey().toLowerCase(Locale.getDefault()).contentEquals(contactName2) == true
                                        || contactListItem.getKey().toLowerCase(Locale.getDefault()).contentEquals(contactName3) == true) {
                                    contactNumbers = contactListItem.getValue();
                                    break;
                                }
                            }
                            if (contactNumbers != null && contactNumbers.isEmpty() == false) {
                                TelephonyManager tm = (TelephonyManager) mContext.getSystemService(Context.TELEPHONY_SERVICE);
                                String nwCountryCode = tm.getNetworkCountryIso();
                                TelephonyInfo telephonyInfo = TelephonyInfo.getInstance(mContext);
                                String callingCode = telephonyInfo.convertCountryCode(nwCountryCode.toUpperCase(Locale.getDefault()));
                                String phoneNumber = "";
                                Iterator<String> phoneNumberList = contactNumbers.iterator();
                                while (phoneNumberList.hasNext()) {
                                    phoneNumber = (String) phoneNumberList.next();
                                    if (phoneNumber.startsWith("+" + callingCode) == true || phoneNumber.startsWith("00" + callingCode) == true) {
                                        break;
                                    }
                                }
                                //Check: using a broadcastreceiver for ACTION_NEW_OUTGOING_CALL it may be possible
                                //to handle the sim selector popup
                                if (phoneNumber.isEmpty() == false) {
                                    Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                                    callIntent.setData(Uri.parse("tel:" + phoneNumber));
                                    mContext.startActivity(callIntent);
                                } else {
                                    Intent setText = new Intent("hiBroadcast");
                                    if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN")
                                        setText.putExtra("setText", "Bocs, nem találtam hívható számot.");
                                    else
                                        setText.putExtra("setText", "Sorry, can't make the call. Something went wrong.");
                                    mContext.sendBroadcast(setText);
                                    //Toast.makeText(mContext, "Sorry, can't make the call. Something went wrong.", Toast.LENGTH_SHORT).show();
                                }
                            } else {
                                Intent setText = new Intent("hiBroadcast");
                                if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN")
                                    setText.putExtra("setText", "Nem találtam senkit. Mondd újra a nevet akár egyenként, betűvel.");
                                else
                                    setText.putExtra("setText", "Sorry, no contact found. Please, repeat the name.");
                                mContext.sendBroadcast(setText);
                            }
                        } else {
                            Iterator<Map.Entry<String, List<String>>> contactList = Contacts.entrySet().iterator();
                            List<String> contactNumbers = null;
                            String message="";
                            if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN")
                                message = "Többet találtam:\n";
                            else
                                message = "Found more than one:\n";
                            int numberCounter = 0;
                            callContext.clear();
                            while (contactList.hasNext()) {
                                Entry<String, List<String>> contactListItem = contactList.next();
                                message += contactListItem.getKey() + "\n";
                                contactNumbers = contactListItem.getValue();
                                Iterator<String> contactNumber = contactNumbers.iterator();
                                while (contactNumber.hasNext()) {
                                    ++numberCounter;
                                    String phoneNumber=contactNumber.next();
                                    message += String.valueOf(numberCounter) + ")" + phoneNumber + "\n";
                                    callContext.add(phoneNumber);
                                }
                            }
                            Intent setText = new Intent("hiBroadcast");
                            setText.putExtra("setText", message);
                            mContext.sendBroadcast(setText);
                        }
                    } else {
                        Intent setText = new Intent("hiBroadcast");
                        if (LanguageChecker.getInstance().getDefaultLanguage() == "HUN")
                            setText.putExtra("setText", "Nem találtam senkit. Mondd újra a nevet akár egyenként, betűvel.");
                        else
                            setText.putExtra("setText", "Sorry, no contact found. Please, repeat the name.");
                        mContext.sendBroadcast(setText);
                    }
                }
			}
       	}
		Activity activity = (Activity) mContext;

        if(ContextCompat.checkSelfPermission(activity, Manifest.permission.READ_CONTACTS)!= PackageManager.PERMISSION_GRANTED){
            mOneShotTask=new OneShotTask(Contact);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.READ_CONTACTS}, PERMISSION_REQUEST_READ_CONTACTS);
        }
        else if(ContextCompat.checkSelfPermission(activity, Manifest.permission.CALL_PHONE)!= PackageManager.PERMISSION_GRANTED){
            mOneShotTask=new OneShotTask(Contact);
            ActivityCompat.requestPermissions(activity, new String[]{Manifest.permission.CALL_PHONE}, PERMISSION_REQUEST_CALL_PHONE);
        }
        else {
            //As JS runs on UI thread, performing any operations on variables
            //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
            //The only workaround seems to be to do such things on UIthread and store results in private attributes.
            activity.runOnUiThread(new OneShotTask(Contact));
        }
    }

    @JavascriptInterface
    public void Toast(String text){
       	class OneShotTask implements Runnable{
       		private String mText;
       		public OneShotTask(String str) { mText = str; }
			@Override
			public void run(){
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
    public void Log(String text){
        class OneShotTask implements Runnable{
            private String mText;
            public OneShotTask(String str) { mText = str; }
            @Override
            public void run(){
                Log.i("hi",mText);
            }
        }
        Activity activity = (Activity) mContext;
        //As JS runs on UI thread, performing any operations on variables
        //coming from JS or calling any method on them results in exception: Error calling method on NPObject.
        //The only workaround seems to be to do such things on UIthread and store results in private attributes.
        activity.runOnUiThread(new OneShotTask(text));
    }

}
