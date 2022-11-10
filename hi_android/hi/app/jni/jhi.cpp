#include <jni.h>
#include <iostream>
#include "../src/main/cpp/hilib.h"
#include <android/log.h>

extern "C" {
JNIEXPORT jbyteArray JNICALL
Java_com_bitroller_hi_MainActivity_jhi(JNIEnv *env, jclass obj, jstring text, jstring language,
                                       jstring db_uri, int toa, int crh) {
    const char *analysis = nullptr;
    const char *text_ = env->GetStringUTFChars(text, JNI_FALSE);
    const char *language_ = env->GetStringUTFChars(language, JNI_FALSE);
    const char *db_uri_ = env->GetStringUTFChars(db_uri, JNI_FALSE);
    const unsigned char toa_ = toa;
    const unsigned char crh_ = crh;
    JavaVM *javaVM = nullptr;
    env->GetJavaVM(&javaVM);
    //jint rc=env->EnsureLocalCapacity(500);
    jobject activity = env->NewGlobalRef(obj);
    analysis = hi(text_, language_, toa_, "js", db_uri_, javaVM, activity, "test", crh_);
    __android_log_print(ANDROID_LOG_INFO, "hi", "jtranslation: %s", analysis);
    env->ReleaseStringUTFChars(text, text_);
    env->ReleaseStringUTFChars(language, language_);
    if (analysis != nullptr) {
        jbyteArray bytes = env->NewByteArray(strlen(analysis));
        env->SetByteArrayRegion(bytes, 0, strlen(analysis), (jbyte *) analysis);
        delete[] analysis;
        return bytes;
    } else {
        return nullptr;
    }
}
}
extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_bitroller_hi_MainActivity_jhi_1transcribe(JNIEnv *env, jclass obj, jstring analyses) {
    const char *analyses_ = env->GetStringUTFChars(analyses, JNI_FALSE);
    const char *script = nullptr;

    script=hi_transcribe("js",analyses_);
    env->ReleaseStringUTFChars(analyses, analyses_);
    if (script != nullptr) {
        jbyteArray bytes = env->NewByteArray(strlen(script));
        env->SetByteArrayRegion(bytes, 0, strlen(script), (jbyte *) script);
        delete[] script;
        return bytes;
    } else {
        return nullptr;
    }
}