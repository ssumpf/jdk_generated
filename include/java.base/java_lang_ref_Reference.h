/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_ref_Reference */

#ifndef _Included_java_lang_ref_Reference
#define _Included_java_lang_ref_Reference
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     java_lang_ref_Reference
 * Method:    getAndClearReferencePendingList
 * Signature: ()Ljava/lang/ref/Reference;
 */
JNIEXPORT jobject JNICALL Java_java_lang_ref_Reference_getAndClearReferencePendingList
  (JNIEnv *, jclass);

/*
 * Class:     java_lang_ref_Reference
 * Method:    hasReferencePendingList
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_java_lang_ref_Reference_hasReferencePendingList
  (JNIEnv *, jclass);

/*
 * Class:     java_lang_ref_Reference
 * Method:    waitForReferencePendingList
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_java_lang_ref_Reference_waitForReferencePendingList
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
