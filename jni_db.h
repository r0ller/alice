#ifndef JNI_DB_H
	#define JNI_DB_H

	#include "jni.h"
	#include <string>
	#include <utility>
	#include <exception>
	#include "query_result.h"

	class jni_db:public db{
		private:
			JNIEnv *env;
			jclass cl_string;
			jclass cl_dbhelper;
			jobject dbhelperobj;
			jmethodID dbhelper_error_message;
			jmethodID dbhelper_open;
			jmethodID dbhelper_close;
			jmethodID dbhelper_exec_sql;
			jmethodID dbhelper_get_metadata;
			jmethodID getBytes;
			JNIEnv *jnienv();
			std::string jstring2string(const jstring&);
			std::string db_uri_;
		public:
			jni_db();
			~jni_db() override;
			void open(const std::string&) override;
			void close() override;
			const std::string error_message() override;
			query_result *exec_sql(const std::string&) override;
			std::string db_uri() override;
	};

#endif
