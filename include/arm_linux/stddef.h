/* stddef.h: ANSI 'C' (X3J11 Oct 88) library header, section 4.1.4 */

/* Copyright (C) ARM Ltd., 1999
 * All rights reserved
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

/* Copyright (C) Codemist Ltd., 1988                            */
/* Copyright 1991 ARM Limited. All rights reserved.             */
/* version 0.05 */

/*
 * ARM Linux variant - includes glibc-compatible definition of wint_t
 */

/*
 * The following types and macros are defined in several headers referred to in
 * the descriptions of the functions declared in that header. They are also
 * defined in this header file.
 */

#ifndef __stddef_h
#define __stddef_h
#define __ARMCLIB_VERSION 6090000

  #ifndef __STDDEF_DECLS
  #define __STDDEF_DECLS
    #undef __CLIBNS
    #ifdef __cplusplus
        namespace std {
        #define __CLIBNS ::std::
        extern "C" {
    #else
      #define __CLIBNS
    #endif  /* __cplusplus */

#if __sizeof_ptr == 8
typedef signed long ptrdiff_t;
#else
typedef signed int ptrdiff_t;
#endif

#if defined(__cplusplus) || !defined(__STRICT_ANSI__)
 /* unconditional in C++ and non-strict C for consistency of debug info */
  #if __sizeof_ptr == 8
    typedef unsigned long size_t;
  #else
    typedef unsigned int size_t;
  #endif
#elif !defined(__size_t)
  #define __size_t 1
  #if __sizeof_ptr == 8
    typedef unsigned long size_t;
  #else
    typedef unsigned int size_t;   /* others (e.g. <stdio.h>) also define */
  #endif
   /* the unsigned integral type of the result of the sizeof operator. */
#endif

#ifndef __cplusplus  /* wchar_t is a builtin type for C++ */
  #if !defined(__STRICT_ANSI__)
  /* unconditional in non-strict C for consistency of debug info */
    #if defined(__WCHAR32) || (defined(__ARM_SIZEOF_WCHAR_T) && __ARM_SIZEOF_WCHAR_T == 4)
      typedef unsigned int wchar_t; /* also in <stdlib.h> and <inttypes.h> */
    #else
      typedef unsigned short wchar_t; /* also in <stdlib.h> and <inttypes.h> */
    #endif
  #elif !defined(__wchar_t)
    #define __wchar_t 1
    #if defined(__WCHAR32) || (defined(__ARM_SIZEOF_WCHAR_T) && __ARM_SIZEOF_WCHAR_T == 4)
      typedef unsigned int wchar_t; /* also in <stdlib.h> and <inttypes.h> */
    #else
      typedef unsigned short wchar_t; /* also in <stdlib.h> and <inttypes.h> */
    #endif
   /*
    * An integral type whose range of values can represent distinct codes for
    * all members of the largest extended character set specified among the
    * supported locales; the null character shall have the code value zero and
    * each member of the basic character set shall have a code value when used
    * as the lone character in an integer character constant.
    */
  #endif
#endif

#if !defined(__STRICT_ANSI__)
  /*
   * For Linux/GCC/glibc compatibility, define wint_t if requested or not
   * already defined
   */
  #if defined(__need_wint_t)
    #undef __need_wint_t
  #endif

  #if !defined(_WINT_T)
    #if !defined(__WINT_TYPE__)
      #define __WINT_TYPE__ unsigned int
    #endif
    typedef __WINT_TYPE__ wint_t;
    #define _WINT_T
    #define _STDDEF_DEFINED_WINT_T
  #endif
#endif

#undef NULL  /* others (e.g. <stdio.h>) also define */
#define NULL 0
   /* null pointer constant. */

  /* EDG uses __INTADDR__ to avoid errors when strict */
  #define offsetof(t, memb) ((__CLIBNS size_t)__INTADDR__(&(((t *)0)->memb)))

    #ifdef __cplusplus
         }  /* extern "C" */
      }  /* namespace std */
    #endif /* __cplusplus */
  #endif /* __STDDEF_DECLS */


  #ifdef __cplusplus
    #ifndef __STDDEF_NO_EXPORTS
      using ::std::size_t;
      using ::std::ptrdiff_t;
      #ifdef _STDDEF_DEFINED_WINT_T
        using ::std::wint_t;
        #undef _STDDEF_DEFINED_WINT_T
      #endif
    #endif 
  #endif /* __cplusplus */

#endif

/* end of stddef.h */

