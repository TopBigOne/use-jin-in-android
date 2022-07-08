//
// Created by dev on 2022/7/8.
//
#include <android/log.h>
#ifndef JNI_DYNAMIC_REGISTER_LOGUTILS_H
#define JNI_DYNAMIC_REGISTER_LOGUTILS_H

#define TAG "DYNAMIC_JNI"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型



#endif //JNI_DYNAMIC_REGISTER_LOGUTILS_H
