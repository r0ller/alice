#include <jni.h>
#include <iostream>
#include "hilib.h"
#include <android/log.h>

extern "C" {
    JNIEXPORT jbyteArray JNICALL
    Java_hi_pkg_MainActivity_jhi
    (JNIEnv *env, jobject obj, jstring text, jstring language, jbyteArray error)
    {
    	const char *cstringout=NULL;
    	const char *cstringin=env->GetStringUTFChars(text, JNI_FALSE);
    	const char *cstringlanguage=env->GetStringUTFChars(language, JNI_FALSE);
    	char *cstringerror=new char[1024];
    	cstringout=hi(cstringin,cstringlanguage,cstringerror);
		__android_log_print(ANDROID_LOG_INFO, "hi", "jtranslation: %s", cstringout);
    	env->ReleaseStringUTFChars(text, cstringin);
    	env->ReleaseStringUTFChars(language, cstringlanguage);
    	env->SetByteArrayRegion(error, 0, strlen(cstringerror), (jbyte*)cstringerror);
    	delete[] cstringerror;
    	if(cstringout!=NULL){
			jbyteArray bytes = env->NewByteArray(strlen(cstringout));
			env->SetByteArrayRegion(bytes, 0, strlen(cstringout), (jbyte*)cstringout);
			delete[] cstringout;
			return bytes;
    	}
    	else{
    		return NULL;
    	}
    }
}
