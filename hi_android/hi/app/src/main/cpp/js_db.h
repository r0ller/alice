#ifndef JS_DB_H
	#define JS_DB_H

	#include <string>
	#include <utility>
	#include <exception>
	#include <emscripten.h>
//	#include <emscripten/val.h>
//	#include <emscripten/bind.h>
	#include "db.h"
	#include "query_result.h"

	class js_db:public db{
		private:
			std::string db_uri;
			int mongodb_init_fptr;
			int mongodb_open_fptr;
		public:
			js_db();
			~js_db() override;
			void open(const std::string&) override;
			void close() override;
			const std::string error_message() override;
			query_result *exec_sql(const std::string&) override;
	};

#endif
