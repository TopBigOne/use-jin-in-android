package com.ya.jnidynamicregister

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.ya.jnidynamicregister.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var nativeMethod: NativeMethod

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        nativeMethod = NativeMethod()
        setContentView(binding.root)

        initEvent()

    }

    private fun initEvent() {
        binding.getStringFromJni.setOnClickListener {
            binding.getStringFromJni.text = nativeMethod.getString()

        }
        binding.tvJniCallJava.setOnClickListener {
            nativeMethod.execJniCallJava()
        }

    }

    /**
     * call by jni
     */
    private fun startLoopTask(count: Int) {
        Log.d(TAG, "startLoopTask:  by jni invoke..... $count")
       // Toast.makeText(this, "by jni invoke", Toast.LENGTH_SHORT).show()
    }

    companion object {
        private const val TAG = "MainActivity : "

        // Used to load the 'jnidynamicregister' library on application startup.
        init {
            System.loadLibrary("jnidynamicregister")
        }
    }
}