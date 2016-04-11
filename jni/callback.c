#include <jni.h>
#include <stdlib.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

/**
 * callbackvoidmethod()���ط�����ʵ��
 * */JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackvoidmethod(
		JNIEnv * env, jobject clazz) {

	/**
	 * 1 ��ȡ�ֽ������,ע�����·����
	 * jclass      (*FindClass)(JNIEnv*, const char*);
	 * com/yanwanfu/ccallbackjava/JNI �� ���·��
	 *  */
	jclass claz = (*env)->FindClass(env, "com/yanwanfu/ccallbackjava/JNI");

	/**2 ��ȡMethod����
	 * jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
	 * env��JNI ����
	 * claz���ֽ������
	 * helloFromJava��java����
	 * ()V�� helloFromJava������ǩ����()�޲���,V �����ͣ� ����ȡǩ�� bin/ javap -s ���·����
	 * */
	jmethodID methodID = (*env)->GetMethodID(env, claz, "helloFromJava", "()V");

	/**3 ͨ���ֽ�����󴴽�һ��object*/
	// ����clazz ����Ҫ������object
	/**4 ͨ��������÷���
	 * env			��JNI����
	 * clazz		��Object
	 * methodID		: ִ�еķ�����helloFromJava��
	 * */
	(*env)->CallVoidMethod(env, clazz, methodID);

}

/**
 * callbackintmethod()���ط�����ʵ��
 */JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackintmethod(
		JNIEnv * env, jobject clazz) {
	jclass claz = (*env)->FindClass(env, "com/yanwanfu/ccallbackjava/JNI");
	//(II)I ��add()������ǩ��������int����������int����
	jmethodID methodID = (*env)->GetMethodID(env, claz, "add", "(II)I");
	int result = (*env)->CallIntMethod(env, clazz, methodID, 3, 4);
	LOGD("result=%d", result);

}

/**
 * callbackstringmethod()���ط�����ʵ��
 */JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackstringmethod(
		JNIEnv * env, jobject clazz) {
	//JNI �ֽ������
	jclass claz = (*env)->FindClass(env, "com/yanwanfu/ccallbackjava/JNI");
	jmethodID methodID = (*env)->GetMethodID(env, claz, "printString",
			"(Ljava/lang/String;)V");
	jstring result = (*env)->NewStringUTF(env, "Hello from C");
	(*env)->CallVoidMethod(env, clazz, methodID, result);
}

JNIEXPORT void JNICALL Java_com_yanwanfu_ccallbackjava_JNI_callbackShowToast(
		JNIEnv * env, jobject clazz) {
	//1   ��ȡMainActivity�ֽ������
	//jclass      (*FindClass)(JNIEnv*, const char*);
	jclass claz = (*env)->FindClass(env,
			"com/yanwanfu/ccallbackjava/JNI");

	//2  ��ȡMethod����
	// jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
	jmethodID methodID = (*env)->GetMethodID(env, claz, "showToast",
			"(Ljava/lang/String;)V");

	//3  ͨ���ֽ�����󴴽�һ��object
	//jobject     (*AllocObject)(JNIEnv*, jclass);

	//4  ͨ��������÷���
	//  void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	jstring result = (*env)->NewStringUTF(env, "Hello from C");
	(*env)->CallVoidMethod(env, clazz, methodID, result);

}

