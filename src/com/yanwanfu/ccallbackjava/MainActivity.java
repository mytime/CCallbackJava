package com.yanwanfu.ccallbackjava;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {

	private JNI jni;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
//		jni = new JNI();
		//getApplicationContext() µ¯ToastÓÃµÄContext
		jni = new JNI(getApplicationContext());
	}

	public void callbackvoid(View v) {

		jni.callbackvoidmethod();
	}

	public void callbackint(View v) {
		jni.callbackintmethod();
	}

	public void callbackstring(View v) {
		jni.callbackstringmethod();
	}
	
	public void callbackshowtoast(View v){
		jni.callbackShowToast();
	}

	
}
