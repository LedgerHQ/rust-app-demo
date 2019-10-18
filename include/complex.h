/* 
 * complex.h: ISO/IEC 9899:1999 (C99), section 7.3 
 *
 * Copyright (C) ARM Ltd., 2006. All rights reserved 
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

#if __STDC_VERSION__ < 199901L && !defined(__GNUC__)
#  error complex.h requires c99 mode or gnu mode
#endif
#define __ARMCLIB_VERSION 6090000

/*
  In order to get the float, double, and long double versions
  this file includes itself twice, for a total of three inclusions,
  each time defining __CFLOAT __FLOAT and __CFUNC appropriately 
  so that we get three versions of each function
*/

/* defined once we have been included thrice */
#ifndef __complex_h

#if defined(__complex_h_twice) && !defined(__complex_h_thrice)
#  define __complex_h_thrice
#  undef __CFLOAT
#  define __CFLOAT long double complex
#  undef __FLOAT
#  define __FLOAT long double
#  undef __CFUNC
#  define __CFUNC(x) x##l
#endif /* complex_h_thrice */


#if defined(__complex_h_once) && !defined(__complex_h_twice)
#  define __complex_h_twice
#  undef __CFLOAT
#  define __CFLOAT float complex
#  undef __FLOAT
#  define __FLOAT float
#  undef __CFUNC
#  define __CFUNC(x) x##f
#endif /* complex_h_twice */


#ifndef __complex_h_once
#  define __complex_h_once

#  define complex _Complex
#  define _Complex_I ((float _Complex)__I__)

   /* imaginary types not supported in gnu mode */
#  if !defined(__GNUC__) && !defined(__ARM_NO_IMAGINARY_TYPE)
#    define imaginary _Imaginary
#    define _Imaginary_I ((float _Imaginary)__I__)
#    define I _Imaginary_I
#  else
#    define I _Complex_I
#  endif

#  define __CFLOAT double complex
#  define __FLOAT double
#  define __CFUNC(x) x

/* _ARMABI may have been defined by math.h */
#  ifndef _ARMABI
#    define _ARMABI __attribute__((nothrow))
#  endif

#endif /* __complex_h_once */


/* trigonometric */
extern _ARMABI __CFLOAT __CFUNC(cacos)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(casin)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(catan)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(ccos)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(csin)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(ctan)(__CFLOAT /*z*/);

/* hyperbolic */
extern _ARMABI __CFLOAT __CFUNC(cacosh)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(casinh)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(catanh)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(ccosh)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(csinh)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(ctanh)(__CFLOAT /*z*/);

/* exponential and logarithmic */
extern _ARMABI __CFLOAT __CFUNC(cexp)(__CFLOAT /*x*/);
extern _ARMABI __CFLOAT __CFUNC(clog)(__CFLOAT /*z*/);

/* power and absolute-value */
extern _ARMABI __FLOAT __CFUNC(cabs)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(cpow)(__CFLOAT /*x*/, __CFLOAT /*y*/);
extern _ARMABI __CFLOAT __CFUNC(csqrt)(__CFLOAT /*z*/);

/* manipulation */
extern _ARMABI __FLOAT __CFUNC(carg)(__CFLOAT /*z*/);
extern _ARMABI __FLOAT __CFUNC(cimag)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(conj)(__CFLOAT /*z*/);
extern _ARMABI __CFLOAT __CFUNC(cproj)(__CFLOAT /*z*/);
extern _ARMABI __FLOAT __CFUNC(creal)(__CFLOAT /*z*/);


#if defined(__complex_h_thrice)
#  define __complex_h
#  undef __CFUNC
#  undef __CFLOAT
#  undef __FLOAT
#else
#  include <complex.h>
#endif

#endif /* __complex_h */

/* end of complex.h */

