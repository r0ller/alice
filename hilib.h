#ifndef HILIB_H
	#define HILIB_H
	#include "hi_constants.h"
	#ifdef __ANDROID__
		const char *hi(const char *,const char *,const unsigned char,const char *,const char *,JavaVM *,jobject,const char *,const unsigned char);
		const char *hi_query(const char*, const char*, const unsigned int, const char*);
		int hi_state_cvalue(const char *,const char *,const char *);
		const char *hi_transcribe(const char *,const char *);
	#else
		#ifdef __EMSCRIPTEN__
		extern "C"{
		#endif
		const char *hi(const char *,const char *,const unsigned char,const char *,const char *,const char *,const unsigned char);
		const char *hi_query(const char*, const char*, const char*);
		int hi_state_cvalue(const char *,const char *,const char *,const char *);
		const char *hi_transcribe(const char *,const char *);
		#ifdef __EMSCRIPTEN__
		}
		#endif
	#endif
#endif
