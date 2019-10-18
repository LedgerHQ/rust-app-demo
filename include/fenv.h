/* fenv.h
 *
 * Copyright 1998 ARM Limited. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author: drodgman $
 */

#ifndef __fenv_h
#define __fenv_h
#define __ARMCLIB_VERSION 6090000

/*
 * Depending on compiler version __int64 or __INT64_TYPE__ should be defined.
 */
#ifndef __int64
  #ifdef __INT64_TYPE__
    #define __int64 __INT64_TYPE__
  #endif
  /* On some architectures neither of these may be defined - if so, fall
     through and error out if used. */
#endif

#ifndef _ARMABI
#  define _ARMABI __attribute__((nothrow))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Types.
 */

#if __ARMCOMPILER_VERSION < 6000000
#pragma push
#pragma anon_unions
#endif

typedef unsigned int __ieee_edata_t;     /* exception flags passed to traps */

typedef union {
    float __f;
    float __s;
    double __d;
    short __h;
    unsigned short __uh;
    int __i;
    unsigned int __ui;
    __int64 __l;
    unsigned __int64 __ul;

#ifndef __STRICT_ANSI__
#ifndef f
    float f;
#endif
#ifndef s
    float s;
#endif
#ifndef d
    double d;
#endif
#ifndef h
    int h;
#endif
#ifndef uh
    unsigned int uh;
#endif
#ifndef i
    int i;
#endif
#ifndef ui
    unsigned int ui;
#endif
#ifndef l
    long long l;
#endif
#ifndef ul
    unsigned long long ul;
#endif
#if !defined word1 && !defined word2 && !defined str
    struct { int word1, word2; } str;
#endif
#endif /* __STRICT_ANSI__ */
    struct { int __word1, __word2; } __str;
} __ieee_value_t;                        /* in/out values passed to traps */

#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))

typedef __attribute__((__pcs__("aapcs"))) __ieee_value_t (*__ieee_handler_t) (__ieee_value_t, __ieee_value_t,
                                                                          __ieee_edata_t);

#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

typedef struct {
#ifdef __STRICT_ANSI__
    unsigned __statusword;
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
    __ieee_handler_t __invalid_handler;
    __ieee_handler_t __divbyzero_handler;
    __ieee_handler_t __overflow_handler;
    __ieee_handler_t __underflow_handler;
    __ieee_handler_t __inexact_handler;
    /* does not include inputdenormal */
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */
#else
    union {
        unsigned __statusword;
#ifndef statusword
        unsigned statusword;
#endif
    };
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
    union {
        __ieee_handler_t __invalid_handler;
#ifndef invalid_handler
        __ieee_handler_t invalid_handler;
#endif
    };
    union {
        __ieee_handler_t __divbyzero_handler;
#ifndef divbyzero_handler
        __ieee_handler_t divbyzero_handler;
#endif
    };
    union {
        __ieee_handler_t __overflow_handler;
#ifndef overflow_handler
        __ieee_handler_t overflow_handler;
#endif
    };
    union {
        __ieee_handler_t __underflow_handler;
#ifndef underflow_handler
        __ieee_handler_t underflow_handler;
#endif
    };
    union {
        __ieee_handler_t __inexact_handler;
#ifndef inexact_handler
        __ieee_handler_t inexact_handler;
#endif
    };
    /* does not include inputdenormal */
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */
#endif
} fenv_t, fexcept_t;


#if __ARMCOMPILER_VERSION < 6000000
#pragma pop /* restore setting of anon_unions */
#endif

/*
 * Exception flags.
 */

#define FE_INVALID    (0x01)
#define FE_DIVBYZERO  (0x02)
#define FE_OVERFLOW   (0x04)
#define FE_UNDERFLOW  (0x08)
#define FE_INEXACT    (0x10)
#define FE_ALL_EXCEPT (0x1F)
/* does not include INPUTDENORMAL */

/*
 * Rounding modes.
 */

#define FE_TONEAREST  (0)
#define FE_UPWARD     (1)
#define FE_DOWNWARD   (2)
#define FE_TOWARDZERO (3)

/*
 * Default environment.
 */

extern const fenv_t __fpl_default_env;
#define FE_DFL_ENV    (&__fpl_default_env)

/*
 * Exception functions.
 */

extern _ARMABI int fegetexceptflag(fexcept_t *, int) __attribute__((__nonnull__(1)));
extern _ARMABI int fesetexceptflag(const fexcept_t *, int) __attribute__((__nonnull__(1)));

extern _ARMABI int feclearexcept(int);
extern _ARMABI int feraiseexcept(int);
extern _ARMABI int fetestexcept(int);

/*
 * Rounding functions.
 */

extern _ARMABI int fegetround(void);
extern _ARMABI int fesetround(int);

/*
 * Full environment access.
 */

extern _ARMABI int fegetenv(fenv_t *) __attribute__((__nonnull__(1)));
extern _ARMABI int fesetenv(const fenv_t *) __attribute__((__nonnull__(1)));

extern _ARMABI int feholdexcept(fenv_t *) __attribute__((__nonnull__(1)));
extern _ARMABI int feupdateenv(const fenv_t *) __attribute__((__nonnull__(1)));

/*
 * Implementation-specific: ARM's own optimal status word access
 * function, and the macros that go with it.
 */
extern _ARMABI unsigned __ieee_status(unsigned, unsigned);

#define FE_IEEE_FLUSHZERO          (0x01000000)
#define FE_IEEE_ROUND_TONEAREST    (0x00000000)
#define FE_IEEE_ROUND_UPWARD       (0x00400000)
#define FE_IEEE_ROUND_DOWNWARD     (0x00800000)
#define FE_IEEE_ROUND_TOWARDZERO   (0x00C00000)
#define FE_IEEE_ROUND_MASK         (0x00C00000)
#define FE_IEEE_MASK_INVALID       (0x00000100)
#define FE_IEEE_MASK_DIVBYZERO     (0x00000200)
#define FE_IEEE_MASK_OVERFLOW      (0x00000400)
#define FE_IEEE_MASK_UNDERFLOW     (0x00000800)
#define FE_IEEE_MASK_INEXACT       (0x00001000)
#define FE_IEEE_MASK_INPUTDENORMAL (0x00008000)
#define FE_IEEE_MASK_ALL_EXCEPT    (0x00009F00)
#define FE_IEEE_INVALID            (0x00000001)
#define FE_IEEE_DIVBYZERO          (0x00000002)
#define FE_IEEE_OVERFLOW           (0x00000004)
#define FE_IEEE_UNDERFLOW          (0x00000008)
#define FE_IEEE_INEXACT            (0x00000010)
#define FE_IEEE_INPUTDENORMAL      (0x00000080)
#define FE_IEEE_ALL_EXCEPT         (0x0000009F)

/*
 * The constants that define the format of __ieee_edata_t.
 */

#define FE_EX_RDIR              (1U << 31)
#define FE_EX_INPUTDENORM_SHIFT (21)
#define FE_EX_INPUTDENORM       (1 << FE_EX_INPUTDENORM_SHIFT)
#define FE_EX_EXCEPT_SHIFT      (26)
#define FE_EX_EXCEPT_MASK       ((0x1F << FE_EX_EXCEPT_SHIFT) \
                                 | FE_EX_INPUTDENORM)
#define FE_EX_INEXACT           (0x10 << FE_EX_EXCEPT_SHIFT)
#define FE_EX_UNDERFLOW         (0x08 << FE_EX_EXCEPT_SHIFT)
#define FE_EX_OVERFLOW          (0x04 << FE_EX_EXCEPT_SHIFT)
#define FE_EX_DIVBYZERO         (0x02 << FE_EX_EXCEPT_SHIFT)
#define FE_EX_INVALID           (0x01 << FE_EX_EXCEPT_SHIFT)
#define FE_EX_FLUSHZERO_SHIFT   (24)
#define FE_EX_FLUSHZERO         (1 << FE_EX_FLUSHZERO_SHIFT)
#define FE_EX_ROUND_SHIFT       (22)
#define FE_EX_ROUND_MASK        (3 << FE_EX_ROUND_SHIFT)
#define FE_EX_INTYPE_SHIFT      (7)
#define FE_EX_INTYPE_MASK       (7 << FE_EX_INTYPE_SHIFT)
#define FE_EX_OUTTYPE_SHIFT     (4)
#define FE_EX_OUTTYPE_MASK      (7 << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_TYPE_SHIFT        (4)
#define FE_EX_TYPE_MASK         (7 << FE_EX_TYPE_SHIFT)
#define FE_EX_FN_SHIFT          (0)
#define FE_EX_FN_MASK           (15 << FE_EX_FN_SHIFT)

#define FE_EX_ROUND_NEAREST     (0 << FE_EX_ROUND_SHIFT)
#define FE_EX_ROUND_PLUSINF     (1 << FE_EX_ROUND_SHIFT)
#define FE_EX_ROUND_MINUSINF    (2 << FE_EX_ROUND_SHIFT)
#define FE_EX_ROUND_ZERO        (3 << FE_EX_ROUND_SHIFT)

#define FE_EX_BASETYPE_FLOAT    (0)
#define FE_EX_BASETYPE_DOUBLE   (1)
#define FE_EX_BASETYPE_FD       (2) /* (float, double) */
#define FE_EX_BASETYPE_DF       (3) /* (double, float) */
#define FE_EX_BASETYPE_SHORT    (2) /* used only with FN_CVTSCALED */
#define FE_EX_BASETYPE_USHORT   (3) /* used only with FN_CVTSCALED */
#define FE_EX_BASETYPE_HALF     (2) /* used only with FN_CVT */
#define FE_EX_BASETYPE_INT      (4)
#define FE_EX_BASETYPE_LONGLONG (5)
#define FE_EX_BASETYPE_UINT     (6)
#define FE_EX_BASETYPE_ULONGLONG (7)

#define FE_EX_TYPE_FLOAT        (FE_EX_BASETYPE_FLOAT << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_DOUBLE       (FE_EX_BASETYPE_DOUBLE << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_SHORT        (FE_EX_BASETYPE_SHORT << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_USHORT       (FE_EX_BASETYPE_USHORT << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_HALF         (FE_EX_BASETYPE_HALF << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_INT          (FE_EX_BASETYPE_INT << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_LONGLONG     (FE_EX_BASETYPE_LONGLONG << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_UINT         (FE_EX_BASETYPE_UINT << FE_EX_TYPE_SHIFT)
#define FE_EX_TYPE_ULONGLONG    (FE_EX_BASETYPE_ULONGLONG << FE_EX_TYPE_SHIFT)

#define FE_EX_INTYPE_FLOAT      (FE_EX_BASETYPE_FLOAT << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_DOUBLE     (FE_EX_BASETYPE_DOUBLE << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_FD         (FE_EX_BASETYPE_FD << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_DF         (FE_EX_BASETYPE_DF << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_SHORT      (FE_EX_BASETYPE_SHORT << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_USHORT     (FE_EX_BASETYPE_USHORT << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_HALF       (FE_EX_BASETYPE_HALF << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_INT        (FE_EX_BASETYPE_INT << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_LONGLONG   (FE_EX_BASETYPE_LONGLONG << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_UINT       (FE_EX_BASETYPE_UINT << FE_EX_INTYPE_SHIFT)
#define FE_EX_INTYPE_ULONGLONG  (FE_EX_BASETYPE_ULONGLONG<<FE_EX_INTYPE_SHIFT)

#define FE_EX_OUTTYPE_FLOAT     (FE_EX_BASETYPE_FLOAT << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_DOUBLE    (FE_EX_BASETYPE_DOUBLE << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_SHORT     (FE_EX_BASETYPE_SHORT << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_USHORT    (FE_EX_BASETYPE_USHORT << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_HALF      (FE_EX_BASETYPE_HALF << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_INT       (FE_EX_BASETYPE_INT << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_LONGLONG  (FE_EX_BASETYPE_LONGLONG<<FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_UINT      (FE_EX_BASETYPE_UINT << FE_EX_OUTTYPE_SHIFT)
#define FE_EX_OUTTYPE_ULONGLONG (FE_EX_BASETYPE_ULONGLONG<<FE_EX_OUTTYPE_SHIFT)

#define FE_EX_FN_ADD            (1 << FE_EX_FN_SHIFT)
#define FE_EX_FN_SUB            (2 << FE_EX_FN_SHIFT)
#define FE_EX_FN_MUL            (3 << FE_EX_FN_SHIFT)
#define FE_EX_FN_DIV            (4 << FE_EX_FN_SHIFT)
#define FE_EX_FN_REM            (5 << FE_EX_FN_SHIFT)
#define FE_EX_FN_RND            (6 << FE_EX_FN_SHIFT)
#define FE_EX_FN_SQRT           (7 << FE_EX_FN_SHIFT)
#define FE_EX_FN_CVT            (8 << FE_EX_FN_SHIFT)
#define FE_EX_FN_CMP            (9 << FE_EX_FN_SHIFT)
#define FE_EX_FN_LOGB           (10 << FE_EX_FN_SHIFT)
#define FE_EX_FN_SCALBN         (11 << FE_EX_FN_SHIFT)
#define FE_EX_FN_NEXTAFTER      (12 << FE_EX_FN_SHIFT)
#define FE_EX_FN_CVTSCALED      (13 << FE_EX_FN_SHIFT)
#define FE_EX_FN_RAISE          (15 << FE_EX_FN_SHIFT)

#define FE_EX_CMPRET_UNORDERED  (8)
#define FE_EX_CMPRET_LESS       (4)
#define FE_EX_CMPRET_EQUAL      (2)
#define FE_EX_CMPRET_GREATER    (1)

#ifdef __cplusplus
}
#endif

#endif

