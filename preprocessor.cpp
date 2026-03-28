#include "preprocessor.h"

preprocessor::preprocessor(const time_t& timestamp,const std::string& text){
	this->timestamp=std::to_string(timestamp);
	this->text=text;
}

preprocessor::~preprocessor(){

}

std::string preprocessor::original_text() const{
	return text;
}
