#include "query_result.h"

/*PUBLIC*/
query_result::query_result(){
}

query_result::~query_result(){
}

std::multimap<unsigned int,field>::const_iterator query_result::get_row(unsigned int rowid){
	return raw_result_set.find(rowid);
}

const std::string& query_result::get_field_value(unsigned int rowid, const std::string& field_name){
	std::multimap<unsigned int,field>::const_iterator position;

	if(raw_result_set.empty()==false){
		for(position=raw_result_set.find(rowid);position!=raw_result_set.end();++position){
			if(position->second.field_name==field_name) break;
		}
		if(position!=raw_result_set.end()) return position->second.field_value;
	}
}

const std::multimap<unsigned int,field>& query_result::result_set(){
	return raw_result_set;
}

unsigned int query_result::result_rows(){
	std::multimap<unsigned int,field>::const_iterator position;
	unsigned int size=0;

	if(raw_result_set.empty()==false){
		position=raw_result_set.begin();
		size=raw_result_set.size()/raw_result_set.count(position->first);
	}
	return size;
}

void query_result::insert(const std::pair<unsigned int, field>& row){
	raw_result_set.insert(row);
}

const std::pair<unsigned int,field>& query_result::find_field_value(const std::string& field_name, const std::string& field_value){
	std::multimap<unsigned int,field>::const_iterator position, field_found;

	//The returning parameter could be as simple as an uint: 0 meaning no hit, and >0 meaning the row number.
	//However, in the db layer (db.cpp) the sqlite callback function (store_row_data) is implemented as
	//starting row numbers from 0 as being quite a common practice in C/C++. Since then, this has been used
	//for constructing other logics in many places. So for the time being and for historical reasons, the
	//row numbering remains as it is, but when exceeding the int type limit for row numbers and changing to long,
	//it may need to be reconsidered.
	field_found=raw_result_set.end();
	if(raw_result_set.empty()==false){
		for(position=raw_result_set.begin();position!=raw_result_set.end();++position){
			if(position->second.field_name==field_name&&position->second.field_value==field_value){
				if(field_found==raw_result_set.end()){
					field_found=position;
				}
				else{
					//TODO: throw exception
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	return *field_found;
}
void query_result::keep(const std::set<unsigned int>& rowids){
	std::multimap<unsigned int,field>::const_iterator position;

	for(position=raw_result_set.begin();position!=raw_result_set.end();++position){
		if(rowids.find(position->first)==set::end) raw_result_set.erase(position->first);
	}
}
