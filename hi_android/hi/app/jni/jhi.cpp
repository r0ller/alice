#include <jni.h>
#include <iostream>
#include "hilib.h"
#include <android/log.h>

//If the project is not gradle aware, this one needs to be compiled by simply invoking
//in the project directory:
//c:\Users\username\AppData\Local\Android\sdk\ndk-bundle\ndk-build.cmd -C C:\path\to\jni\folder
//If Android Studio cannot correctly pack and build it with the java part,
//in the Module Settings add the jni directory on the Path tab as External Annotation
//and on the Dependencies tab add as Library the libs (or even as specfic as libs/armeabi-v7a) directory.
//Not sure though if any of them helps kickstarting the build:(
extern "C" {
    JNIEXPORT jbyteArray JNICALL
    Java_com_bitroller_hi_MainActivity_jhi
    (JNIEnv *env, jobject obj, jstring text, jstring language, jstring db_uri)
    {
    	const char *analysis=NULL;
    	const char *text_=env->GetStringUTFChars(text, JNI_FALSE);
    	const char *language_=env->GetStringUTFChars(language, JNI_FALSE);
		const char *db_uri_=env->GetStringUTFChars(db_uri, JNI_FALSE);
    	JavaVM* javaVM=NULL;
    	env->GetJavaVM(&javaVM);
    	jobject activity = env->NewGlobalRef(obj);
    	analysis=hi(text_,language_,HI_MORPHOLOGY|HI_SEMANTICS,"js",db_uri_,javaVM,activity);
		__android_log_print(ANDROID_LOG_INFO, "hi", "jtranslation: %s", analysis);
    	env->ReleaseStringUTFChars(text, text_);
    	env->ReleaseStringUTFChars(language, language_);
    	if(analysis!=NULL){
			jbyteArray bytes = env->NewByteArray(strlen(analysis));
			env->SetByteArrayRegion(bytes, 0, strlen(analysis), (jbyte*)analysis);
			delete[] analysis;
			return bytes;
    	}
    	else{
    		return NULL;
    	}
    }
}
