#ifndef DB_FACTORY_H
	#define DB_FACTORY_H

	#define EMBEDDED 1
	#define NODEJS 2
	#define NETWORK 3

	#if defined(__ANDROID__)
        #include "jni_db.h"
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
		public:
			virtual const char *what() const throw(){
				//Since the C-string returned by what() is valid until the exception object
				//gets destroyed and the sqlite error message string is managed by sqlite
				//internally, the best bet is to get a copy of it to avoid any crash.
				return db_factory::get_instance()->error_message().c_str();
			}
	};

	class sql_execution_error:public db_error{};

	class failed_to_open_db:public db_error{};

	class failed_to_close_db:public db_error{};

#endif
