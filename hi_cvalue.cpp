#include "hilib.h"
#include <iostream>
#include "db_factory.h"
#include "rapidjson/document.h"

int hi_state_cvalue(const char *db_uri,const char *key,const char *c_value){
    db *sqlite=NULL;
    query_result *result=NULL;

    rapidjson::Document jsonKey;
    jsonKey.Parse(key);
    sqlite=db_factory::get_instance();
    sqlite->open(db_uri);
    std::string sql_stmt="update analyses_deps set c_value='"+std::string(c_value)
        +"' where source='"+jsonKey["source"].GetString()
        +"' and timestamp="+std::to_string(jsonKey["timestamp"].GetUint())
        +" and sentence='"+jsonKey["sentence"].GetString()
        +"' and rank="+std::to_string(jsonKey["rank"].GetUint())
        +" and mood='"+jsonKey["mood"].GetString()
        +"' and function='"+jsonKey["function"].GetString()+"';";
    sqlite->exec_sql(sql_stmt);
    sqlite->close();
    return 0;
}
