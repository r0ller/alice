#include "sh_transcriptor.h"

sh_transcriptor::sh_transcriptor(const char *analyses):transcriptor(analyses){

}

sh_transcriptor::~sh_transcriptor(){
    logger::singleton()==NULL?(void)0:logger::singleton()->log(3,"destructing sh transcriptor");
}

std::string sh_transcriptor::args_to_shfun_arglist(std::vector<std::string>& arguments){
    std::string arglist;

    for(auto&& i:arguments){
        arglist+="\"$"+i+"\" ";
    }
    if(arglist.empty()==false) arglist.pop_back();
    return arglist;
}

std::string sh_transcriptor::args_to_shfun_pmlist(std::vector<std::string>& arguments){
    std::string arglist;

    for(auto&& i:arguments){
        arglist+=i+" ";
    }
    if(arglist.empty()==false) arglist.pop_back();
    return arglist;
}

std::string sh_transcriptor::transcribeDependencies(rapidjson::Value& morphology,rapidjson::Value& syntax,rapidjson::Value& dependencies,rapidjson::Value& functors,std::vector<std::string>& argList,bool first_call){
    std::string script;
    std::vector<std::string> arguments;

    for(unsigned int i=0;i<dependencies.Size();++i){
        rapidjson::Value& dependency=dependencies[i];
        std::string functorID;
        if(dependency.HasMember("functor id")==true){
            functorID=dependency["functor id"].GetString();
        }
        if(functorID.empty()==true){
            functorID=dependency["functor"].GetString();
        }
        std::string dependencyID=dependency["id"].GetString();
        std::string functionName=functorID+"_"+dependencyID;
        std::string argument=functionName+"_out";
        argList.push_back(argument);
        if(dependency.HasMember("dependencies")==true){
            script+=transcribeDependencies(morphology,syntax,dependency["dependencies"],functors,arguments);
        }
        std::string morphologyArg;
        if(dependency.HasMember("morpheme id")==true){
            std::string morphemeID=dependency["morpheme id"].GetString();
            for(unsigned int j=0;j<morphology.Size();++j){
                rapidjson::Value& morphologyObj=morphology[j];
                if(morphologyObj["morpheme id"].GetString()==morphemeID){
                    morphologyArg=value_to_string(morphologyObj);
                    find_replace(morphologyArg,"\"","\\\"");
                    break;
                }
            }
        }
        std::string morphologyVarName=functionName+"_morphology";
        arguments.push_back(morphologyVarName);

        std::string tags;
        std::string tagsVarName;
        if(dependency.HasMember("tags")==true){
            for(auto& tag: dependency["tags"].GetObject()){
                std::string tag_quoted="\""+std::string(tag.name.GetString())+"\":\""+std::string(tag.value.GetString())+"\",";
                //quoting here breaks sh script
                //find_replace(tag_quoted,"\"","\\\"");
                tags+=tag_quoted;
            }
            if(tags.empty()==false){
                tags.pop_back();
                tags="{"+tags+"}";
                tagsVarName=functionName+"_tags";
                arguments.push_back(tagsVarName);
            }
        }

        std::string argStr=args_to_shfun_arglist(arguments);
        std::string parameterList=args_to_shfun_pmlist(arguments);
        std::string functorDef;
        for(unsigned int j=0;j<functors.Size();++j){
            rapidjson::Value& functor=functors[j];
            if(functor["functor id"].GetString()==functorID){
                functorDef=functor["definition"].GetString();
                if(functorDef.empty()==false){
                    functorDef=functionName+"(){ "+functorDef+" };";
                }
                break;
            }
        }
        if(functorDef.empty()==true){
            //TODO:if functor has no definition but has dependencies, propagate the outgoing result of its dependencies to the parent.
            //However, if there are more than one functor having no definition it'll be necessary to pass on which is the last
            //functor that has a definition in order that the arguments are propagated to the right level.
            script+=functionName+"_out="+"\""+morphologyArg+"\";";
        }
        else{
            script+=morphologyVarName+"="+"\""+morphologyArg+"\";";
            if(tags.empty()==false) script+=tagsVarName+"="+"\""+tags+"\";";
            script+=functorDef+functionName+" \""+functionName+"\" \""+parameterList+"\" "+argStr+";";
        }
        arguments.clear();
    }
    return script;
}
