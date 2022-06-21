#include "js_transcriptor.h"
#include "sh_transcriptor.h"

const char *hi_transcribe(const char *transcriptor,const char *analyses){
    sh_transcriptor *sh_trans=NULL;
    js_transcriptor *js_trans=NULL;
    std::string script;
    char *script_chr=NULL;

    if(std::string(transcriptor)=="sh"){
        sh_trans=new sh_transcriptor(analyses);
        script=sh_trans->transcribe();
    }
    else if(std::string(transcriptor)=="js"){
        js_trans=new js_transcriptor(analyses);
        script=js_trans->transcribe();
    }
    if(script.empty()==false){
        script_chr=new char[script.length()+1];
        script.copy(script_chr,script.length(),0);
        script_chr[script.length()]='\0';
    }
    return script_chr;
}
