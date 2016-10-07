#ifndef DB_H
	#define DB_H

	#include <string>
	#include <exception>
	#include "query_result.h"
	#include <deque>
	#include "morphan_result.h"

	typedef struct{
		unsigned int token;
		std::string word;
		std::string lid;
		std::string gcat;
		std::string lexeme;
		query_result *dependencies=NULL;
		morphan_result *morphalytics=NULL;
		std::deque<unsigned int> tokens;
	}lexicon;

	class db{
		public:
			virtual ~db(){};
			virtual void open(const std::string&)=0;
			virtual void close()=0;
			virtual const std::string error_message()=0;
			virtual query_result *exec_sql(const std::string&)=0;
	};

	#if defined(__ANDROID__)
		#include "jni_db.h"
	#elif defined(__EMSCRIPTEN__) && defined(__EMBEDNODB__)
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
					#elif defined(__EMSCRIPTEN__) && defined(__EMBEDNODB__)
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

	db *db_factory::singleton_instance=NULL;

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

	#if defined(__ANDROID__)
		#include "jni_db.cpp"
	#elif defined(__EMSCRIPTEN__) && defined(__EMBEDNODB__)
		#include "js_db.cpp"
	#else
		#include "sqlite_db.cpp"
	#endif

#endif
