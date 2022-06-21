#ifndef TRANSCRIPTOR_H
#define TRANSCRIPTOR_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include <vector>
#include <string>

class transcriptor{
    protected:
        rapidjson::Document jsondoc;
        void find_replace(std::string&,const std::string&,const std::string&);
        std::string value_to_string(rapidjson::Value&);
        virtual std::string transcribeDependencies(rapidjson::Value&,rapidjson::Value&,rapidjson::Value&,rapidjson::Value&,std::vector<std::string>&)=0;
    public:
        transcriptor(const char *);
        virtual ~transcriptor(){};
        std::string transcribe();
};

#endif // TRANSCRIPTOR_H
