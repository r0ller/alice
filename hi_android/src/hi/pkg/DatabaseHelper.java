package hi.pkg;

import android.util.Log;
import android.util.Pair;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Set;
import java.util.Vector;

import android.database.sqlite.SQLiteOpenHelper;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;

public class DatabaseHelper {

	private SQLiteDatabase sqlite;
	private String error_message;
	private Context context;
	private String db_path;
	private Set<String> columns;

    public DatabaseHelper() {
    	context=MainActivity.getContext();
        PackageManager m = context.getPackageManager();
        String s = context.getPackageName();
        try{
	        PackageInfo p = m.getPackageInfo(s, 0);
	        db_path = p.applicationInfo.dataDir+"/";
        }
        catch (PackageManager.NameNotFoundException e) {
            Log.w("hi", "Error: Package name not found ", e);
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

	public void open(String filename){
		try{
			sqlite=SQLiteDatabase.openDatabase(db_path+filename,null,SQLiteDatabase.OPEN_READONLY);
		}
        catch (SQLException e){
            error_message=e.toString();
        }
	}

	public void close(){
    	sqlite.close();
	}

	public String error_message(){
		String errmsg=error_message;
		error_message=null;
		return errmsg;
	}

	public String[] exec_sql(String sql){
		Cursor cursor=null;
		String[] raw_result_array=null;

		try{
			cursor=sqlite.rawQuery(sql, null);
		}
        catch (SQLException e){
            error_message=e.toString();
        }
		List<String> raw_result_list = new ArrayList<String>();
        if(cursor.getCount()>0){
    		int rowcount=0;
    		columns=new HashSet<String>();
            while(cursor.moveToNext()==true){
            	for(int i=0;i<cursor.getColumnCount();++i){
            		raw_result_list.add(Integer.toString(rowcount));
            		raw_result_list.add(cursor.getColumnName(i));
           			columns.add(cursor.getColumnName(i));
            		raw_result_list.add(cursor.getString(i));
            	}
            	++rowcount;
            }
            cursor.close();
            raw_result_array = new String[raw_result_list.size()];
            raw_result_list.toArray(raw_result_array);
        }
		return raw_result_array;
	}

	public String[] get_metadata(){
		return columns.toArray(new String[columns.size()]);
	}
}