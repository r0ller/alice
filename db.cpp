#include "db.h"
#include <algorithm>

db* db::singleton_instance=NULL;
int (*db::fptr_store_row_data)(void *, int, char **, char **)=NULL;

db::db(){
	if(result_set.empty()==false) result_set.clear();
	result_set_size=0;
	sqlite=NULL;
	db::fptr_store_row_data=&db::store_row_data;
}

/*PUBLIC*/

db::~db(){
	destroy_result();
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

const std::multimap<unsigned int,field>& db::exec_sql(const std::string& sql){
	destroy_result();
	if(sqlite3_exec(sqlite, sql.c_str(), db::fptr_store_row_data, this, NULL)==SQLITE_OK) return result_set;
	else throw sql_execution_error();
}

std::multimap<unsigned int,field>::const_iterator db::get_row(unsigned int rowid){
	return result_set.find(rowid);
}

const std::string& db::get_field_value(unsigned int rowid, const std::string& field_name){
	std::multimap<unsigned int,field>::iterator position;

	if(result_set.empty()==false){
		for(position=result_set.find(rowid);position!=result_set.end();++position)
			if(position->second.field_name==field_name) break;
		if(position!=result_set.end()) return position->second.field_value;
	}
}

const std::multimap<unsigned int,field>& db::query_result_set(){
	return result_set;
}

unsigned int db::result_size(){
	return result_set_size;
}

/*PRIVATE*/
int db::store_row_data(void *db_instance, int nr_of_columns, char **field_values, char **fields){/*CALLBACK function for sqlite3_exec*/
	unsigned int row_index=0;
	db *p_this=NULL;
	field field;

	p_this=(db*)(db_instance);
	if(p_this->result_set.empty()==false) row_index=p_this->result_set_size;
	for(int i=0;i<nr_of_columns;++i){
		field.field_name=fields[i];
		field.field_value=field_values[i];
		p_this->result_set.insert(std::make_pair(row_index,field));
		if(i>0&&std::string (fields[0])==std::string (fields[i]))++row_index;
	}
	++p_this->result_set_size;
	return 0; 
}

void db::destroy_result(){

	if(result_set.empty()==false) result_set.clear();
	result_set_size=0;
	return;
}
