/*
 * In The Name Of God
 * ========================================
 * [] File Name : HelloJNI.c
 *
 * [] Creation Date : 11-04-2015
 *
 * [] Last Modified : Sat 11 Apr 2015 01:13:40 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <jni.h>
#include <stdio.h>
#include "HelloJNI.h"

/*
 * Implementation of native method sayHello() of HelloJNI class
*/
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
	printf("Hello World!\n");
	return;
}
