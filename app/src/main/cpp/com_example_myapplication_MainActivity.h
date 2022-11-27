#include <jni.h>
//解决循环copy的问题第二次就进不来了
#ifndef _Included_com_example_myapplication_MainActivity //如果没有定义这个宏
#define _Included_com_example_myapplication_MainActivity //我就定义这个宏
#ifdef __cplusplus//如果是C++环境
extern "C" {//全部采用c的方式 禁止函数重载
#endif
#undef com_example_myapplication_MainActivity_A
#define com_example_myapplication_MainActivity_A 100L
    // 函数的声明
JNIEXPORT jstring JNICALL Java_com_example_myapplication_MainActivity_getString
  (JNIEnv *, jobject);

#ifdef __cplusplus//省略 如果是c++ 啥事不做
}
#endif
#endif
//extern "C"
//JNIEXPORT void JNICALL
//Java_com_example_myapplication_MainActivity_changName(JNIEnv *env, jobject thiz) {
//    // TODO: implement changName()
//}