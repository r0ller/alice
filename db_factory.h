#ifndef DB_FACTORY_H
	#define DB_FACTORY_H

	#define EMBEDDED 1
	#define NODEJS 2
	#define NETWORK 3

	#if defined(__ANDROID__)
		#include "jni_db.h"
		//#include "sqlite_db.h"
	#elif defined(__EMSCRIPTEN__) && FS==NETWORK
		#include "js_db.h"
	#else
		#include "sqlite_db.h"
	#endif

	class db_factory{
		private:
			static db *singleton_instance;
		public:
			static db *get_instance(){
				if(db_factory::singleton_instance==NULL){
					#if defined(__ANDROID__)
						db_factory::singleton_instance=new jni_db;
						//db_factory::singleton_instance=new sqlite_db;
					#elif defined(__EMSCRIPTEN__) && FS==NETWORK
						db_factory::singleton_instance=new js_db;
					#else
						db_factory::singleton_instance=new sqlite_db;
					#endif
				}
				return db_factory::singleton_instance;
			};
			static void delete_instance(){
				delete singleton_instance;
				singleton_instance=NULL;
			};
	};

	class db_error:public std::exception{
		protected:
			std::string error_msg;
		public:
			db_error(std::string error_msg){
				this->error_msg=error_msg;
			}
			virtual const char *what() const throw(){
				//Since the C-string returned by what() is valid until the exception object
				//gets destroyed and the sqlite error message string is managed by sqlite
				//internally, the best bet is to get a copy of it to avoid any crash.
				return error_msg.c_str();
			}
	};

	class sql_execution_error:public db_error{
		public:
		sql_execution_error(std::string error_msg):db_error(error_msg){
		}
		~sql_execution_error() throw() {}
	};

	class failed_to_open_db:public db_error{
		public:
		failed_to_open_db(std::string error_msg):db_error(error_msg){
		}
		~failed_to_open_db() throw() {}
	};

	class failed_to_close_db:public db_error{
		public:
		failed_to_close_db(std::string error_msg):db_error(error_msg){
		}
		~failed_to_close_db() throw() {}
	};

#endif
