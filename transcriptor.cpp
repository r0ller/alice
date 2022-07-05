#include "transcriptor.h"

transcriptor::transcriptor(const char *analyses){
    jsondoc.Parse(analyses);
}

void transcriptor::find_replace(std::string& findrep,const std::string& search_for,const std::string& replace_with){
    size_t pos=findrep.find(search_for);
    while(pos!=std::string::npos){
        findrep.replace(pos,search_for.size(),replace_with);
        pos=findrep.find(search_for,pos+replace_with.size());
    }
}

std::string transcriptor::value_to_string(rapidjson::Value& jsonvalue){
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    jsonvalue.Accept(writer);
    return buffer.GetString();
}

std::string transcriptor::transcribe(){
    std::string script;
    std::vector<std::string> arguments;

    if(jsondoc.HasMember("analyses")==true){
        rapidjson::Value& analysesArray = jsondoc["analyses"];
        if(analysesArray.IsArray()==true&&analysesArray.Size()>0){
            rapidjson::Value& analysis=analysesArray[0];//analyses are ranked, the first is the best
            rapidjson::Value& morphology=analysis["morphology"];
            rapidjson::Value syntax;
            if(analysis.HasMember("syntax")==true){
                syntax=analysis["syntax"];
            }
            rapidjson::Value& semantics=analysis["semantics"];
            rapidjson::Value relatedSemantics;
            if(analysis.HasMember("related semantics")==true){
                relatedSemantics=analysis["related semantics"];
            }
            rapidjson::Value& functors=analysis["functors"];
            if(analysis.HasMember("errors")==false){
                if(semantics.Size()>0){
                    script=transcribeDependencies(morphology,syntax,semantics,functors,arguments,true);
                    if(analysis.HasMember("analysis_deps")==true){
                        rapidjson::Value& analysis_deps=analysis["analysis_deps"];
                        std::string analysis_deps_escaped=value_to_string(analysis_deps);
                        find_replace(analysis_deps_escaped,"\"","\\\"");
                        script="analysis_deps='"+analysis_deps_escaped+"';"+script;
                    }
                }
                else{

                }
            }
            else{

            }
        }
    }
    return script;
}
