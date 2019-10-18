/* uchar.h: C11 header */
/* Copyright 2015 ARM Limited. All rights reserved.            */
/*
 * $Revision$
 * $Date$
 * $Author$
 * $Id$
 * $URL$
 */

#ifndef __uchar_h
#define __uchar_h
#define __ARMCLIB_VERSION 6090000


#undef __CLIBNS
#ifdef __cplusplus
  #define __CLIBNS ::std::
  namespace std {
    extern "C" {
#else /* ndef __cplusplus */
  #define __CLIBNS
#endif /* ndef __cplusplus */

    /* wchar_t type */
    #ifndef __cplusplus  /* wchar_t is a builtin type for C++ */
      #if !defined(__STRICT_ANSI__) || !defined(__wchar_t)
       /* always defined in non-strict C for consistency of debug info */
        #if defined(__WCHAR32) || (defined(__ARM_SIZEOF_WCHAR_T) && __ARM_SIZEOF_WCHAR_T == 4)
          typedef unsigned int wchar_t; /* see <stddef.h> */
        #else
          typedef unsigned short wchar_t; /* see <stddef.h> */
        #endif
        #ifdef __STRICT_ANSI__
          #define __wchar_t 1
        #endif
      #endif
    #endif

    #if defined(__cplusplus) || !defined(__STRICT_ANSI__)
      /* unconditional in C++ and non-strict C for consistency of debug info */
      #if __sizeof_ptr == 8
        typedef unsigned long size_t;   /* see <stddef.h> */
      #else
        typedef unsigned int size_t;   /* see <stddef.h> */
      #endif
    #elif !defined(__size_t)
      #define __size_t 1
      #if __sizeof_ptr == 8
        typedef unsigned long size_t;   /* see <stddef.h> */
      #else
        typedef unsigned int size_t;   /* see <stddef.h> */
      #endif
      /* the unsigned integral type of the result of the sizeof operator. */
    #endif

    /* mbstate_t type */
    #if !defined(__mbstate_t_defined)
      typedef struct __mbstate_t {
          unsigned int __state, __state2;
      } mbstate_t;
      #define __mbstate_t_defined 1
    #endif

    /* New C11/C++11 features only defined in C11, C++11 and non-strict modes */
    #if !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && 201103L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)

      /* char16_t and char32_t types */
      #if !defined(__cplusplus) || (201103L > __cplusplus) /* these are builtin types for C++11 */
        typedef unsigned short char16_t;
        typedef unsigned int   char32_t;
      #endif

      /* uchar <-> multi-byte conversion functions */
        size_t mbrtoc16(char16_t *__restrict /*pc16*/,
                        const char *__restrict /*s*/, size_t /*n*/,
                        mbstate_t *__restrict /*ps*/);
        size_t mbrtoc32(char32_t *__restrict /*pc32*/,
                        const char *__restrict /*s*/, size_t /*n*/,
                        mbstate_t *__restrict /*ps*/);
        size_t c16rtomb(char *__restrict /*s*/, char16_t /*c16*/,
                        mbstate_t *__restrict /*ps*/);
        size_t c32rtomb(char *__restrict /*s*/, char32_t /*c32*/,
                        mbstate_t *__restrict /*ps*/);

    #endif

#ifdef __cplusplus
     }  /* extern "C" */
  }  /* namespace std */
#endif /* __cplusplus */

#if defined(__cplusplus)
  #ifndef __UCHAR_NO_EXPORTS
    #if (201103L > __cplusplus) && !defined(__STRICT_ANSI__)
      /* These are builtin types for C++11 */
      using ::std::char16_t;
      using ::std::char32_t;
    #endif
    using ::std::size_t;
    using ::std::mbstate_t;
    #if !defined(__STRICT_ANSI__) || (defined(__cplusplus) && 201103L <= __cplusplus)
      using ::std::mbrtoc16;
      using ::std::mbrtoc32;
      using ::std::c16rtomb;
      using ::std::c32rtomb;
    #endif
  #endif
#endif

#endif /* ndef __uchar_h */
/* end of wchar.h */
