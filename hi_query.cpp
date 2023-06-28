#include <iostream>
#include <tuple>
#include <set>
#include <vector>
#include <string>
#include "db_factory.h"
#include "query_result.h"
#include "rapidjson/document.h"

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
