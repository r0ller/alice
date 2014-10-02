#include "db.h"
#include <algorithm>

db *db::singleton_instance=NULL;
int (*db::fptr_store_row_data)(void *, int, char **, char **)=NULL;

db::db(){
	sqlite=NULL;
	db::fptr_store_row_data=&db::store_row_data;
}

/*PUBLIC*/

db::~db(){
	db::singleton_instance=NULL;
}

void db::open(const std::string& filename){
	if(sqlite3_open(filename.c_str(),&sqlite)!=SQLITE_OK) throw failed_to_open_db();
	return;
}

void db::close(){
	if(sqlite3_close(sqlite)!=SQLITE_OK) throw failed_to_close_db();
	return;
}

const std::string db::error_message(){
	return sqlite3_errmsg(sqlite);
}

query_result *db::exec_sql(const std::string& sql){
	query_result *result_set=NULL;

//	std::cout<<sql<<std::endl;
	result_set=new query_result();
	if(sqlite3_exec(sqlite, sql.c_str(), db::fptr_store_row_data, result_set, NULL)!=SQLITE_OK){
		throw sql_execution_error();
	}
	if(result_set->result_rows()==0){
		delete result_set;
		result_set=NULL;
	}
	return result_set;
}

/*PRIVATE*/
int db::store_row_data(void *p_result, int nr_of_columns, char **field_values, char **fields){/*CALLBACK function for sqlite3_exec*/
	unsigned int row_index=0;
	query_result *result=NULL;
	field field;

//	std::cout<<nr_of_columns<<std::endl;
	result=(query_result*)(p_result);
	if(nr_of_columns!=0&&field_values!=NULL&&fields!=NULL){
		for(int i=0;i<nr_of_columns;++i){
			field.field_name=fields[i];
			if(field_values[i]!=NULL) field.field_value=field_values[i];
			else field.field_value.clear();
//			std::cout<<field.field_name<<":"<<field.field_value<<std::endl;
			result->insert(std::make_pair(row_index,field));
			if(i>0&&std::string (fields[0])==std::string (fields[i]))++row_index;
		}
	}
	return 0; 
}
