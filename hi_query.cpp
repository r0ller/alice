#include <iostream>
#include <tuple>
#include <set>
#include <vector>
#include <string>
#include "db_factory.h"
#include "query_result.h"
#include "rapidjson/document.h"

void apply_filter(const query_result *dependencies,const std::string& lexeme,const std::string& d_key,const std::string& dependency, const std::string& ref_d_key,const unsigned int& distance,const std::string& distance_op,const unsigned int& lexeme_row_nr,const bool start_lexeme_found,const unsigned int& current_row_nr,const unsigned int& current_distance,std::set<std::pair<unsigned int,unsigned int>>& row_nrs_found){
    //1)find lexeme with d_key, store row id, set distance to 0
    //2)follow its dependencies increasing current_distance till dependency is found
    //(it may happen that a dependency is found but the distance_op is not fulfilled but the
    //dependency chain continues -> in such cases go on as the required dependency may be found deeper)
    //3)if no dependency with ref_d_key is found for the branch, go to step 1)
    //4)if dependency with ref_d_key is found for the branch, fulfilling distance_op
    //store the row nr of the lexeme and that of the dependency (the row nr in which the dependency is in the lexeme field)
    //and go on to step 1) to look for other matches
    //5)return the row nr pairs of the lexemes and corresponding dependencies found
    if(start_lexeme_found==true){
        const std::pair<const unsigned int,field> *row_nr_field=dependencies->value_for_field_name_found_after_row_position(current_row_nr,"lexeme",lexeme);
        if(row_nr_field!=NULL){
            if(row_nr_field->second.field_value==dependency){
                std::string row_d_key=*dependencies->field_value_at_row_position(row_nr_field->first,"d_key");
                if(row_d_key==ref_d_key){
                    if(distance_op=="<"&&current_distance<distance
                        ||distance_op=="<="&&current_distance<=distance
                        ||distance_op=="="&&current_distance==distance
                        ||distance_op==">="&&current_distance>=distance
                        ||distance_op==">"&&current_distance>distance){
                        row_nrs_found.insert(std::make_pair(lexeme_row_nr,row_nr_field->first));
                    }
                    else{
                        //TODO: handle error: unknown operator
                    }
                }
            }
            std::string row_dependency=*dependencies->field_value_at_row_position(row_nr_field->first,"dependency");
            std::string row_ref_d_key=*dependencies->field_value_at_row_position(row_nr_field->first,"ref_d_key");
            if(row_dependency.empty()==false&&std::atoi(row_ref_d_key.c_str())>0){
                apply_filter(dependencies,row_dependency,row_ref_d_key,dependency,ref_d_key,distance,distance_op,lexeme_row_nr,start_lexeme_found,row_nr_field->first,current_distance+1,row_nrs_found);
            }
            //unsigned int row_nr=row_nr_field->first;
            //row_nr_field=dependencies->value_for_field_name_found_after_row_position(row_nr_field->first,"lexeme",lexeme);
            //if(row_nr_field!=NULL){
                apply_filter(dependencies,lexeme,d_key,dependency,ref_d_key,distance,distance_op,lexeme_row_nr,start_lexeme_found,row_nr_field->first,current_distance+1,row_nrs_found);
            //}
        }
    }
    else{
        unsigned int dependencies_size=dependencies->nr_of_result_rows();
        for(unsigned int i=lexeme_row_nr;i<dependencies_size;++i){
            std::string row_lexeme=*dependencies->field_value_at_row_position(i,"lexeme");
            if(row_lexeme==lexeme){
                std::string row_d_key=*dependencies->field_value_at_row_position(i,"d_key");
                if(row_d_key==d_key){
                    std::string row_dependency=*dependencies->field_value_at_row_position(i,"dependency");
                    std::string row_ref_d_key=*dependencies->field_value_at_row_position(i,"ref_d_key");
                    if(row_dependency.empty()==false&&std::atoi(row_ref_d_key.c_str())>0){
                        apply_filter(dependencies,row_dependency,row_ref_d_key,dependency,ref_d_key,distance,distance_op,i,true,i,0,row_nrs_found);
                    }
                }
            }
        }
    }
}

bool check_dependencies(rapidjson::Value& dependency_filters,query_result *dependencies){
    //TODO: apply filter conditions as outlined below
    //This shall call a recursive function that traverses the dependencies
    //to find the lexeme and its dependency in each filter entry.
    std::multimap<std::tuple<unsigned int,unsigned int,std::string,unsigned int,std::string,unsigned int>,std::set<std::pair<unsigned int,unsigned int>>> filter_nr_to_dependencies_rows_map;//accessing dependency_filters[index] is allowed
    std::map<unsigned int,unsigned int> nr_of_filters_applied_on_filter_nr;
    unsigned int current_filter_nr=0;
    unsigned int current_filter_counter=0;
    for(auto& dependencyObject:dependency_filters.GetArray()){
        if(dependencyObject.HasMember("filter_nr")==true
            &&dependencyObject.HasMember("filter_d_counter")==true
            &&dependencyObject.HasMember("filter_nr_d_ref")==true
            &&dependencyObject.HasMember("lexeme")==true
            &&dependencyObject.HasMember("d_key")==true
            &&dependencyObject.HasMember("distance")==true
            &&dependencyObject.HasMember("distance_op")==true
            &&dependencyObject.HasMember("ref_d_filter_nr")==true
            &&dependencyObject.HasMember("dependency")==true
            &&dependencyObject.HasMember("ref_d_key")==true){
            if(current_filter_nr==0) current_filter_nr=dependencyObject["filter_nr"].GetUint();
            else if(current_filter_nr!=dependencyObject["filter_nr"].GetUint()){
                //order filters in filter_nr_to_dependencies_rows_map by their number of filter_d_counters descending so the filter having the most entries is on top
                unsigned int nr_of_filters_applied=0;
                for(auto&& j:filter_nr_to_dependencies_rows_map){
                    if(std::get<0>(j.first)==current_filter_nr) ++nr_of_filters_applied;
                }
                if(nr_of_filters_applied<current_filter_counter) return false;
                nr_of_filters_applied_on_filter_nr.insert(std::make_pair(nr_of_filters_applied,current_filter_nr));
                current_filter_nr=dependencyObject["filter_nr"].GetUint();
            }
            current_filter_counter=dependencyObject["filter_d_counter"].GetUint();
            std::set<std::pair<unsigned int,unsigned int>> dependencies_rows;
            apply_filter(dependencies,dependencyObject["lexeme"].GetString(),std::to_string(dependencyObject["d_key"].GetUint()),dependencyObject["dependency"].GetString(),std::to_string(dependencyObject["ref_d_key"].GetUint()),dependencyObject["distance"].GetUint(),dependencyObject["distance_op"].GetString(),0,false,0,0,dependencies_rows);
            if(dependencies_rows.empty()==false){
                filter_nr_to_dependencies_rows_map.insert(std::make_pair(std::make_tuple(dependencyObject["filter_nr"].GetUint(),dependencyObject["filter_d_counter"].GetUint(),dependencyObject["lexeme"].GetString(),dependencyObject["d_key"].GetUint(),dependencyObject["dependency"].GetString(),dependencyObject["ref_d_key"].GetUint()),dependencies_rows));
            }
            //cross reference (>) examples (see json field structure in hi_query comment):
            //example 1: a>b,b>c (b is the same)
            //1,1,0,V,1,?,?,0,N,1 (V1 (w/o reference i.e. 0) has dependency N1 (w/o reference i.e. 0))
            //2,1,1/1,N,1,?,?,0,A,1 (N1 (referencing the dependency from 1/1) has dependency A1 (w/o reference i.e. 0))
            //example 2: a>c,b>c (c is the same)
            //1,1,0,V,1,?,?,0,A,1 (V1 (w/o reference i.e. 0) has dependency N1 (w/o reference i.e. 0))
            //2,1,0,N,1,?,?,1/1,A,1 (N1 (w/o reference i.e. 0) has dependency A1 (referencing the dependency from 1/1))
            //example 3a: a>c,b>a is not supported yet, equals if referenced as: b>a,a>c which is example 1.
            //example 3b: a>c,b>a is supported if b>a does not refer to 'a' in a>c only uses the same lexeme and d_key of that 'a'
            //example 4a: a>b,a>c is not supported, shall be done by using the same filter_nr
            //example 4a: a>b,a>c is supported if 'a' in a>c does not refer to 'a' in a>b only uses the lexeme and d_key of that 'a'
        }
        else {
            //TODO: handle error
        }
    }
    //-check cross references (how?: apply_filter() must return not only the row nr of the lexeme
    //first found but the last entry's row nr as well in which the dependency is found in the
    //dependency field) and leave all dependencies_rows entries that satisfy the cross refs criteria
    //(if there are no cross refs, leave all entries as they are),
    //after which delete the dependencies_rows preserved for this filter from all other filters
    //but if that deletion removed all entries from an already checked filter, don't delete the
    //last one but then delete that from the currently checked filter.
    //Theoretically, this postponed deletion ensures a best fit logic.
    unsigned int nr_of_filters_applied=0;
    for(auto&& j:filter_nr_to_dependencies_rows_map){
        if(std::get<0>(j.first)==current_filter_nr) ++nr_of_filters_applied;
    }
    if(nr_of_filters_applied<current_filter_counter) return false;
    nr_of_filters_applied_on_filter_nr.insert(std::make_pair(nr_of_filters_applied,current_filter_nr));
    //loop over nr_of_filters_applied_on_filter_nr in reverse direction to begin with the entry having the most filters
    for(auto&& rev_it=nr_of_filters_applied_on_filter_nr.rbegin();rev_it!=nr_of_filters_applied_on_filter_nr.rend();++rev_it){
        //loop over the filter conditions
        for(auto& dependencyObject:dependency_filters.GetArray()){
            unsigned int int_filter_nr_d_ref=0;
            unsigned int int_filter_counter_d_ref=0;
            //check if there's a lexeme to dependency reference in the filter
            if(dependencyObject.HasMember("filter_nr_d_ref")==true){
                std::string filter_nr_d_ref=dependencyObject["filter_nr_d_ref"].GetString();
                std::string::size_type slash_index=filter_nr_d_ref.find_first_of('/');
                if(slash_index!=std::string::npos){
                    int_filter_nr_d_ref=std::atoi(filter_nr_d_ref.substr(0,slash_index).c_str());
                    int_filter_counter_d_ref=std::atoi(filter_nr_d_ref.substr(slash_index+1).c_str());
                }
            }
            unsigned int int_ref_d_filter_nr=0;
            unsigned int int_ref_d_filter_counter=0;
            //check if there's a dependency to dependency reference in the filter
            if(dependencyObject.HasMember("ref_d_filter_nr")==true){
                std::string ref_d_filter_nr=dependencyObject["ref_d_filter_nr"].GetString();
                std::string::size_type slash_index=ref_d_filter_nr.find_first_of('/');
                if(slash_index!=std::string::npos){
                    int_ref_d_filter_nr=std::atoi(ref_d_filter_nr.substr(0,slash_index).c_str());
                    int_ref_d_filter_counter=std::atoi(ref_d_filter_nr.substr(slash_index+1).c_str());
                }
            }
            //check if there's any reference in the filter
            if(((int_filter_nr_d_ref>0&&int_filter_counter_d_ref>0)
                ||(int_ref_d_filter_nr>0&&int_ref_d_filter_counter>0))
                &&rev_it->second!=dependencyObject["filter_nr"].GetUint()&&(rev_it->second==int_filter_nr_d_ref||rev_it->second==int_ref_d_filter_nr)){
                std::set<unsigned int> filter_to_match_dependency_rows;
                //collect the referencing lexeme/dependency row numbers found for the filter entry
                for(auto&& filter_nr_row:filter_nr_to_dependencies_rows_map){
                    if(dependencyObject["filter_nr"].GetUint()==std::get<0>(filter_nr_row.first)&&dependencyObject["filter_d_counter"].GetUint()==std::get<1>(filter_nr_row.first)){
                        if(int_filter_nr_d_ref>0&&int_filter_counter_d_ref>0){
                            for(auto&& dependency_row:filter_nr_row.second){
                                filter_to_match_dependency_rows.insert(dependency_row.first);
                            }
                        }
                        else{//int_ref_d_filter_nr>0&&int_ref_d_filter_counter>0
                            for(auto&& dependency_row:filter_nr_row.second){
                                filter_to_match_dependency_rows.insert(dependency_row.second);
                            }
                        }
                    }
                }
                //get referenced filter from the referencing lexeme/dependency
                if(filter_to_match_dependency_rows.empty()==false){
                    std::string referenced_filter_dependency="";
                    unsigned int referenced_filter_d_key=0;
                    unsigned int referenced_filter_nr=0;
                    unsigned int referenced_filter_counter=0;
                    if(int_filter_nr_d_ref>0&&int_filter_counter_d_ref>0){
                        referenced_filter_nr=int_filter_nr_d_ref;
                        referenced_filter_counter=int_filter_counter_d_ref;
                        referenced_filter_dependency=dependencyObject["lexeme"].GetString();
                        referenced_filter_d_key=dependencyObject["d_key"].GetUint();
                    }
                    else{
                        referenced_filter_nr=int_ref_d_filter_nr;
                        referenced_filter_counter=int_ref_d_filter_counter;
                        referenced_filter_dependency=dependencyObject["dependency"].GetString();
                        referenced_filter_d_key=dependencyObject["ref_d_key"].GetUint();
                    }
                    std::multimap<std::tuple<unsigned int,unsigned int,std::string,unsigned int,std::string,unsigned int>,std::set<std::pair<unsigned int,unsigned int>>>::iterator filter_nr_row;
                    //find the filter entry referenced
                    for(filter_nr_row=filter_nr_to_dependencies_rows_map.begin();filter_nr_row!=filter_nr_to_dependencies_rows_map.end();++filter_nr_row){
                        if(referenced_filter_nr==std::get<0>(filter_nr_row->first)
                            &&referenced_filter_counter==std::get<1>(filter_nr_row->first)
                            &&referenced_filter_dependency==std::get<4>(filter_nr_row->first)
                            &&referenced_filter_d_key==std::get<5>(filter_nr_row->first)){
                            break;
                        }
                    }
                    if(filter_nr_row==filter_nr_to_dependencies_rows_map.end()){
                        return false;
                    }
                    //delete dependencies found for the filter if not referenced
                    for(auto&& dependency_row=filter_nr_row->second.begin();dependency_row!=filter_nr_row->second.end();){
                        std::string filter_dependency_level=*dependencies->field_value_at_row_position(dependency_row->second,"level");
                        bool dependency_referenced=false;
                        for(auto&& referencing_row:filter_to_match_dependency_rows){
                            std::string referencing_row_level=*dependencies->field_value_at_row_position(referencing_row,"level");
                            //if the stack level of the dependency of referencing_row and that of filter_dependency
                            //are the same in the analysis dependency tree, they can be considered the same
                            if(referencing_row_level==filter_dependency_level){
                                dependency_referenced=true;
                                break;
                            }
                        }
                        if(dependency_referenced==false){
                            dependency_row=filter_nr_row->second.erase(dependency_row);
                        }
                        else{
                            ++dependency_row;
                        }
                    }
                    if(filter_nr_row->second.empty()==true){//no reference matched the dependencies found for the filter nr/counter
                        return false;
                    }
                    else{//more than one entry may be referenced but leave only one (the first) entry ...
                        std::pair<unsigned int,unsigned int> dependency_validated_for_filter_nr_counter;
                        for(auto&& dependency_row=filter_nr_row->second.begin();dependency_row!=filter_nr_row->second.end();){
                            if(dependency_row!=filter_nr_row->second.begin()){
                                dependency_row=filter_nr_row->second.erase(dependency_row);
                            }
                            else{//copy the first entry so it can be looked up and deleted elsewhere
                                dependency_validated_for_filter_nr_counter=*dependency_row;
                                ++dependency_row;
                            }
                        }
                        //... but delete it from all other filter_nr_to_dependencies_rows_map entries' second member (dependencies_rows)
                        for(filter_nr_row=filter_nr_to_dependencies_rows_map.begin();filter_nr_row!=filter_nr_to_dependencies_rows_map.end();++filter_nr_row){
                            if(referenced_filter_nr!=std::get<0>(filter_nr_row->first)&&referenced_filter_counter!=std::get<1>(filter_nr_row->first)){
                                for(auto&& dependency_row=filter_nr_row->second.begin();dependency_row!=filter_nr_row->second.end();){
                                    if(dependency_validated_for_filter_nr_counter==*dependency_row){
                                        dependency_row=filter_nr_row->second.erase(dependency_row);
                                    }
                                    else{
                                        ++dependency_row;
                                    }
                                }
                                if(filter_nr_row->second.empty()==true){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

const char *hi_query_original(const char *db_uri, const char* p_root_lexeme, const unsigned int root_d_key, const char* p_dependencies){
//dependencies: [{filter_nr: n, filter_d_counter: n, filter_nr_d_ref: filter_nr/filter_d_counter, lexeme: "", d_key: n, distance (>=0): n, distance_op (<=,<,=,>,>=): n, ref_d_filter_nr: filter_nr/filter_d_counter, dependency: "", ref_d_key: n},...]
//Tests:
    //[{filter_nr: n, filter_d_counter: n, filter_nr_d_ref: filter_nr/filter_d_counter, lexeme: "", d_key: n, distance (>=0): n, distance_op (<=,<,=,>,>=): n, ref_d_filter_nr: filter_nr/filter_d_counter, dependency: "", ref_d_key: n},...]
    //test1: look for analyses with root 'BEENGV-1' and find 'EXECUTABLEENGA-1' with no dependency
    //analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":[{\"filter_nr\": 1,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"EXECUTABLEENGA\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"\",\"ref_d_key\":0}]}");
    //test2: look for analyses with root 'BEENGV-1' and find 'BEENGV-1' with dependency 'EXECUTABLEENGA-1'
    //analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
    //"{\"filter_nr\": 1,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"EXECUTABLEENGB\",\"ref_d_key\":1}]}");
    //test3: look for analyses with root 'BEENGV-1' and find 'BEENGV-1' with dependency 'EXECUTABLEENGA-1'
    //-look for analyses with root 'BEENGV-1' and find 'BEENGV-1' with dependency 'CON-1'
    //analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
    //"{\"filter_nr\": 1,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"distance\":2,\"distance_op\":\"=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1},"
    //"{\"filter_nr\": 1,\"filter_d_counter\": 2,\"filter_nr_d_ref\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"distance\":8,\"distance_op\":\"=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"CON\",\"ref_d_key\":1}]}");
    //test4: look for analyses with root 'BEENGV-1' and find 'BEENGV-1' with dependency 'FILEBEPROP-1'
    //-look for analyses with root 'BEENGV-1' and find 'FILEBEPROP-1' (referencing 1/1 FILEBEPROP-1) with dependency 'EXECUTABLEENGA-1'
    //-look for analyses with root 'BEENGV-1' and find 'FILEBEPROP-1' (referencing 1/1 FILEBEPROP-1) with dependency 'CON-1'
    //analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
    //"{\"filter_nr\": 1,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"FILEBEPROP\",\"ref_d_key\":1},"
    //"{\"filter_nr\": 2,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"1/1\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1},"
    //"{\"filter_nr\": 2,\"filter_d_counter\": 2,\"filter_nr_d_ref\":\"1/1\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"CON\",\"ref_d_key\":1}]}");
    //test5: look for analyses with root 'BEENGV-1' and find 'BEENGV-1' with dependency 'EXECUTABLEENGA-1'
    //-look for analyses with root 'BEENGV-1' and find 'FILEBEPROP-1' with dependency 'EXECUTABLEENGA-1' (referencing 1/1 EXECUTABLEENGA-1)
    //-look for analyses with root 'BEENGV-1' and find 'FILEBEPROP-1' with dependency 'CON-1'
    //analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
    //"{\"filter_nr\": 1,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1},"
    //"{\"filter_nr\": 2,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"1/1\",\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1},"
    //"{\"filter_nr\": 2,\"filter_d_counter\": 2,\"filter_nr_d_ref\":\"\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"CON\",\"ref_d_key\":1}]}");

    db *sqlite=NULL;
    query_result *result=NULL;
    std::string analyses_found;
    char *p_analyses_found=NULL;
    //std::vector<std::tuple<unsigned int, std::string, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, std::string, unsigned int>> dependencies;

    std::string root_lexeme=std::string(p_root_lexeme);
    rapidjson::Document jsondoc;
    jsondoc.Parse(p_dependencies);
    if(jsondoc.HasMember("dependencies")==true){
        rapidjson::Value& dependenciesArray=jsondoc["dependencies"];
        if(dependenciesArray.IsArray()==true&&dependenciesArray.Size()>0){
            sqlite=db_factory::get_instance();
            sqlite->open(db_uri);
            std::set<std::string> lexemes;
            for(auto& dependencyObject:dependenciesArray.GetArray()){
                if(dependencyObject.HasMember("lexeme")==true) lexemes.insert(dependencyObject["lexeme"].GetString());
                else {
                    //TODO: lexeme is obligatory, handle if not present
                }
                if(dependencyObject.HasMember("dependency")==true) lexemes.insert(dependencyObject["dependency"].GetString());
                else {
                    //TODO: is dependency obligatory? probably not ...
                }
            }
            std::string query="select count(*) as lexeme_count,source,timestamp,sentence,rank,mood from analyses_deps where ";
            for(auto&& lexeme:lexemes){
                query+="lexeme='"+lexeme+"' or ";
            }
            query=query.substr(0,query.length()-4);
            query+=" group by source,timestamp,sentence,rank,mood order by lexeme_count desc;";
            result=sqlite->exec_sql(query);
            if(result==NULL){
                //TODO: return whatever
            }
            //loop over result and get unique keys
            std::set<std::tuple<std::string,std::string,std::string,std::string,std::string>> andeps_keys;
            unsigned int result_size=result->nr_of_result_rows();
            for(unsigned int i=0;i<result_size;++i){
                std::string source=*result->field_value_at_row_position(i,"source");
                std::string timestamp=*result->field_value_at_row_position(i,"timestamp");
                std::string sentence=*result->field_value_at_row_position(i,"sentence");
                std::string rank=*result->field_value_at_row_position(i,"rank");
                std::string mood=*result->field_value_at_row_position(i,"mood");
                std::tuple<std::string,std::string,std::string,std::string,std::string> andeps_key=std::make_tuple(source,timestamp,sentence,rank,mood);
                andeps_keys.insert(andeps_key);
            }
            delete result;
            //loop over result and get entries whose root match root_word, root_lexeme and root_d_key
            for(auto&& key:andeps_keys){
                std::string query="select * from analyses_deps where source='"+std::get<0>(key)
                    +"' and timestamp='"+std::get<1>(key)
                    +"' and sentence='"+std::get<2>(key)
                    +"' and rank='"+std::get<3>(key)
                    +"' and mood='"+std::get<4>(key)+"' order by counter;";
                result=sqlite->exec_sql(query);
                if(result==NULL){
                    //TODO: do whatever
                }
                std::string lexeme=*result->field_value_at_row_position(0,"lexeme");
                std::string d_key=*result->field_value_at_row_position(0,"d_key");
                if(root_lexeme==lexeme&&root_d_key==std::atoi(d_key.c_str())){
                    bool filter_applies=check_dependencies(dependenciesArray,result);
                    if(filter_applies==true){
                        query="select * from analyses where source='"+std::get<0>(key)
                            +"' and timestamp='"+std::get<1>(key)
                            +"' and sentence='"+std::get<2>(key)
                            +"' and rank='"+std::get<3>(key)+"';";
                        query_result *analysis_entry=sqlite->exec_sql(query);
                        if(analysis_entry==NULL){
                            //TODO: do whatever
                        }
                        std::string analysis=*analysis_entry->field_value_at_row_position(0,"analysis");
                        analyses_found+=analysis+",";
                    }
                }
                delete result;
            }
            sqlite->close();
            db_factory::delete_instance();
        }
    }
    if(analyses_found.empty()==false){
        analyses_found.pop_back();
        analyses_found="{\"analyses\":["+analyses_found+"]}";
        p_analyses_found=new char[analyses_found.length()+1];
        analyses_found.copy(p_analyses_found,analyses_found.length(),0);
        p_analyses_found[analyses_found.length()]='\0';
    }
    return p_analyses_found;
}

const char *hi_query(const char *db_uri, const char* p_mood, const char* p_dependencies){
//TESTS:
//hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
//"{\"lexeme\":\"EXECUTABLEENGA\",\"c_value\":\"\",\"word\":\"\",\"is_con\":false,\"is_qword\":false,\"mood\":\"indicative\"},"
//"{\"lexeme\":\"FILEENGN\",\"c_value\":\"\",\"word\":\"\",\"is_con\":false,\"is_qword\":false,\"mood\":\"indicative\"},"
//"{\"lexeme\":\"abc\",\"c_value\":\"\",\"word\":\"abc\",\"is_con\":true,\"is_qword\":false,\"mood\":\"indicative\"}"
//"]}");

    db *sqlite=NULL;
    query_result *result=NULL;
    std::string analyses_found;
    char *p_analyses_found=NULL;
    std::string root_lexeme;
    unsigned int root_d_key=0;
    //std::vector<std::tuple<unsigned int, std::string, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, std::string, unsigned int>> dependencies;

    std::string mood=std::string(p_mood);
    rapidjson::Document jsondoc;
    jsondoc.Parse(p_dependencies);
    if(jsondoc.HasMember("dependencies")==true){
        rapidjson::Value& dependenciesArray=jsondoc["dependencies"];
        if(dependenciesArray.IsArray()==true&&dependenciesArray.Size()>0){
            sqlite=db_factory::get_instance();
            sqlite->open(db_uri);
            std::map<std::string,std::pair<std::string,std::string>> lexemes_to_cvalues_cons;
            std::set<std::string> qwords;
            for(auto& dependencyObject:dependenciesArray.GetArray()){
                if(dependencyObject.HasMember("dependency")==true
                    &&dependencyObject.HasMember("ref_d_key")==true
                    &&dependencyObject.HasMember("c_value")==true
                    &&dependencyObject.HasMember("word")==true
                    &&dependencyObject.HasMember("tags")==true){
                    auto& tags=dependencyObject["tags"];
                    if(tags.HasMember("is_root")==true){
                        if(tags["is_root"].GetString()==std::string("true")){
                            root_lexeme=dependencyObject["dependency"].GetString();
                            root_d_key=dependencyObject["ref_d_key"].GetUint();
                        }
                    }
                    if(tags.HasMember("is_qword")==true){
                        if(tags["is_qword"].GetString()==std::string("true")){
                            qwords.insert(dependencyObject["word"].GetString());
                        }
                    }
                    //It is only possible to do it this way if transgraph::transcript() is modified in a way that it read FUNCTOR_TAGS for CONs as well
                    //and then FUNCTOR_TAGS can have unconditional entries (with empty trigger_tag) for the CON functor.
                    /*if(tags.HasMember("is_con")==true){
                        if(tags["is_con"].GetString()==std::string("true")){
                            lexemes_to_cvalues_cons.insert(std::make_pair(dependencyObject["lexeme"].GetString(),std::make_pair("",dependencyObject["word"].GetString())));
                        }
                    }
                    else{
                        lexemes_to_cvalues_cons.insert(std::make_pair(dependencyObject["lexeme"].GetString(),std::make_pair(dependencyObject["c_value"].GetString(),"")));
                    }*/
                    if(dependencyObject["dependency"].GetString()==std::string("CON")){
                        lexemes_to_cvalues_cons.insert(std::make_pair(dependencyObject["dependency"].GetString(),std::make_pair("",dependencyObject["word"].GetString())));
                    }
                    else{
                        lexemes_to_cvalues_cons.insert(std::make_pair(dependencyObject["dependency"].GetString(),std::make_pair(dependencyObject["c_value"].GetString(),"")));
                    }
                }
                else{
                    //TODO: error handling
                    std::cout<<"exiting: not all json parameters found"<<std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            std::string query="select count(*) as lexeme_count,source,timestamp,sentence,rank,a_counter,mood from analyses_deps where mood='"+mood+"' and (";
            std::string tag_conditions;
            if(qwords.empty()==true){//add main verb's lexeme if there's no question word
                lexemes_to_cvalues_cons.insert(std::make_pair(root_lexeme,std::make_pair("","")));
            }
            else{
                for(auto&& qword:qwords){
                    //to handle more than one qwords no matter how they are stored
                    //(as an array e.g. {"qword":["when","what",...]} or as multiple tags like {"qword":"when","qword":"what",...})
                    //this seems to be able to catch all
                    tag_conditions+="tags like '\"qword\":%\""+qword+"\"%' or ";
                }
                tag_conditions=tag_conditions.substr(0,tag_conditions.length()-4);
            }
            std::string lexeme_conditions;
            for(auto&& lexeme_cvalue_con:lexemes_to_cvalues_cons){
                if(lexeme_cvalue_con.second.first.empty()==true){//cvalue empty
                    if(lexeme_cvalue_con.second.second.empty()==true){//con empty
                        lexeme_conditions+="dependency='"+lexeme_cvalue_con.first+"' or ";
                    }
                    else{
                        lexeme_conditions+="dependency='"+lexeme_cvalue_con.first+"' and word='"+sqlite->escape(lexeme_cvalue_con.second.second)+"' or ";
                    }
                }
                else{
                    lexeme_conditions+="dependency='"+lexeme_cvalue_con.first+"' and c_value='"+sqlite->escape(lexeme_cvalue_con.second.first)+"' or ";
                }
            }
            lexeme_conditions=lexeme_conditions.substr(0,lexeme_conditions.length()-4);
            if(tag_conditions.empty()==true){
                query+=lexeme_conditions;
            }
            else{
                query+="("+lexeme_conditions+") or ("+tag_conditions+")";
            }
            query+=") group by source,timestamp,sentence,rank,a_counter,mood order by lexeme_count desc;";
            //std::cout<<"query:"<<query<<std::endl;
            result=sqlite->exec_sql(query);
            if(result==NULL){
                //TODO: return whatever
                std::cout<<"exiting: no SQL query result"<<std::endl;
                exit(EXIT_FAILURE);
            }
            //loop over result and get unique keys
            std::set<std::tuple<std::string,std::string,std::string,std::string,std::string,std::string>> andeps_keys;
            unsigned int result_size=result->nr_of_result_rows();
            for(unsigned int i=0;i<result_size;++i){
                std::string source=*result->field_value_at_row_position(i,"source");
                std::string timestamp=*result->field_value_at_row_position(i,"timestamp");
                std::string sentence=*result->field_value_at_row_position(i,"sentence");
                std::string rank=*result->field_value_at_row_position(i,"rank");
                std::string a_counter=*result->field_value_at_row_position(i,"a_counter");
                std::string mood=*result->field_value_at_row_position(i,"mood");
                std::tuple<std::string,std::string,std::string,std::string,std::string,std::string> andeps_key=std::make_tuple(source,timestamp,sentence,rank,a_counter,mood);
                andeps_keys.insert(andeps_key);
            }
            delete result;
            //loop over result and get entries whose root match root_word, root_lexeme and root_d_key
            for(auto&& key:andeps_keys){
                std::string query="select * from analyses_deps where source='"+std::get<0>(key)
                    +"' and timestamp='"+std::get<1>(key)
                    +"' and sentence='"+sqlite->escape(std::get<2>(key))
                    +"' and rank='"+std::get<3>(key)
                    +"' and a_counter='"+std::get<4>(key)
                    +"' and mood='"+std::get<5>(key)+"' order by counter;";
                //std::cout<<"query:"<<query<<std::endl;
                result=sqlite->exec_sql(query);
                if(result==NULL){
                    //TODO: do whatever
                    std::cout<<"exiting: no entries found for a key"<<std::endl;
                    exit(EXIT_FAILURE);
                }
                std::string lexeme=*result->field_value_at_row_position(0,"dependency");//first entry does not have parent, so no lexeme
                std::string d_key=*result->field_value_at_row_position(0,"ref_d_key");//first entry does not have parent, so no d_key
                //This below should achieve the same but if the two rows above prove to work, they're definitely faster.
                /*std::string lexeme;
                std::string d_key;
                std::string tags=*result->field_value_at_row_position(0,"tags");
                if(tags.empty()==false){
                    tags="{"+tags+"}";
                    rapidjson::Document json_tags;
                    json_tags.Parse(tags.c_str());
                    if(json_tags.HasMember("is_root")==true){
                        if(json_tags["is_root"].GetBool()==true){
                            lexeme=json_tags["dependency"].GetString();
                            d_key=json_tags["ref_d_key"].GetUint();
                        }
                    }
                }*/
                if(root_lexeme==lexeme&&root_d_key==std::atoi(d_key.c_str())){
                    for(unsigned int i=0;i<result->nr_of_result_rows();++i){
                        std::string source=*result->field_value_at_row_position(i,"source");
                        analyses_found+="{\"source\":\""+source+"\",";
                        std::string timestamp=*result->field_value_at_row_position(i,"timestamp");
                        analyses_found+="\"timestamp\":\""+timestamp+"\",";
                        std::string sentence=*result->field_value_at_row_position(i,"sentence");
                        analyses_found+="\"sentence\":\""+sentence+"\",";
                        std::string rank=*result->field_value_at_row_position(i,"rank");
                        analyses_found+="\"rank\":\""+rank+"\",";
                        std::string a_counter=*result->field_value_at_row_position(i,"a_counter");
                        analyses_found+="\"a_counter\":\""+a_counter+"\",";
                        std::string mood=*result->field_value_at_row_position(i,"mood");
                        analyses_found+="\"mood\":\""+mood+"\",";
                        std::string function=*result->field_value_at_row_position(i,"function");
                        analyses_found+="\"function\":\""+function+"\",";
                        std::string counter=*result->field_value_at_row_position(i,"counter");
                        analyses_found+="\"counter\":\""+counter+"\",";
                        std::string level=*result->field_value_at_row_position(i,"level");
                        analyses_found+="\"level\":\""+level+"\",";
                        std::string word=*result->field_value_at_row_position(i,"word");
                        analyses_found+="\"word\":\""+word+"\",";
                        std::string lexeme=*result->field_value_at_row_position(i,"lexeme");
                        analyses_found+="\"lexeme\":\""+lexeme+"\",";
                        std::string d_key=*result->field_value_at_row_position(i,"d_key");
                        analyses_found+="\"d_key\":\""+d_key+"\",";
                        std::string d_counter=*result->field_value_at_row_position(i,"d_counter");
                        analyses_found+="\"d_counter\":\""+d_counter+"\",";
                        std::string dependency=*result->field_value_at_row_position(i,"dependency");
                        analyses_found+="\"dependency\":\""+dependency+"\",";
                        std::string ref_d_key=*result->field_value_at_row_position(i,"ref_d_key");
                        analyses_found+="\"ref_d_key\":\""+ref_d_key+"\",";
                        std::string tags=*result->field_value_at_row_position(i,"tags");
                        analyses_found+="\"tags\":"+tags+",";
                        std::string c_value=*result->field_value_at_row_position(i,"c_value");
                        analyses_found+="\"c_value\":\""+c_value+"\"},";
                    }
                }
                delete result;
            }
            sqlite->close();
            db_factory::delete_instance();
        }
    }
    if(analyses_found.empty()==false){
        analyses_found.pop_back();
        analyses_found="{\"analyses\":["+analyses_found+"]}";
        //std::cout<<"analyses found:"<<analyses_found<<std::endl;
        p_analyses_found=new char[analyses_found.length()+1];
        analyses_found.copy(p_analyses_found,analyses_found.length(),0);
        p_analyses_found[analyses_found.length()]='\0';
    }
    return p_analyses_found;
}
