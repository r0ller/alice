#include "sqlite_db.h"

int (*sqlite_db::fptr_store_row_data)(void *, int, char **, char **)=NULL;

sqlite_db::sqlite_db(){
	sqlite=NULL;
	sqlite_db::fptr_store_row_data=&sqlite_db::store_row_data;
}

sqlite_db::~sqlite_db(){
	sqlite=NULL;
}

void sqlite_db::open(const std::string& filename){
	if(sqlite3_open(filename.c_str(),&sqlite)!=SQLITE_OK) throw failed_to_open_db();
	return;
}

void sqlite_db::close(){
	if(sqlite3_close(sqlite)!=SQLITE_OK) throw failed_to_close_db();
	return;
}

const std::string sqlite_db::error_message(){
	return sqlite3_errmsg(sqlite);
}

query_result *sqlite_db::exec_sql(const std::string& sql){
	query_result *result_set=NULL;

//	std::cout<<sql<<std::endl;
	result_set=new query_result();
	if(sqlite3_exec(sqlite, sql.c_str(), sqlite_db::fptr_store_row_data, result_set, NULL)!=SQLITE_OK){
		throw sql_execution_error();
	}
	if(result_set->nr_of_result_rows()==0){
		delete result_set;
		result_set=NULL;
	}
	return result_set;
}

/*PRIVATE*/
int sqlite_db::store_row_data(void *p_result, int nr_of_columns, char **field_values, char **fields){/*CALLBACK function for sqlite3_exec*/
	unsigned int row_index=0;
	query_result *result=NULL;
	field field;

//	std::cout<<nr_of_columns<<std::endl;
	result=(query_result*)(p_result);
	if(nr_of_columns!=0&&field_values!=NULL&&fields!=NULL){
		result->set_metadata(nr_of_columns,(const char**) &(*fields));
		for(unsigned int i=0;i<nr_of_columns;++i){
			field.field_name=fields[i];
			if(field_values[i]!=NULL) field.field_value=field_values[i];
			else field.field_value.clear();
//			std::cout<<field.field_name<<":"<<field.field_value<<std::endl;
			row_index=result->result_set().size()/nr_of_columns;
			result->insert(std::make_pair(row_index,field));
		}
	}
	return 0; 
}