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
		bool lexicon_entry;
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
			virtual std::string db_uri()=0;
	};

#endif
