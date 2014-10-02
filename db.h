#ifndef DB_H
	#define DB_H

	#include <map>
	#include <string>
	#include "sqlite3.h"
	#include <iterator>
	#include <utility>
	#include <exception>

	typedef struct{
		unsigned int rowid;
		std::string word;
		std::string gcat;
		std::string lexeme;
	}lexicon;

	typedef struct{
		std::string field_name;
		std::string field_value;
	}field;

	class db{
		private:
			db();
			static int store_row_data(void *, int, char **, char**);
			void destroy_result();
			sqlite3 *sqlite;
			static int (*fptr_store_row_data)(void *, int, char **, char**);
			static db *singleton_instance;
			std::multimap<unsigned int,field> result_set;
			unsigned int result_set_size;
		public:
			~db();
			static db *get_instance(){
				if(db::singleton_instance==NULL)
					db::singleton_instance=new db;
				return db::singleton_instance;
			};
			void open(const std::string&);
			void close();
			const std::string error_message();
			const std::multimap<unsigned int,field>& exec_sql(const std::string&);
			std::multimap<unsigned int,field>::const_iterator get_row(unsigned int);
			const std::string& get_field_value(unsigned int, const std::string&);
			const std::multimap<unsigned int,field>& query_result_set();
			unsigned int result_size();
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
