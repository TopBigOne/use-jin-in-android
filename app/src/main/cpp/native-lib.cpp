#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>
#include "logutils.h"


using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

const char *NATIVE_CLASS_PATH = "com/ya/jnidynamicregister/NativeMethod";

jstring getString(JNIEnv *env, jobject thisObj) {
    return env->NewStringUTF(string("，，晚安啦，，").c_str());
}
/**
 * jni call java;
 * @param env
 * @param thisObj
 */
void execJniCallJava(JNIEnv *env, jobject thisObj) {
    LOGD("exec:Jni Call Java method---->");
    char const *classPath = "com/ya/jnidynamicregister/MainActivity";
    classPath = "com/ya/jnidynamicregister/MainActivity";

    jclass jcl = env->FindClass(classPath);
    if (jcl == nullptr) {
        LOGE("jclass is null");
        return;
    }

    jmethodID mid_construct = env->GetMethodID(jcl, "<init>", "()V");
    jmethodID methodId = env->GetMethodID(jcl, "startLoopTask", "(I)V");
    jobject jobj = env->NewObject(jcl, mid_construct);
    env->CallVoidMethod(jobj, methodId, 210);
}


int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *gMethods,
                          int numMethods) {
    jclass clazz = env->FindClass(className);
    if (clazz == nullptr)
        return JNI_FALSE;

    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        LOGE("registerNativeMethods in  error");
        return JNI_FALSE;
    }

    return JNI_TRUE;
}


JNINativeMethod nativeMethods[] = {
        {"getString",       "()V", (void *) getString},
        {"execJniCallJava", "()V", (void *) execJniCallJava},
};


int registerNatives(JNIEnv *env) {
    if (!registerNativeMethods(env, NATIVE_CLASS_PATH, nativeMethods,
                               sizeof(nativeMethods) / sizeof(nativeMethods[0]))) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = nullptr;
    LOGD("JNI_OnLoad ");

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    if (env == nullptr) return -1;
    if (!registerNatives(env)) {
        return -1;
    }
    return JNI_VERSION_1_6;
}


#ifdef __cplusplus
}
#endif