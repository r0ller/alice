package com.bitroller.hi;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognizerIntent;

public class LanguageChecker extends BroadcastReceiver{
	private static LanguageChecker languageChecker;
	private String defaultLanguage="";

	public String getDefaultLanguage(){
	  return defaultLanguage;
	}

	public static LanguageChecker getInstance(){
	  if(languageChecker==null){
		  languageChecker=new LanguageChecker();
	  }
	  return languageChecker;
	}

	@Override
	public void onReceive(Context context, Intent intent) {
		if(getResultCode()==Activity.RESULT_OK) {
			Bundle results = getResultExtras(true);
			defaultLanguage = results.getString(RecognizerIntent.EXTRA_LANGUAGE_PREFERENCE);
			if(defaultLanguage!=null){
				//TODO:set up platform specific language ids in android content
				if (defaultLanguage.contentEquals("en-US") == true || defaultLanguage.contentEquals("en-GB") == true)
					defaultLanguage = "ENG";
				else if (defaultLanguage.contentEquals("hu-HU") == true) defaultLanguage = "HUN";
				else{
					Intent setText = new Intent("hiBroadcast");
					setText.putExtra("setText", "Please, set your language preference to English (GB|US) or Hungarian.");
					context.sendBroadcast(setText);
					return;
				}
				//Toast.makeText(context, defaultLanguage, Toast.LENGTH_LONG).show();
				Intent callingIntent = new Intent(context, MainActivity.class);
				callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
				callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
				callingIntent.putExtra("tryagain", "true");
				context.startActivity(callingIntent);
			}
			else{
				Intent setText = new Intent("hiBroadcast");
				setText.putExtra("setText", "Sorry, could not determine your language preference. Please, set it to English (GB|US) or Hungarian.");
				context.sendBroadcast(setText);
				return;
			}
		}
		else{
			Intent setText = new Intent("hiBroadcast");
			setText.putExtra("setText", "Sorry, could not determine your language preference. Please, set it to English (GB|US) or Hungarian.");
			context.sendBroadcast(setText);
			return;
		}
	}
}