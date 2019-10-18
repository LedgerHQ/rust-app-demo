// -*- C++ -*-
//===----------------------------------------------------------------------===//
// Copyright 2016 ARM Limited. All rights reserved
//===----------------------------------------------------------------------===//

#ifndef ARM_TPL_H
#define ARM_TPL_H

#include <stdint.h>
#include <time.h>

#define _ARMTPL_THREAD_ABI_VISIBILITY __attribute__ ((__visibility__("default")))

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    time_t tv_sec;
    unsigned long tv_nsec;
} timespec;

// Clocks
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_clock_realtime(timespec* __ts);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_clock_monotonic(timespec* __ts);

// Mutexes
typedef struct {
    _Atomic uintptr_t data;
} __ARM_TPL_mutex_t;

#define _ARMCPP_MUTEX_INITIALIZER {(uintptr_t) 0}

_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_recursive_mutex_init(__ARM_TPL_mutex_t* __m);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_mutex_lock(__ARM_TPL_mutex_t* __m);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_mutex_trylock(__ARM_TPL_mutex_t* __m);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_mutex_unlock(__ARM_TPL_mutex_t* __m);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_mutex_destroy(__ARM_TPL_mutex_t* __m);

// Condition variables
typedef struct {
    _Atomic uintptr_t data;
} __ARM_TPL_condvar_t;

#define _ARMCPP_CONDVAR_INITIALIZER {(uintptr_t) 0}

_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_condvar_signal(__ARM_TPL_condvar_t* __cv);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_condvar_broadcast(__ARM_TPL_condvar_t* __cv);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_condvar_wait(__ARM_TPL_condvar_t* __cv, __ARM_TPL_mutex_t* __m);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_condvar_timedwait(__ARM_TPL_condvar_t* __cv,
                                __ARM_TPL_mutex_t* __m,
                                timespec* __ts);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_condvar_destroy(__ARM_TPL_condvar_t* __cv);

// Thread ids
typedef uint32_t __ARM_TPL_thread_id;

_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_thread_id_compare(__ARM_TPL_thread_id __tid1,
                                __ARM_TPL_thread_id __tid2);

// Threads
typedef struct {
    uintptr_t data;
} __ARM_TPL_thread_t;

#define _ARMCPP_NULL_THREAD {0}

_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_thread_create(__ARM_TPL_thread_t* __t,
                            void* (*__func)(void*),
                            void* __arg);
_ARMTPL_THREAD_ABI_VISIBILITY
__ARM_TPL_thread_id __ARM_TPL_thread_get_current_id();
_ARMTPL_THREAD_ABI_VISIBILITY
__ARM_TPL_thread_id __ARM_TPL_thread_get_id(const __ARM_TPL_thread_t* __t);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_thread_join(__ARM_TPL_thread_t* __t);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_thread_detach(__ARM_TPL_thread_t* __t);
_ARMTPL_THREAD_ABI_VISIBILITY
void __ARM_TPL_thread_yield();
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_thread_nanosleep(const timespec *req, timespec *rem);
_ARMTPL_THREAD_ABI_VISIBILITY
unsigned __ARM_TPL_thread_hw_concurrency();

// Execute once
typedef volatile unsigned long __ARM_TPL_exec_once_flag;
#define _ARMCPP_EXEC_ONCE_INITIALIZER {0}

_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_execute_once(__ARM_TPL_exec_once_flag *__flag,
                          void (*__init_routine)(void));

// Thread local storage
typedef uint32_t __ARM_TPL_tls_key;

_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_tls_create(__ARM_TPL_tls_key* __key, void (*__at_exit)(void*));
_ARMTPL_THREAD_ABI_VISIBILITY
void* __ARM_TPL_tls_get(__ARM_TPL_tls_key __key);
_ARMTPL_THREAD_ABI_VISIBILITY
int __ARM_TPL_tls_set(__ARM_TPL_tls_key __key, void* __p);

#ifdef __cplusplus
} // extern "C"
#endif

#undef _ARMTPL_THREAD_ABI_VISIBILITY

#if defined(_ARMTPL_BUILD_DUMMY_THREADS)

/* A dummy implementation of the threading API - used for testing */

#include <stdlib.h>
#include <stdio.h>

#define _ARMTPL_ABORT(MSG) \
    fprintf(stderr, "Error: %s", MSG); \
    abort();

#define _ARMTPL_WEAK __attribute__((__weak__))
#define _ARMTPL_UNUSED(x) x __attribute__((unused))

_ARMTPL_WEAK
int __ARM_TPL_clock_realtime(timespec* _ARMTPL_UNUSED(__ts)) {
    _ARMTPL_ABORT("__ARM_TPL_clock_realtime() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_clock_monotonic(timespec* _ARMTPL_UNUSED(__ts)) {
    _ARMTPL_ABORT("__ARM_TPL_clock_monotonic() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_recursive_mutex_init(__ARM_TPL_mutex_t* _ARMTPL_UNUSED(__m)) {
    _ARMTPL_ABORT("__ARM_TPL_recursive_mutex_init() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_mutex_lock(__ARM_TPL_mutex_t* _ARMTPL_UNUSED(__m)) {
    _ARMTPL_ABORT("__ARM_TPL_mutex_lock() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_mutex_trylock(__ARM_TPL_mutex_t* _ARMTPL_UNUSED(__m)) {
    _ARMTPL_ABORT("__ARM_TPL_mutex_trylock() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_mutex_unlock(__ARM_TPL_mutex_t* _ARMTPL_UNUSED(__m)) {
    _ARMTPL_ABORT("__ARM_TPL_mutex_unlock() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_mutex_destroy(__ARM_TPL_mutex_t* _ARMTPL_UNUSED(__m)) {
    _ARMTPL_ABORT("__ARM_TPL_mutex_destroy() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_condvar_signal(__ARM_TPL_condvar_t* _ARMTPL_UNUSED(__cv)) {
    _ARMTPL_ABORT("__ARM_TPL_condvar_signal() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_condvar_broadcast(__ARM_TPL_condvar_t* _ARMTPL_UNUSED(__cv)) {
    _ARMTPL_ABORT("__ARM_TPL_condvar_broadcast() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_condvar_wait(__ARM_TPL_condvar_t* _ARMTPL_UNUSED(__cv),
                           __ARM_TPL_mutex_t* _ARMTPL_UNUSED(__m)) {
    _ARMTPL_ABORT("__ARM_TPL_condvar_wait() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_condvar_timedwait(__ARM_TPL_condvar_t* _ARMTPL_UNUSED(__cv),
                                __ARM_TPL_mutex_t* _ARMTPL_UNUSED(__m),
                                timespec* _ARMTPL_UNUSED(__ts)) {
    _ARMTPL_ABORT("__ARM_TPL_condvar_timedwait() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_condvar_destroy(__ARM_TPL_condvar_t* _ARMTPL_UNUSED(__cv)) {
    _ARMTPL_ABORT("__ARM_TPL_condvar_destroy() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_thread_id_compare(__ARM_TPL_thread_id _ARMTPL_UNUSED(__tid1),
                                 __ARM_TPL_thread_id _ARMTPL_UNUSED(__tid2)) {
    _ARMTPL_ABORT("__ARM_TPL_thread_id_compare() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_thread_create(__ARM_TPL_thread_t* _ARMTPL_UNUSED(__t),
                            void* _ARMTPL_UNUSED((*__func)(void*)),
                            void* _ARMTPL_UNUSED(__arg)) {
    _ARMTPL_ABORT("__ARM_TPL_thread_create() is not implemented.");
}
_ARMTPL_WEAK
__ARM_TPL_thread_id __ARM_TPL_thread_get_current_id() {
    _ARMTPL_ABORT("__ARM_TPL_thread_get_current_id() is not implemented.");
}
_ARMTPL_WEAK
__ARM_TPL_thread_id __ARM_TPL_thread_get_id(
                    const __ARM_TPL_thread_t* _ARMTPL_UNUSED(__t)) {
    _ARMTPL_ABORT("__ARM_TPL_thread_get_id() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_thread_join(__ARM_TPL_thread_t* _ARMTPL_UNUSED(__t)) {
    _ARMTPL_ABORT("__ARM_TPL_thread_join() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_thread_detach(__ARM_TPL_thread_t* _ARMTPL_UNUSED(__t)) {
    _ARMTPL_ABORT("__ARM_TPL_thread_detach() is not implemented.");
}
_ARMTPL_WEAK
void __ARM_TPL_thread_yield() {
    _ARMTPL_ABORT("__ARM_TPL_thread_yield() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_thread_nanosleep(const timespec * _ARMTPL_UNUSED(__req),
                               timespec * _ARMTPL_UNUSED(__rem)) {
    _ARMTPL_ABORT("__ARM_TPL_thread_nanosleep() is not implemented.");
}
_ARMTPL_WEAK
unsigned __ARM_TPL_thread_hw_concurrency() {
    _ARMTPL_ABORT("__ARM_TPL_thread_hw_concurrency() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_execute_once(__ARM_TPL_exec_once_flag * _ARMTPL_UNUSED(__flag),
                          void _ARMTPL_UNUSED((*__init_routine)(void))) {
    _ARMTPL_ABORT("__ARM_TPL_execute_once() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_tls_create(__ARM_TPL_tls_key* _ARMTPL_UNUSED(__key),
                         void _ARMTPL_UNUSED((*__at_exit)(void*))) {
    _ARMTPL_ABORT("__ARM_TPL_tls_create() is not implemented.");
}
_ARMTPL_WEAK
void* __ARM_TPL_tls_get(__ARM_TPL_tls_key _ARMTPL_UNUSED(__key)) {
    _ARMTPL_ABORT("__ARM_TPL_tls_get() is not implemented.");
}
_ARMTPL_WEAK
int __ARM_TPL_tls_set(__ARM_TPL_tls_key _ARMTPL_UNUSED(__key), void* _ARMTPL_UNUSED(__p)) {
    _ARMTPL_ABORT("__ARM_TPL_tls_set() is not implemented.");
}

#undef _ARMTPL_ABORT
#undef _ARMTPL_WEAK
#undef _ARMTPL_UNUSED

#endif // _ARMTPL_BUILD_DUMMY_THREADS

#endif // ARM_TPL_H
