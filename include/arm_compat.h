/* arm_compat.h - Compatibility header for ARM Compiler 5 intrinsics */
/* Copyright (C) 2016 ARM Limited. All rights reserved. */

#ifndef __ARM_COMPAT_H
#define __ARM_COMPAT_H

#ifndef __ARM_ACLE
#include <arm_acle.h>
#endif

#ifdef __ARM_64BIT_STATE
   #error arm_compat.h is not supported when compiling for the A64 instruction set
#else

#if __ARM_ARCH >= 6 || (__ARM_ARCH == 5 && __ARM_ARCH_ISA_THUMB)
#define __breakpoint(v) __asm__ __volatile__ ("bkpt %0" : : "i"(v) )
#else /* __ARM_ARCH < 6 && (__ARM_ARCH != 5 || !__ARM_ARCH_ISA_THUMB) */
static __inline__ void __attribute__((unavailable(
    "intrinsic not supported for this architecture"))) __breakpoint(int val);
#endif

#define __current_pc()                                                         \
  __extension__({                                                              \
    register unsigned int pc __asm__("pc");                                    \
    __asm__ __volatile__("" : "=r"(pc));                                       \
    pc;                                                                        \
  })

#define __current_sp()                                                         \
  __extension__({                                                              \
    register unsigned int sp __asm__("sp");                                    \
    __asm__ __volatile__("" : "=r"(sp));                                       \
    sp;                                                                        \
  })

#if (defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M' &&                \
    __ARM_ARCH == 6) || __ARM_ARCH_8M_BASE__
static __inline__ unsigned int __attribute__((unavailable(
    "intrinsic not supported for this architecture"))) __disable_fiq(void);
#else // (!defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' ||
      // __ARM_ARCH != 6) && !__ARM_ARCH_8M_BASE__
static __inline__ unsigned int __attribute__((__always_inline__, __nodebug__))
__disable_fiq(void) {
  unsigned int cpsr;
#if defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M'
  __asm__ __volatile__("mrs %[cpsr], faultmask\n"
                       "cpsid f\n"
                       : [cpsr] "=r"(cpsr));
  return cpsr & 0x1;
#elif __ARM_ARCH >= 6 /* !defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' */
  __asm__ __volatile__("mrs %[cpsr], cpsr\n"
                       "cpsid f\n"
                       : [cpsr] "=r"(cpsr));
  return cpsr & 0x40;
#else /* __ARM_ARCH < 6 && !defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' */
  unsigned int tmp;
  __asm__ __volatile__(
          "mrs	%[cpsr], CPSR\n"
          "bic	%[tmp], %[cpsr], #0x40\n"
          "msr	CPSR_c, %[tmp]\n"
          : [tmp]"=r"(tmp), [cpsr]"=r"(cpsr));
  return cpsr & 0x40;
#endif
}
#endif

static __inline__ unsigned int __attribute__((__always_inline__, __nodebug__))
__disable_irq(void) {
  unsigned int cpsr;
#if __ARM_ARCH >= 6
#if defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M'
  __asm__ __volatile__("mrs %[cpsr], primask\n"
                       "cpsid i\n"
                       : [cpsr] "=r"(cpsr));
  return cpsr & 0x1;
#else /* !defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' */
  __asm__ __volatile__("mrs %[cpsr], cpsr\n"
                       "cpsid i\n"
                       : [cpsr] "=r"(cpsr));
  return cpsr & 0x80;
#endif
#else /* __ARM_ARCH < 6 */
  unsigned int tmp;
  __asm__ __volatile__(
          "mrs	%[cpsr], CPSR\n"
          "bic	%[tmp], %[cpsr], #0x80\n"
          "msr	CPSR_c, %[tmp]\n"
          : [tmp]"=r"(tmp), [cpsr]"=r"(cpsr));
  return cpsr & 0x80;
#endif
}

#if (defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M' &&                \
    __ARM_ARCH == 6) || __ARM_ARCH_8M_BASE__
static __inline__ void __attribute__((unavailable(
    "intrinsic not supported for this architecture"))) __enable_fiq(void);
#else // (!defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' ||
      // __ARM_ARCH != 6) && !__ARM_ARCH_8M_BASE__
static __inline__ void __attribute__((__always_inline__, __nodebug__))
__enable_fiq(void) {
#if __ARM_ARCH >= 6
  __asm__ __volatile__("cpsie f");
#else /* __ARM_ARCH < 6 */
  unsigned int tmp;
  __asm__ __volatile__(
          "mrs	%[tmp], CPSR\n"
          "bic	%[tmp], %[tmp], #0x40\n"
          "msr	CPSR_c, %[tmp]\n"
          : [tmp]"=r"(tmp));
#endif
}
#endif

static __inline__ void __attribute__((__always_inline__, __nodebug__))
__enable_irq(void) {
#if __ARM_ARCH >= 6
  __asm__ __volatile__("cpsie i");
#else /* __ARM_ARCH < 6 */
  unsigned int tmp;
  __asm__ __volatile__(
          "mrs	%[tmp], CPSR\n"
          "bic	%[tmp], %[tmp], #0x80\n"
          "msr	CPSR_c, %[tmp]\n"
          : [tmp]"=r"(tmp));
#endif
}

static __inline__ void __attribute__((__always_inline__, __nodebug__)) __force_stores(void) {
    __asm__ __volatile__ ("" : : : "memory", "cc");
}

static void  __attribute__((__always_inline__, __nodebug__)) __memory_changed(void) {
    __asm__ __volatile__ ("" : : : "memory", "cc");
}

static void  __attribute__((__always_inline__, __nodebug__)) __schedule_barrier(void) {
    __asm__ __volatile__ ("" : : : "memory", "cc");
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
__semihost(int val, const void *ptr) {
  register int v __asm__("r0") = val;
  register const void *p __asm__("r1") = ptr;
  __asm__ __volatile__(
#if defined(__thumb__)
#if defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M'
      "bkpt 0xab"
#else /* !defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' */
#if defined(__USE_HLT_SEMIHOSTING)
      ".inst.n 0xbabc"
#else
      "svc 0xab"
#endif
#endif
#else /* !defined(__thumb__) */
#if defined(__USE_HLT_SEMIHOSTING)
      ".inst 0xe10f0070"
#else
      "svc 0x123456"
#endif
#endif
      : "+r"(v), "+r"(p)
      :
      : "memory", "cc");
  return v;
}

#if defined(__ARM_FP)
static __inline__ unsigned int __attribute__((__always_inline__, __nodebug__))
__vfp_status(unsigned int mask, unsigned int flags) {
  unsigned int fpscr;
  __asm__ __volatile__("vmrs %[fpscr], fpscr" : [fpscr] "=r"(fpscr));
  unsigned int set = mask & flags;
  unsigned int clear = mask & ~flags;
  unsigned int toggle = ~mask & flags;
  fpscr |= set;
  fpscr &= ~clear;
  fpscr ^= toggle;
  __asm__ __volatile__("vmsr fpscr, %[fpscr]" : : [fpscr] "r"(fpscr));
  return fpscr;
}
#else /* !defined(__ARM_FP) */
static __inline__ unsigned int __attribute__((
    unavailable("intrinsic not supported for targets without floating point")))
__vfp_status(unsigned int mask, unsigned int flags);
#endif

#endif /* __ARM_64BIT_STATE */

#endif /* __ARM_COMPAT_H */

