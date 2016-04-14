package hi.pkg;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.util.Log;

public class LanguageChecker extends BroadcastReceiver{
	private static LanguageChecker languageChecker;
	private String defaultLanguage;

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
	Bundle results=getResultExtras(true);
	defaultLanguage=results.getString(RecognizerIntent.EXTRA_LANGUAGE_PREFERENCE);
	//TODO:Read hi.db mapping table to convert from platform specific language IDs (plid) to hi specific ones (lid) 
	if(defaultLanguage.contentEquals("en-GB")==true) defaultLanguage="ENG";
	else if(defaultLanguage.contentEquals("hu-HU")==true) defaultLanguage="HUN";
//	Toast.makeText(context, defaultLanguage, Toast.LENGTH_LONG).show();
    Intent callingIntent = new Intent(context, MainActivity.class);
    callingIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
    callingIntent.addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
    callingIntent.putExtra("lid", defaultLanguage);
    context.startActivity(callingIntent);
	}
}