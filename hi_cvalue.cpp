#include <iostream>
#include "db_factory.h"
#include "rapidjson/document.h"

int hi_state_cvalue(const char *db_uri,const char *deps,const char *function, const char *c_value){
    db *sqlite=NULL;
    query_result *result=NULL;

    rapidjson::Document jsonDeps;
    jsonDeps.Parse(deps);
    rapidjson::Value& dependencies=jsonDeps["analysis_deps"];
    if(dependencies.IsArray()==true&&dependencies.Size()>0){
        rapidjson::Value dependency;
        bool function_found=false;
        for(unsigned int i=0;i<dependencies.Size();++i){
            dependency=dependencies[i];
            if(dependency["function"].GetString()==std::string(function)){
                function_found=true;
                break;
            }
        }
        if(function_found==true){
            sqlite=db_factory::get_instance();
            sqlite->open(db_uri);
            std::string sql_stmt="update analyses_deps set c_value='"+sqlite->escape(std::string(c_value))
                +"' where source='"+dependency["source"].GetString()
                +"' and timestamp="+std::to_string(dependency["timestamp"].GetUint())
                +" and sentence='"+sqlite->escape(dependency["sentence"].GetString())
                +"' and rank="+std::to_string(dependency["rank"].GetUint())
                +" and a_counter="+std::to_string(dependency["a_counter"].GetUint())
                +" and mood='"+dependency["mood"].GetString()
                +"' and function='"+dependency["function"].GetString()+"';";
            sqlite->exec_sql(sql_stmt);
            sqlite->close();
        }
    }
    return 0;
}
