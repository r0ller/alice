#include <jni.h>
#include <iostream>
#include "hilib.h"
#include <android/log.h>

//As the project is not gradle aware, this one needs to be compiled by simply invoking
//ndk-build.cmd (like c:\Users\username\AppData\Local\Android\sdk\ndk-bundle\ndk-build.cmd)
//in the project directory
//If Android Studio cannot correctly pack and build it with the java part,
//in the Module Settings add the jni directory on the Path tab as External Annotation
//and on the Dependencies tab add as Library the libs (or even as specfic as libs/armeabi-v7a) directory.
//Not sure which of them helped kickstarting the build as after removing both it still works:)
extern "C" {
    JNIEXPORT jbyteArray JNICALL
    Java_com_bitroller_hi_MainActivity_jhi
    (JNIEnv *env, jobject obj, jstring text, jstring language, jbyteArray error)
    {
    	const char *cstringout=NULL;
    	const char *cstringin=env->GetStringUTFChars(text, JNI_FALSE);
    	const char *cstringlanguage=env->GetStringUTFChars(language, JNI_FALSE);
    	char *cstringerror=new char[1024];
    	JavaVM* javaVM=NULL;
    	env->GetJavaVM(&javaVM);
    	jobject activity = env->NewGlobalRef(obj);
    	cstringout=hi(cstringin,cstringlanguage,cstringerror,javaVM,activity);
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
