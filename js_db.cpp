#include "js_db.h"

js_db::js_db(){
}

js_db::~js_db(){
}

void js_db::open(const std::string& filename){
}

void js_db::close(){
}

const std::string js_db::error_message(){
	return std::string();
}

query_result *js_db::exec_sql(const std::string& sql){
	return NULL;
}
