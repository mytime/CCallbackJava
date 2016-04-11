#include <jni.h>
#include <stdlib.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

/**
 * callbackvoidmethod()本地方法的实现
 * */JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackvoidmethod(
		JNIEnv * env, jobject clazz) {

	/**
	 * 1 获取字节码对象,注意类的路径用
	 * jclass      (*FindClass)(JNIEnv*, const char*);
	 * com/yanwanfu/ccallbackjava/JNI ： 类的路径
	 *  */
	jclass claz = (*env)->FindClass(env, "com/yanwanfu/ccallbackjava/JNI");

	/**2 获取Method对象
	 * jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
	 * env：JNI 环境
	 * claz：字节码对象
	 * helloFromJava：java方法
	 * ()V： helloFromJava方法的签名，()无参数,V 空类型， （获取签名 bin/ javap -s 类的路径）
	 * */
	jmethodID methodID = (*env)->GetMethodID(env, claz, "helloFromJava", "()V");

	/**3 通过字节码对象创建一个object*/
	// 参数clazz 就是要常见的object
	/**4 通过对象调用方法
	 * env			：JNI环境
	 * clazz		：Object
	 * methodID		: 执行的方法（helloFromJava）
	 * */
	(*env)->CallVoidMethod(env, clazz, methodID);

}

/**
 * callbackintmethod()本地方法的实现
 */JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackintmethod(
		JNIEnv * env, jobject clazz) {
	jclass claz = (*env)->FindClass(env, "com/yanwanfu/ccallbackjava/JNI");
	//(II)I ：add()方法的签名，两个int参数，返回int类型
	jmethodID methodID = (*env)->GetMethodID(env, claz, "add", "(II)I");
	int result = (*env)->CallIntMethod(env, clazz, methodID, 3, 4);
	LOGD("result=%d", result);

}

/**
 * callbackstringmethod()本地方法的实现
 */JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackstringmethod(
		JNIEnv * env, jobject clazz) {
	//JNI 字节码对象
	jclass claz = (*env)->FindClass(env, "com/yanwanfu/ccallbackjava/JNI");
	jmethodID methodID = (*env)->GetMethodID(env, claz, "printString",
			"(Ljava/lang/String;)V");
	jstring result = (*env)->NewStringUTF(env, "Hello from C");
	(*env)->CallVoidMethod(env, clazz, methodID, result);
}

JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackShowToast(
		JNIEnv * env, jobject clazz) {
	//1   获取MainActivity字节码对象
	//jclass      (*FindClass)(JNIEnv*, const char*);
	jclass claz = (*env)->FindClass(env,
			"com/yanwanfu/ccallbackjava/JNI");

	//2  获取Method对象
	// jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
	jmethodID methodID = (*env)->GetMethodID(env, claz, "showToast",
			"(Ljava/lang/String;)V");

	//3  通过字节码对象创建一个object
	//jobject     (*AllocObject)(JNIEnv*, jclass);

	//4  通过对象调用方法
	//  void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	jstring result = (*env)->NewStringUTF(env, "Hello from C");
	(*env)->CallVoidMethod(env, clazz, methodID, result);

}

