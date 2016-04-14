package hi.pkg;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map.Entry;
import java.util.Vector;
import java.util.Map;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.ActivityNotFoundException;
import android.database.Cursor;
import android.net.Uri;
import android.provider.ContactsContract;
import android.provider.ContactsContract.Contacts;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.webkit.JavascriptInterface;
import android.widget.Toast;
import android.content.ContentResolver;

public class jsi {
    Context mContext;

    /** Instantiate the interface and set the context */
    jsi(Context c) {
        mContext = c;
    }

    @JavascriptInterface
    public void fetchContacts(String contactName){
       	class OneShotTask implements Runnable{
       		private String mContactName;
       		public OneShotTask(String str) { mContactName = str; }
			@Override
			public void run(){
				Map<String, List<String>> Contacts=findContact(mContactName);
				if(Contacts.isEmpty()==false){
		            Toast.makeText(mContext, Contacts.toString(), Toast.LENGTH_LONG).show();
				}
		        else{
		            Toast.makeText(mContext, "Nothing found", Toast.LENGTH_SHORT).show();
		        }
			}
       	}
		Activity activity = (Activity) mContext;
		//As JS runs on UI thread, performing any operations on variables
		//coming from JS or calling any method on them results in exception: Error calling method on NPObject.
		//The only workaround seems to be to do such things on UIthread and store results in private attributes.
		activity.runOnUiThread(new OneShotTask(contactName));
    }
    
    public Map<String, List<String>> findContact(String contactName){
        Uri CONTENT_URI = ContactsContract.Contacts.CONTENT_URI;
        String _ID = ContactsContract.Contacts._ID;
        String DISPLAY_NAME = Contacts.DISPLAY_NAME;
        String HAS_PHONE_NUMBER = ContactsContract.Contacts.HAS_PHONE_NUMBER;
        Uri PhoneCONTENT_URI = ContactsContract.CommonDataKinds.Phone.CONTENT_URI;
        String Phone_CONTACT_ID = ContactsContract.CommonDataKinds.Phone.CONTACT_ID;
        String NUMBER = ContactsContract.CommonDataKinds.Phone.NUMBER;
        String Selection=Contacts.DISPLAY_NAME+" = ?";
        String[] SelectionArgs={"%"+contactName+"%"};

        Map<String, List<String>> Contacts = new LinkedHashMap<String, List<String>>();
        ContentResolver contentResolver = mContext.getContentResolver();
        //TODO:run query with selection and selectionarg instead of looping over every contact
        Cursor cursor=contentResolver.query(CONTENT_URI,null,null,null,null);
        // Loop for every contact in the phone
        if(cursor.getCount()>0){
            while (cursor.moveToNext()){
                String contact_id = cursor.getString(cursor.getColumnIndex( _ID ));
                String name = cursor.getString(cursor.getColumnIndex( DISPLAY_NAME ));
                int hasPhoneNumber = Integer.parseInt(cursor.getString(cursor.getColumnIndex( HAS_PHONE_NUMBER )));
                if (hasPhoneNumber>0&&contactName.isEmpty()==false&&name.toLowerCase(Locale.getDefault()).contains(contactName.toLowerCase(Locale.getDefault()))==true
                	||hasPhoneNumber>0&&contactName.isEmpty()==true){
                    // Query and loop for every phone number of the contact
                    Cursor phoneCursor = contentResolver.query(PhoneCONTENT_URI, null, Phone_CONTACT_ID + " = ?", new String[] { contact_id }, null);
                    List<String> phoneNumbers=new Vector<String>();
                    while (phoneCursor.moveToNext()) {
                    	String phoneNumber = phoneCursor.getString(phoneCursor.getColumnIndex(NUMBER));
                        phoneNumbers.add(phoneNumber);
                    }
                	Contacts.put(name, phoneNumbers);
                    phoneCursor.close();
                }
            }
            cursor.close();
        }
    	return Contacts;
    }
    
    @JavascriptInterface
    public void showProduct(String product){
       	class OneShotTask implements Runnable{
       		private String mProduct;
       		public OneShotTask(String str) { mProduct = str; }
			@Override
			public void run() {
		    	//Toast.makeText(mContext, "product id is:"+product, Toast.LENGTH_SHORT).show();
	    		String url="https://flpportal-i033768trial.dispatcher.hanatrial.ondemand.com/sap/hana/uis/clients/ushell-app/shells/fiori/FioriLaunchpad.html#product-display&/Products("+mProduct+")";
	        	try
	        	{
	        	    Intent intent = new Intent( Intent.ACTION_VIEW, Uri.parse( url ) );
	        	    mContext.startActivity( intent );
	        	}
	        	catch ( ActivityNotFoundException ex  )
	        	{
	        		Toast.makeText(mContext, "Activity not found", Toast.LENGTH_SHORT).show();
	        	}
			}
       	}
		Activity activity = (Activity) mContext;
		//As JS runs on UI thread, performing any operations on variables
		//coming from JS or calling any method on them results in exception: Error calling method on NPObject.
		//The only workaround seems to be to do such things on UIthread and store results in private attributes.
		activity.runOnUiThread(new OneShotTask(product));
    }

    @JavascriptInterface
    public void Call(String Contact){
       	class OneShotTask implements Runnable{
       		private String mContact;
       		public OneShotTask(String str) { mContact = str; }
			@Override
			public void run(){
				//legösszetettebb magyar pl:"Hívd fel Minta Lacit [a magyar számán [a magyar szám[om]ról]]!"
				//TODO: Ha nincs megadva melyik számról hívjon, a default simről indul a hívás.
				String contactName2="";
				String contactName3="";
				if(LanguageChecker.getInstance().getDefaultLanguage().contentEquals("HUN")==true){
					if(mContact.endsWith("á")==true)contactName2=mContact.substring(0,mContact.length()-1)+"a";
					else if(mContact.endsWith("é")==true)contactName2=mContact.substring(0,mContact.length()-1)+"e";
					else if(mContact.endsWith("í")==true)contactName2=mContact.substring(0,mContact.length()-1)+"i";
					else if(mContact.endsWith("ó")==true)contactName2=mContact.substring(0,mContact.length()-1)+"o";
					else if(mContact.endsWith("ő")==true)contactName2=mContact.substring(0,mContact.length()-1)+"ö";
					else if(mContact.endsWith("ú")==true)contactName2=mContact.substring(0,mContact.length()-1)+"u";
					else if(mContact.endsWith("ű")==true)contactName2=mContact.substring(0,mContact.length()-1)+"ü";
					else if(mContact.endsWith("a")==true)contactName3=mContact.substring(0,mContact.length()-1);
					else if(mContact.endsWith("e")==true)contactName3=mContact.substring(0,mContact.length()-1);
					else if(mContact.endsWith("i")==true)contactName3=mContact.substring(0,mContact.length()-1);
					else if(mContact.endsWith("o")==true)contactName3=mContact.substring(0,mContact.length()-1);
					else if(mContact.endsWith("ö")==true)contactName3=mContact.substring(0,mContact.length()-1);
					else if(mContact.endsWith("u")==true)contactName3=mContact.substring(0,mContact.length()-1);
					else if(mContact.endsWith("ü")==true)contactName3=mContact.substring(0,mContact.length()-1);
				}
	       		Map<String, List<String>> Contacts=findContact(mContact);
	       		if(Contacts.isEmpty()==true&&contactName2.isEmpty()==false) Contacts=findContact(contactName2);
	       		if(Contacts.isEmpty()==true&&contactName3.isEmpty()==false) Contacts=findContact(contactName3);
				if(Contacts.isEmpty()==false){
					Iterator<Map.Entry<String, List<String>>> contactList=Contacts.entrySet().iterator();
					List<String> contactNumbers=null;
					while(contactList.hasNext()){
						Entry<String, List<String>> contactListItem=contactList.next();
						if(contactListItem.getKey().toLowerCase(Locale.getDefault()).contentEquals(mContact)==true
							||contactListItem.getKey().toLowerCase(Locale.getDefault()).contentEquals(contactName2)==true
							||contactListItem.getKey().toLowerCase(Locale.getDefault()).contentEquals(contactName3)==true){
							contactNumbers=contactListItem.getValue();
							break;
						}
					}
					if(contactNumbers!=null&&contactNumbers.isEmpty()==false){
			            TelephonyManager tm=(TelephonyManager)mContext.getSystemService(Context.TELEPHONY_SERVICE);
			            String nwCountryCode=tm.getNetworkCountryIso();
			            TelephonyInfo telephonyInfo=TelephonyInfo.getInstance(mContext);
			            String callingCode=telephonyInfo.convertCountryCode(nwCountryCode.toUpperCase(Locale.getDefault()));
			            String phoneNumber="";
						Iterator<String> phoneNumberList=contactNumbers.iterator();
						while(phoneNumberList.hasNext()){
							phoneNumber=(String)phoneNumberList.next();
							if(phoneNumber.startsWith("+"+callingCode)==true||phoneNumber.startsWith("00"+callingCode)==true){
								break;
							}
						}
						//Check: using a broadcastreceiver for ACTION_NEW_OUTGOING_CALL it may be possible
						//to handle the sim selector popup
						if(phoneNumber.isEmpty()==false){
				            Intent callIntent = new Intent(Intent.ACTION_CALL).setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
				            callIntent.setData(Uri.parse("tel:" + phoneNumber));
				            mContext.startActivity(callIntent);
						}
						else{
				            Toast.makeText(mContext, "Sorry, can't make the call. Something went wrong.", Toast.LENGTH_SHORT).show();
						}
					}
					else{
			            Toast.makeText(mContext, "Sorry, no contact found. Please, repeat the name.", Toast.LENGTH_SHORT).show();
			            Intent callingIntent = new Intent(mContext, MainActivity.class);
			            callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
			            callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
			            callingIntent.putExtra("LID", LanguageChecker.getInstance().getDefaultLanguage());
			            callingIntent.putExtra("tryagain", "true");
			            mContext.startActivity(callingIntent);
					}
				}
		        else{
		            Toast.makeText(mContext, "Sorry, no contact found. Please, repeat the name.", Toast.LENGTH_SHORT).show();
		            Intent callingIntent = new Intent(mContext, MainActivity.class);
		            callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
		            callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
		            callingIntent.putExtra("repeat", mContact);
		            mContext.startActivity(callingIntent);
		        }
			}
       	}
		Activity activity = (Activity) mContext;
		//As JS runs on UI thread, performing any operations on variables
		//coming from JS or calling any method on them results in exception: Error calling method on NPObject.
		//The only workaround seems to be to do such things on UIthread and store results in private attributes.
		activity.runOnUiThread(new OneShotTask(Contact));
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
}
