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
        //Another example for 'when is peter's birthday ?'
        //"{\"dependencies\":[{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"BEENGV_1_4\",\"counter\":0,\"level\":0,\"word\":\"is\",\"lexeme\":\"\",\"d_key\":0,\"d_counter\":0,\"dependency\":\"BEENGV\",\"ref_d_key\":1,\"tags\":{\"is_root\":\"true\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"WHENENGPRON_1\",\"counter\":1,\"level\":1,\"word\":\"when\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":1,\"dependency\":\"WHENENGPRON\",\"ref_d_key\":1,\"tags\":{\"is_qword\":\"true\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"BIRTHDAYENGN_1_15\",\"counter\":2,\"level\":1,\"word\":\"birthday\",\"lexeme\":\"BEENGV\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"BIRTHDAYENGN\",\"ref_d_key\":1,\"tags\":{\"qword\":\"when\"},\"c_value\":\"\"},{\"source\":\"test\",\"timestamp\":1671634874,\"sentence\":\"when is peter's birthday ?\",\"rank\":1,\"a_counter\":1,\"mood\":\"interrogative\",\"function\":\"CON_10\",\"counter\":3,\"level\":2,\"word\":\"peter's\",\"lexeme\":\"BIRTHDAYENGN\",\"d_key\":1,\"d_counter\":2,\"dependency\":\"CON\",\"ref_d_key\":1,\"tags\":{},\"c_value\":\"\"}]}";
        analyses=hi_query(argv[2],argv[3],argv[4]);
        if(analyses!=NULL){
            cout<<analyses<<endl;
            rapidjson::Document jsondoc;
            jsondoc.Parse(analyses);
            if(jsondoc.HasMember("analyses")==true){
                rapidjson::Value& analysesArray=jsondoc["analyses"];
                if(analysesArray.IsArray()==true&&analysesArray.Size()>0){
                    rapidjson::SizeType i=analysesArray.Size()-1;
                    for(i;i>0;--i){
                        auto analysisObject=analysesArray[i].GetObject();
                        //look for the first analysis having the qword tag and c_calue then stop
                        string c_value=analysisObject["c_value"].GetString();
                        if(analysisObject["tags"].HasMember("qword")==true&&c_value.empty()==false){
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
        hi_state_cvalue(argv[2],argv[3],argv[4],argv[5]);
    }
    else{
        while(true){
          getline(cin,text);
          //Test sms scenario:
            //text="üzenem péternek hogy hello\n";
            //text="a harmadiknak\n";
            //text="küldd\n";
          //Test context ref handling for verb:
            //text="hí­vd fel pétert\n";
            //text="a harmadikat\n";
          //Test interpreting statement (see question test above at -q):
            //text="today is peter's birthday .\n";
          //Test sentence without verb and no context ref handling:
            //text="files in abc\n";
            //text="felolvasás be\n";
          if(text.empty()==false){
            //toa=HI_MORPHOLOGY|HI_SYNTAX;
            toa=HI_MORPHOLOGY|HI_SYNTAX|HI_SEMANTICS;
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
                                        while(fgets(line,sizeof line,fp))
                                        {
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
                                        while(fgets(line,sizeof line,fp))
                                        {
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
