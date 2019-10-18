/* rt_fp.h: prototypes for the fplib basic-arithmetic functions
 *
 * Copyright 1999 ARM Limited. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

#ifndef __RT_FP_H
#define __RT_FP_H
#define __ARMCLIB_VERSION 6090000

#ifdef __cplusplus
extern "C" {
#endif

/*
 * For the benefit of the VFP support library, we allow a module
 * including this file to define a name-mapping macro `_PREFIX()',
 * which transforms a name such as `_fadd' into something like
 * `vfp_fadd'.
 */
#ifndef _PREFIX
#define _PREFIX(x) x
#endif

#if (defined(__ARM_64BIT_STATE) || defined(__TARGET_ARCH_AARCH64))
# define _SOFTFP
#else
# define _SOFTFP __attribute__((__pcs__("aapcs")))
#endif

/*
 * Trivial routines.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP float _PREFIX(_fneg)(float);
extern _SOFTFP float _PREFIX(__aeabi_fneg)(float);
extern _SOFTFP float _PREFIX(_fabs)(float);
extern _SOFTFP double _PREFIX(_dneg)(double);
extern _SOFTFP double _PREFIX(__aeabi_dneg)(double);
extern _SOFTFP double _PREFIX(_dabs)(double);
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Single-precision arithmetic routines.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP float _PREFIX(_fadd)(float, float);
extern _SOFTFP float _PREFIX(__aeabi_fadd)(float, float);
extern _SOFTFP float _PREFIX(_fsub)(float, float);
extern _SOFTFP float _PREFIX(__aeabi_fsub)(float, float);
extern _SOFTFP float _PREFIX(_frsb)(float, float);
extern _SOFTFP float _PREFIX(__aeabi_frsub)(float, float);
extern _SOFTFP float _PREFIX(_fmul)(float, float);
extern _SOFTFP float _PREFIX(__aeabi_fmul)(float, float);
extern _SOFTFP float _PREFIX(_fdiv)(float, float);
extern _SOFTFP float _PREFIX(__aeabi_fdiv)(float, float);
extern _SOFTFP float _PREFIX(_frdiv)(float, float);
extern _SOFTFP float _PREFIX(_fsqrt)(float);
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */
extern _SOFTFP float _PREFIX(_frem)(float, float);
extern _SOFTFP float _PREFIX(_frnd)(float);

/*
 * Double-precision arithmetic routines.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP double _PREFIX(_dadd)(double, double);
extern _SOFTFP double _PREFIX(__aeabi_dadd)(double, double);
extern _SOFTFP double _PREFIX(_dsub)(double, double);
extern _SOFTFP double _PREFIX(__aeabi_dsub)(double, double);
extern _SOFTFP double _PREFIX(_drsb)(double, double);
extern _SOFTFP double _PREFIX(__aeabi_drsub)(double, double);
extern _SOFTFP double _PREFIX(_dmul)(double, double);
extern _SOFTFP double _PREFIX(__aeabi_dmul)(double, double);
extern _SOFTFP double _PREFIX(_ddiv)(double, double);
extern _SOFTFP double _PREFIX(__aeabi_ddiv)(double, double);
extern _SOFTFP double _PREFIX(_drdiv)(double, double);
extern _SOFTFP double _PREFIX(_dsqrt)(double);
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */
extern _SOFTFP double _PREFIX(_drem)(double, double);
extern _SOFTFP double _PREFIX(_drnd)(double);

/*
 * Boolean-return compares ({f,d}cmp{eq,ge,le} are not listed
 * because they return results in the flags and so cannot be
 * described by C prototypes).
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP int _PREFIX(_feq)(float, float);
extern _SOFTFP int _PREFIX(__aeabi_fcmpeq)(float, float);
extern _SOFTFP int _PREFIX(_fneq)(float, float);
extern _SOFTFP int _PREFIX(_fgeq)(float, float);
extern _SOFTFP int _PREFIX(__aeabi_fcmpge)(float, float);
extern _SOFTFP int _PREFIX(_fgr)(float, float);
extern _SOFTFP int _PREFIX(__aeabi_fcmpgt)(float, float);
extern _SOFTFP int _PREFIX(_fleq)(float, float);
extern _SOFTFP int _PREFIX(__aeabi_fcmple)(float, float);
extern _SOFTFP int _PREFIX(_fls)(float, float);
extern _SOFTFP int _PREFIX(__aeabi_fcmplt)(float, float);
extern _SOFTFP int _PREFIX(_fun)(float, float);
extern _SOFTFP int _PREFIX(__aeabi_fcmpun)(float, float);
extern _SOFTFP int _PREFIX(_deq)(double, double);
extern _SOFTFP int _PREFIX(__aeabi_dcmpeq)(double, double);
extern _SOFTFP int _PREFIX(_dneq)(double, double);
extern _SOFTFP int _PREFIX(_dgeq)(double, double);
extern _SOFTFP int _PREFIX(__aeabi_dcmpge)(double, double);
extern _SOFTFP int _PREFIX(_dgr)(double, double);
extern _SOFTFP int _PREFIX(__aeabi_dcmpgt)(double, double);
extern _SOFTFP int _PREFIX(_dleq)(double, double);
extern _SOFTFP int _PREFIX(__aeabi_dcmple)(double, double);
extern _SOFTFP int _PREFIX(_dls)(double, double);
extern _SOFTFP int _PREFIX(__aeabi_dcmplt)(double, double);
extern _SOFTFP int _PREFIX(_dun)(double, double);
extern _SOFTFP int _PREFIX(__aeabi_dcmpun)(double, double);
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Four-way compares. These return VFP-type status flags _in_ the
 * CPSR, but also return in r0 so they can be called sensibly from
 * C.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP unsigned _PREFIX(_fcmp4)(float, float);
extern _SOFTFP unsigned _PREFIX(_fcmp4e)(float, float);
extern _SOFTFP unsigned _PREFIX(_dcmp4)(double, double);
extern _SOFTFP unsigned _PREFIX(_dcmp4e)(double, double);
extern _SOFTFP unsigned _PREFIX(_fdcmp4)(float, double);
extern _SOFTFP unsigned _PREFIX(_fdcmp4e)(float, double);
extern _SOFTFP unsigned _PREFIX(_dfcmp4)(double, float);
extern _SOFTFP unsigned _PREFIX(_dfcmp4e)(double, float);
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Floating-to-floating format conversions.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP double _PREFIX(_f2d)(float);
extern _SOFTFP double _PREFIX(__aeabi_f2d)(float);
extern _SOFTFP float _PREFIX(_d2f)(double);
extern _SOFTFP float _PREFIX(__aeabi_d2f)(double);
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Integer-to-floating format conversions.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP float _PREFIX(_fflt)(int);
extern _SOFTFP float _PREFIX(__aeabi_i2f)(int);
extern _SOFTFP float _PREFIX(_ffltu)(unsigned int);
extern _SOFTFP float _PREFIX(__aeabi_ui2f)(unsigned int);
extern _SOFTFP double _PREFIX(_dflt)(int);
extern _SOFTFP double _PREFIX(__aeabi_i2d)(int);
extern _SOFTFP double _PREFIX(_dfltu)(unsigned int);
extern _SOFTFP double _PREFIX(__aeabi_ui2d)(unsigned int);
#if !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__)
extern _SOFTFP float _PREFIX(_ll_sto_f)(long long);
extern _SOFTFP float _PREFIX(__aeabi_l2f)(long long);
extern _SOFTFP float _PREFIX(_ll_uto_f)(unsigned long long);
extern _SOFTFP float _PREFIX(__aeabi_ul2f)(unsigned long long);
extern _SOFTFP double _PREFIX(_ll_sto_d)(long long);
extern _SOFTFP double _PREFIX(__aeabi_l2d)(long long);
extern _SOFTFP double _PREFIX(_ll_uto_d)(unsigned long long);
extern _SOFTFP double _PREFIX(__aeabi_ul2d)(unsigned long long);
#endif /* __STRICT_ANSI__ */
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Floating-to-integer format conversions, rounding toward zero
 * always.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP int _PREFIX(_ffix)(float);
extern _SOFTFP int _PREFIX(__aeabi_f2iz)(float);
extern _SOFTFP unsigned int _PREFIX(_ffixu)(float);
extern _SOFTFP unsigned int _PREFIX(__aeabi_f2uiz)(float);
extern _SOFTFP int _PREFIX(_dfix)(double);
extern _SOFTFP int _PREFIX(__aeabi_d2iz)(double);
extern _SOFTFP unsigned int _PREFIX(_dfixu)(double);
extern _SOFTFP unsigned int _PREFIX(__aeabi_d2uiz)(double);
#if !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__)
extern _SOFTFP long long _PREFIX(_ll_sfrom_f)(float);
extern _SOFTFP long long _PREFIX(__aeabi_f2lz)(float);
extern _SOFTFP unsigned long long _PREFIX(_ll_ufrom_f)(float);
extern _SOFTFP unsigned long long _PREFIX(__aeabi_f2ulz)(float);
extern _SOFTFP long long _PREFIX(_ll_sfrom_d)(double);
extern _SOFTFP long long _PREFIX(__aeabi_d2lz)(double);
extern _SOFTFP unsigned long long _PREFIX(_ll_ufrom_d)(double);
extern _SOFTFP unsigned long long _PREFIX(__aeabi_d2ulz)(double);
#endif /* __STRICT_ANSI__ */
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Floating-to-integer format conversions, rounding to nearest or
 * configurably.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP int _PREFIX(_ffix_r)(float);
extern _SOFTFP unsigned int _PREFIX(_ffixu_r)(float);
extern _SOFTFP int _PREFIX(_dfix_r)(double);
extern _SOFTFP unsigned int _PREFIX(_dfixu_r)(double);
#if !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__)
extern _SOFTFP long long _PREFIX(_ll_sfrom_f_r)(float);
extern _SOFTFP unsigned long long _PREFIX(_ll_ufrom_f_r)(float);
extern _SOFTFP long long _PREFIX(_ll_sfrom_d_r)(double);
extern _SOFTFP unsigned long long _PREFIX(_ll_ufrom_d_r)(double);
#endif /* __STRICT_ANSI__ */
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Low-level (in particular, not setting errno) analogues of math.h
 * functions.
 */
#if (!defined(__ARM_64BIT_STATE) && !defined(__TARGET_ARCH_AARCH64))
extern _SOFTFP int _ilogb(double);
extern _SOFTFP int _ilogbf(float);
extern _SOFTFP double _logb(double);
extern _SOFTFP float _logbf(float);
extern _SOFTFP double __ARM_scalbn(double, int);
extern _SOFTFP float __ARM_scalbnf(float, int);
extern _SOFTFP double _nextafter(double, double);
extern _SOFTFP float _nextafterf(float, float);
extern _SOFTFP float _nexttowardf(float, double);
#endif /* !__ARM_64BIT_STATE && !__TARGET_ARCH_AARCH64 */

/*
 * Call this before using any fplib routines, if you're trying to
 * use fplib on the bare metal.
 */
extern void _PREFIX(_fp_init)(void);

/*
 * This returns a pointer to the FP status word, when it's stored
 * in memory.
 */
extern unsigned * _PREFIX(__rt_fp_status_addr)(void);

#ifdef __cplusplus
}
#endif

#endif

