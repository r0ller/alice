#ifndef HILIB_H
	#define HILIB_H
    //type of analysis (toa) flags:
	#define HI_MORPHOLOGY 1
	#define HI_SYNTAX 2
	#define HI_SEMANTICS 4
    //contextual reference handling (crh) flags:
    #define HI_VERB 1
    #define HI_PRONOUN 2
    #ifdef __ANDROID__
        const char *hi(const char *,const char *,const unsigned char,const char *,const char *,JavaVM *,jobject,const char *,const unsigned char);
	#else
		#ifdef __EMSCRIPTEN__
		extern "C"{
		#endif
        const char *hi(const char *,const char *,const unsigned char,const char *,const char *,const char *,const unsigned char);
		#ifdef __EMSCRIPTEN__
		}
		#endif
	#endif
#endif
