/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class sun_management_ThreadImpl */

#ifndef _Included_sun_management_ThreadImpl
#define _Included_sun_management_ThreadImpl
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     sun_management_ThreadImpl
 * Method:    getThreads
 * Signature: ()[Ljava/lang/Thread;
 */
JNIEXPORT jobjectArray JNICALL Java_sun_management_ThreadImpl_getThreads
  (JNIEnv *, jclass);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    getThreadInfo1
 * Signature: ([JI[Ljava/lang/management/ThreadInfo;)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_getThreadInfo1
  (JNIEnv *, jclass, jlongArray, jint, jobjectArray);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    getThreadTotalCpuTime0
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_sun_management_ThreadImpl_getThreadTotalCpuTime0
  (JNIEnv *, jclass, jlong);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    getThreadTotalCpuTime1
 * Signature: ([J[J)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_getThreadTotalCpuTime1
  (JNIEnv *, jclass, jlongArray, jlongArray);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    getThreadUserCpuTime0
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_sun_management_ThreadImpl_getThreadUserCpuTime0
  (JNIEnv *, jclass, jlong);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    getThreadUserCpuTime1
 * Signature: ([J[J)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_getThreadUserCpuTime1
  (JNIEnv *, jclass, jlongArray, jlongArray);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    getThreadAllocatedMemory1
 * Signature: ([J[J)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_getThreadAllocatedMemory1
  (JNIEnv *, jclass, jlongArray, jlongArray);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    setThreadCpuTimeEnabled0
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_setThreadCpuTimeEnabled0
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    setThreadAllocatedMemoryEnabled0
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_setThreadAllocatedMemoryEnabled0
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    setThreadContentionMonitoringEnabled0
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_setThreadContentionMonitoringEnabled0
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    findMonitorDeadlockedThreads0
 * Signature: ()[Ljava/lang/Thread;
 */
JNIEXPORT jobjectArray JNICALL Java_sun_management_ThreadImpl_findMonitorDeadlockedThreads0
  (JNIEnv *, jclass);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    findDeadlockedThreads0
 * Signature: ()[Ljava/lang/Thread;
 */
JNIEXPORT jobjectArray JNICALL Java_sun_management_ThreadImpl_findDeadlockedThreads0
  (JNIEnv *, jclass);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    resetPeakThreadCount0
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_resetPeakThreadCount0
  (JNIEnv *, jclass);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    dumpThreads0
 * Signature: ([JZZ)[Ljava/lang/management/ThreadInfo;
 */
JNIEXPORT jobjectArray JNICALL Java_sun_management_ThreadImpl_dumpThreads0
  (JNIEnv *, jclass, jlongArray, jboolean, jboolean);

/*
 * Class:     sun_management_ThreadImpl
 * Method:    resetContentionTimes0
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_sun_management_ThreadImpl_resetContentionTimes0
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
