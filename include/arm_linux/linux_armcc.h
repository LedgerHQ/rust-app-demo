/*
 * linux_armcc.h
 * Interoperation with the GNU toolchain and libraries
 * 
 * Copyright (C) ARM Limited, 2007,2008. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

/* Linux/glibc and libstdc++ constants and builtins mappings */

#ifndef __LINUX_ARMCC_H
#define __LINUX_ARMCC_H
#define __ARMCLIB_VERSION 6090000

 /* Define names for equivalent functions*/
#define __align    __alignx
#define lrintf     _ffix_r

/* Include the appropriate armcc headers */
#include <limits_armcc.h>

/* Correct value of MB_LEN_MAX for Linux/glibc */
#undef MB_LEN_MAX
#define MB_LEN_MAX 16

#include <float.h>

/* Endianness macros */
#if !defined(__ARM_BIG_ENDIAN) && !defined(__BIG_ENDIAN)
#define __ARMEL__ 1
#else
#define __ARMEB__ 1
#endif

/* Target OS macros */
#define __linux 1
#define __linux__ 1
#define __unix__ 1
#define unix 1
#define __unix 1
#define linux 1

/* Indicate EABI compatibility */
#define __ARM_EABI__ 1

/* Define _GNU_SOURCE in C++ */
#ifdef __cplusplus
#define _GNU_SOURCE
#endif

/* Add the __CONSTANT__ names used in libstdc++ */
#define __CHAR_BIT__ CHAR_BIT
#define __SCHAR_MIN__ SCHAR_MIN
#define __SCHAR_MAX__ SCHAR_MAX
#define __UCHAR_MAX__ UCHAR_MAX
#define __CHAR_MIN__ CHAR_MIN
#define __CHAR_MAX__ CHAR_MAX
#define __MB_LEN_MAX__ MB_LEN_MAX
#define __SHRT_MIN__  SHRT_MIN
#define __SHRT_MAX__  SHRT_MAX
#define __USHRT_MAX__ USHRT_MAX
#define __INT_MIN__   INT_MIN
#define __INT_MAX__   INT_MAX
#define __UINT_MAX__  UINT_MAX
#define __LONG_MIN__  LONG_MIN
#define __LONG_MAX__  LONG_MAX
#define __ULONG_MAX__ ULONG_MAX
#if !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__)
  #define __LLONG_MIN__  LLONG_MIN
  #define __LLONG_MAX__    LLONG_MAX
  #define __ULLONG_MAX__   ULLONG_MAX
#endif

/* __CONSTANT__ names for float.h */

#define __FLT_RADIX__     FLT_RADIX
#define __FLT_ROUNDS__    FLT_ROUNDS
#define __FLT_MANT_DIG__        FLT_MANT_DIG
#define __DBL_MANT_DIG__        DBL_MANT_DIG
#define __LDBL_MANT_DIG__       LDBL_MANT_DIG
    /* number of base-FLT_RADIX digits in the floating point mantissa */
#if !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__)
#define __DECIMAL_DIG__ DECIMAL_DIG
    /* number of decimal digits that the widest floating point type
       can be rounded to and back again without changing the value */
#endif
#define __FLT_DIG__      FLT_DIG
#define __DBL_DIG__      DBL_DIG
#define __LDBL_DIG__     LDBL_DIG
    /* number of decimal digits of precision */

#define __FLT_MIN_EXP__  FLT_MIN_EXP
#define __DBL_MIN_EXP__  DBL_MIN_EXP
#define __LDBL_MIN_EXP__ LDBL_MIN_EXP
    /* minimum negative integer such that FLT_RADIX raised to that power */
    /* minus 1 is a normalised floating-point number. */

#define __FLT_MIN_10_EXP__  FLT_MIN_10_EXP
#define __DBL_MIN_10_EXP__  DBL_MIN_10_EXP
#define __LDBL_MIN_10_EXP__ LDBL_MIN_10_EXP
    /* minimum negative integer such that 10 raised to that power is in the */
    /* range of normalised floating-point numbers. */

#define __FLT_MAX_EXP__  FLT_MAX_EXP
#define __DBL_MAX_EXP__  DBL_MAX_EXP
#define __LDBL_MAX_EXP__ LDBL_MAX_EXP
    /* maximum integer such that FLT_RADIX raised to that power minus 1 is a */
#define __FLT_MAX_10_EXP__  FLT_MAX_10_EXP
#define __DBL_MAX_10_EXP__  DBL_MAX_10_EXP
#define __LDBL_MAX_10_EXP__ LDBL_MAX_10_EXP
    /* maximum integer such that 10 raised to that power is in the range of */
    /* representable finite floating-point numbers. */

#define __FLT_MAX__  FLT_MAX
#define __DBL_MAX__  DBL_MAX
#define __LDBL_MAX__ LDBL_MAX
    /* maximum representable finite floating-point number */

#define __FLT_EPSILON__         FLT_EPSILON
#define __DBL_EPSILON__         DBL_EPSILON
#define __LDBL_EPSILON__        LDBL_EPSILON

#define __FLT_MIN__  FLT_MIN
#define __DBL_MIN__  DBL_MIN
#define __LDBL_MIN__ LDBL_MIN

/* Some alternative names for the long long limits */
#define __LONG_LONG_MIN__ __LLONG_MIN__
#define __LONG_LONG_MAX__ __LLONG_MAX__
#define __ULONG_LONG_MAX__ __ULLONG_MAX__

/* Extra floating point defines */
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_DENORM_MIN__ __FLT_MIN__
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __DBL_DENORM_MIN__ __DBL_MIN__
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_DENORM_MIN__ __LDBL_MIN__

#endif /* __LINUX_ARMCC_H */

/* end of linux_armcc.h */

