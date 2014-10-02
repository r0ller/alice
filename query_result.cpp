#include "query_result.h"
#include <sstream>

/*PUBLIC*/
query_result::query_result(){
	nr_of_columns=0;
}

query_result::~query_result(){
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
	//insert() ensures that the field values for each field with the same row id are unqiue in the table
	unsigned int nr_of_inserted_columns=0;
	std::set<std::string> fields_inserted;
	const std::pair<const unsigned int,field> *field_found=NULL;
	std::multimap<unsigned int,field> fields_found;
	std::set<unsigned int> keys_found;
	bool entry_already_exists=false;
	std::multimap<unsigned int,field>::iterator upper_bound,erase_invalidation_iterator_copy;
	std::ostringstream out;

	if(raw_result_set.empty()==false){
		//check to avoid inserting a value for an existing field with the same name with the same row id
		if(field_value_at_row_position(row.first,row.second.field_name)==NULL){
			row_buffer.insert(row);
//			out.str(std::string());
//			out.clear();
//			out<<row.first;
//			std::cout<<"inserting with rowid "<<out.str()<<":"<<row.second.field_name<<"="<<row.second.field_value<<" into row buffer"<<std::endl;
		}
	}
	else{
		row_buffer.insert(row);
//		out.str(std::string());
//		out.clear();
//		out<<row.first;
//		std::cout<<"inserting with rowid "<<out.str()<<":"<<row.second.field_name<<"="<<row.second.field_value<<" into row buffer"<<std::endl;
	}
	nr_of_inserted_columns=row_buffer.count(row.first);
	if(nr_of_inserted_columns==nr_of_columns){
		for(std::multimap<unsigned int,field>::const_iterator i=row_buffer.lower_bound(row.first),
				upper_bound=row_buffer.upper_bound(row.first);
				i!=upper_bound;++i){
			if(fields.find(i->second.field_name)!=fields.end()){
				fields_inserted.insert(i->second.field_name);
//				std::cout<<"looking up "<<i->second.field_name<<"="<<i->second.field_value<<" from row buffer in result set"<<std::endl;
				field_found=first_value_for_field_name_found(i->second.field_name,i->second.field_value);
				while(field_found!=NULL){
					fields_found.insert(*field_found);
					keys_found.insert(field_found->first);
//					out.str(std::string());
//					out.clear();
//					out<<field_found->first;
//					std::cout<<i->second.field_name<<"="<<i->second.field_value<<" found in result set in row "<<out.str()<<std::endl;
					field_found=value_for_field_name_found_after_row_position(field_found->first,i->second.field_name,i->second.field_value);
				}
			}
		}
		if(fields_inserted!=fields){
			exit(EXIT_FAILURE);//TODO: throw exception, field names to be inserted and that of the table structure do not match
		}
		for(std::set<unsigned int>::const_iterator i=keys_found.begin();i!=keys_found.end();++i){
			if(fields_found.count(*i)==nr_of_columns){
				entry_already_exists=true;
				row_buffer.erase(row.first);
//				out.str(std::string());
//				out.clear();
//				out<<*i;
//				std::cout<<"entry already exists in result set with row id "<<out.str()<<std::endl;
				break;
			}
		}
		if(entry_already_exists==false){
			for(std::multimap<unsigned int,field>::const_iterator i=row_buffer.lower_bound(row.first),
 				upper_bound=row_buffer.upper_bound(row.first);
				i!=upper_bound;++i){
				raw_result_set.insert(*i);
//				out.str(std::string());
//				out.clear();
//				out<<i->first;
//				std::cout<<"inserting with rowid "<<out.str()<<":"<<i->second.field_name<<"="<<i->second.field_value<<" from row buffer into result set"<<std::endl;
			}
			row_buffer.erase(row.first);
		}
		if(row_buffer.find(row.first)!=row_buffer.end()){
			std::cout<<"exiting, row_buffer not cleared up"<<std::endl;
			exit(EXIT_FAILURE);//TODO: throw exception
		}
	}
	else if(nr_of_inserted_columns>nr_of_columns){
		std::cout<<"exiting, row_buffer is inconsistent"<<std::endl;
		exit(EXIT_FAILURE);//TODO: throw exception
	}
}

void query_result::append(const std::pair<unsigned int, field>& field){
	insert(std::make_pair(nr_of_result_rows(),field.second));
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
	std::multimap<unsigned int,field>::const_iterator position;

	for(position=raw_result_set.begin();position!=raw_result_set.end();++position){
		if(rowids.find(position->first)==rowids.end()) raw_result_set.erase(position->first);
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
