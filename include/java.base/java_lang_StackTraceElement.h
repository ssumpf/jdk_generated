/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_StackTraceElement */

#ifndef _Included_java_lang_StackTraceElement
#define _Included_java_lang_StackTraceElement
#ifdef __cplusplus
extern "C" {
#endif
#undef java_lang_StackTraceElement_BUILTIN_CLASS_LOADER
#define java_lang_StackTraceElement_BUILTIN_CLASS_LOADER 1L
#undef java_lang_StackTraceElement_JDK_NON_UPGRADEABLE_MODULE
#define java_lang_StackTraceElement_JDK_NON_UPGRADEABLE_MODULE 2L
#undef java_lang_StackTraceElement_serialVersionUID
#define java_lang_StackTraceElement_serialVersionUID 6992337162326171013LL
/*
 * Class:     java_lang_StackTraceElement
 * Method:    initStackTraceElements
 * Signature: ([Ljava/lang/StackTraceElement;Ljava/lang/Throwable;)V
 */
JNIEXPORT void JNICALL Java_java_lang_StackTraceElement_initStackTraceElements
  (JNIEnv *, jclass, jobjectArray, jthrowable);

/*
 * Class:     java_lang_StackTraceElement
 * Method:    initStackTraceElement
 * Signature: (Ljava/lang/StackTraceElement;Ljava/lang/StackFrameInfo;)V
 */
JNIEXPORT void JNICALL Java_java_lang_StackTraceElement_initStackTraceElement
  (JNIEnv *, jclass, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
