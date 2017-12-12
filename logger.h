#ifndef LOGGER_H
	#define LOGGER_H

	#ifdef __ANDROID__
		#include "log.h"
	#endif
	#include <string>

	class logger{
		private:
			logger(const std::string&, const unsigned char&, const std::string&);
			static logger *singleton_instance;
			std::string log_mode;
			unsigned char error_level;
			std::string error_level_filter;
		public:
			~logger();
			static logger *singleton(const std::string& log_mode, const unsigned char& error_level, const std::string& error_level_filter){
				if(logger::singleton_instance==NULL){
					logger::singleton_instance=new logger(log_mode,error_level,error_level_filter);
				}
				return logger::singleton_instance;
			};
			static logger *singleton(){
				if(logger::singleton_instance==NULL){
					logger::singleton_instance=new logger("console",0,"LE");
				}
				return logger::singleton_instance;
			};
			void log(const unsigned char&, const std::string&);
	};
#endif
