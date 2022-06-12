#ifndef JS_TRANSCRIPTOR_H
#define JS_TRANSCRIPTOR_H

#include "transcriptor.h"

class js_transcriptor:public transcriptor{
    private:
        std::string args_to_jsfun_arglist(std::vector<std::string>&);
        std::string args_to_jsfun_pmlist(std::vector<std::string>&);
    protected:
        std::string transcribeDependencies(rapidjson::Value&,rapidjson::Value&,rapidjson::Value&,rapidjson::Value&,std::vector<std::string>&) override;
    public:
        js_transcriptor(const char *analyses);
        ~js_transcriptor();
};

#endif // JS_TRANSCRIPTOR_H
