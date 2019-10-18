/* c55x.h - Emulation of selected TI C55x intrinsics */
/* Copyright (C) 2006 ARM Limited. All rights reserved. */

/*
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

#ifndef __arm_c55x_h
#define __arm_c55x_h
#define __ARMCLIB_VERSION 6090000

#ifdef __cplusplus
#define __STDC_LIMIT_MACROS 1
#endif /* __cplusplus */
#include <stdint.h>

#ifdef __cplusplus
#define __ARM_INTRINSIC __attribute__((always_inline))
#elif defined __GNUC__ || defined _USE_STATIC_INLINE
#define __ARM_INTRINSIC static __attribute__((always_inline))
#elif (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__)
#define __ARM_INTRINSIC __attribute__((always_inline))
#else
#define __ARM_INTRINSIC __attribute__((always_inline))
#endif

/* Define this to 1 if you believe all shift counts are in the range [-255,255] */
#ifndef __ARM_DSP_SMALL_SHIFTS
#define __ARM_DSP_SMALL_SHIFTS 0
#endif

#ifdef __ARM_32BIT_STATE
/* Include __qadd/__qsub AArch32 intrinsics definition*/
#include <arm_acle.h>

__ARM_INTRINSIC int32_t _sround  (int32_t src);

__ARM_INTRINSIC int16_t _sadd    (int16_t src1, int16_t src2)      { return __qadd(src1<<16, src2<<16) >> 16; }
__ARM_INTRINSIC int16_t _a_sadd  (int16_t src1, int16_t src2)      { return __qadd(src1<<16, src2<<16) >> 16; }
__ARM_INTRINSIC int32_t _lsadd   (int32_t src1, int32_t src2)      { return __qadd(src1, src2);               }
__ARM_INTRINSIC int32_t _a_lsadd (int32_t src1, int32_t src2)      { return __qadd(src1, src2);               }
__ARM_INTRINSIC int16_t _ssub    (int16_t src1, int16_t src2)      { return __qsub(src1<<16, src2<<16) >> 16; }
__ARM_INTRINSIC int32_t _lssub   (int32_t src1, int32_t src2)      { return __qsub(src1, src2);               }

__ARM_INTRINSIC int16_t _sneg    (int16_t src)                     { return _ssub(0, src);                    }
__ARM_INTRINSIC int32_t _lsneg   (int32_t src)                     { return __qsub(0, src);                   }

__ARM_INTRINSIC int16_t _abss    (int16_t src)                     { return src < 0 ? _sneg(src) : src;       }
__ARM_INTRINSIC int32_t _labss   (int32_t src)                     { return src < 0 ? _lsneg(src) : src;      }

__ARM_INTRINSIC int16_t _smpy    (int16_t src1, int16_t src2)      { return (int16_t)(__qdbl(src1*src2) >> 16); }

__ARM_INTRINSIC int32_t _lsmpy   (int16_t src1, int16_t src2)      { return __qdbl(src1 * src2);              }
#endif
__ARM_INTRINSIC int32_t _lmpy    (int16_t src1, int16_t src2)      { return        src1 * src2;               }
__ARM_INTRINSIC int32_t _lmpysu  (int16_t src1, uint16_t src2)     { return        src1 * src2;               }
__ARM_INTRINSIC int32_t _lmpyu   (uint16_t src1, uint16_t src2)    { return        src1 * src2;               }
__ARM_INTRINSIC int32_t _lsmpyi  (int16_t src1, int16_t src2)      { return        src1 * src2;               }
__ARM_INTRINSIC int32_t _lsmpysui(int16_t src1, uint16_t src2)     { return        src1 * src2;               }
__ARM_INTRINSIC int32_t _lsmpyui (uint16_t src1, uint16_t src2)    { uint32_t r = src1 * src2; return (r > INT32_MAX) ? INT32_MAX : r; }
#ifdef __ARM_32BIT_STATE
__ARM_INTRINSIC int32_t _lsmpysu (int16_t src1, uint16_t src2)     { return __qdbl(src1 * src2);              }
__ARM_INTRINSIC int32_t _lsmpyu  (uint16_t src1, uint16_t src2)    { return __qdbl(_lsmpyui(src1, src2));     }

__ARM_INTRINSIC int32_t _smpyr   (int16_t src1, int16_t src2)      { return __qdbl(src1*src2 + 0x4000) & 0xFFFF0000; } /* old name */
__ARM_INTRINSIC int32_t _lsmpyr  (int16_t src1, int16_t src2)      { return __qdbl(src1*src2 + 0x4000) & 0xFFFF0000; }

/* Accumulation functions: comments indicate the (notional) multiplication intrinsic involved */
__ARM_INTRINSIC int32_t _smac    (int32_t src1, int16_t src2, int16_t src3)  { return __qadd(src1, __qdbl(src2*src3)); } /* _lsmpy */
__ARM_INTRINSIC int32_t _a_smac  (int32_t src1, int16_t src2, int16_t src3)  { return __qadd(src1, __qdbl(src2*src3)); }
__ARM_INTRINSIC int32_t _smaci   (int32_t src1, int16_t src2, int16_t src3)  { return __qadd(src1, src2*src3);         } /* _lsmpyi */
__ARM_INTRINSIC int32_t _smacsui (int32_t src1, int16_t src2, uint16_t src3) { return __qadd(src1, src2*src3);         } /* _lmpysui */
__ARM_INTRINSIC int32_t _smacsu  (int32_t src1, int16_t src2, uint16_t src3) { return __qadd(src1, __qdbl(src2*src3)); } /* _lmpysu */

__ARM_INTRINSIC int32_t _smacr   (int32_t src1, int16_t src2, int16_t src3)  { return _sround(__qadd(src1, __qdbl(src2*src3))); }
__ARM_INTRINSIC int32_t _a_smacr (int32_t src1, int16_t src2, int16_t src3)  { return _sround(__qadd(src1, __qdbl(src2*src3))); }

__ARM_INTRINSIC int32_t _smas    (int32_t src1, int16_t src2, int16_t src3)  { return __qsub(src1, __qdbl(src2*src3)); } /* _lsmpy */
__ARM_INTRINSIC int32_t _a_smas  (int32_t src1, int16_t src2, int16_t src3)  { return __qsub(src1, __qdbl(src2*src3)); }
__ARM_INTRINSIC int32_t _smasi   (int32_t src1, int16_t src2, int16_t src3)  { return __qsub(src1, src2*src3);         } /* _lsmpyi */
__ARM_INTRINSIC int32_t _smassui (int32_t src1, int16_t src2, uint16_t src3) { return __qsub(src1, src2*src3);         } /* _lmpysui */
__ARM_INTRINSIC int32_t _smassu  (int32_t src1, int16_t src2, uint16_t src3) { return __qsub(src1, __qdbl(src2*src3)); } /* _lmpysu */

__ARM_INTRINSIC int32_t _smasr   (int32_t src1, int16_t src2, int16_t src3)  { return _sround(__qsub(src1, __qdbl(src2*src3))); }
__ARM_INTRINSIC int32_t _a_smasr (int32_t src1, int16_t src2, int16_t src3)  { return _sround(__qsub(src1, __qdbl(src2*src3))); }
#endif

#if __ARM_DSP_SMALL_SHIFTS
#define __ARM_normalize_shift(x) (x)
#else /* !__ARM_DSP_SMALL_SHIFTS */
/* Normalize shifts of any range.  Expression should reduce to a 6-bit saturation.
   5-bit saturation is not enough as 32-bit shift and 31-bit shift are different. */
#define __ARM_normalize_shift(x) ((x) >= 63 ? 63 : (x) <= -64 ? -64 : (x))
#endif /* __ARM_DSP_SMALL_SHIFTS */

/* 'x' is known to cause an out-of-range left-shift result.  Generate a
   saturated maximal value and also cause the saturation flag to be set. */
#define __ARM_saturated_result(x) __qdbl(INT32_MAX - ((x) >> 31))
  

#ifdef __ARM_32BIT_STATE
/* Result is saturated */
__ARM_INTRINSIC int16_t _sshl(int16_t src1, int16_t src2)
{
  src2 = __ARM_normalize_shift(src2);
  if (src2 < 0) {
    return src1 >> -src2;
  } else {
    int16_t sh = src1 << src2;
    if ((sh >> src2) != src1) {
      sh = __ARM_saturated_result(src1) >> 16;
    }
    return sh;
  }
}

/* Result is saturated */
__ARM_INTRINSIC int32_t _lsshl(int32_t src1, int16_t src2)
{
  src2 = __ARM_normalize_shift(src2);
  if (src2 < 0) {
    return src1 >> -src2;
  } else {
    int32_t sh = src1 << src2;
    if ((sh >> src2) != src1) {
      sh = __ARM_saturated_result(src1);
    }
    return sh;
  }
}

/* Result is saturated */
__ARM_INTRINSIC int16_t _shrs(int16_t src1, int16_t src2)
{
  src2 = __ARM_normalize_shift(src2);
  if (src2 < 0) {
    int16_t sh = src1 << -src2;
    if ((sh >> -src2) != src1) {
      sh = __ARM_saturated_result(src1) >> 16;
    }
    return sh;
  } else {
    return src1 >> src2;
  }
}

/* Result is saturated */
__ARM_INTRINSIC int32_t _lshrs(int32_t src1, int16_t src2)
{
  src2 = __ARM_normalize_shift(src2);
  if (src2 < 0) {
    int32_t sh = src1 << -src2;
    if ((sh >> -src2) != src1) {
      sh = __ARM_saturated_result(src1);
    }
    return sh;
  } else {
    return src1 >> src2;
  }
}
#endif

/* No saturation is performed */
__ARM_INTRINSIC int16_t _shl(int16_t src1, int16_t src2)
{
  src2 = __ARM_normalize_shift(src2);
  if (src2 < 0) {
    return src1 >> -src2;
  } else {
    return src1 << src2;
  }
}

/* No saturation is performed */
__ARM_INTRINSIC int32_t _lshl(int32_t src1, int16_t src2)
{
  src2 = __ARM_normalize_shift(src2);
  if (src2 < 0) {
    return src1 >> -src2;
  } else {
    return src1 << src2;
  }
}

__ARM_INTRINSIC int32_t _round   (int32_t src)                     { return (src + 0x8000) & 0xFFFF0000; }
#ifdef __ARM_32BIT_STATE
__ARM_INTRINSIC int32_t _sround  (int32_t src)                     { return __qadd(src, 0x8000) & 0xFFFF0000; }
__ARM_INTRINSIC int32_t _rnd     (int32_t src)                     { return _sround(src); }
#endif
__ARM_INTRINSIC int32_t _roundn(int32_t src)
{
  if ((src & 0x17FFF) != 0) {
    src += (src & 0x8000);
  }
  return src & 0xFFFF0000;
}

#ifdef __ARM_32BIT_STATE
__ARM_INTRINSIC int32_t _sroundn(int32_t src)
{
  if ((src & 0x17FFF) != 0) {
    src = __qadd(src, (src & 0x8000));
  }
  return src & 0xFFFF0000;
}
#endif

#if __ARMCOMPILER_VERSION < 6000000
__ARM_INTRINSIC int16_t _norm  (int16_t src)   { return __clz(src ^ ((int32_t)src << 17)) & 15; }
__ARM_INTRINSIC int16_t _lnorm (int32_t src)   { return __clz(src ^ (src << 1)) & 31; }
#endif

/* Note that 'long long' in TI C55x is a 40-bit type. */
__ARM_INTRINSIC int32_t _lsat(int64_t src)
{
  return (src > INT32_MAX) ? INT32_MAX : (src < INT32_MIN) ? INT32_MIN : (int32_t)src;
}

__ARM_INTRINSIC int16_t _count (uint64_t src1, uint64_t src2) { return (int16_t)__builtin_popcountll(src1 & src2); }

__ARM_INTRINSIC int16_t _max   (int16_t src1, int16_t src2)  { return (src1 > src2) ? src1 : src2; }
__ARM_INTRINSIC int32_t _lmax  (int32_t src1, int32_t src2)  { return (src1 > src2) ? src1 : src2; }
__ARM_INTRINSIC int16_t _min   (int16_t src1, int16_t src2)  { return (src1 < src2) ? src1 : src2; }
__ARM_INTRINSIC int32_t _lmin  (int32_t src1, int32_t src2)  { return (src1 < src2) ? src1 : src2; }

/* 16-bit non-fractional division with saturation. */
__ARM_INTRINSIC int16_t _divs(int16_t src1, int16_t src2)
{
  if (src1 == -0x8000 && src2 == -1) {
    return 0x7FFF;
  }
  return src1 / src2;
}

/* Support function: "divides x by y with saturation" - i.e. fractional.
   Equivalent to ETSI div_s over div_s's range */
__ARM_INTRINSIC int16_t divs(int16_t x, int16_t y)
{
    if (x < 0 || y <= 0) return (x == 0) ? 0 : (x == y) ? INT16_MAX : ((x << 1) >= y) ? INT16_MAX : 0;
    if (x >= y) return x ? INT16_MAX : 0;
    return (x * 0x8000) / y;
}


#ifdef __ARM_32BIT_STATE
/* Support function - identical to ETSI shr_r */
__ARM_INTRINSIC int16_t crshft_r(int16_t x, int16_t shift)
{
    int32_t tmp;
    if (shift == 0 || x == 0)
        return x;
    if (shift > 0) {
#if !__ARM_DSP_SMALL_SHIFTS
        if (shift > 32) shift = 32;
#endif /* __ARM_DSP_SMALL_SHIFTS */
        return (int16_t) (((x >> (shift-1)) + 1) >> 1);
    }
    if (shift < -15)
        shift = -16;
    tmp = x << -shift;
#if (defined(__thumb) && (__TARGET_ARCH_THUMB >= 4)) || (__TARGET_ARCH_ARM >= 6)
    return (int16_t)__ssat(tmp, 16);
#else
    /* ARM v5E has no SSAT instruction */
    if (tmp > INT16_MAX || tmp < INT16_MIN)
        tmp = __qdbl(INT32_MAX - (tmp >> 31)) >> 16;   /* Saturate and set Overflow */
    return tmp;
#endif
}
#endif

#if __ARMCOMPILER_VERSION < 6000000
/* Support function - identical to ETSI L_shr_r */
__ARM_INTRINSIC int32_t L_crshft_r(int32_t x, int16_t shift)
{
    if (shift == 0 || x == 0)
        return x;
    if (shift > 0) {        
#if !__ARM_DSP_SMALL_SHIFTS
        int32_t x2 = (shift > 32) ? 0 : x >> (shift-1);
#else
        int32_t x2 = x >> (shift-1);
#endif /* __ARM_DSP_SMALL_SHIFTS */
        return (x2 >> 1) + (x2 & 1);
    }
    if (-shift <= __clz(x ^ (x << 1)) || x == 0)
        return x << (-shift);
    return __qdbl((x < 0) ? INT32_MIN : INT32_MAX);
}
#endif

#undef __ARM_normalize_shift
#undef __ARM_saturated_result

#endif /* ndef __arm_c55x_h */

/* end of c55x.h */

