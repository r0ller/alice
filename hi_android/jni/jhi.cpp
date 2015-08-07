#include <jni.h>
#include <iostream>
#include "hilib.h"
#include <android/log.h>

extern "C" {
    JNIEXPORT jbyteArray JNICALL
    Java_hi_pkg_MainActivity_jhi
    (JNIEnv *env, jobject obj, jstring text)
    {
    	const char *cstringout=NULL;
    	const char *cstringin=env->GetStringUTFChars(text, JNI_FALSE);
    	cstringout=hi(cstringin);
		__android_log_print(ANDROID_LOG_INFO, "hi", "jtranslation: %s", cstringout);
    	env->ReleaseStringUTFChars(text, cstringin);
//    	env->DeleteLocalRef(cstringin);
    	if(cstringout!=NULL){
			jbyteArray bytes = env->NewByteArray(strlen(cstringout));
			env->SetByteArrayRegion(bytes, 0, strlen(cstringout), (jbyte*)cstringout);
			delete[] cstringout;
			return bytes;
    	}
    	else{
    		return NULL;
    	}
//    	return env->NewStringUTF(cstringout);
    }
}
