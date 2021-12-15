#include "logger.h"
#include "query_result.h"

/*PUBLIC*/
query_result::query_result(){
	nr_of_columns=0;
}

query_result::~query_result(){
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"query result destructor called");
}

std::multimap<unsigned int,field>::const_iterator query_result::row_at_position(unsigned int rowid) const{
	return raw_result_set.find(rowid);
}

const std::string* query_result::field_value_at_row_position(unsigned int rowid, const std::string& field_name) const{
	std::multimap<unsigned int,field>::const_iterator position;

	if(raw_result_set.empty()==false){
		for(position=raw_result_set.find(rowid);position!=raw_result_set.end();++position){
			if(position->second.field_name==field_name) break;
		}
		if(position!=raw_result_set.end()) return &position->second.field_value;
		else return NULL;
	}
    return NULL;
}

const std::multimap<unsigned int,field>& query_result::result_set() const{
	return raw_result_set;
}

unsigned int query_result::nr_of_result_rows() const{
	unsigned int size=0;

	if(raw_result_set.empty()==false){
		size=raw_result_set.size()/nr_of_columns;
	}
	return size;
}

void query_result::insert(const std::pair<unsigned int, field>& row){
    //insert() ensures that the field values for each field of the same row id are unqiue in the table
	unsigned int nr_of_inserted_columns=0;
	std::set<std::string> fields_inserted;
	std::multimap<unsigned int,field>::iterator upper_bound;
	std::set<std::pair<std::string,std::string> > field_set;

	if(raw_result_set.empty()==false){
		//check to avoid inserting a value for an existing field with the same name with the same row id
		if(field_value_at_row_position(row.first,row.second.field_name)==NULL){
			row_buffer.insert(row);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting with rowid "+std::to_string(row.first)+":"+row.second.field_name+"="+row.second.field_value+" into row buffer");
		}
	}
	else{
		row_buffer.insert(row);
		logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting with rowid "+std::to_string(row.first)+":"+row.second.field_name+"="+row.second.field_value+" into row buffer");
	}
	nr_of_inserted_columns=row_buffer.count(row.first);
	if(nr_of_inserted_columns==nr_of_columns){
		for(std::multimap<unsigned int,field>::const_iterator i=row_buffer.lower_bound(row.first),
				upper_bound=row_buffer.upper_bound(row.first);
				i!=upper_bound;++i){
			if(fields.find(i->second.field_name)!=fields.end()){
				fields_inserted.insert(i->second.field_name);
				field_set.insert(std::make_pair(i->second.field_name,i->second.field_value));
			}
		}
		if(fields_inserted!=fields){
			throw std::runtime_error("Field names to be inserted and that of the table structure do not match.");
		}
		if(row_set.insert(field_set).second==true){
			for(std::multimap<unsigned int,field>::const_iterator i=row_buffer.lower_bound(row.first),
 				upper_bound=row_buffer.upper_bound(row.first);
				i!=upper_bound;++i){
				raw_result_set.insert(*i);
				logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"inserting with rowid "+std::to_string(i->first)+":"+i->second.field_name+"="+i->second.field_value+" from row buffer into result set");
			}
			row_buffer.erase(row.first);
		}
		else{
			row_buffer.erase(row.first);
			logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"Another entry with the same content already exists in result set for row id "+std::to_string(row.first));
		}
		if(row_buffer.find(row.first)!=row_buffer.end()){
			throw std::runtime_error("Exiting, row_buffer not cleared up.");
		}
	}
	else if(nr_of_inserted_columns>nr_of_columns){
		throw std::runtime_error("Exiting, row_buffer is inconsistent");
	}
}

void query_result::append(const std::pair<unsigned int, field>& field){
	if(row_set.empty()==true){
		insert(std::make_pair(0,field.second));
	}
	else{
		insert(std::make_pair(raw_result_set.rbegin()->first+1,field.second));
	}
}

const std::pair<const unsigned int,field>* query_result::first_value_for_field_name_found(const std::string& field_name, const std::string& field_value) const{
	std::multimap<unsigned int,field>::const_iterator position;
	const std::pair<const unsigned int,field> *field_found=NULL;

	if(raw_result_set.empty()==false){
		for(position=raw_result_set.begin();position!=raw_result_set.end();++position){
			if(position->second.field_name==field_name&&position->second.field_value==field_value){
				if(field_found==NULL){
					field_found=&(*position);
					break;
				}
			}
		}
	}
	return field_found;
}

const std::pair<const unsigned int,field>* query_result::value_for_field_name_found_after_row_position(const unsigned int row_id, const std::string& field_name, const std::string& field_value) const{
	std::multimap<unsigned int,field>::const_iterator position;
	const std::pair<const unsigned int,field> *field_found=NULL;

	if(raw_result_set.empty()==false){
		for(position=row_at_position(row_id+1);position!=raw_result_set.end();++position){
			if(position->second.field_name==field_name&&position->second.field_value==field_value){
				if(field_found==NULL){
					field_found=&(*position);
					break;
				}
			}
		}
	}
	return field_found;
}

void query_result::keep(const std::set<unsigned int>& rowids){
	std::multimap<unsigned int,field>::const_iterator position,upper_bound;
	std::set<std::pair<std::string,std::string> > field_set;

	for(position=raw_result_set.begin();position!=raw_result_set.end();++position){
		if(rowids.find(position->first)==rowids.end()){
			for(auto i=raw_result_set.lower_bound(position->first),
				upper_bound=raw_result_set.upper_bound(position->first);
				i!=upper_bound;++i){
				field_set.insert(std::make_pair(i->second.field_name,i->second.field_value));
			}
			raw_result_set.erase(position->first);
			row_set.erase(field_set);
		}
	}
}

void query_result::append(const query_result& appending_entries){

	for(std::multimap<unsigned int,field>::const_iterator field=appending_entries.result_set().begin();
			field!=appending_entries.result_set().end();++field){
		append(*field);
	}
}

void query_result::set_metadata(const unsigned int colnr, const char** field_names){
	if(nr_of_columns==0) nr_of_columns=colnr;
	if(fields.empty()==true){
		for(unsigned int i=0;i<nr_of_columns;++i){
					fields.insert(field_names[i]);
		}
	}
}
