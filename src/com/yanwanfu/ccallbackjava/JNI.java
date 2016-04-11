package com.yanwanfu.ccallbackjava;

import android.content.Context;
import android.widget.Toast;

public class JNI {

	/** 切记要加static方法 */
	static {
		System.loadLibrary("callback");
	}

	/** 弹 Toast用的Context */
	private Context mContext;

	public JNI(Context context) {
		mContext = context;
	}

	/** 回调java void类型方法 */
	public native void callbackvoidmethod();

	/** 回调java int类型方法 */
	public native void callbackintmethod();

	/** 回调java String类型方法 */
	public native void callbackstringmethod();

	/** 回调java Toast */
	public native void callbackShowToast();

	/** java void类型方法 */
	public void helloFromJava() {

		System.out.println("Hello from java");
	}

	/** java int类型方法 */
	public int add(int x, int y) {

		return x + y;
	}

	/** java String类型方法 */
	public void printString(String s) {
		System.out.println(s);
	}

	/** MainActivity 弹出Toast */
	public void showToast(String s) {
		Toast.makeText(mContext, s, 0).show();
	}
}
