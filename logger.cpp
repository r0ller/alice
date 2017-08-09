#include "logger.h"

logger *logger::singleton_instance=NULL;

logger::logger(const std::string& log_mode, const unsigned char& error_level, const std::string& error_level_filter){
	this->log_mode=log_mode;
	this->log_mode="console";//console log mode is supported only for the time being
	this->error_level=error_level;
	if(error_level_filter=="LT"||error_level_filter=="LE"||error_level_filter=="EQ"||error_level_filter=="GE"||error_level_filter=="GT"){
		this->error_level_filter=error_level_filter;
	}
	else this->error_level_filter="LE";
}

logger::~logger(){

}

void logger::log(const unsigned char& error_level, const std::string& message){

	if(log_mode=="console"){
		if(error_level_filter=="LT"){

		}
		else if(error_level_filter=="LE"){
			if(error_level<=this->error_level){
				#ifdef __ANDROID__
					if(error_level==0){
						__android_log_print(ANDROID_LOG_INFO, "hi", message.c_str());
					}
					else if(error_level==1){
						__android_log_print(ANDROID_LOG_WARN, "hi", message.c_str());
					}
					else if(error_level==2){
						__android_log_print(ANDROID_LOG_ERROR, "hi", message.c_str());
					}
					else if(error_level==3){
						__android_log_print(ANDROID_LOG_DEBUG, "hi", message.c_str());
					}
					else{
						__android_log_print(ANDROID_LOG_INFO, "hi", message.c_str());
					}
				#else
					std::cout<<message<<std::endl;
				#endif

			}
		}
		else if(error_level_filter=="EQ"){

		}
		else if(error_level_filter=="GE"){

		}
		else if(error_level_filter=="GT"){

		}
		else{

		}
	}
}
