#include "jni_db.h"

jni_db::jni_db(){
	env=jnienv();
	cl_string=reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/String")));
	getBytes=env->GetMethodID(cl_string, "getBytes", "()[B");
	cl_dbhelper=reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("com/bitroller/hi/DatabaseHelper")));
	jmethodID dbhelper_constructor=env->GetMethodID(cl_dbhelper, "<init>", "()V");
	dbhelperobj=reinterpret_cast<jobject>(env->NewGlobalRef(env->NewObject(cl_dbhelper,dbhelper_constructor)));
	dbhelper_error_message=env->GetMethodID(cl_dbhelper, "error_message", "()Ljava/lang/String;");
	dbhelper_open=env->GetMethodID(cl_dbhelper, "open", "(Ljava/lang/String;)V");
	dbhelper_close=env->GetMethodID(cl_dbhelper, "close", "()V");
	dbhelper_exec_sql=env->GetMethodID(cl_dbhelper, "exec_sql", "(Ljava/lang/String;)[Ljava/lang/String;");
	dbhelper_get_metadata=env->GetMethodID(cl_dbhelper, "get_metadata", "()[Ljava/lang/String;");
}

jni_db::~jni_db(){
	env->DeleteGlobalRef(cl_string);
	env->DeleteGlobalRef(dbhelperobj);
	env->DeleteGlobalRef(cl_dbhelper);
}

void jni_db::open(const std::string& filename){
	jstring jfilename=env->NewStringUTF(filename.c_str());
	env->CallVoidMethod(dbhelperobj,dbhelper_open,jfilename);
	if(env->ExceptionCheck()==JNI_TRUE){
		env->ExceptionClear();
		throw failed_to_open_db();
	}
	env->ReleaseStringUTFChars(jfilename,env->GetStringUTFChars(jfilename,NULL));
	env->DeleteLocalRef(jfilename);
}

void jni_db::close(){
	env->CallVoidMethod(dbhelperobj,dbhelper_close);
	if(env->ExceptionCheck()==JNI_TRUE){
		env->ExceptionClear();
		throw failed_to_close_db();
	}
}

const std::string jni_db::error_message(){
	jstring error=reinterpret_cast<jstring>(env->CallObjectMethod(dbhelperobj,dbhelper_error_message));
	if(env->ExceptionCheck()==JNI_TRUE){
		env->ExceptionClear();
	}
	//TODO:GetStringUTFChars() uses modified UTF-8 encoding, may need to be replaced
	//by the byteArray trick used in exec_sql below
	std::string errmsg=std::string(env->GetStringUTFChars(error,NULL));
	env->ReleaseStringUTFChars(error,env->GetStringUTFChars(error,NULL));
	env->DeleteLocalRef(error);
	return errmsg;
}

query_result *jni_db::exec_sql(const std::string& sql){
	query_result *result=NULL;
	std::string row_index;
	field field;
	char **fields=NULL;

	jstring jsql=env->NewStringUTF(sql.c_str());
	jobjectArray raw_sqlite_result=reinterpret_cast<jobjectArray>(env->CallObjectMethod(dbhelperobj,dbhelper_exec_sql,jsql));
	if(env->ExceptionCheck()==JNI_TRUE){
		env->ExceptionClear();
		throw sql_execution_error();
	}
	if(raw_sqlite_result!=NULL){
		jsize raw_sqlite_result_size=env->GetArrayLength(raw_sqlite_result);
		result=new query_result();
		jobjectArray column_names=reinterpret_cast<jobjectArray>(env->CallObjectMethod(dbhelperobj,dbhelper_get_metadata));
		jsize column_names_size=env->GetArrayLength(column_names);
		if(column_names_size>0){
			fields=new char*[column_names_size];
			for(jsize i=0;i<column_names_size;++i){
				jstring column_name=reinterpret_cast<jstring>(env->GetObjectArrayElement(column_names,i));
				std::string colname=jstring2string(column_name);
				fields[i]=new char[colname.length()+1];
				env->DeleteLocalRef(column_name);
			    fields[i][colname.length()]='\0';
			    colname.copy(fields[i],colname.length());

			}
			unsigned int nr_of_columns=column_names_size;
			result->set_metadata(nr_of_columns,(const char**) &(*fields));
		}
		unsigned char row_struct_counter=0;
		for(jsize i=0;i<raw_sqlite_result_size;++i){
			if(row_struct_counter==0){
				jstring rowid=reinterpret_cast<jstring>(env->GetObjectArrayElement(raw_sqlite_result,i));
				row_index=jstring2string(rowid);
				env->DeleteLocalRef(rowid);
				row_struct_counter=1;
			}
			else if(row_struct_counter==1){
				jstring column_name=reinterpret_cast<jstring>(env->GetObjectArrayElement(raw_sqlite_result,i));
				field.field_name=jstring2string(column_name);
				env->DeleteLocalRef(column_name);
				row_struct_counter=2;
			}
			else if(row_struct_counter==2){
				jstring column_value=reinterpret_cast<jstring>(env->GetObjectArrayElement(raw_sqlite_result,i));
				field.field_value=jstring2string(column_value);
				env->DeleteLocalRef(column_value);
				result->insert(std::make_pair(std::atoi(row_index.c_str()),field));
				row_struct_counter=0;
			}
		}
		env->DeleteLocalRef(raw_sqlite_result);
		env->DeleteLocalRef(column_names);
		env->ReleaseStringUTFChars(jsql,env->GetStringUTFChars(jsql,NULL));
		env->DeleteLocalRef(jsql);
	}
	return result;
}

JNIEnv *jni_db::jnienv(){
	JNIEnv *jnienv=NULL;
	if(jvm->GetEnv(reinterpret_cast<void**>(&jnienv),JNI_VERSION_1_6)!=JNI_OK) {
		__android_log_print(ANDROID_LOG_INFO, "hi", "exiting: jvm->GetEnv() error");
		exit(EXIT_FAILURE);
    }
//	jvm->AttachCurrentThread(&jnienv, NULL);
	return jnienv;
}

std::string jni_db::jstring2string(const jstring& jtext){
	std::string text;

    if(jtext!=NULL){
		const auto stringJbytes=(jbyteArray) env->CallObjectMethod(jtext,getBytes);
		const auto length=env->GetArrayLength(stringJbytes);
		const auto pBytes=env->GetByteArrayElements(stringJbytes,NULL);
		text=std::string((char *)pBytes,length);
		env->ReleaseByteArrayElements(stringJbytes,pBytes,JNI_ABORT);
		env->DeleteLocalRef(stringJbytes);
    }
    return text;
}
