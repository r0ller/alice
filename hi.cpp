#include "hilib.h" 
#include <string>
#include <vector>
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"

using namespace std;
using namespace rapidjson;

void find_replace(string& findrep,const string& search_for,const string& replace_with){
	size_t pos=findrep.find(search_for);
	while(pos!=string::npos){
		findrep.replace(pos,search_for.size(),replace_with);
		pos=findrep.find(search_for,pos+replace_with.size());
	}
}

string value_to_string(Value& jsonvalue){
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	jsonvalue.Accept(writer);
	return buffer.GetString();
}

string args_to_shfun_arglist(vector<string>& arguments){
	string arglist;

	for(auto&& i:arguments){
		arglist+="\"$"+i+"\" ";
	}
	if(arglist.empty()==false) arglist.pop_back();
	return arglist;
}

string args_to_shfun_pmlist(vector<string>& arguments){
	string arglist;

	for(auto&& i:arguments){
		arglist+=i+" ";
	}
	if(arglist.empty()==false) arglist.pop_back();
	return arglist;
}

string transcribeDependencies(Value& morphology,Value& syntax,Value& dependencies,Value& functors,vector<string>& argList){
	string script;
	vector<string> arguments;

	for(unsigned int i=0;i<dependencies.Size();++i){
		Value& dependency=dependencies[i];
		string functorID;
		if(dependency.HasMember("functor id")==true){
			functorID=dependency["functor id"].GetString();
		}
		if(functorID.empty()==true){
			functorID=dependency["functor"].GetString();
		}
		string dependencyID=dependency["id"].GetString();
		string functionName=functorID+"_"+dependencyID;
		string argument=functionName+"_out";
		argList.push_back(argument);
		if(dependency.HasMember("dependencies")==true){
			script+=transcribeDependencies(morphology,syntax,dependency["dependencies"],functors,arguments);
		}
		string morphologyArg;
		if(dependency.HasMember("morpheme id")==true){
			string morphemeID=dependency["morpheme id"].GetString();
			for(unsigned int j=0;j<morphology.Size();++j){
				Value& morphologyObj=morphology[j];
                if(morphologyObj["morpheme id"].GetString()==morphemeID){
                	morphologyArg=value_to_string(morphologyObj);
                	find_replace(morphologyArg,"\"","\\\"");
                    break;
                }
			}
		}
        string morphologyVarName=functionName+"_morphology";
        arguments.push_back(morphologyVarName);

        string tags;
        string tagsVarName;
        if(dependency.HasMember("tags")==true){
            for(auto& tag: dependency["tags"].GetObject()){
                tags+="\""+string(tag.name.GetString())+"\":\""+string(tag.value.GetString())+"\",";
            }
            if(tags.empty()==false){
                tags.pop_back();
                tags="{"+tags+"}";
                tagsVarName=functionName+"_tags";
                arguments.push_back(tagsVarName);
            }
        }

        string argStr=args_to_shfun_arglist(arguments);
        string parameterList=args_to_shfun_pmlist(arguments);
        string functorDef;
        for(unsigned int j=0;j<functors.Size();++j){
            Value& functor=functors[j];
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

string transcript(const unsigned int toa,Document& jsondoc){
	string script;
	vector<string> arguments;
	Value morphology,syntax,semantics;

	if(jsondoc.HasMember("analyses")==true){
		Value& analysesArray = jsondoc["analyses"];
		if(analysesArray.IsArray()==true&&analysesArray.Size()>0){
			Value& analysis=analysesArray[0];
			if(toa&HI_MORPHOLOGY) morphology=analysis["morphology"];
			if(toa&HI_SYNTAX) syntax=analysis["syntax"];
			if(toa&HI_SEMANTICS){
				semantics=analysis["semantics"];
				Value relatedSemantics;
				if(analysis.HasMember("related semantics")==true){
					relatedSemantics=analysis["related semantics"];
				}
				Value& functors=analysis["functors"];
				if(analysis.HasMember("errors")==false){
					if(semantics.Size()>0){
						script=transcribeDependencies(morphology,syntax,semantics,functors,arguments);
					}
					else{

					}
				}
				else{

				}
			}
		}
	}
	return script;
}

int main(int argc,char **argv){

	const char *analyses;
	string text,script;
	FILE *fp;
	char line[256];
    unsigned char toa=0,crh=0;

//    if(argc==3&&string(argv[1])=="-q"){
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
        analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
        "{\"filter_nr\": 1,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1},"
        "{\"filter_nr\": 2,\"filter_d_counter\": 1,\"filter_nr_d_ref\":\"\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"1/1\",\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1},"
        "{\"filter_nr\": 2,\"filter_d_counter\": 2,\"filter_nr_d_ref\":\"\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"distance\":0,\"distance_op\":\">=\",\"ref_d_filter_nr\":\"\",\"dependency\":\"CON\",\"ref_d_key\":1}]}");
        if(analyses!=NULL){
            cout<<analyses<<endl;
        }
//    }
/*    else{
        while(true){
            getline(cin,text);
    //        text="file abc is executable .\n";
            if(text.empty()==false){
                toa=HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS;
                //crh=HI_VERB;
                analyses=hi(text.c_str(),"ENG",toa,"sh","hi_desktop/hi.db","test",crh);
                if(analyses!=NULL){
                    cout<<analyses<<endl;
                    Document jsondoc;
                    jsondoc.Parse(analyses);
                    script=transcript(toa,jsondoc);
                    if(script.length()>0){
                        cout<<script<<endl;
                        if(argc>1&&string(argv[1])=="-d") script="set -x;"+script;
                        fp=popen(script.c_str(),"r");
                        if(fp!=NULL){
                            while(fgets(line,sizeof line,fp))
                            {
                                cout<<line<<endl;
                            }
                            pclose(fp);
                        }
                    }
                }
                text.clear();
            }
            else break;
        }
    }*/
}
