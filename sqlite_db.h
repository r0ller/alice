#ifndef SQLITE_DB_H
	#define SQLITE_DB_H

	#include <algorithm>
	#include <string>
	#include "sqlite3.h"
	#include <utility>
	#include "query_result.h"

	class sqlite_db:public db{
		private:
			static int store_row_data(void *, int, char **, char **);
			sqlite3 *sqlite;
			static int (*fptr_store_row_data)(void *, int, char **, char **);
		public:
			sqlite_db();
			~sqlite_db() override;
			void open(const std::string&) override;
			void close() override;
			const std::string error_message() override;
			query_result *exec_sql(const std::string&) override;
	};

#endif
