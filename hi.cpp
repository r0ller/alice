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
            script+=functorDef+functionName+" \""+functionName+"\" \""+parameterList+"\" "+argStr+";";
        }
        arguments.clear();
	}
	return script;
}

string transcript(Document& jsondoc){
	string script;
	vector<string> arguments;

	if(jsondoc.HasMember("analyses")==true){
		Value& analysesArray = jsondoc["analyses"];
		if(analysesArray.IsArray()==true&&analysesArray.Size()>0){
			Value& analysis=analysesArray[0];
			Value& morphology=analysis["morphology"];
			Value& syntax=analysis["syntax"];
			Value& semantics=analysis["semantics"];
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
				Value& errors=analysis["errors"];

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

	while(true){
		getline(cin,text);
		if(text.empty()==false){
			analyses=hi(text.c_str(),"ENG",HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS,"","hi_desktop/hi.db");
			if(analyses!=NULL){
				cout<<analyses<<endl;
				Document jsondoc;
				jsondoc.Parse(analyses);
				script=transcript(jsondoc);
				if(argc>1&&string(argv[1])=="-d") script="set -x;"+script;
				cout<<script<<endl;
				fp=popen(script.c_str(),"r");
				if(fp!=NULL){
					while(fgets(line,sizeof line,fp))
					{
						cout<<line<<endl;
					}
					pclose(fp);
				}
			}
			text.clear();
		}
		else break;
	}
}
