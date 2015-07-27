package hi.pkg;

import android.app.Activity;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.provider.ContactsContract;
import android.provider.ContactsContract.Contacts;
import android.util.Log;
import android.webkit.JavascriptInterface;
import android.widget.Toast;
import android.content.ContentResolver;

public class jsi {
    Context mContext;
    String mContactName;
    String[] mSelectionArgs=new String[1];

    /** Instantiate the interface and set the context */
    jsi(Context c) {
        mContext = c;
    }

    @JavascriptInterface
    public void fetchContacts(String contactName){
		mContactName=contactName;
		Activity activity = (Activity) mContext;
		activity.runOnUiThread(new Runnable(){//As JS runs on UI thread, performing any operations on variables
			//coming from JS or calling any method on them results in exception: Error calling method on NPObject.
			//The only workaround seems to be to do such things on UIthread and store results in private attributes.
    		public void run(){
		        mSelectionArgs[0]="%"+mContactName+"%";
    		}
    	});
        String phoneNumber = null;
        Uri CONTENT_URI = ContactsContract.Contacts.CONTENT_URI;
        String _ID = ContactsContract.Contacts._ID;
        String DISPLAY_NAME = Contacts.DISPLAY_NAME;
        String HAS_PHONE_NUMBER = ContactsContract.Contacts.HAS_PHONE_NUMBER;
        Uri PhoneCONTENT_URI = ContactsContract.CommonDataKinds.Phone.CONTENT_URI;
        String Phone_CONTACT_ID = ContactsContract.CommonDataKinds.Phone.CONTACT_ID;
        String NUMBER = ContactsContract.CommonDataKinds.Phone.NUMBER;
        String Selection=Contacts.DISPLAY_NAME+" = ?";

        StringBuffer output = new StringBuffer();
        ContentResolver contentResolver = mContext.getContentResolver();
        //Didn't manage to run query with selection and selectionarg so currently just loop over every contact:(
        Cursor cursor=contentResolver.query(CONTENT_URI,null,null,null,null);
        // Loop for every contact in the phone
        if(cursor.getCount()>0){
        	Log.i("jsi", "JSI debug");
            while (cursor.moveToNext()){
                String contact_id = cursor.getString(cursor.getColumnIndex( _ID ));
                String name = cursor.getString(cursor.getColumnIndex( DISPLAY_NAME ));
                int hasPhoneNumber = Integer.parseInt(cursor.getString(cursor.getColumnIndex( HAS_PHONE_NUMBER )));
                if (hasPhoneNumber>0&&mContactName.isEmpty()==false&&name.equalsIgnoreCase(mContactName)==true
                	||hasPhoneNumber>0&&mContactName.isEmpty()==true){
                    output.append("Name:"+name+"\n");
                    // Query and loop for every phone number of the contact
                    Cursor phoneCursor = contentResolver.query(PhoneCONTENT_URI, null, Phone_CONTACT_ID + " = ?", new String[] { contact_id }, null);
                    while (phoneCursor.moveToNext()) {
                        phoneNumber = phoneCursor.getString(phoneCursor.getColumnIndex(NUMBER));
                        output.append("Phone number:"+phoneNumber+"\n");
                    }
                    phoneCursor.close();
                }
            }
            cursor.close();
            Toast.makeText(mContext, output, Toast.LENGTH_SHORT).show();
        }
        else{
            Toast.makeText(mContext, "Nothing found", Toast.LENGTH_SHORT).show();
        }
    }
}
