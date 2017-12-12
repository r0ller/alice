#ifndef HILIB_H
	#define HILIB_H
	#define HI_MORPHOLOGY 1
	#define HI_SYNTAX 2
	#define HI_SEMANTICS 4
	#ifdef __ANDROID__
		const char *hi(const char *,const char *,const unsigned char,const char *,const char *,JavaVM *,jobject);
	#else
		const char *hi(const char *,const char *,const unsigned char,const char *,const char *);
	#endif
#endif
