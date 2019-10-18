/* limits.h: ANSI 'C' (X3J11 Oct 88) library header, section 2.2.4.2 */
/* Copyright (C) Codemist Ltd., 1988                            */
/* Copyright 1991-1997 ARM Limited. All rights reserved         */

/*
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author: drodgman $
 */

#ifndef __limits_h
#define __limits_h
#define __ARMCLIB_VERSION 6090000

#define CHAR_BIT 8
    /* max number of bits for smallest object that is not a bit-field (byte) */
#define SCHAR_MIN (-128)
    /* mimimum value for an object of type signed char */
#define SCHAR_MAX 127
    /* maximum value for an object of type signed char */
#define UCHAR_MAX 255
    /* maximum value for an object of type unsigned char */
#ifdef __FEATURE_SIGNED_CHAR
  #define CHAR_MIN (-128)
      /* minimum value for an object of type char */
  #define CHAR_MAX 127
      /* maximum value for an object of type char */
#else
  #define CHAR_MIN 0
      /* minimum value for an object of type char */
  #define CHAR_MAX 255
      /* maximum value for an object of type char */
#endif

#if _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
  #define _AEABI_PORTABLE
#endif

#if _AEABI_PORTABILITY_LEVEL != 0 || (!defined _AEABI_PORTABILITY_LEVEL && __DEFAULT_AEABI_PORTABILITY_LEVEL != 0)
extern const int __aeabi_MB_LEN_MAX;
#define MB_LEN_MAX (__aeabi_MB_LEN_MAX)
#else
#define MB_LEN_MAX 6
#endif
    /* maximum number of bytes in a multibyte character, */
    /* for any supported locale */

#define SHRT_MIN  (-0x8000)
    /* minimum value for an object of type short int */
#define SHRT_MAX  0x7fff
    /* maximum value for an object of type short int */
#define USHRT_MAX 65535
    /* maximum value for an object of type unsigned short int */
#define INT_MIN   (~0x7fffffff)  /* -2147483648 and 0x80000000 are unsigned */
    /* minimum value for an object of type int */
#define INT_MAX   0x7fffffff
    /* maximum value for an object of type int */
#define UINT_MAX  0xffffffffU
    /* maximum value for an object of type unsigned int */
#if __sizeof_long == 8
  #define LONG_MIN  (~0x7fffffffffffffffL)
#else
  #define LONG_MIN  (~0x7fffffffL)
#endif
    /* minimum value for an object of type long int */
#if __sizeof_long == 8
  #define LONG_MAX  0x7fffffffffffffffL
#else
  #define LONG_MAX  0x7fffffffL
#endif
    /* maximum value for an object of type long int */
#if __sizeof_long == 8
  #define ULONG_MAX 0xffffffffffffffffUL
#else
  #define ULONG_MAX 0xffffffffUL
#endif
    /* maximum value for an object of type unsigned long int */
#if !defined(__STRICT_ANSI__) || defined(__USE_C99_ALL) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
  #define LLONG_MIN  (~0x7fffffffffffffffLL)
      /* minimum value for an object of type long long int */
  #define LLONG_MAX    0x7fffffffffffffffLL
      /* maximum value for an object of type long long int */
  #define ULLONG_MAX   0xffffffffffffffffULL
      /* maximum value for an object of type unsigned long int */
#endif

#endif

/* end of limits.h */

