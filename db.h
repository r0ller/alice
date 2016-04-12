#ifndef DB_H
	#define DB_H

	#include <map>
	#include <string>
	#include "sqlite3.h"
	#include <iterator>
	#include <utility>
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
		std::vector<unsigned int> tokens;
	}lexicon;

	class db{
		private:
			db();
			static int store_row_data(void *, int, char **, char **);
			sqlite3 *sqlite;
			static int (*fptr_store_row_data)(void *, int, char **, char **);
			static db *singleton_instance;
		public:
			~db();
			static db *get_instance(){
				if(db::singleton_instance==NULL) db::singleton_instance=new db;
				return db::singleton_instance;
			};
			void open(const std::string&);
			void close();
			const std::string error_message();
			query_result *exec_sql(const std::string&);
	};

	class db_error:public std::exception{
		public:
			virtual const char *what() const throw(){
				//Since the C-string returned by what() is valid until the exception object
				//gets destroyed and the sqlite error message string is managed by sqlite
				//internally, the best bet is to get a copy of it to avoid any crash.
				return db::get_instance()->error_message().c_str();
			}
	};

	class sql_execution_error:public db_error{};

	class failed_to_open_db:public db_error{};

	class failed_to_close_db:public db_error{};

#endif
