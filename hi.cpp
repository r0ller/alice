#include "hilib.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "rapidjson/document.h"

using namespace std;

int main(int argc,char **argv){

	const char *analyses,*script_chr=NULL;
	string text,script,language="sh";
	FILE *fp;
	char line[256];
	unsigned char toa=0,crh=0;

	if(argc==5&&string(argv[1])=="-q"){
		//In case of interrogative mood each functor should return in its $1_out parameter a table appending such a json object
		//entry like in the example below in order that the main verb functor can modify it and pass the table to hi_query().
		//Example for 'what is executable ?'
		/*analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
		"{\"lexeme\":\"WHATENGPRON\",\"c_value\":\"\",\"word\":\"what\",\"is_con\":false,\"is_qword\":true,\"mood\":\"indicative\"},"
		"{\"lexeme\":\"BEENGV\",\"c_value\":\"\",\"word\":\"\",\"is_con\":false,\"is_qword\":false,\"mood\":\"indicative\"},"
		"{\"lexeme\":\"EXECUTABLEENGA\",\"c_value\":\"\",\"word\":\"\",\"is_con\":false,\"is_qword\":false,\"mood\":\"indicative\"}"
		"]}");*/
		/*analyses=hi_query("hi_desktop/hi.db","indicative","{\"dependencies\":[{\"source\":\"test\",\"timestamp\":1707253866,\"sentence\":\"what is executable ?\",\"rank\":0.333333,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"BEENGV_1_6\",\"counter\":0,\"level\":0,\"word\":\"is\",\"lexeme\":\"\",\"d_key\":"
						  "0,\"d_counter\":0,\"dependency\":\"BEENGV\",\"ref_d_key\":1,\"tags\":{\"is_root\":\"true\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707253866,\"sentence\":\"what is executable ?\",\"rank\":0.333333,\"a_counter\":1,\"mood\":\"interrogative\","
						  "\"function\":\"WHATENGPRON_1_1\",\"counter\":1,\"level\":1,\"word\":\"what\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":1,\"dependency\":\"WHATENGPRON\",\"ref_d_key\":1,\"tags\":{\"is_qword\":\"true\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":"
						  "1707253866,\"sentence\":\"what is executable ?\",\"rank\":0.333333,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"PROPERTIES_1_6_1\",\"counter\":2,\"level\":1,\"word\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":3,\"dependency\":"
						  "\"PROPERTIES\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707253866,\"sentence\":\"what is executable ?\",\"rank\":0.333333,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"FILEBEPROP_1_6_2\",\"counter\":"
						  "3,\"level\":2,\"word\":\"\",\"lexeme\":\"PROPERTIES\",\"d_key\":1,\"d_counter\":4,\"dependency\":\"FILEBEPROP\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707253866,\"sentence\":\"what is executable ?\",\"rank\":0.333333,"
						  "\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"EXECUTABLEENGA_1_8\",\"counter\":4,\"level\":3,\"word\":\"executable\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"}]}");*/
		//Another example for 'when is peter's birthday ?'
		//"{\"dependencies\":[{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"BEENGV_1_4\",\"counter\":0,\"level\":0,\"word\":\"is\",\"lexeme\":\"\",\"d_key\":0,\"d_counter\":0,\"dependency\":\"BEENGV\",\"ref_d_key\":1,\"tags\":{\"is_root\":\"true\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"WHENENGPRON_1\",\"counter\":1,\"level\":1,\"word\":\"when\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":1,\"dependency\":\"WHENENGPRON\",\"ref_d_key\":1,\"tags\":{\"is_qword\":\"true\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"BIRTHDAYENGN_1_15\",\"counter\":2,\"level\":1,\"word\":\"birthday\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"BIRTHDAYENGN\",\"ref_d_key\":1,\"tags\":{\"qword\":\"when\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"CON_10\",\"counter\":3,\"level\":2,\"word\":\"peter's\",\"lexeme\":\"BIRTHDAYENGN\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"CON\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"}]}";
		analyses=hi_query("hi_desktop/hi.db","indicative","{\"dependencies\":[{\"source\":\"test\",\"timestamp\":1710968969,\"sentence\":\"mi kell ?\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"KELLHUNV_1_6\",\"counter\":0,\"level\":0,\"word\":\"kell\",\"lexeme\":\"\",\"d_key\":0,\"d_counter\":0,\"dependency\":\"KELLHUNV\",\"ref_d_key\":1,\"tags\":[{\"is_root\":\"true\"}],\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1710968969,\"sentence\":\"mi kell ?\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"MIHUNIPRON_1\",\"counter\":1,\"level\":1,\"word\":\"mi\",\"lexeme\":\"KELLHUNV\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"MIHUNIPRON\",\"ref_d_key\":1,\"tags\":[{\"is_qword\":\"true\"}],\"c_value\":\"\"}]}");
		//analyses=hi_query(argv[2],argv[3],argv[4]);
		if(analyses!=NULL){
			cout<<analyses<<endl;
			rapidjson::Document jsondoc;
			jsondoc.Parse(analyses);
			if(jsondoc.HasMember("analyses")==true){
				rapidjson::Value& analysesArray=jsondoc["analyses"];
				if(analysesArray.IsArray()==true&&analysesArray.Size()>0){
					rapidjson::SizeType i=analysesArray.Size()-1;
					for(;i>0;--i){
						auto analysisObject=analysesArray[i].GetObject();
						//look for the first analysis having the qword tag and c_calue then stop
						string c_value=analysisObject["c_value"].GetString();
						//Making condition looser as hi_query() shall make sure that the relevant tags
						//appear in the analysis.
						//if(analysisObject["tags"].HasMember("qword")==true&&c_value.empty()==false){
						if(c_value.empty()==false){
							cout<<c_value<<endl;
							break;
						}
					}
				}
			}
		}
	}
	else if(argc==6&&string(argv[1])=="-c"){
		//hi_state_cvalue("hi_desktop/hi.db","{\"source\":\"test\",\"timestamp\":1655803024,\"sentence\":\"file abc is executable .\",\"rank\":1,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"CON_6\"}","CON_6","test");
		/*hi_state_cvalue("hi_desktop/hi.db","{\"dependencies\":[{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"BEENGV_1_9\",\"counter\":0,\"level\":0,\"word\":\"is\",\"lexeme\":\"\",\"d_key\":"
							 "0,\"d_counter\":0,\"dependency\":\"BEENGV\",\"ref_d_key\":1,\"tags\":{\"is_root\":\"true\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"f"
							 "function\":\"PROPERTIES_1_9_1\",\"counter\":1,\"level\":1,\"word\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":3,\"dependency\":\"PROPERTIES\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":"
							 "\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"FILEBEPROP_1_9_2\",\"counter\":2,\"level\":2,\"word\":\"\",\"lexeme\":\"PROPERTIES\",\"d_key\":1,\"d_counter\":4,\"dependency\":\"FILEBEPROP\",\"ref_d_key\":"
							 "1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"EXECUTABLEENGA_1_12\",\"counter\":3,\"level\":3,\"word\":\"executable"
							 "\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"EXECUTABLEENGA\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,"
							 "\"mood\":\"indicative\",\"function\":\"FILEENGN_1_1\",\"counter\":4,\"level\":3,\"word\":\"file\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"d_counter\":4,\"dependency\":\"FILEENGN\",\"ref_d_key\":1,\"tags\":{\"qword\":\"what\"},\"c_value\":\"\"},{\"source\""
							 ":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"BEENGV_1_1_3\",\"counter\":5,\"level\":4,\"word\":\"\",\"lexeme\":\"FILEENGN\",\"d_key\":1,\"d_counter\":1,\""
							 "dependency\":\"BEENGV\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"PROPERTIES_1_1_4\",\"counter\":"
							 "6,\"level\":5,\"word\":\"\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":3,\"dependency\":\"PROPERTIES\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5"
							 ",\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"FILEBEPROP_1_1_5\",\"counter\":7,\"level\":6,\"word\":\"\",\"lexeme\":\"PROPERTIES\",\"d_key\":1,\"d_counter\":4,\"dependency\":\"FILEBEPROP\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source"
							 "\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"FILEENGN_1_1_6\",\"counter\":8,\"level\":7,\"word\":\"\",\"lexeme\":\"FILEBEPROP\",\"d_key\":1,\"d_counter\""
							 ":4,\"dependency\":\"FILEENGN\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1707419402,\"sentence\":\"file def is executable .\",\"rank\":0.5,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"CON_6\",\"counter\":9,"
							 "\"level\":8,\"word\":\"def\",\"lexeme\":\"FILEENGN\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"CON\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"}]}","FILEENGN_1_1_6","def");*/
		hi_state_cvalue(argv[2],argv[3],argv[4],argv[5]);
	}
	else{
		while(true){
			getline(cin,text);
			//Test sms scenario:
			//text="küldj sms tesztnek hogy x";
			//text="üzenem péternek hogy hello";
			//text="a másodiknak\n";
			//text="küldd\n";
			//Test context ref handling for verb:
			//text="hí­vd fel pétert\n";
			//text="a harmadikat\n";
			//Test interpreting statement (see question test above at -q):
			//text="today is peter's birthday .\n";
			//Test sentence without verb and no context ref handling:
			//text="files in abc\n";
			//text="felolvasás be\n";
			//text="vazze kapcsold be a felolvasást";
			//text="keress a névjegyzékben alizt";
			//text="küld";
			//Test interpreting mood:
			//text="kell só és bors .";
			//text="mi kell ?";
			//text="list files !";
			//Test interpreting json:
			//text="{\"anya\":1}";
			//text="{\"anya\":{\"darab\":1}}";
			//text="{\"mátrix\":{\"sor\":1,\"oszlop\":2}}";
			//text="{\"anya\":{\"darab\":{\"mennyiség\":1}}}";
			//text="{\"anya\":{\"darab\":{\"mennyiség\":1,\"tömeg\":2}}}";
			//text="{\"anya\":[1]}";
			//text="{\"anya\":[1,2]}";
			//text="{\"anya\":[\"teszt\"]}";
			//text="{\"anya\":[\"teszt\",\"valami\"]}";
			//text="{\"anya\":[1,\"teszt\",2,\"valami\"]}";//order of array elements depends on rule2rule map
			//text="{\"anya\":{\"darab\":[1]}}";
			//text="{\"anya\":{\"darab\":[1,2]}}";
			//text="{\"anya\":{\"darab\":[\"teszt\"]}}";
			//text="{\"anya\":{\"darab\":[\"teszt\",\"valami\"]}}";
			//text="{\"anya\":{\"darab\":[1,\"teszt\",2,\"valami\"]}}";
			//text="{\"anya\":[{\"darab\":1}]}";
			//text="{\"anya\":[1,{\"darab\":2}]}";
			//text="{\"anya\":[{\"darab\":1},{\"mennyiség\":2}]}";
			//text="{\"anya\":{\"darab\":[{\"mennyiség\":1}]}}";
			//text="{\"anya\":{\"adat\":[{\"darab\":1},{\"mennyiség\":2}]}}";
			//text="{\"anya\":[[1]]}";//FIXME: does not work yet
			//Test semantics with leo (lexical entries only) syntax:
			//text="kérem az izé útmutatót !"
			if(text.empty()==false){
				//toa=HI_MORPHOLOGY|HI_SYNTAX;
				//toa=HI_MORPHOLOGY|HI_SYNTAX|HI_LEO_SYNTAX;
				toa=HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS;
				//toa=HI_MORPHOLOGY|HI_SYNTAX|HI_LEO_SYNTAX|HI_SEMANTICS;
				//toa=HI_MORPHOLOGY|HI_SEMANTICS;
				//crh=HI_VERB;
				analyses=hi(text.c_str(),"ENG",toa,language.c_str(),"hi_desktop/hi.db","test",crh);
				if(analyses!=NULL){
					cout<<analyses<<endl;
					script_chr=hi_transcribe(language.c_str(),analyses);
					if(script_chr!=NULL){
						script=string(script_chr);
						if(script.length()>0){
							cout<<script<<endl;
							if(language=="sh"){
								if(argc>1&&string(argv[1])=="-d") script="set -x;"+script;
									fp=popen(script.c_str(),"r");
									if(fp!=NULL){
										while(fgets(line,sizeof line,fp)){
											cout<<line<<endl;
									}
									pclose(fp);
								}
							}
							else if(language=="js"){
								script="console.log((function(){"+script+"})())";
								ofstream *js_file=new std::ofstream("script.js");
								*js_file << script;
								js_file->close();
								delete js_file;
								fp=popen("node -e \"$(cat script.js)\"","r");
								if(fp!=NULL){
									while(fgets(line,sizeof line,fp)){
										cout<<line<<endl;
									}
									pclose(fp);
								}
							}
						}
					}
				}
				text.clear();
			}
			else break;
		}
	}
}
