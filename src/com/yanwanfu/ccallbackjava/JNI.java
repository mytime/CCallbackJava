package com.yanwanfu.ccallbackjava;

import android.content.Context;
import android.widget.Toast;

public class JNI {

	/** �м�Ҫ��static���� */
	static {
		System.loadLibrary("callback");
	}

	/** �� Toast�õ�Context */
	private Context mContext;

	public JNI(Context context) {
		mContext = context;
	}

	/** �ص�java void���ͷ��� */
	public native void callbackvoidmethod();

	/** �ص�java int���ͷ��� */
	public native void callbackintmethod();

	/** �ص�java String���ͷ��� */
	public native void callbackstringmethod();

	/** �ص�java Toast */
	public native void callbackShowToast();

	/** java void���ͷ��� */
	public void helloFromJava() {

		System.out.println("Hello from java");
	}

	/** java int���ͷ��� */
	public int add(int x, int y) {

		return x + y;
	}

	/** java String���ͷ��� */
	public void printString(String s) {
		System.out.println(s);
	}

	/** MainActivity ����Toast */
	public void showToast(String s) {
		Toast.makeText(mContext, s, 0).show();
	}
}
