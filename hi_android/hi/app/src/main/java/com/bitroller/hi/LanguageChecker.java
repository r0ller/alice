package com.bitroller.hi;

import android.widget.Toast;

import static android.widget.Toast.*;

public class LanguageChecker{
	private static LanguageChecker languageChecker;
	private String defaultLanguage="";

	public String getDefaultLanguage(){
		if(defaultLanguage.isEmpty()==true){
			DatabaseHelper hiDb=new DatabaseHelper();
			hiDb.open("hi.db");
			String[] languageEntry=hiDb.exec_sql("SELECT value FROM settings WHERE key='language';");
			if(languageEntry.length>0){//languageEntry[0]:rowid,[1]:fieldname,[2]:value
				defaultLanguage = languageEntry[2];
			}
			hiDb.close();
		}
		return defaultLanguage;
	}
	public void setLanguage(String language){
		defaultLanguage = language;
		DatabaseHelper hiDb=new DatabaseHelper();
		hiDb.open("hi.db");
		hiDb.exec_sql("UPDATE settings SET value='"+language+"' where key='language';");
		hiDb.close();
	}

	public static LanguageChecker getInstance(){
	  if(languageChecker==null){
		  languageChecker=new LanguageChecker();
	  }
	  return languageChecker;
	}
}