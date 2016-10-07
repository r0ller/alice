#ifndef HILIB_H
	#define HILIB_H
	#ifdef __ANDROID__
		const char *hi(const char *,const char *,char *, JavaVM *, jobject);
	#else
		const char *hi(const char *,const char *,char *);
	#endif
#endif
