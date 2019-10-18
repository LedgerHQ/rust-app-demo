/* armdsp.h
 *
 * Copyright 2001 ARM Limited. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

/* ----------------------------------------------------------------------
 * This header file provides a set of DSP-type primitive
 * operations, such as saturating integer arithmetic and 16x16 bit
 * multiplication. The operations it provides are exactly the same
 * operations supported directly by the ARM9E.
 * 
 * This header file is intended as an example implementation. It
 * demonstrates how to use the inline assembly feature in the ARM
 * compilers, to construct intrinsic functions that provide
 * C-language access to the ARM9E's DSP capability.
 */

#ifndef ARMDSP_ARMDSP_H
#define ARMDSP_ARMDSP_H
#define __ARMCLIB_VERSION 6090000

#ifndef ARMDSP_WORD32_DEFINED
#define ARMDSP_WORD32_DEFINED
typedef signed int Word32;
typedef signed short Word16;
#define ARMDSP_WORD32_MAX ((Word32)0x7FFFFFFF)
#define ARMDSP_WORD32_MIN ((Word32)-0x80000000)
#define ARMDSP_WORD16_MAX ((Word16)0x7FFF)
#define ARMDSP_WORD16_MIN ((Word16)-0x8000)
#endif

#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif

/*
 * Saturating 32-bit integer addition.
 */
__inline Word32 qadd(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("qadd %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        qadd ret, x, y;
    }
#endif
    return ret;
}

/*
 * Saturating 32-bit integer subtraction.
 */
__inline Word32 qsub(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("qsub %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        qsub ret, x, y;
    }
#endif
    return ret;
}

/*
 * Saturating 32-bit integer addition, with the second operand
 * multiplied by two. (i.e. return x + 2 * y)
 */
__inline Word32 qdadd(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("qdadd %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        qdadd ret, x, y;
    }
#endif
    return ret;
}

/*
 * Saturating 32-bit integer subtraction, with the second operand
 * multiplied by two. (i.e. return x - 2 * y)
 */
__inline Word32 qdsub(Word32 x, Word32 y)
{
    Word32 ret;
 #if __ARMCOMPILER_VERSION > 6000000
   __asm ("qdsub %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        qdsub ret, x, y;
    }
#endif
    return ret;
}

/*
 * Multiply two signed 16-bit numbers, taken from the bottom or top
 * halves of the input words. For example, smulbt(x,y) multiplies
 * the bottom 16 bits of x with the top 16 bits of y.
 */

/* smulbb - multiply bottom half of x and bottom half of y */
__inline Word32 smulbb(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smulbb %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        smulbb ret, x, y;
    }
#endif
    return ret;
}

/* smulbt - multiply bottom half of x and top half of y */
__inline Word32 smulbt(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smulbt %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        smulbt ret, x, y;
    }
#endif
    return ret;
}

/* smultb - multiply top half of x and bottom half of y */
__inline Word32 smultb(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smultb %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        smultb ret, x, y;
    }
#endif
    return ret;
}

/* smultt - multiply top half of x and top half of y */
__inline Word32 smultt(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smultt %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        smultt ret, x, y;
    }
#endif
    return ret;
}

/*
 * Multiply two signed 16-bit numbers, taken from the bottom or top
 * halves of the input words x and y, and add to the input word a.
 * For example, smlabt(x,y,a) multiplies the bottom 16 bits of x with
 * the top 16 bits of y, and then adds a.
 */

/* smlabb - multiply bottom half of x and bottom half of y */
__inline Word32 smlabb(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smlabb %0, %1, %2, %3": "=r" (ret) : "r" (x), "r" (y), "r" (a));
#else
    __asm {
        smlabb ret, x, y, a;
    }
#endif
    return ret;
}

/* smlabt - multiply bottom half of x and top half of y */
__inline Word32 smlabt(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smlabt %0, %1, %2, %3": "=r" (ret) : "r" (x), "r" (y), "r" (a));
#else
    __asm {
        smlabt ret, x, y, a;
    }
#endif
    return ret;
}

/* smlatb - multiply top half of x and bottom half of y */
__inline Word32 smlatb(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smlatb %0, %1, %2, %3": "=r" (ret) : "r" (x), "r" (y), "r" (a));
#else
    __asm {
        smlatb ret, x, y, a;
    }
#endif
    return ret;
}

/* smlatt - multiply top half of x and top half of y */
__inline Word32 smlatt(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smlatt %0, %1, %2, %3": "=r" (ret) : "r" (x), "r" (y), "r" (a));
#else
    __asm {
        smlatt ret, x, y, a;
    }
#endif
    return ret;
}

/*
 * Multiply two signed 16-bit numbers, taken from the bottom or top
 * halves of the input words x and y, and add to the 64-bit integer
 * stored in the input words lo and hi. For example,
 * smlalbt(&lo,&hi,x,y) multiplies the bottom 16 bits of x with the
 * top 16 bits of y, and then adds the result to (hi,lo).
 * 
 * WARNING: if you use these primitives too often inside the same
 * function, they may fail to be inlined.
 */

/* smlalbb - multiply bottom half of x and bottom half of y */
__inline void smlalbb(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __ARMCOMPILER_VERSION > 6000000
    Word32 reglo = *lo, reghi = *hi;
    __asm ("smlalbb %0, %1, %2, %3": "+r" (reglo), "+r" (reghi)
                                   : "r" (x), "r" (y));
    *lo = reglo; *hi = reghi;
#else
    __asm {
        smlalbb *lo, *hi, x, y;
    }
#endif
}

/* smlalbt - multiply bottom half of x and top half of y */
__inline void smlalbt(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __ARMCOMPILER_VERSION > 6000000
    Word32 reglo = *lo, reghi = *hi;
    __asm ("smlalbt %0, %1, %2, %3": "+r" (reglo), "+r" (reghi)
                                   : "r" (x), "r" (y));
    *lo = reglo; *hi = reghi;
#else
    __asm {
        smlalbt *lo, *hi, x, y;
    }
#endif
}

/* smlaltb - multiply top half of x and bottom half of y */
__inline void smlaltb(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __ARMCOMPILER_VERSION > 6000000
    Word32 reglo = *lo, reghi = *hi;
    __asm ("smlaltb %0, %1, %2, %3": "+r" (reglo), "+r" (reghi)
                                   : "r" (x), "r" (y));
    *lo = reglo; *hi = reghi;
#else
    __asm {
        smlaltb *lo, *hi, x, y;
    }
#endif
}

/* smlaltt - multiply top half of x and top half of y */
__inline void smlaltt(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __ARMCOMPILER_VERSION > 6000000
    Word32 reglo = *lo, reghi = *hi;
    __asm ("smlaltt %0, %1, %2, %3": "+r" (reglo), "+r" (reghi)
                                   : "r" (x), "r" (y));
    *lo = reglo; *hi = reghi;
#else
    __asm {
        smlaltt *lo, *hi, x, y;
    }
#endif
}

/*
 * Multiply a 32-bit signed integer (the input word x) with a
 * 16-bit signed integer (taken from either the top or the bottom
 * half of the input word y). Discard the bottom 16 bits of the
 * 48-bit product.
 */

/* smulwb - multiply x by the bottom half of y */
__inline Word32 smulwb(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smulwb %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        smulwb ret, x, y;
    }
#endif
    return ret;
}

/* smulwt - multiply x by the top half of y */
__inline Word32 smulwt(Word32 x, Word32 y)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smulwt %0, %1, %2": "=r" (ret) : "r" (x), "r" (y));
#else
    __asm {
        smulwt ret, x, y;
    }
#endif
    return ret;
}

/*
 * Multiply a 32-bit signed integer (the input word x) with a
 * 16-bit signed integer (taken from either the top or the bottom
 * half of the input word y). Discard the bottom 16 bits of the
 * 48-bit product, and add to the input word a.
 */

/* smlawb - multiply x by the bottom half of y */
__inline Word32 smlawb(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smlawb %0, %1, %2, %3": "=r" (ret) : "r" (x), "r" (y), "r" (a));
#else
    __asm {
        smlawb ret, x, y, a;
    }
#endif
    return ret;
}

/* smlawt - multiply x by the top half of y */
__inline Word32 smlawt(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __ARMCOMPILER_VERSION > 6000000
    __asm ("smlawt %0, %1, %2, %3": "=r" (ret) : "r" (x), "r" (y), "r" (a));
#else
    __asm {
        smlawt ret, x, y, a;
    }
#endif
    return ret;
}

#ifdef __cplusplus
}
#endif

#endif /* ARMDSP_ARMDSP_H */

