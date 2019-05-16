#ifndef LOGGER_H
	#define LOGGER_H

	#ifdef __ANDROID__
		#include "log.h"
	#endif
	#include <iostream>
	#include <string>

	class logger{
		private:
			logger(const std::string&, const unsigned char&, const std::string&);
			static logger *singleton_instance;
			std::string log_mode;
			unsigned char error_level;
			std::string error_level_filter;
		public:
			~logger();//Use this to set singleton_instance to NULL i.e. to turn it off on the fly
			static logger *singleton(const std::string& log_mode, const unsigned char& error_level, const std::string& error_level_filter){
				if(logger::singleton_instance!=NULL){//make logger reconfiguration easier on the fly
					delete logger::singleton_instance;
				}
				logger::singleton_instance=new logger(log_mode,error_level,error_level_filter);
				return logger::singleton_instance;
			};
			static logger *singleton(){
				//returning whatever we have there in order to be able to carry out
				//a real turned-off check by:
				//logger::singleton()==NULL?(void)0:logger::singleton()->log(...);
				//If logging is not turned off there's almost no penalty on using it as the
				//condition in the ternary operator just checks for being NULL or not and
				//when not, then we get the pointer again and call the log() method.
				//However, when logging is turned off, only one check is carried out and no
				//superfluous call to log() method takes place.
				return logger::singleton_instance;
			};
			void log(const unsigned char&, const std::string&);
	};
#endif
