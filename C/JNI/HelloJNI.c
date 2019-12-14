/*
 * In The Name Of God
 * ========================================
 * [] File Name : HelloJNI.c
 *
 * [] Creation Date : 11-04-2015
 *
 * [] Last Modified : Sun 12 Apr 2015 01:06:32 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include "HelloJNI.h"
#include <jni.h>
#include <stdio.h>

/*
 * Implementation of native method sayHello() of HelloJNI class
 */
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject obj,
                                              jint number, jintArray array) {
  printf("Hello Number %d !! You have %d item in your array\n", number,
         (*env)->GetArrayLength(env, array));
  return;
}
