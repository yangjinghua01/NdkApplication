package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.myapplication.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("native-lib");
    }
    static final int A =100;
    public native String getString();
    public static native String getString2();
    public String name = "YJH"; //签名 Ljava/lang/String
    public static int age = 23; //签名 I
    public static native void changage();
//    public static native void callAddMethod();
    public  native void callAddMethod();
    //给native调用
    public int add(int number,int number2){
        return number+number2;
    }

    //--------------------------
    public native void changName();
    private TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.sample_text);
        changName();
        textView.setText(name);
        changage();
        textView.setText(age+"");
        callAddMethod();
    }

}
/**
 * 签名规则 大写
 * java的boolean
 *
 * java的boolean  ---Z
 *
 * java的byte  ----B
 *
 * java的char  -----C
 *
 * java的short ------S
 *
 * java的int --------I
 *
 * java的Long ------J
 *
 * java的float   -----F
 *
 * java的double   ------D
 *
 * java的void ------V
 *
 * java的(引用类型)Objcet  -----L包名/xxxx/xxxx/类名;
 *
 * java的String    -----L包名/xxxx/xxxx/类名;
 *
 * java的array(数组)   int[]  ------[I] double [][][] -----[[[D
 *
 * java命令 java -s -p xxx.class -s 输出xxxx。class的所有属性和方法的签名  -p忽略私有公开的属性方法全部输出
 *
 *
 *
 * */