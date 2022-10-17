#include "hilib.h" 
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char **argv){

    const char *analyses,*script_chr=NULL;
    string text,script,language="sh";
	FILE *fp;
    char line[256];
    unsigned char toa=0,crh=0;

    if(argc==6&&string(argv[1])=="-q"){
        //In case of interrogative mood each functor should return in its $1_out parameter a table appending such a json object
        //entry like in the example below in order that the main verb functor can modify it and pass the table to hi_query().
        //Example for 'what is executable ?'
        /*analyses=hi_query("hi_desktop/hi.db","BEENGV",1,"{\"dependencies\":["
        "{\"lexeme\":\"WHATENGPRON\",\"c_value\":\"\",\"word\":\"what\",\"is_con\":false,\"is_qword\":true,\"mood\":\"indicative\"},"
        "{\"lexeme\":\"BEENGV\",\"c_value\":\"\",\"word\":\"\",\"is_con\":false,\"is_qword\":false,\"mood\":\"indicative\"},"
        "{\"lexeme\":\"EXECUTABLEENGA\",\"c_value\":\"\",\"word\":\"\",\"is_con\":false,\"is_qword\":false,\"mood\":\"indicative\"}"
        "]}");*/
        analyses=hi_query(argv[2],argv[3],atoi(argv[4]),argv[5]);
        if(analyses!=NULL){
            cout<<analyses<<endl;
        }
    }
    else if(argc==5&&string(argv[1])=="-c"){
        //hi_state_cvalue("hi_desktop/hi.db","{\"source\":\"test\",\"timestamp\":1655803024,\"sentence\":\"file abc is executable .\",\"rank\":1,\"a_counter\":1,\"mood\":\"indicative\",\"function\":\"CON_6\"}","test");
        hi_state_cvalue(argv[2],argv[3],argv[4]);
    }
    else{
        while(true){
            getline(cin,text);
            //text="üzenem Aliznak hogy x\n";
            if(text.empty()==false){
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
