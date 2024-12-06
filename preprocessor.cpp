#include "preprocessor.h"

preprocessor::preprocessor(const time_t& timestamp){
	this->timestamp=std::to_string(timestamp);
}

preprocessor::~preprocessor(){

}