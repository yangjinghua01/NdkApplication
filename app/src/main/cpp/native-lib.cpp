#include "com_example_myapplication_MainActivity.h"//引入头文件
#include "android/log.h" //导入安卓的日志包

#define  TAG "YJH"
// ...我都不知道传入什么我可以借助JNI里面的宏来自动帮我填充
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
// 必须此阿勇c的编译方式。为什么，看JNIENv内部源码。
//函数的实现
extern "C"
JNIEXPORT //标记该方法可以被外部调用
jstring //java <--------->转换用的
JNICALL //代表是jni的标记 可以少
//JNIEnv *env JNI的桥梁环境
//jobject jobj 谁调用，mainactivity的实例
//jclass 谁调用就是谁的class
Java_com_example_myapplication_MainActivity_getString(JNIEnv *env, jobject jobj) {
//    无论是c还是c++ 最终都会调用到c的JNINativeIntreface，所以必须才用c的方式extern"C"


}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_getString2(JNIEnv *env, jclass clazz) {
    // TODO: implement getString2()
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_changName(JNIEnv *env, jobject thiz) {
// TODO: implement changName()
// 获取class
    jclass j_cls = env->GetObjectClass(thiz);
//获取属性
//jfieldID GetGFiledID(jclass clazz ,congst char* name,const char * sig)
/**
 * jclass: MainActivity
 * char*:方法名
 * char *:方法签名
 */
    jfieldID j_fid = env->GetFieldID(j_cls, "name", "Ljava/lang/String;");
    jstring j_str = static_cast<jstring>(env->GetObjectField(thiz, j_fid));
//     打印字符串
    char *c_str = const_cast<char *>(env->GetStringUTFChars(j_str, NULL));
    LOGD("native:%s", c_str);
    LOGE("native:%s", c_str);
    LOGI("native:%s", c_str);
    jstring j_name = env->NewStringUTF("Beyond");
    env->SetObjectField(thiz, j_fid, j_name);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_changage(JNIEnv *env, jclass clazz) {
    jfieldID j_fid = env->GetStaticFieldID(clazz, "age", "I");
    jint age = env->GetStaticIntField(clazz, j_fid);
    age += 10;
    env->SetStaticIntField(clazz, j_fid, age);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_callAddMethod(JNIEnv *env, jobject clazz) {
    //自己得到jclass
    jclass jclazz = env->GetObjectClass(clazz);
    jmethodID jmethodId = env->GetMethodID(jclazz, "add", "(II)I");
    jint sun = env->CallIntMethod(clazz, jmethodId, 2, 3);
    LOGE("Add%d", sun);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_getTest(JNIEnv *env, jobject thiz) {
    jclass  jclass1 =env->GetObjectClass(thiz);
    jfieldID  jfieldId = env->GetFieldID(jclass1,"TEST", "Ljava/lang/String;");
    jstring str = static_cast<jstring>(env->GetObjectField(thiz, jfieldId));
    const char* val =  env->GetStringUTFChars(str,NULL);
    LOGE("TST:%s",val);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_setTest(JNIEnv *env, jobject thiz) {
    jclass  jclass1 = env->GetObjectClass(thiz);
    jfieldID  jfieldId = env->GetFieldID(jclass1,"TEST", "Ljava/lang/String;");
    jstring  js = env->NewStringUTF("金莲说");
    env->SetObjectField(thiz,jfieldId,js);
}