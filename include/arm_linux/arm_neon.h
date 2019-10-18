

/* arm_neon.h
 *
 * Copyright 2005 ARM Limited. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 * $Id$
 * $URL: $
 *
 * Note: this file is auto-generated from neon_intrinsics_spec.xml
 */

#ifndef __NEON_H_
#define __NEON_H_

#ifdef __cplusplus
#define __STDC_LIMIT_MACROS 1
#define __STDC_FORMAT_MACROS 1
#define __STDC_CONSTANT_MACROS 1
#endif
#include <stdint.h>
/* typedef double quad; */
#if (defined(__ARM_64BIT_STATE) || defined(__TARGET_ARCH_AARCH64))
#define SIMD128_ALIGN __attribute__((aligned(16)))
#else
#define SIMD128_ALIGN
#endif

#define __MKVECTORSTRUCT64(T,N,T2) struct __simd64_##T { double __private; }; \
                                struct __library_simd64_##T { T2 a[N]; }
#define __MKVECTORSTRUCT128(T,N,T2) struct __simd128_##T { SIMD128_ALIGN double __private1; \
                                                         double __private2; }; \
                                 struct __library_simd128_##T { T2 a[N]; }

#ifdef __BUILDING_NEON_LIBRARY
#define __VECTORSTRUCT64(T,N) struct __library_simd64_##T
#define __VECTORSTRUCT128(T,N) struct __library_simd128_##T
#else
#define __VECTORSTRUCT64(T,N) struct __simd64_##T
#define __VECTORSTRUCT128(T,N) struct __simd128_##T
#endif

/* annotate type argument which must be compile time constant */
#define __constrange(min,max)
#define __transfersize(size)

#ifdef __CC_ARM
#define __VALUE_IN_REGS __value_in_regs
#define __PURE __pure
#else
#define __VALUE_IN_REGS
#define __PURE
#endif

#ifdef __cplusplus
#define __EXTERNC extern "C"
#else
#define __EXTERNC
#endif

/* generate the vector type definitions */
typedef uint8_t poly8_t;
typedef uint16_t poly16_t;
typedef uint64_t poly64_t;
typedef uint32_t __encoding_t;
typedef float float32_t;
typedef double float64_t;

#define __VECNAME(vs, t, l) t##x##l##_t

#define __VECTOR64int(typ, l, typ2) __MKVECTORSTRUCT64(typ##_t, l, typ2); \
                           typedef __VECTORSTRUCT64(typ##_t, l) __VECNAME(64,typ,l)
#define __VECTOR128int(typ, l,typ2) __MKVECTORSTRUCT128(typ##_t, l, typ2); \
                            typedef __VECTORSTRUCT128(typ##_t, l) __VECNAME(128,typ,l)

#define __VECTOR64(T,L) __VECTOR64int(T,L,T ## _t)
#define __VECTOR128(T,L) __VECTOR128int(T,L,T ## _t)

#if (!defined(__TARGET_FEATURE_NEON_FP16) || !defined(__ARM_FP16))
#define __ARM_NEON_FP16_INTRINSICS 0
#else
#define __ARM_NEON_FP16_INTRINSICS 1
#endif

__VECTOR64(int8,     8);
__VECTOR64(int16,    4);
__VECTOR64(int32,    2);
__VECTOR64(int64,    1);
__VECTOR64(uint8,    8);
__VECTOR64(uint16,   4);
__VECTOR64(uint32,   2);
__VECTOR64(uint64,   1);
__VECTOR64(float32,  2);
__VECTOR64(float64,  1);
__VECTOR64(poly8,    8);
__VECTOR64(poly16,   4);
__VECTOR64(poly64,   1);
__VECTOR128(int8,   16);
__VECTOR128(int16,   8);
__VECTOR128(int32,   4);
__VECTOR128(int64,   2);
__VECTOR128(uint8,  16);
__VECTOR128(uint16,  8);
__VECTOR128(uint32,  4);
__VECTOR128(uint64,  2);
__VECTOR128(float32, 4);
__VECTOR128(float64, 2);
__VECTOR128(poly8,  16);
__VECTOR128(poly16,  8);
__VECTOR128(poly64,  2);

#if defined (__ARM_FP16)
__VECTOR64int(float16,  4, __fp16);
__VECTOR128int(float16, 8, __fp16);
#endif

#define __ARRAYNAME(N, V, T, L) T##x##L##x##N##_t


#define __MKARRAYSTRUCT(N, V, T, L) \
   struct __simd_array##N##_##T##x##L##_t { struct __simd##V##_##T##_t val[N]; }; \
   struct __library_simd_array##N##_##T##x##L##_t { struct __library_simd##V##_##T##_t val[N]; }; \


#ifdef __BUILDING_NEON_LIBRARY
#define __ARRAYSTRUCT(N, V, T, L) struct __library_simd_array##N##_##T##x##L##_t
#else
#define __ARRAYSTRUCT(N, V, T, L) struct __simd_array##N##_##T##x##L##_t
#endif

#define __ARRAY(N, V, T, L) __MKARRAYSTRUCT(N,V,T,L) typedef __ARRAYSTRUCT(N,V,T,L) __ARRAYNAME(N,V,T,L)
#define __ALLARRAYS(V,T,L) \
    __ARRAY(2,V,T,L); \
    __ARRAY(3,V,T,L); \
    __ARRAY(4,V,T,L);

__ALLARRAYS(64,  poly8,   8)
__ALLARRAYS(128, poly8,  16)
__ALLARRAYS(64,  poly16,  4)
__ALLARRAYS(128, poly16,  8)
__ALLARRAYS(64,  poly64,  1)
__ALLARRAYS(128, poly64,  2)
__ALLARRAYS(64,  float32, 2)
__ALLARRAYS(128, float32, 4)
__ALLARRAYS(64,  float64, 1)
__ALLARRAYS(128, float64, 2)
#if defined(__ARM_FP16)
__ALLARRAYS(64,  float16, 4)
__ALLARRAYS(128, float16, 8)
#endif
__ALLARRAYS(64,  int8,    8)
__ALLARRAYS(128, int8,   16)
__ALLARRAYS(64,  int16,   4)
__ALLARRAYS(128, int16,   8)
__ALLARRAYS(64,  int32,   2)
__ALLARRAYS(128, int32,   4)
__ALLARRAYS(64,  int64,   1)
__ALLARRAYS(128, int64,   2)
__ALLARRAYS(64,  uint8,   8)
__ALLARRAYS(128, uint8,  16)
__ALLARRAYS(64,  uint16 , 4)
__ALLARRAYS(128, uint16,  8)
__ALLARRAYS(64,  uint32,  2)
__ALLARRAYS(128, uint32,  4)
__ALLARRAYS(64,  uint64,  1)
__ALLARRAYS(128, uint64,  2)



#ifdef __TARGET_FEATURE_NEON
#define vadd_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000800) /* VADD.I8 d0,d0,d0 */
#define vadd_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100800) /* VADD.I16 d0,d0,d0 */
#define vadd_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200800) /* VADD.I32 d0,d0,d0 */
#define vadd_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300800) /* VADD.I64 d0,d0,d0 */
#define vadd_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf2000d00) /* VADD.F32 d0,d0,d0 */
#define vadd_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2000800) /* VADD.I8 d0,d0,d0 */
#define vadd_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2100800) /* VADD.I16 d0,d0,d0 */
#define vadd_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2200800) /* VADD.I32 d0,d0,d0 */
#define vadd_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf2300800) /* VADD.I64 d0,d0,d0 */
#define vaddq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000840) /* VADD.I8 q0,q0,q0 */
#define vaddq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100840) /* VADD.I16 q0,q0,q0 */
#define vaddq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200840) /* VADD.I32 q0,q0,q0 */
#define vaddq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300840) /* VADD.I64 q0,q0,q0 */
#define vaddq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf2000d40) /* VADD.F32 q0,q0,q0 */
#define vaddq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf2000840) /* VADD.I8 q0,q0,q0 */
#define vaddq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf2100840) /* VADD.I16 q0,q0,q0 */
#define vaddq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf2200840) /* VADD.I32 q0,q0,q0 */
#define vaddq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf2300840) /* VADD.I64 q0,q0,q0 */
#define vaddl_s8(a,b) __ndp4_wrr_qdd_s16_s8((a),(b),0xf2800000) /* VADDL.S8 q0,d0,d0 */
#define vaddl_s16(a,b) __ndp4_wrr_qdd_s32_s16((a),(b),0xf2900000) /* VADDL.S16 q0,d0,d0 */
#define vaddl_s32(a,b) __ndp4_wrr_qdd_s64_s32((a),(b),0xf2a00000) /* VADDL.S32 q0,d0,d0 */
#define vaddl_u8(a,b) __ndp4_wrr_qdd_u16_u8((a),(b),0xf3800000) /* VADDL.U8 q0,d0,d0 */
#define vaddl_u16(a,b) __ndp4_wrr_qdd_u32_u16((a),(b),0xf3900000) /* VADDL.U16 q0,d0,d0 */
#define vaddl_u32(a,b) __ndp4_wrr_qdd_u64_u32((a),(b),0xf3a00000) /* VADDL.U32 q0,d0,d0 */
#define vaddw_s8(a,b) __ndp4_wrr_qqd_s16_s16_s8((a),(b),0xf2800100) /* VADDW.S8 q0,q0,d0 */
#define vaddw_s16(a,b) __ndp4_wrr_qqd_s32_s32_s16((a),(b),0xf2900100) /* VADDW.S16 q0,q0,d0 */
#define vaddw_s32(a,b) __ndp4_wrr_qqd_s64_s64_s32((a),(b),0xf2a00100) /* VADDW.S32 q0,q0,d0 */
#define vaddw_u8(a,b) __ndp4_wrr_qqd_u16_u16_u8((a),(b),0xf3800100) /* VADDW.U8 q0,q0,d0 */
#define vaddw_u16(a,b) __ndp4_wrr_qqd_u32_u32_u16((a),(b),0xf3900100) /* VADDW.U16 q0,q0,d0 */
#define vaddw_u32(a,b) __ndp4_wrr_qqd_u64_u64_u32((a),(b),0xf3a00100) /* VADDW.U32 q0,q0,d0 */
#define vhadd_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000000) /* VHADD.S8 d0,d0,d0 */
#define vhadd_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100000) /* VHADD.S16 d0,d0,d0 */
#define vhadd_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200000) /* VHADD.S32 d0,d0,d0 */
#define vhadd_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000000) /* VHADD.U8 d0,d0,d0 */
#define vhadd_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100000) /* VHADD.U16 d0,d0,d0 */
#define vhadd_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200000) /* VHADD.U32 d0,d0,d0 */
#define vhaddq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000040) /* VHADD.S8 q0,q0,q0 */
#define vhaddq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100040) /* VHADD.S16 q0,q0,q0 */
#define vhaddq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200040) /* VHADD.S32 q0,q0,q0 */
#define vhaddq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000040) /* VHADD.U8 q0,q0,q0 */
#define vhaddq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100040) /* VHADD.U16 q0,q0,q0 */
#define vhaddq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200040) /* VHADD.U32 q0,q0,q0 */
#define vrhadd_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000100) /* VRHADD.S8 d0,d0,d0 */
#define vrhadd_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100100) /* VRHADD.S16 d0,d0,d0 */
#define vrhadd_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200100) /* VRHADD.S32 d0,d0,d0 */
#define vrhadd_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000100) /* VRHADD.U8 d0,d0,d0 */
#define vrhadd_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100100) /* VRHADD.U16 d0,d0,d0 */
#define vrhadd_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200100) /* VRHADD.U32 d0,d0,d0 */
#define vrhaddq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000140) /* VRHADD.S8 q0,q0,q0 */
#define vrhaddq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100140) /* VRHADD.S16 q0,q0,q0 */
#define vrhaddq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200140) /* VRHADD.S32 q0,q0,q0 */
#define vrhaddq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000140) /* VRHADD.U8 q0,q0,q0 */
#define vrhaddq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100140) /* VRHADD.U16 q0,q0,q0 */
#define vrhaddq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200140) /* VRHADD.U32 q0,q0,q0 */
#define vqadd_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000010) /* VQADD.S8 d0,d0,d0 */
#define vqadd_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100010) /* VQADD.S16 d0,d0,d0 */
#define vqadd_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200010) /* VQADD.S32 d0,d0,d0 */
#define vqadd_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300010) /* VQADD.S64 d0,d0,d0 */
#define vqadd_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000010) /* VQADD.U8 d0,d0,d0 */
#define vqadd_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100010) /* VQADD.U16 d0,d0,d0 */
#define vqadd_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200010) /* VQADD.U32 d0,d0,d0 */
#define vqadd_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf3300010) /* VQADD.U64 d0,d0,d0 */
#define vqaddq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000050) /* VQADD.S8 q0,q0,q0 */
#define vqaddq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100050) /* VQADD.S16 q0,q0,q0 */
#define vqaddq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200050) /* VQADD.S32 q0,q0,q0 */
#define vqaddq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300050) /* VQADD.S64 q0,q0,q0 */
#define vqaddq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000050) /* VQADD.U8 q0,q0,q0 */
#define vqaddq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100050) /* VQADD.U16 q0,q0,q0 */
#define vqaddq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200050) /* VQADD.U32 q0,q0,q0 */
#define vqaddq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf3300050) /* VQADD.U64 q0,q0,q0 */
#define vaddhn_s16(a,b) __ndp4_wrr_dqq_s8_s16((a),(b),0xf2800400) /* VADDHN.I16 d0,q0,q0 */
#define vaddhn_s32(a,b) __ndp4_wrr_dqq_s16_s32((a),(b),0xf2900400) /* VADDHN.I32 d0,q0,q0 */
#define vaddhn_s64(a,b) __ndp4_wrr_dqq_s32_s64((a),(b),0xf2a00400) /* VADDHN.I64 d0,q0,q0 */
#define vaddhn_u16(a,b) __ndp4_wrr_dqq_u8_u16((a),(b),0xf2800400) /* VADDHN.I16 d0,q0,q0 */
#define vaddhn_u32(a,b) __ndp4_wrr_dqq_u16_u32((a),(b),0xf2900400) /* VADDHN.I32 d0,q0,q0 */
#define vaddhn_u64(a,b) __ndp4_wrr_dqq_u32_u64((a),(b),0xf2a00400) /* VADDHN.I64 d0,q0,q0 */
#define vraddhn_s16(a,b) __ndp4_wrr_dqq_s8_s16((a),(b),0xf3800400) /* VRADDHN.I16 d0,q0,q0 */
#define vraddhn_s32(a,b) __ndp4_wrr_dqq_s16_s32((a),(b),0xf3900400) /* VRADDHN.I32 d0,q0,q0 */
#define vraddhn_s64(a,b) __ndp4_wrr_dqq_s32_s64((a),(b),0xf3a00400) /* VRADDHN.I64 d0,q0,q0 */
#define vraddhn_u16(a,b) __ndp4_wrr_dqq_u8_u16((a),(b),0xf3800400) /* VRADDHN.I16 d0,q0,q0 */
#define vraddhn_u32(a,b) __ndp4_wrr_dqq_u16_u32((a),(b),0xf3900400) /* VRADDHN.I32 d0,q0,q0 */
#define vraddhn_u64(a,b) __ndp4_wrr_dqq_u32_u64((a),(b),0xf3a00400) /* VRADDHN.I64 d0,q0,q0 */
#define vmul_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000910) /* VMUL.I8 d0,d0,d0 */
#define vmul_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100910) /* VMUL.I16 d0,d0,d0 */
#define vmul_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200910) /* VMUL.I32 d0,d0,d0 */
#define vmul_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf3000d10) /* VMUL.F32 d0,d0,d0 */
#define vmul_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2000910) /* VMUL.I8 d0,d0,d0 */
#define vmul_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2100910) /* VMUL.I16 d0,d0,d0 */
#define vmul_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2200910) /* VMUL.I32 d0,d0,d0 */
#define vmul_p8(a,b) __ndp1_wrr_ddd_p8((a),(b),0xf3000910) /* VMUL.P8 d0,d0,d0 */
#define vmulq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000950) /* VMUL.I8 q0,q0,q0 */
#define vmulq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100950) /* VMUL.I16 q0,q0,q0 */
#define vmulq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200950) /* VMUL.I32 q0,q0,q0 */
#define vmulq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf3000d50) /* VMUL.F32 q0,q0,q0 */
#define vmulq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf2000950) /* VMUL.I8 q0,q0,q0 */
#define vmulq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf2100950) /* VMUL.I16 q0,q0,q0 */
#define vmulq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf2200950) /* VMUL.I32 q0,q0,q0 */
#define vmulq_p8(a,b) __ndp1_wrr_qqq_p8((a),(b),0xf3000950) /* VMUL.P8 q0,q0,q0 */
#define vmla_s8(a,b,c) __ndp1_xrr_ddd_s8((a),(b),(c),0xf2000900) /* VMLA.I8 d0,d0,d0 */
#define vmla_s16(a,b,c) __ndp1_xrr_ddd_s16((a),(b),(c),0xf2100900) /* VMLA.I16 d0,d0,d0 */
#define vmla_s32(a,b,c) __ndp1_xrr_ddd_s32((a),(b),(c),0xf2200900) /* VMLA.I32 d0,d0,d0 */
#define vmla_u8(a,b,c) __ndp1_xrr_ddd_u8((a),(b),(c),0xf2000900) /* VMLA.I8 d0,d0,d0 */
#define vmla_u16(a,b,c) __ndp1_xrr_ddd_u16((a),(b),(c),0xf2100900) /* VMLA.I16 d0,d0,d0 */
#define vmla_u32(a,b,c) __ndp1_xrr_ddd_u32((a),(b),(c),0xf2200900) /* VMLA.I32 d0,d0,d0 */
#define vmlaq_s8(a,b,c) __ndp1_xrr_qqq_s8((a),(b),(c),0xf2000940) /* VMLA.I8 q0,q0,q0 */
#define vmlaq_s16(a,b,c) __ndp1_xrr_qqq_s16((a),(b),(c),0xf2100940) /* VMLA.I16 q0,q0,q0 */
#define vmlaq_s32(a,b,c) __ndp1_xrr_qqq_s32((a),(b),(c),0xf2200940) /* VMLA.I32 q0,q0,q0 */
#define vmlaq_u8(a,b,c) __ndp1_xrr_qqq_u8((a),(b),(c),0xf2000940) /* VMLA.I8 q0,q0,q0 */
#define vmlaq_u16(a,b,c) __ndp1_xrr_qqq_u16((a),(b),(c),0xf2100940) /* VMLA.I16 q0,q0,q0 */
#define vmlaq_u32(a,b,c) __ndp1_xrr_qqq_u32((a),(b),(c),0xf2200940) /* VMLA.I32 q0,q0,q0 */
#define vmla_f32(a,b,c) __ndp1_xrr_ddd_f32((a),(b),(c),0xf2000d10) /* VMLA.F32 d0,d0,d0 */
#define vmlaq_f32(a,b,c) __ndp1_xrr_qqq_f32((a),(b),(c),0xf2000d50) /* VMLA.F32 q0,q0,q0 */
#define vmlal_s8(a,b,c) __ndp4_xrr_qdd_s16_s16_s8((a),(b),(c),0xf2800800) /* VMLAL.S8 q0,d0,d0 */
#define vmlal_s16(a,b,c) __ndp4_xrr_qdd_s32_s32_s16((a),(b),(c),0xf2900800) /* VMLAL.S16 q0,d0,d0 */
#define vmlal_s32(a,b,c) __ndp4_xrr_qdd_s64_s64_s32((a),(b),(c),0xf2a00800) /* VMLAL.S32 q0,d0,d0 */
#define vmlal_u8(a,b,c) __ndp4_xrr_qdd_u16_u16_u8((a),(b),(c),0xf3800800) /* VMLAL.U8 q0,d0,d0 */
#define vmlal_u16(a,b,c) __ndp4_xrr_qdd_u32_u32_u16((a),(b),(c),0xf3900800) /* VMLAL.U16 q0,d0,d0 */
#define vmlal_u32(a,b,c) __ndp4_xrr_qdd_u64_u64_u32((a),(b),(c),0xf3a00800) /* VMLAL.U32 q0,d0,d0 */
#define vmls_s8(a,b,c) __ndp1_xrr_ddd_s8((a),(b),(c),0xf3000900) /* VMLS.I8 d0,d0,d0 */
#define vmls_s16(a,b,c) __ndp1_xrr_ddd_s16((a),(b),(c),0xf3100900) /* VMLS.I16 d0,d0,d0 */
#define vmls_s32(a,b,c) __ndp1_xrr_ddd_s32((a),(b),(c),0xf3200900) /* VMLS.I32 d0,d0,d0 */
#define vmls_u8(a,b,c) __ndp1_xrr_ddd_u8((a),(b),(c),0xf3000900) /* VMLS.I8 d0,d0,d0 */
#define vmls_u16(a,b,c) __ndp1_xrr_ddd_u16((a),(b),(c),0xf3100900) /* VMLS.I16 d0,d0,d0 */
#define vmls_u32(a,b,c) __ndp1_xrr_ddd_u32((a),(b),(c),0xf3200900) /* VMLS.I32 d0,d0,d0 */
#define vmlsq_s8(a,b,c) __ndp1_xrr_qqq_s8((a),(b),(c),0xf3000940) /* VMLS.I8 q0,q0,q0 */
#define vmlsq_s16(a,b,c) __ndp1_xrr_qqq_s16((a),(b),(c),0xf3100940) /* VMLS.I16 q0,q0,q0 */
#define vmlsq_s32(a,b,c) __ndp1_xrr_qqq_s32((a),(b),(c),0xf3200940) /* VMLS.I32 q0,q0,q0 */
#define vmlsq_u8(a,b,c) __ndp1_xrr_qqq_u8((a),(b),(c),0xf3000940) /* VMLS.I8 q0,q0,q0 */
#define vmlsq_u16(a,b,c) __ndp1_xrr_qqq_u16((a),(b),(c),0xf3100940) /* VMLS.I16 q0,q0,q0 */
#define vmlsq_u32(a,b,c) __ndp1_xrr_qqq_u32((a),(b),(c),0xf3200940) /* VMLS.I32 q0,q0,q0 */
#define vmls_f32(a,b,c) __ndp1_xrr_ddd_f32((a),(b),(c),0xf2200d10) /* VMLS.F32 d0,d0,d0 */
#define vmlsq_f32(a,b,c) __ndp1_xrr_qqq_f32((a),(b),(c),0xf2200d50) /* VMLS.F32 q0,q0,q0 */
#define vmlsl_s8(a,b,c) __ndp4_xrr_qdd_s16_s16_s8((a),(b),(c),0xf2800a00) /* VMLSL.S8 q0,d0,d0 */
#define vmlsl_s16(a,b,c) __ndp4_xrr_qdd_s32_s32_s16((a),(b),(c),0xf2900a00) /* VMLSL.S16 q0,d0,d0 */
#define vmlsl_s32(a,b,c) __ndp4_xrr_qdd_s64_s64_s32((a),(b),(c),0xf2a00a00) /* VMLSL.S32 q0,d0,d0 */
#define vmlsl_u8(a,b,c) __ndp4_xrr_qdd_u16_u16_u8((a),(b),(c),0xf3800a00) /* VMLSL.U8 q0,d0,d0 */
#define vmlsl_u16(a,b,c) __ndp4_xrr_qdd_u32_u32_u16((a),(b),(c),0xf3900a00) /* VMLSL.U16 q0,d0,d0 */
#define vmlsl_u32(a,b,c) __ndp4_xrr_qdd_u64_u64_u32((a),(b),(c),0xf3a00a00) /* VMLSL.U32 q0,d0,d0 */
#define vqdmulh_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100b00) /* VQDMULH.S16 d0,d0,d0 */
#define vqdmulh_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200b00) /* VQDMULH.S32 d0,d0,d0 */
#define vqdmulhq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100b40) /* VQDMULH.S16 q0,q0,q0 */
#define vqdmulhq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200b40) /* VQDMULH.S32 q0,q0,q0 */
#define vqrdmulh_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf3100b00) /* VQRDMULH.S16 d0,d0,d0 */
#define vqrdmulh_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf3200b00) /* VQRDMULH.S32 d0,d0,d0 */
#define vqrdmulhq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf3100b40) /* VQRDMULH.S16 q0,q0,q0 */
#define vqrdmulhq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf3200b40) /* VQRDMULH.S32 q0,q0,q0 */
#define vqdmlal_s16(a,b,c) __ndp4_xrr_qdd_s32_s32_s16((a),(b),(c),0xf2900900) /* VQDMLAL.S16 q0,d0,d0 */
#define vqdmlal_s32(a,b,c) __ndp4_xrr_qdd_s64_s64_s32((a),(b),(c),0xf2a00900) /* VQDMLAL.S32 q0,d0,d0 */
#define vqdmlsl_s16(a,b,c) __ndp4_xrr_qdd_s32_s32_s16((a),(b),(c),0xf2900b00) /* VQDMLSL.S16 q0,d0,d0 */
#define vqdmlsl_s32(a,b,c) __ndp4_xrr_qdd_s64_s64_s32((a),(b),(c),0xf2a00b00) /* VQDMLSL.S32 q0,d0,d0 */
#define vmull_s8(a,b) __ndp4_wrr_qdd_s16_s8((a),(b),0xf2800c00) /* VMULL.S8 q0,d0,d0 */
#define vmull_s16(a,b) __ndp4_wrr_qdd_s32_s16((a),(b),0xf2900c00) /* VMULL.S16 q0,d0,d0 */
#define vmull_s32(a,b) __ndp4_wrr_qdd_s64_s32((a),(b),0xf2a00c00) /* VMULL.S32 q0,d0,d0 */
#define vmull_u8(a,b) __ndp4_wrr_qdd_u16_u8((a),(b),0xf3800c00) /* VMULL.U8 q0,d0,d0 */
#define vmull_u16(a,b) __ndp4_wrr_qdd_u32_u16((a),(b),0xf3900c00) /* VMULL.U16 q0,d0,d0 */
#define vmull_u32(a,b) __ndp4_wrr_qdd_u64_u32((a),(b),0xf3a00c00) /* VMULL.U32 q0,d0,d0 */
#define vmull_p8(a,b) __ndp4_wrr_qdd_p16_p8((a),(b),0xf2800e00) /* VMULL.P8 q0,d0,d0 */
#define vqdmull_s16(a,b) __ndp4_wrr_qdd_s32_s16((a),(b),0xf2900d00) /* VQDMULL.S16 q0,d0,d0 */
#define vqdmull_s32(a,b) __ndp4_wrr_qdd_s64_s32((a),(b),0xf2a00d00) /* VQDMULL.S32 q0,d0,d0 */
#define vsub_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf3000800) /* VSUB.I8 d0,d0,d0 */
#define vsub_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf3100800) /* VSUB.I16 d0,d0,d0 */
#define vsub_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf3200800) /* VSUB.I32 d0,d0,d0 */
#define vsub_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf3300800) /* VSUB.I64 d0,d0,d0 */
#define vsub_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf2200d00) /* VSUB.F32 d0,d0,d0 */
#define vsub_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000800) /* VSUB.I8 d0,d0,d0 */
#define vsub_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100800) /* VSUB.I16 d0,d0,d0 */
#define vsub_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200800) /* VSUB.I32 d0,d0,d0 */
#define vsub_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf3300800) /* VSUB.I64 d0,d0,d0 */
#define vsubq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf3000840) /* VSUB.I8 q0,q0,q0 */
#define vsubq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf3100840) /* VSUB.I16 q0,q0,q0 */
#define vsubq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf3200840) /* VSUB.I32 q0,q0,q0 */
#define vsubq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf3300840) /* VSUB.I64 q0,q0,q0 */
#define vsubq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf2200d40) /* VSUB.F32 q0,q0,q0 */
#define vsubq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000840) /* VSUB.I8 q0,q0,q0 */
#define vsubq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100840) /* VSUB.I16 q0,q0,q0 */
#define vsubq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200840) /* VSUB.I32 q0,q0,q0 */
#define vsubq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf3300840) /* VSUB.I64 q0,q0,q0 */
#define vsubl_s8(a,b) __ndp4_wrr_qdd_s16_s8((a),(b),0xf2800200) /* VSUBL.S8 q0,d0,d0 */
#define vsubl_s16(a,b) __ndp4_wrr_qdd_s32_s16((a),(b),0xf2900200) /* VSUBL.S16 q0,d0,d0 */
#define vsubl_s32(a,b) __ndp4_wrr_qdd_s64_s32((a),(b),0xf2a00200) /* VSUBL.S32 q0,d0,d0 */
#define vsubl_u8(a,b) __ndp4_wrr_qdd_u16_u8((a),(b),0xf3800200) /* VSUBL.U8 q0,d0,d0 */
#define vsubl_u16(a,b) __ndp4_wrr_qdd_u32_u16((a),(b),0xf3900200) /* VSUBL.U16 q0,d0,d0 */
#define vsubl_u32(a,b) __ndp4_wrr_qdd_u64_u32((a),(b),0xf3a00200) /* VSUBL.U32 q0,d0,d0 */
#define vsubw_s8(a,b) __ndp4_wrr_qqd_s16_s16_s8((a),(b),0xf2800300) /* VSUBW.S8 q0,q0,d0 */
#define vsubw_s16(a,b) __ndp4_wrr_qqd_s32_s32_s16((a),(b),0xf2900300) /* VSUBW.S16 q0,q0,d0 */
#define vsubw_s32(a,b) __ndp4_wrr_qqd_s64_s64_s32((a),(b),0xf2a00300) /* VSUBW.S32 q0,q0,d0 */
#define vsubw_u8(a,b) __ndp4_wrr_qqd_u16_u16_u8((a),(b),0xf3800300) /* VSUBW.U8 q0,q0,d0 */
#define vsubw_u16(a,b) __ndp4_wrr_qqd_u32_u32_u16((a),(b),0xf3900300) /* VSUBW.U16 q0,q0,d0 */
#define vsubw_u32(a,b) __ndp4_wrr_qqd_u64_u64_u32((a),(b),0xf3a00300) /* VSUBW.U32 q0,q0,d0 */
#define vqsub_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000210) /* VQSUB.S8 d0,d0,d0 */
#define vqsub_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100210) /* VQSUB.S16 d0,d0,d0 */
#define vqsub_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200210) /* VQSUB.S32 d0,d0,d0 */
#define vqsub_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300210) /* VQSUB.S64 d0,d0,d0 */
#define vqsub_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000210) /* VQSUB.U8 d0,d0,d0 */
#define vqsub_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100210) /* VQSUB.U16 d0,d0,d0 */
#define vqsub_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200210) /* VQSUB.U32 d0,d0,d0 */
#define vqsub_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf3300210) /* VQSUB.U64 d0,d0,d0 */
#define vqsubq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000250) /* VQSUB.S8 q0,q0,q0 */
#define vqsubq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100250) /* VQSUB.S16 q0,q0,q0 */
#define vqsubq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200250) /* VQSUB.S32 q0,q0,q0 */
#define vqsubq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300250) /* VQSUB.S64 q0,q0,q0 */
#define vqsubq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000250) /* VQSUB.U8 q0,q0,q0 */
#define vqsubq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100250) /* VQSUB.U16 q0,q0,q0 */
#define vqsubq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200250) /* VQSUB.U32 q0,q0,q0 */
#define vqsubq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf3300250) /* VQSUB.U64 q0,q0,q0 */
#define vhsub_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000200) /* VHSUB.S8 d0,d0,d0 */
#define vhsub_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100200) /* VHSUB.S16 d0,d0,d0 */
#define vhsub_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200200) /* VHSUB.S32 d0,d0,d0 */
#define vhsub_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000200) /* VHSUB.U8 d0,d0,d0 */
#define vhsub_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100200) /* VHSUB.U16 d0,d0,d0 */
#define vhsub_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200200) /* VHSUB.U32 d0,d0,d0 */
#define vhsubq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000240) /* VHSUB.S8 q0,q0,q0 */
#define vhsubq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100240) /* VHSUB.S16 q0,q0,q0 */
#define vhsubq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200240) /* VHSUB.S32 q0,q0,q0 */
#define vhsubq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000240) /* VHSUB.U8 q0,q0,q0 */
#define vhsubq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100240) /* VHSUB.U16 q0,q0,q0 */
#define vhsubq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200240) /* VHSUB.U32 q0,q0,q0 */
#define vsubhn_s16(a,b) __ndp4_wrr_dqq_s8_s16((a),(b),0xf2800600) /* VSUBHN.I16 d0,q0,q0 */
#define vsubhn_s32(a,b) __ndp4_wrr_dqq_s16_s32((a),(b),0xf2900600) /* VSUBHN.I32 d0,q0,q0 */
#define vsubhn_s64(a,b) __ndp4_wrr_dqq_s32_s64((a),(b),0xf2a00600) /* VSUBHN.I64 d0,q0,q0 */
#define vsubhn_u16(a,b) __ndp4_wrr_dqq_u8_u16((a),(b),0xf2800600) /* VSUBHN.I16 d0,q0,q0 */
#define vsubhn_u32(a,b) __ndp4_wrr_dqq_u16_u32((a),(b),0xf2900600) /* VSUBHN.I32 d0,q0,q0 */
#define vsubhn_u64(a,b) __ndp4_wrr_dqq_u32_u64((a),(b),0xf2a00600) /* VSUBHN.I64 d0,q0,q0 */
#define vrsubhn_s16(a,b) __ndp4_wrr_dqq_s8_s16((a),(b),0xf3800600) /* VRSUBHN.I16 d0,q0,q0 */
#define vrsubhn_s32(a,b) __ndp4_wrr_dqq_s16_s32((a),(b),0xf3900600) /* VRSUBHN.I32 d0,q0,q0 */
#define vrsubhn_s64(a,b) __ndp4_wrr_dqq_s32_s64((a),(b),0xf3a00600) /* VRSUBHN.I64 d0,q0,q0 */
#define vrsubhn_u16(a,b) __ndp4_wrr_dqq_u8_u16((a),(b),0xf3800600) /* VRSUBHN.I16 d0,q0,q0 */
#define vrsubhn_u32(a,b) __ndp4_wrr_dqq_u16_u32((a),(b),0xf3900600) /* VRSUBHN.I32 d0,q0,q0 */
#define vrsubhn_u64(a,b) __ndp4_wrr_dqq_u32_u64((a),(b),0xf3a00600) /* VRSUBHN.I64 d0,q0,q0 */
#define vceq_s8(a,b) __ndp1_wrr_ddd_u8_s8((a),(b),0xf3000810) /* VCEQ.I8 d0, d0, d0 */
#define vceq_s16(a,b) __ndp1_wrr_ddd_u16_s16((a),(b),0xf3100810) /* VCEQ.I16 d0, d0, d0 */
#define vceq_s32(a,b) __ndp1_wrr_ddd_u32_s32((a),(b),0xf3200810) /* VCEQ.I32 d0, d0, d0 */
#define vceq_f32(a,b) __ndp1_wrr_ddd_u32_f32((a),(b),0xf2000e00) /* VCEQ.F32 d0, d0, d0 */
#define vceq_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000810) /* VCEQ.I8 d0, d0, d0 */
#define vceq_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100810) /* VCEQ.I16 d0, d0, d0 */
#define vceq_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200810) /* VCEQ.I32 d0, d0, d0 */
#define vceq_p8(a,b) __ndp1_wrr_ddd_u8_p8((a),(b),0xf3000810) /* VCEQ.I8 d0, d0, d0 */
#define vceqq_s8(a,b) __ndp1_wrr_qqq_u8_s8((a),(b),0xf3000850) /* VCEQ.I8 q0, q0, q0 */
#define vceqq_s16(a,b) __ndp1_wrr_qqq_u16_s16((a),(b),0xf3100850) /* VCEQ.I16 q0, q0, q0 */
#define vceqq_s32(a,b) __ndp1_wrr_qqq_u32_s32((a),(b),0xf3200850) /* VCEQ.I32 q0, q0, q0 */
#define vceqq_f32(a,b) __ndp1_wrr_qqq_u32_f32((a),(b),0xf2000e40) /* VCEQ.F32 q0, q0, q0 */
#define vceqq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000850) /* VCEQ.I8 q0, q0, q0 */
#define vceqq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100850) /* VCEQ.I16 q0, q0, q0 */
#define vceqq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200850) /* VCEQ.I32 q0, q0, q0 */
#define vceqq_p8(a,b) __ndp1_wrr_qqq_u8_p8((a),(b),0xf3000850) /* VCEQ.I8 q0, q0, q0 */
#define vcge_s8(a,b) __ndp1_wrr_ddd_u8_s8((a),(b),0xf2000310) /* VCGE.S8 d0, d0, d0 */
#define vcge_s16(a,b) __ndp1_wrr_ddd_u16_s16((a),(b),0xf2100310) /* VCGE.S16 d0, d0, d0 */
#define vcge_s32(a,b) __ndp1_wrr_ddd_u32_s32((a),(b),0xf2200310) /* VCGE.S32 d0, d0, d0 */
#define vcge_f32(a,b) __ndp1_wrr_ddd_u32_f32((a),(b),0xf3000e00) /* VCGE.F32 d0, d0, d0 */
#define vcge_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000310) /* VCGE.U8 d0, d0, d0 */
#define vcge_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100310) /* VCGE.U16 d0, d0, d0 */
#define vcge_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200310) /* VCGE.U32 d0, d0, d0 */
#define vcgeq_s8(a,b) __ndp1_wrr_qqq_u8_s8((a),(b),0xf2000350) /* VCGE.S8 q0, q0, q0 */
#define vcgeq_s16(a,b) __ndp1_wrr_qqq_u16_s16((a),(b),0xf2100350) /* VCGE.S16 q0, q0, q0 */
#define vcgeq_s32(a,b) __ndp1_wrr_qqq_u32_s32((a),(b),0xf2200350) /* VCGE.S32 q0, q0, q0 */
#define vcgeq_f32(a,b) __ndp1_wrr_qqq_u32_f32((a),(b),0xf3000e40) /* VCGE.F32 q0, q0, q0 */
#define vcgeq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000350) /* VCGE.U8 q0, q0, q0 */
#define vcgeq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100350) /* VCGE.U16 q0, q0, q0 */
#define vcgeq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200350) /* VCGE.U32 q0, q0, q0 */
#define vcle_s8(a,b) __swap_ndp1_wrr_ddd_u8_s8((a),(b),0xf2000310) /* VCGE.S8 d0, d0, d0 */
#define vcle_s16(a,b) __swap_ndp1_wrr_ddd_u16_s16((a),(b),0xf2100310) /* VCGE.S16 d0, d0, d0 */
#define vcle_s32(a,b) __swap_ndp1_wrr_ddd_u32_s32((a),(b),0xf2200310) /* VCGE.S32 d0, d0, d0 */
#define vcle_f32(a,b) __swap_ndp1_wrr_ddd_u32_f32((a),(b),0xf3000e00) /* VCGE.F32 d0, d0, d0 */
#define vcle_u8(a,b) __swap_ndp1_wrr_ddd_u8((a),(b),0xf3000310) /* VCGE.U8 d0, d0, d0 */
#define vcle_u16(a,b) __swap_ndp1_wrr_ddd_u16((a),(b),0xf3100310) /* VCGE.U16 d0, d0, d0 */
#define vcle_u32(a,b) __swap_ndp1_wrr_ddd_u32((a),(b),0xf3200310) /* VCGE.U32 d0, d0, d0 */
#define vcleq_s8(a,b) __swap_ndp1_wrr_qqq_u8_s8((a),(b),0xf2000350) /* VCGE.S8 q0, q0, q0 */
#define vcleq_s16(a,b) __swap_ndp1_wrr_qqq_u16_s16((a),(b),0xf2100350) /* VCGE.S16 q0, q0, q0 */
#define vcleq_s32(a,b) __swap_ndp1_wrr_qqq_u32_s32((a),(b),0xf2200350) /* VCGE.S32 q0, q0, q0 */
#define vcleq_f32(a,b) __swap_ndp1_wrr_qqq_u32_f32((a),(b),0xf3000e40) /* VCGE.F32 q0, q0, q0 */
#define vcleq_u8(a,b) __swap_ndp1_wrr_qqq_u8((a),(b),0xf3000350) /* VCGE.U8 q0, q0, q0 */
#define vcleq_u16(a,b) __swap_ndp1_wrr_qqq_u16((a),(b),0xf3100350) /* VCGE.U16 q0, q0, q0 */
#define vcleq_u32(a,b) __swap_ndp1_wrr_qqq_u32((a),(b),0xf3200350) /* VCGE.U32 q0, q0, q0 */
#define vcgt_s8(a,b) __ndp1_wrr_ddd_u8_s8((a),(b),0xf2000300) /* VCGT.S8 d0, d0, d0 */
#define vcgt_s16(a,b) __ndp1_wrr_ddd_u16_s16((a),(b),0xf2100300) /* VCGT.S16 d0, d0, d0 */
#define vcgt_s32(a,b) __ndp1_wrr_ddd_u32_s32((a),(b),0xf2200300) /* VCGT.S32 d0, d0, d0 */
#define vcgt_f32(a,b) __ndp1_wrr_ddd_u32_f32((a),(b),0xf3200e00) /* VCGT.F32 d0, d0, d0 */
#define vcgt_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000300) /* VCGT.U8 d0, d0, d0 */
#define vcgt_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100300) /* VCGT.U16 d0, d0, d0 */
#define vcgt_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200300) /* VCGT.U32 d0, d0, d0 */
#define vcgtq_s8(a,b) __ndp1_wrr_qqq_u8_s8((a),(b),0xf2000340) /* VCGT.S8 q0, q0, q0 */
#define vcgtq_s16(a,b) __ndp1_wrr_qqq_u16_s16((a),(b),0xf2100340) /* VCGT.S16 q0, q0, q0 */
#define vcgtq_s32(a,b) __ndp1_wrr_qqq_u32_s32((a),(b),0xf2200340) /* VCGT.S32 q0, q0, q0 */
#define vcgtq_f32(a,b) __ndp1_wrr_qqq_u32_f32((a),(b),0xf3200e40) /* VCGT.F32 q0, q0, q0 */
#define vcgtq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000340) /* VCGT.U8 q0, q0, q0 */
#define vcgtq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100340) /* VCGT.U16 q0, q0, q0 */
#define vcgtq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200340) /* VCGT.U32 q0, q0, q0 */
#define vclt_s8(a,b) __swap_ndp1_wrr_ddd_u8_s8((a),(b),0xf2000300) /* VCGT.S8 d0, d0, d0 */
#define vclt_s16(a,b) __swap_ndp1_wrr_ddd_u16_s16((a),(b),0xf2100300) /* VCGT.S16 d0, d0, d0 */
#define vclt_s32(a,b) __swap_ndp1_wrr_ddd_u32_s32((a),(b),0xf2200300) /* VCGT.S32 d0, d0, d0 */
#define vclt_f32(a,b) __swap_ndp1_wrr_ddd_u32_f32((a),(b),0xf3200e00) /* VCGT.F32 d0, d0, d0 */
#define vclt_u8(a,b) __swap_ndp1_wrr_ddd_u8((a),(b),0xf3000300) /* VCGT.U8 d0, d0, d0 */
#define vclt_u16(a,b) __swap_ndp1_wrr_ddd_u16((a),(b),0xf3100300) /* VCGT.U16 d0, d0, d0 */
#define vclt_u32(a,b) __swap_ndp1_wrr_ddd_u32((a),(b),0xf3200300) /* VCGT.U32 d0, d0, d0 */
#define vcltq_s8(a,b) __swap_ndp1_wrr_qqq_u8_s8((a),(b),0xf2000340) /* VCGT.S8 q0, q0, q0 */
#define vcltq_s16(a,b) __swap_ndp1_wrr_qqq_u16_s16((a),(b),0xf2100340) /* VCGT.S16 q0, q0, q0 */
#define vcltq_s32(a,b) __swap_ndp1_wrr_qqq_u32_s32((a),(b),0xf2200340) /* VCGT.S32 q0, q0, q0 */
#define vcltq_f32(a,b) __swap_ndp1_wrr_qqq_u32_f32((a),(b),0xf3200e40) /* VCGT.F32 q0, q0, q0 */
#define vcltq_u8(a,b) __swap_ndp1_wrr_qqq_u8((a),(b),0xf3000340) /* VCGT.U8 q0, q0, q0 */
#define vcltq_u16(a,b) __swap_ndp1_wrr_qqq_u16((a),(b),0xf3100340) /* VCGT.U16 q0, q0, q0 */
#define vcltq_u32(a,b) __swap_ndp1_wrr_qqq_u32((a),(b),0xf3200340) /* VCGT.U32 q0, q0, q0 */
#define vcage_f32(a,b) __ndp1_wrr_ddd_u32_f32((a),(b),0xf3000e10) /* VACGE.F32 d0, d0, d0 */
#define vcageq_f32(a,b) __ndp1_wrr_qqq_u32_f32((a),(b),0xf3000e50) /* VACGE.F32 q0, q0, q0 */
#define vcale_f32(a,b) __swap_ndp1_wrr_ddd_u32_f32((a),(b),0xf3000e10) /* VACGE.F32 d0, d0, d0 */
#define vcaleq_f32(a,b) __swap_ndp1_wrr_qqq_u32_f32((a),(b),0xf3000e50) /* VACGE.F32 q0, q0, q0 */
#define vcagt_f32(a,b) __ndp1_wrr_ddd_u32_f32((a),(b),0xf3200e10) /* VACGT.F32 d0, d0, d0 */
#define vcagtq_f32(a,b) __ndp1_wrr_qqq_u32_f32((a),(b),0xf3200e50) /* VACGT.F32 q0, q0, q0 */
#define vcalt_f32(a,b) __swap_ndp1_wrr_ddd_u32_f32((a),(b),0xf3200e10) /* VACGT.F32 d0, d0, d0 */
#define vcaltq_f32(a,b) __swap_ndp1_wrr_qqq_u32_f32((a),(b),0xf3200e50) /* VACGT.F32 q0, q0, q0 */
#define vtst_s8(a,b) __ndp1_wrr_ddd_u8_s8((a),(b),0xf2000810) /* VTST.8 d0, d0, d0 */
#define vtst_s16(a,b) __ndp1_wrr_ddd_u16_s16((a),(b),0xf2100810) /* VTST.16 d0, d0, d0 */
#define vtst_s32(a,b) __ndp1_wrr_ddd_u32_s32((a),(b),0xf2200810) /* VTST.32 d0, d0, d0 */
#define vtst_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2000810) /* VTST.8 d0, d0, d0 */
#define vtst_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2100810) /* VTST.16 d0, d0, d0 */
#define vtst_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2200810) /* VTST.32 d0, d0, d0 */
#define vtst_p8(a,b) __ndp1_wrr_ddd_u8_p8((a),(b),0xf2000810) /* VTST.8 d0, d0, d0 */
#define vtst_p16(a,b) __ndp1_wrr_ddd_u16_p16((a),(b),0xf2100810) /* VTST.16 d0, d0, d0 */
#define vtstq_s8(a,b) __ndp1_wrr_qqq_u8_s8((a),(b),0xf2000850) /* VTST.8 q0, q0, q0 */
#define vtstq_s16(a,b) __ndp1_wrr_qqq_u16_s16((a),(b),0xf2100850) /* VTST.16 q0, q0, q0 */
#define vtstq_s32(a,b) __ndp1_wrr_qqq_u32_s32((a),(b),0xf2200850) /* VTST.32 q0, q0, q0 */
#define vtstq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf2000850) /* VTST.8 q0, q0, q0 */
#define vtstq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf2100850) /* VTST.16 q0, q0, q0 */
#define vtstq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf2200850) /* VTST.32 q0, q0, q0 */
#define vtstq_p8(a,b) __ndp1_wrr_qqq_u8_p8((a),(b),0xf2000850) /* VTST.8 q0, q0, q0 */
#define vtstq_p16(a,b) __ndp1_wrr_qqq_u16_p16((a),(b),0xf2100850) /* VTST.16 q0, q0, q0 */
#define vceqz_s8(a) __ndp7_wr_dd_u8_s8((a),0xf3b10100) /* VCEQ.I8 d0,d0,#0 */
#define vceqz_s16(a) __ndp7_wr_dd_u16_s16((a),0xf3b50100) /* VCEQ.I16 d0,d0,#0 */
#define vceqz_s32(a) __ndp7_wr_dd_u32_s32((a),0xf3b90100) /* VCEQ.I32 d0,d0,#0 */
#define vceqz_u8(a) __ndp7_wr_dd_u8((a),0xf3b10100) /* VCEQ.I8 d0,d0,#0 */
#define vceqz_u16(a) __ndp7_wr_dd_u16((a),0xf3b50100) /* VCEQ.I16 d0,d0,#0 */
#define vceqz_u32(a) __ndp7_wr_dd_u32((a),0xf3b90100) /* VCEQ.I32 d0,d0,#0 */
#define vceqz_f32(a) __ndp7_wr_dd_u32_f32((a),0xf3b90500) /* VCEQ.F32 d0,d0,#0 */
#define vceqz_p8(a) __ndp7_wr_dd_u8_p8((a),0xf3b10100) /* VCEQ.I8 d0,d0,#0 */
#define vceqzq_s8(a) __ndp7_wr_qq_u8_s8((a),0xf3b10140) /* VCEQ.I8 q0,q0,#0 */
#define vceqzq_s16(a) __ndp7_wr_qq_u16_s16((a),0xf3b50140) /* VCEQ.I16 q0,q0,#0 */
#define vceqzq_s32(a) __ndp7_wr_qq_u32_s32((a),0xf3b90140) /* VCEQ.I32 q0,q0,#0 */
#define vceqzq_u8(a) __ndp7_wr_qq_u8((a),0xf3b10140) /* VCEQ.I8 q0,q0,#0 */
#define vceqzq_u16(a) __ndp7_wr_qq_u16((a),0xf3b50140) /* VCEQ.I16 q0,q0,#0 */
#define vceqzq_u32(a) __ndp7_wr_qq_u32((a),0xf3b90140) /* VCEQ.I32 q0,q0,#0 */
#define vceqzq_f32(a) __ndp7_wr_qq_u32_f32((a),0xf3b90540) /* VCEQ.F32 q0,q0,#0 */
#define vceqzq_p8(a) __ndp7_wr_qq_u8_p8((a),0xf3b10140) /* VCEQ.I8 q0,q0,#0 */
#define vcgtz_s8(a) __ndp7_wr_dd_u8_s8((a),0xf3b10000) /* VCGT.S8 d0,d0,#0 */
#define vcgtz_s16(a) __ndp7_wr_dd_u16_s16((a),0xf3b50000) /* VCGT.S16 d0,d0,#0 */
#define vcgtz_s32(a) __ndp7_wr_dd_u32_s32((a),0xf3b90000) /* VCGT.S32 d0,d0,#0 */
#define vcgtz_f32(a) __ndp7_wr_dd_u32_f32((a),0xf3b90400) /* VCGT.F32 d0,d0,#0 */
#define vcgtzq_s8(a) __ndp7_wr_qq_u8_s8((a),0xf3b10040) /* VCGT.S8 q0,q0,#0 */
#define vcgtzq_s16(a) __ndp7_wr_qq_u16_s16((a),0xf3b50040) /* VCGT.S16 q0,q0,#0 */
#define vcgtzq_s32(a) __ndp7_wr_qq_u32_s32((a),0xf3b90040) /* VCGT.S32 q0,q0,#0 */
#define vcgtzq_f32(a) __ndp7_wr_qq_u32_f32((a),0xf3b90440) /* VCGT.F32 q0,q0,#0 */
#define vcgez_s8(a) __ndp7_wr_dd_u8_s8((a),0xf3b10080) /* VCGE.S8 d0,d0,#0 */
#define vcgez_s16(a) __ndp7_wr_dd_u16_s16((a),0xf3b50080) /* VCGE.S16 d0,d0,#0 */
#define vcgez_s32(a) __ndp7_wr_dd_u32_s32((a),0xf3b90080) /* VCGE.S32 d0,d0,#0 */
#define vcgez_f32(a) __ndp7_wr_dd_u32_f32((a),0xf3b90480) /* VCGE.F32 d0,d0,#0 */
#define vcgezq_s8(a) __ndp7_wr_qq_u8_s8((a),0xf3b100c0) /* VCGE.S8 q0,q0,#0 */
#define vcgezq_s16(a) __ndp7_wr_qq_u16_s16((a),0xf3b500c0) /* VCGE.S16 q0,q0,#0 */
#define vcgezq_s32(a) __ndp7_wr_qq_u32_s32((a),0xf3b900c0) /* VCGE.S32 q0,q0,#0 */
#define vcgezq_f32(a) __ndp7_wr_qq_u32_f32((a),0xf3b904c0) /* VCGE.F32 q0,q0,#0 */
#define vclez_s8(a) __ndp7_wr_dd_u8_s8((a),0xf3b10180) /* VCLE.S8 d0,d0,#0 */
#define vclez_s16(a) __ndp7_wr_dd_u16_s16((a),0xf3b50180) /* VCLE.S16 d0,d0,#0 */
#define vclez_s32(a) __ndp7_wr_dd_u32_s32((a),0xf3b90180) /* VCLE.S32 d0,d0,#0 */
#define vclez_f32(a) __ndp7_wr_dd_u32_f32((a),0xf3b90580) /* VCLE.F32 d0,d0,#0 */
#define vclezq_s8(a) __ndp7_wr_qq_u8_s8((a),0xf3b101c0) /* VCLE.S8 q0,q0,#0 */
#define vclezq_s16(a) __ndp7_wr_qq_u16_s16((a),0xf3b501c0) /* VCLE.S16 q0,q0,#0 */
#define vclezq_s32(a) __ndp7_wr_qq_u32_s32((a),0xf3b901c0) /* VCLE.S32 q0,q0,#0 */
#define vclezq_f32(a) __ndp7_wr_qq_u32_f32((a),0xf3b905c0) /* VCLE.F32 q0,q0,#0 */
#define vcltz_s8(a) __ndp7_wr_dd_u8_s8((a),0xf3b10200) /* VCLT.S8 d0,d0,#0 */
#define vcltz_s16(a) __ndp7_wr_dd_u16_s16((a),0xf3b50200) /* VCLT.S16 d0,d0,#0 */
#define vcltz_s32(a) __ndp7_wr_dd_u32_s32((a),0xf3b90200) /* VCLT.S32 d0,d0,#0 */
#define vcltz_f32(a) __ndp7_wr_dd_u32_f32((a),0xf3b90600) /* VCLT.F32 d0,d0,#0 */
#define vcltzq_s8(a) __ndp7_wr_qq_u8_s8((a),0xf3b10240) /* VCLT.S8 q0,q0,#0 */
#define vcltzq_s16(a) __ndp7_wr_qq_u16_s16((a),0xf3b50240) /* VCLT.S16 q0,q0,#0 */
#define vcltzq_s32(a) __ndp7_wr_qq_u32_s32((a),0xf3b90240) /* VCLT.S32 q0,q0,#0 */
#define vcltzq_f32(a) __ndp7_wr_qq_u32_f32((a),0xf3b90640) /* VCLT.F32 q0,q0,#0 */
#define vabd_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000700) /* VABD.S8 d0,d0,d0 */
#define vabd_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100700) /* VABD.S16 d0,d0,d0 */
#define vabd_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200700) /* VABD.S32 d0,d0,d0 */
#define vabd_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000700) /* VABD.U8 d0,d0,d0 */
#define vabd_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100700) /* VABD.U16 d0,d0,d0 */
#define vabd_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200700) /* VABD.U32 d0,d0,d0 */
#define vabd_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf3200d00) /* VABD.F32 d0,d0,d0 */
#define vabdq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000740) /* VABD.S8 q0,q0,q0 */
#define vabdq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100740) /* VABD.S16 q0,q0,q0 */
#define vabdq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200740) /* VABD.S32 q0,q0,q0 */
#define vabdq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000740) /* VABD.U8 q0,q0,q0 */
#define vabdq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100740) /* VABD.U16 q0,q0,q0 */
#define vabdq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200740) /* VABD.U32 q0,q0,q0 */
#define vabdq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf3200d40) /* VABD.F32 q0,q0,q0 */
#define vabdl_s8(a,b) __ndp4_wrr_qdd_s16_s8((a),(b),0xf2800700) /* VABDL.S8 q0,d0,d0 */
#define vabdl_s16(a,b) __ndp4_wrr_qdd_s32_s16((a),(b),0xf2900700) /* VABDL.S16 q0,d0,d0 */
#define vabdl_s32(a,b) __ndp4_wrr_qdd_s64_s32((a),(b),0xf2a00700) /* VABDL.S32 q0,d0,d0 */
#define vabdl_u8(a,b) __ndp4_wrr_qdd_u16_u8((a),(b),0xf3800700) /* VABDL.U8 q0,d0,d0 */
#define vabdl_u16(a,b) __ndp4_wrr_qdd_u32_u16((a),(b),0xf3900700) /* VABDL.U16 q0,d0,d0 */
#define vabdl_u32(a,b) __ndp4_wrr_qdd_u64_u32((a),(b),0xf3a00700) /* VABDL.U32 q0,d0,d0 */
#define vaba_s8(a,b,c) __ndp1_xrr_ddd_s8((a),(b),(c),0xf2000710) /* VABA.S8 d0,d0,d0 */
#define vaba_s16(a,b,c) __ndp1_xrr_ddd_s16((a),(b),(c),0xf2100710) /* VABA.S16 d0,d0,d0 */
#define vaba_s32(a,b,c) __ndp1_xrr_ddd_s32((a),(b),(c),0xf2200710) /* VABA.S32 d0,d0,d0 */
#define vaba_u8(a,b,c) __ndp1_xrr_ddd_u8((a),(b),(c),0xf3000710) /* VABA.U8 d0,d0,d0 */
#define vaba_u16(a,b,c) __ndp1_xrr_ddd_u16((a),(b),(c),0xf3100710) /* VABA.U16 d0,d0,d0 */
#define vaba_u32(a,b,c) __ndp1_xrr_ddd_u32((a),(b),(c),0xf3200710) /* VABA.U32 d0,d0,d0 */
#define vabaq_s8(a,b,c) __ndp1_xrr_qqq_s8((a),(b),(c),0xf2000750) /* VABA.S8 q0,q0,q0 */
#define vabaq_s16(a,b,c) __ndp1_xrr_qqq_s16((a),(b),(c),0xf2100750) /* VABA.S16 q0,q0,q0 */
#define vabaq_s32(a,b,c) __ndp1_xrr_qqq_s32((a),(b),(c),0xf2200750) /* VABA.S32 q0,q0,q0 */
#define vabaq_u8(a,b,c) __ndp1_xrr_qqq_u8((a),(b),(c),0xf3000750) /* VABA.U8 q0,q0,q0 */
#define vabaq_u16(a,b,c) __ndp1_xrr_qqq_u16((a),(b),(c),0xf3100750) /* VABA.U16 q0,q0,q0 */
#define vabaq_u32(a,b,c) __ndp1_xrr_qqq_u32((a),(b),(c),0xf3200750) /* VABA.U32 q0,q0,q0 */
#define vabal_s8(a,b,c) __ndp4_xrr_qdd_s16_s16_s8((a),(b),(c),0xf2800500) /* VABAL.S8 q0,d0,d0 */
#define vabal_s16(a,b,c) __ndp4_xrr_qdd_s32_s32_s16((a),(b),(c),0xf2900500) /* VABAL.S16 q0,d0,d0 */
#define vabal_s32(a,b,c) __ndp4_xrr_qdd_s64_s64_s32((a),(b),(c),0xf2a00500) /* VABAL.S32 q0,d0,d0 */
#define vabal_u8(a,b,c) __ndp4_xrr_qdd_u16_u16_u8((a),(b),(c),0xf3800500) /* VABAL.U8 q0,d0,d0 */
#define vabal_u16(a,b,c) __ndp4_xrr_qdd_u32_u32_u16((a),(b),(c),0xf3900500) /* VABAL.U16 q0,d0,d0 */
#define vabal_u32(a,b,c) __ndp4_xrr_qdd_u64_u64_u32((a),(b),(c),0xf3a00500) /* VABAL.U32 q0,d0,d0 */
#define vmax_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000600) /* VMAX.S8 d0,d0,d0 */
#define vmax_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100600) /* VMAX.S16 d0,d0,d0 */
#define vmax_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200600) /* VMAX.S32 d0,d0,d0 */
#define vmax_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000600) /* VMAX.U8 d0,d0,d0 */
#define vmax_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100600) /* VMAX.U16 d0,d0,d0 */
#define vmax_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200600) /* VMAX.U32 d0,d0,d0 */
#define vmax_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf2000f00) /* VMAX.F32 d0,d0,d0 */
#define vmaxq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000640) /* VMAX.S8 q0,q0,q0 */
#define vmaxq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100640) /* VMAX.S16 q0,q0,q0 */
#define vmaxq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200640) /* VMAX.S32 q0,q0,q0 */
#define vmaxq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000640) /* VMAX.U8 q0,q0,q0 */
#define vmaxq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100640) /* VMAX.U16 q0,q0,q0 */
#define vmaxq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200640) /* VMAX.U32 q0,q0,q0 */
#define vmaxq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf2000f40) /* VMAX.F32 q0,q0,q0 */
#define vmin_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000610) /* VMIN.S8 d0,d0,d0 */
#define vmin_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100610) /* VMIN.S16 d0,d0,d0 */
#define vmin_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200610) /* VMIN.S32 d0,d0,d0 */
#define vmin_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000610) /* VMIN.U8 d0,d0,d0 */
#define vmin_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100610) /* VMIN.U16 d0,d0,d0 */
#define vmin_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200610) /* VMIN.U32 d0,d0,d0 */
#define vmin_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf2200f00) /* VMIN.F32 d0,d0,d0 */
#define vminq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000650) /* VMIN.S8 q0,q0,q0 */
#define vminq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100650) /* VMIN.S16 q0,q0,q0 */
#define vminq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200650) /* VMIN.S32 q0,q0,q0 */
#define vminq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000650) /* VMIN.U8 q0,q0,q0 */
#define vminq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3100650) /* VMIN.U16 q0,q0,q0 */
#define vminq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3200650) /* VMIN.U32 q0,q0,q0 */
#define vminq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf2200f40) /* VMIN.F32 q0,q0,q0 */
#define vpadd_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000b10) /* VPADD.I8 d0,d0,d0 */
#define vpadd_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100b10) /* VPADD.I16 d0,d0,d0 */
#define vpadd_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200b10) /* VPADD.I32 d0,d0,d0 */
#define vpadd_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2000b10) /* VPADD.I8 d0,d0,d0 */
#define vpadd_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2100b10) /* VPADD.I16 d0,d0,d0 */
#define vpadd_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2200b10) /* VPADD.I32 d0,d0,d0 */
#define vpadd_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf3000d00) /* VPADD.F32 d0,d0,d0 */
#define vpaddl_s8(a) __ndp7_wr_dd_s16_s8((a),0xf3b00200) /* VPADDL.S8 d0,d0 */
#define vpaddl_s16(a) __ndp7_wr_dd_s32_s16((a),0xf3b40200) /* VPADDL.S16 d0,d0 */
#define vpaddl_s32(a) __ndp7_wr_dd_s64_s32((a),0xf3b80200) /* VPADDL.S32 d0,d0 */
#define vpaddl_u8(a) __ndp7_wr_dd_u16_u8((a),0xf3b00280) /* VPADDL.U8 d0,d0 */
#define vpaddl_u16(a) __ndp7_wr_dd_u32_u16((a),0xf3b40280) /* VPADDL.U16 d0,d0 */
#define vpaddl_u32(a) __ndp7_wr_dd_u64_u32((a),0xf3b80280) /* VPADDL.U32 d0,d0 */
#define vpaddlq_s8(a) __ndp7_wr_qq_s16_s8((a),0xf3b00240) /* VPADDL.S8 q0,q0 */
#define vpaddlq_s16(a) __ndp7_wr_qq_s32_s16((a),0xf3b40240) /* VPADDL.S16 q0,q0 */
#define vpaddlq_s32(a) __ndp7_wr_qq_s64_s32((a),0xf3b80240) /* VPADDL.S32 q0,q0 */
#define vpaddlq_u8(a) __ndp7_wr_qq_u16_u8((a),0xf3b002c0) /* VPADDL.U8 q0,q0 */
#define vpaddlq_u16(a) __ndp7_wr_qq_u32_u16((a),0xf3b402c0) /* VPADDL.U16 q0,q0 */
#define vpaddlq_u32(a) __ndp7_wr_qq_u64_u32((a),0xf3b802c0) /* VPADDL.U32 q0,q0 */
#define vpadal_s8(a,b) __ndp7_xr_dd_s16_s16_s8((a),(b),0xf3b00600) /* VPADAL.S8 d0,d0 */
#define vpadal_s16(a,b) __ndp7_xr_dd_s32_s32_s16((a),(b),0xf3b40600) /* VPADAL.S16 d0,d0 */
#define vpadal_s32(a,b) __ndp7_xr_dd_s64_s64_s32((a),(b),0xf3b80600) /* VPADAL.S32 d0,d0 */
#define vpadal_u8(a,b) __ndp7_xr_dd_u16_u16_u8((a),(b),0xf3b00680) /* VPADAL.U8 d0,d0 */
#define vpadal_u16(a,b) __ndp7_xr_dd_u32_u32_u16((a),(b),0xf3b40680) /* VPADAL.U16 d0,d0 */
#define vpadal_u32(a,b) __ndp7_xr_dd_u64_u64_u32((a),(b),0xf3b80680) /* VPADAL.U32 d0,d0 */
#define vpadalq_s8(a,b) __ndp7_xr_qq_s16_s16_s8((a),(b),0xf3b00640) /* VPADAL.S8 q0,q0 */
#define vpadalq_s16(a,b) __ndp7_xr_qq_s32_s32_s16((a),(b),0xf3b40640) /* VPADAL.S16 q0,q0 */
#define vpadalq_s32(a,b) __ndp7_xr_qq_s64_s64_s32((a),(b),0xf3b80640) /* VPADAL.S32 q0,q0 */
#define vpadalq_u8(a,b) __ndp7_xr_qq_u16_u16_u8((a),(b),0xf3b006c0) /* VPADAL.U8 q0,q0 */
#define vpadalq_u16(a,b) __ndp7_xr_qq_u32_u32_u16((a),(b),0xf3b406c0) /* VPADAL.U16 q0,q0 */
#define vpadalq_u32(a,b) __ndp7_xr_qq_u64_u64_u32((a),(b),0xf3b806c0) /* VPADAL.U32 q0,q0 */
#define vpmax_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000a00) /* VPMAX.S8 d0,d0,d0 */
#define vpmax_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100a00) /* VPMAX.S16 d0,d0,d0 */
#define vpmax_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200a00) /* VPMAX.S32 d0,d0,d0 */
#define vpmax_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000a00) /* VPMAX.U8 d0,d0,d0 */
#define vpmax_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100a00) /* VPMAX.U16 d0,d0,d0 */
#define vpmax_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200a00) /* VPMAX.U32 d0,d0,d0 */
#define vpmax_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf3000f00) /* VPMAX.F32 d0,d0,d0 */
#define vpmin_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000a10) /* VPMIN.S8 d0,d0,d0 */
#define vpmin_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100a10) /* VPMIN.S16 d0,d0,d0 */
#define vpmin_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200a10) /* VPMIN.S32 d0,d0,d0 */
#define vpmin_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000a10) /* VPMIN.U8 d0,d0,d0 */
#define vpmin_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3100a10) /* VPMIN.U16 d0,d0,d0 */
#define vpmin_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3200a10) /* VPMIN.U32 d0,d0,d0 */
#define vpmin_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf3200f00) /* VPMIN.F32 d0,d0,d0 */
#define vrecps_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf2000f10) /* VRECPS.F32 d0, d0, d0 */
#define vrecpsq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf2000f50) /* VRECPS.F32 q0, q0, q0 */
#define vrsqrts_f32(a,b) __ndp1_wrr_ddd_f32((a),(b),0xf2200f10) /* VRSQRTS.F32 d0, d0, d0 */
#define vrsqrtsq_f32(a,b) __ndp1_wrr_qqq_f32((a),(b),0xf2200f50) /* VRSQRTS.F32 q0, q0, q0 */
#define vshl_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000400) /* VSHL.S8 d0,d0,d0 */
#define vshl_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100400) /* VSHL.S16 d0,d0,d0 */
#define vshl_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200400) /* VSHL.S32 d0,d0,d0 */
#define vshl_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300400) /* VSHL.S64 d0,d0,d0 */
#define vshl_u8(a,b) __ndp1_wrr_ddd_u8_u8_s8((a),(b),0xf3000400) /* VSHL.U8 d0,d0,d0 */
#define vshl_u16(a,b) __ndp1_wrr_ddd_u16_u16_s16((a),(b),0xf3100400) /* VSHL.U16 d0,d0,d0 */
#define vshl_u32(a,b) __ndp1_wrr_ddd_u32_u32_s32((a),(b),0xf3200400) /* VSHL.U32 d0,d0,d0 */
#define vshl_u64(a,b) __ndp1_wrr_ddd_u64_u64_s64((a),(b),0xf3300400) /* VSHL.U64 d0,d0,d0 */
#define vshlq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000440) /* VSHL.S8 q0,q0,q0 */
#define vshlq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100440) /* VSHL.S16 q0,q0,q0 */
#define vshlq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200440) /* VSHL.S32 q0,q0,q0 */
#define vshlq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300440) /* VSHL.S64 q0,q0,q0 */
#define vshlq_u8(a,b) __ndp1_wrr_qqq_u8_u8_s8((a),(b),0xf3000440) /* VSHL.U8 q0,q0,q0 */
#define vshlq_u16(a,b) __ndp1_wrr_qqq_u16_u16_s16((a),(b),0xf3100440) /* VSHL.U16 q0,q0,q0 */
#define vshlq_u32(a,b) __ndp1_wrr_qqq_u32_u32_s32((a),(b),0xf3200440) /* VSHL.U32 q0,q0,q0 */
#define vshlq_u64(a,b) __ndp1_wrr_qqq_u64_u64_s64((a),(b),0xf3300440) /* VSHL.U64 q0,q0,q0 */
#define vqshl_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000410) /* VQSHL.S8 d0,d0,d0 */
#define vqshl_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100410) /* VQSHL.S16 d0,d0,d0 */
#define vqshl_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200410) /* VQSHL.S32 d0,d0,d0 */
#define vqshl_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300410) /* VQSHL.S64 d0,d0,d0 */
#define vqshl_u8(a,b) __ndp1_wrr_ddd_u8_u8_s8((a),(b),0xf3000410) /* VQSHL.U8 d0,d0,d0 */
#define vqshl_u16(a,b) __ndp1_wrr_ddd_u16_u16_s16((a),(b),0xf3100410) /* VQSHL.U16 d0,d0,d0 */
#define vqshl_u32(a,b) __ndp1_wrr_ddd_u32_u32_s32((a),(b),0xf3200410) /* VQSHL.U32 d0,d0,d0 */
#define vqshl_u64(a,b) __ndp1_wrr_ddd_u64_u64_s64((a),(b),0xf3300410) /* VQSHL.U64 d0,d0,d0 */
#define vqshlq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000450) /* VQSHL.S8 q0,q0,q0 */
#define vqshlq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100450) /* VQSHL.S16 q0,q0,q0 */
#define vqshlq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200450) /* VQSHL.S32 q0,q0,q0 */
#define vqshlq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300450) /* VQSHL.S64 q0,q0,q0 */
#define vqshlq_u8(a,b) __ndp1_wrr_qqq_u8_u8_s8((a),(b),0xf3000450) /* VQSHL.U8 q0,q0,q0 */
#define vqshlq_u16(a,b) __ndp1_wrr_qqq_u16_u16_s16((a),(b),0xf3100450) /* VQSHL.U16 q0,q0,q0 */
#define vqshlq_u32(a,b) __ndp1_wrr_qqq_u32_u32_s32((a),(b),0xf3200450) /* VQSHL.U32 q0,q0,q0 */
#define vqshlq_u64(a,b) __ndp1_wrr_qqq_u64_u64_s64((a),(b),0xf3300450) /* VQSHL.U64 q0,q0,q0 */
#define vrshl_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000500) /* VRSHL.S8 d0,d0,d0 */
#define vrshl_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100500) /* VRSHL.S16 d0,d0,d0 */
#define vrshl_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200500) /* VRSHL.S32 d0,d0,d0 */
#define vrshl_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300500) /* VRSHL.S64 d0,d0,d0 */
#define vrshl_u8(a,b) __ndp1_wrr_ddd_u8_u8_s8((a),(b),0xf3000500) /* VRSHL.U8 d0,d0,d0 */
#define vrshl_u16(a,b) __ndp1_wrr_ddd_u16_u16_s16((a),(b),0xf3100500) /* VRSHL.U16 d0,d0,d0 */
#define vrshl_u32(a,b) __ndp1_wrr_ddd_u32_u32_s32((a),(b),0xf3200500) /* VRSHL.U32 d0,d0,d0 */
#define vrshl_u64(a,b) __ndp1_wrr_ddd_u64_u64_s64((a),(b),0xf3300500) /* VRSHL.U64 d0,d0,d0 */
#define vrshlq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000540) /* VRSHL.S8 q0,q0,q0 */
#define vrshlq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100540) /* VRSHL.S16 q0,q0,q0 */
#define vrshlq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200540) /* VRSHL.S32 q0,q0,q0 */
#define vrshlq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300540) /* VRSHL.S64 q0,q0,q0 */
#define vrshlq_u8(a,b) __ndp1_wrr_qqq_u8_u8_s8((a),(b),0xf3000540) /* VRSHL.U8 q0,q0,q0 */
#define vrshlq_u16(a,b) __ndp1_wrr_qqq_u16_u16_s16((a),(b),0xf3100540) /* VRSHL.U16 q0,q0,q0 */
#define vrshlq_u32(a,b) __ndp1_wrr_qqq_u32_u32_s32((a),(b),0xf3200540) /* VRSHL.U32 q0,q0,q0 */
#define vrshlq_u64(a,b) __ndp1_wrr_qqq_u64_u64_s64((a),(b),0xf3300540) /* VRSHL.U64 q0,q0,q0 */
#define vqrshl_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000510) /* VQRSHL.S8 d0,d0,d0 */
#define vqrshl_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100510) /* VQRSHL.S16 d0,d0,d0 */
#define vqrshl_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200510) /* VQRSHL.S32 d0,d0,d0 */
#define vqrshl_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300510) /* VQRSHL.S64 d0,d0,d0 */
#define vqrshl_u8(a,b) __ndp1_wrr_ddd_u8_u8_s8((a),(b),0xf3000510) /* VQRSHL.U8 d0,d0,d0 */
#define vqrshl_u16(a,b) __ndp1_wrr_ddd_u16_u16_s16((a),(b),0xf3100510) /* VQRSHL.U16 d0,d0,d0 */
#define vqrshl_u32(a,b) __ndp1_wrr_ddd_u32_u32_s32((a),(b),0xf3200510) /* VQRSHL.U32 d0,d0,d0 */
#define vqrshl_u64(a,b) __ndp1_wrr_ddd_u64_u64_s64((a),(b),0xf3300510) /* VQRSHL.U64 d0,d0,d0 */
#define vqrshlq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000550) /* VQRSHL.S8 q0,q0,q0 */
#define vqrshlq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100550) /* VQRSHL.S16 q0,q0,q0 */
#define vqrshlq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200550) /* VQRSHL.S32 q0,q0,q0 */
#define vqrshlq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300550) /* VQRSHL.S64 q0,q0,q0 */
#define vqrshlq_u8(a,b) __ndp1_wrr_qqq_u8_u8_s8((a),(b),0xf3000550) /* VQRSHL.U8 q0,q0,q0 */
#define vqrshlq_u16(a,b) __ndp1_wrr_qqq_u16_u16_s16((a),(b),0xf3100550) /* VQRSHL.U16 q0,q0,q0 */
#define vqrshlq_u32(a,b) __ndp1_wrr_qqq_u32_u32_s32((a),(b),0xf3200550) /* VQRSHL.U32 q0,q0,q0 */
#define vqrshlq_u64(a,b) __ndp1_wrr_qqq_u64_u64_s64((a),(b),0xf3300550) /* VQRSHL.U64 q0,q0,q0 */
#define vshr_n_s8(a,b) __ndp2_wrk_dd_s8_k((a),__is_constrange(1,8,b),0xf2880010) /* VSHR.S8 d0,d0,#8 */
#define vshr_n_s16(a,b) __ndp2_wrk_dd_s16_k((a),__is_constrange(1,16,b),0xf2900010) /* VSHR.S16 d0,d0,#16 */
#define vshr_n_s32(a,b) __ndp2_wrk_dd_s32_k((a),__is_constrange(1,32,b),0xf2a00010) /* VSHR.S32 d0,d0,#32 */
#define vshr_n_s64(a,b) __ndp2_wrk_dd_s64_k((a),__is_constrange(1,64,b),0xf2800090) /* VSHR.S64 d0,d0,#64 */
#define vshr_n_u8(a,b) __ndp2_wrk_dd_u8_k((a),__is_constrange(1,8,b),0xf3880010) /* VSHR.U8 d0,d0,#8 */
#define vshr_n_u16(a,b) __ndp2_wrk_dd_u16_k((a),__is_constrange(1,16,b),0xf3900010) /* VSHR.U16 d0,d0,#16 */
#define vshr_n_u32(a,b) __ndp2_wrk_dd_u32_k((a),__is_constrange(1,32,b),0xf3a00010) /* VSHR.U32 d0,d0,#32 */
#define vshr_n_u64(a,b) __ndp2_wrk_dd_u64_k((a),__is_constrange(1,64,b),0xf3800090) /* VSHR.U64 d0,d0,#64 */
#define vshrq_n_s8(a,b) __ndp2_wrk_qq_s8_k((a),__is_constrange(1,8,b),0xf2880050) /* VSHR.S8 q0,q0,#8 */
#define vshrq_n_s16(a,b) __ndp2_wrk_qq_s16_k((a),__is_constrange(1,16,b),0xf2900050) /* VSHR.S16 q0,q0,#16 */
#define vshrq_n_s32(a,b) __ndp2_wrk_qq_s32_k((a),__is_constrange(1,32,b),0xf2a00050) /* VSHR.S32 q0,q0,#32 */
#define vshrq_n_s64(a,b) __ndp2_wrk_qq_s64_k((a),__is_constrange(1,64,b),0xf28000d0) /* VSHR.S64 q0,q0,#64 */
#define vshrq_n_u8(a,b) __ndp2_wrk_qq_u8_k((a),__is_constrange(1,8,b),0xf3880050) /* VSHR.U8 q0,q0,#8 */
#define vshrq_n_u16(a,b) __ndp2_wrk_qq_u16_k((a),__is_constrange(1,16,b),0xf3900050) /* VSHR.U16 q0,q0,#16 */
#define vshrq_n_u32(a,b) __ndp2_wrk_qq_u32_k((a),__is_constrange(1,32,b),0xf3a00050) /* VSHR.U32 q0,q0,#32 */
#define vshrq_n_u64(a,b) __ndp2_wrk_qq_u64_k((a),__is_constrange(1,64,b),0xf38000d0) /* VSHR.U64 q0,q0,#64 */
#define vshl_n_s8(a,b) __ndp2_wrk_dd_s8_k((a),__is_constrange(0,7,b),0xf2880510) /* VSHL.I8 d0,d0,#0 */
#define vshl_n_s16(a,b) __ndp2_wrk_dd_s16_k((a),__is_constrange(0,15,b),0xf2900510) /* VSHL.I16 d0,d0,#0 */
#define vshl_n_s32(a,b) __ndp2_wrk_dd_s32_k((a),__is_constrange(0,31,b),0xf2a00510) /* VSHL.I32 d0,d0,#0 */
#define vshl_n_s64(a,b) __ndp2_wrk_dd_s64_k((a),__is_constrange(0,63,b),0xf2800590) /* VSHL.I64 d0,d0,#0 */
#define vshl_n_u8(a,b) __ndp2_wrk_dd_u8_k((a),__is_constrange(0,7,b),0xf2880510) /* VSHL.I8 d0,d0,#0 */
#define vshl_n_u16(a,b) __ndp2_wrk_dd_u16_k((a),__is_constrange(0,15,b),0xf2900510) /* VSHL.I16 d0,d0,#0 */
#define vshl_n_u32(a,b) __ndp2_wrk_dd_u32_k((a),__is_constrange(0,31,b),0xf2a00510) /* VSHL.I32 d0,d0,#0 */
#define vshl_n_u64(a,b) __ndp2_wrk_dd_u64_k((a),__is_constrange(0,63,b),0xf2800590) /* VSHL.I64 d0,d0,#0 */
#define vshlq_n_s8(a,b) __ndp2_wrk_qq_s8_k((a),__is_constrange(0,7,b),0xf2880550) /* VSHL.I8 q0,q0,#0 */
#define vshlq_n_s16(a,b) __ndp2_wrk_qq_s16_k((a),__is_constrange(0,15,b),0xf2900550) /* VSHL.I16 q0,q0,#0 */
#define vshlq_n_s32(a,b) __ndp2_wrk_qq_s32_k((a),__is_constrange(0,31,b),0xf2a00550) /* VSHL.I32 q0,q0,#0 */
#define vshlq_n_s64(a,b) __ndp2_wrk_qq_s64_k((a),__is_constrange(0,63,b),0xf28005d0) /* VSHL.I64 q0,q0,#0 */
#define vshlq_n_u8(a,b) __ndp2_wrk_qq_u8_k((a),__is_constrange(0,7,b),0xf2880550) /* VSHL.I8 q0,q0,#0 */
#define vshlq_n_u16(a,b) __ndp2_wrk_qq_u16_k((a),__is_constrange(0,15,b),0xf2900550) /* VSHL.I16 q0,q0,#0 */
#define vshlq_n_u32(a,b) __ndp2_wrk_qq_u32_k((a),__is_constrange(0,31,b),0xf2a00550) /* VSHL.I32 q0,q0,#0 */
#define vshlq_n_u64(a,b) __ndp2_wrk_qq_u64_k((a),__is_constrange(0,63,b),0xf28005d0) /* VSHL.I64 q0,q0,#0 */
#define vrshr_n_s8(a,b) __ndp2_wrk_dd_s8_k((a),__is_constrange(1,8,b),0xf2880210) /* VRSHR.S8 d0,d0,#8 */
#define vrshr_n_s16(a,b) __ndp2_wrk_dd_s16_k((a),__is_constrange(1,16,b),0xf2900210) /* VRSHR.S16 d0,d0,#16 */
#define vrshr_n_s32(a,b) __ndp2_wrk_dd_s32_k((a),__is_constrange(1,32,b),0xf2a00210) /* VRSHR.S32 d0,d0,#32 */
#define vrshr_n_s64(a,b) __ndp2_wrk_dd_s64_k((a),__is_constrange(1,64,b),0xf2800290) /* VRSHR.S64 d0,d0,#64 */
#define vrshr_n_u8(a,b) __ndp2_wrk_dd_u8_k((a),__is_constrange(1,8,b),0xf3880210) /* VRSHR.U8 d0,d0,#8 */
#define vrshr_n_u16(a,b) __ndp2_wrk_dd_u16_k((a),__is_constrange(1,16,b),0xf3900210) /* VRSHR.U16 d0,d0,#16 */
#define vrshr_n_u32(a,b) __ndp2_wrk_dd_u32_k((a),__is_constrange(1,32,b),0xf3a00210) /* VRSHR.U32 d0,d0,#32 */
#define vrshr_n_u64(a,b) __ndp2_wrk_dd_u64_k((a),__is_constrange(1,64,b),0xf3800290) /* VRSHR.U64 d0,d0,#64 */
#define vrshrq_n_s8(a,b) __ndp2_wrk_qq_s8_k((a),__is_constrange(1,8,b),0xf2880250) /* VRSHR.S8 q0,q0,#8 */
#define vrshrq_n_s16(a,b) __ndp2_wrk_qq_s16_k((a),__is_constrange(1,16,b),0xf2900250) /* VRSHR.S16 q0,q0,#16 */
#define vrshrq_n_s32(a,b) __ndp2_wrk_qq_s32_k((a),__is_constrange(1,32,b),0xf2a00250) /* VRSHR.S32 q0,q0,#32 */
#define vrshrq_n_s64(a,b) __ndp2_wrk_qq_s64_k((a),__is_constrange(1,64,b),0xf28002d0) /* VRSHR.S64 q0,q0,#64 */
#define vrshrq_n_u8(a,b) __ndp2_wrk_qq_u8_k((a),__is_constrange(1,8,b),0xf3880250) /* VRSHR.U8 q0,q0,#8 */
#define vrshrq_n_u16(a,b) __ndp2_wrk_qq_u16_k((a),__is_constrange(1,16,b),0xf3900250) /* VRSHR.U16 q0,q0,#16 */
#define vrshrq_n_u32(a,b) __ndp2_wrk_qq_u32_k((a),__is_constrange(1,32,b),0xf3a00250) /* VRSHR.U32 q0,q0,#32 */
#define vrshrq_n_u64(a,b) __ndp2_wrk_qq_u64_k((a),__is_constrange(1,64,b),0xf38002d0) /* VRSHR.U64 q0,q0,#64 */
#define vsra_n_s8(a,b,c) __ndp2_xrk_dd_s8_k((a),(b),__is_constrange(1,8,c),0xf2880110) /* VSRA.S8 d0,d0,#8 */
#define vsra_n_s16(a,b,c) __ndp2_xrk_dd_s16_k((a),(b),__is_constrange(1,16,c),0xf2900110) /* VSRA.S16 d0,d0,#16 */
#define vsra_n_s32(a,b,c) __ndp2_xrk_dd_s32_k((a),(b),__is_constrange(1,32,c),0xf2a00110) /* VSRA.S32 d0,d0,#32 */
#define vsra_n_s64(a,b,c) __ndp2_xrk_dd_s64_k((a),(b),__is_constrange(1,64,c),0xf2800190) /* VSRA.S64 d0,d0,#64 */
#define vsra_n_u8(a,b,c) __ndp2_xrk_dd_u8_k((a),(b),__is_constrange(1,8,c),0xf3880110) /* VSRA.U8 d0,d0,#8 */
#define vsra_n_u16(a,b,c) __ndp2_xrk_dd_u16_k((a),(b),__is_constrange(1,16,c),0xf3900110) /* VSRA.U16 d0,d0,#16 */
#define vsra_n_u32(a,b,c) __ndp2_xrk_dd_u32_k((a),(b),__is_constrange(1,32,c),0xf3a00110) /* VSRA.U32 d0,d0,#32 */
#define vsra_n_u64(a,b,c) __ndp2_xrk_dd_u64_k((a),(b),__is_constrange(1,64,c),0xf3800190) /* VSRA.U64 d0,d0,#64 */
#define vsraq_n_s8(a,b,c) __ndp2_xrk_qq_s8_k((a),(b),__is_constrange(1,8,c),0xf2880150) /* VSRA.S8 q0,q0,#8 */
#define vsraq_n_s16(a,b,c) __ndp2_xrk_qq_s16_k((a),(b),__is_constrange(1,16,c),0xf2900150) /* VSRA.S16 q0,q0,#16 */
#define vsraq_n_s32(a,b,c) __ndp2_xrk_qq_s32_k((a),(b),__is_constrange(1,32,c),0xf2a00150) /* VSRA.S32 q0,q0,#32 */
#define vsraq_n_s64(a,b,c) __ndp2_xrk_qq_s64_k((a),(b),__is_constrange(1,64,c),0xf28001d0) /* VSRA.S64 q0,q0,#64 */
#define vsraq_n_u8(a,b,c) __ndp2_xrk_qq_u8_k((a),(b),__is_constrange(1,8,c),0xf3880150) /* VSRA.U8 q0,q0,#8 */
#define vsraq_n_u16(a,b,c) __ndp2_xrk_qq_u16_k((a),(b),__is_constrange(1,16,c),0xf3900150) /* VSRA.U16 q0,q0,#16 */
#define vsraq_n_u32(a,b,c) __ndp2_xrk_qq_u32_k((a),(b),__is_constrange(1,32,c),0xf3a00150) /* VSRA.U32 q0,q0,#32 */
#define vsraq_n_u64(a,b,c) __ndp2_xrk_qq_u64_k((a),(b),__is_constrange(1,64,c),0xf38001d0) /* VSRA.U64 q0,q0,#64 */
#define vrsra_n_s8(a,b,c) __ndp2_xrk_dd_s8_k((a),(b),__is_constrange(1,8,c),0xf2880310) /* VRSRA.S8 d0,d0,#8 */
#define vrsra_n_s16(a,b,c) __ndp2_xrk_dd_s16_k((a),(b),__is_constrange(1,16,c),0xf2900310) /* VRSRA.S16 d0,d0,#16 */
#define vrsra_n_s32(a,b,c) __ndp2_xrk_dd_s32_k((a),(b),__is_constrange(1,32,c),0xf2a00310) /* VRSRA.S32 d0,d0,#32 */
#define vrsra_n_s64(a,b,c) __ndp2_xrk_dd_s64_k((a),(b),__is_constrange(1,64,c),0xf2800390) /* VRSRA.S64 d0,d0,#64 */
#define vrsra_n_u8(a,b,c) __ndp2_xrk_dd_u8_k((a),(b),__is_constrange(1,8,c),0xf3880310) /* VRSRA.U8 d0,d0,#8 */
#define vrsra_n_u16(a,b,c) __ndp2_xrk_dd_u16_k((a),(b),__is_constrange(1,16,c),0xf3900310) /* VRSRA.U16 d0,d0,#16 */
#define vrsra_n_u32(a,b,c) __ndp2_xrk_dd_u32_k((a),(b),__is_constrange(1,32,c),0xf3a00310) /* VRSRA.U32 d0,d0,#32 */
#define vrsra_n_u64(a,b,c) __ndp2_xrk_dd_u64_k((a),(b),__is_constrange(1,64,c),0xf3800390) /* VRSRA.U64 d0,d0,#64 */
#define vrsraq_n_s8(a,b,c) __ndp2_xrk_qq_s8_k((a),(b),__is_constrange(1,8,c),0xf2880350) /* VRSRA.S8 q0,q0,#8 */
#define vrsraq_n_s16(a,b,c) __ndp2_xrk_qq_s16_k((a),(b),__is_constrange(1,16,c),0xf2900350) /* VRSRA.S16 q0,q0,#16 */
#define vrsraq_n_s32(a,b,c) __ndp2_xrk_qq_s32_k((a),(b),__is_constrange(1,32,c),0xf2a00350) /* VRSRA.S32 q0,q0,#32 */
#define vrsraq_n_s64(a,b,c) __ndp2_xrk_qq_s64_k((a),(b),__is_constrange(1,64,c),0xf28003d0) /* VRSRA.S64 q0,q0,#64 */
#define vrsraq_n_u8(a,b,c) __ndp2_xrk_qq_u8_k((a),(b),__is_constrange(1,8,c),0xf3880350) /* VRSRA.U8 q0,q0,#8 */
#define vrsraq_n_u16(a,b,c) __ndp2_xrk_qq_u16_k((a),(b),__is_constrange(1,16,c),0xf3900350) /* VRSRA.U16 q0,q0,#16 */
#define vrsraq_n_u32(a,b,c) __ndp2_xrk_qq_u32_k((a),(b),__is_constrange(1,32,c),0xf3a00350) /* VRSRA.U32 q0,q0,#32 */
#define vrsraq_n_u64(a,b,c) __ndp2_xrk_qq_u64_k((a),(b),__is_constrange(1,64,c),0xf38003d0) /* VRSRA.U64 q0,q0,#64 */
#define vqshl_n_s8(a,b) __ndp2_wrk_dd_s8_k((a),__is_constrange(0,7,b),0xf2880710) /* VQSHL.S8 d0,d0,#0 */
#define vqshl_n_s16(a,b) __ndp2_wrk_dd_s16_k((a),__is_constrange(0,15,b),0xf2900710) /* VQSHL.S16 d0,d0,#0 */
#define vqshl_n_s32(a,b) __ndp2_wrk_dd_s32_k((a),__is_constrange(0,31,b),0xf2a00710) /* VQSHL.S32 d0,d0,#0 */
#define vqshl_n_s64(a,b) __ndp2_wrk_dd_s64_k((a),__is_constrange(0,63,b),0xf2800790) /* VQSHL.S64 d0,d0,#0 */
#define vqshl_n_u8(a,b) __ndp2_wrk_dd_u8_k((a),__is_constrange(0,7,b),0xf3880710) /* VQSHL.U8 d0,d0,#0 */
#define vqshl_n_u16(a,b) __ndp2_wrk_dd_u16_k((a),__is_constrange(0,15,b),0xf3900710) /* VQSHL.U16 d0,d0,#0 */
#define vqshl_n_u32(a,b) __ndp2_wrk_dd_u32_k((a),__is_constrange(0,31,b),0xf3a00710) /* VQSHL.U32 d0,d0,#0 */
#define vqshl_n_u64(a,b) __ndp2_wrk_dd_u64_k((a),__is_constrange(0,63,b),0xf3800790) /* VQSHL.U64 d0,d0,#0 */
#define vqshlq_n_s8(a,b) __ndp2_wrk_qq_s8_k((a),__is_constrange(0,7,b),0xf2880750) /* VQSHL.S8 q0,q0,#0 */
#define vqshlq_n_s16(a,b) __ndp2_wrk_qq_s16_k((a),__is_constrange(0,15,b),0xf2900750) /* VQSHL.S16 q0,q0,#0 */
#define vqshlq_n_s32(a,b) __ndp2_wrk_qq_s32_k((a),__is_constrange(0,31,b),0xf2a00750) /* VQSHL.S32 q0,q0,#0 */
#define vqshlq_n_s64(a,b) __ndp2_wrk_qq_s64_k((a),__is_constrange(0,63,b),0xf28007d0) /* VQSHL.S64 q0,q0,#0 */
#define vqshlq_n_u8(a,b) __ndp2_wrk_qq_u8_k((a),__is_constrange(0,7,b),0xf3880750) /* VQSHL.U8 q0,q0,#0 */
#define vqshlq_n_u16(a,b) __ndp2_wrk_qq_u16_k((a),__is_constrange(0,15,b),0xf3900750) /* VQSHL.U16 q0,q0,#0 */
#define vqshlq_n_u32(a,b) __ndp2_wrk_qq_u32_k((a),__is_constrange(0,31,b),0xf3a00750) /* VQSHL.U32 q0,q0,#0 */
#define vqshlq_n_u64(a,b) __ndp2_wrk_qq_u64_k((a),__is_constrange(0,63,b),0xf38007d0) /* VQSHL.U64 q0,q0,#0 */
#define vqshlu_n_s8(a,b) __ndp2_wrk_dd_u8_s8_k((a),__is_constrange(0,7,b),0xf3880610) /* VQSHLU.S8 d0,d0,#0 */
#define vqshlu_n_s16(a,b) __ndp2_wrk_dd_u16_s16_k((a),__is_constrange(0,15,b),0xf3900610) /* VQSHLU.S16 d0,d0,#0 */
#define vqshlu_n_s32(a,b) __ndp2_wrk_dd_u32_s32_k((a),__is_constrange(0,31,b),0xf3a00610) /* VQSHLU.S32 d0,d0,#0 */
#define vqshlu_n_s64(a,b) __ndp2_wrk_dd_u64_s64_k((a),__is_constrange(0,63,b),0xf3800690) /* VQSHLU.S64 d0,d0,#0 */
#define vqshluq_n_s8(a,b) __ndp2_wrk_qq_u8_s8_k((a),__is_constrange(0,7,b),0xf3880650) /* VQSHLU.S8 q0,q0,#0 */
#define vqshluq_n_s16(a,b) __ndp2_wrk_qq_u16_s16_k((a),__is_constrange(0,15,b),0xf3900650) /* VQSHLU.S16 q0,q0,#0 */
#define vqshluq_n_s32(a,b) __ndp2_wrk_qq_u32_s32_k((a),__is_constrange(0,31,b),0xf3a00650) /* VQSHLU.S32 q0,q0,#0 */
#define vqshluq_n_s64(a,b) __ndp2_wrk_qq_u64_s64_k((a),__is_constrange(0,63,b),0xf38006d0) /* VQSHLU.S64 q0,q0,#0 */
#define vshrn_n_s16(a,b) __ndp2_wrk_dq_s8_s16_k((a),__is_constrange(1,8,b),0xf2880810) /* VSHRN.I16 d0,q0,#8 */
#define vshrn_n_s32(a,b) __ndp2_wrk_dq_s16_s32_k((a),__is_constrange(1,16,b),0xf2900810) /* VSHRN.I32 d0,q0,#16 */
#define vshrn_n_s64(a,b) __ndp2_wrk_dq_s32_s64_k((a),__is_constrange(1,32,b),0xf2a00810) /* VSHRN.I64 d0,q0,#32 */
#define vshrn_n_u16(a,b) __ndp2_wrk_dq_u8_u16_k((a),__is_constrange(1,8,b),0xf2880810) /* VSHRN.I16 d0,q0,#8 */
#define vshrn_n_u32(a,b) __ndp2_wrk_dq_u16_u32_k((a),__is_constrange(1,16,b),0xf2900810) /* VSHRN.I32 d0,q0,#16 */
#define vshrn_n_u64(a,b) __ndp2_wrk_dq_u32_u64_k((a),__is_constrange(1,32,b),0xf2a00810) /* VSHRN.I64 d0,q0,#32 */
#define vqshrun_n_s16(a,b) __ndp2_wrk_dq_u8_s16_k((a),__is_constrange(1,8,b),0xf3880810) /* VQSHRUN.S16 d0,q0,#8 */
#define vqshrun_n_s32(a,b) __ndp2_wrk_dq_u16_s32_k((a),__is_constrange(1,16,b),0xf3900810) /* VQSHRUN.S32 d0,q0,#16 */
#define vqshrun_n_s64(a,b) __ndp2_wrk_dq_u32_s64_k((a),__is_constrange(1,32,b),0xf3a00810) /* VQSHRUN.S64 d0,q0,#32 */
#define vqrshrun_n_s16(a,b) __ndp2_wrk_dq_u8_s16_k((a),__is_constrange(1,8,b),0xf3880850) /* VQRSHRUN.S16 d0,q0,#8 */
#define vqrshrun_n_s32(a,b) __ndp2_wrk_dq_u16_s32_k((a),__is_constrange(1,16,b),0xf3900850) /* VQRSHRUN.S32 d0,q0,#16 */
#define vqrshrun_n_s64(a,b) __ndp2_wrk_dq_u32_s64_k((a),__is_constrange(1,32,b),0xf3a00850) /* VQRSHRUN.S64 d0,q0,#32 */
#define vqshrn_n_s16(a,b) __ndp2_wrk_dq_s8_s16_k((a),__is_constrange(1,8,b),0xf2880910) /* VQSHRN.S16 d0,q0,#8 */
#define vqshrn_n_s32(a,b) __ndp2_wrk_dq_s16_s32_k((a),__is_constrange(1,16,b),0xf2900910) /* VQSHRN.S32 d0,q0,#16 */
#define vqshrn_n_s64(a,b) __ndp2_wrk_dq_s32_s64_k((a),__is_constrange(1,32,b),0xf2a00910) /* VQSHRN.S64 d0,q0,#32 */
#define vqshrn_n_u16(a,b) __ndp2_wrk_dq_u8_u16_k((a),__is_constrange(1,8,b),0xf3880910) /* VQSHRN.U16 d0,q0,#8 */
#define vqshrn_n_u32(a,b) __ndp2_wrk_dq_u16_u32_k((a),__is_constrange(1,16,b),0xf3900910) /* VQSHRN.U32 d0,q0,#16 */
#define vqshrn_n_u64(a,b) __ndp2_wrk_dq_u32_u64_k((a),__is_constrange(1,32,b),0xf3a00910) /* VQSHRN.U64 d0,q0,#32 */
#define vrshrn_n_s16(a,b) __ndp2_wrk_dq_s8_s16_k((a),__is_constrange(1,8,b),0xf2880850) /* VRSHRN.I16 d0,q0,#8 */
#define vrshrn_n_s32(a,b) __ndp2_wrk_dq_s16_s32_k((a),__is_constrange(1,16,b),0xf2900850) /* VRSHRN.I32 d0,q0,#16 */
#define vrshrn_n_s64(a,b) __ndp2_wrk_dq_s32_s64_k((a),__is_constrange(1,32,b),0xf2a00850) /* VRSHRN.I64 d0,q0,#32 */
#define vrshrn_n_u16(a,b) __ndp2_wrk_dq_u8_u16_k((a),__is_constrange(1,8,b),0xf2880850) /* VRSHRN.I16 d0,q0,#8 */
#define vrshrn_n_u32(a,b) __ndp2_wrk_dq_u16_u32_k((a),__is_constrange(1,16,b),0xf2900850) /* VRSHRN.I32 d0,q0,#16 */
#define vrshrn_n_u64(a,b) __ndp2_wrk_dq_u32_u64_k((a),__is_constrange(1,32,b),0xf2a00850) /* VRSHRN.I64 d0,q0,#32 */
#define vqrshrn_n_s16(a,b) __ndp2_wrk_dq_s8_s16_k((a),__is_constrange(1,8,b),0xf2880950) /* VQRSHRN.S16 d0,q0,#8 */
#define vqrshrn_n_s32(a,b) __ndp2_wrk_dq_s16_s32_k((a),__is_constrange(1,16,b),0xf2900950) /* VQRSHRN.S32 d0,q0,#16 */
#define vqrshrn_n_s64(a,b) __ndp2_wrk_dq_s32_s64_k((a),__is_constrange(1,32,b),0xf2a00950) /* VQRSHRN.S64 d0,q0,#32 */
#define vqrshrn_n_u16(a,b) __ndp2_wrk_dq_u8_u16_k((a),__is_constrange(1,8,b),0xf3880950) /* VQRSHRN.U16 d0,q0,#8 */
#define vqrshrn_n_u32(a,b) __ndp2_wrk_dq_u16_u32_k((a),__is_constrange(1,16,b),0xf3900950) /* VQRSHRN.U32 d0,q0,#16 */
#define vqrshrn_n_u64(a,b) __ndp2_wrk_dq_u32_u64_k((a),__is_constrange(1,32,b),0xf3a00950) /* VQRSHRN.U64 d0,q0,#32 */
#define vshll_n_s8(a,b) __ndp2_wrk_qd_s16_s8_k((a),__is_constrange(0,8,b),0xf2880a10) /* VSHLL.S8 q0,d0,#0 */
#define vshll_n_s16(a,b) __ndp2_wrk_qd_s32_s16_k((a),__is_constrange(0,16,b),0xf2900a10) /* VSHLL.S16 q0,d0,#0 */
#define vshll_n_s32(a,b) __ndp2_wrk_qd_s64_s32_k((a),__is_constrange(0,32,b),0xf2a00a10) /* VSHLL.S32 q0,d0,#0 */
#define vshll_n_u8(a,b) __ndp2_wrk_qd_u16_u8_k((a),__is_constrange(0,8,b),0xf3880a10) /* VSHLL.U8 q0,d0,#0 */
#define vshll_n_u16(a,b) __ndp2_wrk_qd_u32_u16_k((a),__is_constrange(0,16,b),0xf3900a10) /* VSHLL.U16 q0,d0,#0 */
#define vshll_n_u32(a,b) __ndp2_wrk_qd_u64_u32_k((a),__is_constrange(0,32,b),0xf3a00a10) /* VSHLL.U32 q0,d0,#0 */
#define vsri_n_s8(a,b,c) __ndp2_xrk_dd_s8_k((a),(b),__is_constrange(1,8,c),0xf3880410) /* VSRI.8 d0,d0,#8 */
#define vsri_n_s16(a,b,c) __ndp2_xrk_dd_s16_k((a),(b),__is_constrange(1,16,c),0xf3900410) /* VSRI.16 d0,d0,#16 */
#define vsri_n_s32(a,b,c) __ndp2_xrk_dd_s32_k((a),(b),__is_constrange(1,32,c),0xf3a00410) /* VSRI.32 d0,d0,#32 */
#define vsri_n_s64(a,b,c) __ndp2_xrk_dd_s64_k((a),(b),__is_constrange(1,64,c),0xf3800490) /* VSRI.64 d0,d0,#64 */
#define vsri_n_u8(a,b,c) __ndp2_xrk_dd_u8_k((a),(b),__is_constrange(1,8,c),0xf3880410) /* VSRI.8 d0,d0,#8 */
#define vsri_n_u16(a,b,c) __ndp2_xrk_dd_u16_k((a),(b),__is_constrange(1,16,c),0xf3900410) /* VSRI.16 d0,d0,#16 */
#define vsri_n_u32(a,b,c) __ndp2_xrk_dd_u32_k((a),(b),__is_constrange(1,32,c),0xf3a00410) /* VSRI.32 d0,d0,#32 */
#define vsri_n_u64(a,b,c) __ndp2_xrk_dd_u64_k((a),(b),__is_constrange(1,64,c),0xf3800490) /* VSRI.64 d0,d0,#64 */
#define vsri_n_p8(a,b,c) __ndp2_xrk_dd_p8_k((a),(b),__is_constrange(1,8,c),0xf3880410) /* VSRI.8 d0,d0,#8 */
#define vsri_n_p16(a,b,c) __ndp2_xrk_dd_p16_k((a),(b),__is_constrange(1,16,c),0xf3900410) /* VSRI.16 d0,d0,#16 */
#define vsriq_n_s8(a,b,c) __ndp2_xrk_qq_s8_k((a),(b),__is_constrange(1,8,c),0xf3880450) /* VSRI.8 q0,q0,#8 */
#define vsriq_n_s16(a,b,c) __ndp2_xrk_qq_s16_k((a),(b),__is_constrange(1,16,c),0xf3900450) /* VSRI.16 q0,q0,#16 */
#define vsriq_n_s32(a,b,c) __ndp2_xrk_qq_s32_k((a),(b),__is_constrange(1,32,c),0xf3a00450) /* VSRI.32 q0,q0,#32 */
#define vsriq_n_s64(a,b,c) __ndp2_xrk_qq_s64_k((a),(b),__is_constrange(1,64,c),0xf38004d0) /* VSRI.64 q0,q0,#64 */
#define vsriq_n_u8(a,b,c) __ndp2_xrk_qq_u8_k((a),(b),__is_constrange(1,8,c),0xf3880450) /* VSRI.8 q0,q0,#8 */
#define vsriq_n_u16(a,b,c) __ndp2_xrk_qq_u16_k((a),(b),__is_constrange(1,16,c),0xf3900450) /* VSRI.16 q0,q0,#16 */
#define vsriq_n_u32(a,b,c) __ndp2_xrk_qq_u32_k((a),(b),__is_constrange(1,32,c),0xf3a00450) /* VSRI.32 q0,q0,#32 */
#define vsriq_n_u64(a,b,c) __ndp2_xrk_qq_u64_k((a),(b),__is_constrange(1,64,c),0xf38004d0) /* VSRI.64 q0,q0,#64 */
#define vsriq_n_p8(a,b,c) __ndp2_xrk_qq_p8_k((a),(b),__is_constrange(1,8,c),0xf3880450) /* VSRI.8 q0,q0,#8 */
#define vsriq_n_p16(a,b,c) __ndp2_xrk_qq_p16_k((a),(b),__is_constrange(1,16,c),0xf3900450) /* VSRI.16 q0,q0,#16 */
#define vsli_n_s8(a,b,c) __ndp2_xrk_dd_s8_k((a),(b),__is_constrange(0,7,c),0xf3880510) /* VSLI.8 d0,d0,#0 */
#define vsli_n_s16(a,b,c) __ndp2_xrk_dd_s16_k((a),(b),__is_constrange(0,15,c),0xf3900510) /* VSLI.16 d0,d0,#0 */
#define vsli_n_s32(a,b,c) __ndp2_xrk_dd_s32_k((a),(b),__is_constrange(0,31,c),0xf3a00510) /* VSLI.32 d0,d0,#0 */
#define vsli_n_s64(a,b,c) __ndp2_xrk_dd_s64_k((a),(b),__is_constrange(0,63,c),0xf3800590) /* VSLI.64 d0,d0,#0 */
#define vsli_n_u8(a,b,c) __ndp2_xrk_dd_u8_k((a),(b),__is_constrange(0,7,c),0xf3880510) /* VSLI.8 d0,d0,#0 */
#define vsli_n_u16(a,b,c) __ndp2_xrk_dd_u16_k((a),(b),__is_constrange(0,15,c),0xf3900510) /* VSLI.16 d0,d0,#0 */
#define vsli_n_u32(a,b,c) __ndp2_xrk_dd_u32_k((a),(b),__is_constrange(0,31,c),0xf3a00510) /* VSLI.32 d0,d0,#0 */
#define vsli_n_u64(a,b,c) __ndp2_xrk_dd_u64_k((a),(b),__is_constrange(0,63,c),0xf3800590) /* VSLI.64 d0,d0,#0 */
#define vsli_n_p8(a,b,c) __ndp2_xrk_dd_p8_k((a),(b),__is_constrange(0,7,c),0xf3880510) /* VSLI.8 d0,d0,#0 */
#define vsli_n_p16(a,b,c) __ndp2_xrk_dd_p16_k((a),(b),__is_constrange(0,15,c),0xf3900510) /* VSLI.16 d0,d0,#0 */
#define vsliq_n_s8(a,b,c) __ndp2_xrk_qq_s8_k((a),(b),__is_constrange(0,7,c),0xf3880550) /* VSLI.8 q0,q0,#0 */
#define vsliq_n_s16(a,b,c) __ndp2_xrk_qq_s16_k((a),(b),__is_constrange(0,15,c),0xf3900550) /* VSLI.16 q0,q0,#0 */
#define vsliq_n_s32(a,b,c) __ndp2_xrk_qq_s32_k((a),(b),__is_constrange(0,31,c),0xf3a00550) /* VSLI.32 q0,q0,#0 */
#define vsliq_n_s64(a,b,c) __ndp2_xrk_qq_s64_k((a),(b),__is_constrange(0,63,c),0xf38005d0) /* VSLI.64 q0,q0,#0 */
#define vsliq_n_u8(a,b,c) __ndp2_xrk_qq_u8_k((a),(b),__is_constrange(0,7,c),0xf3880550) /* VSLI.8 q0,q0,#0 */
#define vsliq_n_u16(a,b,c) __ndp2_xrk_qq_u16_k((a),(b),__is_constrange(0,15,c),0xf3900550) /* VSLI.16 q0,q0,#0 */
#define vsliq_n_u32(a,b,c) __ndp2_xrk_qq_u32_k((a),(b),__is_constrange(0,31,c),0xf3a00550) /* VSLI.32 q0,q0,#0 */
#define vsliq_n_u64(a,b,c) __ndp2_xrk_qq_u64_k((a),(b),__is_constrange(0,63,c),0xf38005d0) /* VSLI.64 q0,q0,#0 */
#define vsliq_n_p8(a,b,c) __ndp2_xrk_qq_p8_k((a),(b),__is_constrange(0,7,c),0xf3880550) /* VSLI.8 q0,q0,#0 */
#define vsliq_n_p16(a,b,c) __ndp2_xrk_qq_p16_k((a),(b),__is_constrange(0,15,c),0xf3900550) /* VSLI.16 q0,q0,#0 */
#define vld1q_u8(ptr) __vld_wr_q0_u8((ptr),0xf4200a0f) /* VLD1.8 {d0, d1}, [r0] */
#define vld1q_u16(ptr) __vld_wr_q0_u16((ptr),0xf4200a4f) /* VLD1.16 {d0, d1}, [r0] */
#define vld1q_u32(ptr) __vld_wr_q0_u32((ptr),0xf4200a8f) /* VLD1.32 {d0, d1}, [r0] */
#define vld1q_u64(ptr) __vld_wr_q0_u64((ptr),0xf4200acf) /* VLD1.64 {d0, d1}, [r0] */
#define vld1q_s8(ptr) __vld_wr_q0_s8((ptr),0xf4200a0f) /* VLD1.8 {d0, d1}, [r0] */
#define vld1q_s16(ptr) __vld_wr_q0_s16((ptr),0xf4200a4f) /* VLD1.16 {d0, d1}, [r0] */
#define vld1q_s32(ptr) __vld_wr_q0_s32((ptr),0xf4200a8f) /* VLD1.32 {d0, d1}, [r0] */
#define vld1q_s64(ptr) __vld_wr_q0_s64((ptr),0xf4200acf) /* VLD1.64 {d0, d1}, [r0] */
#define vld1q_f32(ptr) __vld_wr_q0_f32((ptr),0xf4200a8f) /* VLD1.32 {d0, d1}, [r0] */
#define vld1q_p8(ptr) __vld_wr_q0_p8((ptr),0xf4200a0f) /* VLD1.8 {d0, d1}, [r0] */
#define vld1q_p16(ptr) __vld_wr_q0_p16((ptr),0xf4200a4f) /* VLD1.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld1q_f16(ptr) __vld_wr_q0_f16((ptr),0xf4200a4f) /* VLD1.16 {d0, d1}, [r0] */
#endif
#define vld1_u8(ptr) __vld_wr_d0_u8((ptr),0xf420070f) /* VLD1.8 {d0}, [r0] */
#define vld1_u16(ptr) __vld_wr_d0_u16((ptr),0xf420074f) /* VLD1.16 {d0}, [r0] */
#define vld1_u32(ptr) __vld_wr_d0_u32((ptr),0xf420078f) /* VLD1.32 {d0}, [r0] */
#define vld1_u64(ptr) __vld_wr_d0_u64((ptr),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1_s8(ptr) __vld_wr_d0_s8((ptr),0xf420070f) /* VLD1.8 {d0}, [r0] */
#define vld1_s16(ptr) __vld_wr_d0_s16((ptr),0xf420074f) /* VLD1.16 {d0}, [r0] */
#define vld1_s32(ptr) __vld_wr_d0_s32((ptr),0xf420078f) /* VLD1.32 {d0}, [r0] */
#define vld1_s64(ptr) __vld_wr_d0_s64((ptr),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1_f32(ptr) __vld_wr_d0_f32((ptr),0xf420078f) /* VLD1.32 {d0}, [r0] */
#define vld1_p8(ptr) __vld_wr_d0_p8((ptr),0xf420070f) /* VLD1.8 {d0}, [r0] */
#define vld1_p16(ptr) __vld_wr_d0_p16((ptr),0xf420074f) /* VLD1.16 {d0}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld1_f16(ptr) __vld_wr_d0_f16((ptr),0xf420074f) /* VLD1.16 {d0}, [r0] */
#endif
#define vld1q_lane_u8(ptr,vec,lane) __vld_xr_q0_u8_k((ptr),(vec),__is_constrange(0,15,lane),0xf4a0000f) /* VLD1.8 {d0[0]}, [r0] */
#define vld1q_lane_u16(ptr,vec,lane) __vld_xr_q0_u16_k((ptr),(vec),__is_constrange(0,7,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#define vld1q_lane_u32(ptr,vec,lane) __vld_xr_q0_u32_k((ptr),(vec),__is_constrange(0,3,lane),0xf4a0080f) /* VLD1.32 {d0[0]}, [r0] */
#define vld1q_lane_u64(ptr,vec,lane) __vld_xr_q0_u64_k((ptr),(vec),__is_constrange(0,1,lane),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1q_lane_s8(ptr,vec,lane) __vld_xr_q0_s8_k((ptr),(vec),__is_constrange(0,15,lane),0xf4a0000f) /* VLD1.8 {d0[0]}, [r0] */
#define vld1q_lane_s16(ptr,vec,lane) __vld_xr_q0_s16_k((ptr),(vec),__is_constrange(0,7,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#define vld1q_lane_s32(ptr,vec,lane) __vld_xr_q0_s32_k((ptr),(vec),__is_constrange(0,3,lane),0xf4a0080f) /* VLD1.32 {d0[0]}, [r0] */
#define vld1q_lane_f32(ptr,vec,lane) __vld_xr_q0_f32_k((ptr),(vec),__is_constrange(0,3,lane),0xf4a0080f) /* VLD1.32 {d0[0]}, [r0] */
#define vld1q_lane_s64(ptr,vec,lane) __vld_xr_q0_s64_k((ptr),(vec),__is_constrange(0,1,lane),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1q_lane_p8(ptr,vec,lane) __vld_xr_q0_p8_k((ptr),(vec),__is_constrange(0,15,lane),0xf4a0000f) /* VLD1.8 {d0[0]}, [r0] */
#define vld1q_lane_p16(ptr,vec,lane) __vld_xr_q0_p16_k((ptr),(vec),__is_constrange(0,7,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld1q_lane_f16(ptr,vec,lane) __vld_xr_q0_f16_k((ptr),(vec),__is_constrange(0,7,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#endif
#define vld1_lane_u8(ptr,vec,lane) __vld_xr_d0_u8_k((ptr),(vec),__is_constrange(0,7,lane),0xf4a0000f) /* VLD1.8 {d0[0]}, [r0] */
#define vld1_lane_u16(ptr,vec,lane) __vld_xr_d0_u16_k((ptr),(vec),__is_constrange(0,3,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#define vld1_lane_u32(ptr,vec,lane) __vld_xr_d0_u32_k((ptr),(vec),__is_constrange(0,1,lane),0xf4a0080f) /* VLD1.32 {d0[0]}, [r0] */
#define vld1_lane_u64(ptr,vec,lane) __vld_xr_d0_u64_k((ptr),(vec),__is_constrange(0,0,lane),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1_lane_s8(ptr,vec,lane) __vld_xr_d0_s8_k((ptr),(vec),__is_constrange(0,7,lane),0xf4a0000f) /* VLD1.8 {d0[0]}, [r0] */
#define vld1_lane_s16(ptr,vec,lane) __vld_xr_d0_s16_k((ptr),(vec),__is_constrange(0,3,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#define vld1_lane_s32(ptr,vec,lane) __vld_xr_d0_s32_k((ptr),(vec),__is_constrange(0,1,lane),0xf4a0080f) /* VLD1.32 {d0[0]}, [r0] */
#define vld1_lane_f32(ptr,vec,lane) __vld_xr_d0_f32_k((ptr),(vec),__is_constrange(0,1,lane),0xf4a0080f) /* VLD1.32 {d0[0]}, [r0] */
#define vld1_lane_s64(ptr,vec,lane) __vld_xr_d0_s64_k((ptr),(vec),__is_constrange(0,0,lane),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1_lane_p8(ptr,vec,lane) __vld_xr_d0_p8_k((ptr),(vec),__is_constrange(0,7,lane),0xf4a0000f) /* VLD1.8 {d0[0]}, [r0] */
#define vld1_lane_p16(ptr,vec,lane) __vld_xr_d0_p16_k((ptr),(vec),__is_constrange(0,3,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld1_lane_f16(ptr,vec,lane) __vld_xr_d0_f16_k((ptr),(vec),__is_constrange(0,3,lane),0xf4a0040f) /* VLD1.16 {d0[0]}, [r0] */
#endif
#define vld1q_dup_u8(ptr) __vld_wr_extq0_u8((ptr),0xf4a00c0f) /* VLD1.8 {d0[]}, [r0] */
#define vld1q_dup_u16(ptr) __vld_wr_extq0_u16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#define vld1q_dup_u32(ptr) __vld_wr_extq0_u32((ptr),0xf4a00c8f) /* VLD1.32 {d0[]}, [r0] */
#define vld1q_dup_u64(ptr) __vld_wr_extq0_u64((ptr),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1q_dup_s8(ptr) __vld_wr_extq0_s8((ptr),0xf4a00c0f) /* VLD1.8 {d0[]}, [r0] */
#define vld1q_dup_s16(ptr) __vld_wr_extq0_s16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#define vld1q_dup_s32(ptr) __vld_wr_extq0_s32((ptr),0xf4a00c8f) /* VLD1.32 {d0[]}, [r0] */
#define vld1q_dup_s64(ptr) __vld_wr_extq0_s64((ptr),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1q_dup_f32(ptr) __vld_wr_extq0_f32((ptr),0xf4a00c8f) /* VLD1.32 {d0[]}, [r0] */
#define vld1q_dup_p8(ptr) __vld_wr_extq0_p8((ptr),0xf4a00c0f) /* VLD1.8 {d0[]}, [r0] */
#define vld1q_dup_p16(ptr) __vld_wr_extq0_p16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld1q_dup_f16(ptr) __vld_wr_extq0_f16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#endif
#define vld1_dup_u8(ptr) __vld_wr_d0_u8((ptr),0xf4a00c0f) /* VLD1.8 {d0[]}, [r0] */
#define vld1_dup_u16(ptr) __vld_wr_d0_u16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#define vld1_dup_u32(ptr) __vld_wr_d0_u32((ptr),0xf4a00c8f) /* VLD1.32 {d0[]}, [r0] */
#define vld1_dup_u64(ptr) __vld_wr_d0_u64((ptr),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1_dup_s8(ptr) __vld_wr_d0_s8((ptr),0xf4a00c0f) /* VLD1.8 {d0[]}, [r0] */
#define vld1_dup_s16(ptr) __vld_wr_d0_s16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#define vld1_dup_s32(ptr) __vld_wr_d0_s32((ptr),0xf4a00c8f) /* VLD1.32 {d0[]}, [r0] */
#define vld1_dup_s64(ptr) __vld_wr_d0_s64((ptr),0xf42007cf) /* VLD1.64 {d0}, [r0] */
#define vld1_dup_f32(ptr) __vld_wr_d0_f32((ptr),0xf4a00c8f) /* VLD1.32 {d0[]}, [r0] */
#define vld1_dup_p8(ptr) __vld_wr_d0_p8((ptr),0xf4a00c0f) /* VLD1.8 {d0[]}, [r0] */
#define vld1_dup_p16(ptr) __vld_wr_d0_p16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld1_dup_f16(ptr) __vld_wr_d0_f16((ptr),0xf4a00c4f) /* VLD1.16 {d0[]}, [r0] */
#endif
#define vst1q_u8(ptr,val) __vst_rr_q0_u8((ptr),(val),0xf4000a0f) /* VST1.8 {d0, d1}, [r0] */
#define vst1q_u16(ptr,val) __vst_rr_q0_u16((ptr),(val),0xf4000a4f) /* VST1.16 {d0, d1}, [r0] */
#define vst1q_u32(ptr,val) __vst_rr_q0_u32((ptr),(val),0xf4000a8f) /* VST1.32 {d0, d1}, [r0] */
#define vst1q_u64(ptr,val) __vst_rr_q0_u64((ptr),(val),0xf4000acf) /* VST1.64 {d0, d1}, [r0] */
#define vst1q_s8(ptr,val) __vst_rr_q0_s8((ptr),(val),0xf4000a0f) /* VST1.8 {d0, d1}, [r0] */
#define vst1q_s16(ptr,val) __vst_rr_q0_s16((ptr),(val),0xf4000a4f) /* VST1.16 {d0, d1}, [r0] */
#define vst1q_s32(ptr,val) __vst_rr_q0_s32((ptr),(val),0xf4000a8f) /* VST1.32 {d0, d1}, [r0] */
#define vst1q_s64(ptr,val) __vst_rr_q0_s64((ptr),(val),0xf4000acf) /* VST1.64 {d0, d1}, [r0] */
#define vst1q_f32(ptr,val) __vst_rr_q0_f32((ptr),(val),0xf4000a8f) /* VST1.32 {d0, d1}, [r0] */
#define vst1q_p8(ptr,val) __vst_rr_q0_p8((ptr),(val),0xf4000a0f) /* VST1.8 {d0, d1}, [r0] */
#define vst1q_p16(ptr,val) __vst_rr_q0_p16((ptr),(val),0xf4000a4f) /* VST1.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst1q_f16(ptr,val) __vst_rr_q0_f16((ptr),(val),0xf4000a4f) /* VST1.16 {d0, d1}, [r0] */
#endif
#define vst1_u8(ptr,val) __vst_rr_d0_u8((ptr),(val),0xf400070f) /* VST1.8 {d0}, [r0] */
#define vst1_u16(ptr,val) __vst_rr_d0_u16((ptr),(val),0xf400074f) /* VST1.16 {d0}, [r0] */
#define vst1_u32(ptr,val) __vst_rr_d0_u32((ptr),(val),0xf400078f) /* VST1.32 {d0}, [r0] */
#define vst1_u64(ptr,val) __vst_rr_d0_u64((ptr),(val),0xf40007cf) /* VST1.64 {d0}, [r0] */
#define vst1_s8(ptr,val) __vst_rr_d0_s8((ptr),(val),0xf400070f) /* VST1.8 {d0}, [r0] */
#define vst1_s16(ptr,val) __vst_rr_d0_s16((ptr),(val),0xf400074f) /* VST1.16 {d0}, [r0] */
#define vst1_s32(ptr,val) __vst_rr_d0_s32((ptr),(val),0xf400078f) /* VST1.32 {d0}, [r0] */
#define vst1_s64(ptr,val) __vst_rr_d0_s64((ptr),(val),0xf40007cf) /* VST1.64 {d0}, [r0] */
#define vst1_f32(ptr,val) __vst_rr_d0_f32((ptr),(val),0xf400078f) /* VST1.32 {d0}, [r0] */
#define vst1_p8(ptr,val) __vst_rr_d0_p8((ptr),(val),0xf400070f) /* VST1.8 {d0}, [r0] */
#define vst1_p16(ptr,val) __vst_rr_d0_p16((ptr),(val),0xf400074f) /* VST1.16 {d0}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst1_f16(ptr,val) __vst_rr_d0_f16((ptr),(val),0xf400074f) /* VST1.16 {d0}, [r0] */
#endif
#define vst1q_lane_u8(ptr,val,lane) __vst_rrk_q0_u8_k((ptr),(val),__is_constrange(0,15,lane),0xf480000f) /* VST1.8 {d0[0]}, [r0] */
#define vst1q_lane_u16(ptr,val,lane) __vst_rrk_q0_u16_k((ptr),(val),__is_constrange(0,7,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#define vst1q_lane_u32(ptr,val,lane) __vst_rrk_q0_u32_k((ptr),(val),__is_constrange(0,3,lane),0xf480080f) /* VST1.32 {d0[0]}, [r0] */
#define vst1q_lane_u64(ptr,val,lane) __vst_rrk_q0_u64_k((ptr),(val),__is_constrange(0,1,lane),0xf40007cf) /* VST1.64 {d0}, [r0] */
#define vst1q_lane_s8(ptr,val,lane) __vst_rrk_q0_s8_k((ptr),(val),__is_constrange(0,15,lane),0xf480000f) /* VST1.8 {d0[0]}, [r0] */
#define vst1q_lane_s16(ptr,val,lane) __vst_rrk_q0_s16_k((ptr),(val),__is_constrange(0,7,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#define vst1q_lane_s32(ptr,val,lane) __vst_rrk_q0_s32_k((ptr),(val),__is_constrange(0,3,lane),0xf480080f) /* VST1.32 {d0[0]}, [r0] */
#define vst1q_lane_s64(ptr,val,lane) __vst_rrk_q0_s64_k((ptr),(val),__is_constrange(0,1,lane),0xf40007cf) /* VST1.64 {d0}, [r0] */
#define vst1q_lane_f32(ptr,val,lane) __vst_rrk_q0_f32_k((ptr),(val),__is_constrange(0,3,lane),0xf480080f) /* VST1.32 {d0[0]}, [r0] */
#define vst1q_lane_p8(ptr,val,lane) __vst_rrk_q0_p8_k((ptr),(val),__is_constrange(0,15,lane),0xf480000f) /* VST1.8 {d0[0]}, [r0] */
#define vst1q_lane_p16(ptr,val,lane) __vst_rrk_q0_p16_k((ptr),(val),__is_constrange(0,7,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst1q_lane_f16(ptr,val,lane) __vst_rrk_q0_f16_k((ptr),(val),__is_constrange(0,7,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#endif
#define vst1_lane_u8(ptr,val,lane) __vst_rrk_d0_u8_k((ptr),(val),__is_constrange(0,7,lane),0xf480000f) /* VST1.8 {d0[0]}, [r0] */
#define vst1_lane_u16(ptr,val,lane) __vst_rrk_d0_u16_k((ptr),(val),__is_constrange(0,3,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#define vst1_lane_u32(ptr,val,lane) __vst_rrk_d0_u32_k((ptr),(val),__is_constrange(0,1,lane),0xf480080f) /* VST1.32 {d0[0]}, [r0] */
#define vst1_lane_u64(ptr,val,lane) __vst_rrk_d0_u64_k((ptr),(val),__is_constrange(0,0,lane),0xf40007cf) /* VST1.64 {d0}, [r0] */
#define vst1_lane_s8(ptr,val,lane) __vst_rrk_d0_s8_k((ptr),(val),__is_constrange(0,7,lane),0xf480000f) /* VST1.8 {d0[0]}, [r0] */
#define vst1_lane_s16(ptr,val,lane) __vst_rrk_d0_s16_k((ptr),(val),__is_constrange(0,3,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#define vst1_lane_s32(ptr,val,lane) __vst_rrk_d0_s32_k((ptr),(val),__is_constrange(0,1,lane),0xf480080f) /* VST1.32 {d0[0]}, [r0] */
#define vst1_lane_s64(ptr,val,lane) __vst_rrk_d0_s64_k((ptr),(val),__is_constrange(0,0,lane),0xf40007cf) /* VST1.64 {d0}, [r0] */
#define vst1_lane_f32(ptr,val,lane) __vst_rrk_d0_f32_k((ptr),(val),__is_constrange(0,1,lane),0xf480080f) /* VST1.32 {d0[0]}, [r0] */
#define vst1_lane_p8(ptr,val,lane) __vst_rrk_d0_p8_k((ptr),(val),__is_constrange(0,7,lane),0xf480000f) /* VST1.8 {d0[0]}, [r0] */
#define vst1_lane_p16(ptr,val,lane) __vst_rrk_d0_p16_k((ptr),(val),__is_constrange(0,3,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst1_lane_f16(ptr,val,lane) __vst_rrk_d0_f16_k((ptr),(val),__is_constrange(0,3,lane),0xf480040f) /* VST1.16 {d0[0]}, [r0] */
#endif
#define vld2q_u8(ptr) __vld_wr_q01_u8((ptr),0xf420090f) /* VLD2.8 {d0, d2}, [r0] */
#define vld2q_u16(ptr) __vld_wr_q01_u16((ptr),0xf420094f) /* VLD2.16 {d0, d2}, [r0] */
#define vld2q_u32(ptr) __vld_wr_q01_u32((ptr),0xf420098f) /* VLD2.32 {d0, d2}, [r0] */
#define vld2q_s8(ptr) __vld_wr_q01_s8((ptr),0xf420090f) /* VLD2.8 {d0, d2}, [r0] */
#define vld2q_s16(ptr) __vld_wr_q01_s16((ptr),0xf420094f) /* VLD2.16 {d0, d2}, [r0] */
#define vld2q_s32(ptr) __vld_wr_q01_s32((ptr),0xf420098f) /* VLD2.32 {d0, d2}, [r0] */
#define vld2q_f32(ptr) __vld_wr_q01_f32((ptr),0xf420098f) /* VLD2.32 {d0, d2}, [r0] */
#define vld2q_p8(ptr) __vld_wr_q01_p8((ptr),0xf420090f) /* VLD2.8 {d0, d2}, [r0] */
#define vld2q_p16(ptr) __vld_wr_q01_p16((ptr),0xf420094f) /* VLD2.16 {d0, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld2q_f16(ptr) __vld_wr_q01_f16((ptr),0xf420094f) /* VLD2.16 {d0, d2}, [r0] */
#endif
#define vld2_u8(ptr) __vld_wr_d01_u8((ptr),0xf420080f) /* VLD2.8 {d0, d1}, [r0] */
#define vld2_u16(ptr) __vld_wr_d01_u16((ptr),0xf420084f) /* VLD2.16 {d0, d1}, [r0] */
#define vld2_u32(ptr) __vld_wr_d01_u32((ptr),0xf420088f) /* VLD2.32 {d0, d1}, [r0] */
#define vld2_u64(ptr) __vld_wr_d01_u64((ptr),0xf4200acf) /* VLD1.64 {d0, d1}, [r0] */
#define vld2_s8(ptr) __vld_wr_d01_s8((ptr),0xf420080f) /* VLD2.8 {d0, d1}, [r0] */
#define vld2_s16(ptr) __vld_wr_d01_s16((ptr),0xf420084f) /* VLD2.16 {d0, d1}, [r0] */
#define vld2_s32(ptr) __vld_wr_d01_s32((ptr),0xf420088f) /* VLD2.32 {d0, d1}, [r0] */
#define vld2_s64(ptr) __vld_wr_d01_s64((ptr),0xf4200acf) /* VLD1.64 {d0, d1}, [r0] */
#define vld2_f32(ptr) __vld_wr_d01_f32((ptr),0xf420088f) /* VLD2.32 {d0, d1}, [r0] */
#define vld2_p8(ptr) __vld_wr_d01_p8((ptr),0xf420080f) /* VLD2.8 {d0, d1}, [r0] */
#define vld2_p16(ptr) __vld_wr_d01_p16((ptr),0xf420084f) /* VLD2.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld2_f16(ptr) __vld_wr_d01_f16((ptr),0xf420084f) /* VLD2.16 {d0, d1}, [r0] */
#endif
#define vld3q_u8(ptr) __vld_wr_q012_u8((ptr),0xf420050f) /* VLD3.8 {d0, d2, d4}, [r0] */
#define vld3q_u16(ptr) __vld_wr_q012_u16((ptr),0xf420054f) /* VLD3.16 {d0, d2, d4}, [r0] */
#define vld3q_u32(ptr) __vld_wr_q012_u32((ptr),0xf420058f) /* VLD3.32 {d0, d2, d4}, [r0] */
#define vld3q_s8(ptr) __vld_wr_q012_s8((ptr),0xf420050f) /* VLD3.8 {d0, d2, d4}, [r0] */
#define vld3q_s16(ptr) __vld_wr_q012_s16((ptr),0xf420054f) /* VLD3.16 {d0, d2, d4}, [r0] */
#define vld3q_s32(ptr) __vld_wr_q012_s32((ptr),0xf420058f) /* VLD3.32 {d0, d2, d4}, [r0] */
#define vld3q_f32(ptr) __vld_wr_q012_f32((ptr),0xf420058f) /* VLD3.32 {d0, d2, d4}, [r0] */
#define vld3q_p8(ptr) __vld_wr_q012_p8((ptr),0xf420050f) /* VLD3.8 {d0, d2, d4}, [r0] */
#define vld3q_p16(ptr) __vld_wr_q012_p16((ptr),0xf420054f) /* VLD3.16 {d0, d2, d4}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld3q_f16(ptr) __vld_wr_q012_f16((ptr),0xf420054f) /* VLD3.16 {d0, d2, d4}, [r0] */
#endif
#define vld3_u8(ptr) __vld_wr_d012_u8((ptr),0xf420040f) /* VLD3.8 {d0, d1, d2}, [r0] */
#define vld3_u16(ptr) __vld_wr_d012_u16((ptr),0xf420044f) /* VLD3.16 {d0, d1, d2}, [r0] */
#define vld3_u32(ptr) __vld_wr_d012_u32((ptr),0xf420048f) /* VLD3.32 {d0, d1, d2}, [r0] */
#define vld3_u64(ptr) __vld_wr_d012_u64((ptr),0xf42006cf) /* VLD1.64 {d0, d1, d2}, [r0] */
#define vld3_s8(ptr) __vld_wr_d012_s8((ptr),0xf420040f) /* VLD3.8 {d0, d1, d2}, [r0] */
#define vld3_s16(ptr) __vld_wr_d012_s16((ptr),0xf420044f) /* VLD3.16 {d0, d1, d2}, [r0] */
#define vld3_s32(ptr) __vld_wr_d012_s32((ptr),0xf420048f) /* VLD3.32 {d0, d1, d2}, [r0] */
#define vld3_s64(ptr) __vld_wr_d012_s64((ptr),0xf42006cf) /* VLD1.64 {d0, d1, d2}, [r0] */
#define vld3_f32(ptr) __vld_wr_d012_f32((ptr),0xf420048f) /* VLD3.32 {d0, d1, d2}, [r0] */
#define vld3_p8(ptr) __vld_wr_d012_p8((ptr),0xf420040f) /* VLD3.8 {d0, d1, d2}, [r0] */
#define vld3_p16(ptr) __vld_wr_d012_p16((ptr),0xf420044f) /* VLD3.16 {d0, d1, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld3_f16(ptr) __vld_wr_d012_f16((ptr),0xf420044f) /* VLD3.16 {d0, d1, d2}, [r0] */
#endif
#define vld4q_u8(ptr) __vld_wr_q0123_u8((ptr),0xf420010f) /* VLD4.8 {d0, d2, d4, d6}, [r0] */
#define vld4q_u16(ptr) __vld_wr_q0123_u16((ptr),0xf420014f) /* VLD4.16 {d0, d2, d4, d6}, [r0] */
#define vld4q_u32(ptr) __vld_wr_q0123_u32((ptr),0xf420018f) /* VLD4.32 {d0, d2, d4, d6}, [r0] */
#define vld4q_s8(ptr) __vld_wr_q0123_s8((ptr),0xf420010f) /* VLD4.8 {d0, d2, d4, d6}, [r0] */
#define vld4q_s16(ptr) __vld_wr_q0123_s16((ptr),0xf420014f) /* VLD4.16 {d0, d2, d4, d6}, [r0] */
#define vld4q_s32(ptr) __vld_wr_q0123_s32((ptr),0xf420018f) /* VLD4.32 {d0, d2, d4, d6}, [r0] */
#define vld4q_f32(ptr) __vld_wr_q0123_f32((ptr),0xf420018f) /* VLD4.32 {d0, d2, d4, d6}, [r0] */
#define vld4q_p8(ptr) __vld_wr_q0123_p8((ptr),0xf420010f) /* VLD4.8 {d0, d2, d4, d6}, [r0] */
#define vld4q_p16(ptr) __vld_wr_q0123_p16((ptr),0xf420014f) /* VLD4.16 {d0, d2, d4, d6}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld4q_f16(ptr) __vld_wr_q0123_f16((ptr),0xf420014f) /* VLD4.16 {d0, d2, d4, d6}, [r0] */
#endif
#define vld4_u8(ptr) __vld_wr_d0123_u8((ptr),0xf420000f) /* VLD4.8 {d0, d1, d2, d3}, [r0] */
#define vld4_u16(ptr) __vld_wr_d0123_u16((ptr),0xf420004f) /* VLD4.16 {d0, d1, d2, d3}, [r0] */
#define vld4_u32(ptr) __vld_wr_d0123_u32((ptr),0xf420008f) /* VLD4.32 {d0, d1, d2, d3}, [r0] */
#define vld4_u64(ptr) __vld_wr_d0123_u64((ptr),0xf42002cf) /* VLD1.64 {d0, d1, d2, d3}, [r0] */
#define vld4_s8(ptr) __vld_wr_d0123_s8((ptr),0xf420000f) /* VLD4.8 {d0, d1, d2, d3}, [r0] */
#define vld4_s16(ptr) __vld_wr_d0123_s16((ptr),0xf420004f) /* VLD4.16 {d0, d1, d2, d3}, [r0] */
#define vld4_s32(ptr) __vld_wr_d0123_s32((ptr),0xf420008f) /* VLD4.32 {d0, d1, d2, d3}, [r0] */
#define vld4_s64(ptr) __vld_wr_d0123_s64((ptr),0xf42002cf) /* VLD1.64 {d0, d1, d2, d3}, [r0] */
#define vld4_f32(ptr) __vld_wr_d0123_f32((ptr),0xf420008f) /* VLD4.32 {d0, d1, d2, d3}, [r0] */
#define vld4_p8(ptr) __vld_wr_d0123_p8((ptr),0xf420000f) /* VLD4.8 {d0, d1, d2, d3}, [r0] */
#define vld4_p16(ptr) __vld_wr_d0123_p16((ptr),0xf420004f) /* VLD4.16 {d0, d1, d2, d3}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld4_f16(ptr) __vld_wr_d0123_f16((ptr),0xf420004f) /* VLD4.16 {d0, d1, d2, d3}, [r0] */
#endif
#define vld2_dup_u8(ptr) __vld_wr_d01_u8((ptr),0xf4a00d0f) /* VLD2.8 {d0[], d1[]}, [r0] */
#define vld2_dup_u16(ptr) __vld_wr_d01_u16((ptr),0xf4a00d4f) /* VLD2.16 {d0[], d1[]}, [r0] */
#define vld2_dup_u32(ptr) __vld_wr_d01_u32((ptr),0xf4a00d8f) /* VLD2.32 {d0[], d1[]}, [r0] */
#define vld2_dup_u64(ptr) __vld_wr_d01_u64((ptr),0xf4200acf) /* VLD1.64 {d0, d1}, [r0] */
#define vld2_dup_s8(ptr) __vld_wr_d01_s8((ptr),0xf4a00d0f) /* VLD2.8 {d0[], d1[]}, [r0] */
#define vld2_dup_s16(ptr) __vld_wr_d01_s16((ptr),0xf4a00d4f) /* VLD2.16 {d0[], d1[]}, [r0] */
#define vld2_dup_s32(ptr) __vld_wr_d01_s32((ptr),0xf4a00d8f) /* VLD2.32 {d0[], d1[]}, [r0] */
#define vld2_dup_s64(ptr) __vld_wr_d01_s64((ptr),0xf4200acf) /* VLD1.64 {d0, d1}, [r0] */
#define vld2_dup_f32(ptr) __vld_wr_d01_f32((ptr),0xf4a00d8f) /* VLD2.32 {d0[], d1[]}, [r0] */
#define vld2_dup_p8(ptr) __vld_wr_d01_p8((ptr),0xf4a00d0f) /* VLD2.8 {d0[], d1[]}, [r0] */
#define vld2_dup_p16(ptr) __vld_wr_d01_p16((ptr),0xf4a00d4f) /* VLD2.16 {d0[], d1[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld2_dup_f16(ptr) __vld_wr_d01_f16((ptr),0xf4a00d4f) /* VLD2.16 {d0[], d1[]}, [r0] */
#endif
#define vld3_dup_u8(ptr) __vld_wr_d012_u8((ptr),0xf4a00e0f) /* VLD3.8 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_u16(ptr) __vld_wr_d012_u16((ptr),0xf4a00e4f) /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_u32(ptr) __vld_wr_d012_u32((ptr),0xf4a00e8f) /* VLD3.32 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_u64(ptr) __vld_wr_d012_u64((ptr),0xf42006cf) /* VLD1.64 {d0, d1, d2}, [r0] */
#define vld3_dup_s8(ptr) __vld_wr_d012_s8((ptr),0xf4a00e0f) /* VLD3.8 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_s16(ptr) __vld_wr_d012_s16((ptr),0xf4a00e4f) /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_s32(ptr) __vld_wr_d012_s32((ptr),0xf4a00e8f) /* VLD3.32 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_s64(ptr) __vld_wr_d012_s64((ptr),0xf42006cf) /* VLD1.64 {d0, d1, d2}, [r0] */
#define vld3_dup_f32(ptr) __vld_wr_d012_f32((ptr),0xf4a00e8f) /* VLD3.32 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_p8(ptr) __vld_wr_d012_p8((ptr),0xf4a00e0f) /* VLD3.8 {d0[], d1[], d2[]}, [r0] */
#define vld3_dup_p16(ptr) __vld_wr_d012_p16((ptr),0xf4a00e4f) /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld3_dup_f16(ptr) __vld_wr_d012_f16((ptr),0xf4a00e4f) /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
#endif
#define vld4_dup_u8(ptr) __vld_wr_d0123_u8((ptr),0xf4a00f0f) /* VLD4.8 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_u16(ptr) __vld_wr_d0123_u16((ptr),0xf4a00f4f) /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_u32(ptr) __vld_wr_d0123_u32((ptr),0xf4a00f8f) /* VLD4.32 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_u64(ptr) __vld_wr_d0123_u64((ptr),0xf42002cf) /* VLD1.64 {d0, d1, d2, d3}, [r0] */
#define vld4_dup_s8(ptr) __vld_wr_d0123_s8((ptr),0xf4a00f0f) /* VLD4.8 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_s16(ptr) __vld_wr_d0123_s16((ptr),0xf4a00f4f) /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_s32(ptr) __vld_wr_d0123_s32((ptr),0xf4a00f8f) /* VLD4.32 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_s64(ptr) __vld_wr_d0123_s64((ptr),0xf42002cf) /* VLD1.64 {d0, d1, d2, d3}, [r0] */
#define vld4_dup_f32(ptr) __vld_wr_d0123_f32((ptr),0xf4a00f8f) /* VLD4.32 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_p8(ptr) __vld_wr_d0123_p8((ptr),0xf4a00f0f) /* VLD4.8 {d0[], d1[], d2[], d3[]}, [r0] */
#define vld4_dup_p16(ptr) __vld_wr_d0123_p16((ptr),0xf4a00f4f) /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld4_dup_f16(ptr) __vld_wr_d0123_f16((ptr),0xf4a00f4f) /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
#endif
#define vld2q_lane_u16(ptr,src,lane) __vld_xr_q01_u16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0052f) /* VLD2.16 {d0[0], d2[0]}, [r0] */
#define vld2q_lane_u32(ptr,src,lane) __vld_xr_q01_u32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0094f) /* VLD2.32 {d0[0], d2[0]}, [r0] */
#define vld2q_lane_s16(ptr,src,lane) __vld_xr_q01_s16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0052f) /* VLD2.16 {d0[0], d2[0]}, [r0] */
#define vld2q_lane_s32(ptr,src,lane) __vld_xr_q01_s32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0094f) /* VLD2.32 {d0[0], d2[0]}, [r0] */
#define vld2q_lane_f32(ptr,src,lane) __vld_xr_q01_f32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0094f) /* VLD2.32 {d0[0], d2[0]}, [r0] */
#define vld2q_lane_p16(ptr,src,lane) __vld_xr_q01_p16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0052f) /* VLD2.16 {d0[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld2q_lane_f16(ptr,src,lane) __vld_xr_q01_f16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0052f) /* VLD2.16 {d0[0], d2[0]}, [r0] */
#endif
#define vld2_lane_u8(ptr,src,lane) __vld_xr_d01_u8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0010f) /* VLD2.8 {d0[0], d1[0]}, [r0] */
#define vld2_lane_u16(ptr,src,lane) __vld_xr_d01_u16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0050f) /* VLD2.16 {d0[0], d1[0]}, [r0] */
#define vld2_lane_u32(ptr,src,lane) __vld_xr_d01_u32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a0090f) /* VLD2.32 {d0[0], d1[0]}, [r0] */
#define vld2_lane_s8(ptr,src,lane) __vld_xr_d01_s8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0010f) /* VLD2.8 {d0[0], d1[0]}, [r0] */
#define vld2_lane_s16(ptr,src,lane) __vld_xr_d01_s16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0050f) /* VLD2.16 {d0[0], d1[0]}, [r0] */
#define vld2_lane_s32(ptr,src,lane) __vld_xr_d01_s32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a0090f) /* VLD2.32 {d0[0], d1[0]}, [r0] */
#define vld2_lane_f32(ptr,src,lane) __vld_xr_d01_f32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a0090f) /* VLD2.32 {d0[0], d1[0]}, [r0] */
#define vld2_lane_p8(ptr,src,lane) __vld_xr_d01_p8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0010f) /* VLD2.8 {d0[0], d1[0]}, [r0] */
#define vld2_lane_p16(ptr,src,lane) __vld_xr_d01_p16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0050f) /* VLD2.16 {d0[0], d1[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld2_lane_f16(ptr,src,lane) __vld_xr_d01_f16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0050f) /* VLD2.16 {d0[0], d1[0]}, [r0] */
#endif
#define vld3q_lane_u16(ptr,src,lane) __vld_xr_q012_u16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0062f) /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
#define vld3q_lane_u32(ptr,src,lane) __vld_xr_q012_u32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a00a4f) /* VLD3.32 {d0[0], d2[0], d4[0]}, [r0] */
#define vld3q_lane_s16(ptr,src,lane) __vld_xr_q012_s16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0062f) /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
#define vld3q_lane_s32(ptr,src,lane) __vld_xr_q012_s32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a00a4f) /* VLD3.32 {d0[0], d2[0], d4[0]}, [r0] */
#define vld3q_lane_f32(ptr,src,lane) __vld_xr_q012_f32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a00a4f) /* VLD3.32 {d0[0], d2[0], d4[0]}, [r0] */
#define vld3q_lane_p16(ptr,src,lane) __vld_xr_q012_p16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0062f) /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld3q_lane_f16(ptr,src,lane) __vld_xr_q012_f16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0062f) /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
#endif
#define vld3_lane_u8(ptr,src,lane) __vld_xr_d012_u8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0020f) /* VLD3.8 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_u16(ptr,src,lane) __vld_xr_d012_u16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0060f) /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_u32(ptr,src,lane) __vld_xr_d012_u32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a00a0f) /* VLD3.32 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_s8(ptr,src,lane) __vld_xr_d012_s8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0020f) /* VLD3.8 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_s16(ptr,src,lane) __vld_xr_d012_s16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0060f) /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_s32(ptr,src,lane) __vld_xr_d012_s32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a00a0f) /* VLD3.32 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_f32(ptr,src,lane) __vld_xr_d012_f32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a00a0f) /* VLD3.32 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_p8(ptr,src,lane) __vld_xr_d012_p8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0020f) /* VLD3.8 {d0[0], d1[0], d2[0]}, [r0] */
#define vld3_lane_p16(ptr,src,lane) __vld_xr_d012_p16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0060f) /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld3_lane_f16(ptr,src,lane) __vld_xr_d012_f16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0060f) /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
#endif
#define vld4q_lane_u16(ptr,src,lane) __vld_xr_q0123_u16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0072f) /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vld4q_lane_u32(ptr,src,lane) __vld_xr_q0123_u32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a00b4f) /* VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vld4q_lane_s16(ptr,src,lane) __vld_xr_q0123_s16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0072f) /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vld4q_lane_s32(ptr,src,lane) __vld_xr_q0123_s32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a00b4f) /* VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vld4q_lane_f32(ptr,src,lane) __vld_xr_q0123_f32_k((ptr),(src),__is_constrange(0,3,lane),0xf4a00b4f) /* VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vld4q_lane_p16(ptr,src,lane) __vld_xr_q0123_p16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0072f) /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld4q_lane_f16(ptr,src,lane) __vld_xr_q0123_f16_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0072f) /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#endif
#define vld4_lane_u8(ptr,src,lane) __vld_xr_d0123_u8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0030f) /* VLD4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_u16(ptr,src,lane) __vld_xr_d0123_u16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0070f) /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_u32(ptr,src,lane) __vld_xr_d0123_u32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a00b0f) /* VLD4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_s8(ptr,src,lane) __vld_xr_d0123_s8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0030f) /* VLD4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_s16(ptr,src,lane) __vld_xr_d0123_s16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0070f) /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_s32(ptr,src,lane) __vld_xr_d0123_s32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a00b0f) /* VLD4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_f32(ptr,src,lane) __vld_xr_d0123_f32_k((ptr),(src),__is_constrange(0,1,lane),0xf4a00b0f) /* VLD4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_p8(ptr,src,lane) __vld_xr_d0123_p8_k((ptr),(src),__is_constrange(0,7,lane),0xf4a0030f) /* VLD4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vld4_lane_p16(ptr,src,lane) __vld_xr_d0123_p16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0070f) /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vld4_lane_f16(ptr,src,lane) __vld_xr_d0123_f16_k((ptr),(src),__is_constrange(0,3,lane),0xf4a0070f) /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#endif
#define vst2q_u8(ptr,val) __vst_rr_q01_u8((ptr),(val),0xf400090f) /* VST2.8 {d0, d2}, [r0] */
#define vst2q_u16(ptr,val) __vst_rr_q01_u16((ptr),(val),0xf400094f) /* VST2.16 {d0, d2}, [r0] */
#define vst2q_u32(ptr,val) __vst_rr_q01_u32((ptr),(val),0xf400098f) /* VST2.32 {d0, d2}, [r0] */
#define vst2q_s8(ptr,val) __vst_rr_q01_s8((ptr),(val),0xf400090f) /* VST2.8 {d0, d2}, [r0] */
#define vst2q_s16(ptr,val) __vst_rr_q01_s16((ptr),(val),0xf400094f) /* VST2.16 {d0, d2}, [r0] */
#define vst2q_s32(ptr,val) __vst_rr_q01_s32((ptr),(val),0xf400098f) /* VST2.32 {d0, d2}, [r0] */
#define vst2q_f32(ptr,val) __vst_rr_q01_f32((ptr),(val),0xf400098f) /* VST2.32 {d0, d2}, [r0] */
#define vst2q_p8(ptr,val) __vst_rr_q01_p8((ptr),(val),0xf400090f) /* VST2.8 {d0, d2}, [r0] */
#define vst2q_p16(ptr,val) __vst_rr_q01_p16((ptr),(val),0xf400094f) /* VST2.16 {d0, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst2q_f16(ptr,val) __vst_rr_q01_f16((ptr),(val),0xf400094f) /* VST2.16 {d0, d2}, [r0] */
#endif
#define vst2_u8(ptr,val) __vst_rr_d01_u8((ptr),(val),0xf400080f) /* VST2.8 {d0, d1}, [r0] */
#define vst2_u16(ptr,val) __vst_rr_d01_u16((ptr),(val),0xf400084f) /* VST2.16 {d0, d1}, [r0] */
#define vst2_u32(ptr,val) __vst_rr_d01_u32((ptr),(val),0xf400088f) /* VST2.32 {d0, d1}, [r0] */
#define vst2_u64(ptr,val) __vst_rr_d01_u64((ptr),(val),0xf4000acf) /* VST1.64 {d0, d1}, [r0] */
#define vst2_s8(ptr,val) __vst_rr_d01_s8((ptr),(val),0xf400080f) /* VST2.8 {d0, d1}, [r0] */
#define vst2_s16(ptr,val) __vst_rr_d01_s16((ptr),(val),0xf400084f) /* VST2.16 {d0, d1}, [r0] */
#define vst2_s32(ptr,val) __vst_rr_d01_s32((ptr),(val),0xf400088f) /* VST2.32 {d0, d1}, [r0] */
#define vst2_s64(ptr,val) __vst_rr_d01_s64((ptr),(val),0xf4000acf) /* VST1.64 {d0, d1}, [r0] */
#define vst2_f32(ptr,val) __vst_rr_d01_f32((ptr),(val),0xf400088f) /* VST2.32 {d0, d1}, [r0] */
#define vst2_p8(ptr,val) __vst_rr_d01_p8((ptr),(val),0xf400080f) /* VST2.8 {d0, d1}, [r0] */
#define vst2_p16(ptr,val) __vst_rr_d01_p16((ptr),(val),0xf400084f) /* VST2.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst2_f16(ptr,val) __vst_rr_d01_f16((ptr),(val),0xf400084f) /* VST2.16 {d0, d1}, [r0] */
#endif
#define vst3q_u8(ptr,val) __vst_rr_q012_u8((ptr),(val),0xf400050f) /* VST3.8 {d0, d2, d4}, [r0] */
#define vst3q_u16(ptr,val) __vst_rr_q012_u16((ptr),(val),0xf400054f) /* VST3.16 {d0, d2, d4}, [r0] */
#define vst3q_u32(ptr,val) __vst_rr_q012_u32((ptr),(val),0xf400058f) /* VST3.32 {d0, d2, d4}, [r0] */
#define vst3q_s8(ptr,val) __vst_rr_q012_s8((ptr),(val),0xf400050f) /* VST3.8 {d0, d2, d4}, [r0] */
#define vst3q_s16(ptr,val) __vst_rr_q012_s16((ptr),(val),0xf400054f) /* VST3.16 {d0, d2, d4}, [r0] */
#define vst3q_s32(ptr,val) __vst_rr_q012_s32((ptr),(val),0xf400058f) /* VST3.32 {d0, d2, d4}, [r0] */
#define vst3q_f32(ptr,val) __vst_rr_q012_f32((ptr),(val),0xf400058f) /* VST3.32 {d0, d2, d4}, [r0] */
#define vst3q_p8(ptr,val) __vst_rr_q012_p8((ptr),(val),0xf400050f) /* VST3.8 {d0, d2, d4}, [r0] */
#define vst3q_p16(ptr,val) __vst_rr_q012_p16((ptr),(val),0xf400054f) /* VST3.16 {d0, d2, d4}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst3q_f16(ptr,val) __vst_rr_q012_f16((ptr),(val),0xf400054f) /* VST3.16 {d0, d2, d4}, [r0] */
#endif
#define vst3_u8(ptr,val) __vst_rr_d012_u8((ptr),(val),0xf400040f) /* VST3.8 {d0, d1, d2}, [r0] */
#define vst3_u16(ptr,val) __vst_rr_d012_u16((ptr),(val),0xf400044f) /* VST3.16 {d0, d1, d2}, [r0] */
#define vst3_u32(ptr,val) __vst_rr_d012_u32((ptr),(val),0xf400048f) /* VST3.32 {d0, d1, d2}, [r0] */
#define vst3_u64(ptr,val) __vst_rr_d012_u64((ptr),(val),0xf40006cf) /* VST1.64 {d0, d1, d2}, [r0] */
#define vst3_s8(ptr,val) __vst_rr_d012_s8((ptr),(val),0xf400040f) /* VST3.8 {d0, d1, d2}, [r0] */
#define vst3_s16(ptr,val) __vst_rr_d012_s16((ptr),(val),0xf400044f) /* VST3.16 {d0, d1, d2}, [r0] */
#define vst3_s32(ptr,val) __vst_rr_d012_s32((ptr),(val),0xf400048f) /* VST3.32 {d0, d1, d2}, [r0] */
#define vst3_s64(ptr,val) __vst_rr_d012_s64((ptr),(val),0xf40006cf) /* VST1.64 {d0, d1, d2}, [r0] */
#define vst3_f32(ptr,val) __vst_rr_d012_f32((ptr),(val),0xf400048f) /* VST3.32 {d0, d1, d2}, [r0] */
#define vst3_p8(ptr,val) __vst_rr_d012_p8((ptr),(val),0xf400040f) /* VST3.8 {d0, d1, d2}, [r0] */
#define vst3_p16(ptr,val) __vst_rr_d012_p16((ptr),(val),0xf400044f) /* VST3.16 {d0, d1, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst3_f16(ptr,val) __vst_rr_d012_f16((ptr),(val),0xf400044f) /* VST3.16 {d0, d1, d2}, [r0] */
#endif
#define vst4q_u8(ptr,val) __vst_rr_q0123_u8((ptr),(val),0xf400010f) /* VST4.8 {d0, d2, d4, d6}, [r0] */
#define vst4q_u16(ptr,val) __vst_rr_q0123_u16((ptr),(val),0xf400014f) /* VST4.16 {d0, d2, d4, d6}, [r0] */
#define vst4q_u32(ptr,val) __vst_rr_q0123_u32((ptr),(val),0xf400018f) /* VST4.32 {d0, d2, d4, d6}, [r0] */
#define vst4q_s8(ptr,val) __vst_rr_q0123_s8((ptr),(val),0xf400010f) /* VST4.8 {d0, d2, d4, d6}, [r0] */
#define vst4q_s16(ptr,val) __vst_rr_q0123_s16((ptr),(val),0xf400014f) /* VST4.16 {d0, d2, d4, d6}, [r0] */
#define vst4q_s32(ptr,val) __vst_rr_q0123_s32((ptr),(val),0xf400018f) /* VST4.32 {d0, d2, d4, d6}, [r0] */
#define vst4q_f32(ptr,val) __vst_rr_q0123_f32((ptr),(val),0xf400018f) /* VST4.32 {d0, d2, d4, d6}, [r0] */
#define vst4q_p8(ptr,val) __vst_rr_q0123_p8((ptr),(val),0xf400010f) /* VST4.8 {d0, d2, d4, d6}, [r0] */
#define vst4q_p16(ptr,val) __vst_rr_q0123_p16((ptr),(val),0xf400014f) /* VST4.16 {d0, d2, d4, d6}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst4q_f16(ptr,val) __vst_rr_q0123_f16((ptr),(val),0xf400014f) /* VST4.16 {d0, d2, d4, d6}, [r0] */
#endif
#define vst4_u8(ptr,val) __vst_rr_d0123_u8((ptr),(val),0xf400000f) /* VST4.8 {d0, d1, d2, d3}, [r0] */
#define vst4_u16(ptr,val) __vst_rr_d0123_u16((ptr),(val),0xf400004f) /* VST4.16 {d0, d1, d2, d3}, [r0] */
#define vst4_u32(ptr,val) __vst_rr_d0123_u32((ptr),(val),0xf400008f) /* VST4.32 {d0, d1, d2, d3}, [r0] */
#define vst4_u64(ptr,val) __vst_rr_d0123_u64((ptr),(val),0xf40002cf) /* VST1.64 {d0, d1, d2, d3}, [r0] */
#define vst4_s8(ptr,val) __vst_rr_d0123_s8((ptr),(val),0xf400000f) /* VST4.8 {d0, d1, d2, d3}, [r0] */
#define vst4_s16(ptr,val) __vst_rr_d0123_s16((ptr),(val),0xf400004f) /* VST4.16 {d0, d1, d2, d3}, [r0] */
#define vst4_s32(ptr,val) __vst_rr_d0123_s32((ptr),(val),0xf400008f) /* VST4.32 {d0, d1, d2, d3}, [r0] */
#define vst4_s64(ptr,val) __vst_rr_d0123_s64((ptr),(val),0xf40002cf) /* VST1.64 {d0, d1, d2, d3}, [r0] */
#define vst4_f32(ptr,val) __vst_rr_d0123_f32((ptr),(val),0xf400008f) /* VST4.32 {d0, d1, d2, d3}, [r0] */
#define vst4_p8(ptr,val) __vst_rr_d0123_p8((ptr),(val),0xf400000f) /* VST4.8 {d0, d1, d2, d3}, [r0] */
#define vst4_p16(ptr,val) __vst_rr_d0123_p16((ptr),(val),0xf400004f) /* VST4.16 {d0, d1, d2, d3}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst4_f16(ptr,val) __vst_rr_d0123_f16((ptr),(val),0xf400004f) /* VST4.16 {d0, d1, d2, d3}, [r0] */
#endif
#define vst2q_lane_u16(ptr,val,lane) __vst_rrk_q01_u16_k((ptr),(val),__is_constrange(0,7,lane),0xf480052f) /* VST2.16 {d0[0], d2[0]}, [r0] */
#define vst2q_lane_u32(ptr,val,lane) __vst_rrk_q01_u32_k((ptr),(val),__is_constrange(0,3,lane),0xf480094f) /* VST2.32 {d0[0], d2[0]}, [r0] */
#define vst2q_lane_s16(ptr,val,lane) __vst_rrk_q01_s16_k((ptr),(val),__is_constrange(0,7,lane),0xf480052f) /* VST2.16 {d0[0], d2[0]}, [r0] */
#define vst2q_lane_s32(ptr,val,lane) __vst_rrk_q01_s32_k((ptr),(val),__is_constrange(0,3,lane),0xf480094f) /* VST2.32 {d0[0], d2[0]}, [r0] */
#define vst2q_lane_f32(ptr,val,lane) __vst_rrk_q01_f32_k((ptr),(val),__is_constrange(0,3,lane),0xf480094f) /* VST2.32 {d0[0], d2[0]}, [r0] */
#define vst2q_lane_p16(ptr,val,lane) __vst_rrk_q01_p16_k((ptr),(val),__is_constrange(0,7,lane),0xf480052f) /* VST2.16 {d0[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst2q_lane_f16(ptr,val,lane) __vst_rrk_q01_f16_k((ptr),(val),__is_constrange(0,7,lane),0xf480052f) /* VST2.16 {d0[0], d2[0]}, [r0] */
#endif
#define vst2_lane_u8(ptr,val,lane) __vst_rrk_d01_u8_k((ptr),(val),__is_constrange(0,7,lane),0xf480010f) /* VST2.8 {d0[0], d1[0]}, [r0] */
#define vst2_lane_u16(ptr,val,lane) __vst_rrk_d01_u16_k((ptr),(val),__is_constrange(0,3,lane),0xf480050f) /* VST2.16 {d0[0], d1[0]}, [r0] */
#define vst2_lane_u32(ptr,val,lane) __vst_rrk_d01_u32_k((ptr),(val),__is_constrange(0,1,lane),0xf480090f) /* VST2.32 {d0[0], d1[0]}, [r0] */
#define vst2_lane_s8(ptr,val,lane) __vst_rrk_d01_s8_k((ptr),(val),__is_constrange(0,7,lane),0xf480010f) /* VST2.8 {d0[0], d1[0]}, [r0] */
#define vst2_lane_s16(ptr,val,lane) __vst_rrk_d01_s16_k((ptr),(val),__is_constrange(0,3,lane),0xf480050f) /* VST2.16 {d0[0], d1[0]}, [r0] */
#define vst2_lane_s32(ptr,val,lane) __vst_rrk_d01_s32_k((ptr),(val),__is_constrange(0,1,lane),0xf480090f) /* VST2.32 {d0[0], d1[0]}, [r0] */
#define vst2_lane_f32(ptr,val,lane) __vst_rrk_d01_f32_k((ptr),(val),__is_constrange(0,1,lane),0xf480090f) /* VST2.32 {d0[0], d1[0]}, [r0] */
#define vst2_lane_p8(ptr,val,lane) __vst_rrk_d01_p8_k((ptr),(val),__is_constrange(0,7,lane),0xf480010f) /* VST2.8 {d0[0], d1[0]}, [r0] */
#define vst2_lane_p16(ptr,val,lane) __vst_rrk_d01_p16_k((ptr),(val),__is_constrange(0,3,lane),0xf480050f) /* VST2.16 {d0[0], d1[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst2_lane_f16(ptr,val,lane) __vst_rrk_d01_f16_k((ptr),(val),__is_constrange(0,3,lane),0xf480050f) /* VST2.16 {d0[0], d1[0]}, [r0] */
#endif
#define vst3q_lane_u16(ptr,val,lane) __vst_rrk_q012_u16_k((ptr),(val),__is_constrange(0,7,lane),0xf480062f) /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
#define vst3q_lane_u32(ptr,val,lane) __vst_rrk_q012_u32_k((ptr),(val),__is_constrange(0,3,lane),0xf4800a4f) /* VST3.32 {d0[0], d2[0], d4[0]}, [r0] */
#define vst3q_lane_s16(ptr,val,lane) __vst_rrk_q012_s16_k((ptr),(val),__is_constrange(0,7,lane),0xf480062f) /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
#define vst3q_lane_s32(ptr,val,lane) __vst_rrk_q012_s32_k((ptr),(val),__is_constrange(0,3,lane),0xf4800a4f) /* VST3.32 {d0[0], d2[0], d4[0]}, [r0] */
#define vst3q_lane_f32(ptr,val,lane) __vst_rrk_q012_f32_k((ptr),(val),__is_constrange(0,3,lane),0xf4800a4f) /* VST3.32 {d0[0], d2[0], d4[0]}, [r0] */
#define vst3q_lane_p16(ptr,val,lane) __vst_rrk_q012_p16_k((ptr),(val),__is_constrange(0,7,lane),0xf480062f) /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst3q_lane_f16(ptr,val,lane) __vst_rrk_q012_f16_k((ptr),(val),__is_constrange(0,7,lane),0xf480062f) /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
#endif
#define vst3_lane_u8(ptr,val,lane) __vst_rrk_d012_u8_k((ptr),(val),__is_constrange(0,7,lane),0xf480020f) /* VST3.8 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_u16(ptr,val,lane) __vst_rrk_d012_u16_k((ptr),(val),__is_constrange(0,3,lane),0xf480060f) /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_u32(ptr,val,lane) __vst_rrk_d012_u32_k((ptr),(val),__is_constrange(0,1,lane),0xf4800a0f) /* VST3.32 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_s8(ptr,val,lane) __vst_rrk_d012_s8_k((ptr),(val),__is_constrange(0,7,lane),0xf480020f) /* VST3.8 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_s16(ptr,val,lane) __vst_rrk_d012_s16_k((ptr),(val),__is_constrange(0,3,lane),0xf480060f) /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_s32(ptr,val,lane) __vst_rrk_d012_s32_k((ptr),(val),__is_constrange(0,1,lane),0xf4800a0f) /* VST3.32 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_f32(ptr,val,lane) __vst_rrk_d012_f32_k((ptr),(val),__is_constrange(0,1,lane),0xf4800a0f) /* VST3.32 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_p8(ptr,val,lane) __vst_rrk_d012_p8_k((ptr),(val),__is_constrange(0,7,lane),0xf480020f) /* VST3.8 {d0[0], d1[0], d2[0]}, [r0] */
#define vst3_lane_p16(ptr,val,lane) __vst_rrk_d012_p16_k((ptr),(val),__is_constrange(0,3,lane),0xf480060f) /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst3_lane_f16(ptr,val,lane) __vst_rrk_d012_f16_k((ptr),(val),__is_constrange(0,3,lane),0xf480060f) /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
#endif
#define vst4q_lane_u16(ptr,val,lane) __vst_rrk_q0123_u16_k((ptr),(val),__is_constrange(0,7,lane),0xf480072f) /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vst4q_lane_u32(ptr,val,lane) __vst_rrk_q0123_u32_k((ptr),(val),__is_constrange(0,3,lane),0xf4800b4f) /* VST4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vst4q_lane_s16(ptr,val,lane) __vst_rrk_q0123_s16_k((ptr),(val),__is_constrange(0,7,lane),0xf480072f) /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vst4q_lane_s32(ptr,val,lane) __vst_rrk_q0123_s32_k((ptr),(val),__is_constrange(0,3,lane),0xf4800b4f) /* VST4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vst4q_lane_f32(ptr,val,lane) __vst_rrk_q0123_f32_k((ptr),(val),__is_constrange(0,3,lane),0xf4800b4f) /* VST4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#define vst4q_lane_p16(ptr,val,lane) __vst_rrk_q0123_p16_k((ptr),(val),__is_constrange(0,7,lane),0xf480072f) /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst4q_lane_f16(ptr,val,lane) __vst_rrk_q0123_f16_k((ptr),(val),__is_constrange(0,7,lane),0xf480072f) /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#endif
#define vst4_lane_u8(ptr,val,lane) __vst_rrk_d0123_u8_k((ptr),(val),__is_constrange(0,7,lane),0xf480030f) /* VST4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_u16(ptr,val,lane) __vst_rrk_d0123_u16_k((ptr),(val),__is_constrange(0,3,lane),0xf480070f) /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_u32(ptr,val,lane) __vst_rrk_d0123_u32_k((ptr),(val),__is_constrange(0,1,lane),0xf4800b0f) /* VST4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_s8(ptr,val,lane) __vst_rrk_d0123_s8_k((ptr),(val),__is_constrange(0,7,lane),0xf480030f) /* VST4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_s16(ptr,val,lane) __vst_rrk_d0123_s16_k((ptr),(val),__is_constrange(0,3,lane),0xf480070f) /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_s32(ptr,val,lane) __vst_rrk_d0123_s32_k((ptr),(val),__is_constrange(0,1,lane),0xf4800b0f) /* VST4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_f32(ptr,val,lane) __vst_rrk_d0123_f32_k((ptr),(val),__is_constrange(0,1,lane),0xf4800b0f) /* VST4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_p8(ptr,val,lane) __vst_rrk_d0123_p8_k((ptr),(val),__is_constrange(0,7,lane),0xf480030f) /* VST4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#define vst4_lane_p16(ptr,val,lane) __vst_rrk_d0123_p16_k((ptr),(val),__is_constrange(0,3,lane),0xf480070f) /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
#define vst4_lane_f16(ptr,val,lane) __vst_rrk_d0123_f16_k((ptr),(val),__is_constrange(0,3,lane),0xf480070f) /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#endif
#define vget_lane_u8(vec,lane) __vmov_wr_id_u8_k((vec),__is_constrange(0,7,lane),0xeed00b10) /* VMOV.U8 r0, d0[0] */
#define vget_lane_u16(vec,lane) __vmov_wr_id_u16_k((vec),__is_constrange(0,3,lane),0xee900b30) /* VMOV.U16 r0, d0[0] */
#define vget_lane_u32(vec,lane) __vmov_wr_id_u32_k((vec),__is_constrange(0,1,lane),0xee100b10) /* VMOV.32 r0, d0[0] */
#define vget_lane_s8(vec,lane) __vmov_wr_id_s8_k((vec),__is_constrange(0,7,lane),0xee500b10) /* VMOV.S8 r0, d0[0] */
#define vget_lane_s16(vec,lane) __vmov_wr_id_s16_k((vec),__is_constrange(0,3,lane),0xee100b30) /* VMOV.S16 r0, d0[0] */
#define vget_lane_s32(vec,lane) __vmov_wr_id_s32_k((vec),__is_constrange(0,1,lane),0xee100b10) /* VMOV.32 r0, d0[0] */
#define vget_lane_p8(vec,lane) __vmov_wr_id_p8_k((vec),__is_constrange(0,7,lane),0xeed00b10) /* VMOV.U8 r0, d0[0] */
#define vget_lane_p16(vec,lane) __vmov_wr_id_p16_k((vec),__is_constrange(0,3,lane),0xee900b30) /* VMOV.U16 r0, d0[0] */
#define vget_lane_f32(vec,lane) __vmov_wr_fd_f32_k((vec),__is_constrange(0,1,lane),0xee100b10) /* VMOV.32 r0, d0[0] */
#define vgetq_lane_u8(vec,lane) __vmov_wr_iq_u8_k((vec),__is_constrange(0,15,lane),0xeed00b10) /* VMOV.U8 r0, d0[0] */
#define vgetq_lane_u16(vec,lane) __vmov_wr_iq_u16_k((vec),__is_constrange(0,7,lane),0xee900b30) /* VMOV.U16 r0, d0[0] */
#define vgetq_lane_u32(vec,lane) __vmov_wr_iq_u32_k((vec),__is_constrange(0,3,lane),0xee100b10) /* VMOV.32 r0, d0[0] */
#define vgetq_lane_s8(vec,lane) __vmov_wr_iq_s8_k((vec),__is_constrange(0,15,lane),0xee500b10) /* VMOV.S8 r0, d0[0] */
#define vgetq_lane_s16(vec,lane) __vmov_wr_iq_s16_k((vec),__is_constrange(0,7,lane),0xee100b30) /* VMOV.S16 r0, d0[0] */
#define vgetq_lane_s32(vec,lane) __vmov_wr_iq_s32_k((vec),__is_constrange(0,3,lane),0xee100b10) /* VMOV.32 r0, d0[0] */
#define vgetq_lane_p8(vec,lane) __vmov_wr_iq_p8_k((vec),__is_constrange(0,15,lane),0xeed00b10) /* VMOV.U8 r0, d0[0] */
#define vgetq_lane_p16(vec,lane) __vmov_wr_iq_p16_k((vec),__is_constrange(0,7,lane),0xee900b30) /* VMOV.U16 r0, d0[0] */
#define vgetq_lane_f32(vec,lane) __vmov_wr_fq_f32_k((vec),__is_constrange(0,3,lane),0xee100b10) /* VMOV.32 r0, d0[0] */
#define vget_lane_s64(vec,lane) __vmov_wwr_iid_s64_k((vec),__is_constrange(0,0,lane),0xec500b10) /* VMOV r0,r0,d0 */
#define vget_lane_u64(vec,lane) __vmov_wwr_iid_u64_k((vec),__is_constrange(0,0,lane),0xec500b10) /* VMOV r0,r0,d0 */
#define vgetq_lane_s64(vec,lane) __vmov_wwr_iiq_s64_k((vec),__is_constrange(0,1,lane),0xec500b10) /* VMOV r0,r0,d0 */
#define vgetq_lane_u64(vec,lane) __vmov_wwr_iiq_u64_k((vec),__is_constrange(0,1,lane),0xec500b10) /* VMOV r0,r0,d0 */
#define vset_lane_u8(value,vec,lane) __vmov_xr_di_u8_k((value),(vec),__is_constrange(0,7,lane),0xee400b10) /* VMOV.8 d0[0],r0 */
#define vset_lane_u16(value,vec,lane) __vmov_xr_di_u16_k((value),(vec),__is_constrange(0,3,lane),0xee000b30) /* VMOV.16 d0[0],r0 */
#define vset_lane_u32(value,vec,lane) __vmov_xr_di_u32_k((value),(vec),__is_constrange(0,1,lane),0xee000b10) /* VMOV.32 d0[0],r0 */
#define vset_lane_s8(value,vec,lane) __vmov_xr_di_s8_k((value),(vec),__is_constrange(0,7,lane),0xee400b10) /* VMOV.8 d0[0],r0 */
#define vset_lane_s16(value,vec,lane) __vmov_xr_di_s16_k((value),(vec),__is_constrange(0,3,lane),0xee000b30) /* VMOV.16 d0[0],r0 */
#define vset_lane_s32(value,vec,lane) __vmov_xr_di_s32_k((value),(vec),__is_constrange(0,1,lane),0xee000b10) /* VMOV.32 d0[0],r0 */
#define vset_lane_p8(value,vec,lane) __vmov_xr_di_p8_k((value),(vec),__is_constrange(0,7,lane),0xee400b10) /* VMOV.8 d0[0],r0 */
#define vset_lane_p16(value,vec,lane) __vmov_xr_di_p16_k((value),(vec),__is_constrange(0,3,lane),0xee000b30) /* VMOV.16 d0[0],r0 */
#define vset_lane_f32(value,vec,lane) __vmov_xr_di_f32_k((value),(vec),__is_constrange(0,1,lane),0xee000b10) /* VMOV.32 d0[0],r0 */
#define vsetq_lane_u8(value,vec,lane) __vmov_xr_qi_u8_k((value),(vec),__is_constrange(0,15,lane),0xee400b10) /* VMOV.8 d0[0],r0 */
#define vsetq_lane_u16(value,vec,lane) __vmov_xr_qi_u16_k((value),(vec),__is_constrange(0,7,lane),0xee000b30) /* VMOV.16 d0[0],r0 */
#define vsetq_lane_u32(value,vec,lane) __vmov_xr_qi_u32_k((value),(vec),__is_constrange(0,3,lane),0xee000b10) /* VMOV.32 d0[0],r0 */
#define vsetq_lane_s8(value,vec,lane) __vmov_xr_qi_s8_k((value),(vec),__is_constrange(0,15,lane),0xee400b10) /* VMOV.8 d0[0],r0 */
#define vsetq_lane_s16(value,vec,lane) __vmov_xr_qi_s16_k((value),(vec),__is_constrange(0,7,lane),0xee000b30) /* VMOV.16 d0[0],r0 */
#define vsetq_lane_s32(value,vec,lane) __vmov_xr_qi_s32_k((value),(vec),__is_constrange(0,3,lane),0xee000b10) /* VMOV.32 d0[0],r0 */
#define vsetq_lane_p8(value,vec,lane) __vmov_xr_qi_p8_k((value),(vec),__is_constrange(0,15,lane),0xee400b10) /* VMOV.8 d0[0],r0 */
#define vsetq_lane_p16(value,vec,lane) __vmov_xr_qi_p16_k((value),(vec),__is_constrange(0,7,lane),0xee000b30) /* VMOV.16 d0[0],r0 */
#define vsetq_lane_f32(value,vec,lane) __vmov_xr_qi_f32_k((value),(vec),__is_constrange(0,3,lane),0xee000b10) /* VMOV.32 d0[0],r0 */
#define vset_lane_s64(value,vec,lane) __vmov_xr_di_s64_k((value),(vec),__is_constrange(0,0,lane),0xec400b10) /* VMOV d0,r0,r0 */
#define vset_lane_u64(value,vec,lane) __vmov_xr_di_u64_k((value),(vec),__is_constrange(0,0,lane),0xec400b10) /* VMOV d0,r0,r0 */
#define vsetq_lane_s64(value,vec,lane) __vmov_xr_qi_s64_k((value),(vec),__is_constrange(0,1,lane),0xec400b10) /* VMOV d0,r0,r0 */
#define vsetq_lane_u64(value,vec,lane) __vmov_xr_qi_u64_k((value),(vec),__is_constrange(0,1,lane),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_s8(a) __vmov_wrr_dii_s8_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_s16(a) __vmov_wrr_dii_s16_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_s32(a) __vmov_wrr_dii_s32_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_f32(a) __vmov_wrr_dii_f32_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_u8(a) __vmov_wrr_dii_u8_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_u16(a) __vmov_wrr_dii_u16_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_u32(a) __vmov_wrr_dii_u32_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_u64(a) __vmov_wrr_dii_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_p8(a) __vmov_wrr_dii_p8_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_p16(a) __vmov_wrr_dii_p16_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#define vcreate_s64(a) __vmov_wrr_dii_s64_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vcreate_f16(a) __vmov_wrr_dii_f16_u64((a),0xec400b10) /* VMOV d0,r0,r0 */
#endif
#define vdup_n_u8(value) __vmov_wr_di_u8((value),0xeec00b10) /* VDUP.8 d0,r0 */
#define vdup_n_u16(value) __vmov_wr_di_u16((value),0xee800b30) /* VDUP.16 d0,r0 */
#define vdup_n_u32(value) __vmov_wr_di_u32((value),0xee800b10) /* VDUP.32 d0,r0 */
#define vdup_n_s8(value) __vmov_wr_di_s8((value),0xeec00b10) /* VDUP.8 d0,r0 */
#define vdup_n_s16(value) __vmov_wr_di_s16((value),0xee800b30) /* VDUP.16 d0,r0 */
#define vdup_n_s32(value) __vmov_wr_di_s32((value),0xee800b10) /* VDUP.32 d0,r0 */
#define vdup_n_p8(value) __vmov_wr_di_p8((value),0xeec00b10) /* VDUP.8 d0,r0 */
#define vdup_n_p16(value) __vmov_wr_di_p16((value),0xee800b30) /* VDUP.16 d0,r0 */
#define vdup_n_f32(value) __vmov_wr_di_f32((value),0xee800b10) /* VDUP.32 d0,r0 */
#define vdupq_n_u8(value) __vmov_wr_qi_u8((value),0xeee00b10) /* VDUP.8 q0,r0 */
#define vdupq_n_u16(value) __vmov_wr_qi_u16((value),0xeea00b30) /* VDUP.16 q0,r0 */
#define vdupq_n_u32(value) __vmov_wr_qi_u32((value),0xeea00b10) /* VDUP.32 q0,r0 */
#define vdupq_n_s8(value) __vmov_wr_qi_s8((value),0xeee00b10) /* VDUP.8 q0,r0 */
#define vdupq_n_s16(value) __vmov_wr_qi_s16((value),0xeea00b30) /* VDUP.16 q0,r0 */
#define vdupq_n_s32(value) __vmov_wr_qi_s32((value),0xeea00b10) /* VDUP.32 q0,r0 */
#define vdupq_n_p8(value) __vmov_wr_qi_p8((value),0xeee00b10) /* VDUP.8 q0,r0 */
#define vdupq_n_p16(value) __vmov_wr_qi_p16((value),0xeea00b30) /* VDUP.16 q0,r0 */
#define vdupq_n_f32(value) __vmov_wr_qi_f32((value),0xeea00b10) /* VDUP.32 q0,r0 */
#define vdup_n_s64(value) __vmov_wrr_dii_s64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vdup_n_u64(value) __vmov_wrr_dii_u64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vdupq_n_s64(value) __vmov_wrr_qii_s64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vdupq_n_u64(value) __vmov_wrr_qii_u64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vmov_n_u8(value) __vmov_wr_di_u8((value),0xeec00b10) /* VDUP.8 d0,r0 */
#define vmov_n_u16(value) __vmov_wr_di_u16((value),0xee800b30) /* VDUP.16 d0,r0 */
#define vmov_n_u32(value) __vmov_wr_di_u32((value),0xee800b10) /* VDUP.32 d0,r0 */
#define vmov_n_s8(value) __vmov_wr_di_s8((value),0xeec00b10) /* VDUP.8 d0,r0 */
#define vmov_n_s16(value) __vmov_wr_di_s16((value),0xee800b30) /* VDUP.16 d0,r0 */
#define vmov_n_s32(value) __vmov_wr_di_s32((value),0xee800b10) /* VDUP.32 d0,r0 */
#define vmov_n_p8(value) __vmov_wr_di_p8((value),0xeec00b10) /* VDUP.8 d0,r0 */
#define vmov_n_p16(value) __vmov_wr_di_p16((value),0xee800b30) /* VDUP.16 d0,r0 */
#define vmov_n_f32(value) __vmov_wr_di_f32((value),0xee800b10) /* VDUP.32 d0,r0 */
#define vmovq_n_u8(value) __vmov_wr_qi_u8((value),0xeee00b10) /* VDUP.8 q0,r0 */
#define vmovq_n_u16(value) __vmov_wr_qi_u16((value),0xeea00b30) /* VDUP.16 q0,r0 */
#define vmovq_n_u32(value) __vmov_wr_qi_u32((value),0xeea00b10) /* VDUP.32 q0,r0 */
#define vmovq_n_s8(value) __vmov_wr_qi_s8((value),0xeee00b10) /* VDUP.8 q0,r0 */
#define vmovq_n_s16(value) __vmov_wr_qi_s16((value),0xeea00b30) /* VDUP.16 q0,r0 */
#define vmovq_n_s32(value) __vmov_wr_qi_s32((value),0xeea00b10) /* VDUP.32 q0,r0 */
#define vmovq_n_p8(value) __vmov_wr_qi_p8((value),0xeee00b10) /* VDUP.8 q0,r0 */
#define vmovq_n_p16(value) __vmov_wr_qi_p16((value),0xeea00b30) /* VDUP.16 q0,r0 */
#define vmovq_n_f32(value) __vmov_wr_qi_f32((value),0xeea00b10) /* VDUP.32 q0,r0 */
#define vmov_n_s64(value) __vmov_wrr_dii_s64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vmov_n_u64(value) __vmov_wrr_dii_u64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vmovq_n_s64(value) __vmov_wrr_qii_s64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vmovq_n_u64(value) __vmov_wrr_qii_u64((value),0xec400b10) /* VMOV d0,r0,r0 */
#define vdup_lane_u8(vec,lane) __ndp9_wrk_dd_u8_k((vec),__is_constrange(0,7,lane),0xf3b10c00) /* VDUP.8 d0,d0[0] */
#define vdup_lane_u16(vec,lane) __ndp9_wrk_dd_u16_k((vec),__is_constrange(0,3,lane),0xf3b20c00) /* VDUP.16 d0,d0[0] */
#define vdup_lane_u32(vec,lane) __ndp9_wrk_dd_u32_k((vec),__is_constrange(0,1,lane),0xf3b40c00) /* VDUP.32 d0,d0[0] */
#define vdup_lane_s8(vec,lane) __ndp9_wrk_dd_s8_k((vec),__is_constrange(0,7,lane),0xf3b10c00) /* VDUP.8 d0,d0[0] */
#define vdup_lane_s16(vec,lane) __ndp9_wrk_dd_s16_k((vec),__is_constrange(0,3,lane),0xf3b20c00) /* VDUP.16 d0,d0[0] */
#define vdup_lane_s32(vec,lane) __ndp9_wrk_dd_s32_k((vec),__is_constrange(0,1,lane),0xf3b40c00) /* VDUP.32 d0,d0[0] */
#define vdup_lane_p8(vec,lane) __ndp9_wrk_dd_p8_k((vec),__is_constrange(0,7,lane),0xf3b10c00) /* VDUP.8 d0,d0[0] */
#define vdup_lane_p16(vec,lane) __ndp9_wrk_dd_p16_k((vec),__is_constrange(0,3,lane),0xf3b20c00) /* VDUP.16 d0,d0[0] */
#define vdup_lane_f32(vec,lane) __ndp9_wrk_dd_f32_k((vec),__is_constrange(0,1,lane),0xf3b40c00) /* VDUP.32 d0,d0[0] */
#define vdupq_lane_u8(vec,lane) __ndp9_wrk_qd_u8_k((vec),__is_constrange(0,7,lane),0xf3b10c40) /* VDUP.8 q0,d0[0] */
#define vdupq_lane_u16(vec,lane) __ndp9_wrk_qd_u16_k((vec),__is_constrange(0,3,lane),0xf3b20c40) /* VDUP.16 q0,d0[0] */
#define vdupq_lane_u32(vec,lane) __ndp9_wrk_qd_u32_k((vec),__is_constrange(0,1,lane),0xf3b40c40) /* VDUP.32 q0,d0[0] */
#define vdupq_lane_s8(vec,lane) __ndp9_wrk_qd_s8_k((vec),__is_constrange(0,7,lane),0xf3b10c40) /* VDUP.8 q0,d0[0] */
#define vdupq_lane_s16(vec,lane) __ndp9_wrk_qd_s16_k((vec),__is_constrange(0,3,lane),0xf3b20c40) /* VDUP.16 q0,d0[0] */
#define vdupq_lane_s32(vec,lane) __ndp9_wrk_qd_s32_k((vec),__is_constrange(0,1,lane),0xf3b40c40) /* VDUP.32 q0,d0[0] */
#define vdupq_lane_p8(vec,lane) __ndp9_wrk_qd_p8_k((vec),__is_constrange(0,7,lane),0xf3b10c40) /* VDUP.8 q0,d0[0] */
#define vdupq_lane_p16(vec,lane) __ndp9_wrk_qd_p16_k((vec),__is_constrange(0,3,lane),0xf3b20c40) /* VDUP.16 q0,d0[0] */
#define vdupq_lane_f32(vec,lane) __ndp9_wrk_qd_f32_k((vec),__is_constrange(0,1,lane),0xf3b40c40) /* VDUP.32 q0,d0[0] */
#define vdup_lane_s64(vec,lane) __ndp9_wrk_dd_s64_k((vec),__is_constrange(0,0,lane),0xf2200110) /* VMOV d0,d0 */
#define vdup_lane_u64(vec,lane) __ndp9_wrk_dd_u64_k((vec),__is_constrange(0,0,lane),0xf2200110) /* VMOV d0,d0 */
#define vdupq_lane_s64(vec,lane) __ndp9_wrk_qd_s64_k((vec),__is_constrange(0,0,lane),0xf2200150) /* VMOV q0,q0 */
#define vdupq_lane_u64(vec,lane) __ndp9_wrk_qd_u64_k((vec),__is_constrange(0,0,lane),0xf2200150) /* VMOV q0,q0 */
#define vcombine_s8(low,high) __njoin_wrr_qdd_s8((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_s16(low,high) __njoin_wrr_qdd_s16((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_s32(low,high) __njoin_wrr_qdd_s32((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_s64(low,high) __njoin_wrr_qdd_s64((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_f32(low,high) __njoin_wrr_qdd_f32((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_u8(low,high) __njoin_wrr_qdd_u8((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_u16(low,high) __njoin_wrr_qdd_u16((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_u32(low,high) __njoin_wrr_qdd_u32((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_u64(low,high) __njoin_wrr_qdd_u64((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_p8(low,high) __njoin_wrr_qdd_p8((low),(high),0xf2200110) /* VMOV d0,d0 */
#define vcombine_p16(low,high) __njoin_wrr_qdd_p16((low),(high),0xf2200110) /* VMOV d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vcombine_f16(low,high) __njoin_wrr_qdd_f16((low),(high),0xf2200110) /* VMOV d0,d0 */
#endif
#define vget_high_s8(a) __nhigh_wr_dq_s8((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_s16(a) __nhigh_wr_dq_s16((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_s32(a) __nhigh_wr_dq_s32((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_s64(a) __nhigh_wr_dq_s64((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_f32(a) __nhigh_wr_dq_f32((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_u8(a) __nhigh_wr_dq_u8((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_u16(a) __nhigh_wr_dq_u16((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_u32(a) __nhigh_wr_dq_u32((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_u64(a) __nhigh_wr_dq_u64((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_p8(a) __nhigh_wr_dq_p8((a),0xf2200110) /* VMOV d0,d0 */
#define vget_high_p16(a) __nhigh_wr_dq_p16((a),0xf2200110) /* VMOV d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vget_high_f16(a) __nhigh_wr_dq_f16((a),0xf2200110) /* VMOV d0,d0 */
#endif
#define vget_low_s8(a) __nlow_wr_dq_s8((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_s16(a) __nlow_wr_dq_s16((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_s32(a) __nlow_wr_dq_s32((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_s64(a) __nlow_wr_dq_s64((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_f32(a) __nlow_wr_dq_f32((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_u8(a) __nlow_wr_dq_u8((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_u16(a) __nlow_wr_dq_u16((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_u32(a) __nlow_wr_dq_u32((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_u64(a) __nlow_wr_dq_u64((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_p8(a) __nlow_wr_dq_p8((a),0xf2200110) /* VMOV d0,d0 */
#define vget_low_p16(a) __nlow_wr_dq_p16((a),0xf2200110) /* VMOV d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vget_low_f16(a) __nlow_wr_dq_f16((a),0xf2200110) /* VMOV d0,d0 */
#endif
#define vcvt_s32_f32(a) __ndp2_wr_dd_s32_f32((a),0xf3bb0700) /* VCVT.S32.F32 d0, d0 */
#define vcvt_u32_f32(a) __ndp2_wr_dd_u32_f32((a),0xf3bb0780) /* VCVT.U32.F32 d0, d0 */
#define vcvtq_s32_f32(a) __ndp2_wr_qq_s32_f32((a),0xf3bb0740) /* VCVT.S32.F32 q0, q0 */
#define vcvtq_u32_f32(a) __ndp2_wr_qq_u32_f32((a),0xf3bb07c0) /* VCVT.U32.F32 q0, q0 */
#define vcvt_n_s32_f32(a,b) __ndp2_wrk_dd_s32_f32_k((a),__is_constrange(1,32,b),0xf2a00f10) /* VCVT.S32.F32 d0, d0, #32 */
#define vcvt_n_u32_f32(a,b) __ndp2_wrk_dd_u32_f32_k((a),__is_constrange(1,32,b),0xf3a00f10) /* VCVT.U32.F32 d0, d0, #32 */
#define vcvtq_n_s32_f32(a,b) __ndp2_wrk_qq_s32_f32_k((a),__is_constrange(1,32,b),0xf2a00f50) /* VCVT.S32.F32 q0, q0, #32 */
#define vcvtq_n_u32_f32(a,b) __ndp2_wrk_qq_u32_f32_k((a),__is_constrange(1,32,b),0xf3a00f50) /* VCVT.U32.F32 q0, q0, #32 */
#define vcvt_f32_s32(a) __ndp2_wr_dd_f32_s32((a),0xf3bb0600) /* VCVT.F32.S32 d0, d0 */
#define vcvt_f32_u32(a) __ndp2_wr_dd_f32_u32((a),0xf3bb0680) /* VCVT.F32.U32 d0, d0 */
#define vcvtq_f32_s32(a) __ndp2_wr_qq_f32_s32((a),0xf3bb0640) /* VCVT.F32.S32 q0, q0 */
#define vcvtq_f32_u32(a) __ndp2_wr_qq_f32_u32((a),0xf3bb06c0) /* VCVT.F32.U32 q0, q0 */
#define vcvt_n_f32_s32(a,b) __ndp2_wrk_dd_f32_s32_k((a),__is_constrange(1,32,b),0xf2a00e10) /* VCVT.F32.S32 d0, d0, #32 */
#define vcvt_n_f32_u32(a,b) __ndp2_wrk_dd_f32_u32_k((a),__is_constrange(1,32,b),0xf3a00e10) /* VCVT.F32.U32 d0, d0, #32 */
#define vcvtq_n_f32_s32(a,b) __ndp2_wrk_qq_f32_s32_k((a),__is_constrange(1,32,b),0xf2a00e50) /* VCVT.F32.S32 q0, q0, #32 */
#define vcvtq_n_f32_u32(a,b) __ndp2_wrk_qq_f32_u32_k((a),__is_constrange(1,32,b),0xf3a00e50) /* VCVT.F32.U32 q0, q0, #32 */
#if __ARM_NEON_FP16_INTRINSICS
#define vcvt_f16_f32(a) __ndp2_wr_dq_f16_f32((a),0xf3b60600) /* VCVT.F16.F32 d0, q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vcvt_f32_f16(a) __ndp2_wr_qd_f32_f16((a),0xf3b60700) /* VCVT.F32.F16 q0, d0 */
#endif
#define vmovn_s16(a) __ndp7_wr_dq_s8_s16((a),0xf3b20200) /* VMOVN.I16 d0,q0 */
#define vmovn_s32(a) __ndp7_wr_dq_s16_s32((a),0xf3b60200) /* VMOVN.I32 d0,q0 */
#define vmovn_s64(a) __ndp7_wr_dq_s32_s64((a),0xf3ba0200) /* VMOVN.I64 d0,q0 */
#define vmovn_u16(a) __ndp7_wr_dq_u8_u16((a),0xf3b20200) /* VMOVN.I16 d0,q0 */
#define vmovn_u32(a) __ndp7_wr_dq_u16_u32((a),0xf3b60200) /* VMOVN.I32 d0,q0 */
#define vmovn_u64(a) __ndp7_wr_dq_u32_u64((a),0xf3ba0200) /* VMOVN.I64 d0,q0 */
#define vmovl_s8(a) __ndp2_wr_qd_s16_s8((a),0xf2880a10) /* VMOVL.S8 q0,d0 */
#define vmovl_s16(a) __ndp2_wr_qd_s32_s16((a),0xf2900a10) /* VMOVL.S16 q0,d0 */
#define vmovl_s32(a) __ndp2_wr_qd_s64_s32((a),0xf2a00a10) /* VMOVL.S32 q0,d0 */
#define vmovl_u8(a) __ndp2_wr_qd_u16_u8((a),0xf3880a10) /* VMOVL.U8 q0,d0 */
#define vmovl_u16(a) __ndp2_wr_qd_u32_u16((a),0xf3900a10) /* VMOVL.U16 q0,d0 */
#define vmovl_u32(a) __ndp2_wr_qd_u64_u32((a),0xf3a00a10) /* VMOVL.U32 q0,d0 */
#define vqmovn_s16(a) __ndp7_wr_dq_s8_s16((a),0xf3b20280) /* VQMOVN.S16 d0,q0 */
#define vqmovn_s32(a) __ndp7_wr_dq_s16_s32((a),0xf3b60280) /* VQMOVN.S32 d0,q0 */
#define vqmovn_s64(a) __ndp7_wr_dq_s32_s64((a),0xf3ba0280) /* VQMOVN.S64 d0,q0 */
#define vqmovn_u16(a) __ndp7_wr_dq_u8_u16((a),0xf3b202c0) /* VQMOVN.U16 d0,q0 */
#define vqmovn_u32(a) __ndp7_wr_dq_u16_u32((a),0xf3b602c0) /* VQMOVN.U32 d0,q0 */
#define vqmovn_u64(a) __ndp7_wr_dq_u32_u64((a),0xf3ba02c0) /* VQMOVN.U64 d0,q0 */
#define vqmovun_s16(a) __ndp7_wr_dq_u8_s16((a),0xf3b20240) /* VQMOVUN.S16 d0,q0 */
#define vqmovun_s32(a) __ndp7_wr_dq_u16_s32((a),0xf3b60240) /* VQMOVUN.S32 d0,q0 */
#define vqmovun_s64(a) __ndp7_wr_dq_u32_s64((a),0xf3ba0240) /* VQMOVUN.S64 d0,q0 */
#define vtbl1_u8(a,b) __tbl_wrr_0_u8((a),(b),0xf3b00800) /* VTBL.8 d0, {d0}, d0 */
#define vtbl1_s8(a,b) __tbl_wrr_0_s8((a),(b),0xf3b00800) /* VTBL.8 d0, {d0}, d0 */
#define vtbl1_p8(a,b) __tbl_wrr_0_p8_p8_u8((a),(b),0xf3b00800) /* VTBL.8 d0, {d0}, d0 */
#define vtbl2_u8(a,b) __tbl_wrr_01_u8((a),(b),0xf3b00900) /* VTBL.8 d0, {d0, d1}, d0 */
#define vtbl2_s8(a,b) __tbl_wrr_01_s8((a),(b),0xf3b00900) /* VTBL.8 d0, {d0, d1}, d0 */
#define vtbl2_p8(a,b) __tbl_wrr_01_p8_p8_u8((a),(b),0xf3b00900) /* VTBL.8 d0, {d0, d1}, d0 */
#define vtbl3_u8(a,b) __tbl_wrr_012_u8((a),(b),0xf3b00a00) /* VTBL.8 d0, {d0, d1, d2}, d0 */
#define vtbl3_s8(a,b) __tbl_wrr_012_s8((a),(b),0xf3b00a00) /* VTBL.8 d0, {d0, d1, d2}, d0 */
#define vtbl3_p8(a,b) __tbl_wrr_012_p8_p8_u8((a),(b),0xf3b00a00) /* VTBL.8 d0, {d0, d1, d2}, d0 */
#define vtbl4_u8(a,b) __tbl_wrr_0123_u8((a),(b),0xf3b00b00) /* VTBL.8 d0, {d0, d1, d2, d3}, d0 */
#define vtbl4_s8(a,b) __tbl_wrr_0123_s8((a),(b),0xf3b00b00) /* VTBL.8 d0, {d0, d1, d2, d3}, d0 */
#define vtbl4_p8(a,b) __tbl_wrr_0123_p8_p8_u8((a),(b),0xf3b00b00) /* VTBL.8 d0, {d0, d1, d2, d3}, d0 */
#define vtbx1_u8(a,b,c) __tbx_xrr_0_u8((a),(b),(c),0xf3b00840) /* VTBX.8 d0, {d0}, d0 */
#define vtbx1_s8(a,b,c) __tbx_xrr_0_s8((a),(b),(c),0xf3b00840) /* VTBX.8 d0, {d0}, d0 */
#define vtbx1_p8(a,b,c) __tbx_xrr_0_p8_p8_p8_u8((a),(b),(c),0xf3b00840) /* VTBX.8 d0, {d0}, d0 */
#define vtbx2_u8(a,b,c) __tbx_xrr_01_u8((a),(b),(c),0xf3b00940) /* VTBX.8 d0, {d0, d1}, d0 */
#define vtbx2_s8(a,b,c) __tbx_xrr_01_s8((a),(b),(c),0xf3b00940) /* VTBX.8 d0, {d0, d1}, d0 */
#define vtbx2_p8(a,b,c) __tbx_xrr_01_p8_p8_p8_u8((a),(b),(c),0xf3b00940) /* VTBX.8 d0, {d0, d1}, d0 */
#define vtbx3_u8(a,b,c) __tbx_xrr_012_u8((a),(b),(c),0xf3b00a40) /* VTBX.8 d0, {d0, d1, d2}, d0 */
#define vtbx3_s8(a,b,c) __tbx_xrr_012_s8((a),(b),(c),0xf3b00a40) /* VTBX.8 d0, {d0, d1, d2}, d0 */
#define vtbx3_p8(a,b,c) __tbx_xrr_012_p8_p8_p8_u8((a),(b),(c),0xf3b00a40) /* VTBX.8 d0, {d0, d1, d2}, d0 */
#define vtbx4_u8(a,b,c) __tbx_xrr_0123_u8((a),(b),(c),0xf3b00b40) /* VTBX.8 d0, {d0, d1, d2, d3}, d0 */
#define vtbx4_s8(a,b,c) __tbx_xrr_0123_s8((a),(b),(c),0xf3b00b40) /* VTBX.8 d0, {d0, d1, d2, d3}, d0 */
#define vtbx4_p8(a,b,c) __tbx_xrr_0123_p8_p8_p8_u8((a),(b),(c),0xf3b00b40) /* VTBX.8 d0, {d0, d1, d2, d3}, d0 */
#define vmla_n_s16(a,b,c) __ndp5_xrr_ddi_s16((a),(b),(c),0xf2900040) /* VMLA.I16 d0, d0, d0[0] */
#define vmla_n_s32(a,b,c) __ndp5_xrr_ddi_s32((a),(b),(c),0xf2a00040) /* VMLA.I32 d0, d0, d0[0] */
#define vmla_n_u16(a,b,c) __ndp5_xrr_ddi_u16((a),(b),(c),0xf2900040) /* VMLA.I16 d0, d0, d0[0] */
#define vmla_n_u32(a,b,c) __ndp5_xrr_ddi_u32((a),(b),(c),0xf2a00040) /* VMLA.I32 d0, d0, d0[0] */
#define vmlaq_n_s16(a,b,c) __ndp5_xrr_qqi_s16((a),(b),(c),0xf3900040) /* VMLA.I16 q0, q0, d0[0] */
#define vmlaq_n_s32(a,b,c) __ndp5_xrr_qqi_s32((a),(b),(c),0xf3a00040) /* VMLA.I32 q0, q0, d0[0] */
#define vmlaq_n_u16(a,b,c) __ndp5_xrr_qqi_u16((a),(b),(c),0xf3900040) /* VMLA.I16 q0, q0, d0[0] */
#define vmlaq_n_u32(a,b,c) __ndp5_xrr_qqi_u32((a),(b),(c),0xf3a00040) /* VMLA.I32 q0, q0, d0[0] */
#define vmla_n_f32(a,b,c) __ndp5_xrr_ddi_f32((a),(b),(c),0xf2a00140) /* VMLA.F32 d0, d0, d0[0] */
#define vmlaq_n_f32(a,b,c) __ndp5_xrr_qqi_f32((a),(b),(c),0xf3a00140) /* VMLA.F32 q0, q0, d0[0] */
#define vmlal_n_s16(a,b,c) __ndp5_xrr_qdi_s32_s32_s16((a),(b),(c),0xf2900240) /* VMLAL.S16 q0, d0, d0[0] */
#define vmlal_n_s32(a,b,c) __ndp5_xrr_qdi_s64_s64_s32((a),(b),(c),0xf2a00240) /* VMLAL.S32 q0, d0, d0[0] */
#define vmlal_n_u16(a,b,c) __ndp5_xrr_qdi_u32_u32_u16((a),(b),(c),0xf3900240) /* VMLAL.U16 q0, d0, d0[0] */
#define vmlal_n_u32(a,b,c) __ndp5_xrr_qdi_u64_u64_u32((a),(b),(c),0xf3a00240) /* VMLAL.U32 q0, d0, d0[0] */
#define vqdmlal_n_s16(a,b,c) __ndp5_xrr_qdi_s32_s32_s16((a),(b),(c),0xf2900340) /* VQDMLAL.S16 q0, d0, d0[0] */
#define vqdmlal_n_s32(a,b,c) __ndp5_xrr_qdi_s64_s64_s32((a),(b),(c),0xf2a00340) /* VQDMLAL.S32 q0, d0, d0[0] */
#define vmls_n_s16(a,b,c) __ndp5_xrr_ddi_s16((a),(b),(c),0xf2900440) /* VMLS.I16 d0, d0, d0[0] */
#define vmls_n_s32(a,b,c) __ndp5_xrr_ddi_s32((a),(b),(c),0xf2a00440) /* VMLS.I32 d0, d0, d0[0] */
#define vmls_n_u16(a,b,c) __ndp5_xrr_ddi_u16((a),(b),(c),0xf2900440) /* VMLS.I16 d0, d0, d0[0] */
#define vmls_n_u32(a,b,c) __ndp5_xrr_ddi_u32((a),(b),(c),0xf2a00440) /* VMLS.I32 d0, d0, d0[0] */
#define vmlsq_n_s16(a,b,c) __ndp5_xrr_qqi_s16((a),(b),(c),0xf3900440) /* VMLS.I16 q0, q0, d0[0] */
#define vmlsq_n_s32(a,b,c) __ndp5_xrr_qqi_s32((a),(b),(c),0xf3a00440) /* VMLS.I32 q0, q0, d0[0] */
#define vmlsq_n_u16(a,b,c) __ndp5_xrr_qqi_u16((a),(b),(c),0xf3900440) /* VMLS.I16 q0, q0, d0[0] */
#define vmlsq_n_u32(a,b,c) __ndp5_xrr_qqi_u32((a),(b),(c),0xf3a00440) /* VMLS.I32 q0, q0, d0[0] */
#define vmls_n_f32(a,b,c) __ndp5_xrr_ddi_f32((a),(b),(c),0xf2a00540) /* VMLS.F32 d0, d0, d0[0] */
#define vmlsq_n_f32(a,b,c) __ndp5_xrr_qqi_f32((a),(b),(c),0xf3a00540) /* VMLS.F32 q0, q0, d0[0] */
#define vmlsl_n_s16(a,b,c) __ndp5_xrr_qdi_s32_s32_s16((a),(b),(c),0xf2900640) /* VMLSL.S16 q0, d0, d0[0] */
#define vmlsl_n_s32(a,b,c) __ndp5_xrr_qdi_s64_s64_s32((a),(b),(c),0xf2a00640) /* VMLSL.S32 q0, d0, d0[0] */
#define vmlsl_n_u16(a,b,c) __ndp5_xrr_qdi_u32_u32_u16((a),(b),(c),0xf3900640) /* VMLSL.U16 q0, d0, d0[0] */
#define vmlsl_n_u32(a,b,c) __ndp5_xrr_qdi_u64_u64_u32((a),(b),(c),0xf3a00640) /* VMLSL.U32 q0, d0, d0[0] */
#define vqdmlsl_n_s16(a,b,c) __ndp5_xrr_qdi_s32_s32_s16((a),(b),(c),0xf2900740) /* VQDMLSL.S16 q0, d0, d0[0] */
#define vqdmlsl_n_s32(a,b,c) __ndp5_xrr_qdi_s64_s64_s32((a),(b),(c),0xf2a00740) /* VQDMLSL.S32 q0, d0, d0[0] */
#define vmul_n_s16(a,b) __ndp5_wrr_ddi_s16((a),(b),0xf2900840) /* VMUL.I16 d0,d0,d0[0] */
#define vmul_n_s32(a,b) __ndp5_wrr_ddi_s32((a),(b),0xf2a00840) /* VMUL.I32 d0,d0,d0[0] */
#define vmul_n_f32(a,b) __ndp5_wrr_ddi_f32((a),(b),0xf2a00940) /* VMUL.F32 d0,d0,d0[0] */
#define vmul_n_u16(a,b) __ndp5_wrr_ddi_u16((a),(b),0xf2900840) /* VMUL.I16 d0,d0,d0[0] */
#define vmul_n_u32(a,b) __ndp5_wrr_ddi_u32((a),(b),0xf2a00840) /* VMUL.I32 d0,d0,d0[0] */
#define vmulq_n_s16(a,b) __ndp5_wrr_qqi_s16((a),(b),0xf3900840) /* VMUL.I16 q0,q0,d0[0] */
#define vmulq_n_s32(a,b) __ndp5_wrr_qqi_s32((a),(b),0xf3a00840) /* VMUL.I32 q0,q0,d0[0] */
#define vmulq_n_f32(a,b) __ndp5_wrr_qqi_f32((a),(b),0xf3a00940) /* VMUL.F32 q0,q0,d0[0] */
#define vmulq_n_u16(a,b) __ndp5_wrr_qqi_u16((a),(b),0xf3900840) /* VMUL.I16 q0,q0,d0[0] */
#define vmulq_n_u32(a,b) __ndp5_wrr_qqi_u32((a),(b),0xf3a00840) /* VMUL.I32 q0,q0,d0[0] */
#define vmull_n_s16(a,b) __ndp5_wrr_qdi_s32_s16((a),(b),0xf2900a40) /* VMULL.S16 q0,d0,d0[0] */
#define vmull_n_s32(a,b) __ndp5_wrr_qdi_s64_s32((a),(b),0xf2a00a40) /* VMULL.S32 q0,d0,d0[0] */
#define vmull_n_u16(a,b) __ndp5_wrr_qdi_u32_u16((a),(b),0xf3900a40) /* VMULL.U16 q0,d0,d0[0] */
#define vmull_n_u32(a,b) __ndp5_wrr_qdi_u64_u32((a),(b),0xf3a00a40) /* VMULL.U32 q0,d0,d0[0] */
#define vqdmull_n_s16(a,b) __ndp5_wrr_qdi_s32_s16((a),(b),0xf2900b40) /* VQDMULL.S16 q0,d0,d0[0] */
#define vqdmull_n_s32(a,b) __ndp5_wrr_qdi_s64_s32((a),(b),0xf2a00b40) /* VQDMULL.S32 q0,d0,d0[0] */
#define vqdmull_lane_s16(a,b,l) __ndp5_wrrk_qdd_s32_s16_k((a),(b),__is_constrange(0,3,l),0xf2900b40) /* VQDMULL.S16 q0,d0,d0[0] */
#define vqdmull_lane_s32(a,b,l) __ndp5_wrrk_qdd_s64_s32_k((a),(b),__is_constrange(0,1,l),0xf2a00b40) /* VQDMULL.S32 q0,d0,d0[0] */
#define vqdmulh_n_s16(a,b) __ndp5_wrr_ddi_s16((a),(b),0xf2900c40) /* VQDMULH.S16 d0,d0,d0[0] */
#define vqdmulh_n_s32(a,b) __ndp5_wrr_ddi_s32((a),(b),0xf2a00c40) /* VQDMULH.S32 d0,d0,d0[0] */
#define vqdmulhq_n_s16(a,b) __ndp5_wrr_qqi_s16((a),(b),0xf3900c40) /* VQDMULH.S16 q0,q0,d0[0] */
#define vqdmulhq_n_s32(a,b) __ndp5_wrr_qqi_s32((a),(b),0xf3a00c40) /* VQDMULH.S32 q0,q0,d0[0] */
#define vqdmulh_lane_s16(a,v,l) __ndp5_wrrk_ddd_s16_k((a),(v),__is_constrange(0,3,l),0xf2900c40) /* VQDMULH.S16 d0,d0,d0[0] */
#define vqdmulh_lane_s32(a,v,l) __ndp5_wrrk_ddd_s32_k((a),(v),__is_constrange(0,1,l),0xf2a00c40) /* VQDMULH.S32 d0,d0,d0[0] */
#define vqdmulhq_lane_s16(a,v,l) __ndp5_wrrk_qqd_s16_k((a),(v),__is_constrange(0,3,l),0xf3900c40) /* VQDMULH.S16 q0,q0,d0[0] */
#define vqdmulhq_lane_s32(a,v,l) __ndp5_wrrk_qqd_s32_k((a),(v),__is_constrange(0,1,l),0xf3a00c40) /* VQDMULH.S32 q0,q0,d0[0] */
#define vqrdmulh_n_s16(a,b) __ndp5_wrr_ddi_s16((a),(b),0xf2900d40) /* VQRDMULH.S16 d0,d0,d0[0] */
#define vqrdmulh_n_s32(a,b) __ndp5_wrr_ddi_s32((a),(b),0xf2a00d40) /* VQRDMULH.S32 d0,d0,d0[0] */
#define vqrdmulhq_n_s16(a,b) __ndp5_wrr_qqi_s16((a),(b),0xf3900d40) /* VQRDMULH.S16 q0,q0,d0[0] */
#define vqrdmulhq_n_s32(a,b) __ndp5_wrr_qqi_s32((a),(b),0xf3a00d40) /* VQRDMULH.S32 q0,q0,d0[0] */
#define vqrdmulh_lane_s16(a,v,l) __ndp5_wrrk_ddd_s16_k((a),(v),__is_constrange(0,3,l),0xf2900d40) /* VQRDMULH.S16 d0,d0,d0[0] */
#define vqrdmulh_lane_s32(a,v,l) __ndp5_wrrk_ddd_s32_k((a),(v),__is_constrange(0,1,l),0xf2a00d40) /* VQRDMULH.S32 d0,d0,d0[0] */
#define vqrdmulhq_lane_s16(a,v,l) __ndp5_wrrk_qqd_s16_k((a),(v),__is_constrange(0,3,l),0xf3900d40) /* VQRDMULH.S16 q0,q0,d0[0] */
#define vqrdmulhq_lane_s32(a,v,l) __ndp5_wrrk_qqd_s32_k((a),(v),__is_constrange(0,1,l),0xf3a00d40) /* VQRDMULH.S32 q0,q0,d0[0] */
#define vmla_lane_s16(a,b,v,l) __ndp5_xrrk_ddd_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900040) /* VMLA.I16 d0, d0, d0[0] */
#define vmla_lane_s32(a,b,v,l) __ndp5_xrrk_ddd_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00040) /* VMLA.I32 d0, d0, d0[0] */
#define vmla_lane_u16(a,b,v,l) __ndp5_xrrk_ddd_u16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900040) /* VMLA.I16 d0, d0, d0[0] */
#define vmla_lane_u32(a,b,v,l) __ndp5_xrrk_ddd_u32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00040) /* VMLA.I32 d0, d0, d0[0] */
#define vmla_lane_f32(a,b,v,l) __ndp5_xrrk_ddd_f32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00140) /* VMLA.F32 d0, d0, d0[0] */
#define vmlaq_lane_s16(a,b,v,l) __ndp5_xrrk_qqd_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf3900040) /* VMLA.I16 q0, q0, d0[0] */
#define vmlaq_lane_s32(a,b,v,l) __ndp5_xrrk_qqd_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00040) /* VMLA.I32 q0, q0, d0[0] */
#define vmlaq_lane_u16(a,b,v,l) __ndp5_xrrk_qqd_u16_k((a),(b),(v),__is_constrange(0,3,l),0xf3900040) /* VMLA.I16 q0, q0, d0[0] */
#define vmlaq_lane_u32(a,b,v,l) __ndp5_xrrk_qqd_u32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00040) /* VMLA.I32 q0, q0, d0[0] */
#define vmlaq_lane_f32(a,b,v,l) __ndp5_xrrk_qqd_f32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00140) /* VMLA.F32 q0, q0, d0[0] */
#define vmlal_lane_s16(a,b,v,l) __ndp5_xrrk_qdd_s32_s32_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900240) /* VMLAL.S16 q0, d0, d0[0] */
#define vmlal_lane_s32(a,b,v,l) __ndp5_xrrk_qdd_s64_s64_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00240) /* VMLAL.S32 q0, d0, d0[0] */
#define vmlal_lane_u16(a,b,v,l) __ndp5_xrrk_qdd_u32_u32_u16_k((a),(b),(v),__is_constrange(0,3,l),0xf3900240) /* VMLAL.U16 q0, d0, d0[0] */
#define vmlal_lane_u32(a,b,v,l) __ndp5_xrrk_qdd_u64_u64_u32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00240) /* VMLAL.U32 q0, d0, d0[0] */
#define vqdmlal_lane_s16(a,b,v,l) __ndp5_xrrk_qdd_s32_s32_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900340) /* VQDMLAL.S16 q0, d0, d0[0] */
#define vqdmlal_lane_s32(a,b,v,l) __ndp5_xrrk_qdd_s64_s64_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00340) /* VQDMLAL.S32 q0, d0, d0[0] */
#define vmls_lane_s16(a,b,v,l) __ndp5_xrrk_ddd_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900440) /* VMLS.I16 d0, d0, d0[0] */
#define vmls_lane_s32(a,b,v,l) __ndp5_xrrk_ddd_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00440) /* VMLS.I32 d0, d0, d0[0] */
#define vmls_lane_u16(a,b,v,l) __ndp5_xrrk_ddd_u16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900440) /* VMLS.I16 d0, d0, d0[0] */
#define vmls_lane_u32(a,b,v,l) __ndp5_xrrk_ddd_u32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00440) /* VMLS.I32 d0, d0, d0[0] */
#define vmls_lane_f32(a,b,v,l) __ndp5_xrrk_ddd_f32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00540) /* VMLS.F32 d0, d0, d0[0] */
#define vmlsq_lane_s16(a,b,v,l) __ndp5_xrrk_qqd_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf3900440) /* VMLS.I16 q0, q0, d0[0] */
#define vmlsq_lane_s32(a,b,v,l) __ndp5_xrrk_qqd_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00440) /* VMLS.I32 q0, q0, d0[0] */
#define vmlsq_lane_u16(a,b,v,l) __ndp5_xrrk_qqd_u16_k((a),(b),(v),__is_constrange(0,3,l),0xf3900440) /* VMLS.I16 q0, q0, d0[0] */
#define vmlsq_lane_u32(a,b,v,l) __ndp5_xrrk_qqd_u32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00440) /* VMLS.I32 q0, q0, d0[0] */
#define vmlsq_lane_f32(a,b,v,l) __ndp5_xrrk_qqd_f32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00540) /* VMLS.F32 q0, q0, d0[0] */
#define vmlsl_lane_s16(a,b,v,l) __ndp5_xrrk_qdd_s32_s32_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900640) /* VMLSL.S16 q0, d0, d0[0] */
#define vmlsl_lane_s32(a,b,v,l) __ndp5_xrrk_qdd_s64_s64_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00640) /* VMLSL.S32 q0, d0, d0[0] */
#define vmlsl_lane_u16(a,b,v,l) __ndp5_xrrk_qdd_u32_u32_u16_k((a),(b),(v),__is_constrange(0,3,l),0xf3900640) /* VMLSL.U16 q0, d0, d0[0] */
#define vmlsl_lane_u32(a,b,v,l) __ndp5_xrrk_qdd_u64_u64_u32_k((a),(b),(v),__is_constrange(0,1,l),0xf3a00640) /* VMLSL.U32 q0, d0, d0[0] */
#define vqdmlsl_lane_s16(a,b,v,l) __ndp5_xrrk_qdd_s32_s32_s16_k((a),(b),(v),__is_constrange(0,3,l),0xf2900740) /* VQDMLSL.S16 q0, d0, d0[0] */
#define vqdmlsl_lane_s32(a,b,v,l) __ndp5_xrrk_qdd_s64_s64_s32_k((a),(b),(v),__is_constrange(0,1,l),0xf2a00740) /* VQDMLSL.S32 q0, d0, d0[0] */
#define vmull_lane_s16(a,v,l) __ndp5_wrrk_qdd_s32_s16_k((a),(v),__is_constrange(0,3,l),0xf2900a40) /* VMULL.S16 q0,d0,d0[0] */
#define vmull_lane_s32(a,v,l) __ndp5_wrrk_qdd_s64_s32_k((a),(v),__is_constrange(0,1,l),0xf2a00a40) /* VMULL.S32 q0,d0,d0[0] */
#define vmull_lane_u16(a,v,l) __ndp5_wrrk_qdd_u32_u16_k((a),(v),__is_constrange(0,3,l),0xf3900a40) /* VMULL.U16 q0,d0,d0[0] */
#define vmull_lane_u32(a,v,l) __ndp5_wrrk_qdd_u64_u32_k((a),(v),__is_constrange(0,1,l),0xf3a00a40) /* VMULL.U32 q0,d0,d0[0] */
#define vmul_lane_s16(a,v,l) __ndp5_wrrk_ddd_s16_k((a),(v),__is_constrange(0,3,l),0xf2900840) /* VMUL.I16 d0,d0,d0[0] */
#define vmul_lane_s32(a,v,l) __ndp5_wrrk_ddd_s32_k((a),(v),__is_constrange(0,1,l),0xf2a00840) /* VMUL.I32 d0,d0,d0[0] */
#define vmul_lane_f32(a,v,l) __ndp5_wrrk_ddd_f32_k((a),(v),__is_constrange(0,1,l),0xf2a00940) /* VMUL.F32 d0,d0,d0[0] */
#define vmul_lane_u16(a,v,l) __ndp5_wrrk_ddd_u16_k((a),(v),__is_constrange(0,3,l),0xf2900840) /* VMUL.I16 d0,d0,d0[0] */
#define vmul_lane_u32(a,v,l) __ndp5_wrrk_ddd_u32_k((a),(v),__is_constrange(0,1,l),0xf2a00840) /* VMUL.I32 d0,d0,d0[0] */
#define vmulq_lane_s16(a,v,l) __ndp5_wrrk_qqd_s16_k((a),(v),__is_constrange(0,3,l),0xf3900840) /* VMUL.I16 q0,q0,d0[0] */
#define vmulq_lane_s32(a,v,l) __ndp5_wrrk_qqd_s32_k((a),(v),__is_constrange(0,1,l),0xf3a00840) /* VMUL.I32 q0,q0,d0[0] */
#define vmulq_lane_f32(a,v,l) __ndp5_wrrk_qqd_f32_k((a),(v),__is_constrange(0,1,l),0xf3a00940) /* VMUL.F32 q0,q0,d0[0] */
#define vmulq_lane_u16(a,v,l) __ndp5_wrrk_qqd_u16_k((a),(v),__is_constrange(0,3,l),0xf3900840) /* VMUL.I16 q0,q0,d0[0] */
#define vmulq_lane_u32(a,v,l) __ndp5_wrrk_qqd_u32_k((a),(v),__is_constrange(0,1,l),0xf3a00840) /* VMUL.I32 q0,q0,d0[0] */
#define vext_s8(a,b,c) __vext8_wrrk_ddd_s8_k((a),(b),__is_constrange(0,7,c),0xf2b00000) /* VEXT.8 d0,d0,d0,#0 */
#define vext_u8(a,b,c) __vext8_wrrk_ddd_u8_k((a),(b),__is_constrange(0,7,c),0xf2b00000) /* VEXT.8 d0,d0,d0,#0 */
#define vext_p8(a,b,c) __vext8_wrrk_ddd_p8_k((a),(b),__is_constrange(0,7,c),0xf2b00000) /* VEXT.8 d0,d0,d0,#0 */
#define vext_s16(a,b,c) __vext16_wrrk_ddd_s16_k((a),(b),__is_constrange(0,3,c),0xf2b00000) /* VEXT.16 d0,d0,d0,#0 */
#define vext_u16(a,b,c) __vext16_wrrk_ddd_u16_k((a),(b),__is_constrange(0,3,c),0xf2b00000) /* VEXT.16 d0,d0,d0,#0 */
#define vext_p16(a,b,c) __vext16_wrrk_ddd_p16_k((a),(b),__is_constrange(0,3,c),0xf2b00000) /* VEXT.16 d0,d0,d0,#0 */
#define vext_s32(a,b,c) __vext32_wrrk_ddd_s32_k((a),(b),__is_constrange(0,1,c),0xf2b00000) /* VEXT.32 d0,d0,d0,#0 */
#define vext_u32(a,b,c) __vext32_wrrk_ddd_u32_k((a),(b),__is_constrange(0,1,c),0xf2b00000) /* VEXT.32 d0,d0,d0,#0 */
#define vext_f32(a,b,c) __vext32_wrrk_ddd_f32_k((a),(b),__is_constrange(0,1,c),0xf2b00000) /* VEXT.32 d0,d0,d0,#0 */
#define vext_s64(a,b,c) __vext64_wrrk_ddd_s64_k((a),(b),__is_constrange(0,0,c),0xf2b00000) /* VEXT.64 d0,d0,d0,#0 */
#define vext_u64(a,b,c) __vext64_wrrk_ddd_u64_k((a),(b),__is_constrange(0,0,c),0xf2b00000) /* VEXT.64 d0,d0,d0,#0 */
#define vextq_s8(a,b,c) __vext8_wrrk_qqq_s8_k((a),(b),__is_constrange(0,15,c),0xf2b00040) /* VEXT.8 q0,q0,q0,#0 */
#define vextq_u8(a,b,c) __vext8_wrrk_qqq_u8_k((a),(b),__is_constrange(0,15,c),0xf2b00040) /* VEXT.8 q0,q0,q0,#0 */
#define vextq_p8(a,b,c) __vext8_wrrk_qqq_p8_k((a),(b),__is_constrange(0,15,c),0xf2b00040) /* VEXT.8 q0,q0,q0,#0 */
#define vextq_s16(a,b,c) __vext16_wrrk_qqq_s16_k((a),(b),__is_constrange(0,7,c),0xf2b00040) /* VEXT.16 q0,q0,q0,#0 */
#define vextq_u16(a,b,c) __vext16_wrrk_qqq_u16_k((a),(b),__is_constrange(0,7,c),0xf2b00040) /* VEXT.16 q0,q0,q0,#0 */
#define vextq_p16(a,b,c) __vext16_wrrk_qqq_p16_k((a),(b),__is_constrange(0,7,c),0xf2b00040) /* VEXT.16 q0,q0,q0,#0 */
#define vextq_s32(a,b,c) __vext32_wrrk_qqq_s32_k((a),(b),__is_constrange(0,3,c),0xf2b00040) /* VEXT.32 q0,q0,q0,#0 */
#define vextq_u32(a,b,c) __vext32_wrrk_qqq_u32_k((a),(b),__is_constrange(0,3,c),0xf2b00040) /* VEXT.32 q0,q0,q0,#0 */
#define vextq_f32(a,b,c) __vext32_wrrk_qqq_f32_k((a),(b),__is_constrange(0,3,c),0xf2b00040) /* VEXT.32 q0,q0,q0,#0 */
#define vextq_s64(a,b,c) __vext64_wrrk_qqq_s64_k((a),(b),__is_constrange(0,1,c),0xf2b00040) /* VEXT.64 q0,q0,q0,#0 */
#define vextq_u64(a,b,c) __vext64_wrrk_qqq_u64_k((a),(b),__is_constrange(0,1,c),0xf2b00040) /* VEXT.64 q0,q0,q0,#0 */
#define vrev64_s8(vec) __ndp7_wr_dd_s8((vec),0xf3b00000) /* VREV64.8 d0,d0 */
#define vrev64_s16(vec) __ndp7_wr_dd_s16((vec),0xf3b40000) /* VREV64.16 d0,d0 */
#define vrev64_s32(vec) __ndp7_wr_dd_s32((vec),0xf3b80000) /* VREV64.32 d0,d0 */
#define vrev64_u8(vec) __ndp7_wr_dd_u8((vec),0xf3b00000) /* VREV64.8 d0,d0 */
#define vrev64_u16(vec) __ndp7_wr_dd_u16((vec),0xf3b40000) /* VREV64.16 d0,d0 */
#define vrev64_u32(vec) __ndp7_wr_dd_u32((vec),0xf3b80000) /* VREV64.32 d0,d0 */
#define vrev64_p8(vec) __ndp7_wr_dd_p8((vec),0xf3b00000) /* VREV64.8 d0,d0 */
#define vrev64_p16(vec) __ndp7_wr_dd_p16((vec),0xf3b40000) /* VREV64.16 d0,d0 */
#define vrev64_f32(vec) __ndp7_wr_dd_f32((vec),0xf3b80000) /* VREV64.32 d0,d0 */
#define vrev64q_s8(vec) __ndp7_wr_qq_s8((vec),0xf3b00040) /* VREV64.8 q0,q0 */
#define vrev64q_s16(vec) __ndp7_wr_qq_s16((vec),0xf3b40040) /* VREV64.16 q0,q0 */
#define vrev64q_s32(vec) __ndp7_wr_qq_s32((vec),0xf3b80040) /* VREV64.32 q0,q0 */
#define vrev64q_u8(vec) __ndp7_wr_qq_u8((vec),0xf3b00040) /* VREV64.8 q0,q0 */
#define vrev64q_u16(vec) __ndp7_wr_qq_u16((vec),0xf3b40040) /* VREV64.16 q0,q0 */
#define vrev64q_u32(vec) __ndp7_wr_qq_u32((vec),0xf3b80040) /* VREV64.32 q0,q0 */
#define vrev64q_p8(vec) __ndp7_wr_qq_p8((vec),0xf3b00040) /* VREV64.8 q0,q0 */
#define vrev64q_p16(vec) __ndp7_wr_qq_p16((vec),0xf3b40040) /* VREV64.16 q0,q0 */
#define vrev64q_f32(vec) __ndp7_wr_qq_f32((vec),0xf3b80040) /* VREV64.32 q0,q0 */
#define vrev32_s8(vec) __ndp7_wr_dd_s8((vec),0xf3b00080) /* VREV32.8 d0,d0 */
#define vrev32_s16(vec) __ndp7_wr_dd_s16((vec),0xf3b40080) /* VREV32.16 d0,d0 */
#define vrev32_u8(vec) __ndp7_wr_dd_u8((vec),0xf3b00080) /* VREV32.8 d0,d0 */
#define vrev32_u16(vec) __ndp7_wr_dd_u16((vec),0xf3b40080) /* VREV32.16 d0,d0 */
#define vrev32_p8(vec) __ndp7_wr_dd_p8((vec),0xf3b00080) /* VREV32.8 d0,d0 */
#define vrev32_p16(vec) __ndp7_wr_dd_p16((vec),0xf3b40080) /* VREV32.16 d0,d0 */
#define vrev32q_s8(vec) __ndp7_wr_qq_s8((vec),0xf3b000c0) /* VREV32.8 q0,q0 */
#define vrev32q_s16(vec) __ndp7_wr_qq_s16((vec),0xf3b400c0) /* VREV32.16 q0,q0 */
#define vrev32q_u8(vec) __ndp7_wr_qq_u8((vec),0xf3b000c0) /* VREV32.8 q0,q0 */
#define vrev32q_u16(vec) __ndp7_wr_qq_u16((vec),0xf3b400c0) /* VREV32.16 q0,q0 */
#define vrev32q_p8(vec) __ndp7_wr_qq_p8((vec),0xf3b000c0) /* VREV32.8 q0,q0 */
#define vrev32q_p16(vec) __ndp7_wr_qq_p16((vec),0xf3b400c0) /* VREV32.16 q0,q0 */
#define vrev16_s8(vec) __ndp7_wr_dd_s8((vec),0xf3b00100) /* VREV16.8 d0,d0 */
#define vrev16_u8(vec) __ndp7_wr_dd_u8((vec),0xf3b00100) /* VREV16.8 d0,d0 */
#define vrev16_p8(vec) __ndp7_wr_dd_p8((vec),0xf3b00100) /* VREV16.8 d0,d0 */
#define vrev16q_s8(vec) __ndp7_wr_qq_s8((vec),0xf3b00140) /* VREV16.8 q0,q0 */
#define vrev16q_u8(vec) __ndp7_wr_qq_u8((vec),0xf3b00140) /* VREV16.8 q0,q0 */
#define vrev16q_p8(vec) __ndp7_wr_qq_p8((vec),0xf3b00140) /* VREV16.8 q0,q0 */
#define vabs_s8(a) __ndp7_wr_dd_s8((a),0xf3b10300) /* VABS.S8 d0,d0 */
#define vabs_s16(a) __ndp7_wr_dd_s16((a),0xf3b50300) /* VABS.S16 d0,d0 */
#define vabs_s32(a) __ndp7_wr_dd_s32((a),0xf3b90300) /* VABS.S32 d0,d0 */
#define vabs_f32(a) __ndp7_wr_dd_f32((a),0xf3b90700) /* VABS.F32 d0,d0 */
#define vabsq_s8(a) __ndp7_wr_qq_s8((a),0xf3b10340) /* VABS.S8 q0,q0 */
#define vabsq_s16(a) __ndp7_wr_qq_s16((a),0xf3b50340) /* VABS.S16 q0,q0 */
#define vabsq_s32(a) __ndp7_wr_qq_s32((a),0xf3b90340) /* VABS.S32 q0,q0 */
#define vabsq_f32(a) __ndp7_wr_qq_f32((a),0xf3b90740) /* VABS.F32 q0,q0 */
#define vqabs_s8(a) __ndp7_wr_dd_s8((a),0xf3b00700) /* VQABS.S8 d0,d0 */
#define vqabs_s16(a) __ndp7_wr_dd_s16((a),0xf3b40700) /* VQABS.S16 d0,d0 */
#define vqabs_s32(a) __ndp7_wr_dd_s32((a),0xf3b80700) /* VQABS.S32 d0,d0 */
#define vqabsq_s8(a) __ndp7_wr_qq_s8((a),0xf3b00740) /* VQABS.S8 q0,q0 */
#define vqabsq_s16(a) __ndp7_wr_qq_s16((a),0xf3b40740) /* VQABS.S16 q0,q0 */
#define vqabsq_s32(a) __ndp7_wr_qq_s32((a),0xf3b80740) /* VQABS.S32 q0,q0 */
#define vneg_s8(a) __ndp7_wr_dd_s8((a),0xf3b10380) /* VNEG.S8 d0,d0 */
#define vneg_s16(a) __ndp7_wr_dd_s16((a),0xf3b50380) /* VNEG.S16 d0,d0 */
#define vneg_s32(a) __ndp7_wr_dd_s32((a),0xf3b90380) /* VNEG.S32 d0,d0 */
#define vneg_f32(a) __ndp7_wr_dd_f32((a),0xf3b90780) /* VNEG.F32 d0,d0 */
#define vnegq_s8(a) __ndp7_wr_qq_s8((a),0xf3b103c0) /* VNEG.S8 q0,q0 */
#define vnegq_s16(a) __ndp7_wr_qq_s16((a),0xf3b503c0) /* VNEG.S16 q0,q0 */
#define vnegq_s32(a) __ndp7_wr_qq_s32((a),0xf3b903c0) /* VNEG.S32 q0,q0 */
#define vnegq_f32(a) __ndp7_wr_qq_f32((a),0xf3b907c0) /* VNEG.F32 q0,q0 */
#define vqneg_s8(a) __ndp7_wr_dd_s8((a),0xf3b00780) /* VQNEG.S8 d0,d0 */
#define vqneg_s16(a) __ndp7_wr_dd_s16((a),0xf3b40780) /* VQNEG.S16 d0,d0 */
#define vqneg_s32(a) __ndp7_wr_dd_s32((a),0xf3b80780) /* VQNEG.S32 d0,d0 */
#define vqnegq_s8(a) __ndp7_wr_qq_s8((a),0xf3b007c0) /* VQNEG.S8 q0,q0 */
#define vqnegq_s16(a) __ndp7_wr_qq_s16((a),0xf3b407c0) /* VQNEG.S16 q0,q0 */
#define vqnegq_s32(a) __ndp7_wr_qq_s32((a),0xf3b807c0) /* VQNEG.S32 q0,q0 */
#define vcls_s8(a) __ndp7_wr_dd_s8((a),0xf3b00400) /* VCLS.S8 d0,d0 */
#define vcls_s16(a) __ndp7_wr_dd_s16((a),0xf3b40400) /* VCLS.S16 d0,d0 */
#define vcls_s32(a) __ndp7_wr_dd_s32((a),0xf3b80400) /* VCLS.S32 d0,d0 */
#define vclsq_s8(a) __ndp7_wr_qq_s8((a),0xf3b00440) /* VCLS.S8 q0,q0 */
#define vclsq_s16(a) __ndp7_wr_qq_s16((a),0xf3b40440) /* VCLS.S16 q0,q0 */
#define vclsq_s32(a) __ndp7_wr_qq_s32((a),0xf3b80440) /* VCLS.S32 q0,q0 */
#define vclz_s8(a) __ndp7_wr_dd_s8((a),0xf3b00480) /* VCLZ.I8 d0,d0 */
#define vclz_s16(a) __ndp7_wr_dd_s16((a),0xf3b40480) /* VCLZ.I16 d0,d0 */
#define vclz_s32(a) __ndp7_wr_dd_s32((a),0xf3b80480) /* VCLZ.I32 d0,d0 */
#define vclz_u8(a) __ndp7_wr_dd_u8((a),0xf3b00480) /* VCLZ.I8 d0,d0 */
#define vclz_u16(a) __ndp7_wr_dd_u16((a),0xf3b40480) /* VCLZ.I16 d0,d0 */
#define vclz_u32(a) __ndp7_wr_dd_u32((a),0xf3b80480) /* VCLZ.I32 d0,d0 */
#define vclzq_s8(a) __ndp7_wr_qq_s8((a),0xf3b004c0) /* VCLZ.I8 q0,q0 */
#define vclzq_s16(a) __ndp7_wr_qq_s16((a),0xf3b404c0) /* VCLZ.I16 q0,q0 */
#define vclzq_s32(a) __ndp7_wr_qq_s32((a),0xf3b804c0) /* VCLZ.I32 q0,q0 */
#define vclzq_u8(a) __ndp7_wr_qq_u8((a),0xf3b004c0) /* VCLZ.I8 q0,q0 */
#define vclzq_u16(a) __ndp7_wr_qq_u16((a),0xf3b404c0) /* VCLZ.I16 q0,q0 */
#define vclzq_u32(a) __ndp7_wr_qq_u32((a),0xf3b804c0) /* VCLZ.I32 q0,q0 */
#define vcnt_u8(a) __ndp7_wr_dd_u8((a),0xf3b00500) /* VCNT.8 d0,d0 */
#define vcnt_s8(a) __ndp7_wr_dd_s8((a),0xf3b00500) /* VCNT.8 d0,d0 */
#define vcnt_p8(a) __ndp7_wr_dd_p8((a),0xf3b00500) /* VCNT.8 d0,d0 */
#define vcntq_u8(a) __ndp7_wr_qq_u8((a),0xf3b00540) /* VCNT.8 q0,q0 */
#define vcntq_s8(a) __ndp7_wr_qq_s8((a),0xf3b00540) /* VCNT.8 q0,q0 */
#define vcntq_p8(a) __ndp7_wr_qq_p8((a),0xf3b00540) /* VCNT.8 q0,q0 */
#define vrecpe_f32(a) __ndp7_wr_dd_f32((a),0xf3bb0500) /* VRECPE.F32 d0,d0 */
#define vrecpe_u32(a) __ndp7_wr_dd_u32((a),0xf3bb0400) /* VRECPE.U32 d0,d0 */
#define vrecpeq_f32(a) __ndp7_wr_qq_f32((a),0xf3bb0540) /* VRECPE.F32 q0,q0 */
#define vrecpeq_u32(a) __ndp7_wr_qq_u32((a),0xf3bb0440) /* VRECPE.U32 q0,q0 */
#define vrsqrte_f32(a) __ndp7_wr_dd_f32((a),0xf3bb0580) /* VRSQRTE.F32 d0,d0 */
#define vrsqrte_u32(a) __ndp7_wr_dd_u32((a),0xf3bb0480) /* VRSQRTE.U32 d0,d0 */
#define vrsqrteq_f32(a) __ndp7_wr_qq_f32((a),0xf3bb05c0) /* VRSQRTE.F32 q0,q0 */
#define vrsqrteq_u32(a) __ndp7_wr_qq_u32((a),0xf3bb04c0) /* VRSQRTE.U32 q0,q0 */
#define vreinterpret_s16_s8(a) __reinterpret___d_s16_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_s8(a) __reinterpret___d_s32_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_s8(a) __reinterpret___d_f32_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_s8(a) __reinterpret___d_u8_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_s8(a) __reinterpret___d_u16_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_s8(a) __reinterpret___d_u32_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_s8(a) __reinterpret___d_p8_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_s8(a) __reinterpret___d_p16_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_s8(a) __reinterpret___d_u64_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_s8(a) __reinterpret___d_s64_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_s8(a) __reinterpret___d_f16_s8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_s16(a) __reinterpret___d_s8_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_s16(a) __reinterpret___d_s32_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_s16(a) __reinterpret___d_f32_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_s16(a) __reinterpret___d_u8_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_s16(a) __reinterpret___d_u16_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_s16(a) __reinterpret___d_u32_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_s16(a) __reinterpret___d_p8_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_s16(a) __reinterpret___d_p16_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_s16(a) __reinterpret___d_u64_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_s16(a) __reinterpret___d_s64_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_s16(a) __reinterpret___d_f16_s16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_s32(a) __reinterpret___d_s8_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_s32(a) __reinterpret___d_s16_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_s32(a) __reinterpret___d_f32_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_s32(a) __reinterpret___d_u8_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_s32(a) __reinterpret___d_u16_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_s32(a) __reinterpret___d_u32_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_s32(a) __reinterpret___d_p8_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_s32(a) __reinterpret___d_p16_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_s32(a) __reinterpret___d_u64_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_s32(a) __reinterpret___d_s64_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_s32(a) __reinterpret___d_f16_s32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_f32(a) __reinterpret___d_s8_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_f32(a) __reinterpret___d_s16_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_f32(a) __reinterpret___d_s32_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_f32(a) __reinterpret___d_u8_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_f32(a) __reinterpret___d_u16_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_f32(a) __reinterpret___d_u32_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_f32(a) __reinterpret___d_p8_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_f32(a) __reinterpret___d_p16_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_f32(a) __reinterpret___d_u64_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_f32(a) __reinterpret___d_s64_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_f32(a) __reinterpret___d_f16_f32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_u8(a) __reinterpret___d_s8_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_u8(a) __reinterpret___d_s16_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_u8(a) __reinterpret___d_s32_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_u8(a) __reinterpret___d_f32_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_u8(a) __reinterpret___d_u16_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_u8(a) __reinterpret___d_u32_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_u8(a) __reinterpret___d_p8_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_u8(a) __reinterpret___d_p16_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_u8(a) __reinterpret___d_u64_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_u8(a) __reinterpret___d_s64_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_u8(a) __reinterpret___d_f16_u8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_u16(a) __reinterpret___d_s8_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_u16(a) __reinterpret___d_s16_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_u16(a) __reinterpret___d_s32_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_u16(a) __reinterpret___d_f32_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_u16(a) __reinterpret___d_u8_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_u16(a) __reinterpret___d_u32_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_u16(a) __reinterpret___d_p8_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_u16(a) __reinterpret___d_p16_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_u16(a) __reinterpret___d_u64_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_u16(a) __reinterpret___d_s64_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_u16(a) __reinterpret___d_f16_u16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_u32(a) __reinterpret___d_s8_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_u32(a) __reinterpret___d_s16_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_u32(a) __reinterpret___d_s32_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_u32(a) __reinterpret___d_f32_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_u32(a) __reinterpret___d_u8_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_u32(a) __reinterpret___d_u16_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_u32(a) __reinterpret___d_p8_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_u32(a) __reinterpret___d_p16_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_u32(a) __reinterpret___d_u64_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_u32(a) __reinterpret___d_s64_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_u32(a) __reinterpret___d_f16_u32((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_p8(a) __reinterpret___d_s8_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_p8(a) __reinterpret___d_s16_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_p8(a) __reinterpret___d_s32_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_p8(a) __reinterpret___d_f32_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_p8(a) __reinterpret___d_u8_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_p8(a) __reinterpret___d_u16_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_p8(a) __reinterpret___d_u32_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_p8(a) __reinterpret___d_p16_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_p8(a) __reinterpret___d_u64_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_p8(a) __reinterpret___d_s64_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_p8(a) __reinterpret___d_f16_p8((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_p16(a) __reinterpret___d_s8_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_p16(a) __reinterpret___d_s16_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_p16(a) __reinterpret___d_s32_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_p16(a) __reinterpret___d_f32_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_p16(a) __reinterpret___d_u8_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_p16(a) __reinterpret___d_u16_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_p16(a) __reinterpret___d_u32_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_p16(a) __reinterpret___d_p8_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_p16(a) __reinterpret___d_u64_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_p16(a) __reinterpret___d_s64_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_p16(a) __reinterpret___d_f16_p16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_u64(a) __reinterpret___d_s8_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_u64(a) __reinterpret___d_s16_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_u64(a) __reinterpret___d_s32_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_u64(a) __reinterpret___d_f32_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_u64(a) __reinterpret___d_u8_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_u64(a) __reinterpret___d_u16_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_u64(a) __reinterpret___d_u32_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_u64(a) __reinterpret___d_p8_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_u64(a) __reinterpret___d_p16_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s64_u64(a) __reinterpret___d_s64_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_u64(a) __reinterpret___d_f16_u64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpret_s8_s64(a) __reinterpret___d_s8_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s16_s64(a) __reinterpret___d_s16_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_s32_s64(a) __reinterpret___d_s32_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_f32_s64(a) __reinterpret___d_f32_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u8_s64(a) __reinterpret___d_u8_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u16_s64(a) __reinterpret___d_u16_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u32_s64(a) __reinterpret___d_u32_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p8_s64(a) __reinterpret___d_p8_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_p16_s64(a) __reinterpret___d_p16_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#define vreinterpret_u64_s64(a) __reinterpret___d_u64_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f16_s64(a) __reinterpret___d_f16_s64((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_s8_f16(a) __reinterpret___d_s8_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_s16_f16(a) __reinterpret___d_s16_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_s32_f16(a) __reinterpret___d_s32_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_f32_f16(a) __reinterpret___d_f32_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_u8_f16(a) __reinterpret___d_u8_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_u16_f16(a) __reinterpret___d_u16_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_u32_f16(a) __reinterpret___d_u32_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_p8_f16(a) __reinterpret___d_p8_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_p16_f16(a) __reinterpret___d_p16_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_u64_f16(a) __reinterpret___d_u64_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpret_s64_f16(a) __reinterpret___d_s64_f16((a),0xe320f000) /* NOP ;d0,d0,d0 */
#endif
#define vreinterpretq_s16_s8(a) __reinterpret___q_s16_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_s8(a) __reinterpret___q_s32_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_s8(a) __reinterpret___q_f32_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_s8(a) __reinterpret___q_u8_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_s8(a) __reinterpret___q_u16_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_s8(a) __reinterpret___q_u32_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_s8(a) __reinterpret___q_p8_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_s8(a) __reinterpret___q_p16_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_s8(a) __reinterpret___q_u64_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_s8(a) __reinterpret___q_s64_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_s8(a) __reinterpret___q_f16_s8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_s16(a) __reinterpret___q_s8_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_s16(a) __reinterpret___q_s32_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_s16(a) __reinterpret___q_f32_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_s16(a) __reinterpret___q_u8_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_s16(a) __reinterpret___q_u16_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_s16(a) __reinterpret___q_u32_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_s16(a) __reinterpret___q_p8_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_s16(a) __reinterpret___q_p16_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_s16(a) __reinterpret___q_u64_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_s16(a) __reinterpret___q_s64_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_s16(a) __reinterpret___q_f16_s16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_s32(a) __reinterpret___q_s8_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_s32(a) __reinterpret___q_s16_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_s32(a) __reinterpret___q_f32_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_s32(a) __reinterpret___q_u8_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_s32(a) __reinterpret___q_u16_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_s32(a) __reinterpret___q_u32_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_s32(a) __reinterpret___q_p8_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_s32(a) __reinterpret___q_p16_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_s32(a) __reinterpret___q_u64_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_s32(a) __reinterpret___q_s64_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_s32(a) __reinterpret___q_f16_s32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_f32(a) __reinterpret___q_s8_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_f32(a) __reinterpret___q_s16_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_f32(a) __reinterpret___q_s32_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_f32(a) __reinterpret___q_u8_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_f32(a) __reinterpret___q_u16_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_f32(a) __reinterpret___q_u32_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_f32(a) __reinterpret___q_p8_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_f32(a) __reinterpret___q_p16_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_f32(a) __reinterpret___q_u64_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_f32(a) __reinterpret___q_s64_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_f32(a) __reinterpret___q_f16_f32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_u8(a) __reinterpret___q_s8_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_u8(a) __reinterpret___q_s16_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_u8(a) __reinterpret___q_s32_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_u8(a) __reinterpret___q_f32_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_u8(a) __reinterpret___q_u16_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_u8(a) __reinterpret___q_u32_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_u8(a) __reinterpret___q_p8_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_u8(a) __reinterpret___q_p16_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_u8(a) __reinterpret___q_u64_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_u8(a) __reinterpret___q_s64_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_u8(a) __reinterpret___q_f16_u8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_u16(a) __reinterpret___q_s8_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_u16(a) __reinterpret___q_s16_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_u16(a) __reinterpret___q_s32_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_u16(a) __reinterpret___q_f32_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_u16(a) __reinterpret___q_u8_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_u16(a) __reinterpret___q_u32_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_u16(a) __reinterpret___q_p8_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_u16(a) __reinterpret___q_p16_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_u16(a) __reinterpret___q_u64_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_u16(a) __reinterpret___q_s64_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_u16(a) __reinterpret___q_f16_u16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_u32(a) __reinterpret___q_s8_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_u32(a) __reinterpret___q_s16_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_u32(a) __reinterpret___q_s32_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_u32(a) __reinterpret___q_f32_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_u32(a) __reinterpret___q_u8_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_u32(a) __reinterpret___q_u16_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_u32(a) __reinterpret___q_p8_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_u32(a) __reinterpret___q_p16_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_u32(a) __reinterpret___q_u64_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_u32(a) __reinterpret___q_s64_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_u32(a) __reinterpret___q_f16_u32((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_p8(a) __reinterpret___q_s8_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_p8(a) __reinterpret___q_s16_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_p8(a) __reinterpret___q_s32_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_p8(a) __reinterpret___q_f32_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_p8(a) __reinterpret___q_u8_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_p8(a) __reinterpret___q_u16_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_p8(a) __reinterpret___q_u32_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_p8(a) __reinterpret___q_p16_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_p8(a) __reinterpret___q_u64_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_p8(a) __reinterpret___q_s64_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_p8(a) __reinterpret___q_f16_p8((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_p16(a) __reinterpret___q_s8_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_p16(a) __reinterpret___q_s16_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_p16(a) __reinterpret___q_s32_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_p16(a) __reinterpret___q_f32_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_p16(a) __reinterpret___q_u8_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_p16(a) __reinterpret___q_u16_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_p16(a) __reinterpret___q_u32_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_p16(a) __reinterpret___q_p8_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_p16(a) __reinterpret___q_u64_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_p16(a) __reinterpret___q_s64_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_p16(a) __reinterpret___q_f16_p16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_u64(a) __reinterpret___q_s8_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_u64(a) __reinterpret___q_s16_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_u64(a) __reinterpret___q_s32_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_u64(a) __reinterpret___q_f32_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_u64(a) __reinterpret___q_u8_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_u64(a) __reinterpret___q_u16_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_u64(a) __reinterpret___q_u32_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_u64(a) __reinterpret___q_p8_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_u64(a) __reinterpret___q_p16_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s64_u64(a) __reinterpret___q_s64_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_u64(a) __reinterpret___q_f16_u64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vreinterpretq_s8_s64(a) __reinterpret___q_s8_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s16_s64(a) __reinterpret___q_s16_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_s32_s64(a) __reinterpret___q_s32_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_f32_s64(a) __reinterpret___q_f32_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u8_s64(a) __reinterpret___q_u8_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u16_s64(a) __reinterpret___q_u16_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u32_s64(a) __reinterpret___q_u32_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p8_s64(a) __reinterpret___q_p8_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_p16_s64(a) __reinterpret___q_p16_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#define vreinterpretq_u64_s64(a) __reinterpret___q_u64_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f16_s64(a) __reinterpret___q_f16_s64((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_s8_f16(a) __reinterpret___q_s8_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_s16_f16(a) __reinterpret___q_s16_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_s32_f16(a) __reinterpret___q_s32_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_f32_f16(a) __reinterpret___q_f32_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_u8_f16(a) __reinterpret___q_u8_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_u16_f16(a) __reinterpret___q_u16_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_u32_f16(a) __reinterpret___q_u32_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_p8_f16(a) __reinterpret___q_p8_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_p16_f16(a) __reinterpret___q_p16_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_u64_f16(a) __reinterpret___q_u64_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
#define vreinterpretq_s64_f16(a) __reinterpret___q_s64_f16((a),0xe320f000) /* NOP ;q0,q0,q0 */
#endif
#define vmvn_s8(a) __ndp7_wr_dd_s8((a),0xf3b00580) /* VMVN d0,d0 */
#define vmvn_s16(a) __ndp7_wr_dd_s16((a),0xf3b00580) /* VMVN d0,d0 */
#define vmvn_s32(a) __ndp7_wr_dd_s32((a),0xf3b00580) /* VMVN d0,d0 */
#define vmvn_u8(a) __ndp7_wr_dd_u8((a),0xf3b00580) /* VMVN d0,d0 */
#define vmvn_u16(a) __ndp7_wr_dd_u16((a),0xf3b00580) /* VMVN d0,d0 */
#define vmvn_u32(a) __ndp7_wr_dd_u32((a),0xf3b00580) /* VMVN d0,d0 */
#define vmvn_p8(a) __ndp7_wr_dd_p8((a),0xf3b00580) /* VMVN d0,d0 */
#define vmvnq_s8(a) __ndp7_wr_qq_s8((a),0xf3b005c0) /* VMVN q0,q0 */
#define vmvnq_s16(a) __ndp7_wr_qq_s16((a),0xf3b005c0) /* VMVN q0,q0 */
#define vmvnq_s32(a) __ndp7_wr_qq_s32((a),0xf3b005c0) /* VMVN q0,q0 */
#define vmvnq_u8(a) __ndp7_wr_qq_u8((a),0xf3b005c0) /* VMVN q0,q0 */
#define vmvnq_u16(a) __ndp7_wr_qq_u16((a),0xf3b005c0) /* VMVN q0,q0 */
#define vmvnq_u32(a) __ndp7_wr_qq_u32((a),0xf3b005c0) /* VMVN q0,q0 */
#define vmvnq_p8(a) __ndp7_wr_qq_p8((a),0xf3b005c0) /* VMVN q0,q0 */
#define vand_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vand_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vand_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vand_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vand_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vand_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vand_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vand_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf2000110) /* VAND d0,d0,d0 */
#define vandq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vandq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vandq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vandq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vandq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vandq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vandq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vandq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf2000150) /* VAND q0,q0,q0 */
#define vorr_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorr_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorr_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorr_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorr_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorr_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorr_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorr_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf2200110) /* VORR d0,d0,d0 */
#define vorrq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define vorrq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define vorrq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define vorrq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define vorrq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define vorrq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define vorrq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define vorrq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf2200150) /* VORR q0,q0,q0 */
#define veor_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veor_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veor_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veor_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veor_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veor_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veor_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veor_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf3000110) /* VEOR d0,d0,d0 */
#define veorq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define veorq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define veorq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define veorq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define veorq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define veorq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define veorq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define veorq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf3000150) /* VEOR q0,q0,q0 */
#define vbic_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbic_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbic_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbic_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbic_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbic_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbic_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbic_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf2100110) /* VBIC d0,d0,d0 */
#define vbicq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vbicq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vbicq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vbicq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vbicq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vbicq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vbicq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vbicq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf2100150) /* VBIC q0,q0,q0 */
#define vorn_s8(a,b) __ndp1_wrr_ddd_s8((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vorn_s16(a,b) __ndp1_wrr_ddd_s16((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vorn_s32(a,b) __ndp1_wrr_ddd_s32((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vorn_s64(a,b) __ndp1_wrr_ddd_s64((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vorn_u8(a,b) __ndp1_wrr_ddd_u8((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vorn_u16(a,b) __ndp1_wrr_ddd_u16((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vorn_u32(a,b) __ndp1_wrr_ddd_u32((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vorn_u64(a,b) __ndp1_wrr_ddd_u64((a),(b),0xf2300110) /* VORN d0,d0,d0 */
#define vornq_s8(a,b) __ndp1_wrr_qqq_s8((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vornq_s16(a,b) __ndp1_wrr_qqq_s16((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vornq_s32(a,b) __ndp1_wrr_qqq_s32((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vornq_s64(a,b) __ndp1_wrr_qqq_s64((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vornq_u8(a,b) __ndp1_wrr_qqq_u8((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vornq_u16(a,b) __ndp1_wrr_qqq_u16((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vornq_u32(a,b) __ndp1_wrr_qqq_u32((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vornq_u64(a,b) __ndp1_wrr_qqq_u64((a),(b),0xf2300150) /* VORN q0,q0,q0 */
#define vbsl_s8(a,b,c) __ndp1_xrr_ddd_s8_u8_s8((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_s16(a,b,c) __ndp1_xrr_ddd_s16_u16_s16((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_s32(a,b,c) __ndp1_xrr_ddd_s32_u32_s32((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_s64(a,b,c) __ndp1_xrr_ddd_s64_u64_s64((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_u8(a,b,c) __ndp1_xrr_ddd_u8((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_u16(a,b,c) __ndp1_xrr_ddd_u16((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_u32(a,b,c) __ndp1_xrr_ddd_u32((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_u64(a,b,c) __ndp1_xrr_ddd_u64((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_f32(a,b,c) __ndp1_xrr_ddd_f32_u32_f32((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_p8(a,b,c) __ndp1_xrr_ddd_p8_u8_p8((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbsl_p16(a,b,c) __ndp1_xrr_ddd_p16_u16_p16((a),(b),(c),0xf3100110) /* VBSL d0,d0,d0 */
#define vbslq_s8(a,b,c) __ndp1_xrr_qqq_s8_u8_s8((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_s16(a,b,c) __ndp1_xrr_qqq_s16_u16_s16((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_s32(a,b,c) __ndp1_xrr_qqq_s32_u32_s32((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_s64(a,b,c) __ndp1_xrr_qqq_s64_u64_s64((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_u8(a,b,c) __ndp1_xrr_qqq_u8((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_u16(a,b,c) __ndp1_xrr_qqq_u16((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_u32(a,b,c) __ndp1_xrr_qqq_u32((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_u64(a,b,c) __ndp1_xrr_qqq_u64((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_f32(a,b,c) __ndp1_xrr_qqq_f32_u32_f32((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_p8(a,b,c) __ndp1_xrr_qqq_p8_u8_p8((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vbslq_p16(a,b,c) __ndp1_xrr_qqq_p16_u16_p16((a),(b),(c),0xf3100150) /* VBSL q0,q0,q0 */
#define vtrn_s8(a,b) __ndp7_xx_dd_s8((a),(b),0xf3b20080) /* VTRN.8 d0,d0 */
#define vtrn_s16(a,b) __ndp7_xx_dd_s16((a),(b),0xf3b60080) /* VTRN.16 d0,d0 */
#define vtrn_s32(a,b) __ndp7_xx_dd_s32((a),(b),0xf3ba0080) /* VTRN.32 d0,d0 */
#define vtrn_u8(a,b) __ndp7_xx_dd_u8((a),(b),0xf3b20080) /* VTRN.8 d0,d0 */
#define vtrn_u16(a,b) __ndp7_xx_dd_u16((a),(b),0xf3b60080) /* VTRN.16 d0,d0 */
#define vtrn_u32(a,b) __ndp7_xx_dd_u32((a),(b),0xf3ba0080) /* VTRN.32 d0,d0 */
#define vtrn_f32(a,b) __ndp7_xx_dd_f32((a),(b),0xf3ba0080) /* VTRN.32 d0,d0 */
#define vtrn_p8(a,b) __ndp7_xx_dd_p8((a),(b),0xf3b20080) /* VTRN.8 d0,d0 */
#define vtrn_p16(a,b) __ndp7_xx_dd_p16((a),(b),0xf3b60080) /* VTRN.16 d0,d0 */
#define vtrnq_s8(a,b) __ndp7_xx_qq_s8((a),(b),0xf3b200c0) /* VTRN.8 q0,q0 */
#define vtrnq_s16(a,b) __ndp7_xx_qq_s16((a),(b),0xf3b600c0) /* VTRN.16 q0,q0 */
#define vtrnq_s32(a,b) __ndp7_xx_qq_s32((a),(b),0xf3ba00c0) /* VTRN.32 q0,q0 */
#define vtrnq_u8(a,b) __ndp7_xx_qq_u8((a),(b),0xf3b200c0) /* VTRN.8 q0,q0 */
#define vtrnq_u16(a,b) __ndp7_xx_qq_u16((a),(b),0xf3b600c0) /* VTRN.16 q0,q0 */
#define vtrnq_u32(a,b) __ndp7_xx_qq_u32((a),(b),0xf3ba00c0) /* VTRN.32 q0,q0 */
#define vtrnq_f32(a,b) __ndp7_xx_qq_f32((a),(b),0xf3ba00c0) /* VTRN.32 q0,q0 */
#define vtrnq_p8(a,b) __ndp7_xx_qq_p8((a),(b),0xf3b200c0) /* VTRN.8 q0,q0 */
#define vtrnq_p16(a,b) __ndp7_xx_qq_p16((a),(b),0xf3b600c0) /* VTRN.16 q0,q0 */
#define vzip_s8(a,b) __ndp7_xx_dd_s8((a),(b),0xf3b20180) /* VZIP.8 d0,d0 */
#define vzip_s16(a,b) __ndp7_xx_dd_s16((a),(b),0xf3b60180) /* VZIP.16 d0,d0 */
#define vzip_s32(a,b) __ndp7_xx_dd_s32((a),(b),0xf3ba0080) /* VZIP.32 d0,d0 */
#define vzip_u8(a,b) __ndp7_xx_dd_u8((a),(b),0xf3b20180) /* VZIP.8 d0,d0 */
#define vzip_u16(a,b) __ndp7_xx_dd_u16((a),(b),0xf3b60180) /* VZIP.16 d0,d0 */
#define vzip_u32(a,b) __ndp7_xx_dd_u32((a),(b),0xf3ba0080) /* VZIP.32 d0,d0 */
#define vzip_p8(a,b) __ndp7_xx_dd_p8((a),(b),0xf3b20180) /* VZIP.8 d0,d0 */
#define vzip_p16(a,b) __ndp7_xx_dd_p16((a),(b),0xf3b60180) /* VZIP.16 d0,d0 */
#define vzip_f32(a,b) __ndp7_xx_dd_f32((a),(b),0xf3ba0080) /* VZIP.32 d0,d0 */
#define vzipq_s8(a,b) __ndp7_xx_qq_s8((a),(b),0xf3b201c0) /* VZIP.8 q0,q0 */
#define vzipq_s16(a,b) __ndp7_xx_qq_s16((a),(b),0xf3b601c0) /* VZIP.16 q0,q0 */
#define vzipq_s32(a,b) __ndp7_xx_qq_s32((a),(b),0xf3ba01c0) /* VZIP.32 q0,q0 */
#define vzipq_u8(a,b) __ndp7_xx_qq_u8((a),(b),0xf3b201c0) /* VZIP.8 q0,q0 */
#define vzipq_u16(a,b) __ndp7_xx_qq_u16((a),(b),0xf3b601c0) /* VZIP.16 q0,q0 */
#define vzipq_u32(a,b) __ndp7_xx_qq_u32((a),(b),0xf3ba01c0) /* VZIP.32 q0,q0 */
#define vzipq_p8(a,b) __ndp7_xx_qq_p8((a),(b),0xf3b201c0) /* VZIP.8 q0,q0 */
#define vzipq_p16(a,b) __ndp7_xx_qq_p16((a),(b),0xf3b601c0) /* VZIP.16 q0,q0 */
#define vzipq_f32(a,b) __ndp7_xx_qq_f32((a),(b),0xf3ba01c0) /* VZIP.32 q0,q0 */
#define vuzp_s8(a,b) __ndp7_xx_dd_s8((a),(b),0xf3b20100) /* VUZP.8 d0,d0 */
#define vuzp_s16(a,b) __ndp7_xx_dd_s16((a),(b),0xf3b60100) /* VUZP.16 d0,d0 */
#define vuzp_s32(a,b) __ndp7_xx_dd_s32((a),(b),0xf3ba0080) /* VUZP.32 d0,d0 */
#define vuzp_u8(a,b) __ndp7_xx_dd_u8((a),(b),0xf3b20100) /* VUZP.8 d0,d0 */
#define vuzp_u16(a,b) __ndp7_xx_dd_u16((a),(b),0xf3b60100) /* VUZP.16 d0,d0 */
#define vuzp_u32(a,b) __ndp7_xx_dd_u32((a),(b),0xf3ba0080) /* VUZP.32 d0,d0 */
#define vuzp_p8(a,b) __ndp7_xx_dd_p8((a),(b),0xf3b20100) /* VUZP.8 d0,d0 */
#define vuzp_p16(a,b) __ndp7_xx_dd_p16((a),(b),0xf3b60100) /* VUZP.16 d0,d0 */
#define vuzp_f32(a,b) __ndp7_xx_dd_f32((a),(b),0xf3ba0080) /* VUZP.32 d0,d0 */
#define vuzpq_s8(a,b) __ndp7_xx_qq_s8((a),(b),0xf3b20140) /* VUZP.8 q0,q0 */
#define vuzpq_s16(a,b) __ndp7_xx_qq_s16((a),(b),0xf3b60140) /* VUZP.16 q0,q0 */
#define vuzpq_s32(a,b) __ndp7_xx_qq_s32((a),(b),0xf3ba0140) /* VUZP.32 q0,q0 */
#define vuzpq_u8(a,b) __ndp7_xx_qq_u8((a),(b),0xf3b20140) /* VUZP.8 q0,q0 */
#define vuzpq_u16(a,b) __ndp7_xx_qq_u16((a),(b),0xf3b60140) /* VUZP.16 q0,q0 */
#define vuzpq_u32(a,b) __ndp7_xx_qq_u32((a),(b),0xf3ba0140) /* VUZP.32 q0,q0 */
#define vuzpq_p8(a,b) __ndp7_xx_qq_p8((a),(b),0xf3b20140) /* VUZP.8 q0,q0 */
#define vuzpq_p16(a,b) __ndp7_xx_qq_p16((a),(b),0xf3b60140) /* VUZP.16 q0,q0 */
#define vuzpq_f32(a,b) __ndp7_xx_qq_f32((a),(b),0xf3ba0140) /* VUZP.32 q0,q0 */
#ifdef __cplusplus
extern "C" {
#endif /* def __cplusplus */
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __ndp2_wr_dq_f16_f32(float32x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __nhigh_wr_dq_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __nlow_wr_dq_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_f32(float32x2_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_p16(poly16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_p8(poly8x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_s16(int16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_s32(int32x2_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_s64(int64x1_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_s8(int8x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_u16(uint16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_u32(uint32x2_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_u64(uint64x1_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __reinterpret___d_f16_u8(uint8x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __vld_wr_d0_f16(__transfersize(1) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __vld_wr_d0_f16(__transfersize(4) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __vld_xr_d0_f16_k(__transfersize(1) __fp16 const *,
                 float16x4_t, 
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4_t __vmov_wrr_dii_f16_u64(uint64_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x2_t __vld_wr_d01_f16(__transfersize(2) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x2_t __vld_wr_d01_f16(__transfersize(8) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x2_t __vld_xr_d01_f16_k(__transfersize(2) __fp16 const *,
                 float16x4x2_t, 
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x3_t __vld_wr_d012_f16(__transfersize(12) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x3_t __vld_wr_d012_f16(__transfersize(3) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x3_t __vld_xr_d012_f16_k(__transfersize(3) __fp16 const *,
                 float16x4x3_t, 
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x4_t __vld_wr_d0123_f16(__transfersize(16) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x4_t __vld_wr_d0123_f16(__transfersize(4) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x4x4_t __vld_xr_d0123_f16_k(__transfersize(4) __fp16 const *,
                 float16x4x4_t, 
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __njoin_wrr_qdd_f16(float16x4_t,float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_f32(float32x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_p16(poly16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_p8(poly8x16_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_s16(int16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_s32(int32x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_s64(int64x2_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_s8(int8x16_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_u16(uint16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_u32(uint32x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_u64(uint64x2_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __reinterpret___q_f16_u8(uint8x16_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __vld_wr_extq0_f16(__transfersize(1) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __vld_wr_q0_f16(__transfersize(8) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8_t __vld_xr_q0_f16_k(__transfersize(1) __fp16 const *,
                 float16x8_t, 
                 __constrange(0,7) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8x2_t __vld_wr_q01_f16(__transfersize(16) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8x2_t __vld_xr_q01_f16_k(__transfersize(2) __fp16 const *,
                 float16x8x2_t, 
                 __constrange(0,7) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8x3_t __vld_wr_q012_f16(__transfersize(24) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8x3_t __vld_xr_q012_f16_k(__transfersize(3) __fp16 const *,
                 float16x8x3_t, 
                 __constrange(0,7) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8x4_t __vld_wr_q0123_f16(__transfersize(32) __fp16 const *, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float16x8x4_t __vld_xr_q0123_f16_k(__transfersize(4) __fp16 const *,
                 float16x8x4_t, 
                 __constrange(0,7) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float32x2_t __reinterpret___d_f32_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float32x4_t __ndp2_wr_qd_f32_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
float32x4_t __reinterpret___q_f32_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int16x4_t __reinterpret___d_s16_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int16x8_t __reinterpret___q_s16_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int32x2_t __reinterpret___d_s32_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int32x4_t __reinterpret___q_s32_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int64x1_t __reinterpret___d_s64_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int64x2_t __reinterpret___q_s64_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int8x16_t __reinterpret___q_s8_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
int8x8_t __reinterpret___d_s8_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
poly16x4_t __reinterpret___d_p16_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
poly16x8_t __reinterpret___q_p16_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
poly8x16_t __reinterpret___q_p8_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
poly8x8_t __reinterpret___d_p8_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint16x4_t __reinterpret___d_u16_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint16x8_t __reinterpret___q_u16_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint32x2_t __reinterpret___d_u32_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint32x4_t __reinterpret___q_u32_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint64x1_t __reinterpret___d_u64_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint64x2_t __reinterpret___q_u64_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint8x16_t __reinterpret___q_u8_f16(float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
uint8x8_t __reinterpret___d_u8_f16(float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_d0123_f16(__transfersize(16) __fp16 *, float16x4x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_d012_f16(__transfersize(12) __fp16 *, float16x4x3_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_d01_f16(__transfersize(8) __fp16 *, float16x4x2_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_d0_f16(__transfersize(4) __fp16 *,float16x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_q0123_f16(__transfersize(32) __fp16 *, float16x8x4_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_q012_f16(__transfersize(24) __fp16 *, float16x8x3_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_q01_f16(__transfersize(16) __fp16 *, float16x8x2_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rr_q0_f16(__transfersize(8) __fp16 *,float16x8_t, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_d0123_f16_k(__transfersize(4) __fp16 *,
                 float16x4x4_t,
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_d012_f16_k(__transfersize(3) __fp16 *,
                 float16x4x3_t,
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_d01_f16_k(__transfersize(2) __fp16 *,
                 float16x4x2_t,
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_d0_f16_k(__transfersize(1) __fp16 *,
                 float16x4_t,
                 __constrange(0,3) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_q0123_f16_k(__transfersize(4) __fp16 *,
                 float16x8x4_t,
                 __constrange(0,7) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_q012_f16_k(__transfersize(3) __fp16 *,
                 float16x8x3_t,
                 __constrange(0,7) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_q01_f16_k(__transfersize(2) __fp16 *,
                 float16x8x2_t,
                 __constrange(0,7) int, __encoding_t);
#endif
#if __ARM_NEON_FP16_INTRINSICS
void __vst_rrk_q0_f16_k(__transfersize(1) __fp16 *,
                 float16x8_t,
                 __constrange(0,7) int, __encoding_t);
#endif
float32_t __vmov_wr_fd_f32_k(float32x2_t,__constrange(0,1) int, __encoding_t);
float32_t __vmov_wr_fq_f32_k(float32x4_t,__constrange(0,3) int, __encoding_t);
float32x2_t __ndp1_wrr_ddd_f32(float32x2_t,float32x2_t, __encoding_t);
float32x2_t __ndp1_xrr_ddd_f32(float32x2_t,float32x2_t,float32x2_t, __encoding_t);
float32x2_t __ndp1_xrr_ddd_f32_u32_f32(uint32x2_t,float32x2_t,float32x2_t, __encoding_t);
float32x2_t __ndp2_wr_dd_f32_s32(int32x2_t, __encoding_t);
float32x2_t __ndp2_wr_dd_f32_u32(uint32x2_t, __encoding_t);
float32x2_t __ndp2_wrk_dd_f32_s32_k(int32x2_t,__constrange(1,32) int, __encoding_t);
float32x2_t __ndp2_wrk_dd_f32_u32_k(uint32x2_t,__constrange(1,32) int, __encoding_t);
float32x2_t __ndp5_wrr_ddi_f32(float32x2_t,float32_t, __encoding_t);
float32x2_t __ndp5_wrrk_ddd_f32_k(float32x2_t,float32x2_t,__constrange(0,1) int, __encoding_t);
float32x2_t __ndp5_xrr_ddi_f32(float32x2_t,float32x2_t,float32_t, __encoding_t);
float32x2_t __ndp5_xrrk_ddd_f32_k(float32x2_t,float32x2_t,float32x2_t,__constrange(0,1) int, __encoding_t);
float32x2_t __ndp7_wr_dd_f32(float32x2_t, __encoding_t);
float32x2_t __ndp9_wrk_dd_f32_k(float32x2_t,__constrange(0,1) int, __encoding_t);
float32x2_t __nhigh_wr_dq_f32(float32x4_t, __encoding_t);
float32x2_t __nlow_wr_dq_f32(float32x4_t, __encoding_t);
float32x2_t __reinterpret___d_f32_p16(poly16x4_t, __encoding_t);
float32x2_t __reinterpret___d_f32_p8(poly8x8_t, __encoding_t);
float32x2_t __reinterpret___d_f32_s16(int16x4_t, __encoding_t);
float32x2_t __reinterpret___d_f32_s32(int32x2_t, __encoding_t);
float32x2_t __reinterpret___d_f32_s64(int64x1_t, __encoding_t);
float32x2_t __reinterpret___d_f32_s8(int8x8_t, __encoding_t);
float32x2_t __reinterpret___d_f32_u16(uint16x4_t, __encoding_t);
float32x2_t __reinterpret___d_f32_u32(uint32x2_t, __encoding_t);
float32x2_t __reinterpret___d_f32_u64(uint64x1_t, __encoding_t);
float32x2_t __reinterpret___d_f32_u8(uint8x8_t, __encoding_t);
float32x2_t __vext32_wrrk_ddd_f32_k(float32x2_t,float32x2_t,__constrange(0,1) int, __encoding_t);
float32x2_t __vld_wr_d0_f32(__transfersize(1) float32_t const *, __encoding_t);
float32x2_t __vld_wr_d0_f32(__transfersize(2) float32_t const *, __encoding_t);
float32x2_t __vld_xr_d0_f32_k(__transfersize(1) float32_t const *,
                 float32x2_t, 
                 __constrange(0,1) int, __encoding_t);
float32x2_t __vmov_wr_di_f32(float32_t, __encoding_t);
float32x2_t __vmov_wrr_dii_f32_u64(uint64_t, __encoding_t);
float32x2_t __vmov_xr_di_f32_k(float32_t,float32x2_t,__constrange(0,1) int, __encoding_t);
float32x2x2_t __ndp7_xx_dd_f32(float32x2_t,float32x2_t, __encoding_t);
float32x2x2_t __vld_wr_d01_f32(__transfersize(2) float32_t const *, __encoding_t);
float32x2x2_t __vld_wr_d01_f32(__transfersize(4) float32_t const *, __encoding_t);
float32x2x2_t __vld_xr_d01_f32_k(__transfersize(2) float32_t const *,
                 float32x2x2_t, 
                 __constrange(0,1) int, __encoding_t);
float32x2x3_t __vld_wr_d012_f32(__transfersize(3) float32_t const *, __encoding_t);
float32x2x3_t __vld_wr_d012_f32(__transfersize(6) float32_t const *, __encoding_t);
float32x2x3_t __vld_xr_d012_f32_k(__transfersize(3) float32_t const *,
                 float32x2x3_t, 
                 __constrange(0,1) int, __encoding_t);
float32x2x4_t __vld_wr_d0123_f32(__transfersize(4) float32_t const *, __encoding_t);
float32x2x4_t __vld_wr_d0123_f32(__transfersize(8) float32_t const *, __encoding_t);
float32x2x4_t __vld_xr_d0123_f32_k(__transfersize(4) float32_t const *,
                 float32x2x4_t, 
                 __constrange(0,1) int, __encoding_t);
float32x4_t __ndp1_wrr_qqq_f32(float32x4_t,float32x4_t, __encoding_t);
float32x4_t __ndp1_xrr_qqq_f32(float32x4_t,float32x4_t,float32x4_t, __encoding_t);
float32x4_t __ndp1_xrr_qqq_f32_u32_f32(uint32x4_t,float32x4_t,float32x4_t, __encoding_t);
float32x4_t __ndp2_wr_qq_f32_s32(int32x4_t, __encoding_t);
float32x4_t __ndp2_wr_qq_f32_u32(uint32x4_t, __encoding_t);
float32x4_t __ndp2_wrk_qq_f32_s32_k(int32x4_t,__constrange(1,32) int, __encoding_t);
float32x4_t __ndp2_wrk_qq_f32_u32_k(uint32x4_t,__constrange(1,32) int, __encoding_t);
float32x4_t __ndp5_wrr_qqi_f32(float32x4_t,float32_t, __encoding_t);
float32x4_t __ndp5_wrrk_qqd_f32_k(float32x4_t,float32x2_t,__constrange(0,1) int, __encoding_t);
float32x4_t __ndp5_xrr_qqi_f32(float32x4_t,float32x4_t,float32_t, __encoding_t);
float32x4_t __ndp5_xrrk_qqd_f32_k(float32x4_t,float32x4_t,float32x2_t,__constrange(0,1) int, __encoding_t);
float32x4_t __ndp7_wr_qq_f32(float32x4_t, __encoding_t);
float32x4_t __ndp9_wrk_qd_f32_k(float32x2_t,__constrange(0,1) int, __encoding_t);
float32x4_t __njoin_wrr_qdd_f32(float32x2_t,float32x2_t, __encoding_t);
float32x4_t __reinterpret___q_f32_p16(poly16x8_t, __encoding_t);
float32x4_t __reinterpret___q_f32_p8(poly8x16_t, __encoding_t);
float32x4_t __reinterpret___q_f32_s16(int16x8_t, __encoding_t);
float32x4_t __reinterpret___q_f32_s32(int32x4_t, __encoding_t);
float32x4_t __reinterpret___q_f32_s64(int64x2_t, __encoding_t);
float32x4_t __reinterpret___q_f32_s8(int8x16_t, __encoding_t);
float32x4_t __reinterpret___q_f32_u16(uint16x8_t, __encoding_t);
float32x4_t __reinterpret___q_f32_u32(uint32x4_t, __encoding_t);
float32x4_t __reinterpret___q_f32_u64(uint64x2_t, __encoding_t);
float32x4_t __reinterpret___q_f32_u8(uint8x16_t, __encoding_t);
float32x4_t __vext32_wrrk_qqq_f32_k(float32x4_t,float32x4_t,__constrange(0,3) int, __encoding_t);
float32x4_t __vld_wr_extq0_f32(__transfersize(1) float32_t const *, __encoding_t);
float32x4_t __vld_wr_q0_f32(__transfersize(4) float32_t const *, __encoding_t);
float32x4_t __vld_xr_q0_f32_k(__transfersize(1) float32_t const *,
                 float32x4_t, 
                 __constrange(0,3) int, __encoding_t);
float32x4_t __vmov_wr_qi_f32(float32_t, __encoding_t);
float32x4_t __vmov_xr_qi_f32_k(float32_t,float32x4_t,__constrange(0,3) int, __encoding_t);
float32x4x2_t __ndp7_xx_qq_f32(float32x4_t,float32x4_t, __encoding_t);
float32x4x2_t __vld_wr_q01_f32(__transfersize(8) float32_t const *, __encoding_t);
float32x4x2_t __vld_xr_q01_f32_k(__transfersize(2) float32_t const *,
                 float32x4x2_t, 
                 __constrange(0,3) int, __encoding_t);
float32x4x3_t __vld_wr_q012_f32(__transfersize(12) float32_t const *, __encoding_t);
float32x4x3_t __vld_xr_q012_f32_k(__transfersize(3) float32_t const *,
                 float32x4x3_t, 
                 __constrange(0,3) int, __encoding_t);
float32x4x4_t __vld_wr_q0123_f32(__transfersize(16) float32_t const *, __encoding_t);
float32x4x4_t __vld_xr_q0123_f32_k(__transfersize(4) float32_t const *,
                 float32x4x4_t, 
                 __constrange(0,3) int, __encoding_t);
int16_t __vmov_wr_id_s16_k(int16x4_t,__constrange(0,3) int, __encoding_t);
int16_t __vmov_wr_iq_s16_k(int16x8_t,__constrange(0,7) int, __encoding_t);
int16x4_t __ndp1_wrr_ddd_s16(int16x4_t,int16x4_t, __encoding_t);
int16x4_t __ndp1_xrr_ddd_s16(int16x4_t,int16x4_t,int16x4_t, __encoding_t);
int16x4_t __ndp1_xrr_ddd_s16_u16_s16(uint16x4_t,int16x4_t,int16x4_t, __encoding_t);
int16x4_t __ndp2_wrk_dd_s16_k(int16x4_t,__constrange(0,15) int, __encoding_t);
int16x4_t __ndp2_wrk_dd_s16_k(int16x4_t,__constrange(1,16) int, __encoding_t);
int16x4_t __ndp2_wrk_dq_s16_s32_k(int32x4_t,__constrange(1,16) int, __encoding_t);
int16x4_t __ndp2_xrk_dd_s16_k(int16x4_t,int16x4_t,__constrange(0,15) int, __encoding_t);
int16x4_t __ndp2_xrk_dd_s16_k(int16x4_t,int16x4_t,__constrange(1,16) int, __encoding_t);
int16x4_t __ndp4_wrr_dqq_s16_s32(int32x4_t,int32x4_t, __encoding_t);
int16x4_t __ndp5_wrr_ddi_s16(int16x4_t,int16_t, __encoding_t);
int16x4_t __ndp5_wrrk_ddd_s16_k(int16x4_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int16x4_t __ndp5_xrr_ddi_s16(int16x4_t,int16x4_t,int16_t, __encoding_t);
int16x4_t __ndp5_xrrk_ddd_s16_k(int16x4_t,int16x4_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int16x4_t __ndp7_wr_dd_s16(int16x4_t, __encoding_t);
int16x4_t __ndp7_wr_dd_s16_s8(int8x8_t, __encoding_t);
int16x4_t __ndp7_wr_dq_s16_s32(int32x4_t, __encoding_t);
int16x4_t __ndp7_xr_dd_s16_s16_s8(int16x4_t,int8x8_t, __encoding_t);
int16x4_t __ndp9_wrk_dd_s16_k(int16x4_t,__constrange(0,3) int, __encoding_t);
int16x4_t __nhigh_wr_dq_s16(int16x8_t, __encoding_t);
int16x4_t __nlow_wr_dq_s16(int16x8_t, __encoding_t);
int16x4_t __reinterpret___d_s16_f32(float32x2_t, __encoding_t);
int16x4_t __reinterpret___d_s16_p16(poly16x4_t, __encoding_t);
int16x4_t __reinterpret___d_s16_p8(poly8x8_t, __encoding_t);
int16x4_t __reinterpret___d_s16_s32(int32x2_t, __encoding_t);
int16x4_t __reinterpret___d_s16_s64(int64x1_t, __encoding_t);
int16x4_t __reinterpret___d_s16_s8(int8x8_t, __encoding_t);
int16x4_t __reinterpret___d_s16_u16(uint16x4_t, __encoding_t);
int16x4_t __reinterpret___d_s16_u32(uint32x2_t, __encoding_t);
int16x4_t __reinterpret___d_s16_u64(uint64x1_t, __encoding_t);
int16x4_t __reinterpret___d_s16_u8(uint8x8_t, __encoding_t);
int16x4_t __vext16_wrrk_ddd_s16_k(int16x4_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int16x4_t __vld_wr_d0_s16(__transfersize(1) int16_t const *, __encoding_t);
int16x4_t __vld_wr_d0_s16(__transfersize(4) int16_t const *, __encoding_t);
int16x4_t __vld_xr_d0_s16_k(__transfersize(1) int16_t const *,
                 int16x4_t, 
                 __constrange(0,3) int, __encoding_t);
int16x4_t __vmov_wr_di_s16(int16_t, __encoding_t);
int16x4_t __vmov_wrr_dii_s16_u64(uint64_t, __encoding_t);
int16x4_t __vmov_xr_di_s16_k(int16_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int16x4x2_t __ndp7_xx_dd_s16(int16x4_t,int16x4_t, __encoding_t);
int16x4x2_t __vld_wr_d01_s16(__transfersize(2) int16_t const *, __encoding_t);
int16x4x2_t __vld_wr_d01_s16(__transfersize(8) int16_t const *, __encoding_t);
int16x4x2_t __vld_xr_d01_s16_k(__transfersize(2) int16_t const *,
                 int16x4x2_t, 
                 __constrange(0,3) int, __encoding_t);
int16x4x3_t __vld_wr_d012_s16(__transfersize(12) int16_t const *, __encoding_t);
int16x4x3_t __vld_wr_d012_s16(__transfersize(3) int16_t const *, __encoding_t);
int16x4x3_t __vld_xr_d012_s16_k(__transfersize(3) int16_t const *,
                 int16x4x3_t, 
                 __constrange(0,3) int, __encoding_t);
int16x4x4_t __vld_wr_d0123_s16(__transfersize(16) int16_t const *, __encoding_t);
int16x4x4_t __vld_wr_d0123_s16(__transfersize(4) int16_t const *, __encoding_t);
int16x4x4_t __vld_xr_d0123_s16_k(__transfersize(4) int16_t const *,
                 int16x4x4_t, 
                 __constrange(0,3) int, __encoding_t);
int16x8_t __ndp1_wrr_qqq_s16(int16x8_t,int16x8_t, __encoding_t);
int16x8_t __ndp1_xrr_qqq_s16(int16x8_t,int16x8_t,int16x8_t, __encoding_t);
int16x8_t __ndp1_xrr_qqq_s16_u16_s16(uint16x8_t,int16x8_t,int16x8_t, __encoding_t);
int16x8_t __ndp2_wr_qd_s16_s8(int8x8_t, __encoding_t);
int16x8_t __ndp2_wrk_qd_s16_s8_k(int8x8_t,__constrange(0,8) int, __encoding_t);
int16x8_t __ndp2_wrk_qq_s16_k(int16x8_t,__constrange(0,15) int, __encoding_t);
int16x8_t __ndp2_wrk_qq_s16_k(int16x8_t,__constrange(1,16) int, __encoding_t);
int16x8_t __ndp2_xrk_qq_s16_k(int16x8_t,int16x8_t,__constrange(0,15) int, __encoding_t);
int16x8_t __ndp2_xrk_qq_s16_k(int16x8_t,int16x8_t,__constrange(1,16) int, __encoding_t);
int16x8_t __ndp4_wrr_qdd_s16_s8(int8x8_t,int8x8_t, __encoding_t);
int16x8_t __ndp4_wrr_qqd_s16_s16_s8(int16x8_t,int8x8_t, __encoding_t);
int16x8_t __ndp4_xrr_qdd_s16_s16_s8(int16x8_t,int8x8_t,int8x8_t, __encoding_t);
int16x8_t __ndp5_wrr_qqi_s16(int16x8_t,int16_t, __encoding_t);
int16x8_t __ndp5_wrrk_qqd_s16_k(int16x8_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int16x8_t __ndp5_xrr_qqi_s16(int16x8_t,int16x8_t,int16_t, __encoding_t);
int16x8_t __ndp5_xrrk_qqd_s16_k(int16x8_t,int16x8_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int16x8_t __ndp7_wr_qq_s16(int16x8_t, __encoding_t);
int16x8_t __ndp7_wr_qq_s16_s8(int8x16_t, __encoding_t);
int16x8_t __ndp7_xr_qq_s16_s16_s8(int16x8_t,int8x16_t, __encoding_t);
int16x8_t __ndp9_wrk_qd_s16_k(int16x4_t,__constrange(0,3) int, __encoding_t);
int16x8_t __njoin_wrr_qdd_s16(int16x4_t,int16x4_t, __encoding_t);
int16x8_t __reinterpret___q_s16_f32(float32x4_t, __encoding_t);
int16x8_t __reinterpret___q_s16_p16(poly16x8_t, __encoding_t);
int16x8_t __reinterpret___q_s16_p8(poly8x16_t, __encoding_t);
int16x8_t __reinterpret___q_s16_s32(int32x4_t, __encoding_t);
int16x8_t __reinterpret___q_s16_s64(int64x2_t, __encoding_t);
int16x8_t __reinterpret___q_s16_s8(int8x16_t, __encoding_t);
int16x8_t __reinterpret___q_s16_u16(uint16x8_t, __encoding_t);
int16x8_t __reinterpret___q_s16_u32(uint32x4_t, __encoding_t);
int16x8_t __reinterpret___q_s16_u64(uint64x2_t, __encoding_t);
int16x8_t __reinterpret___q_s16_u8(uint8x16_t, __encoding_t);
int16x8_t __vext16_wrrk_qqq_s16_k(int16x8_t,int16x8_t,__constrange(0,7) int, __encoding_t);
int16x8_t __vld_wr_extq0_s16(__transfersize(1) int16_t const *, __encoding_t);
int16x8_t __vld_wr_q0_s16(__transfersize(8) int16_t const *, __encoding_t);
int16x8_t __vld_xr_q0_s16_k(__transfersize(1) int16_t const *,
                 int16x8_t, 
                 __constrange(0,7) int, __encoding_t);
int16x8_t __vmov_wr_qi_s16(int16_t, __encoding_t);
int16x8_t __vmov_xr_qi_s16_k(int16_t,int16x8_t,__constrange(0,7) int, __encoding_t);
int16x8x2_t __ndp7_xx_qq_s16(int16x8_t,int16x8_t, __encoding_t);
int16x8x2_t __vld_wr_q01_s16(__transfersize(16) int16_t const *, __encoding_t);
int16x8x2_t __vld_xr_q01_s16_k(__transfersize(2) int16_t const *,
                 int16x8x2_t, 
                 __constrange(0,7) int, __encoding_t);
int16x8x3_t __vld_wr_q012_s16(__transfersize(24) int16_t const *, __encoding_t);
int16x8x3_t __vld_xr_q012_s16_k(__transfersize(3) int16_t const *,
                 int16x8x3_t, 
                 __constrange(0,7) int, __encoding_t);
int16x8x4_t __vld_wr_q0123_s16(__transfersize(32) int16_t const *, __encoding_t);
int16x8x4_t __vld_xr_q0123_s16_k(__transfersize(4) int16_t const *,
                 int16x8x4_t, 
                 __constrange(0,7) int, __encoding_t);
int32_t __vmov_wr_id_s32_k(int32x2_t,__constrange(0,1) int, __encoding_t);
int32_t __vmov_wr_iq_s32_k(int32x4_t,__constrange(0,3) int, __encoding_t);
int32x2_t __ndp1_wrr_ddd_s32(int32x2_t,int32x2_t, __encoding_t);
int32x2_t __ndp1_xrr_ddd_s32(int32x2_t,int32x2_t,int32x2_t, __encoding_t);
int32x2_t __ndp1_xrr_ddd_s32_u32_s32(uint32x2_t,int32x2_t,int32x2_t, __encoding_t);
int32x2_t __ndp2_wr_dd_s32_f32(float32x2_t, __encoding_t);
int32x2_t __ndp2_wrk_dd_s32_f32_k(float32x2_t,__constrange(1,32) int, __encoding_t);
int32x2_t __ndp2_wrk_dd_s32_k(int32x2_t,__constrange(0,31) int, __encoding_t);
int32x2_t __ndp2_wrk_dd_s32_k(int32x2_t,__constrange(1,32) int, __encoding_t);
int32x2_t __ndp2_wrk_dq_s32_s64_k(int64x2_t,__constrange(1,32) int, __encoding_t);
int32x2_t __ndp2_xrk_dd_s32_k(int32x2_t,int32x2_t,__constrange(0,31) int, __encoding_t);
int32x2_t __ndp2_xrk_dd_s32_k(int32x2_t,int32x2_t,__constrange(1,32) int, __encoding_t);
int32x2_t __ndp4_wrr_dqq_s32_s64(int64x2_t,int64x2_t, __encoding_t);
int32x2_t __ndp5_wrr_ddi_s32(int32x2_t,int32_t, __encoding_t);
int32x2_t __ndp5_wrrk_ddd_s32_k(int32x2_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int32x2_t __ndp5_xrr_ddi_s32(int32x2_t,int32x2_t,int32_t, __encoding_t);
int32x2_t __ndp5_xrrk_ddd_s32_k(int32x2_t,int32x2_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int32x2_t __ndp7_wr_dd_s32(int32x2_t, __encoding_t);
int32x2_t __ndp7_wr_dd_s32_s16(int16x4_t, __encoding_t);
int32x2_t __ndp7_wr_dq_s32_s64(int64x2_t, __encoding_t);
int32x2_t __ndp7_xr_dd_s32_s32_s16(int32x2_t,int16x4_t, __encoding_t);
int32x2_t __ndp9_wrk_dd_s32_k(int32x2_t,__constrange(0,1) int, __encoding_t);
int32x2_t __nhigh_wr_dq_s32(int32x4_t, __encoding_t);
int32x2_t __nlow_wr_dq_s32(int32x4_t, __encoding_t);
int32x2_t __reinterpret___d_s32_f32(float32x2_t, __encoding_t);
int32x2_t __reinterpret___d_s32_p16(poly16x4_t, __encoding_t);
int32x2_t __reinterpret___d_s32_p8(poly8x8_t, __encoding_t);
int32x2_t __reinterpret___d_s32_s16(int16x4_t, __encoding_t);
int32x2_t __reinterpret___d_s32_s64(int64x1_t, __encoding_t);
int32x2_t __reinterpret___d_s32_s8(int8x8_t, __encoding_t);
int32x2_t __reinterpret___d_s32_u16(uint16x4_t, __encoding_t);
int32x2_t __reinterpret___d_s32_u32(uint32x2_t, __encoding_t);
int32x2_t __reinterpret___d_s32_u64(uint64x1_t, __encoding_t);
int32x2_t __reinterpret___d_s32_u8(uint8x8_t, __encoding_t);
int32x2_t __vext32_wrrk_ddd_s32_k(int32x2_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int32x2_t __vld_wr_d0_s32(__transfersize(1) int32_t const *, __encoding_t);
int32x2_t __vld_wr_d0_s32(__transfersize(2) int32_t const *, __encoding_t);
int32x2_t __vld_xr_d0_s32_k(__transfersize(1) int32_t const *,
                 int32x2_t, 
                 __constrange(0,1) int, __encoding_t);
int32x2_t __vmov_wr_di_s32(int32_t, __encoding_t);
int32x2_t __vmov_wrr_dii_s32_u64(uint64_t, __encoding_t);
int32x2_t __vmov_xr_di_s32_k(int32_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int32x2x2_t __ndp7_xx_dd_s32(int32x2_t,int32x2_t, __encoding_t);
int32x2x2_t __vld_wr_d01_s32(__transfersize(2) int32_t const *, __encoding_t);
int32x2x2_t __vld_wr_d01_s32(__transfersize(4) int32_t const *, __encoding_t);
int32x2x2_t __vld_xr_d01_s32_k(__transfersize(2) int32_t const *,
                 int32x2x2_t, 
                 __constrange(0,1) int, __encoding_t);
int32x2x3_t __vld_wr_d012_s32(__transfersize(3) int32_t const *, __encoding_t);
int32x2x3_t __vld_wr_d012_s32(__transfersize(6) int32_t const *, __encoding_t);
int32x2x3_t __vld_xr_d012_s32_k(__transfersize(3) int32_t const *,
                 int32x2x3_t, 
                 __constrange(0,1) int, __encoding_t);
int32x2x4_t __vld_wr_d0123_s32(__transfersize(4) int32_t const *, __encoding_t);
int32x2x4_t __vld_wr_d0123_s32(__transfersize(8) int32_t const *, __encoding_t);
int32x2x4_t __vld_xr_d0123_s32_k(__transfersize(4) int32_t const *,
                 int32x2x4_t, 
                 __constrange(0,1) int, __encoding_t);
int32x4_t __ndp1_wrr_qqq_s32(int32x4_t,int32x4_t, __encoding_t);
int32x4_t __ndp1_xrr_qqq_s32(int32x4_t,int32x4_t,int32x4_t, __encoding_t);
int32x4_t __ndp1_xrr_qqq_s32_u32_s32(uint32x4_t,int32x4_t,int32x4_t, __encoding_t);
int32x4_t __ndp2_wr_qd_s32_s16(int16x4_t, __encoding_t);
int32x4_t __ndp2_wr_qq_s32_f32(float32x4_t, __encoding_t);
int32x4_t __ndp2_wrk_qd_s32_s16_k(int16x4_t,__constrange(0,16) int, __encoding_t);
int32x4_t __ndp2_wrk_qq_s32_f32_k(float32x4_t,__constrange(1,32) int, __encoding_t);
int32x4_t __ndp2_wrk_qq_s32_k(int32x4_t,__constrange(0,31) int, __encoding_t);
int32x4_t __ndp2_wrk_qq_s32_k(int32x4_t,__constrange(1,32) int, __encoding_t);
int32x4_t __ndp2_xrk_qq_s32_k(int32x4_t,int32x4_t,__constrange(0,31) int, __encoding_t);
int32x4_t __ndp2_xrk_qq_s32_k(int32x4_t,int32x4_t,__constrange(1,32) int, __encoding_t);
int32x4_t __ndp4_wrr_qdd_s32_s16(int16x4_t,int16x4_t, __encoding_t);
int32x4_t __ndp4_wrr_qqd_s32_s32_s16(int32x4_t,int16x4_t, __encoding_t);
int32x4_t __ndp4_xrr_qdd_s32_s32_s16(int32x4_t,int16x4_t,int16x4_t, __encoding_t);
int32x4_t __ndp5_wrr_qdi_s32_s16(int16x4_t,int16_t, __encoding_t);
int32x4_t __ndp5_wrr_qqi_s32(int32x4_t,int32_t, __encoding_t);
int32x4_t __ndp5_wrrk_qdd_s32_s16_k(int16x4_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int32x4_t __ndp5_wrrk_qqd_s32_k(int32x4_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int32x4_t __ndp5_xrr_qdi_s32_s32_s16(int32x4_t,int16x4_t,int16_t, __encoding_t);
int32x4_t __ndp5_xrr_qqi_s32(int32x4_t,int32x4_t,int32_t, __encoding_t);
int32x4_t __ndp5_xrrk_qdd_s32_s32_s16_k(int32x4_t,int16x4_t,int16x4_t,__constrange(0,3) int, __encoding_t);
int32x4_t __ndp5_xrrk_qqd_s32_k(int32x4_t,int32x4_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int32x4_t __ndp7_wr_qq_s32(int32x4_t, __encoding_t);
int32x4_t __ndp7_wr_qq_s32_s16(int16x8_t, __encoding_t);
int32x4_t __ndp7_xr_qq_s32_s32_s16(int32x4_t,int16x8_t, __encoding_t);
int32x4_t __ndp9_wrk_qd_s32_k(int32x2_t,__constrange(0,1) int, __encoding_t);
int32x4_t __njoin_wrr_qdd_s32(int32x2_t,int32x2_t, __encoding_t);
int32x4_t __reinterpret___q_s32_f32(float32x4_t, __encoding_t);
int32x4_t __reinterpret___q_s32_p16(poly16x8_t, __encoding_t);
int32x4_t __reinterpret___q_s32_p8(poly8x16_t, __encoding_t);
int32x4_t __reinterpret___q_s32_s16(int16x8_t, __encoding_t);
int32x4_t __reinterpret___q_s32_s64(int64x2_t, __encoding_t);
int32x4_t __reinterpret___q_s32_s8(int8x16_t, __encoding_t);
int32x4_t __reinterpret___q_s32_u16(uint16x8_t, __encoding_t);
int32x4_t __reinterpret___q_s32_u32(uint32x4_t, __encoding_t);
int32x4_t __reinterpret___q_s32_u64(uint64x2_t, __encoding_t);
int32x4_t __reinterpret___q_s32_u8(uint8x16_t, __encoding_t);
int32x4_t __vext32_wrrk_qqq_s32_k(int32x4_t,int32x4_t,__constrange(0,3) int, __encoding_t);
int32x4_t __vld_wr_extq0_s32(__transfersize(1) int32_t const *, __encoding_t);
int32x4_t __vld_wr_q0_s32(__transfersize(4) int32_t const *, __encoding_t);
int32x4_t __vld_xr_q0_s32_k(__transfersize(1) int32_t const *,
                 int32x4_t, 
                 __constrange(0,3) int, __encoding_t);
int32x4_t __vmov_wr_qi_s32(int32_t, __encoding_t);
int32x4_t __vmov_xr_qi_s32_k(int32_t,int32x4_t,__constrange(0,3) int, __encoding_t);
int32x4x2_t __ndp7_xx_qq_s32(int32x4_t,int32x4_t, __encoding_t);
int32x4x2_t __vld_wr_q01_s32(__transfersize(8) int32_t const *, __encoding_t);
int32x4x2_t __vld_xr_q01_s32_k(__transfersize(2) int32_t const *,
                 int32x4x2_t, 
                 __constrange(0,3) int, __encoding_t);
int32x4x3_t __vld_wr_q012_s32(__transfersize(12) int32_t const *, __encoding_t);
int32x4x3_t __vld_xr_q012_s32_k(__transfersize(3) int32_t const *,
                 int32x4x3_t, 
                 __constrange(0,3) int, __encoding_t);
int32x4x4_t __vld_wr_q0123_s32(__transfersize(16) int32_t const *, __encoding_t);
int32x4x4_t __vld_xr_q0123_s32_k(__transfersize(4) int32_t const *,
                 int32x4x4_t, 
                 __constrange(0,3) int, __encoding_t);
int64_t __vmov_wwr_iid_s64_k(int64x1_t,__constrange(0,0) int, __encoding_t);
int64_t __vmov_wwr_iiq_s64_k(int64x2_t,__constrange(0,1) int, __encoding_t);
int64x1_t __ndp1_wrr_ddd_s64(int64x1_t,int64x1_t, __encoding_t);
int64x1_t __ndp1_xrr_ddd_s64_u64_s64(uint64x1_t,int64x1_t,int64x1_t, __encoding_t);
int64x1_t __ndp2_wrk_dd_s64_k(int64x1_t,__constrange(0,63) int, __encoding_t);
int64x1_t __ndp2_wrk_dd_s64_k(int64x1_t,__constrange(1,64) int, __encoding_t);
int64x1_t __ndp2_xrk_dd_s64_k(int64x1_t,int64x1_t,__constrange(0,63) int, __encoding_t);
int64x1_t __ndp2_xrk_dd_s64_k(int64x1_t,int64x1_t,__constrange(1,64) int, __encoding_t);
int64x1_t __ndp7_wr_dd_s64_s32(int32x2_t, __encoding_t);
int64x1_t __ndp7_xr_dd_s64_s64_s32(int64x1_t,int32x2_t, __encoding_t);
int64x1_t __ndp9_wrk_dd_s64_k(int64x1_t,__constrange(0,0) int, __encoding_t);
int64x1_t __nhigh_wr_dq_s64(int64x2_t, __encoding_t);
int64x1_t __nlow_wr_dq_s64(int64x2_t, __encoding_t);
int64x1_t __reinterpret___d_s64_f32(float32x2_t, __encoding_t);
int64x1_t __reinterpret___d_s64_p16(poly16x4_t, __encoding_t);
int64x1_t __reinterpret___d_s64_p8(poly8x8_t, __encoding_t);
int64x1_t __reinterpret___d_s64_s16(int16x4_t, __encoding_t);
int64x1_t __reinterpret___d_s64_s32(int32x2_t, __encoding_t);
int64x1_t __reinterpret___d_s64_s8(int8x8_t, __encoding_t);
int64x1_t __reinterpret___d_s64_u16(uint16x4_t, __encoding_t);
int64x1_t __reinterpret___d_s64_u32(uint32x2_t, __encoding_t);
int64x1_t __reinterpret___d_s64_u64(uint64x1_t, __encoding_t);
int64x1_t __reinterpret___d_s64_u8(uint8x8_t, __encoding_t);
int64x1_t __vext64_wrrk_ddd_s64_k(int64x1_t,int64x1_t,__constrange(0,0) int, __encoding_t);
int64x1_t __vld_wr_d0_s64(__transfersize(1) int64_t const *, __encoding_t);
int64x1_t __vld_xr_d0_s64_k(__transfersize(1) int64_t const *,
                 int64x1_t, 
                 __constrange(0,0) int, __encoding_t);
int64x1_t __vmov_wrr_dii_s64(int64_t, __encoding_t);
int64x1_t __vmov_wrr_dii_s64_u64(uint64_t, __encoding_t);
int64x1_t __vmov_xr_di_s64_k(int64_t,int64x1_t,__constrange(0,0) int, __encoding_t);
int64x1x2_t __vld_wr_d01_s64(__transfersize(2) int64_t const *, __encoding_t);
int64x1x3_t __vld_wr_d012_s64(__transfersize(3) int64_t const *, __encoding_t);
int64x1x4_t __vld_wr_d0123_s64(__transfersize(4) int64_t const *, __encoding_t);
int64x2_t __ndp1_wrr_qqq_s64(int64x2_t,int64x2_t, __encoding_t);
int64x2_t __ndp1_xrr_qqq_s64_u64_s64(uint64x2_t,int64x2_t,int64x2_t, __encoding_t);
int64x2_t __ndp2_wr_qd_s64_s32(int32x2_t, __encoding_t);
int64x2_t __ndp2_wrk_qd_s64_s32_k(int32x2_t,__constrange(0,32) int, __encoding_t);
int64x2_t __ndp2_wrk_qq_s64_k(int64x2_t,__constrange(0,63) int, __encoding_t);
int64x2_t __ndp2_wrk_qq_s64_k(int64x2_t,__constrange(1,64) int, __encoding_t);
int64x2_t __ndp2_xrk_qq_s64_k(int64x2_t,int64x2_t,__constrange(0,63) int, __encoding_t);
int64x2_t __ndp2_xrk_qq_s64_k(int64x2_t,int64x2_t,__constrange(1,64) int, __encoding_t);
int64x2_t __ndp4_wrr_qdd_s64_s32(int32x2_t,int32x2_t, __encoding_t);
int64x2_t __ndp4_wrr_qqd_s64_s64_s32(int64x2_t,int32x2_t, __encoding_t);
int64x2_t __ndp4_xrr_qdd_s64_s64_s32(int64x2_t,int32x2_t,int32x2_t, __encoding_t);
int64x2_t __ndp5_wrr_qdi_s64_s32(int32x2_t,int32_t, __encoding_t);
int64x2_t __ndp5_wrrk_qdd_s64_s32_k(int32x2_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int64x2_t __ndp5_xrr_qdi_s64_s64_s32(int64x2_t,int32x2_t,int32_t, __encoding_t);
int64x2_t __ndp5_xrrk_qdd_s64_s64_s32_k(int64x2_t,int32x2_t,int32x2_t,__constrange(0,1) int, __encoding_t);
int64x2_t __ndp7_wr_qq_s64_s32(int32x4_t, __encoding_t);
int64x2_t __ndp7_xr_qq_s64_s64_s32(int64x2_t,int32x4_t, __encoding_t);
int64x2_t __ndp9_wrk_qd_s64_k(int64x1_t,__constrange(0,0) int, __encoding_t);
int64x2_t __njoin_wrr_qdd_s64(int64x1_t,int64x1_t, __encoding_t);
int64x2_t __reinterpret___q_s64_f32(float32x4_t, __encoding_t);
int64x2_t __reinterpret___q_s64_p16(poly16x8_t, __encoding_t);
int64x2_t __reinterpret___q_s64_p8(poly8x16_t, __encoding_t);
int64x2_t __reinterpret___q_s64_s16(int16x8_t, __encoding_t);
int64x2_t __reinterpret___q_s64_s32(int32x4_t, __encoding_t);
int64x2_t __reinterpret___q_s64_s8(int8x16_t, __encoding_t);
int64x2_t __reinterpret___q_s64_u16(uint16x8_t, __encoding_t);
int64x2_t __reinterpret___q_s64_u32(uint32x4_t, __encoding_t);
int64x2_t __reinterpret___q_s64_u64(uint64x2_t, __encoding_t);
int64x2_t __reinterpret___q_s64_u8(uint8x16_t, __encoding_t);
int64x2_t __vext64_wrrk_qqq_s64_k(int64x2_t,int64x2_t,__constrange(0,1) int, __encoding_t);
int64x2_t __vld_wr_extq0_s64(__transfersize(1) int64_t const *, __encoding_t);
int64x2_t __vld_wr_q0_s64(__transfersize(2) int64_t const *, __encoding_t);
int64x2_t __vld_xr_q0_s64_k(__transfersize(1) int64_t const *,
                 int64x2_t, 
                 __constrange(0,1) int, __encoding_t);
int64x2_t __vmov_wrr_qii_s64(int64_t, __encoding_t);
int64x2_t __vmov_xr_qi_s64_k(int64_t,int64x2_t,__constrange(0,1) int, __encoding_t);
int8_t __vmov_wr_id_s8_k(int8x8_t,__constrange(0,7) int, __encoding_t);
int8_t __vmov_wr_iq_s8_k(int8x16_t,__constrange(0,15) int, __encoding_t);
int8x16_t __ndp1_wrr_qqq_s8(int8x16_t,int8x16_t, __encoding_t);
int8x16_t __ndp1_xrr_qqq_s8(int8x16_t,int8x16_t,int8x16_t, __encoding_t);
int8x16_t __ndp1_xrr_qqq_s8_u8_s8(uint8x16_t,int8x16_t,int8x16_t, __encoding_t);
int8x16_t __ndp2_wrk_qq_s8_k(int8x16_t,__constrange(0,7) int, __encoding_t);
int8x16_t __ndp2_wrk_qq_s8_k(int8x16_t,__constrange(1,8) int, __encoding_t);
int8x16_t __ndp2_xrk_qq_s8_k(int8x16_t,int8x16_t,__constrange(0,7) int, __encoding_t);
int8x16_t __ndp2_xrk_qq_s8_k(int8x16_t,int8x16_t,__constrange(1,8) int, __encoding_t);
int8x16_t __ndp7_wr_qq_s8(int8x16_t, __encoding_t);
int8x16_t __ndp9_wrk_qd_s8_k(int8x8_t,__constrange(0,7) int, __encoding_t);
int8x16_t __njoin_wrr_qdd_s8(int8x8_t,int8x8_t, __encoding_t);
int8x16_t __reinterpret___q_s8_f32(float32x4_t, __encoding_t);
int8x16_t __reinterpret___q_s8_p16(poly16x8_t, __encoding_t);
int8x16_t __reinterpret___q_s8_p8(poly8x16_t, __encoding_t);
int8x16_t __reinterpret___q_s8_s16(int16x8_t, __encoding_t);
int8x16_t __reinterpret___q_s8_s32(int32x4_t, __encoding_t);
int8x16_t __reinterpret___q_s8_s64(int64x2_t, __encoding_t);
int8x16_t __reinterpret___q_s8_u16(uint16x8_t, __encoding_t);
int8x16_t __reinterpret___q_s8_u32(uint32x4_t, __encoding_t);
int8x16_t __reinterpret___q_s8_u64(uint64x2_t, __encoding_t);
int8x16_t __reinterpret___q_s8_u8(uint8x16_t, __encoding_t);
int8x16_t __vext8_wrrk_qqq_s8_k(int8x16_t,int8x16_t,__constrange(0,15) int, __encoding_t);
int8x16_t __vld_wr_extq0_s8(__transfersize(1) int8_t const *, __encoding_t);
int8x16_t __vld_wr_q0_s8(__transfersize(16) int8_t const *, __encoding_t);
int8x16_t __vld_xr_q0_s8_k(__transfersize(1) int8_t const *,
                 int8x16_t, 
                 __constrange(0,15) int, __encoding_t);
int8x16_t __vmov_wr_qi_s8(int8_t, __encoding_t);
int8x16_t __vmov_xr_qi_s8_k(int8_t,int8x16_t,__constrange(0,15) int, __encoding_t);
int8x16x2_t __ndp7_xx_qq_s8(int8x16_t,int8x16_t, __encoding_t);
int8x16x2_t __vld_wr_q01_s8(__transfersize(32) int8_t const *, __encoding_t);
int8x16x3_t __vld_wr_q012_s8(__transfersize(48) int8_t const *, __encoding_t);
int8x16x4_t __vld_wr_q0123_s8(__transfersize(64) int8_t const *, __encoding_t);
int8x8_t __ndp1_wrr_ddd_s8(int8x8_t,int8x8_t, __encoding_t);
int8x8_t __ndp1_xrr_ddd_s8(int8x8_t,int8x8_t,int8x8_t, __encoding_t);
int8x8_t __ndp1_xrr_ddd_s8_u8_s8(uint8x8_t,int8x8_t,int8x8_t, __encoding_t);
int8x8_t __ndp2_wrk_dd_s8_k(int8x8_t,__constrange(0,7) int, __encoding_t);
int8x8_t __ndp2_wrk_dd_s8_k(int8x8_t,__constrange(1,8) int, __encoding_t);
int8x8_t __ndp2_wrk_dq_s8_s16_k(int16x8_t,__constrange(1,8) int, __encoding_t);
int8x8_t __ndp2_xrk_dd_s8_k(int8x8_t,int8x8_t,__constrange(0,7) int, __encoding_t);
int8x8_t __ndp2_xrk_dd_s8_k(int8x8_t,int8x8_t,__constrange(1,8) int, __encoding_t);
int8x8_t __ndp4_wrr_dqq_s8_s16(int16x8_t,int16x8_t, __encoding_t);
int8x8_t __ndp7_wr_dd_s8(int8x8_t, __encoding_t);
int8x8_t __ndp7_wr_dq_s8_s16(int16x8_t, __encoding_t);
int8x8_t __ndp9_wrk_dd_s8_k(int8x8_t,__constrange(0,7) int, __encoding_t);
int8x8_t __nhigh_wr_dq_s8(int8x16_t, __encoding_t);
int8x8_t __nlow_wr_dq_s8(int8x16_t, __encoding_t);
int8x8_t __reinterpret___d_s8_f32(float32x2_t, __encoding_t);
int8x8_t __reinterpret___d_s8_p16(poly16x4_t, __encoding_t);
int8x8_t __reinterpret___d_s8_p8(poly8x8_t, __encoding_t);
int8x8_t __reinterpret___d_s8_s16(int16x4_t, __encoding_t);
int8x8_t __reinterpret___d_s8_s32(int32x2_t, __encoding_t);
int8x8_t __reinterpret___d_s8_s64(int64x1_t, __encoding_t);
int8x8_t __reinterpret___d_s8_u16(uint16x4_t, __encoding_t);
int8x8_t __reinterpret___d_s8_u32(uint32x2_t, __encoding_t);
int8x8_t __reinterpret___d_s8_u64(uint64x1_t, __encoding_t);
int8x8_t __reinterpret___d_s8_u8(uint8x8_t, __encoding_t);
int8x8_t __tbl_wrr_0123_s8(int8x8x4_t,int8x8_t, __encoding_t);
int8x8_t __tbl_wrr_012_s8(int8x8x3_t,int8x8_t, __encoding_t);
int8x8_t __tbl_wrr_01_s8(int8x8x2_t,int8x8_t, __encoding_t);
int8x8_t __tbl_wrr_0_s8(int8x8_t,int8x8_t, __encoding_t);
int8x8_t __tbx_xrr_0123_s8(int8x8_t,int8x8x4_t,int8x8_t, __encoding_t);
int8x8_t __tbx_xrr_012_s8(int8x8_t,int8x8x3_t,int8x8_t, __encoding_t);
int8x8_t __tbx_xrr_01_s8(int8x8_t,int8x8x2_t,int8x8_t, __encoding_t);
int8x8_t __tbx_xrr_0_s8(int8x8_t,int8x8_t,int8x8_t, __encoding_t);
int8x8_t __vext8_wrrk_ddd_s8_k(int8x8_t,int8x8_t,__constrange(0,7) int, __encoding_t);
int8x8_t __vld_wr_d0_s8(__transfersize(1) int8_t const *, __encoding_t);
int8x8_t __vld_wr_d0_s8(__transfersize(8) int8_t const *, __encoding_t);
int8x8_t __vld_xr_d0_s8_k(__transfersize(1) int8_t const *,
                 int8x8_t, 
                 __constrange(0,7) int, __encoding_t);
int8x8_t __vmov_wr_di_s8(int8_t, __encoding_t);
int8x8_t __vmov_wrr_dii_s8_u64(uint64_t, __encoding_t);
int8x8_t __vmov_xr_di_s8_k(int8_t,int8x8_t,__constrange(0,7) int, __encoding_t);
int8x8x2_t __ndp7_xx_dd_s8(int8x8_t,int8x8_t, __encoding_t);
int8x8x2_t __vld_wr_d01_s8(__transfersize(16) int8_t const *, __encoding_t);
int8x8x2_t __vld_wr_d01_s8(__transfersize(2) int8_t const *, __encoding_t);
int8x8x2_t __vld_xr_d01_s8_k(__transfersize(2) int8_t const *,
                 int8x8x2_t, 
                 __constrange(0,7) int, __encoding_t);
int8x8x3_t __vld_wr_d012_s8(__transfersize(24) int8_t const *, __encoding_t);
int8x8x3_t __vld_wr_d012_s8(__transfersize(3) int8_t const *, __encoding_t);
int8x8x3_t __vld_xr_d012_s8_k(__transfersize(3) int8_t const *,
                 int8x8x3_t, 
                 __constrange(0,7) int, __encoding_t);
int8x8x4_t __vld_wr_d0123_s8(__transfersize(32) int8_t const *, __encoding_t);
int8x8x4_t __vld_wr_d0123_s8(__transfersize(4) int8_t const *, __encoding_t);
int8x8x4_t __vld_xr_d0123_s8_k(__transfersize(4) int8_t const *,
                 int8x8x4_t, 
                 __constrange(0,7) int, __encoding_t);
poly16_t __vmov_wr_id_p16_k(poly16x4_t,__constrange(0,3) int, __encoding_t);
poly16_t __vmov_wr_iq_p16_k(poly16x8_t,__constrange(0,7) int, __encoding_t);
poly16x4_t __ndp1_xrr_ddd_p16_u16_p16(uint16x4_t,poly16x4_t,poly16x4_t, __encoding_t);
poly16x4_t __ndp2_xrk_dd_p16_k(poly16x4_t,poly16x4_t,__constrange(0,15) int, __encoding_t);
poly16x4_t __ndp2_xrk_dd_p16_k(poly16x4_t,poly16x4_t,__constrange(1,16) int, __encoding_t);
poly16x4_t __ndp7_wr_dd_p16(poly16x4_t, __encoding_t);
poly16x4_t __ndp9_wrk_dd_p16_k(poly16x4_t,__constrange(0,3) int, __encoding_t);
poly16x4_t __nhigh_wr_dq_p16(poly16x8_t, __encoding_t);
poly16x4_t __nlow_wr_dq_p16(poly16x8_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_f32(float32x2_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_p8(poly8x8_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_s16(int16x4_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_s32(int32x2_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_s64(int64x1_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_s8(int8x8_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_u16(uint16x4_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_u32(uint32x2_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_u64(uint64x1_t, __encoding_t);
poly16x4_t __reinterpret___d_p16_u8(uint8x8_t, __encoding_t);
poly16x4_t __vext16_wrrk_ddd_p16_k(poly16x4_t,poly16x4_t,__constrange(0,3) int, __encoding_t);
poly16x4_t __vld_wr_d0_p16(__transfersize(1) poly16_t const *, __encoding_t);
poly16x4_t __vld_wr_d0_p16(__transfersize(4) poly16_t const *, __encoding_t);
poly16x4_t __vld_xr_d0_p16_k(__transfersize(1) poly16_t const *,
                 poly16x4_t, 
                 __constrange(0,3) int, __encoding_t);
poly16x4_t __vmov_wr_di_p16(poly16_t, __encoding_t);
poly16x4_t __vmov_wrr_dii_p16_u64(uint64_t, __encoding_t);
poly16x4_t __vmov_xr_di_p16_k(poly16_t,poly16x4_t,__constrange(0,3) int, __encoding_t);
poly16x4x2_t __ndp7_xx_dd_p16(poly16x4_t,poly16x4_t, __encoding_t);
poly16x4x2_t __vld_wr_d01_p16(__transfersize(2) poly16_t const *, __encoding_t);
poly16x4x2_t __vld_wr_d01_p16(__transfersize(8) poly16_t const *, __encoding_t);
poly16x4x2_t __vld_xr_d01_p16_k(__transfersize(2) poly16_t const *,
                 poly16x4x2_t, 
                 __constrange(0,3) int, __encoding_t);
poly16x4x3_t __vld_wr_d012_p16(__transfersize(12) poly16_t const *, __encoding_t);
poly16x4x3_t __vld_wr_d012_p16(__transfersize(3) poly16_t const *, __encoding_t);
poly16x4x3_t __vld_xr_d012_p16_k(__transfersize(3) poly16_t const *,
                 poly16x4x3_t, 
                 __constrange(0,3) int, __encoding_t);
poly16x4x4_t __vld_wr_d0123_p16(__transfersize(16) poly16_t const *, __encoding_t);
poly16x4x4_t __vld_wr_d0123_p16(__transfersize(4) poly16_t const *, __encoding_t);
poly16x4x4_t __vld_xr_d0123_p16_k(__transfersize(4) poly16_t const *,
                 poly16x4x4_t, 
                 __constrange(0,3) int, __encoding_t);
poly16x8_t __ndp1_xrr_qqq_p16_u16_p16(uint16x8_t,poly16x8_t,poly16x8_t, __encoding_t);
poly16x8_t __ndp2_xrk_qq_p16_k(poly16x8_t,poly16x8_t,__constrange(0,15) int, __encoding_t);
poly16x8_t __ndp2_xrk_qq_p16_k(poly16x8_t,poly16x8_t,__constrange(1,16) int, __encoding_t);
poly16x8_t __ndp4_wrr_qdd_p16_p8(poly8x8_t,poly8x8_t, __encoding_t);
poly16x8_t __ndp7_wr_qq_p16(poly16x8_t, __encoding_t);
poly16x8_t __ndp9_wrk_qd_p16_k(poly16x4_t,__constrange(0,3) int, __encoding_t);
poly16x8_t __njoin_wrr_qdd_p16(poly16x4_t,poly16x4_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_f32(float32x4_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_p8(poly8x16_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_s16(int16x8_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_s32(int32x4_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_s64(int64x2_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_s8(int8x16_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_u16(uint16x8_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_u32(uint32x4_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_u64(uint64x2_t, __encoding_t);
poly16x8_t __reinterpret___q_p16_u8(uint8x16_t, __encoding_t);
poly16x8_t __vext16_wrrk_qqq_p16_k(poly16x8_t,poly16x8_t,__constrange(0,7) int, __encoding_t);
poly16x8_t __vld_wr_extq0_p16(__transfersize(1) poly16_t const *, __encoding_t);
poly16x8_t __vld_wr_q0_p16(__transfersize(8) poly16_t const *, __encoding_t);
poly16x8_t __vld_xr_q0_p16_k(__transfersize(1) poly16_t const *,
                 poly16x8_t, 
                 __constrange(0,7) int, __encoding_t);
poly16x8_t __vmov_wr_qi_p16(poly16_t, __encoding_t);
poly16x8_t __vmov_xr_qi_p16_k(poly16_t,poly16x8_t,__constrange(0,7) int, __encoding_t);
poly16x8x2_t __ndp7_xx_qq_p16(poly16x8_t,poly16x8_t, __encoding_t);
poly16x8x2_t __vld_wr_q01_p16(__transfersize(16) poly16_t const *, __encoding_t);
poly16x8x2_t __vld_xr_q01_p16_k(__transfersize(2) poly16_t const *,
                 poly16x8x2_t, 
                 __constrange(0,7) int, __encoding_t);
poly16x8x3_t __vld_wr_q012_p16(__transfersize(24) poly16_t const *, __encoding_t);
poly16x8x3_t __vld_xr_q012_p16_k(__transfersize(3) poly16_t const *,
                 poly16x8x3_t, 
                 __constrange(0,7) int, __encoding_t);
poly16x8x4_t __vld_wr_q0123_p16(__transfersize(32) poly16_t const *, __encoding_t);
poly16x8x4_t __vld_xr_q0123_p16_k(__transfersize(4) poly16_t const *,
                 poly16x8x4_t, 
                 __constrange(0,7) int, __encoding_t);
poly8_t __vmov_wr_id_p8_k(poly8x8_t,__constrange(0,7) int, __encoding_t);
poly8_t __vmov_wr_iq_p8_k(poly8x16_t,__constrange(0,15) int, __encoding_t);
poly8x16_t __ndp1_wrr_qqq_p8(poly8x16_t,poly8x16_t, __encoding_t);
poly8x16_t __ndp1_xrr_qqq_p8_u8_p8(uint8x16_t,poly8x16_t,poly8x16_t, __encoding_t);
poly8x16_t __ndp2_xrk_qq_p8_k(poly8x16_t,poly8x16_t,__constrange(0,7) int, __encoding_t);
poly8x16_t __ndp2_xrk_qq_p8_k(poly8x16_t,poly8x16_t,__constrange(1,8) int, __encoding_t);
poly8x16_t __ndp7_wr_qq_p8(poly8x16_t, __encoding_t);
poly8x16_t __ndp9_wrk_qd_p8_k(poly8x8_t,__constrange(0,7) int, __encoding_t);
poly8x16_t __njoin_wrr_qdd_p8(poly8x8_t,poly8x8_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_f32(float32x4_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_p16(poly16x8_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_s16(int16x8_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_s32(int32x4_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_s64(int64x2_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_s8(int8x16_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_u16(uint16x8_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_u32(uint32x4_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_u64(uint64x2_t, __encoding_t);
poly8x16_t __reinterpret___q_p8_u8(uint8x16_t, __encoding_t);
poly8x16_t __vext8_wrrk_qqq_p8_k(poly8x16_t,poly8x16_t,__constrange(0,15) int, __encoding_t);
poly8x16_t __vld_wr_extq0_p8(__transfersize(1) poly8_t const *, __encoding_t);
poly8x16_t __vld_wr_q0_p8(__transfersize(16) poly8_t const *, __encoding_t);
poly8x16_t __vld_xr_q0_p8_k(__transfersize(1) poly8_t const *,
                 poly8x16_t, 
                 __constrange(0,15) int, __encoding_t);
poly8x16_t __vmov_wr_qi_p8(poly8_t, __encoding_t);
poly8x16_t __vmov_xr_qi_p8_k(poly8_t,poly8x16_t,__constrange(0,15) int, __encoding_t);
poly8x16x2_t __ndp7_xx_qq_p8(poly8x16_t,poly8x16_t, __encoding_t);
poly8x16x2_t __vld_wr_q01_p8(__transfersize(32) poly8_t const *, __encoding_t);
poly8x16x3_t __vld_wr_q012_p8(__transfersize(48) poly8_t const *, __encoding_t);
poly8x16x4_t __vld_wr_q0123_p8(__transfersize(64) poly8_t const *, __encoding_t);
poly8x8_t __ndp1_wrr_ddd_p8(poly8x8_t,poly8x8_t, __encoding_t);
poly8x8_t __ndp1_xrr_ddd_p8_u8_p8(uint8x8_t,poly8x8_t,poly8x8_t, __encoding_t);
poly8x8_t __ndp2_xrk_dd_p8_k(poly8x8_t,poly8x8_t,__constrange(0,7) int, __encoding_t);
poly8x8_t __ndp2_xrk_dd_p8_k(poly8x8_t,poly8x8_t,__constrange(1,8) int, __encoding_t);
poly8x8_t __ndp7_wr_dd_p8(poly8x8_t, __encoding_t);
poly8x8_t __ndp9_wrk_dd_p8_k(poly8x8_t,__constrange(0,7) int, __encoding_t);
poly8x8_t __nhigh_wr_dq_p8(poly8x16_t, __encoding_t);
poly8x8_t __nlow_wr_dq_p8(poly8x16_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_f32(float32x2_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_p16(poly16x4_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_s16(int16x4_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_s32(int32x2_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_s64(int64x1_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_s8(int8x8_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_u16(uint16x4_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_u32(uint32x2_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_u64(uint64x1_t, __encoding_t);
poly8x8_t __reinterpret___d_p8_u8(uint8x8_t, __encoding_t);
poly8x8_t __tbl_wrr_0123_p8_p8_u8(poly8x8x4_t,uint8x8_t, __encoding_t);
poly8x8_t __tbl_wrr_012_p8_p8_u8(poly8x8x3_t,uint8x8_t, __encoding_t);
poly8x8_t __tbl_wrr_01_p8_p8_u8(poly8x8x2_t,uint8x8_t, __encoding_t);
poly8x8_t __tbl_wrr_0_p8_p8_u8(poly8x8_t,uint8x8_t, __encoding_t);
poly8x8_t __tbx_xrr_0123_p8_p8_p8_u8(poly8x8_t,poly8x8x4_t,uint8x8_t, __encoding_t);
poly8x8_t __tbx_xrr_012_p8_p8_p8_u8(poly8x8_t,poly8x8x3_t,uint8x8_t, __encoding_t);
poly8x8_t __tbx_xrr_01_p8_p8_p8_u8(poly8x8_t,poly8x8x2_t,uint8x8_t, __encoding_t);
poly8x8_t __tbx_xrr_0_p8_p8_p8_u8(poly8x8_t,poly8x8_t,uint8x8_t, __encoding_t);
poly8x8_t __vext8_wrrk_ddd_p8_k(poly8x8_t,poly8x8_t,__constrange(0,7) int, __encoding_t);
poly8x8_t __vld_wr_d0_p8(__transfersize(1) poly8_t const *, __encoding_t);
poly8x8_t __vld_wr_d0_p8(__transfersize(8) poly8_t const *, __encoding_t);
poly8x8_t __vld_xr_d0_p8_k(__transfersize(1) poly8_t const *,
                 poly8x8_t, 
                 __constrange(0,7) int, __encoding_t);
poly8x8_t __vmov_wr_di_p8(poly8_t, __encoding_t);
poly8x8_t __vmov_wrr_dii_p8_u64(uint64_t, __encoding_t);
poly8x8_t __vmov_xr_di_p8_k(poly8_t,poly8x8_t,__constrange(0,7) int, __encoding_t);
poly8x8x2_t __ndp7_xx_dd_p8(poly8x8_t,poly8x8_t, __encoding_t);
poly8x8x2_t __vld_wr_d01_p8(__transfersize(16) poly8_t const *, __encoding_t);
poly8x8x2_t __vld_wr_d01_p8(__transfersize(2) poly8_t const *, __encoding_t);
poly8x8x2_t __vld_xr_d01_p8_k(__transfersize(2) poly8_t const *,
                 poly8x8x2_t, 
                 __constrange(0,7) int, __encoding_t);
poly8x8x3_t __vld_wr_d012_p8(__transfersize(24) poly8_t const *, __encoding_t);
poly8x8x3_t __vld_wr_d012_p8(__transfersize(3) poly8_t const *, __encoding_t);
poly8x8x3_t __vld_xr_d012_p8_k(__transfersize(3) poly8_t const *,
                 poly8x8x3_t, 
                 __constrange(0,7) int, __encoding_t);
poly8x8x4_t __vld_wr_d0123_p8(__transfersize(32) poly8_t const *, __encoding_t);
poly8x8x4_t __vld_wr_d0123_p8(__transfersize(4) poly8_t const *, __encoding_t);
poly8x8x4_t __vld_xr_d0123_p8_k(__transfersize(4) poly8_t const *,
                 poly8x8x4_t, 
                 __constrange(0,7) int, __encoding_t);
uint16_t __vmov_wr_id_u16_k(uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16_t __vmov_wr_iq_u16_k(uint16x8_t,__constrange(0,7) int, __encoding_t);
uint16x4_t __ndp1_wrr_ddd_u16(uint16x4_t,uint16x4_t, __encoding_t);
uint16x4_t __ndp1_wrr_ddd_u16_p16(poly16x4_t,poly16x4_t, __encoding_t);
uint16x4_t __ndp1_wrr_ddd_u16_s16(int16x4_t,int16x4_t, __encoding_t);
uint16x4_t __ndp1_wrr_ddd_u16_u16_s16(uint16x4_t,int16x4_t, __encoding_t);
uint16x4_t __ndp1_xrr_ddd_u16(uint16x4_t,uint16x4_t,uint16x4_t, __encoding_t);
uint16x4_t __ndp2_wrk_dd_u16_k(uint16x4_t,__constrange(0,15) int, __encoding_t);
uint16x4_t __ndp2_wrk_dd_u16_k(uint16x4_t,__constrange(1,16) int, __encoding_t);
uint16x4_t __ndp2_wrk_dd_u16_s16_k(int16x4_t,__constrange(0,15) int, __encoding_t);
uint16x4_t __ndp2_wrk_dq_u16_s32_k(int32x4_t,__constrange(1,16) int, __encoding_t);
uint16x4_t __ndp2_wrk_dq_u16_u32_k(uint32x4_t,__constrange(1,16) int, __encoding_t);
uint16x4_t __ndp2_xrk_dd_u16_k(uint16x4_t,uint16x4_t,__constrange(0,15) int, __encoding_t);
uint16x4_t __ndp2_xrk_dd_u16_k(uint16x4_t,uint16x4_t,__constrange(1,16) int, __encoding_t);
uint16x4_t __ndp4_wrr_dqq_u16_u32(uint32x4_t,uint32x4_t, __encoding_t);
uint16x4_t __ndp5_wrr_ddi_u16(uint16x4_t,uint16_t, __encoding_t);
uint16x4_t __ndp5_wrrk_ddd_u16_k(uint16x4_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x4_t __ndp5_xrr_ddi_u16(uint16x4_t,uint16x4_t,uint16_t, __encoding_t);
uint16x4_t __ndp5_xrrk_ddd_u16_k(uint16x4_t,uint16x4_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x4_t __ndp7_wr_dd_u16(uint16x4_t, __encoding_t);
uint16x4_t __ndp7_wr_dd_u16_s16(int16x4_t, __encoding_t);
uint16x4_t __ndp7_wr_dd_u16_u8(uint8x8_t, __encoding_t);
uint16x4_t __ndp7_wr_dq_u16_s32(int32x4_t, __encoding_t);
uint16x4_t __ndp7_wr_dq_u16_u32(uint32x4_t, __encoding_t);
uint16x4_t __ndp7_xr_dd_u16_u16_u8(uint16x4_t,uint8x8_t, __encoding_t);
uint16x4_t __ndp9_wrk_dd_u16_k(uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x4_t __nhigh_wr_dq_u16(uint16x8_t, __encoding_t);
uint16x4_t __nlow_wr_dq_u16(uint16x8_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_f32(float32x2_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_p16(poly16x4_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_p8(poly8x8_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_s16(int16x4_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_s32(int32x2_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_s64(int64x1_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_s8(int8x8_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_u32(uint32x2_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_u64(uint64x1_t, __encoding_t);
uint16x4_t __reinterpret___d_u16_u8(uint8x8_t, __encoding_t);
uint16x4_t __swap_ndp1_wrr_ddd_u16(uint16x4_t,uint16x4_t, __encoding_t);
uint16x4_t __swap_ndp1_wrr_ddd_u16_s16(int16x4_t,int16x4_t, __encoding_t);
uint16x4_t __vext16_wrrk_ddd_u16_k(uint16x4_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x4_t __vld_wr_d0_u16(__transfersize(1) uint16_t const *, __encoding_t);
uint16x4_t __vld_wr_d0_u16(__transfersize(4) uint16_t const *, __encoding_t);
uint16x4_t __vld_xr_d0_u16_k(__transfersize(1) uint16_t const *,
                 uint16x4_t, 
                 __constrange(0,3) int, __encoding_t);
uint16x4_t __vmov_wr_di_u16(uint16_t, __encoding_t);
uint16x4_t __vmov_wrr_dii_u16_u64(uint64_t, __encoding_t);
uint16x4_t __vmov_xr_di_u16_k(uint16_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x4x2_t __ndp7_xx_dd_u16(uint16x4_t,uint16x4_t, __encoding_t);
uint16x4x2_t __vld_wr_d01_u16(__transfersize(2) uint16_t const *, __encoding_t);
uint16x4x2_t __vld_wr_d01_u16(__transfersize(8) uint16_t const *, __encoding_t);
uint16x4x2_t __vld_xr_d01_u16_k(__transfersize(2) uint16_t const *,
                 uint16x4x2_t, 
                 __constrange(0,3) int, __encoding_t);
uint16x4x3_t __vld_wr_d012_u16(__transfersize(12) uint16_t const *, __encoding_t);
uint16x4x3_t __vld_wr_d012_u16(__transfersize(3) uint16_t const *, __encoding_t);
uint16x4x3_t __vld_xr_d012_u16_k(__transfersize(3) uint16_t const *,
                 uint16x4x3_t, 
                 __constrange(0,3) int, __encoding_t);
uint16x4x4_t __vld_wr_d0123_u16(__transfersize(16) uint16_t const *, __encoding_t);
uint16x4x4_t __vld_wr_d0123_u16(__transfersize(4) uint16_t const *, __encoding_t);
uint16x4x4_t __vld_xr_d0123_u16_k(__transfersize(4) uint16_t const *,
                 uint16x4x4_t, 
                 __constrange(0,3) int, __encoding_t);
uint16x8_t __ndp1_wrr_qqq_u16(uint16x8_t,uint16x8_t, __encoding_t);
uint16x8_t __ndp1_wrr_qqq_u16_p16(poly16x8_t,poly16x8_t, __encoding_t);
uint16x8_t __ndp1_wrr_qqq_u16_s16(int16x8_t,int16x8_t, __encoding_t);
uint16x8_t __ndp1_wrr_qqq_u16_u16_s16(uint16x8_t,int16x8_t, __encoding_t);
uint16x8_t __ndp1_xrr_qqq_u16(uint16x8_t,uint16x8_t,uint16x8_t, __encoding_t);
uint16x8_t __ndp2_wr_qd_u16_u8(uint8x8_t, __encoding_t);
uint16x8_t __ndp2_wrk_qd_u16_u8_k(uint8x8_t,__constrange(0,8) int, __encoding_t);
uint16x8_t __ndp2_wrk_qq_u16_k(uint16x8_t,__constrange(0,15) int, __encoding_t);
uint16x8_t __ndp2_wrk_qq_u16_k(uint16x8_t,__constrange(1,16) int, __encoding_t);
uint16x8_t __ndp2_wrk_qq_u16_s16_k(int16x8_t,__constrange(0,15) int, __encoding_t);
uint16x8_t __ndp2_xrk_qq_u16_k(uint16x8_t,uint16x8_t,__constrange(0,15) int, __encoding_t);
uint16x8_t __ndp2_xrk_qq_u16_k(uint16x8_t,uint16x8_t,__constrange(1,16) int, __encoding_t);
uint16x8_t __ndp4_wrr_qdd_u16_u8(uint8x8_t,uint8x8_t, __encoding_t);
uint16x8_t __ndp4_wrr_qqd_u16_u16_u8(uint16x8_t,uint8x8_t, __encoding_t);
uint16x8_t __ndp4_xrr_qdd_u16_u16_u8(uint16x8_t,uint8x8_t,uint8x8_t, __encoding_t);
uint16x8_t __ndp5_wrr_qqi_u16(uint16x8_t,uint16_t, __encoding_t);
uint16x8_t __ndp5_wrrk_qqd_u16_k(uint16x8_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x8_t __ndp5_xrr_qqi_u16(uint16x8_t,uint16x8_t,uint16_t, __encoding_t);
uint16x8_t __ndp5_xrrk_qqd_u16_k(uint16x8_t,uint16x8_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x8_t __ndp7_wr_qq_u16(uint16x8_t, __encoding_t);
uint16x8_t __ndp7_wr_qq_u16_s16(int16x8_t, __encoding_t);
uint16x8_t __ndp7_wr_qq_u16_u8(uint8x16_t, __encoding_t);
uint16x8_t __ndp7_xr_qq_u16_u16_u8(uint16x8_t,uint8x16_t, __encoding_t);
uint16x8_t __ndp9_wrk_qd_u16_k(uint16x4_t,__constrange(0,3) int, __encoding_t);
uint16x8_t __njoin_wrr_qdd_u16(uint16x4_t,uint16x4_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_f32(float32x4_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_p16(poly16x8_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_p8(poly8x16_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_s16(int16x8_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_s32(int32x4_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_s64(int64x2_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_s8(int8x16_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_u32(uint32x4_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_u64(uint64x2_t, __encoding_t);
uint16x8_t __reinterpret___q_u16_u8(uint8x16_t, __encoding_t);
uint16x8_t __swap_ndp1_wrr_qqq_u16(uint16x8_t,uint16x8_t, __encoding_t);
uint16x8_t __swap_ndp1_wrr_qqq_u16_s16(int16x8_t,int16x8_t, __encoding_t);
uint16x8_t __vext16_wrrk_qqq_u16_k(uint16x8_t,uint16x8_t,__constrange(0,7) int, __encoding_t);
uint16x8_t __vld_wr_extq0_u16(__transfersize(1) uint16_t const *, __encoding_t);
uint16x8_t __vld_wr_q0_u16(__transfersize(8) uint16_t const *, __encoding_t);
uint16x8_t __vld_xr_q0_u16_k(__transfersize(1) uint16_t const *,
                 uint16x8_t, 
                 __constrange(0,7) int, __encoding_t);
uint16x8_t __vmov_wr_qi_u16(uint16_t, __encoding_t);
uint16x8_t __vmov_xr_qi_u16_k(uint16_t,uint16x8_t,__constrange(0,7) int, __encoding_t);
uint16x8x2_t __ndp7_xx_qq_u16(uint16x8_t,uint16x8_t, __encoding_t);
uint16x8x2_t __vld_wr_q01_u16(__transfersize(16) uint16_t const *, __encoding_t);
uint16x8x2_t __vld_xr_q01_u16_k(__transfersize(2) uint16_t const *,
                 uint16x8x2_t, 
                 __constrange(0,7) int, __encoding_t);
uint16x8x3_t __vld_wr_q012_u16(__transfersize(24) uint16_t const *, __encoding_t);
uint16x8x3_t __vld_xr_q012_u16_k(__transfersize(3) uint16_t const *,
                 uint16x8x3_t, 
                 __constrange(0,7) int, __encoding_t);
uint16x8x4_t __vld_wr_q0123_u16(__transfersize(32) uint16_t const *, __encoding_t);
uint16x8x4_t __vld_xr_q0123_u16_k(__transfersize(4) uint16_t const *,
                 uint16x8x4_t, 
                 __constrange(0,7) int, __encoding_t);
uint32_t __vmov_wr_id_u32_k(uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32_t __vmov_wr_iq_u32_k(uint32x4_t,__constrange(0,3) int, __encoding_t);
uint32x2_t __ndp1_wrr_ddd_u32(uint32x2_t,uint32x2_t, __encoding_t);
uint32x2_t __ndp1_wrr_ddd_u32_f32(float32x2_t,float32x2_t, __encoding_t);
uint32x2_t __ndp1_wrr_ddd_u32_s32(int32x2_t,int32x2_t, __encoding_t);
uint32x2_t __ndp1_wrr_ddd_u32_u32_s32(uint32x2_t,int32x2_t, __encoding_t);
uint32x2_t __ndp1_xrr_ddd_u32(uint32x2_t,uint32x2_t,uint32x2_t, __encoding_t);
uint32x2_t __ndp2_wr_dd_u32_f32(float32x2_t, __encoding_t);
uint32x2_t __ndp2_wrk_dd_u32_f32_k(float32x2_t,__constrange(1,32) int, __encoding_t);
uint32x2_t __ndp2_wrk_dd_u32_k(uint32x2_t,__constrange(0,31) int, __encoding_t);
uint32x2_t __ndp2_wrk_dd_u32_k(uint32x2_t,__constrange(1,32) int, __encoding_t);
uint32x2_t __ndp2_wrk_dd_u32_s32_k(int32x2_t,__constrange(0,31) int, __encoding_t);
uint32x2_t __ndp2_wrk_dq_u32_s64_k(int64x2_t,__constrange(1,32) int, __encoding_t);
uint32x2_t __ndp2_wrk_dq_u32_u64_k(uint64x2_t,__constrange(1,32) int, __encoding_t);
uint32x2_t __ndp2_xrk_dd_u32_k(uint32x2_t,uint32x2_t,__constrange(0,31) int, __encoding_t);
uint32x2_t __ndp2_xrk_dd_u32_k(uint32x2_t,uint32x2_t,__constrange(1,32) int, __encoding_t);
uint32x2_t __ndp4_wrr_dqq_u32_u64(uint64x2_t,uint64x2_t, __encoding_t);
uint32x2_t __ndp5_wrr_ddi_u32(uint32x2_t,uint32_t, __encoding_t);
uint32x2_t __ndp5_wrrk_ddd_u32_k(uint32x2_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x2_t __ndp5_xrr_ddi_u32(uint32x2_t,uint32x2_t,uint32_t, __encoding_t);
uint32x2_t __ndp5_xrrk_ddd_u32_k(uint32x2_t,uint32x2_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x2_t __ndp7_wr_dd_u32(uint32x2_t, __encoding_t);
uint32x2_t __ndp7_wr_dd_u32_f32(float32x2_t, __encoding_t);
uint32x2_t __ndp7_wr_dd_u32_s32(int32x2_t, __encoding_t);
uint32x2_t __ndp7_wr_dd_u32_u16(uint16x4_t, __encoding_t);
uint32x2_t __ndp7_wr_dq_u32_s64(int64x2_t, __encoding_t);
uint32x2_t __ndp7_wr_dq_u32_u64(uint64x2_t, __encoding_t);
uint32x2_t __ndp7_xr_dd_u32_u32_u16(uint32x2_t,uint16x4_t, __encoding_t);
uint32x2_t __ndp9_wrk_dd_u32_k(uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x2_t __nhigh_wr_dq_u32(uint32x4_t, __encoding_t);
uint32x2_t __nlow_wr_dq_u32(uint32x4_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_f32(float32x2_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_p16(poly16x4_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_p8(poly8x8_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_s16(int16x4_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_s32(int32x2_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_s64(int64x1_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_s8(int8x8_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_u16(uint16x4_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_u64(uint64x1_t, __encoding_t);
uint32x2_t __reinterpret___d_u32_u8(uint8x8_t, __encoding_t);
uint32x2_t __swap_ndp1_wrr_ddd_u32(uint32x2_t,uint32x2_t, __encoding_t);
uint32x2_t __swap_ndp1_wrr_ddd_u32_f32(float32x2_t,float32x2_t, __encoding_t);
uint32x2_t __swap_ndp1_wrr_ddd_u32_s32(int32x2_t,int32x2_t, __encoding_t);
uint32x2_t __vext32_wrrk_ddd_u32_k(uint32x2_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x2_t __vld_wr_d0_u32(__transfersize(1) uint32_t const *, __encoding_t);
uint32x2_t __vld_wr_d0_u32(__transfersize(2) uint32_t const *, __encoding_t);
uint32x2_t __vld_xr_d0_u32_k(__transfersize(1) uint32_t const *,
                 uint32x2_t, 
                 __constrange(0,1) int, __encoding_t);
uint32x2_t __vmov_wr_di_u32(uint32_t, __encoding_t);
uint32x2_t __vmov_wrr_dii_u32_u64(uint64_t, __encoding_t);
uint32x2_t __vmov_xr_di_u32_k(uint32_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x2x2_t __ndp7_xx_dd_u32(uint32x2_t,uint32x2_t, __encoding_t);
uint32x2x2_t __vld_wr_d01_u32(__transfersize(2) uint32_t const *, __encoding_t);
uint32x2x2_t __vld_wr_d01_u32(__transfersize(4) uint32_t const *, __encoding_t);
uint32x2x2_t __vld_xr_d01_u32_k(__transfersize(2) uint32_t const *,
                 uint32x2x2_t, 
                 __constrange(0,1) int, __encoding_t);
uint32x2x3_t __vld_wr_d012_u32(__transfersize(3) uint32_t const *, __encoding_t);
uint32x2x3_t __vld_wr_d012_u32(__transfersize(6) uint32_t const *, __encoding_t);
uint32x2x3_t __vld_xr_d012_u32_k(__transfersize(3) uint32_t const *,
                 uint32x2x3_t, 
                 __constrange(0,1) int, __encoding_t);
uint32x2x4_t __vld_wr_d0123_u32(__transfersize(4) uint32_t const *, __encoding_t);
uint32x2x4_t __vld_wr_d0123_u32(__transfersize(8) uint32_t const *, __encoding_t);
uint32x2x4_t __vld_xr_d0123_u32_k(__transfersize(4) uint32_t const *,
                 uint32x2x4_t, 
                 __constrange(0,1) int, __encoding_t);
uint32x4_t __ndp1_wrr_qqq_u32(uint32x4_t,uint32x4_t, __encoding_t);
uint32x4_t __ndp1_wrr_qqq_u32_f32(float32x4_t,float32x4_t, __encoding_t);
uint32x4_t __ndp1_wrr_qqq_u32_s32(int32x4_t,int32x4_t, __encoding_t);
uint32x4_t __ndp1_wrr_qqq_u32_u32_s32(uint32x4_t,int32x4_t, __encoding_t);
uint32x4_t __ndp1_xrr_qqq_u32(uint32x4_t,uint32x4_t,uint32x4_t, __encoding_t);
uint32x4_t __ndp2_wr_qd_u32_u16(uint16x4_t, __encoding_t);
uint32x4_t __ndp2_wr_qq_u32_f32(float32x4_t, __encoding_t);
uint32x4_t __ndp2_wrk_qd_u32_u16_k(uint16x4_t,__constrange(0,16) int, __encoding_t);
uint32x4_t __ndp2_wrk_qq_u32_f32_k(float32x4_t,__constrange(1,32) int, __encoding_t);
uint32x4_t __ndp2_wrk_qq_u32_k(uint32x4_t,__constrange(0,31) int, __encoding_t);
uint32x4_t __ndp2_wrk_qq_u32_k(uint32x4_t,__constrange(1,32) int, __encoding_t);
uint32x4_t __ndp2_wrk_qq_u32_s32_k(int32x4_t,__constrange(0,31) int, __encoding_t);
uint32x4_t __ndp2_xrk_qq_u32_k(uint32x4_t,uint32x4_t,__constrange(0,31) int, __encoding_t);
uint32x4_t __ndp2_xrk_qq_u32_k(uint32x4_t,uint32x4_t,__constrange(1,32) int, __encoding_t);
uint32x4_t __ndp4_wrr_qdd_u32_u16(uint16x4_t,uint16x4_t, __encoding_t);
uint32x4_t __ndp4_wrr_qqd_u32_u32_u16(uint32x4_t,uint16x4_t, __encoding_t);
uint32x4_t __ndp4_xrr_qdd_u32_u32_u16(uint32x4_t,uint16x4_t,uint16x4_t, __encoding_t);
uint32x4_t __ndp5_wrr_qdi_u32_u16(uint16x4_t,uint16_t, __encoding_t);
uint32x4_t __ndp5_wrr_qqi_u32(uint32x4_t,uint32_t, __encoding_t);
uint32x4_t __ndp5_wrrk_qdd_u32_u16_k(uint16x4_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint32x4_t __ndp5_wrrk_qqd_u32_k(uint32x4_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x4_t __ndp5_xrr_qdi_u32_u32_u16(uint32x4_t,uint16x4_t,uint16_t, __encoding_t);
uint32x4_t __ndp5_xrr_qqi_u32(uint32x4_t,uint32x4_t,uint32_t, __encoding_t);
uint32x4_t __ndp5_xrrk_qdd_u32_u32_u16_k(uint32x4_t,uint16x4_t,uint16x4_t,__constrange(0,3) int, __encoding_t);
uint32x4_t __ndp5_xrrk_qqd_u32_k(uint32x4_t,uint32x4_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x4_t __ndp7_wr_qq_u32(uint32x4_t, __encoding_t);
uint32x4_t __ndp7_wr_qq_u32_f32(float32x4_t, __encoding_t);
uint32x4_t __ndp7_wr_qq_u32_s32(int32x4_t, __encoding_t);
uint32x4_t __ndp7_wr_qq_u32_u16(uint16x8_t, __encoding_t);
uint32x4_t __ndp7_xr_qq_u32_u32_u16(uint32x4_t,uint16x8_t, __encoding_t);
uint32x4_t __ndp9_wrk_qd_u32_k(uint32x2_t,__constrange(0,1) int, __encoding_t);
uint32x4_t __njoin_wrr_qdd_u32(uint32x2_t,uint32x2_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_f32(float32x4_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_p16(poly16x8_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_p8(poly8x16_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_s16(int16x8_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_s32(int32x4_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_s64(int64x2_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_s8(int8x16_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_u16(uint16x8_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_u64(uint64x2_t, __encoding_t);
uint32x4_t __reinterpret___q_u32_u8(uint8x16_t, __encoding_t);
uint32x4_t __swap_ndp1_wrr_qqq_u32(uint32x4_t,uint32x4_t, __encoding_t);
uint32x4_t __swap_ndp1_wrr_qqq_u32_f32(float32x4_t,float32x4_t, __encoding_t);
uint32x4_t __swap_ndp1_wrr_qqq_u32_s32(int32x4_t,int32x4_t, __encoding_t);
uint32x4_t __vext32_wrrk_qqq_u32_k(uint32x4_t,uint32x4_t,__constrange(0,3) int, __encoding_t);
uint32x4_t __vld_wr_extq0_u32(__transfersize(1) uint32_t const *, __encoding_t);
uint32x4_t __vld_wr_q0_u32(__transfersize(4) uint32_t const *, __encoding_t);
uint32x4_t __vld_xr_q0_u32_k(__transfersize(1) uint32_t const *,
                 uint32x4_t, 
                 __constrange(0,3) int, __encoding_t);
uint32x4_t __vmov_wr_qi_u32(uint32_t, __encoding_t);
uint32x4_t __vmov_xr_qi_u32_k(uint32_t,uint32x4_t,__constrange(0,3) int, __encoding_t);
uint32x4x2_t __ndp7_xx_qq_u32(uint32x4_t,uint32x4_t, __encoding_t);
uint32x4x2_t __vld_wr_q01_u32(__transfersize(8) uint32_t const *, __encoding_t);
uint32x4x2_t __vld_xr_q01_u32_k(__transfersize(2) uint32_t const *,
                 uint32x4x2_t, 
                 __constrange(0,3) int, __encoding_t);
uint32x4x3_t __vld_wr_q012_u32(__transfersize(12) uint32_t const *, __encoding_t);
uint32x4x3_t __vld_xr_q012_u32_k(__transfersize(3) uint32_t const *,
                 uint32x4x3_t, 
                 __constrange(0,3) int, __encoding_t);
uint32x4x4_t __vld_wr_q0123_u32(__transfersize(16) uint32_t const *, __encoding_t);
uint32x4x4_t __vld_xr_q0123_u32_k(__transfersize(4) uint32_t const *,
                 uint32x4x4_t, 
                 __constrange(0,3) int, __encoding_t);
uint64_t __vmov_wwr_iid_u64_k(uint64x1_t,__constrange(0,0) int, __encoding_t);
uint64_t __vmov_wwr_iiq_u64_k(uint64x2_t,__constrange(0,1) int, __encoding_t);
uint64x1_t __ndp1_wrr_ddd_u64(uint64x1_t,uint64x1_t, __encoding_t);
uint64x1_t __ndp1_wrr_ddd_u64_u64_s64(uint64x1_t,int64x1_t, __encoding_t);
uint64x1_t __ndp1_xrr_ddd_u64(uint64x1_t,uint64x1_t,uint64x1_t, __encoding_t);
uint64x1_t __ndp2_wrk_dd_u64_k(uint64x1_t,__constrange(0,63) int, __encoding_t);
uint64x1_t __ndp2_wrk_dd_u64_k(uint64x1_t,__constrange(1,64) int, __encoding_t);
uint64x1_t __ndp2_wrk_dd_u64_s64_k(int64x1_t,__constrange(0,63) int, __encoding_t);
uint64x1_t __ndp2_xrk_dd_u64_k(uint64x1_t,uint64x1_t,__constrange(0,63) int, __encoding_t);
uint64x1_t __ndp2_xrk_dd_u64_k(uint64x1_t,uint64x1_t,__constrange(1,64) int, __encoding_t);
uint64x1_t __ndp7_wr_dd_u64_u32(uint32x2_t, __encoding_t);
uint64x1_t __ndp7_xr_dd_u64_u64_u32(uint64x1_t,uint32x2_t, __encoding_t);
uint64x1_t __ndp9_wrk_dd_u64_k(uint64x1_t,__constrange(0,0) int, __encoding_t);
uint64x1_t __nhigh_wr_dq_u64(uint64x2_t, __encoding_t);
uint64x1_t __nlow_wr_dq_u64(uint64x2_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_f32(float32x2_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_p16(poly16x4_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_p8(poly8x8_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_s16(int16x4_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_s32(int32x2_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_s64(int64x1_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_s8(int8x8_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_u16(uint16x4_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_u32(uint32x2_t, __encoding_t);
uint64x1_t __reinterpret___d_u64_u8(uint8x8_t, __encoding_t);
uint64x1_t __vext64_wrrk_ddd_u64_k(uint64x1_t,uint64x1_t,__constrange(0,0) int, __encoding_t);
uint64x1_t __vld_wr_d0_u64(__transfersize(1) uint64_t const *, __encoding_t);
uint64x1_t __vld_xr_d0_u64_k(__transfersize(1) uint64_t const *,
                 uint64x1_t, 
                 __constrange(0,0) int, __encoding_t);
uint64x1_t __vmov_wrr_dii_u64(uint64_t, __encoding_t);
uint64x1_t __vmov_xr_di_u64_k(uint64_t,uint64x1_t,__constrange(0,0) int, __encoding_t);
uint64x1x2_t __vld_wr_d01_u64(__transfersize(2) uint64_t const *, __encoding_t);
uint64x1x3_t __vld_wr_d012_u64(__transfersize(3) uint64_t const *, __encoding_t);
uint64x1x4_t __vld_wr_d0123_u64(__transfersize(4) uint64_t const *, __encoding_t);
uint64x2_t __ndp1_wrr_qqq_u64(uint64x2_t,uint64x2_t, __encoding_t);
uint64x2_t __ndp1_wrr_qqq_u64_u64_s64(uint64x2_t,int64x2_t, __encoding_t);
uint64x2_t __ndp1_xrr_qqq_u64(uint64x2_t,uint64x2_t,uint64x2_t, __encoding_t);
uint64x2_t __ndp2_wr_qd_u64_u32(uint32x2_t, __encoding_t);
uint64x2_t __ndp2_wrk_qd_u64_u32_k(uint32x2_t,__constrange(0,32) int, __encoding_t);
uint64x2_t __ndp2_wrk_qq_u64_k(uint64x2_t,__constrange(0,63) int, __encoding_t);
uint64x2_t __ndp2_wrk_qq_u64_k(uint64x2_t,__constrange(1,64) int, __encoding_t);
uint64x2_t __ndp2_wrk_qq_u64_s64_k(int64x2_t,__constrange(0,63) int, __encoding_t);
uint64x2_t __ndp2_xrk_qq_u64_k(uint64x2_t,uint64x2_t,__constrange(0,63) int, __encoding_t);
uint64x2_t __ndp2_xrk_qq_u64_k(uint64x2_t,uint64x2_t,__constrange(1,64) int, __encoding_t);
uint64x2_t __ndp4_wrr_qdd_u64_u32(uint32x2_t,uint32x2_t, __encoding_t);
uint64x2_t __ndp4_wrr_qqd_u64_u64_u32(uint64x2_t,uint32x2_t, __encoding_t);
uint64x2_t __ndp4_xrr_qdd_u64_u64_u32(uint64x2_t,uint32x2_t,uint32x2_t, __encoding_t);
uint64x2_t __ndp5_wrr_qdi_u64_u32(uint32x2_t,uint32_t, __encoding_t);
uint64x2_t __ndp5_wrrk_qdd_u64_u32_k(uint32x2_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint64x2_t __ndp5_xrr_qdi_u64_u64_u32(uint64x2_t,uint32x2_t,uint32_t, __encoding_t);
uint64x2_t __ndp5_xrrk_qdd_u64_u64_u32_k(uint64x2_t,uint32x2_t,uint32x2_t,__constrange(0,1) int, __encoding_t);
uint64x2_t __ndp7_wr_qq_u64_u32(uint32x4_t, __encoding_t);
uint64x2_t __ndp7_xr_qq_u64_u64_u32(uint64x2_t,uint32x4_t, __encoding_t);
uint64x2_t __ndp9_wrk_qd_u64_k(uint64x1_t,__constrange(0,0) int, __encoding_t);
uint64x2_t __njoin_wrr_qdd_u64(uint64x1_t,uint64x1_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_f32(float32x4_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_p16(poly16x8_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_p8(poly8x16_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_s16(int16x8_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_s32(int32x4_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_s64(int64x2_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_s8(int8x16_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_u16(uint16x8_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_u32(uint32x4_t, __encoding_t);
uint64x2_t __reinterpret___q_u64_u8(uint8x16_t, __encoding_t);
uint64x2_t __vext64_wrrk_qqq_u64_k(uint64x2_t,uint64x2_t,__constrange(0,1) int, __encoding_t);
uint64x2_t __vld_wr_extq0_u64(__transfersize(1) uint64_t const *, __encoding_t);
uint64x2_t __vld_wr_q0_u64(__transfersize(2) uint64_t const *, __encoding_t);
uint64x2_t __vld_xr_q0_u64_k(__transfersize(1) uint64_t const *,
                 uint64x2_t, 
                 __constrange(0,1) int, __encoding_t);
uint64x2_t __vmov_wrr_qii_u64(uint64_t, __encoding_t);
uint64x2_t __vmov_xr_qi_u64_k(uint64_t,uint64x2_t,__constrange(0,1) int, __encoding_t);
uint8_t __vmov_wr_id_u8_k(uint8x8_t,__constrange(0,7) int, __encoding_t);
uint8_t __vmov_wr_iq_u8_k(uint8x16_t,__constrange(0,15) int, __encoding_t);
uint8x16_t __ndp1_wrr_qqq_u8(uint8x16_t,uint8x16_t, __encoding_t);
uint8x16_t __ndp1_wrr_qqq_u8_p8(poly8x16_t,poly8x16_t, __encoding_t);
uint8x16_t __ndp1_wrr_qqq_u8_s8(int8x16_t,int8x16_t, __encoding_t);
uint8x16_t __ndp1_wrr_qqq_u8_u8_s8(uint8x16_t,int8x16_t, __encoding_t);
uint8x16_t __ndp1_xrr_qqq_u8(uint8x16_t,uint8x16_t,uint8x16_t, __encoding_t);
uint8x16_t __ndp2_wrk_qq_u8_k(uint8x16_t,__constrange(0,7) int, __encoding_t);
uint8x16_t __ndp2_wrk_qq_u8_k(uint8x16_t,__constrange(1,8) int, __encoding_t);
uint8x16_t __ndp2_wrk_qq_u8_s8_k(int8x16_t,__constrange(0,7) int, __encoding_t);
uint8x16_t __ndp2_xrk_qq_u8_k(uint8x16_t,uint8x16_t,__constrange(0,7) int, __encoding_t);
uint8x16_t __ndp2_xrk_qq_u8_k(uint8x16_t,uint8x16_t,__constrange(1,8) int, __encoding_t);
uint8x16_t __ndp7_wr_qq_u8(uint8x16_t, __encoding_t);
uint8x16_t __ndp7_wr_qq_u8_p8(poly8x16_t, __encoding_t);
uint8x16_t __ndp7_wr_qq_u8_s8(int8x16_t, __encoding_t);
uint8x16_t __ndp9_wrk_qd_u8_k(uint8x8_t,__constrange(0,7) int, __encoding_t);
uint8x16_t __njoin_wrr_qdd_u8(uint8x8_t,uint8x8_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_f32(float32x4_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_p16(poly16x8_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_p8(poly8x16_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_s16(int16x8_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_s32(int32x4_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_s64(int64x2_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_s8(int8x16_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_u16(uint16x8_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_u32(uint32x4_t, __encoding_t);
uint8x16_t __reinterpret___q_u8_u64(uint64x2_t, __encoding_t);
uint8x16_t __swap_ndp1_wrr_qqq_u8(uint8x16_t,uint8x16_t, __encoding_t);
uint8x16_t __swap_ndp1_wrr_qqq_u8_s8(int8x16_t,int8x16_t, __encoding_t);
uint8x16_t __vext8_wrrk_qqq_u8_k(uint8x16_t,uint8x16_t,__constrange(0,15) int, __encoding_t);
uint8x16_t __vld_wr_extq0_u8(__transfersize(1) uint8_t const *, __encoding_t);
uint8x16_t __vld_wr_q0_u8(__transfersize(16) uint8_t const *, __encoding_t);
uint8x16_t __vld_xr_q0_u8_k(__transfersize(1) uint8_t const *,
                 uint8x16_t, 
                 __constrange(0,15) int, __encoding_t);
uint8x16_t __vmov_wr_qi_u8(uint8_t, __encoding_t);
uint8x16_t __vmov_xr_qi_u8_k(uint8_t,uint8x16_t,__constrange(0,15) int, __encoding_t);
uint8x16x2_t __ndp7_xx_qq_u8(uint8x16_t,uint8x16_t, __encoding_t);
uint8x16x2_t __vld_wr_q01_u8(__transfersize(32) uint8_t const *, __encoding_t);
uint8x16x3_t __vld_wr_q012_u8(__transfersize(48) uint8_t const *, __encoding_t);
uint8x16x4_t __vld_wr_q0123_u8(__transfersize(64) uint8_t const *, __encoding_t);
uint8x8_t __ndp1_wrr_ddd_u8(uint8x8_t,uint8x8_t, __encoding_t);
uint8x8_t __ndp1_wrr_ddd_u8_p8(poly8x8_t,poly8x8_t, __encoding_t);
uint8x8_t __ndp1_wrr_ddd_u8_s8(int8x8_t,int8x8_t, __encoding_t);
uint8x8_t __ndp1_wrr_ddd_u8_u8_s8(uint8x8_t,int8x8_t, __encoding_t);
uint8x8_t __ndp1_xrr_ddd_u8(uint8x8_t,uint8x8_t,uint8x8_t, __encoding_t);
uint8x8_t __ndp2_wrk_dd_u8_k(uint8x8_t,__constrange(0,7) int, __encoding_t);
uint8x8_t __ndp2_wrk_dd_u8_k(uint8x8_t,__constrange(1,8) int, __encoding_t);
uint8x8_t __ndp2_wrk_dd_u8_s8_k(int8x8_t,__constrange(0,7) int, __encoding_t);
uint8x8_t __ndp2_wrk_dq_u8_s16_k(int16x8_t,__constrange(1,8) int, __encoding_t);
uint8x8_t __ndp2_wrk_dq_u8_u16_k(uint16x8_t,__constrange(1,8) int, __encoding_t);
uint8x8_t __ndp2_xrk_dd_u8_k(uint8x8_t,uint8x8_t,__constrange(0,7) int, __encoding_t);
uint8x8_t __ndp2_xrk_dd_u8_k(uint8x8_t,uint8x8_t,__constrange(1,8) int, __encoding_t);
uint8x8_t __ndp4_wrr_dqq_u8_u16(uint16x8_t,uint16x8_t, __encoding_t);
uint8x8_t __ndp7_wr_dd_u8(uint8x8_t, __encoding_t);
uint8x8_t __ndp7_wr_dd_u8_p8(poly8x8_t, __encoding_t);
uint8x8_t __ndp7_wr_dd_u8_s8(int8x8_t, __encoding_t);
uint8x8_t __ndp7_wr_dq_u8_s16(int16x8_t, __encoding_t);
uint8x8_t __ndp7_wr_dq_u8_u16(uint16x8_t, __encoding_t);
uint8x8_t __ndp9_wrk_dd_u8_k(uint8x8_t,__constrange(0,7) int, __encoding_t);
uint8x8_t __nhigh_wr_dq_u8(uint8x16_t, __encoding_t);
uint8x8_t __nlow_wr_dq_u8(uint8x16_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_f32(float32x2_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_p16(poly16x4_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_p8(poly8x8_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_s16(int16x4_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_s32(int32x2_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_s64(int64x1_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_s8(int8x8_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_u16(uint16x4_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_u32(uint32x2_t, __encoding_t);
uint8x8_t __reinterpret___d_u8_u64(uint64x1_t, __encoding_t);
uint8x8_t __swap_ndp1_wrr_ddd_u8(uint8x8_t,uint8x8_t, __encoding_t);
uint8x8_t __swap_ndp1_wrr_ddd_u8_s8(int8x8_t,int8x8_t, __encoding_t);
uint8x8_t __tbl_wrr_0123_u8(uint8x8x4_t,uint8x8_t, __encoding_t);
uint8x8_t __tbl_wrr_012_u8(uint8x8x3_t,uint8x8_t, __encoding_t);
uint8x8_t __tbl_wrr_01_u8(uint8x8x2_t,uint8x8_t, __encoding_t);
uint8x8_t __tbl_wrr_0_u8(uint8x8_t,uint8x8_t, __encoding_t);
uint8x8_t __tbx_xrr_0123_u8(uint8x8_t,uint8x8x4_t,uint8x8_t, __encoding_t);
uint8x8_t __tbx_xrr_012_u8(uint8x8_t,uint8x8x3_t,uint8x8_t, __encoding_t);
uint8x8_t __tbx_xrr_01_u8(uint8x8_t,uint8x8x2_t,uint8x8_t, __encoding_t);
uint8x8_t __tbx_xrr_0_u8(uint8x8_t,uint8x8_t,uint8x8_t, __encoding_t);
uint8x8_t __vext8_wrrk_ddd_u8_k(uint8x8_t,uint8x8_t,__constrange(0,7) int, __encoding_t);
uint8x8_t __vld_wr_d0_u8(__transfersize(1) uint8_t const *, __encoding_t);
uint8x8_t __vld_wr_d0_u8(__transfersize(8) uint8_t const *, __encoding_t);
uint8x8_t __vld_xr_d0_u8_k(__transfersize(1) uint8_t const *,
                 uint8x8_t, 
                 __constrange(0,7) int, __encoding_t);
uint8x8_t __vmov_wr_di_u8(uint8_t, __encoding_t);
uint8x8_t __vmov_wrr_dii_u8_u64(uint64_t, __encoding_t);
uint8x8_t __vmov_xr_di_u8_k(uint8_t,uint8x8_t,__constrange(0,7) int, __encoding_t);
uint8x8x2_t __ndp7_xx_dd_u8(uint8x8_t,uint8x8_t, __encoding_t);
uint8x8x2_t __vld_wr_d01_u8(__transfersize(16) uint8_t const *, __encoding_t);
uint8x8x2_t __vld_wr_d01_u8(__transfersize(2) uint8_t const *, __encoding_t);
uint8x8x2_t __vld_xr_d01_u8_k(__transfersize(2) uint8_t const *,
                 uint8x8x2_t, 
                 __constrange(0,7) int, __encoding_t);
uint8x8x3_t __vld_wr_d012_u8(__transfersize(24) uint8_t const *, __encoding_t);
uint8x8x3_t __vld_wr_d012_u8(__transfersize(3) uint8_t const *, __encoding_t);
uint8x8x3_t __vld_xr_d012_u8_k(__transfersize(3) uint8_t const *,
                 uint8x8x3_t, 
                 __constrange(0,7) int, __encoding_t);
uint8x8x4_t __vld_wr_d0123_u8(__transfersize(32) uint8_t const *, __encoding_t);
uint8x8x4_t __vld_wr_d0123_u8(__transfersize(4) uint8_t const *, __encoding_t);
uint8x8x4_t __vld_xr_d0123_u8_k(__transfersize(4) uint8_t const *,
                 uint8x8x4_t, 
                 __constrange(0,7) int, __encoding_t);
void __vst_rr_d0123_f32(__transfersize(8) float32_t *, float32x2x4_t, __encoding_t);
void __vst_rr_d0123_p16(__transfersize(16) poly16_t *, poly16x4x4_t, __encoding_t);
void __vst_rr_d0123_p8(__transfersize(32) poly8_t *, poly8x8x4_t, __encoding_t);
void __vst_rr_d0123_s16(__transfersize(16) int16_t *, int16x4x4_t, __encoding_t);
void __vst_rr_d0123_s32(__transfersize(8) int32_t *, int32x2x4_t, __encoding_t);
void __vst_rr_d0123_s64(__transfersize(4) int64_t *, int64x1x4_t, __encoding_t);
void __vst_rr_d0123_s8(__transfersize(32) int8_t *, int8x8x4_t, __encoding_t);
void __vst_rr_d0123_u16(__transfersize(16) uint16_t *, uint16x4x4_t, __encoding_t);
void __vst_rr_d0123_u32(__transfersize(8) uint32_t *, uint32x2x4_t, __encoding_t);
void __vst_rr_d0123_u64(__transfersize(4) uint64_t *, uint64x1x4_t, __encoding_t);
void __vst_rr_d0123_u8(__transfersize(32) uint8_t *, uint8x8x4_t, __encoding_t);
void __vst_rr_d012_f32(__transfersize(6) float32_t *, float32x2x3_t, __encoding_t);
void __vst_rr_d012_p16(__transfersize(12) poly16_t *, poly16x4x3_t, __encoding_t);
void __vst_rr_d012_p8(__transfersize(24) poly8_t *, poly8x8x3_t, __encoding_t);
void __vst_rr_d012_s16(__transfersize(12) int16_t *, int16x4x3_t, __encoding_t);
void __vst_rr_d012_s32(__transfersize(6) int32_t *, int32x2x3_t, __encoding_t);
void __vst_rr_d012_s64(__transfersize(3) int64_t *, int64x1x3_t, __encoding_t);
void __vst_rr_d012_s8(__transfersize(24) int8_t *, int8x8x3_t, __encoding_t);
void __vst_rr_d012_u16(__transfersize(12) uint16_t *, uint16x4x3_t, __encoding_t);
void __vst_rr_d012_u32(__transfersize(6) uint32_t *, uint32x2x3_t, __encoding_t);
void __vst_rr_d012_u64(__transfersize(3) uint64_t *, uint64x1x3_t, __encoding_t);
void __vst_rr_d012_u8(__transfersize(24) uint8_t *, uint8x8x3_t, __encoding_t);
void __vst_rr_d01_f32(__transfersize(4) float32_t *, float32x2x2_t, __encoding_t);
void __vst_rr_d01_p16(__transfersize(8) poly16_t *, poly16x4x2_t, __encoding_t);
void __vst_rr_d01_p8(__transfersize(16) poly8_t *, poly8x8x2_t, __encoding_t);
void __vst_rr_d01_s16(__transfersize(8) int16_t *, int16x4x2_t, __encoding_t);
void __vst_rr_d01_s32(__transfersize(4) int32_t *, int32x2x2_t, __encoding_t);
void __vst_rr_d01_s64(__transfersize(2) int64_t *, int64x1x2_t, __encoding_t);
void __vst_rr_d01_s8(__transfersize(16) int8_t *, int8x8x2_t, __encoding_t);
void __vst_rr_d01_u16(__transfersize(8) uint16_t *, uint16x4x2_t, __encoding_t);
void __vst_rr_d01_u32(__transfersize(4) uint32_t *, uint32x2x2_t, __encoding_t);
void __vst_rr_d01_u64(__transfersize(2) uint64_t *, uint64x1x2_t, __encoding_t);
void __vst_rr_d01_u8(__transfersize(16) uint8_t *, uint8x8x2_t, __encoding_t);
void __vst_rr_d0_f32(__transfersize(2) float32_t *,float32x2_t, __encoding_t);
void __vst_rr_d0_p16(__transfersize(4) poly16_t *,poly16x4_t, __encoding_t);
void __vst_rr_d0_p8(__transfersize(8) poly8_t *,poly8x8_t, __encoding_t);
void __vst_rr_d0_s16(__transfersize(4) int16_t *,int16x4_t, __encoding_t);
void __vst_rr_d0_s32(__transfersize(2) int32_t *,int32x2_t, __encoding_t);
void __vst_rr_d0_s64(__transfersize(1) int64_t *,int64x1_t, __encoding_t);
void __vst_rr_d0_s8(__transfersize(8) int8_t *,int8x8_t, __encoding_t);
void __vst_rr_d0_u16(__transfersize(4) uint16_t *,uint16x4_t, __encoding_t);
void __vst_rr_d0_u32(__transfersize(2) uint32_t *,uint32x2_t, __encoding_t);
void __vst_rr_d0_u64(__transfersize(1) uint64_t *,uint64x1_t, __encoding_t);
void __vst_rr_d0_u8(__transfersize(8) uint8_t *,uint8x8_t, __encoding_t);
void __vst_rr_q0123_f32(__transfersize(16) float32_t *, float32x4x4_t, __encoding_t);
void __vst_rr_q0123_p16(__transfersize(32) poly16_t *, poly16x8x4_t, __encoding_t);
void __vst_rr_q0123_p8(__transfersize(64) poly8_t *, poly8x16x4_t, __encoding_t);
void __vst_rr_q0123_s16(__transfersize(32) int16_t *, int16x8x4_t, __encoding_t);
void __vst_rr_q0123_s32(__transfersize(16) int32_t *, int32x4x4_t, __encoding_t);
void __vst_rr_q0123_s8(__transfersize(64) int8_t *, int8x16x4_t, __encoding_t);
void __vst_rr_q0123_u16(__transfersize(32) uint16_t *, uint16x8x4_t, __encoding_t);
void __vst_rr_q0123_u32(__transfersize(16) uint32_t *, uint32x4x4_t, __encoding_t);
void __vst_rr_q0123_u8(__transfersize(64) uint8_t *, uint8x16x4_t, __encoding_t);
void __vst_rr_q012_f32(__transfersize(12) float32_t *, float32x4x3_t, __encoding_t);
void __vst_rr_q012_p16(__transfersize(24) poly16_t *, poly16x8x3_t, __encoding_t);
void __vst_rr_q012_p8(__transfersize(48) poly8_t *, poly8x16x3_t, __encoding_t);
void __vst_rr_q012_s16(__transfersize(24) int16_t *, int16x8x3_t, __encoding_t);
void __vst_rr_q012_s32(__transfersize(12) int32_t *, int32x4x3_t, __encoding_t);
void __vst_rr_q012_s8(__transfersize(48) int8_t *, int8x16x3_t, __encoding_t);
void __vst_rr_q012_u16(__transfersize(24) uint16_t *, uint16x8x3_t, __encoding_t);
void __vst_rr_q012_u32(__transfersize(12) uint32_t *, uint32x4x3_t, __encoding_t);
void __vst_rr_q012_u8(__transfersize(48) uint8_t *, uint8x16x3_t, __encoding_t);
void __vst_rr_q01_f32(__transfersize(8) float32_t *, float32x4x2_t, __encoding_t);
void __vst_rr_q01_p16(__transfersize(16) poly16_t *, poly16x8x2_t, __encoding_t);
void __vst_rr_q01_p8(__transfersize(32) poly8_t *, poly8x16x2_t, __encoding_t);
void __vst_rr_q01_s16(__transfersize(16) int16_t *, int16x8x2_t, __encoding_t);
void __vst_rr_q01_s32(__transfersize(8) int32_t *, int32x4x2_t, __encoding_t);
void __vst_rr_q01_s8(__transfersize(32) int8_t *, int8x16x2_t, __encoding_t);
void __vst_rr_q01_u16(__transfersize(16) uint16_t *, uint16x8x2_t, __encoding_t);
void __vst_rr_q01_u32(__transfersize(8) uint32_t *, uint32x4x2_t, __encoding_t);
void __vst_rr_q01_u8(__transfersize(32) uint8_t *, uint8x16x2_t, __encoding_t);
void __vst_rr_q0_f32(__transfersize(4) float32_t *,float32x4_t, __encoding_t);
void __vst_rr_q0_p16(__transfersize(8) poly16_t *,poly16x8_t, __encoding_t);
void __vst_rr_q0_p8(__transfersize(16) poly8_t *,poly8x16_t, __encoding_t);
void __vst_rr_q0_s16(__transfersize(8) int16_t *,int16x8_t, __encoding_t);
void __vst_rr_q0_s32(__transfersize(4) int32_t *,int32x4_t, __encoding_t);
void __vst_rr_q0_s64(__transfersize(2) int64_t *,int64x2_t, __encoding_t);
void __vst_rr_q0_s8(__transfersize(16) int8_t *,int8x16_t, __encoding_t);
void __vst_rr_q0_u16(__transfersize(8) uint16_t *,uint16x8_t, __encoding_t);
void __vst_rr_q0_u32(__transfersize(4) uint32_t *,uint32x4_t, __encoding_t);
void __vst_rr_q0_u64(__transfersize(2) uint64_t *,uint64x2_t, __encoding_t);
void __vst_rr_q0_u8(__transfersize(16) uint8_t *,uint8x16_t, __encoding_t);
void __vst_rrk_d0123_f32_k(__transfersize(4) float32_t *,
                 float32x2x4_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d0123_p16_k(__transfersize(4) poly16_t *,
                 poly16x4x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d0123_p8_k(__transfersize(4) poly8_t *,
                 poly8x8x4_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d0123_s16_k(__transfersize(4) int16_t *,
                 int16x4x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d0123_s32_k(__transfersize(4) int32_t *,
                 int32x2x4_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d0123_s8_k(__transfersize(4) int8_t *,
                 int8x8x4_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d0123_u16_k(__transfersize(4) uint16_t *,
                 uint16x4x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d0123_u32_k(__transfersize(4) uint32_t *,
                 uint32x2x4_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d0123_u8_k(__transfersize(4) uint8_t *,
                 uint8x8x4_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d012_f32_k(__transfersize(3) float32_t *,
                 float32x2x3_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d012_p16_k(__transfersize(3) poly16_t *,
                 poly16x4x3_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d012_p8_k(__transfersize(3) poly8_t *,
                 poly8x8x3_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d012_s16_k(__transfersize(3) int16_t *,
                 int16x4x3_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d012_s32_k(__transfersize(3) int32_t *,
                 int32x2x3_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d012_s8_k(__transfersize(3) int8_t *,
                 int8x8x3_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d012_u16_k(__transfersize(3) uint16_t *,
                 uint16x4x3_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d012_u32_k(__transfersize(3) uint32_t *,
                 uint32x2x3_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d012_u8_k(__transfersize(3) uint8_t *,
                 uint8x8x3_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d01_f32_k(__transfersize(2) float32_t *,
                 float32x2x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d01_p16_k(__transfersize(2) poly16_t *,
                 poly16x4x2_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d01_p8_k(__transfersize(2) poly8_t *,
                 poly8x8x2_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d01_s16_k(__transfersize(2) int16_t *,
                 int16x4x2_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d01_s32_k(__transfersize(2) int32_t *,
                 int32x2x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d01_s8_k(__transfersize(2) int8_t *,
                 int8x8x2_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d01_u16_k(__transfersize(2) uint16_t *,
                 uint16x4x2_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d01_u32_k(__transfersize(2) uint32_t *,
                 uint32x2x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d01_u8_k(__transfersize(2) uint8_t *,
                 uint8x8x2_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d0_f32_k(__transfersize(1) float32_t *,
                 float32x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d0_p16_k(__transfersize(1) poly16_t *,
                 poly16x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d0_p8_k(__transfersize(1) poly8_t *,
                 poly8x8_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d0_s16_k(__transfersize(1) int16_t *,
                 int16x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d0_s32_k(__transfersize(1) int32_t *,
                 int32x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d0_s64_k(__transfersize(1) int64_t *,
                 int64x1_t,
                 __constrange(0,0) int, __encoding_t);
void __vst_rrk_d0_s8_k(__transfersize(1) int8_t *,
                 int8x8_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_d0_u16_k(__transfersize(1) uint16_t *,
                 uint16x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_d0_u32_k(__transfersize(1) uint32_t *,
                 uint32x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_d0_u64_k(__transfersize(1) uint64_t *,
                 uint64x1_t,
                 __constrange(0,0) int, __encoding_t);
void __vst_rrk_d0_u8_k(__transfersize(1) uint8_t *,
                 uint8x8_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q0123_f32_k(__transfersize(4) float32_t *,
                 float32x4x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q0123_p16_k(__transfersize(4) poly16_t *,
                 poly16x8x4_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q0123_s16_k(__transfersize(4) int16_t *,
                 int16x8x4_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q0123_s32_k(__transfersize(4) int32_t *,
                 int32x4x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q0123_u16_k(__transfersize(4) uint16_t *,
                 uint16x8x4_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q0123_u32_k(__transfersize(4) uint32_t *,
                 uint32x4x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q012_f32_k(__transfersize(3) float32_t *,
                 float32x4x3_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q012_p16_k(__transfersize(3) poly16_t *,
                 poly16x8x3_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q012_s16_k(__transfersize(3) int16_t *,
                 int16x8x3_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q012_s32_k(__transfersize(3) int32_t *,
                 int32x4x3_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q012_u16_k(__transfersize(3) uint16_t *,
                 uint16x8x3_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q012_u32_k(__transfersize(3) uint32_t *,
                 uint32x4x3_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q01_f32_k(__transfersize(2) float32_t *,
                 float32x4x2_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q01_p16_k(__transfersize(2) poly16_t *,
                 poly16x8x2_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q01_s16_k(__transfersize(2) int16_t *,
                 int16x8x2_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q01_s32_k(__transfersize(2) int32_t *,
                 int32x4x2_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q01_u16_k(__transfersize(2) uint16_t *,
                 uint16x8x2_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q01_u32_k(__transfersize(2) uint32_t *,
                 uint32x4x2_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q0_f32_k(__transfersize(1) float32_t *,
                 float32x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q0_p16_k(__transfersize(1) poly16_t *,
                 poly16x8_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q0_p8_k(__transfersize(1) poly8_t *,
                 poly8x16_t,
                 __constrange(0,15) int, __encoding_t);
void __vst_rrk_q0_s16_k(__transfersize(1) int16_t *,
                 int16x8_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q0_s32_k(__transfersize(1) int32_t *,
                 int32x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q0_s64_k(__transfersize(1) int64_t *,
                 int64x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_q0_s8_k(__transfersize(1) int8_t *,
                 int8x16_t,
                 __constrange(0,15) int, __encoding_t);
void __vst_rrk_q0_u16_k(__transfersize(1) uint16_t *,
                 uint16x8_t,
                 __constrange(0,7) int, __encoding_t);
void __vst_rrk_q0_u32_k(__transfersize(1) uint32_t *,
                 uint32x4_t,
                 __constrange(0,3) int, __encoding_t);
void __vst_rrk_q0_u64_k(__transfersize(1) uint64_t *,
                 uint64x2_t,
                 __constrange(0,1) int, __encoding_t);
void __vst_rrk_q0_u8_k(__transfersize(1) uint8_t *,
                 uint8x16_t,
                 __constrange(0,15) int, __encoding_t);
#ifdef __cplusplus
} /* extern "C" */
#endif /* def __cplusplus */
#else /* def __TARGET_FEATURE_NEON */
#error NEON intrinsics require NEON instruction set on target
/* The following prototypes are provided for documentation only */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vadd_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VADD.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vadd_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VADD.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vadd_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VADD.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vadd_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VADD.I64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vadd_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VADD.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vadd_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VADD.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vadd_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VADD.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vadd_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VADD.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vadd_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2); /* VADD.I64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vaddq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VADD.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vaddq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VADD.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vaddq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VADD.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vaddq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VADD.I64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vaddq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VADD.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vaddq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VADD.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vaddq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VADD.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vaddq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VADD.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vaddq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2); /* VADD.I64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vaddl_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VADDL.S8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vaddl_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VADDL.S16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vaddl_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VADDL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vaddl_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VADDL.U8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vaddl_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VADDL.U16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vaddl_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VADDL.U32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vaddw_s8(int16x8_t vec1,
                                                    int8x8_t vec2); /* VADDW.S8 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vaddw_s16(int32x4_t vec1,
                                                     int16x4_t vec2); /* VADDW.S16 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vaddw_s32(int64x2_t vec1,
                                                     int32x2_t vec2); /* VADDW.S32 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vaddw_u8(uint16x8_t vec1,
                                                     uint8x8_t vec2); /* VADDW.U8 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vaddw_u16(uint32x4_t vec1,
                                                      uint16x4_t vec2); /* VADDW.U16 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vaddw_u32(uint64x2_t vec1,
                                                      uint32x2_t vec2); /* VADDW.U32 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vhadd_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VHADD.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vhadd_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VHADD.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vhadd_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VHADD.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vhadd_u8(uint8x8_t vec1,
                                                    uint8x8_t vec2); /* VHADD.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vhadd_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VHADD.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vhadd_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VHADD.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vhaddq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VHADD.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vhaddq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VHADD.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vhaddq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VHADD.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vhaddq_u8(uint8x16_t vec1,
                                                      uint8x16_t vec2); /* VHADD.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vhaddq_u16(uint16x8_t vec1,
                                                       uint16x8_t vec2); /* VHADD.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vhaddq_u32(uint32x4_t vec1,
                                                       uint32x4_t vec2); /* VHADD.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrhadd_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VRHADD.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrhadd_s16(int16x4_t vec1,
                                                      int16x4_t vec2); /* VRHADD.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vrhadd_s32(int32x2_t vec1,
                                                      int32x2_t vec2); /* VRHADD.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrhadd_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VRHADD.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrhadd_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2); /* VRHADD.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrhadd_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2); /* VRHADD.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vrhaddq_s8(int8x16_t vec1,
                                                      int8x16_t vec2); /* VRHADD.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vrhaddq_s16(int16x8_t vec1,
                                                       int16x8_t vec2); /* VRHADD.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vrhaddq_s32(int32x4_t vec1,
                                                       int32x4_t vec2); /* VRHADD.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vrhaddq_u8(uint8x16_t vec1,
                                                       uint8x16_t vec2); /* VRHADD.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vrhaddq_u16(uint16x8_t vec1,
                                                        uint16x8_t vec2); /* VRHADD.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vrhaddq_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2); /* VRHADD.U32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqadd_s8(int8x8_t vec1,
                                            int8x8_t vec2); /* VQADD.S8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqadd_s16(int16x4_t vec1,
                                              int16x4_t vec2); /* VQADD.S16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqadd_s32(int32x2_t vec1,
                                              int32x2_t vec2); /* VQADD.S32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int64x1_t vqadd_s64(int64x1_t vec1,
                                              int64x1_t vec2); /* VQADD.S64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqadd_u8(uint8x8_t vec1,
                                             uint8x8_t vec2); /* VQADD.U8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqadd_u16(uint16x4_t vec1,
                                               uint16x4_t vec2); /* VQADD.U16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqadd_u32(uint32x2_t vec1,
                                               uint32x2_t vec2); /* VQADD.U32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint64x1_t vqadd_u64(uint64x1_t vec1,
                                               uint64x1_t vec2); /* VQADD.U64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int8x16_t vqaddq_s8(int8x16_t vec1,
                                              int8x16_t vec2); /* VQADD.S8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqaddq_s16(int16x8_t vec1,
                                               int16x8_t vec2); /* VQADD.S16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqaddq_s32(int32x4_t vec1,
                                               int32x4_t vec2); /* VQADD.S32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqaddq_s64(int64x2_t vec1,
                                               int64x2_t vec2); /* VQADD.S64 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint8x16_t vqaddq_u8(uint8x16_t vec1,
                                               uint8x16_t vec2); /* VQADD.U8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint16x8_t vqaddq_u16(uint16x8_t vec1,
                                                uint16x8_t vec2); /* VQADD.U16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint32x4_t vqaddq_u32(uint32x4_t vec1,
                                                uint32x4_t vec2); /* VQADD.U32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint64x2_t vqaddq_u64(uint64x2_t vec1,
                                                uint64x2_t vec2); /* VQADD.U64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vaddhn_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VADDHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vaddhn_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VADDHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vaddhn_s64(int64x2_t vec1,
                                                      int64x2_t vec2); /* VADDHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vaddhn_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VADDHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vaddhn_u32(uint32x4_t vec1,
                                                       uint32x4_t vec2); /* VADDHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vaddhn_u64(uint64x2_t vec1,
                                                       uint64x2_t vec2); /* VADDHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vraddhn_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VRADDHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vraddhn_s32(int32x4_t vec1,
                                                       int32x4_t vec2); /* VRADDHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vraddhn_s64(int64x2_t vec1,
                                                       int64x2_t vec2); /* VRADDHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vraddhn_u16(uint16x8_t vec1,
                                                       uint16x8_t vec2); /* VRADDHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vraddhn_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2); /* VRADDHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vraddhn_u64(uint64x2_t vec1,
                                                        uint64x2_t vec2); /* VRADDHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmul_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VMUL.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmul_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VMUL.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmul_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VMUL.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmul_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VMUL.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmul_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VMUL.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmul_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VMUL.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmul_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VMUL.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vmul_p8(poly8x8_t vec1,
                                                   poly8x8_t vec2); /* VMUL.P8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vmulq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VMUL.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmulq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VMUL.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmulq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VMUL.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmulq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VMUL.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vmulq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VMUL.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmulq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VMUL.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmulq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VMUL.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vmulq_p8(poly8x16_t vec1,
                                                     poly8x16_t vec2); /* VMUL.P8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmla_s8(int8x8_t vec1,
                                                  int8x8_t vec2,
                                                  int8x8_t vec3); /* VMLA.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmla_s16(int16x4_t vec1,
                                                    int16x4_t vec2,
                                                    int16x4_t vec3); /* VMLA.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmla_s32(int32x2_t vec1,
                                                    int32x2_t vec2,
                                                    int32x2_t vec3); /* VMLA.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmla_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2,
                                                   uint8x8_t vec3); /* VMLA.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmla_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2,
                                                     uint16x4_t vec3); /* VMLA.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmla_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2,
                                                     uint32x2_t vec3); /* VMLA.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vmlaq_s8(int8x16_t vec1,
                                                    int8x16_t vec2,
                                                    int8x16_t vec3); /* VMLA.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlaq_s16(int16x8_t vec1,
                                                     int16x8_t vec2,
                                                     int16x8_t vec3); /* VMLA.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlaq_s32(int32x4_t vec1,
                                                     int32x4_t vec2,
                                                     int32x4_t vec3); /* VMLA.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vmlaq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2,
                                                     uint8x16_t vec3); /* VMLA.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlaq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2,
                                                      uint16x8_t vec3); /* VMLA.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlaq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2,
                                                      uint32x4_t vec3); /* VMLA.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmla_f32(float32x2_t vec1,
                                                      float32x2_t vec2,
                                                      float32x2_t vec3); /* VMLA.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmlaq_f32(float32x4_t vec1,
                                                       float32x4_t vec2,
                                                       float32x4_t vec3); /* VMLA.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlal_s8(int16x8_t vec1,
                                                    int8x8_t vec2,
                                                    int8x8_t vec3); /* VMLAL.S8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlal_s16(int32x4_t vec1,
                                                     int16x4_t vec2,
                                                     int16x4_t vec3); /* VMLAL.S16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmlal_s32(int64x2_t vec1,
                                                     int32x2_t vec2,
                                                     int32x2_t vec3); /* VMLAL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlal_u8(uint16x8_t vec1,
                                                     uint8x8_t vec2,
                                                     uint8x8_t vec3); /* VMLAL.U8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlal_u16(uint32x4_t vec1,
                                                      uint16x4_t vec2,
                                                      uint16x4_t vec3); /* VMLAL.U16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmlal_u32(uint64x2_t vec1,
                                                      uint32x2_t vec2,
                                                      uint32x2_t vec3); /* VMLAL.U32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmls_s8(int8x8_t vec1,
                                                  int8x8_t vec2,
                                                  int8x8_t vec3); /* VMLS.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmls_s16(int16x4_t vec1,
                                                    int16x4_t vec2,
                                                    int16x4_t vec3); /* VMLS.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmls_s32(int32x2_t vec1,
                                                    int32x2_t vec2,
                                                    int32x2_t vec3); /* VMLS.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmls_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2,
                                                   uint8x8_t vec3); /* VMLS.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmls_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2,
                                                     uint16x4_t vec3); /* VMLS.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmls_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2,
                                                     uint32x2_t vec3); /* VMLS.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vmlsq_s8(int8x16_t vec1,
                                                    int8x16_t vec2,
                                                    int8x16_t vec3); /* VMLS.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlsq_s16(int16x8_t vec1,
                                                     int16x8_t vec2,
                                                     int16x8_t vec3); /* VMLS.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlsq_s32(int32x4_t vec1,
                                                     int32x4_t vec2,
                                                     int32x4_t vec3); /* VMLS.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vmlsq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2,
                                                     uint8x16_t vec3); /* VMLS.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlsq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2,
                                                      uint16x8_t vec3); /* VMLS.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlsq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2,
                                                      uint32x4_t vec3); /* VMLS.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmls_f32(float32x2_t vec1,
                                                      float32x2_t vec2,
                                                      float32x2_t vec3); /* VMLS.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmlsq_f32(float32x4_t vec1,
                                                       float32x4_t vec2,
                                                       float32x4_t vec3); /* VMLS.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlsl_s8(int16x8_t vec1,
                                                    int8x8_t vec2,
                                                    int8x8_t vec3); /* VMLSL.S8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlsl_s16(int32x4_t vec1,
                                                     int16x4_t vec2,
                                                     int16x4_t vec3); /* VMLSL.S16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmlsl_s32(int64x2_t vec1,
                                                     int32x2_t vec2,
                                                     int32x2_t vec3); /* VMLSL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlsl_u8(uint16x8_t vec1,
                                                     uint8x8_t vec2,
                                                     uint8x8_t vec3); /* VMLSL.U8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlsl_u16(uint32x4_t vec1,
                                                      uint16x4_t vec2,
                                                      uint16x4_t vec3); /* VMLSL.U16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmlsl_u32(uint64x2_t vec1,
                                                      uint32x2_t vec2,
                                                      uint32x2_t vec3); /* VMLSL.U32 q0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqdmulh_s16(int16x4_t vec1,
                                                int16x4_t vec2); /* VQDMULH.S16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqdmulh_s32(int32x2_t vec1,
                                                int32x2_t vec2); /* VQDMULH.S32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqdmulhq_s16(int16x8_t vec1,
                                                 int16x8_t vec2); /* VQDMULH.S16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmulhq_s32(int32x4_t vec1,
                                                 int32x4_t vec2); /* VQDMULH.S32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqrdmulh_s16(int16x4_t vec1,
                                                 int16x4_t vec2); /* VQRDMULH.S16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqrdmulh_s32(int32x2_t vec1,
                                                 int32x2_t vec2); /* VQRDMULH.S32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqrdmulhq_s16(int16x8_t vec1,
                                                  int16x8_t vec2); /* VQRDMULH.S16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqrdmulhq_s32(int32x4_t vec1,
                                                  int32x4_t vec2); /* VQRDMULH.S32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmlal_s16(int32x4_t vec1,
                                                int16x4_t vec2,
                                                int16x4_t vec3); /* VQDMLAL.S16 q0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqdmlal_s32(int64x2_t vec1,
                                                int32x2_t vec2,
                                                int32x2_t vec3); /* VQDMLAL.S32 q0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmlsl_s16(int32x4_t vec1,
                                                int16x4_t vec2,
                                                int16x4_t vec3); /* VQDMLSL.S16 q0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqdmlsl_s32(int64x2_t vec1,
                                                int32x2_t vec2,
                                                int32x2_t vec3); /* VQDMLSL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmull_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VMULL.S8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmull_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VMULL.S16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmull_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VMULL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmull_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VMULL.U8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmull_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VMULL.U16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmull_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VMULL.U32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vmull_p8(poly8x8_t vec1,
                                                     poly8x8_t vec2); /* VMULL.P8 q0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmull_s16(int16x4_t vec1,
                                                int16x4_t vec2); /* VQDMULL.S16 q0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqdmull_s32(int32x2_t vec1,
                                                int32x2_t vec2); /* VQDMULL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vsub_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VSUB.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vsub_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VSUB.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vsub_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VSUB.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vsub_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VSUB.I64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vsub_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VSUB.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vsub_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VSUB.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vsub_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VSUB.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vsub_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VSUB.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vsub_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2); /* VSUB.I64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vsubq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VSUB.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vsubq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VSUB.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vsubq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VSUB.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vsubq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VSUB.I64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vsubq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VSUB.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vsubq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VSUB.I8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vsubq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VSUB.I16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vsubq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VSUB.I32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vsubq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2); /* VSUB.I64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vsubl_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VSUBL.S8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vsubl_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VSUBL.S16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vsubl_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VSUBL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vsubl_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VSUBL.U8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vsubl_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VSUBL.U16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vsubl_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VSUBL.U32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vsubw_s8(int16x8_t vec1,
                                                    int8x8_t vec2); /* VSUBW.S8 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vsubw_s16(int32x4_t vec1,
                                                     int16x4_t vec2); /* VSUBW.S16 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vsubw_s32(int64x2_t vec1,
                                                     int32x2_t vec2); /* VSUBW.S32 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vsubw_u8(uint16x8_t vec1,
                                                     uint8x8_t vec2); /* VSUBW.U8 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vsubw_u16(uint32x4_t vec1,
                                                      uint16x4_t vec2); /* VSUBW.U16 q0,q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vsubw_u32(uint64x2_t vec1,
                                                      uint32x2_t vec2); /* VSUBW.U32 q0,q0,d0 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqsub_s8(int8x8_t vec1,
                                            int8x8_t vec2); /* VQSUB.S8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqsub_s16(int16x4_t vec1,
                                              int16x4_t vec2); /* VQSUB.S16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqsub_s32(int32x2_t vec1,
                                              int32x2_t vec2); /* VQSUB.S32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int64x1_t vqsub_s64(int64x1_t vec1,
                                              int64x1_t vec2); /* VQSUB.S64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqsub_u8(uint8x8_t vec1,
                                             uint8x8_t vec2); /* VQSUB.U8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqsub_u16(uint16x4_t vec1,
                                               uint16x4_t vec2); /* VQSUB.U16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqsub_u32(uint32x2_t vec1,
                                               uint32x2_t vec2); /* VQSUB.U32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint64x1_t vqsub_u64(uint64x1_t vec1,
                                               uint64x1_t vec2); /* VQSUB.U64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int8x16_t vqsubq_s8(int8x16_t vec1,
                                              int8x16_t vec2); /* VQSUB.S8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqsubq_s16(int16x8_t vec1,
                                               int16x8_t vec2); /* VQSUB.S16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqsubq_s32(int32x4_t vec1,
                                               int32x4_t vec2); /* VQSUB.S32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqsubq_s64(int64x2_t vec1,
                                               int64x2_t vec2); /* VQSUB.S64 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint8x16_t vqsubq_u8(uint8x16_t vec1,
                                               uint8x16_t vec2); /* VQSUB.U8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint16x8_t vqsubq_u16(uint16x8_t vec1,
                                                uint16x8_t vec2); /* VQSUB.U16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint32x4_t vqsubq_u32(uint32x4_t vec1,
                                                uint32x4_t vec2); /* VQSUB.U32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint64x2_t vqsubq_u64(uint64x2_t vec1,
                                                uint64x2_t vec2); /* VQSUB.U64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vhsub_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VHSUB.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vhsub_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VHSUB.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vhsub_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VHSUB.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vhsub_u8(uint8x8_t vec1,
                                                    uint8x8_t vec2); /* VHSUB.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vhsub_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VHSUB.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vhsub_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VHSUB.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vhsubq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VHSUB.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vhsubq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VHSUB.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vhsubq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VHSUB.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vhsubq_u8(uint8x16_t vec1,
                                                      uint8x16_t vec2); /* VHSUB.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vhsubq_u16(uint16x8_t vec1,
                                                       uint16x8_t vec2); /* VHSUB.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vhsubq_u32(uint32x4_t vec1,
                                                       uint32x4_t vec2); /* VHSUB.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vsubhn_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VSUBHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vsubhn_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VSUBHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vsubhn_s64(int64x2_t vec1,
                                                      int64x2_t vec2); /* VSUBHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vsubhn_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VSUBHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vsubhn_u32(uint32x4_t vec1,
                                                       uint32x4_t vec2); /* VSUBHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vsubhn_u64(uint64x2_t vec1,
                                                       uint64x2_t vec2); /* VSUBHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrsubhn_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VRSUBHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrsubhn_s32(int32x4_t vec1,
                                                       int32x4_t vec2); /* VRSUBHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vrsubhn_s64(int64x2_t vec1,
                                                       int64x2_t vec2); /* VRSUBHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrsubhn_u16(uint16x8_t vec1,
                                                       uint16x8_t vec2); /* VRSUBHN.I16 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrsubhn_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2); /* VRSUBHN.I32 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrsubhn_u64(uint64x2_t vec1,
                                                        uint64x2_t vec2); /* VRSUBHN.I64 d0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vceq_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VCEQ.I8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vceq_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VCEQ.I16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vceq_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VCEQ.I32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vceq_f32(float32x2_t vec1,
                                                     float32x2_t vec2); /* VCEQ.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vceq_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VCEQ.I8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vceq_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VCEQ.I16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vceq_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VCEQ.I32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vceq_p8(poly8x8_t vec1,
                                                   poly8x8_t vec2); /* VCEQ.I8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vceqq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VCEQ.I8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vceqq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VCEQ.I16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vceqq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VCEQ.I32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vceqq_f32(float32x4_t vec1,
                                                      float32x4_t vec2); /* VCEQ.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vceqq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VCEQ.I8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vceqq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VCEQ.I16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vceqq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VCEQ.I32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vceqq_p8(poly8x16_t vec1,
                                                     poly8x16_t vec2); /* VCEQ.I8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcge_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VCGE.S8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcge_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VCGE.S16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcge_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VCGE.S32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcge_f32(float32x2_t vec1,
                                                     float32x2_t vec2); /* VCGE.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcge_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VCGE.U8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcge_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VCGE.U16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcge_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VCGE.U32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcgeq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VCGE.S8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcgeq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VCGE.S16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgeq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VCGE.S32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgeq_f32(float32x4_t vec1,
                                                      float32x4_t vec2); /* VCGE.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcgeq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VCGE.U8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcgeq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VCGE.U16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgeq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VCGE.U32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcle_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VCGE.S8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcle_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VCGE.S16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcle_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VCGE.S32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcle_f32(float32x2_t vec1,
                                                     float32x2_t vec2); /* VCGE.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcle_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VCGE.U8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcle_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VCGE.U16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcle_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VCGE.U32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcleq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VCGE.S8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcleq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VCGE.S16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcleq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VCGE.S32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcleq_f32(float32x4_t vec1,
                                                      float32x4_t vec2); /* VCGE.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcleq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VCGE.U8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcleq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VCGE.U16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcleq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VCGE.U32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcgt_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VCGT.S8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcgt_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VCGT.S16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcgt_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VCGT.S32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcgt_f32(float32x2_t vec1,
                                                     float32x2_t vec2); /* VCGT.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcgt_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VCGT.U8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcgt_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VCGT.U16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcgt_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VCGT.U32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcgtq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VCGT.S8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcgtq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VCGT.S16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgtq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VCGT.S32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgtq_f32(float32x4_t vec1,
                                                      float32x4_t vec2); /* VCGT.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcgtq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VCGT.U8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcgtq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VCGT.U16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgtq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VCGT.U32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vclt_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VCGT.S8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vclt_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VCGT.S16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vclt_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VCGT.S32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vclt_f32(float32x2_t vec1,
                                                     float32x2_t vec2); /* VCGT.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vclt_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VCGT.U8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vclt_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VCGT.U16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vclt_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VCGT.U32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcltq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VCGT.S8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcltq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VCGT.S16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcltq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VCGT.S32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcltq_f32(float32x4_t vec1,
                                                      float32x4_t vec2); /* VCGT.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcltq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VCGT.U8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcltq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VCGT.U16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcltq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VCGT.U32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcage_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VACGE.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcageq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VACGE.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcale_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VACGE.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcaleq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VACGE.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcagt_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VACGT.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcagtq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VACGT.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcalt_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VACGT.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcaltq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VACGT.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtst_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VTST.8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vtst_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VTST.16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vtst_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VTST.32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtst_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VTST.8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vtst_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VTST.16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vtst_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VTST.32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtst_p8(poly8x8_t vec1,
                                                   poly8x8_t vec2); /* VTST.8 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vtst_p16(poly16x4_t vec1,
                                                     poly16x4_t vec2); /* VTST.16 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vtstq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VTST.8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vtstq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VTST.16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vtstq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VTST.32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vtstq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VTST.8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vtstq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VTST.16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vtstq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VTST.32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vtstq_p8(poly8x16_t vec1,
                                                     poly8x16_t vec2); /* VTST.8 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vtstq_p16(poly16x8_t vec1,
                                                      poly16x8_t vec2); /* VTST.16 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vceqz_s8(int8x8_t vec); /* VCEQ.I8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vceqz_s16(int16x4_t vec); /* VCEQ.I16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vceqz_s32(int32x2_t vec); /* VCEQ.I32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vceqz_u8(uint8x8_t vec); /* VCEQ.I8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vceqz_u16(uint16x4_t vec); /* VCEQ.I16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vceqz_u32(uint32x2_t vec); /* VCEQ.I32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vceqz_f32(float32x2_t vec); /* VCEQ.F32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vceqz_p8(poly8x8_t vec); /* VCEQ.I8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vceqzq_s8(int8x16_t vec); /* VCEQ.I8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vceqzq_s16(int16x8_t vec); /* VCEQ.I16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vceqzq_s32(int32x4_t vec); /* VCEQ.I32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vceqzq_u8(uint8x16_t vec); /* VCEQ.I8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vceqzq_u16(uint16x8_t vec); /* VCEQ.I16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vceqzq_u32(uint32x4_t vec); /* VCEQ.I32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vceqzq_f32(float32x4_t vec); /* VCEQ.F32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vceqzq_p8(poly8x16_t vec); /* VCEQ.I8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcgtz_s8(int8x8_t vec); /* VCGT.S8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcgtz_s16(int16x4_t vec); /* VCGT.S16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcgtz_s32(int32x2_t vec); /* VCGT.S32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcgtz_f32(float32x2_t vec); /* VCGT.F32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcgtzq_s8(int8x16_t vec); /* VCGT.S8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcgtzq_s16(int16x8_t vec); /* VCGT.S16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgtzq_s32(int32x4_t vec); /* VCGT.S32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgtzq_f32(float32x4_t vec); /* VCGT.F32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcgez_s8(int8x8_t vec); /* VCGE.S8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcgez_s16(int16x4_t vec); /* VCGE.S16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcgez_s32(int32x2_t vec); /* VCGE.S32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcgez_f32(float32x2_t vec); /* VCGE.F32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcgezq_s8(int8x16_t vec); /* VCGE.S8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcgezq_s16(int16x8_t vec); /* VCGE.S16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgezq_s32(int32x4_t vec); /* VCGE.S32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcgezq_f32(float32x4_t vec); /* VCGE.F32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vclez_s8(int8x8_t vec); /* VCLE.S8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vclez_s16(int16x4_t vec); /* VCLE.S16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vclez_s32(int32x2_t vec); /* VCLE.S32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vclez_f32(float32x2_t vec); /* VCLE.F32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vclezq_s8(int8x16_t vec); /* VCLE.S8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vclezq_s16(int16x8_t vec); /* VCLE.S16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vclezq_s32(int32x4_t vec); /* VCLE.S32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vclezq_f32(float32x4_t vec); /* VCLE.F32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcltz_s8(int8x8_t vec); /* VCLT.S8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcltz_s16(int16x4_t vec); /* VCLT.S16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcltz_s32(int32x2_t vec); /* VCLT.S32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcltz_f32(float32x2_t vec); /* VCLT.F32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcltzq_s8(int8x16_t vec); /* VCLT.S8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcltzq_s16(int16x8_t vec); /* VCLT.S16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcltzq_s32(int32x4_t vec); /* VCLT.S32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcltzq_f32(float32x4_t vec); /* VCLT.F32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vabd_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VABD.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vabd_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VABD.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vabd_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VABD.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vabd_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VABD.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vabd_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VABD.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vabd_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VABD.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vabd_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VABD.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vabdq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VABD.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vabdq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VABD.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vabdq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VABD.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vabdq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VABD.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vabdq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VABD.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vabdq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VABD.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vabdq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VABD.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vabdl_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VABDL.S8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vabdl_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VABDL.S16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vabdl_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VABDL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vabdl_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VABDL.U8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vabdl_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VABDL.U16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vabdl_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VABDL.U32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vaba_s8(int8x8_t vec1,
                                                  int8x8_t vec2,
                                                  int8x8_t vec3); /* VABA.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vaba_s16(int16x4_t vec1,
                                                    int16x4_t vec2,
                                                    int16x4_t vec3); /* VABA.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vaba_s32(int32x2_t vec1,
                                                    int32x2_t vec2,
                                                    int32x2_t vec3); /* VABA.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vaba_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2,
                                                   uint8x8_t vec3); /* VABA.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vaba_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2,
                                                     uint16x4_t vec3); /* VABA.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vaba_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2,
                                                     uint32x2_t vec3); /* VABA.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vabaq_s8(int8x16_t vec1,
                                                    int8x16_t vec2,
                                                    int8x16_t vec3); /* VABA.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vabaq_s16(int16x8_t vec1,
                                                     int16x8_t vec2,
                                                     int16x8_t vec3); /* VABA.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vabaq_s32(int32x4_t vec1,
                                                     int32x4_t vec2,
                                                     int32x4_t vec3); /* VABA.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vabaq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2,
                                                     uint8x16_t vec3); /* VABA.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vabaq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2,
                                                      uint16x8_t vec3); /* VABA.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vabaq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2,
                                                      uint32x4_t vec3); /* VABA.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vabal_s8(int16x8_t vec1,
                                                    int8x8_t vec2,
                                                    int8x8_t vec3); /* VABAL.S8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vabal_s16(int32x4_t vec1,
                                                     int16x4_t vec2,
                                                     int16x4_t vec3); /* VABAL.S16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vabal_s32(int64x2_t vec1,
                                                     int32x2_t vec2,
                                                     int32x2_t vec3); /* VABAL.S32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vabal_u8(uint16x8_t vec1,
                                                     uint8x8_t vec2,
                                                     uint8x8_t vec3); /* VABAL.U8 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vabal_u16(uint32x4_t vec1,
                                                      uint16x4_t vec2,
                                                      uint16x4_t vec3); /* VABAL.U16 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vabal_u32(uint64x2_t vec1,
                                                      uint32x2_t vec2,
                                                      uint32x2_t vec3); /* VABAL.U32 q0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmax_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VMAX.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmax_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VMAX.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmax_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VMAX.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmax_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VMAX.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmax_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VMAX.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmax_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VMAX.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmax_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VMAX.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vmaxq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VMAX.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmaxq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VMAX.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmaxq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VMAX.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vmaxq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VMAX.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmaxq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VMAX.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmaxq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VMAX.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmaxq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VMAX.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmin_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VMIN.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmin_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VMIN.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmin_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VMIN.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmin_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VMIN.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmin_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VMIN.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmin_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VMIN.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmin_f32(float32x2_t vec1,
                                                      float32x2_t vec2); /* VMIN.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vminq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VMIN.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vminq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VMIN.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vminq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VMIN.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vminq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VMIN.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vminq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VMIN.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vminq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VMIN.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vminq_f32(float32x4_t vec1,
                                                       float32x4_t vec2); /* VMIN.F32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vpadd_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VPADD.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vpadd_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VPADD.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vpadd_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VPADD.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vpadd_u8(uint8x8_t vec1,
                                                    uint8x8_t vec2); /* VPADD.I8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vpadd_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VPADD.I16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vpadd_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VPADD.I32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vpadd_f32(float32x2_t vec1,
                                                       float32x2_t vec2); /* VPADD.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vpaddl_s8(int8x8_t vec); /* VPADDL.S8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vpaddl_s16(int16x4_t vec); /* VPADDL.S16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vpaddl_s32(int32x2_t vec); /* VPADDL.S32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vpaddl_u8(uint8x8_t vec); /* VPADDL.U8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vpaddl_u16(uint16x4_t vec); /* VPADDL.U16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vpaddl_u32(uint32x2_t vec); /* VPADDL.U32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vpaddlq_s8(int8x16_t vec); /* VPADDL.S8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vpaddlq_s16(int16x8_t vec); /* VPADDL.S16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vpaddlq_s32(int32x4_t vec); /* VPADDL.S32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vpaddlq_u8(uint8x16_t vec); /* VPADDL.U8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vpaddlq_u16(uint16x8_t vec); /* VPADDL.U16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vpaddlq_u32(uint32x4_t vec); /* VPADDL.U32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vpadal_s8(int16x4_t acc,
                                                     int8x8_t vec); /* VPADAL.S8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vpadal_s16(int32x2_t acc,
                                                      int16x4_t vec); /* VPADAL.S16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vpadal_s32(int64x1_t acc,
                                                      int32x2_t vec); /* VPADAL.S32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vpadal_u8(uint16x4_t acc,
                                                      uint8x8_t vec); /* VPADAL.U8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vpadal_u16(uint32x2_t acc,
                                                       uint16x4_t vec); /* VPADAL.U16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vpadal_u32(uint64x1_t acc,
                                                       uint32x2_t vec); /* VPADAL.U32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vpadalq_s8(int16x8_t acc,
                                                      int8x16_t vec); /* VPADAL.S8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vpadalq_s16(int32x4_t acc,
                                                       int16x8_t vec); /* VPADAL.S16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vpadalq_s32(int64x2_t acc,
                                                       int32x4_t vec); /* VPADAL.S32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vpadalq_u8(uint16x8_t acc,
                                                       uint8x16_t vec); /* VPADAL.U8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vpadalq_u16(uint32x4_t acc,
                                                        uint16x8_t vec); /* VPADAL.U16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vpadalq_u32(uint64x2_t acc,
                                                        uint32x4_t vec); /* VPADAL.U32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vpmax_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VPMAX.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vpmax_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VPMAX.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vpmax_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VPMAX.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vpmax_u8(uint8x8_t vec1,
                                                    uint8x8_t vec2); /* VPMAX.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vpmax_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VPMAX.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vpmax_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VPMAX.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vpmax_f32(float32x2_t vec1,
                                                       float32x2_t vec2); /* VPMAX.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vpmin_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VPMIN.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vpmin_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VPMIN.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vpmin_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VPMIN.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vpmin_u8(uint8x8_t vec1,
                                                    uint8x8_t vec2); /* VPMIN.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vpmin_u16(uint16x4_t vec1,
                                                      uint16x4_t vec2); /* VPMIN.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vpmin_u32(uint32x2_t vec1,
                                                      uint32x2_t vec2); /* VPMIN.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vpmin_f32(float32x2_t vec1,
                                                       float32x2_t vec2); /* VPMIN.F32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vrecps_f32(float32x2_t vec1,
                                                        float32x2_t vec2); /* VRECPS.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vrecpsq_f32(float32x4_t vec1,
                                                         float32x4_t vec2); /* VRECPS.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vrsqrts_f32(float32x2_t vec1,
                                                         float32x2_t vec2); /* VRSQRTS.F32 d0, d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vrsqrtsq_f32(float32x4_t vec1,
                                                          float32x4_t vec2); /* VRSQRTS.F32 q0, q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vshl_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VSHL.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vshl_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VSHL.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vshl_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VSHL.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vshl_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VSHL.S64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vshl_u8(uint8x8_t vec1,
                                                   int8x8_t vec2); /* VSHL.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vshl_u16(uint16x4_t vec1,
                                                     int16x4_t vec2); /* VSHL.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vshl_u32(uint32x2_t vec1,
                                                     int32x2_t vec2); /* VSHL.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vshl_u64(uint64x1_t vec1,
                                                     int64x1_t vec2); /* VSHL.U64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vshlq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VSHL.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vshlq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VSHL.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vshlq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VSHL.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vshlq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VSHL.S64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vshlq_u8(uint8x16_t vec1,
                                                     int8x16_t vec2); /* VSHL.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vshlq_u16(uint16x8_t vec1,
                                                      int16x8_t vec2); /* VSHL.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vshlq_u32(uint32x4_t vec1,
                                                      int32x4_t vec2); /* VSHL.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vshlq_u64(uint64x2_t vec1,
                                                      int64x2_t vec2); /* VSHL.U64 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqshl_s8(int8x8_t vec1,
                                            int8x8_t vec2); /* VQSHL.S8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqshl_s16(int16x4_t vec1,
                                              int16x4_t vec2); /* VQSHL.S16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqshl_s32(int32x2_t vec1,
                                              int32x2_t vec2); /* VQSHL.S32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int64x1_t vqshl_s64(int64x1_t vec1,
                                              int64x1_t vec2); /* VQSHL.S64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqshl_u8(uint8x8_t vec1,
                                             int8x8_t vec2); /* VQSHL.U8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqshl_u16(uint16x4_t vec1,
                                               int16x4_t vec2); /* VQSHL.U16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqshl_u32(uint32x2_t vec1,
                                               int32x2_t vec2); /* VQSHL.U32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint64x1_t vqshl_u64(uint64x1_t vec1,
                                               int64x1_t vec2); /* VQSHL.U64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int8x16_t vqshlq_s8(int8x16_t vec1,
                                              int8x16_t vec2); /* VQSHL.S8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqshlq_s16(int16x8_t vec1,
                                               int16x8_t vec2); /* VQSHL.S16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqshlq_s32(int32x4_t vec1,
                                               int32x4_t vec2); /* VQSHL.S32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqshlq_s64(int64x2_t vec1,
                                               int64x2_t vec2); /* VQSHL.S64 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint8x16_t vqshlq_u8(uint8x16_t vec1,
                                               int8x16_t vec2); /* VQSHL.U8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint16x8_t vqshlq_u16(uint16x8_t vec1,
                                                int16x8_t vec2); /* VQSHL.U16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint32x4_t vqshlq_u32(uint32x4_t vec1,
                                                int32x4_t vec2); /* VQSHL.U32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint64x2_t vqshlq_u64(uint64x2_t vec1,
                                                int64x2_t vec2); /* VQSHL.U64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrshl_s8(int8x8_t vec1,
                                                   int8x8_t vec2); /* VRSHL.S8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrshl_s16(int16x4_t vec1,
                                                     int16x4_t vec2); /* VRSHL.S16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vrshl_s32(int32x2_t vec1,
                                                     int32x2_t vec2); /* VRSHL.S32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vrshl_s64(int64x1_t vec1,
                                                     int64x1_t vec2); /* VRSHL.S64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrshl_u8(uint8x8_t vec1,
                                                    int8x8_t vec2); /* VRSHL.U8 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrshl_u16(uint16x4_t vec1,
                                                      int16x4_t vec2); /* VRSHL.U16 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrshl_u32(uint32x2_t vec1,
                                                      int32x2_t vec2); /* VRSHL.U32 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vrshl_u64(uint64x1_t vec1,
                                                      int64x1_t vec2); /* VRSHL.U64 d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vrshlq_s8(int8x16_t vec1,
                                                     int8x16_t vec2); /* VRSHL.S8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vrshlq_s16(int16x8_t vec1,
                                                      int16x8_t vec2); /* VRSHL.S16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vrshlq_s32(int32x4_t vec1,
                                                      int32x4_t vec2); /* VRSHL.S32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vrshlq_s64(int64x2_t vec1,
                                                      int64x2_t vec2); /* VRSHL.S64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vrshlq_u8(uint8x16_t vec1,
                                                      int8x16_t vec2); /* VRSHL.U8 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vrshlq_u16(uint16x8_t vec1,
                                                       int16x8_t vec2); /* VRSHL.U16 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vrshlq_u32(uint32x4_t vec1,
                                                       int32x4_t vec2); /* VRSHL.U32 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vrshlq_u64(uint64x2_t vec1,
                                                       int64x2_t vec2); /* VRSHL.U64 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqrshl_s8(int8x8_t vec1,
                                             int8x8_t vec2); /* VQRSHL.S8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqrshl_s16(int16x4_t vec1,
                                               int16x4_t vec2); /* VQRSHL.S16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqrshl_s32(int32x2_t vec1,
                                               int32x2_t vec2); /* VQRSHL.S32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int64x1_t vqrshl_s64(int64x1_t vec1,
                                               int64x1_t vec2); /* VQRSHL.S64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqrshl_u8(uint8x8_t vec1,
                                              int8x8_t vec2); /* VQRSHL.U8 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqrshl_u16(uint16x4_t vec1,
                                                int16x4_t vec2); /* VQRSHL.U16 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqrshl_u32(uint32x2_t vec1,
                                                int32x2_t vec2); /* VQRSHL.U32 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS uint64x1_t vqrshl_u64(uint64x1_t vec1,
                                                int64x1_t vec2); /* VQRSHL.U64 d0,d0,d0 */
__EXTERNC __VALUE_IN_REGS int8x16_t vqrshlq_s8(int8x16_t vec1,
                                               int8x16_t vec2); /* VQRSHL.S8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqrshlq_s16(int16x8_t vec1,
                                                int16x8_t vec2); /* VQRSHL.S16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqrshlq_s32(int32x4_t vec1,
                                                int32x4_t vec2); /* VQRSHL.S32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqrshlq_s64(int64x2_t vec1,
                                                int64x2_t vec2); /* VQRSHL.S64 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint8x16_t vqrshlq_u8(uint8x16_t vec1,
                                                int8x16_t vec2); /* VQRSHL.U8 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint16x8_t vqrshlq_u16(uint16x8_t vec1,
                                                 int16x8_t vec2); /* VQRSHL.U16 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint32x4_t vqrshlq_u32(uint32x4_t vec1,
                                                 int32x4_t vec2); /* VQRSHL.U32 q0,q0,q0 */
__EXTERNC __VALUE_IN_REGS uint64x2_t vqrshlq_u64(uint64x2_t vec1,
                                                 int64x2_t vec2); /* VQRSHL.U64 q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vshr_n_s8(int8x8_t vec1,
                                                    __constrange(1,8) int val2); /* VSHR.S8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vshr_n_s16(int16x4_t vec1,
                                                      __constrange(1,16) int val2); /* VSHR.S16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vshr_n_s32(int32x2_t vec1,
                                                      __constrange(1,32) int val2); /* VSHR.S32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vshr_n_s64(int64x1_t vec1,
                                                      __constrange(1,64) int val2); /* VSHR.S64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vshr_n_u8(uint8x8_t vec1,
                                                     __constrange(1,8) int val2); /* VSHR.U8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vshr_n_u16(uint16x4_t vec1,
                                                       __constrange(1,16) int val2); /* VSHR.U16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vshr_n_u32(uint32x2_t vec1,
                                                       __constrange(1,32) int val2); /* VSHR.U32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vshr_n_u64(uint64x1_t vec1,
                                                       __constrange(1,64) int val2); /* VSHR.U64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vshrq_n_s8(int8x16_t vec1,
                                                      __constrange(1,8) int val2); /* VSHR.S8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vshrq_n_s16(int16x8_t vec1,
                                                       __constrange(1,16) int val2); /* VSHR.S16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vshrq_n_s32(int32x4_t vec1,
                                                       __constrange(1,32) int val2); /* VSHR.S32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vshrq_n_s64(int64x2_t vec1,
                                                       __constrange(1,64) int val2); /* VSHR.S64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vshrq_n_u8(uint8x16_t vec1,
                                                       __constrange(1,8) int val2); /* VSHR.U8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vshrq_n_u16(uint16x8_t vec1,
                                                        __constrange(1,16) int val2); /* VSHR.U16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vshrq_n_u32(uint32x4_t vec1,
                                                        __constrange(1,32) int val2); /* VSHR.U32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vshrq_n_u64(uint64x2_t vec1,
                                                        __constrange(1,64) int val2); /* VSHR.U64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vshl_n_s8(int8x8_t vec1,
                                                    __constrange(0,7) int val2); /* VSHL.I8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vshl_n_s16(int16x4_t vec1,
                                                      __constrange(0,15) int val2); /* VSHL.I16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vshl_n_s32(int32x2_t vec1,
                                                      __constrange(0,31) int val2); /* VSHL.I32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vshl_n_s64(int64x1_t vec1,
                                                      __constrange(0,63) int val2); /* VSHL.I64 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vshl_n_u8(uint8x8_t vec1,
                                                     __constrange(0,7) int val2); /* VSHL.I8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vshl_n_u16(uint16x4_t vec1,
                                                       __constrange(0,15) int val2); /* VSHL.I16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vshl_n_u32(uint32x2_t vec1,
                                                       __constrange(0,31) int val2); /* VSHL.I32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vshl_n_u64(uint64x1_t vec1,
                                                       __constrange(0,63) int val2); /* VSHL.I64 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vshlq_n_s8(int8x16_t vec1,
                                                      __constrange(0,7) int val2); /* VSHL.I8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vshlq_n_s16(int16x8_t vec1,
                                                       __constrange(0,15) int val2); /* VSHL.I16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vshlq_n_s32(int32x4_t vec1,
                                                       __constrange(0,31) int val2); /* VSHL.I32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vshlq_n_s64(int64x2_t vec1,
                                                       __constrange(0,63) int val2); /* VSHL.I64 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vshlq_n_u8(uint8x16_t vec1,
                                                       __constrange(0,7) int val2); /* VSHL.I8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vshlq_n_u16(uint16x8_t vec1,
                                                        __constrange(0,15) int val2); /* VSHL.I16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vshlq_n_u32(uint32x4_t vec1,
                                                        __constrange(0,31) int val2); /* VSHL.I32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vshlq_n_u64(uint64x2_t vec1,
                                                        __constrange(0,63) int val2); /* VSHL.I64 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrshr_n_s8(int8x8_t vec1,
                                                     __constrange(1,8) int val2); /* VRSHR.S8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrshr_n_s16(int16x4_t vec1,
                                                       __constrange(1,16) int val2); /* VRSHR.S16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vrshr_n_s32(int32x2_t vec1,
                                                       __constrange(1,32) int val2); /* VRSHR.S32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vrshr_n_s64(int64x1_t vec1,
                                                       __constrange(1,64) int val2); /* VRSHR.S64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrshr_n_u8(uint8x8_t vec1,
                                                      __constrange(1,8) int val2); /* VRSHR.U8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrshr_n_u16(uint16x4_t vec1,
                                                        __constrange(1,16) int val2); /* VRSHR.U16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrshr_n_u32(uint32x2_t vec1,
                                                        __constrange(1,32) int val2); /* VRSHR.U32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vrshr_n_u64(uint64x1_t vec1,
                                                        __constrange(1,64) int val2); /* VRSHR.U64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vrshrq_n_s8(int8x16_t vec1,
                                                       __constrange(1,8) int val2); /* VRSHR.S8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vrshrq_n_s16(int16x8_t vec1,
                                                        __constrange(1,16) int val2); /* VRSHR.S16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vrshrq_n_s32(int32x4_t vec1,
                                                        __constrange(1,32) int val2); /* VRSHR.S32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vrshrq_n_s64(int64x2_t vec1,
                                                        __constrange(1,64) int val2); /* VRSHR.S64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vrshrq_n_u8(uint8x16_t vec1,
                                                        __constrange(1,8) int val2); /* VRSHR.U8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vrshrq_n_u16(uint16x8_t vec1,
                                                         __constrange(1,16) int val2); /* VRSHR.U16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vrshrq_n_u32(uint32x4_t vec1,
                                                         __constrange(1,32) int val2); /* VRSHR.U32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vrshrq_n_u64(uint64x2_t vec1,
                                                         __constrange(1,64) int val2); /* VRSHR.U64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vsra_n_s8(int8x8_t vec1,
                                                    int8x8_t vec2,
                                                    __constrange(1,8) int val3); /* VSRA.S8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vsra_n_s16(int16x4_t vec1,
                                                      int16x4_t vec2,
                                                      __constrange(1,16) int val3); /* VSRA.S16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vsra_n_s32(int32x2_t vec1,
                                                      int32x2_t vec2,
                                                      __constrange(1,32) int val3); /* VSRA.S32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vsra_n_s64(int64x1_t vec1,
                                                      int64x1_t vec2,
                                                      __constrange(1,64) int val3); /* VSRA.S64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vsra_n_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2,
                                                     __constrange(1,8) int val3); /* VSRA.U8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vsra_n_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2,
                                                       __constrange(1,16) int val3); /* VSRA.U16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vsra_n_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2,
                                                       __constrange(1,32) int val3); /* VSRA.U32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vsra_n_u64(uint64x1_t vec1,
                                                       uint64x1_t vec2,
                                                       __constrange(1,64) int val3); /* VSRA.U64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vsraq_n_s8(int8x16_t vec1,
                                                      int8x16_t vec2,
                                                      __constrange(1,8) int val3); /* VSRA.S8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vsraq_n_s16(int16x8_t vec1,
                                                       int16x8_t vec2,
                                                       __constrange(1,16) int val3); /* VSRA.S16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vsraq_n_s32(int32x4_t vec1,
                                                       int32x4_t vec2,
                                                       __constrange(1,32) int val3); /* VSRA.S32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vsraq_n_s64(int64x2_t vec1,
                                                       int64x2_t vec2,
                                                       __constrange(1,64) int val3); /* VSRA.S64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vsraq_n_u8(uint8x16_t vec1,
                                                       uint8x16_t vec2,
                                                       __constrange(1,8) int val3); /* VSRA.U8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vsraq_n_u16(uint16x8_t vec1,
                                                        uint16x8_t vec2,
                                                        __constrange(1,16) int val3); /* VSRA.U16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vsraq_n_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2,
                                                        __constrange(1,32) int val3); /* VSRA.U32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vsraq_n_u64(uint64x2_t vec1,
                                                        uint64x2_t vec2,
                                                        __constrange(1,64) int val3); /* VSRA.U64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrsra_n_s8(int8x8_t vec1,
                                                     int8x8_t vec2,
                                                     __constrange(1,8) int val3); /* VRSRA.S8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrsra_n_s16(int16x4_t vec1,
                                                       int16x4_t vec2,
                                                       __constrange(1,16) int val3); /* VRSRA.S16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vrsra_n_s32(int32x2_t vec1,
                                                       int32x2_t vec2,
                                                       __constrange(1,32) int val3); /* VRSRA.S32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vrsra_n_s64(int64x1_t vec1,
                                                       int64x1_t vec2,
                                                       __constrange(1,64) int val3); /* VRSRA.S64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrsra_n_u8(uint8x8_t vec1,
                                                      uint8x8_t vec2,
                                                      __constrange(1,8) int val3); /* VRSRA.U8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrsra_n_u16(uint16x4_t vec1,
                                                        uint16x4_t vec2,
                                                        __constrange(1,16) int val3); /* VRSRA.U16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrsra_n_u32(uint32x2_t vec1,
                                                        uint32x2_t vec2,
                                                        __constrange(1,32) int val3); /* VRSRA.U32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vrsra_n_u64(uint64x1_t vec1,
                                                        uint64x1_t vec2,
                                                        __constrange(1,64) int val3); /* VRSRA.U64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vrsraq_n_s8(int8x16_t vec1,
                                                       int8x16_t vec2,
                                                       __constrange(1,8) int val3); /* VRSRA.S8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vrsraq_n_s16(int16x8_t vec1,
                                                        int16x8_t vec2,
                                                        __constrange(1,16) int val3); /* VRSRA.S16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vrsraq_n_s32(int32x4_t vec1,
                                                        int32x4_t vec2,
                                                        __constrange(1,32) int val3); /* VRSRA.S32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vrsraq_n_s64(int64x2_t vec1,
                                                        int64x2_t vec2,
                                                        __constrange(1,64) int val3); /* VRSRA.S64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vrsraq_n_u8(uint8x16_t vec1,
                                                        uint8x16_t vec2,
                                                        __constrange(1,8) int val3); /* VRSRA.U8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vrsraq_n_u16(uint16x8_t vec1,
                                                         uint16x8_t vec2,
                                                         __constrange(1,16) int val3); /* VRSRA.U16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vrsraq_n_u32(uint32x4_t vec1,
                                                         uint32x4_t vec2,
                                                         __constrange(1,32) int val3); /* VRSRA.U32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vrsraq_n_u64(uint64x2_t vec1,
                                                         uint64x2_t vec2,
                                                         __constrange(1,64) int val3); /* VRSRA.U64 q0,q0,#64 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqshl_n_s8(int8x8_t vec1,
                                              __constrange(0,7) int val2); /* VQSHL.S8 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqshl_n_s16(int16x4_t vec1,
                                                __constrange(0,15) int val2); /* VQSHL.S16 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqshl_n_s32(int32x2_t vec1,
                                                __constrange(0,31) int val2); /* VQSHL.S32 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS int64x1_t vqshl_n_s64(int64x1_t vec1,
                                                __constrange(0,63) int val2); /* VQSHL.S64 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqshl_n_u8(uint8x8_t vec1,
                                               __constrange(0,7) int val2); /* VQSHL.U8 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqshl_n_u16(uint16x4_t vec1,
                                                 __constrange(0,15) int val2); /* VQSHL.U16 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqshl_n_u32(uint32x2_t vec1,
                                                 __constrange(0,31) int val2); /* VQSHL.U32 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint64x1_t vqshl_n_u64(uint64x1_t vec1,
                                                 __constrange(0,63) int val2); /* VQSHL.U64 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS int8x16_t vqshlq_n_s8(int8x16_t vec1,
                                                __constrange(0,7) int val2); /* VQSHL.S8 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqshlq_n_s16(int16x8_t vec1,
                                                 __constrange(0,15) int val2); /* VQSHL.S16 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqshlq_n_s32(int32x4_t vec1,
                                                 __constrange(0,31) int val2); /* VQSHL.S32 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS int64x2_t vqshlq_n_s64(int64x2_t vec1,
                                                 __constrange(0,63) int val2); /* VQSHL.S64 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint8x16_t vqshlq_n_u8(uint8x16_t vec1,
                                                 __constrange(0,7) int val2); /* VQSHL.U8 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint16x8_t vqshlq_n_u16(uint16x8_t vec1,
                                                  __constrange(0,15) int val2); /* VQSHL.U16 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint32x4_t vqshlq_n_u32(uint32x4_t vec1,
                                                  __constrange(0,31) int val2); /* VQSHL.U32 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint64x2_t vqshlq_n_u64(uint64x2_t vec1,
                                                  __constrange(0,63) int val2); /* VQSHL.U64 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqshlu_n_s8(int8x8_t vec1,
                                                __constrange(0,7) int val2); /* VQSHLU.S8 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqshlu_n_s16(int16x4_t vec1,
                                                  __constrange(0,15) int val2); /* VQSHLU.S16 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqshlu_n_s32(int32x2_t vec1,
                                                  __constrange(0,31) int val2); /* VQSHLU.S32 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint64x1_t vqshlu_n_s64(int64x1_t vec1,
                                                  __constrange(0,63) int val2); /* VQSHLU.S64 d0,d0,#0 */
__EXTERNC __VALUE_IN_REGS uint8x16_t vqshluq_n_s8(int8x16_t vec1,
                                                  __constrange(0,7) int val2); /* VQSHLU.S8 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint16x8_t vqshluq_n_s16(int16x8_t vec1,
                                                   __constrange(0,15) int val2); /* VQSHLU.S16 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint32x4_t vqshluq_n_s32(int32x4_t vec1,
                                                   __constrange(0,31) int val2); /* VQSHLU.S32 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint64x2_t vqshluq_n_s64(int64x2_t vec1,
                                                   __constrange(0,63) int val2); /* VQSHLU.S64 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vshrn_n_s16(int16x8_t vec1,
                                                      __constrange(1,8) int val2); /* VSHRN.I16 d0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vshrn_n_s32(int32x4_t vec1,
                                                       __constrange(1,16) int val2); /* VSHRN.I32 d0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vshrn_n_s64(int64x2_t vec1,
                                                       __constrange(1,32) int val2); /* VSHRN.I64 d0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vshrn_n_u16(uint16x8_t vec1,
                                                       __constrange(1,8) int val2); /* VSHRN.I16 d0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vshrn_n_u32(uint32x4_t vec1,
                                                        __constrange(1,16) int val2); /* VSHRN.I32 d0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vshrn_n_u64(uint64x2_t vec1,
                                                        __constrange(1,32) int val2); /* VSHRN.I64 d0,q0,#32 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqshrun_n_s16(int16x8_t vec1,
                                                  __constrange(1,8) int val2); /* VQSHRUN.S16 d0,q0,#8 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqshrun_n_s32(int32x4_t vec1,
                                                   __constrange(1,16) int val2); /* VQSHRUN.S32 d0,q0,#16 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqshrun_n_s64(int64x2_t vec1,
                                                   __constrange(1,32) int val2); /* VQSHRUN.S64 d0,q0,#32 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqrshrun_n_s16(int16x8_t vec1,
                                                   __constrange(1,8) int val2); /* VQRSHRUN.S16 d0,q0,#8 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqrshrun_n_s32(int32x4_t vec1,
                                                    __constrange(1,16) int val2); /* VQRSHRUN.S32 d0,q0,#16 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqrshrun_n_s64(int64x2_t vec1,
                                                    __constrange(1,32) int val2); /* VQRSHRUN.S64 d0,q0,#32 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqshrn_n_s16(int16x8_t vec1,
                                                __constrange(1,8) int val2); /* VQSHRN.S16 d0,q0,#8 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqshrn_n_s32(int32x4_t vec1,
                                                 __constrange(1,16) int val2); /* VQSHRN.S32 d0,q0,#16 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqshrn_n_s64(int64x2_t vec1,
                                                 __constrange(1,32) int val2); /* VQSHRN.S64 d0,q0,#32 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqshrn_n_u16(uint16x8_t vec1,
                                                 __constrange(1,8) int val2); /* VQSHRN.U16 d0,q0,#8 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqshrn_n_u32(uint32x4_t vec1,
                                                  __constrange(1,16) int val2); /* VQSHRN.U32 d0,q0,#16 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqshrn_n_u64(uint64x2_t vec1,
                                                  __constrange(1,32) int val2); /* VQSHRN.U64 d0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrshrn_n_s16(int16x8_t vec1,
                                                       __constrange(1,8) int val2); /* VRSHRN.I16 d0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrshrn_n_s32(int32x4_t vec1,
                                                        __constrange(1,16) int val2); /* VRSHRN.I32 d0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vrshrn_n_s64(int64x2_t vec1,
                                                        __constrange(1,32) int val2); /* VRSHRN.I64 d0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrshrn_n_u16(uint16x8_t vec1,
                                                        __constrange(1,8) int val2); /* VRSHRN.I16 d0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrshrn_n_u32(uint32x4_t vec1,
                                                         __constrange(1,16) int val2); /* VRSHRN.I32 d0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrshrn_n_u64(uint64x2_t vec1,
                                                         __constrange(1,32) int val2); /* VRSHRN.I64 d0,q0,#32 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqrshrn_n_s16(int16x8_t vec1,
                                                 __constrange(1,8) int val2); /* VQRSHRN.S16 d0,q0,#8 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqrshrn_n_s32(int32x4_t vec1,
                                                  __constrange(1,16) int val2); /* VQRSHRN.S32 d0,q0,#16 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqrshrn_n_s64(int64x2_t vec1,
                                                  __constrange(1,32) int val2); /* VQRSHRN.S64 d0,q0,#32 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqrshrn_n_u16(uint16x8_t vec1,
                                                  __constrange(1,8) int val2); /* VQRSHRN.U16 d0,q0,#8 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqrshrn_n_u32(uint32x4_t vec1,
                                                   __constrange(1,16) int val2); /* VQRSHRN.U32 d0,q0,#16 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqrshrn_n_u64(uint64x2_t vec1,
                                                   __constrange(1,32) int val2); /* VQRSHRN.U64 d0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vshll_n_s8(int8x8_t vec1,
                                                      __constrange(0,8) int val2); /* VSHLL.S8 q0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vshll_n_s16(int16x4_t vec1,
                                                       __constrange(0,16) int val2); /* VSHLL.S16 q0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vshll_n_s32(int32x2_t vec1,
                                                       __constrange(0,32) int val2); /* VSHLL.S32 q0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vshll_n_u8(uint8x8_t vec1,
                                                       __constrange(0,8) int val2); /* VSHLL.U8 q0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vshll_n_u16(uint16x4_t vec1,
                                                        __constrange(0,16) int val2); /* VSHLL.U16 q0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vshll_n_u32(uint32x2_t vec1,
                                                        __constrange(0,32) int val2); /* VSHLL.U32 q0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vsri_n_s8(int8x8_t vec1,
                                                    int8x8_t vec2,
                                                    __constrange(1,8) int val3); /* VSRI.8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vsri_n_s16(int16x4_t vec1,
                                                      int16x4_t vec2,
                                                      __constrange(1,16) int val3); /* VSRI.16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vsri_n_s32(int32x2_t vec1,
                                                      int32x2_t vec2,
                                                      __constrange(1,32) int val3); /* VSRI.32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vsri_n_s64(int64x1_t vec1,
                                                      int64x1_t vec2,
                                                      __constrange(1,64) int val3); /* VSRI.64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vsri_n_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2,
                                                     __constrange(1,8) int val3); /* VSRI.8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vsri_n_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2,
                                                       __constrange(1,16) int val3); /* VSRI.16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vsri_n_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2,
                                                       __constrange(1,32) int val3); /* VSRI.32 d0,d0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vsri_n_u64(uint64x1_t vec1,
                                                       uint64x1_t vec2,
                                                       __constrange(1,64) int val3); /* VSRI.64 d0,d0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vsri_n_p8(poly8x8_t vec1,
                                                     poly8x8_t vec2,
                                                     __constrange(1,8) int val3); /* VSRI.8 d0,d0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vsri_n_p16(poly16x4_t vec1,
                                                       poly16x4_t vec2,
                                                       __constrange(1,16) int val3); /* VSRI.16 d0,d0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vsriq_n_s8(int8x16_t vec1,
                                                      int8x16_t vec2,
                                                      __constrange(1,8) int val3); /* VSRI.8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vsriq_n_s16(int16x8_t vec1,
                                                       int16x8_t vec2,
                                                       __constrange(1,16) int val3); /* VSRI.16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vsriq_n_s32(int32x4_t vec1,
                                                       int32x4_t vec2,
                                                       __constrange(1,32) int val3); /* VSRI.32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vsriq_n_s64(int64x2_t vec1,
                                                       int64x2_t vec2,
                                                       __constrange(1,64) int val3); /* VSRI.64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vsriq_n_u8(uint8x16_t vec1,
                                                       uint8x16_t vec2,
                                                       __constrange(1,8) int val3); /* VSRI.8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vsriq_n_u16(uint16x8_t vec1,
                                                        uint16x8_t vec2,
                                                        __constrange(1,16) int val3); /* VSRI.16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vsriq_n_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2,
                                                        __constrange(1,32) int val3); /* VSRI.32 q0,q0,#32 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vsriq_n_u64(uint64x2_t vec1,
                                                        uint64x2_t vec2,
                                                        __constrange(1,64) int val3); /* VSRI.64 q0,q0,#64 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vsriq_n_p8(poly8x16_t vec1,
                                                       poly8x16_t vec2,
                                                       __constrange(1,8) int val3); /* VSRI.8 q0,q0,#8 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vsriq_n_p16(poly16x8_t vec1,
                                                        poly16x8_t vec2,
                                                        __constrange(1,16) int val3); /* VSRI.16 q0,q0,#16 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vsli_n_s8(int8x8_t vec1,
                                                    int8x8_t vec2,
                                                    __constrange(0,7) int val3); /* VSLI.8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vsli_n_s16(int16x4_t vec1,
                                                      int16x4_t vec2,
                                                      __constrange(0,15) int val3); /* VSLI.16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vsli_n_s32(int32x2_t vec1,
                                                      int32x2_t vec2,
                                                      __constrange(0,31) int val3); /* VSLI.32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vsli_n_s64(int64x1_t vec1,
                                                      int64x1_t vec2,
                                                      __constrange(0,63) int val3); /* VSLI.64 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vsli_n_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2,
                                                     __constrange(0,7) int val3); /* VSLI.8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vsli_n_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2,
                                                       __constrange(0,15) int val3); /* VSLI.16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vsli_n_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2,
                                                       __constrange(0,31) int val3); /* VSLI.32 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vsli_n_u64(uint64x1_t vec1,
                                                       uint64x1_t vec2,
                                                       __constrange(0,63) int val3); /* VSLI.64 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vsli_n_p8(poly8x8_t vec1,
                                                     poly8x8_t vec2,
                                                     __constrange(0,7) int val3); /* VSLI.8 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vsli_n_p16(poly16x4_t vec1,
                                                       poly16x4_t vec2,
                                                       __constrange(0,15) int val3); /* VSLI.16 d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vsliq_n_s8(int8x16_t vec1,
                                                      int8x16_t vec2,
                                                      __constrange(0,7) int val3); /* VSLI.8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vsliq_n_s16(int16x8_t vec1,
                                                       int16x8_t vec2,
                                                       __constrange(0,15) int val3); /* VSLI.16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vsliq_n_s32(int32x4_t vec1,
                                                       int32x4_t vec2,
                                                       __constrange(0,31) int val3); /* VSLI.32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vsliq_n_s64(int64x2_t vec1,
                                                       int64x2_t vec2,
                                                       __constrange(0,63) int val3); /* VSLI.64 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vsliq_n_u8(uint8x16_t vec1,
                                                       uint8x16_t vec2,
                                                       __constrange(0,7) int val3); /* VSLI.8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vsliq_n_u16(uint16x8_t vec1,
                                                        uint16x8_t vec2,
                                                        __constrange(0,15) int val3); /* VSLI.16 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vsliq_n_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2,
                                                        __constrange(0,31) int val3); /* VSLI.32 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vsliq_n_u64(uint64x2_t vec1,
                                                        uint64x2_t vec2,
                                                        __constrange(0,63) int val3); /* VSLI.64 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vsliq_n_p8(poly8x16_t vec1,
                                                       poly8x16_t vec2,
                                                       __constrange(0,7) int val3); /* VSLI.8 q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vsliq_n_p16(poly16x8_t vec1,
                                                        poly16x8_t vec2,
                                                        __constrange(0,15) int val3); /* VSLI.16 q0,q0,#0 */
__EXTERNC __VALUE_IN_REGS uint8x16_t vld1q_u8(__transfersize(16) uint8_t const * buf); /* VLD1.8 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x8_t vld1q_u16(__transfersize(8) uint16_t const * buf); /* VLD1.16 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x4_t vld1q_u32(__transfersize(4) uint32_t const * buf); /* VLD1.32 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x2_t vld1q_u64(__transfersize(2) uint64_t const * buf); /* VLD1.64 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x16_t vld1q_s8(__transfersize(16) int8_t const * buf); /* VLD1.8 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x8_t vld1q_s16(__transfersize(8) int16_t const * buf); /* VLD1.16 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vld1q_s32(__transfersize(4) int32_t const * buf); /* VLD1.32 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x2_t vld1q_s64(__transfersize(2) int64_t const * buf); /* VLD1.64 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x4_t vld1q_f32(__transfersize(4) float32_t const * buf); /* VLD1.32 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x16_t vld1q_p8(__transfersize(16) poly8_t const * buf); /* VLD1.8 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x8_t vld1q_p16(__transfersize(8) poly16_t const * buf); /* VLD1.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x8_t vld1q_f16(__transfersize(8) __fp16 const * buf); /* VLD1.16 {d0, d1}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x8_t vld1_u8(__transfersize(8) uint8_t const * buf); /* VLD1.8 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x4_t vld1_u16(__transfersize(4) uint16_t const * buf); /* VLD1.16 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x2_t vld1_u32(__transfersize(2) uint32_t const * buf); /* VLD1.32 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x1_t vld1_u64(__transfersize(1) uint64_t const * buf); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x8_t vld1_s8(__transfersize(8) int8_t const * buf); /* VLD1.8 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x4_t vld1_s16(__transfersize(4) int16_t const * buf); /* VLD1.16 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x2_t vld1_s32(__transfersize(2) int32_t const * buf); /* VLD1.32 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x1_t vld1_s64(__transfersize(1) int64_t const * buf); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x2_t vld1_f32(__transfersize(2) float32_t const * buf); /* VLD1.32 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x8_t vld1_p8(__transfersize(8) poly8_t const * buf); /* VLD1.8 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x4_t vld1_p16(__transfersize(4) poly16_t const * buf); /* VLD1.16 {d0}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x4_t vld1_f16(__transfersize(4) __fp16 const * buf); /* VLD1.16 {d0}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x16_t vld1q_lane_u8(__transfersize(1) uint8_t const * buf,
                                                   uint8x16_t vec,
                                                   __constrange(0,15) int num); /* VLD1.8 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x8_t vld1q_lane_u16(__transfersize(1) uint16_t const * buf,
                                                    uint16x8_t vec,
                                                    __constrange(0,7) int num); /* VLD1.16 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x4_t vld1q_lane_u32(__transfersize(1) uint32_t const * buf,
                                                    uint32x4_t vec,
                                                    __constrange(0,3) int num); /* VLD1.32 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x2_t vld1q_lane_u64(__transfersize(1) uint64_t const * buf,
                                                    uint64x2_t vec,
                                                    __constrange(0,1) int num); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x16_t vld1q_lane_s8(__transfersize(1) int8_t const * buf,
                                                  int8x16_t vec,
                                                  __constrange(0,15) int num); /* VLD1.8 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x8_t vld1q_lane_s16(__transfersize(1) int16_t const * buf,
                                                   int16x8_t vec,
                                                   __constrange(0,7) int num); /* VLD1.16 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vld1q_lane_s32(__transfersize(1) int32_t const * buf,
                                                   int32x4_t vec,
                                                   __constrange(0,3) int num); /* VLD1.32 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x4_t vld1q_lane_f32(__transfersize(1) float32_t const * buf,
                                                     float32x4_t vec,
                                                     __constrange(0,3) int num); /* VLD1.32 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x2_t vld1q_lane_s64(__transfersize(1) int64_t const * buf,
                                                   int64x2_t vec,
                                                   __constrange(0,1) int num); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x16_t vld1q_lane_p8(__transfersize(1) poly8_t const * buf,
                                                   poly8x16_t vec,
                                                   __constrange(0,15) int num); /* VLD1.8 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x8_t vld1q_lane_p16(__transfersize(1) poly16_t const * buf,
                                                    poly16x8_t vec,
                                                    __constrange(0,7) int num); /* VLD1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x8_t vld1q_lane_f16(__transfersize(1) __fp16 const * buf,
                                                     float16x8_t vec,
                                                     __constrange(0,7) int num); /* VLD1.16 {d0[0]}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x8_t vld1_lane_u8(__transfersize(1) uint8_t const * buf,
                                                 uint8x8_t vec,
                                                 __constrange(0,7) int num); /* VLD1.8 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x4_t vld1_lane_u16(__transfersize(1) uint16_t const * buf,
                                                   uint16x4_t vec,
                                                   __constrange(0,3) int num); /* VLD1.16 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x2_t vld1_lane_u32(__transfersize(1) uint32_t const * buf,
                                                   uint32x2_t vec,
                                                   __constrange(0,1) int num); /* VLD1.32 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x1_t vld1_lane_u64(__transfersize(1) uint64_t const * buf,
                                                   uint64x1_t vec,
                                                   __constrange(0,0) int num); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x8_t vld1_lane_s8(__transfersize(1) int8_t const * buf,
                                                int8x8_t vec,
                                                __constrange(0,7) int num); /* VLD1.8 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x4_t vld1_lane_s16(__transfersize(1) int16_t const * buf,
                                                  int16x4_t vec,
                                                  __constrange(0,3) int num); /* VLD1.16 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x2_t vld1_lane_s32(__transfersize(1) int32_t const * buf,
                                                  int32x2_t vec,
                                                  __constrange(0,1) int num); /* VLD1.32 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x2_t vld1_lane_f32(__transfersize(1) float32_t const * buf,
                                                    float32x2_t vec,
                                                    __constrange(0,1) int num); /* VLD1.32 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x1_t vld1_lane_s64(__transfersize(1) int64_t const * buf,
                                                  int64x1_t vec,
                                                  __constrange(0,0) int num); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x8_t vld1_lane_p8(__transfersize(1) poly8_t const * buf,
                                                 poly8x8_t vec,
                                                 __constrange(0,7) int num); /* VLD1.8 {d0[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x4_t vld1_lane_p16(__transfersize(1) poly16_t const * buf,
                                                   poly16x4_t vec,
                                                   __constrange(0,3) int num); /* VLD1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x4_t vld1_lane_f16(__transfersize(1) __fp16 const * buf,
                                                    float16x4_t vec,
                                                    __constrange(0,3) int num); /* VLD1.16 {d0[0]}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x16_t vld1q_dup_u8(__transfersize(1) uint8_t const * buf); /* VLD1.8 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x8_t vld1q_dup_u16(__transfersize(1) uint16_t const * buf); /* VLD1.16 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x4_t vld1q_dup_u32(__transfersize(1) uint32_t const * buf); /* VLD1.32 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x2_t vld1q_dup_u64(__transfersize(1) uint64_t const * buf); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x16_t vld1q_dup_s8(__transfersize(1) int8_t const * buf); /* VLD1.8 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x8_t vld1q_dup_s16(__transfersize(1) int16_t const * buf); /* VLD1.16 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vld1q_dup_s32(__transfersize(1) int32_t const * buf); /* VLD1.32 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x2_t vld1q_dup_s64(__transfersize(1) int64_t const * buf); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x4_t vld1q_dup_f32(__transfersize(1) float32_t const * buf); /* VLD1.32 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x16_t vld1q_dup_p8(__transfersize(1) poly8_t const * buf); /* VLD1.8 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x8_t vld1q_dup_p16(__transfersize(1) poly16_t const * buf); /* VLD1.16 {d0[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x8_t vld1q_dup_f16(__transfersize(1) __fp16 const * buf); /* VLD1.16 {d0[]}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x8_t vld1_dup_u8(__transfersize(1) uint8_t const * buf); /* VLD1.8 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x4_t vld1_dup_u16(__transfersize(1) uint16_t const * buf); /* VLD1.16 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x2_t vld1_dup_u32(__transfersize(1) uint32_t const * buf); /* VLD1.32 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x1_t vld1_dup_u64(__transfersize(1) uint64_t const * buf); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x8_t vld1_dup_s8(__transfersize(1) int8_t const * buf); /* VLD1.8 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x4_t vld1_dup_s16(__transfersize(1) int16_t const * buf); /* VLD1.16 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x2_t vld1_dup_s32(__transfersize(1) int32_t const * buf); /* VLD1.32 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x1_t vld1_dup_s64(__transfersize(1) int64_t const * buf); /* VLD1.64 {d0}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x2_t vld1_dup_f32(__transfersize(1) float32_t const * buf); /* VLD1.32 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x8_t vld1_dup_p8(__transfersize(1) poly8_t const * buf); /* VLD1.8 {d0[]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x4_t vld1_dup_p16(__transfersize(1) poly16_t const * buf); /* VLD1.16 {d0[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x4_t vld1_dup_f16(__transfersize(1) __fp16 const * buf); /* VLD1.16 {d0[]}, [r0] */
#endif
__EXTERNC void vst1q_u8(__transfersize(16) uint8_t * buf,
                        uint8x16_t vec); /* VST1.8 {d0, d1}, [r0] */
__EXTERNC void vst1q_u16(__transfersize(8) uint16_t * buf,
                         uint16x8_t vec); /* VST1.16 {d0, d1}, [r0] */
__EXTERNC void vst1q_u32(__transfersize(4) uint32_t * buf,
                         uint32x4_t vec); /* VST1.32 {d0, d1}, [r0] */
__EXTERNC void vst1q_u64(__transfersize(2) uint64_t * buf,
                         uint64x2_t vec); /* VST1.64 {d0, d1}, [r0] */
__EXTERNC void vst1q_s8(__transfersize(16) int8_t * buf,
                        int8x16_t vec); /* VST1.8 {d0, d1}, [r0] */
__EXTERNC void vst1q_s16(__transfersize(8) int16_t * buf,
                         int16x8_t vec); /* VST1.16 {d0, d1}, [r0] */
__EXTERNC void vst1q_s32(__transfersize(4) int32_t * buf,
                         int32x4_t vec); /* VST1.32 {d0, d1}, [r0] */
__EXTERNC void vst1q_s64(__transfersize(2) int64_t * buf,
                         int64x2_t vec); /* VST1.64 {d0, d1}, [r0] */
__EXTERNC void vst1q_f32(__transfersize(4) float32_t * buf,
                         float32x4_t vec); /* VST1.32 {d0, d1}, [r0] */
__EXTERNC void vst1q_p8(__transfersize(16) poly8_t * buf,
                        poly8x16_t vec); /* VST1.8 {d0, d1}, [r0] */
__EXTERNC void vst1q_p16(__transfersize(8) poly16_t * buf,
                         poly16x8_t vec); /* VST1.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst1q_f16(__transfersize(8) __fp16 * buf,
                         float16x8_t vec); /* VST1.16 {d0, d1}, [r0] */
#endif
__EXTERNC void vst1_u8(__transfersize(8) uint8_t * buf,
                       uint8x8_t vec); /* VST1.8 {d0}, [r0] */
__EXTERNC void vst1_u16(__transfersize(4) uint16_t * buf,
                        uint16x4_t vec); /* VST1.16 {d0}, [r0] */
__EXTERNC void vst1_u32(__transfersize(2) uint32_t * buf,
                        uint32x2_t vec); /* VST1.32 {d0}, [r0] */
__EXTERNC void vst1_u64(__transfersize(1) uint64_t * buf,
                        uint64x1_t vec); /* VST1.64 {d0}, [r0] */
__EXTERNC void vst1_s8(__transfersize(8) int8_t * buf,
                       int8x8_t vec); /* VST1.8 {d0}, [r0] */
__EXTERNC void vst1_s16(__transfersize(4) int16_t * buf,
                        int16x4_t vec); /* VST1.16 {d0}, [r0] */
__EXTERNC void vst1_s32(__transfersize(2) int32_t * buf,
                        int32x2_t vec); /* VST1.32 {d0}, [r0] */
__EXTERNC void vst1_s64(__transfersize(1) int64_t * buf,
                        int64x1_t vec); /* VST1.64 {d0}, [r0] */
__EXTERNC void vst1_f32(__transfersize(2) float32_t * buf,
                        float32x2_t vec); /* VST1.32 {d0}, [r0] */
__EXTERNC void vst1_p8(__transfersize(8) poly8_t * buf,
                       poly8x8_t vec); /* VST1.8 {d0}, [r0] */
__EXTERNC void vst1_p16(__transfersize(4) poly16_t * buf,
                        poly16x4_t vec); /* VST1.16 {d0}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst1_f16(__transfersize(4) __fp16 * buf,
                        float16x4_t vec); /* VST1.16 {d0}, [r0] */
#endif
__EXTERNC void vst1q_lane_u8(__transfersize(1) uint8_t * buf,
                             uint8x16_t vec,
                             __constrange(0,15) int num); /* VST1.8 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_u16(__transfersize(1) uint16_t * buf,
                              uint16x8_t vec,
                              __constrange(0,7) int num); /* VST1.16 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_u32(__transfersize(1) uint32_t * buf,
                              uint32x4_t vec,
                              __constrange(0,3) int num); /* VST1.32 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_u64(__transfersize(1) uint64_t * buf,
                              uint64x2_t vec,
                              __constrange(0,1) int num); /* VST1.64 {d0}, [r0] */
__EXTERNC void vst1q_lane_s8(__transfersize(1) int8_t * buf,
                             int8x16_t vec,
                             __constrange(0,15) int num); /* VST1.8 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_s16(__transfersize(1) int16_t * buf,
                              int16x8_t vec,
                              __constrange(0,7) int num); /* VST1.16 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_s32(__transfersize(1) int32_t * buf,
                              int32x4_t vec,
                              __constrange(0,3) int num); /* VST1.32 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_s64(__transfersize(1) int64_t * buf,
                              int64x2_t vec,
                              __constrange(0,1) int num); /* VST1.64 {d0}, [r0] */
__EXTERNC void vst1q_lane_f32(__transfersize(1) float32_t * buf,
                              float32x4_t vec,
                              __constrange(0,3) int num); /* VST1.32 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_p8(__transfersize(1) poly8_t * buf,
                             poly8x16_t vec,
                             __constrange(0,15) int num); /* VST1.8 {d0[0]}, [r0] */
__EXTERNC void vst1q_lane_p16(__transfersize(1) poly16_t * buf,
                              poly16x8_t vec,
                              __constrange(0,7) int num); /* VST1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst1q_lane_f16(__transfersize(1) __fp16 * buf,
                              float16x8_t vec,
                              __constrange(0,7) int num); /* VST1.16 {d0[0]}, [r0] */
#endif
__EXTERNC void vst1_lane_u8(__transfersize(1) uint8_t * buf,
                            uint8x8_t vec,
                            __constrange(0,7) int num); /* VST1.8 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_u16(__transfersize(1) uint16_t * buf,
                             uint16x4_t vec,
                             __constrange(0,3) int num); /* VST1.16 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_u32(__transfersize(1) uint32_t * buf,
                             uint32x2_t vec,
                             __constrange(0,1) int num); /* VST1.32 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_u64(__transfersize(1) uint64_t * buf,
                             uint64x1_t vec,
                             __constrange(0,0) int num); /* VST1.64 {d0}, [r0] */
__EXTERNC void vst1_lane_s8(__transfersize(1) int8_t * buf,
                            int8x8_t vec,
                            __constrange(0,7) int num); /* VST1.8 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_s16(__transfersize(1) int16_t * buf,
                             int16x4_t vec,
                             __constrange(0,3) int num); /* VST1.16 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_s32(__transfersize(1) int32_t * buf,
                             int32x2_t vec,
                             __constrange(0,1) int num); /* VST1.32 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_s64(__transfersize(1) int64_t * buf,
                             int64x1_t vec,
                             __constrange(0,0) int num); /* VST1.64 {d0}, [r0] */
__EXTERNC void vst1_lane_f32(__transfersize(1) float32_t * buf,
                             float32x2_t vec,
                             __constrange(0,1) int num); /* VST1.32 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_p8(__transfersize(1) poly8_t * buf,
                            poly8x8_t vec,
                            __constrange(0,7) int num); /* VST1.8 {d0[0]}, [r0] */
__EXTERNC void vst1_lane_p16(__transfersize(1) poly16_t * buf,
                             poly16x4_t vec,
                             __constrange(0,3) int num); /* VST1.16 {d0[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst1_lane_f16(__transfersize(1) __fp16 * buf,
                             float16x4_t vec,
                             __constrange(0,3) int num); /* VST1.16 {d0[0]}, [r0] */
#endif
__EXTERNC uint8x16x2_t vld2q_u8(__transfersize(32) uint8_t const * buf); /* VLD2.8 {d0, d2}, [r0] */
__EXTERNC uint16x8x2_t vld2q_u16(__transfersize(16) uint16_t const * buf); /* VLD2.16 {d0, d2}, [r0] */
__EXTERNC uint32x4x2_t vld2q_u32(__transfersize(8) uint32_t const * buf); /* VLD2.32 {d0, d2}, [r0] */
__EXTERNC int8x16x2_t vld2q_s8(__transfersize(32) int8_t const * buf); /* VLD2.8 {d0, d2}, [r0] */
__EXTERNC int16x8x2_t vld2q_s16(__transfersize(16) int16_t const * buf); /* VLD2.16 {d0, d2}, [r0] */
__EXTERNC int32x4x2_t vld2q_s32(__transfersize(8) int32_t const * buf); /* VLD2.32 {d0, d2}, [r0] */
__EXTERNC float32x4x2_t vld2q_f32(__transfersize(8) float32_t const * buf); /* VLD2.32 {d0, d2}, [r0] */
__EXTERNC poly8x16x2_t vld2q_p8(__transfersize(32) poly8_t const * buf); /* VLD2.8 {d0, d2}, [r0] */
__EXTERNC poly16x8x2_t vld2q_p16(__transfersize(16) poly16_t const * buf); /* VLD2.16 {d0, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x8x2_t vld2q_f16(__transfersize(16) __fp16 const * buf); /* VLD2.16 {d0, d2}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x8x2_t vld2_u8(__transfersize(16) uint8_t const * buf); /* VLD2.8 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x4x2_t vld2_u16(__transfersize(8) uint16_t const * buf); /* VLD2.16 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x2x2_t vld2_u32(__transfersize(4) uint32_t const * buf); /* VLD2.32 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x1x2_t vld2_u64(__transfersize(2) uint64_t const * buf); /* VLD1.64 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x8x2_t vld2_s8(__transfersize(16) int8_t const * buf); /* VLD2.8 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x4x2_t vld2_s16(__transfersize(8) int16_t const * buf); /* VLD2.16 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x2x2_t vld2_s32(__transfersize(4) int32_t const * buf); /* VLD2.32 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x1x2_t vld2_s64(__transfersize(2) int64_t const * buf); /* VLD1.64 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x2x2_t vld2_f32(__transfersize(4) float32_t const * buf); /* VLD2.32 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x8x2_t vld2_p8(__transfersize(16) poly8_t const * buf); /* VLD2.8 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x4x2_t vld2_p16(__transfersize(8) poly16_t const * buf); /* VLD2.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x4x2_t vld2_f16(__transfersize(8) __fp16 const * buf); /* VLD2.16 {d0, d1}, [r0] */
#endif
__EXTERNC uint8x16x3_t vld3q_u8(__transfersize(48) uint8_t const * buf); /* VLD3.8 {d0, d2, d4}, [r0] */
__EXTERNC uint16x8x3_t vld3q_u16(__transfersize(24) uint16_t const * buf); /* VLD3.16 {d0, d2, d4}, [r0] */
__EXTERNC uint32x4x3_t vld3q_u32(__transfersize(12) uint32_t const * buf); /* VLD3.32 {d0, d2, d4}, [r0] */
__EXTERNC int8x16x3_t vld3q_s8(__transfersize(48) int8_t const * buf); /* VLD3.8 {d0, d2, d4}, [r0] */
__EXTERNC int16x8x3_t vld3q_s16(__transfersize(24) int16_t const * buf); /* VLD3.16 {d0, d2, d4}, [r0] */
__EXTERNC int32x4x3_t vld3q_s32(__transfersize(12) int32_t const * buf); /* VLD3.32 {d0, d2, d4}, [r0] */
__EXTERNC float32x4x3_t vld3q_f32(__transfersize(12) float32_t const * buf); /* VLD3.32 {d0, d2, d4}, [r0] */
__EXTERNC poly8x16x3_t vld3q_p8(__transfersize(48) poly8_t const * buf); /* VLD3.8 {d0, d2, d4}, [r0] */
__EXTERNC poly16x8x3_t vld3q_p16(__transfersize(24) poly16_t const * buf); /* VLD3.16 {d0, d2, d4}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x8x3_t vld3q_f16(__transfersize(24) __fp16 const * buf); /* VLD3.16 {d0, d2, d4}, [r0] */
#endif
__EXTERNC uint8x8x3_t vld3_u8(__transfersize(24) uint8_t const * buf); /* VLD3.8 {d0, d1, d2}, [r0] */
__EXTERNC uint16x4x3_t vld3_u16(__transfersize(12) uint16_t const * buf); /* VLD3.16 {d0, d1, d2}, [r0] */
__EXTERNC uint32x2x3_t vld3_u32(__transfersize(6) uint32_t const * buf); /* VLD3.32 {d0, d1, d2}, [r0] */
__EXTERNC uint64x1x3_t vld3_u64(__transfersize(3) uint64_t const * buf); /* VLD1.64 {d0, d1, d2}, [r0] */
__EXTERNC int8x8x3_t vld3_s8(__transfersize(24) int8_t const * buf); /* VLD3.8 {d0, d1, d2}, [r0] */
__EXTERNC int16x4x3_t vld3_s16(__transfersize(12) int16_t const * buf); /* VLD3.16 {d0, d1, d2}, [r0] */
__EXTERNC int32x2x3_t vld3_s32(__transfersize(6) int32_t const * buf); /* VLD3.32 {d0, d1, d2}, [r0] */
__EXTERNC int64x1x3_t vld3_s64(__transfersize(3) int64_t const * buf); /* VLD1.64 {d0, d1, d2}, [r0] */
__EXTERNC float32x2x3_t vld3_f32(__transfersize(6) float32_t const * buf); /* VLD3.32 {d0, d1, d2}, [r0] */
__EXTERNC poly8x8x3_t vld3_p8(__transfersize(24) poly8_t const * buf); /* VLD3.8 {d0, d1, d2}, [r0] */
__EXTERNC poly16x4x3_t vld3_p16(__transfersize(12) poly16_t const * buf); /* VLD3.16 {d0, d1, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x4x3_t vld3_f16(__transfersize(12) __fp16 const * buf); /* VLD3.16 {d0, d1, d2}, [r0] */
#endif
__EXTERNC uint8x16x4_t vld4q_u8(__transfersize(64) uint8_t const * buf); /* VLD4.8 {d0, d2, d4, d6}, [r0] */
__EXTERNC uint16x8x4_t vld4q_u16(__transfersize(32) uint16_t const * buf); /* VLD4.16 {d0, d2, d4, d6}, [r0] */
__EXTERNC uint32x4x4_t vld4q_u32(__transfersize(16) uint32_t const * buf); /* VLD4.32 {d0, d2, d4, d6}, [r0] */
__EXTERNC int8x16x4_t vld4q_s8(__transfersize(64) int8_t const * buf); /* VLD4.8 {d0, d2, d4, d6}, [r0] */
__EXTERNC int16x8x4_t vld4q_s16(__transfersize(32) int16_t const * buf); /* VLD4.16 {d0, d2, d4, d6}, [r0] */
__EXTERNC int32x4x4_t vld4q_s32(__transfersize(16) int32_t const * buf); /* VLD4.32 {d0, d2, d4, d6}, [r0] */
__EXTERNC float32x4x4_t vld4q_f32(__transfersize(16) float32_t const * buf); /* VLD4.32 {d0, d2, d4, d6}, [r0] */
__EXTERNC poly8x16x4_t vld4q_p8(__transfersize(64) poly8_t const * buf); /* VLD4.8 {d0, d2, d4, d6}, [r0] */
__EXTERNC poly16x8x4_t vld4q_p16(__transfersize(32) poly16_t const * buf); /* VLD4.16 {d0, d2, d4, d6}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x8x4_t vld4q_f16(__transfersize(32) __fp16 const * buf); /* VLD4.16 {d0, d2, d4, d6}, [r0] */
#endif
__EXTERNC uint8x8x4_t vld4_u8(__transfersize(32) uint8_t const * buf); /* VLD4.8 {d0, d1, d2, d3}, [r0] */
__EXTERNC uint16x4x4_t vld4_u16(__transfersize(16) uint16_t const * buf); /* VLD4.16 {d0, d1, d2, d3}, [r0] */
__EXTERNC uint32x2x4_t vld4_u32(__transfersize(8) uint32_t const * buf); /* VLD4.32 {d0, d1, d2, d3}, [r0] */
__EXTERNC uint64x1x4_t vld4_u64(__transfersize(4) uint64_t const * buf); /* VLD1.64 {d0, d1, d2, d3}, [r0] */
__EXTERNC int8x8x4_t vld4_s8(__transfersize(32) int8_t const * buf); /* VLD4.8 {d0, d1, d2, d3}, [r0] */
__EXTERNC int16x4x4_t vld4_s16(__transfersize(16) int16_t const * buf); /* VLD4.16 {d0, d1, d2, d3}, [r0] */
__EXTERNC int32x2x4_t vld4_s32(__transfersize(8) int32_t const * buf); /* VLD4.32 {d0, d1, d2, d3}, [r0] */
__EXTERNC int64x1x4_t vld4_s64(__transfersize(4) int64_t const * buf); /* VLD1.64 {d0, d1, d2, d3}, [r0] */
__EXTERNC float32x2x4_t vld4_f32(__transfersize(8) float32_t const * buf); /* VLD4.32 {d0, d1, d2, d3}, [r0] */
__EXTERNC poly8x8x4_t vld4_p8(__transfersize(32) poly8_t const * buf); /* VLD4.8 {d0, d1, d2, d3}, [r0] */
__EXTERNC poly16x4x4_t vld4_p16(__transfersize(16) poly16_t const * buf); /* VLD4.16 {d0, d1, d2, d3}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x4x4_t vld4_f16(__transfersize(16) __fp16 const * buf); /* VLD4.16 {d0, d1, d2, d3}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x8x2_t vld2_dup_u8(__transfersize(2) uint8_t const * buf); /* VLD2.8 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x4x2_t vld2_dup_u16(__transfersize(2) uint16_t const * buf); /* VLD2.16 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x2x2_t vld2_dup_u32(__transfersize(2) uint32_t const * buf); /* VLD2.32 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint64x1x2_t vld2_dup_u64(__transfersize(2) uint64_t const * buf); /* VLD1.64 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x8x2_t vld2_dup_s8(__transfersize(2) int8_t const * buf); /* VLD2.8 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x4x2_t vld2_dup_s16(__transfersize(2) int16_t const * buf); /* VLD2.16 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x2x2_t vld2_dup_s32(__transfersize(2) int32_t const * buf); /* VLD2.32 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS int64x1x2_t vld2_dup_s64(__transfersize(2) int64_t const * buf); /* VLD1.64 {d0, d1}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x2x2_t vld2_dup_f32(__transfersize(2) float32_t const * buf); /* VLD2.32 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x8x2_t vld2_dup_p8(__transfersize(2) poly8_t const * buf); /* VLD2.8 {d0[], d1[]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x4x2_t vld2_dup_p16(__transfersize(2) poly16_t const * buf); /* VLD2.16 {d0[], d1[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x4x2_t vld2_dup_f16(__transfersize(2) __fp16 const * buf); /* VLD2.16 {d0[], d1[]}, [r0] */
#endif
__EXTERNC uint8x8x3_t vld3_dup_u8(__transfersize(3) uint8_t const * buf); /* VLD3.8 {d0[], d1[], d2[]}, [r0] */
__EXTERNC uint16x4x3_t vld3_dup_u16(__transfersize(3) uint16_t const * buf); /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
__EXTERNC uint32x2x3_t vld3_dup_u32(__transfersize(3) uint32_t const * buf); /* VLD3.32 {d0[], d1[], d2[]}, [r0] */
__EXTERNC uint64x1x3_t vld3_dup_u64(__transfersize(3) uint64_t const * buf); /* VLD1.64 {d0, d1, d2}, [r0] */
__EXTERNC int8x8x3_t vld3_dup_s8(__transfersize(3) int8_t const * buf); /* VLD3.8 {d0[], d1[], d2[]}, [r0] */
__EXTERNC int16x4x3_t vld3_dup_s16(__transfersize(3) int16_t const * buf); /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
__EXTERNC int32x2x3_t vld3_dup_s32(__transfersize(3) int32_t const * buf); /* VLD3.32 {d0[], d1[], d2[]}, [r0] */
__EXTERNC int64x1x3_t vld3_dup_s64(__transfersize(3) int64_t const * buf); /* VLD1.64 {d0, d1, d2}, [r0] */
__EXTERNC float32x2x3_t vld3_dup_f32(__transfersize(3) float32_t const * buf); /* VLD3.32 {d0[], d1[], d2[]}, [r0] */
__EXTERNC poly8x8x3_t vld3_dup_p8(__transfersize(3) poly8_t const * buf); /* VLD3.8 {d0[], d1[], d2[]}, [r0] */
__EXTERNC poly16x4x3_t vld3_dup_p16(__transfersize(3) poly16_t const * buf); /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x4x3_t vld3_dup_f16(__transfersize(3) __fp16 const * buf); /* VLD3.16 {d0[], d1[], d2[]}, [r0] */
#endif
__EXTERNC uint8x8x4_t vld4_dup_u8(__transfersize(4) uint8_t const * buf); /* VLD4.8 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC uint16x4x4_t vld4_dup_u16(__transfersize(4) uint16_t const * buf); /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC uint32x2x4_t vld4_dup_u32(__transfersize(4) uint32_t const * buf); /* VLD4.32 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC uint64x1x4_t vld4_dup_u64(__transfersize(4) uint64_t const * buf); /* VLD1.64 {d0, d1, d2, d3}, [r0] */
__EXTERNC int8x8x4_t vld4_dup_s8(__transfersize(4) int8_t const * buf); /* VLD4.8 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC int16x4x4_t vld4_dup_s16(__transfersize(4) int16_t const * buf); /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC int32x2x4_t vld4_dup_s32(__transfersize(4) int32_t const * buf); /* VLD4.32 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC int64x1x4_t vld4_dup_s64(__transfersize(4) int64_t const * buf); /* VLD1.64 {d0, d1, d2, d3}, [r0] */
__EXTERNC float32x2x4_t vld4_dup_f32(__transfersize(4) float32_t const * buf); /* VLD4.32 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC poly8x8x4_t vld4_dup_p8(__transfersize(4) poly8_t const * buf); /* VLD4.8 {d0[], d1[], d2[], d3[]}, [r0] */
__EXTERNC poly16x4x4_t vld4_dup_p16(__transfersize(4) poly16_t const * buf); /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x4x4_t vld4_dup_f16(__transfersize(4) __fp16 const * buf); /* VLD4.16 {d0[], d1[], d2[], d3[]}, [r0] */
#endif
__EXTERNC uint16x8x2_t vld2q_lane_u16(__transfersize(2) uint16_t const * buf,
                                      uint16x8x2_t vec,
                                      __constrange(0,7) int num); /* VLD2.16 {d0[0], d2[0]}, [r0] */
__EXTERNC uint32x4x2_t vld2q_lane_u32(__transfersize(2) uint32_t const * buf,
                                      uint32x4x2_t vec,
                                      __constrange(0,3) int num); /* VLD2.32 {d0[0], d2[0]}, [r0] */
__EXTERNC int16x8x2_t vld2q_lane_s16(__transfersize(2) int16_t const * buf,
                                     int16x8x2_t vec,
                                     __constrange(0,7) int num); /* VLD2.16 {d0[0], d2[0]}, [r0] */
__EXTERNC int32x4x2_t vld2q_lane_s32(__transfersize(2) int32_t const * buf,
                                     int32x4x2_t vec,
                                     __constrange(0,3) int num); /* VLD2.32 {d0[0], d2[0]}, [r0] */
__EXTERNC float32x4x2_t vld2q_lane_f32(__transfersize(2) float32_t const * buf,
                                       float32x4x2_t vec,
                                       __constrange(0,3) int num); /* VLD2.32 {d0[0], d2[0]}, [r0] */
__EXTERNC poly16x8x2_t vld2q_lane_p16(__transfersize(2) poly16_t const * buf,
                                      poly16x8x2_t vec,
                                      __constrange(0,7) int num); /* VLD2.16 {d0[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x8x2_t vld2q_lane_f16(__transfersize(2) __fp16 const * buf,
                                       float16x8x2_t vec,
                                       __constrange(0,7) int num); /* VLD2.16 {d0[0], d2[0]}, [r0] */
#endif
__EXTERNC __VALUE_IN_REGS uint8x8x2_t vld2_lane_u8(__transfersize(2) uint8_t const * buf,
                                                   uint8x8x2_t vec,
                                                   __constrange(0,7) int num); /* VLD2.8 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint16x4x2_t vld2_lane_u16(__transfersize(2) uint16_t const * buf,
                                                     uint16x4x2_t vec,
                                                     __constrange(0,3) int num); /* VLD2.16 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS uint32x2x2_t vld2_lane_u32(__transfersize(2) uint32_t const * buf,
                                                     uint32x2x2_t vec,
                                                     __constrange(0,1) int num); /* VLD2.32 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int8x8x2_t vld2_lane_s8(__transfersize(2) int8_t const * buf,
                                                  int8x8x2_t vec,
                                                  __constrange(0,7) int num); /* VLD2.8 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int16x4x2_t vld2_lane_s16(__transfersize(2) int16_t const * buf,
                                                    int16x4x2_t vec,
                                                    __constrange(0,3) int num); /* VLD2.16 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS int32x2x2_t vld2_lane_s32(__transfersize(2) int32_t const * buf,
                                                    int32x2x2_t vec,
                                                    __constrange(0,1) int num); /* VLD2.32 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS float32x2x2_t vld2_lane_f32(__transfersize(2) float32_t const * buf,
                                                      float32x2x2_t vec,
                                                      __constrange(0,1) int num); /* VLD2.32 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly8x8x2_t vld2_lane_p8(__transfersize(2) poly8_t const * buf,
                                                   poly8x8x2_t vec,
                                                   __constrange(0,7) int num); /* VLD2.8 {d0[0], d1[0]}, [r0] */
__EXTERNC __VALUE_IN_REGS poly16x4x2_t vld2_lane_p16(__transfersize(2) poly16_t const * buf,
                                                     poly16x4x2_t vec,
                                                     __constrange(0,3) int num); /* VLD2.16 {d0[0], d1[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __VALUE_IN_REGS float16x4x2_t vld2_lane_f16(__transfersize(2) __fp16 const * buf,
                                                      float16x4x2_t vec,
                                                      __constrange(0,3) int num); /* VLD2.16 {d0[0], d1[0]}, [r0] */
#endif
__EXTERNC uint16x8x3_t vld3q_lane_u16(__transfersize(3) uint16_t const * buf,
                                      uint16x8x3_t vec,
                                      __constrange(0,7) int num); /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC uint32x4x3_t vld3q_lane_u32(__transfersize(3) uint32_t const * buf,
                                      uint32x4x3_t vec,
                                      __constrange(0,3) int num); /* VLD3.32 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC int16x8x3_t vld3q_lane_s16(__transfersize(3) int16_t const * buf,
                                     int16x8x3_t vec,
                                     __constrange(0,7) int num); /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC int32x4x3_t vld3q_lane_s32(__transfersize(3) int32_t const * buf,
                                     int32x4x3_t vec,
                                     __constrange(0,3) int num); /* VLD3.32 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC float32x4x3_t vld3q_lane_f32(__transfersize(3) float32_t const * buf,
                                       float32x4x3_t vec,
                                       __constrange(0,3) int num); /* VLD3.32 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC poly16x8x3_t vld3q_lane_p16(__transfersize(3) poly16_t const * buf,
                                      poly16x8x3_t vec,
                                      __constrange(0,7) int num); /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x8x3_t vld3q_lane_f16(__transfersize(3) __fp16 const * buf,
                                       float16x8x3_t vec,
                                       __constrange(0,7) int num); /* VLD3.16 {d0[0], d2[0], d4[0]}, [r0] */
#endif
__EXTERNC uint8x8x3_t vld3_lane_u8(__transfersize(3) uint8_t const * buf,
                                   uint8x8x3_t vec,
                                   __constrange(0,7) int num); /* VLD3.8 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC uint16x4x3_t vld3_lane_u16(__transfersize(3) uint16_t const * buf,
                                     uint16x4x3_t vec,
                                     __constrange(0,3) int num); /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC uint32x2x3_t vld3_lane_u32(__transfersize(3) uint32_t const * buf,
                                     uint32x2x3_t vec,
                                     __constrange(0,1) int num); /* VLD3.32 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC int8x8x3_t vld3_lane_s8(__transfersize(3) int8_t const * buf,
                                  int8x8x3_t vec,
                                  __constrange(0,7) int num); /* VLD3.8 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC int16x4x3_t vld3_lane_s16(__transfersize(3) int16_t const * buf,
                                    int16x4x3_t vec,
                                    __constrange(0,3) int num); /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC int32x2x3_t vld3_lane_s32(__transfersize(3) int32_t const * buf,
                                    int32x2x3_t vec,
                                    __constrange(0,1) int num); /* VLD3.32 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC float32x2x3_t vld3_lane_f32(__transfersize(3) float32_t const * buf,
                                      float32x2x3_t vec,
                                      __constrange(0,1) int num); /* VLD3.32 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC poly8x8x3_t vld3_lane_p8(__transfersize(3) poly8_t const * buf,
                                   poly8x8x3_t vec,
                                   __constrange(0,7) int num); /* VLD3.8 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC poly16x4x3_t vld3_lane_p16(__transfersize(3) poly16_t const * buf,
                                     poly16x4x3_t vec,
                                     __constrange(0,3) int num); /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x4x3_t vld3_lane_f16(__transfersize(3) __fp16 const * buf,
                                      float16x4x3_t vec,
                                      __constrange(0,3) int num); /* VLD3.16 {d0[0], d1[0], d2[0]}, [r0] */
#endif
__EXTERNC uint16x8x4_t vld4q_lane_u16(__transfersize(4) uint16_t const * buf,
                                      uint16x8x4_t vec,
                                      __constrange(0,7) int num); /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC uint32x4x4_t vld4q_lane_u32(__transfersize(4) uint32_t const * buf,
                                      uint32x4x4_t vec,
                                      __constrange(0,3) int num); /* VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC int16x8x4_t vld4q_lane_s16(__transfersize(4) int16_t const * buf,
                                     int16x8x4_t vec,
                                     __constrange(0,7) int num); /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC int32x4x4_t vld4q_lane_s32(__transfersize(4) int32_t const * buf,
                                     int32x4x4_t vec,
                                     __constrange(0,3) int num); /* VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC float32x4x4_t vld4q_lane_f32(__transfersize(4) float32_t const * buf,
                                       float32x4x4_t vec,
                                       __constrange(0,3) int num); /* VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC poly16x8x4_t vld4q_lane_p16(__transfersize(4) poly16_t const * buf,
                                      poly16x8x4_t vec,
                                      __constrange(0,7) int num); /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x8x4_t vld4q_lane_f16(__transfersize(4) __fp16 const * buf,
                                       float16x8x4_t vec,
                                       __constrange(0,7) int num); /* VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#endif
__EXTERNC uint8x8x4_t vld4_lane_u8(__transfersize(4) uint8_t const * buf,
                                   uint8x8x4_t vec,
                                   __constrange(0,7) int num); /* VLD4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC uint16x4x4_t vld4_lane_u16(__transfersize(4) uint16_t const * buf,
                                     uint16x4x4_t vec,
                                     __constrange(0,3) int num); /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC uint32x2x4_t vld4_lane_u32(__transfersize(4) uint32_t const * buf,
                                     uint32x2x4_t vec,
                                     __constrange(0,1) int num); /* VLD4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC int8x8x4_t vld4_lane_s8(__transfersize(4) int8_t const * buf,
                                  int8x8x4_t vec,
                                  __constrange(0,7) int num); /* VLD4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC int16x4x4_t vld4_lane_s16(__transfersize(4) int16_t const * buf,
                                    int16x4x4_t vec,
                                    __constrange(0,3) int num); /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC int32x2x4_t vld4_lane_s32(__transfersize(4) int32_t const * buf,
                                    int32x2x4_t vec,
                                    __constrange(0,1) int num); /* VLD4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC float32x2x4_t vld4_lane_f32(__transfersize(4) float32_t const * buf,
                                      float32x2x4_t vec,
                                      __constrange(0,1) int num); /* VLD4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC poly8x8x4_t vld4_lane_p8(__transfersize(4) poly8_t const * buf,
                                   poly8x8x4_t vec,
                                   __constrange(0,7) int num); /* VLD4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC poly16x4x4_t vld4_lane_p16(__transfersize(4) poly16_t const * buf,
                                     poly16x4x4_t vec,
                                     __constrange(0,3) int num); /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC float16x4x4_t vld4_lane_f16(__transfersize(4) __fp16 const * buf,
                                      float16x4x4_t vec,
                                      __constrange(0,3) int num); /* VLD4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#endif
__EXTERNC void vst2q_u8(__transfersize(32) uint8_t * buf,
                        uint8x16x2_t vecs); /* VST2.8 {d0, d2}, [r0] */
__EXTERNC void vst2q_u16(__transfersize(16) uint16_t * buf,
                         uint16x8x2_t vecs); /* VST2.16 {d0, d2}, [r0] */
__EXTERNC void vst2q_u32(__transfersize(8) uint32_t * buf,
                         uint32x4x2_t vecs); /* VST2.32 {d0, d2}, [r0] */
__EXTERNC void vst2q_s8(__transfersize(32) int8_t * buf,
                        int8x16x2_t vecs); /* VST2.8 {d0, d2}, [r0] */
__EXTERNC void vst2q_s16(__transfersize(16) int16_t * buf,
                         int16x8x2_t vecs); /* VST2.16 {d0, d2}, [r0] */
__EXTERNC void vst2q_s32(__transfersize(8) int32_t * buf,
                         int32x4x2_t vecs); /* VST2.32 {d0, d2}, [r0] */
__EXTERNC void vst2q_f32(__transfersize(8) float32_t * buf,
                         float32x4x2_t vecs); /* VST2.32 {d0, d2}, [r0] */
__EXTERNC void vst2q_p8(__transfersize(32) poly8_t * buf,
                        poly8x16x2_t vecs); /* VST2.8 {d0, d2}, [r0] */
__EXTERNC void vst2q_p16(__transfersize(16) poly16_t * buf,
                         poly16x8x2_t vecs); /* VST2.16 {d0, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst2q_f16(__transfersize(16) __fp16 * buf,
                         float16x8x2_t vecs); /* VST2.16 {d0, d2}, [r0] */
#endif
__EXTERNC void vst2_u8(__transfersize(16) uint8_t * buf,
                       uint8x8x2_t vecs); /* VST2.8 {d0, d1}, [r0] */
__EXTERNC void vst2_u16(__transfersize(8) uint16_t * buf,
                        uint16x4x2_t vecs); /* VST2.16 {d0, d1}, [r0] */
__EXTERNC void vst2_u32(__transfersize(4) uint32_t * buf,
                        uint32x2x2_t vecs); /* VST2.32 {d0, d1}, [r0] */
__EXTERNC void vst2_u64(__transfersize(2) uint64_t * buf,
                        uint64x1x2_t vecs); /* VST1.64 {d0, d1}, [r0] */
__EXTERNC void vst2_s8(__transfersize(16) int8_t * buf,
                       int8x8x2_t vecs); /* VST2.8 {d0, d1}, [r0] */
__EXTERNC void vst2_s16(__transfersize(8) int16_t * buf,
                        int16x4x2_t vecs); /* VST2.16 {d0, d1}, [r0] */
__EXTERNC void vst2_s32(__transfersize(4) int32_t * buf,
                        int32x2x2_t vecs); /* VST2.32 {d0, d1}, [r0] */
__EXTERNC void vst2_s64(__transfersize(2) int64_t * buf,
                        int64x1x2_t vecs); /* VST1.64 {d0, d1}, [r0] */
__EXTERNC void vst2_f32(__transfersize(4) float32_t * buf,
                        float32x2x2_t vecs); /* VST2.32 {d0, d1}, [r0] */
__EXTERNC void vst2_p8(__transfersize(16) poly8_t * buf,
                       poly8x8x2_t vecs); /* VST2.8 {d0, d1}, [r0] */
__EXTERNC void vst2_p16(__transfersize(8) poly16_t * buf,
                        poly16x4x2_t vecs); /* VST2.16 {d0, d1}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst2_f16(__transfersize(8) __fp16 * buf,
                        float16x4x2_t vecs); /* VST2.16 {d0, d1}, [r0] */
#endif
__EXTERNC void vst3q_u8(__transfersize(48) uint8_t * buf,
                        uint8x16x3_t vecs); /* VST3.8 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_u16(__transfersize(24) uint16_t * buf,
                         uint16x8x3_t vecs); /* VST3.16 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_u32(__transfersize(12) uint32_t * buf,
                         uint32x4x3_t vecs); /* VST3.32 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_s8(__transfersize(48) int8_t * buf,
                        int8x16x3_t vecs); /* VST3.8 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_s16(__transfersize(24) int16_t * buf,
                         int16x8x3_t vecs); /* VST3.16 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_s32(__transfersize(12) int32_t * buf,
                         int32x4x3_t vecs); /* VST3.32 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_f32(__transfersize(12) float32_t * buf,
                         float32x4x3_t vecs); /* VST3.32 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_p8(__transfersize(48) poly8_t * buf,
                        poly8x16x3_t vecs); /* VST3.8 {d0, d2, d4}, [r0] */
__EXTERNC void vst3q_p16(__transfersize(24) poly16_t * buf,
                         poly16x8x3_t vecs); /* VST3.16 {d0, d2, d4}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst3q_f16(__transfersize(24) __fp16 * buf,
                         float16x8x3_t vecs); /* VST3.16 {d0, d2, d4}, [r0] */
#endif
__EXTERNC void vst3_u8(__transfersize(24) uint8_t * buf,
                       uint8x8x3_t vecs); /* VST3.8 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_u16(__transfersize(12) uint16_t * buf,
                        uint16x4x3_t vecs); /* VST3.16 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_u32(__transfersize(6) uint32_t * buf,
                        uint32x2x3_t vecs); /* VST3.32 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_u64(__transfersize(3) uint64_t * buf,
                        uint64x1x3_t vecs); /* VST1.64 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_s8(__transfersize(24) int8_t * buf,
                       int8x8x3_t vecs); /* VST3.8 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_s16(__transfersize(12) int16_t * buf,
                        int16x4x3_t vecs); /* VST3.16 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_s32(__transfersize(6) int32_t * buf,
                        int32x2x3_t vecs); /* VST3.32 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_s64(__transfersize(3) int64_t * buf,
                        int64x1x3_t vecs); /* VST1.64 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_f32(__transfersize(6) float32_t * buf,
                        float32x2x3_t vecs); /* VST3.32 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_p8(__transfersize(24) poly8_t * buf,
                       poly8x8x3_t vecs); /* VST3.8 {d0, d1, d2}, [r0] */
__EXTERNC void vst3_p16(__transfersize(12) poly16_t * buf,
                        poly16x4x3_t vecs); /* VST3.16 {d0, d1, d2}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst3_f16(__transfersize(12) __fp16 * buf,
                        float16x4x3_t vecs); /* VST3.16 {d0, d1, d2}, [r0] */
#endif
__EXTERNC void vst4q_u8(__transfersize(64) uint8_t * buf,
                        uint8x16x4_t vecs); /* VST4.8 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_u16(__transfersize(32) uint16_t * buf,
                         uint16x8x4_t vecs); /* VST4.16 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_u32(__transfersize(16) uint32_t * buf,
                         uint32x4x4_t vecs); /* VST4.32 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_s8(__transfersize(64) int8_t * buf,
                        int8x16x4_t vecs); /* VST4.8 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_s16(__transfersize(32) int16_t * buf,
                         int16x8x4_t vecs); /* VST4.16 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_s32(__transfersize(16) int32_t * buf,
                         int32x4x4_t vecs); /* VST4.32 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_f32(__transfersize(16) float32_t * buf,
                         float32x4x4_t vecs); /* VST4.32 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_p8(__transfersize(64) poly8_t * buf,
                        poly8x16x4_t vecs); /* VST4.8 {d0, d2, d4, d6}, [r0] */
__EXTERNC void vst4q_p16(__transfersize(32) poly16_t * buf,
                         poly16x8x4_t vecs); /* VST4.16 {d0, d2, d4, d6}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst4q_f16(__transfersize(32) __fp16 * buf,
                         float16x8x4_t vecs); /* VST4.16 {d0, d2, d4, d6}, [r0] */
#endif
__EXTERNC void vst4_u8(__transfersize(32) uint8_t * buf,
                       uint8x8x4_t vecs); /* VST4.8 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_u16(__transfersize(16) uint16_t * buf,
                        uint16x4x4_t vecs); /* VST4.16 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_u32(__transfersize(8) uint32_t * buf,
                        uint32x2x4_t vecs); /* VST4.32 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_u64(__transfersize(4) uint64_t * buf,
                        uint64x1x4_t vecs); /* VST1.64 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_s8(__transfersize(32) int8_t * buf,
                       int8x8x4_t vecs); /* VST4.8 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_s16(__transfersize(16) int16_t * buf,
                        int16x4x4_t vecs); /* VST4.16 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_s32(__transfersize(8) int32_t * buf,
                        int32x2x4_t vecs); /* VST4.32 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_s64(__transfersize(4) int64_t * buf,
                        int64x1x4_t vecs); /* VST1.64 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_f32(__transfersize(8) float32_t * buf,
                        float32x2x4_t vecs); /* VST4.32 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_p8(__transfersize(32) poly8_t * buf,
                       poly8x8x4_t vecs); /* VST4.8 {d0, d1, d2, d3}, [r0] */
__EXTERNC void vst4_p16(__transfersize(16) poly16_t * buf,
                        poly16x4x4_t vecs); /* VST4.16 {d0, d1, d2, d3}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst4_f16(__transfersize(16) __fp16 * buf,
                        float16x4x4_t vecs); /* VST4.16 {d0, d1, d2, d3}, [r0] */
#endif
__EXTERNC void vst2q_lane_u16(__transfersize(2) uint16_t * buf,
                              uint16x8x2_t vec,
                              __constrange(0,7) int num); /* VST2.16 {d0[0], d2[0]}, [r0] */
__EXTERNC void vst2q_lane_u32(__transfersize(2) uint32_t * buf,
                              uint32x4x2_t vec,
                              __constrange(0,3) int num); /* VST2.32 {d0[0], d2[0]}, [r0] */
__EXTERNC void vst2q_lane_s16(__transfersize(2) int16_t * buf,
                              int16x8x2_t vec,
                              __constrange(0,7) int num); /* VST2.16 {d0[0], d2[0]}, [r0] */
__EXTERNC void vst2q_lane_s32(__transfersize(2) int32_t * buf,
                              int32x4x2_t vec,
                              __constrange(0,3) int num); /* VST2.32 {d0[0], d2[0]}, [r0] */
__EXTERNC void vst2q_lane_f32(__transfersize(2) float32_t * buf,
                              float32x4x2_t vec,
                              __constrange(0,3) int num); /* VST2.32 {d0[0], d2[0]}, [r0] */
__EXTERNC void vst2q_lane_p16(__transfersize(2) poly16_t * buf,
                              poly16x8x2_t vec,
                              __constrange(0,7) int num); /* VST2.16 {d0[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst2q_lane_f16(__transfersize(2) __fp16 * buf,
                              float16x8x2_t vec,
                              __constrange(0,7) int num); /* VST2.16 {d0[0], d2[0]}, [r0] */
#endif
__EXTERNC void vst2_lane_u8(__transfersize(2) uint8_t * buf,
                            uint8x8x2_t vec,
                            __constrange(0,7) int num); /* VST2.8 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_u16(__transfersize(2) uint16_t * buf,
                             uint16x4x2_t vec,
                             __constrange(0,3) int num); /* VST2.16 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_u32(__transfersize(2) uint32_t * buf,
                             uint32x2x2_t vec,
                             __constrange(0,1) int num); /* VST2.32 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_s8(__transfersize(2) int8_t * buf,
                            int8x8x2_t vec,
                            __constrange(0,7) int num); /* VST2.8 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_s16(__transfersize(2) int16_t * buf,
                             int16x4x2_t vec,
                             __constrange(0,3) int num); /* VST2.16 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_s32(__transfersize(2) int32_t * buf,
                             int32x2x2_t vec,
                             __constrange(0,1) int num); /* VST2.32 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_f32(__transfersize(2) float32_t * buf,
                             float32x2x2_t vec,
                             __constrange(0,1) int num); /* VST2.32 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_p8(__transfersize(2) poly8_t * buf,
                            poly8x8x2_t vec,
                            __constrange(0,7) int num); /* VST2.8 {d0[0], d1[0]}, [r0] */
__EXTERNC void vst2_lane_p16(__transfersize(2) poly16_t * buf,
                             poly16x4x2_t vec,
                             __constrange(0,3) int num); /* VST2.16 {d0[0], d1[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst2_lane_f16(__transfersize(2) __fp16 * buf,
                             float16x4x2_t vec,
                             __constrange(0,3) int num); /* VST2.16 {d0[0], d1[0]}, [r0] */
#endif
__EXTERNC void vst3q_lane_u16(__transfersize(3) uint16_t * buf,
                              uint16x8x3_t vec,
                              __constrange(0,7) int num); /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC void vst3q_lane_u32(__transfersize(3) uint32_t * buf,
                              uint32x4x3_t vec,
                              __constrange(0,3) int num); /* VST3.32 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC void vst3q_lane_s16(__transfersize(3) int16_t * buf,
                              int16x8x3_t vec,
                              __constrange(0,7) int num); /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC void vst3q_lane_s32(__transfersize(3) int32_t * buf,
                              int32x4x3_t vec,
                              __constrange(0,3) int num); /* VST3.32 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC void vst3q_lane_f32(__transfersize(3) float32_t * buf,
                              float32x4x3_t vec,
                              __constrange(0,3) int num); /* VST3.32 {d0[0], d2[0], d4[0]}, [r0] */
__EXTERNC void vst3q_lane_p16(__transfersize(3) poly16_t * buf,
                              poly16x8x3_t vec,
                              __constrange(0,7) int num); /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst3q_lane_f16(__transfersize(3) __fp16 * buf,
                              float16x8x3_t vec,
                              __constrange(0,7) int num); /* VST3.16 {d0[0], d2[0], d4[0]}, [r0] */
#endif
__EXTERNC void vst3_lane_u8(__transfersize(3) uint8_t * buf,
                            uint8x8x3_t vec,
                            __constrange(0,7) int num); /* VST3.8 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_u16(__transfersize(3) uint16_t * buf,
                             uint16x4x3_t vec,
                             __constrange(0,3) int num); /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_u32(__transfersize(3) uint32_t * buf,
                             uint32x2x3_t vec,
                             __constrange(0,1) int num); /* VST3.32 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_s8(__transfersize(3) int8_t * buf,
                            int8x8x3_t vec,
                            __constrange(0,7) int num); /* VST3.8 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_s16(__transfersize(3) int16_t * buf,
                             int16x4x3_t vec,
                             __constrange(0,3) int num); /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_s32(__transfersize(3) int32_t * buf,
                             int32x2x3_t vec,
                             __constrange(0,1) int num); /* VST3.32 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_f32(__transfersize(3) float32_t * buf,
                             float32x2x3_t vec,
                             __constrange(0,1) int num); /* VST3.32 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_p8(__transfersize(3) poly8_t * buf,
                            poly8x8x3_t vec,
                            __constrange(0,7) int num); /* VST3.8 {d0[0], d1[0], d2[0]}, [r0] */
__EXTERNC void vst3_lane_p16(__transfersize(3) poly16_t * buf,
                             poly16x4x3_t vec,
                             __constrange(0,3) int num); /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst3_lane_f16(__transfersize(3) __fp16 * buf,
                             float16x4x3_t vec,
                             __constrange(0,3) int num); /* VST3.16 {d0[0], d1[0], d2[0]}, [r0] */
#endif
__EXTERNC void vst4q_lane_u16(__transfersize(4) uint16_t * buf,
                              uint16x8x4_t vec,
                              __constrange(0,7) int num); /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC void vst4q_lane_u32(__transfersize(4) uint32_t * buf,
                              uint32x4x4_t vec,
                              __constrange(0,3) int num); /* VST4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC void vst4q_lane_s16(__transfersize(4) int16_t * buf,
                              int16x8x4_t vec,
                              __constrange(0,7) int num); /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC void vst4q_lane_s32(__transfersize(4) int32_t * buf,
                              int32x4x4_t vec,
                              __constrange(0,3) int num); /* VST4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC void vst4q_lane_f32(__transfersize(4) float32_t * buf,
                              float32x4x4_t vec,
                              __constrange(0,3) int num); /* VST4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
__EXTERNC void vst4q_lane_p16(__transfersize(4) poly16_t * buf,
                              poly16x8x4_t vec,
                              __constrange(0,7) int num); /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst4q_lane_f16(__transfersize(4) __fp16 * buf,
                              float16x8x4_t vec,
                              __constrange(0,7) int num); /* VST4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0] */
#endif
__EXTERNC void vst4_lane_u8(__transfersize(4) uint8_t * buf,
                            uint8x8x4_t vec,
                            __constrange(0,7) int num); /* VST4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_u16(__transfersize(4) uint16_t * buf,
                             uint16x4x4_t vec,
                             __constrange(0,3) int num); /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_u32(__transfersize(4) uint32_t * buf,
                             uint32x2x4_t vec,
                             __constrange(0,1) int num); /* VST4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_s8(__transfersize(4) int8_t * buf,
                            int8x8x4_t vec,
                            __constrange(0,7) int num); /* VST4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_s16(__transfersize(4) int16_t * buf,
                             int16x4x4_t vec,
                             __constrange(0,3) int num); /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_s32(__transfersize(4) int32_t * buf,
                             int32x2x4_t vec,
                             __constrange(0,1) int num); /* VST4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_f32(__transfersize(4) float32_t * buf,
                             float32x2x4_t vec,
                             __constrange(0,1) int num); /* VST4.32 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_p8(__transfersize(4) poly8_t * buf,
                            poly8x8x4_t vec,
                            __constrange(0,7) int num); /* VST4.8 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
__EXTERNC void vst4_lane_p16(__transfersize(4) poly16_t * buf,
                             poly16x4x4_t vec,
                             __constrange(0,3) int num); /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC void vst4_lane_f16(__transfersize(4) __fp16 * buf,
                             float16x4x4_t vec,
                             __constrange(0,3) int num); /* VST4.16 {d0[0], d1[0], d2[0], d3[0]}, [r0] */
#endif
__EXTERNC __PURE uint8_t vget_lane_u8(uint8x8_t vec,
                                      __constrange(0,7) int lane); /* VMOV.U8 r0, d0[0] */
__EXTERNC __PURE uint16_t vget_lane_u16(uint16x4_t vec,
                                        __constrange(0,3) int lane); /* VMOV.U16 r0, d0[0] */
__EXTERNC __PURE uint32_t vget_lane_u32(uint32x2_t vec,
                                        __constrange(0,1) int lane); /* VMOV.32 r0, d0[0] */
__EXTERNC __PURE int8_t vget_lane_s8(int8x8_t vec,
                                     __constrange(0,7) int lane); /* VMOV.S8 r0, d0[0] */
__EXTERNC __PURE int16_t vget_lane_s16(int16x4_t vec,
                                       __constrange(0,3) int lane); /* VMOV.S16 r0, d0[0] */
__EXTERNC __PURE int32_t vget_lane_s32(int32x2_t vec,
                                       __constrange(0,1) int lane); /* VMOV.32 r0, d0[0] */
__EXTERNC __PURE poly8_t vget_lane_p8(poly8x8_t vec,
                                      __constrange(0,7) int lane); /* VMOV.U8 r0, d0[0] */
__EXTERNC __PURE poly16_t vget_lane_p16(poly16x4_t vec,
                                        __constrange(0,3) int lane); /* VMOV.U16 r0, d0[0] */
__EXTERNC __PURE float32_t vget_lane_f32(float32x2_t vec,
                                         __constrange(0,1) int lane); /* VMOV.32 r0, d0[0] */
__EXTERNC __PURE uint8_t vgetq_lane_u8(uint8x16_t vec,
                                       __constrange(0,15) int lane); /* VMOV.U8 r0, d0[0] */
__EXTERNC __PURE uint16_t vgetq_lane_u16(uint16x8_t vec,
                                         __constrange(0,7) int lane); /* VMOV.U16 r0, d0[0] */
__EXTERNC __PURE uint32_t vgetq_lane_u32(uint32x4_t vec,
                                         __constrange(0,3) int lane); /* VMOV.32 r0, d0[0] */
__EXTERNC __PURE int8_t vgetq_lane_s8(int8x16_t vec,
                                      __constrange(0,15) int lane); /* VMOV.S8 r0, d0[0] */
__EXTERNC __PURE int16_t vgetq_lane_s16(int16x8_t vec,
                                        __constrange(0,7) int lane); /* VMOV.S16 r0, d0[0] */
__EXTERNC __PURE int32_t vgetq_lane_s32(int32x4_t vec,
                                        __constrange(0,3) int lane); /* VMOV.32 r0, d0[0] */
__EXTERNC __PURE poly8_t vgetq_lane_p8(poly8x16_t vec,
                                       __constrange(0,15) int lane); /* VMOV.U8 r0, d0[0] */
__EXTERNC __PURE poly16_t vgetq_lane_p16(poly16x8_t vec,
                                         __constrange(0,7) int lane); /* VMOV.U16 r0, d0[0] */
__EXTERNC __PURE float32_t vgetq_lane_f32(float32x4_t vec,
                                          __constrange(0,3) int lane); /* VMOV.32 r0, d0[0] */
__EXTERNC __PURE int64_t vget_lane_s64(int64x1_t vec,
                                       __constrange(0,0) int lane); /* VMOV r0,r0,d0 */
__EXTERNC __PURE uint64_t vget_lane_u64(uint64x1_t vec,
                                        __constrange(0,0) int lane); /* VMOV r0,r0,d0 */
__EXTERNC __PURE int64_t vgetq_lane_s64(int64x2_t vec,
                                        __constrange(0,1) int lane); /* VMOV r0,r0,d0 */
__EXTERNC __PURE uint64_t vgetq_lane_u64(uint64x2_t vec,
                                         __constrange(0,1) int lane); /* VMOV r0,r0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vset_lane_u8(uint8_t v,
                                                        uint8x8_t vec,
                                                        __constrange(0,7) int lane); /* VMOV.8 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vset_lane_u16(uint16_t v,
                                                          uint16x4_t vec,
                                                          __constrange(0,3) int lane); /* VMOV.16 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vset_lane_u32(uint32_t v,
                                                          uint32x2_t vec,
                                                          __constrange(0,1) int lane); /* VMOV.32 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vset_lane_s8(int8_t v,
                                                       int8x8_t vec,
                                                       __constrange(0,7) int lane); /* VMOV.8 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vset_lane_s16(int16_t v,
                                                         int16x4_t vec,
                                                         __constrange(0,3) int lane); /* VMOV.16 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vset_lane_s32(int32_t v,
                                                         int32x2_t vec,
                                                         __constrange(0,1) int lane); /* VMOV.32 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vset_lane_p8(poly8_t v,
                                                        poly8x8_t vec,
                                                        __constrange(0,7) int lane); /* VMOV.8 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vset_lane_p16(poly16_t v,
                                                          poly16x4_t vec,
                                                          __constrange(0,3) int lane); /* VMOV.16 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vset_lane_f32(float32_t v,
                                                           float32x2_t vec,
                                                           __constrange(0,1) int lane); /* VMOV.32 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vsetq_lane_u8(uint8_t v,
                                                          uint8x16_t vec,
                                                          __constrange(0,15) int lane); /* VMOV.8 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vsetq_lane_u16(uint16_t v,
                                                           uint16x8_t vec,
                                                           __constrange(0,7) int lane); /* VMOV.16 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vsetq_lane_u32(uint32_t v,
                                                           uint32x4_t vec,
                                                           __constrange(0,3) int lane); /* VMOV.32 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vsetq_lane_s8(int8_t v,
                                                         int8x16_t vec,
                                                         __constrange(0,15) int lane); /* VMOV.8 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vsetq_lane_s16(int16_t v,
                                                          int16x8_t vec,
                                                          __constrange(0,7) int lane); /* VMOV.16 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vsetq_lane_s32(int32_t v,
                                                          int32x4_t vec,
                                                          __constrange(0,3) int lane); /* VMOV.32 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vsetq_lane_p8(poly8_t v,
                                                          poly8x16_t vec,
                                                          __constrange(0,15) int lane); /* VMOV.8 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vsetq_lane_p16(poly16_t v,
                                                           poly16x8_t vec,
                                                           __constrange(0,7) int lane); /* VMOV.16 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vsetq_lane_f32(float32_t v,
                                                            float32x4_t vec,
                                                            __constrange(0,3) int lane); /* VMOV.32 d0[0],r0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vset_lane_s64(int64_t v,
                                                         int64x1_t vec,
                                                         __constrange(0,0) int lane); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vset_lane_u64(uint64_t v,
                                                          uint64x1_t vec,
                                                          __constrange(0,0) int lane); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vsetq_lane_s64(int64_t v,
                                                          int64x2_t vec,
                                                          __constrange(0,1) int lane); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vsetq_lane_u64(uint64_t v,
                                                           uint64x2_t vec,
                                                           __constrange(0,1) int lane); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vcreate_s8(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vcreate_s16(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vcreate_s32(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vcreate_f32(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcreate_u8(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vcreate_u16(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcreate_u32(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vcreate_u64(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vcreate_p8(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vcreate_p16(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vcreate_s64(uint64_t v); /* VMOV d0,r0,r0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vcreate_f16(uint64_t v); /* VMOV d0,r0,r0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vdup_n_u8(uint8_t v); /* VDUP.8 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vdup_n_u16(uint16_t v); /* VDUP.16 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vdup_n_u32(uint32_t v); /* VDUP.32 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vdup_n_s8(int8_t v); /* VDUP.8 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vdup_n_s16(int16_t v); /* VDUP.16 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vdup_n_s32(int32_t v); /* VDUP.32 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vdup_n_p8(poly8_t v); /* VDUP.8 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vdup_n_p16(poly16_t v); /* VDUP.16 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vdup_n_f32(float32_t v); /* VDUP.32 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vdupq_n_u8(uint8_t v); /* VDUP.8 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vdupq_n_u16(uint16_t v); /* VDUP.16 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vdupq_n_u32(uint32_t v); /* VDUP.32 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vdupq_n_s8(int8_t v); /* VDUP.8 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vdupq_n_s16(int16_t v); /* VDUP.16 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vdupq_n_s32(int32_t v); /* VDUP.32 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vdupq_n_p8(poly8_t v); /* VDUP.8 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vdupq_n_p16(poly16_t v); /* VDUP.16 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vdupq_n_f32(float32_t v); /* VDUP.32 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vdup_n_s64(int64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vdup_n_u64(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vdupq_n_s64(int64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vdupq_n_u64(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmov_n_u8(uint8_t v); /* VDUP.8 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmov_n_u16(uint16_t v); /* VDUP.16 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmov_n_u32(uint32_t v); /* VDUP.32 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmov_n_s8(int8_t v); /* VDUP.8 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmov_n_s16(int16_t v); /* VDUP.16 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmov_n_s32(int32_t v); /* VDUP.32 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vmov_n_p8(poly8_t v); /* VDUP.8 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vmov_n_p16(poly16_t v); /* VDUP.16 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmov_n_f32(float32_t v); /* VDUP.32 d0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vmovq_n_u8(uint8_t v); /* VDUP.8 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmovq_n_u16(uint16_t v); /* VDUP.16 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmovq_n_u32(uint32_t v); /* VDUP.32 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vmovq_n_s8(int8_t v); /* VDUP.8 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmovq_n_s16(int16_t v); /* VDUP.16 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmovq_n_s32(int32_t v); /* VDUP.32 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vmovq_n_p8(poly8_t v); /* VDUP.8 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vmovq_n_p16(poly16_t v); /* VDUP.16 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmovq_n_f32(float32_t v); /* VDUP.32 q0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vmov_n_s64(int64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vmov_n_u64(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmovq_n_s64(int64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmovq_n_u64(uint64_t v); /* VMOV d0,r0,r0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vdup_lane_u8(uint8x8_t v,
                                                        __constrange(0,7) int lane); /* VDUP.8 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vdup_lane_u16(uint16x4_t v,
                                                          __constrange(0,3) int lane); /* VDUP.16 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vdup_lane_u32(uint32x2_t v,
                                                          __constrange(0,1) int lane); /* VDUP.32 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vdup_lane_s8(int8x8_t v,
                                                       __constrange(0,7) int lane); /* VDUP.8 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vdup_lane_s16(int16x4_t v,
                                                         __constrange(0,3) int lane); /* VDUP.16 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vdup_lane_s32(int32x2_t v,
                                                         __constrange(0,1) int lane); /* VDUP.32 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vdup_lane_p8(poly8x8_t v,
                                                        __constrange(0,7) int lane); /* VDUP.8 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vdup_lane_p16(poly16x4_t v,
                                                          __constrange(0,3) int lane); /* VDUP.16 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vdup_lane_f32(float32x2_t v,
                                                           __constrange(0,1) int lane); /* VDUP.32 d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vdupq_lane_u8(uint8x8_t v,
                                                          __constrange(0,7) int lane); /* VDUP.8 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vdupq_lane_u16(uint16x4_t v,
                                                           __constrange(0,3) int lane); /* VDUP.16 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vdupq_lane_u32(uint32x2_t v,
                                                           __constrange(0,1) int lane); /* VDUP.32 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vdupq_lane_s8(int8x8_t v,
                                                         __constrange(0,7) int lane); /* VDUP.8 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vdupq_lane_s16(int16x4_t v,
                                                          __constrange(0,3) int lane); /* VDUP.16 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vdupq_lane_s32(int32x2_t v,
                                                          __constrange(0,1) int lane); /* VDUP.32 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vdupq_lane_p8(poly8x8_t v,
                                                          __constrange(0,7) int lane); /* VDUP.8 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vdupq_lane_p16(poly16x4_t v,
                                                           __constrange(0,3) int lane); /* VDUP.16 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vdupq_lane_f32(float32x2_t v,
                                                            __constrange(0,1) int lane); /* VDUP.32 q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vdup_lane_s64(int64x1_t v,
                                                         __constrange(0,0) int lane); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vdup_lane_u64(uint64x1_t v,
                                                          __constrange(0,0) int lane); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vdupq_lane_s64(int64x1_t v,
                                                          __constrange(0,0) int lane); /* VMOV q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vdupq_lane_u64(uint64x1_t v,
                                                           __constrange(0,0) int lane); /* VMOV q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vcombine_s8(int8x8_t vec1,
                                                       int8x8_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vcombine_s16(int16x4_t vec1,
                                                        int16x4_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vcombine_s32(int32x2_t vec1,
                                                        int32x2_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vcombine_s64(int64x1_t vec1,
                                                        int64x1_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vcombine_f32(float32x2_t vec1,
                                                          float32x2_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcombine_u8(uint8x8_t vec1,
                                                        uint8x8_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vcombine_u16(uint16x4_t vec1,
                                                         uint16x4_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcombine_u32(uint32x2_t vec1,
                                                         uint32x2_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vcombine_u64(uint64x1_t vec1,
                                                         uint64x1_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vcombine_p8(poly8x8_t vec1,
                                                        poly8x8_t vec2); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vcombine_p16(poly16x4_t vec1,
                                                         poly16x4_t vec2); /* VMOV d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vcombine_f16(float16x4_t vec1,
                                                          float16x4_t vec2); /* VMOV d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vget_high_s8(int8x16_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vget_high_s16(int16x8_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vget_high_s32(int32x4_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vget_high_s64(int64x2_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vget_high_f32(float32x4_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vget_high_u8(uint8x16_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vget_high_u16(uint16x8_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vget_high_u32(uint32x4_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vget_high_u64(uint64x2_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vget_high_p8(poly8x16_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vget_high_p16(poly16x8_t vec); /* VMOV d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vget_high_f16(float16x8_t vec); /* VMOV d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vget_low_s8(int8x16_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vget_low_s16(int16x8_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vget_low_s32(int32x4_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vget_low_s64(int64x2_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vget_low_f32(float32x4_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vget_low_u8(uint8x16_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vget_low_u16(uint16x8_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vget_low_u32(uint32x4_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vget_low_u64(uint64x2_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vget_low_p8(poly8x16_t vec); /* VMOV d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vget_low_p16(poly16x8_t vec); /* VMOV d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vget_low_f16(float16x8_t vec); /* VMOV d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vcvt_s32_f32(float32x2_t vec); /* VCVT.S32.F32 d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcvt_u32_f32(float32x2_t vec); /* VCVT.U32.F32 d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vcvtq_s32_f32(float32x4_t vec); /* VCVT.S32.F32 q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcvtq_u32_f32(float32x4_t vec); /* VCVT.U32.F32 q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vcvt_n_s32_f32(float32x2_t vec1,
                                                          __constrange(1,32) int val2); /* VCVT.S32.F32 d0, d0, #32 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vcvt_n_u32_f32(float32x2_t vec1,
                                                           __constrange(1,32) int val2); /* VCVT.U32.F32 d0, d0, #32 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vcvtq_n_s32_f32(float32x4_t vec1,
                                                           __constrange(1,32) int val2); /* VCVT.S32.F32 q0, q0, #32 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vcvtq_n_u32_f32(float32x4_t vec1,
                                                            __constrange(1,32) int val2); /* VCVT.U32.F32 q0, q0, #32 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vcvt_f32_s32(int32x2_t vec); /* VCVT.F32.S32 d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vcvt_f32_u32(uint32x2_t vec); /* VCVT.F32.U32 d0, d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vcvtq_f32_s32(int32x4_t vec); /* VCVT.F32.S32 q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vcvtq_f32_u32(uint32x4_t vec); /* VCVT.F32.U32 q0, q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vcvt_n_f32_s32(int32x2_t vec1,
                                                            __constrange(1,32) int val2); /* VCVT.F32.S32 d0, d0, #32 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vcvt_n_f32_u32(uint32x2_t vec1,
                                                            __constrange(1,32) int val2); /* VCVT.F32.U32 d0, d0, #32 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vcvtq_n_f32_s32(int32x4_t vec1,
                                                             __constrange(1,32) int val2); /* VCVT.F32.S32 q0, q0, #32 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vcvtq_n_f32_u32(uint32x4_t vec1,
                                                             __constrange(1,32) int val2); /* VCVT.F32.U32 q0, q0, #32 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vcvt_f16_f32(float32x4_t vec); /* VCVT.F16.F32 d0, q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vcvt_f32_f16(float16x4_t vec); /* VCVT.F32.F16 q0, d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmovn_s16(int16x8_t vec); /* VMOVN.I16 d0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmovn_s32(int32x4_t vec); /* VMOVN.I32 d0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmovn_s64(int64x2_t vec); /* VMOVN.I64 d0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmovn_u16(uint16x8_t vec); /* VMOVN.I16 d0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmovn_u32(uint32x4_t vec); /* VMOVN.I32 d0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmovn_u64(uint64x2_t vec); /* VMOVN.I64 d0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmovl_s8(int8x8_t vec); /* VMOVL.S8 q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmovl_s16(int16x4_t vec); /* VMOVL.S16 q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmovl_s32(int32x2_t vec); /* VMOVL.S32 q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmovl_u8(uint8x8_t vec); /* VMOVL.U8 q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmovl_u16(uint16x4_t vec); /* VMOVL.U16 q0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmovl_u32(uint32x2_t vec); /* VMOVL.U32 q0,d0 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqmovn_s16(int16x8_t vec); /* VQMOVN.S16 d0,q0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqmovn_s32(int32x4_t vec); /* VQMOVN.S32 d0,q0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqmovn_s64(int64x2_t vec); /* VQMOVN.S64 d0,q0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqmovn_u16(uint16x8_t vec); /* VQMOVN.U16 d0,q0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqmovn_u32(uint32x4_t vec); /* VQMOVN.U32 d0,q0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqmovn_u64(uint64x2_t vec); /* VQMOVN.U64 d0,q0 */
__EXTERNC __VALUE_IN_REGS uint8x8_t vqmovun_s16(int16x8_t vec); /* VQMOVUN.S16 d0,q0 */
__EXTERNC __VALUE_IN_REGS uint16x4_t vqmovun_s32(int32x4_t vec); /* VQMOVUN.S32 d0,q0 */
__EXTERNC __VALUE_IN_REGS uint32x2_t vqmovun_s64(int64x2_t vec); /* VQMOVUN.S64 d0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbl1_u8(uint8x8_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbl1_s8(int8x8_t list,
                                                   int8x8_t indexarr); /* VTBL.8 d0, {d0}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbl1_p8(poly8x8_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbl2_u8(uint8x8x2_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0, d1}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbl2_s8(int8x8x2_t list,
                                                   int8x8_t indexarr); /* VTBL.8 d0, {d0, d1}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbl2_p8(poly8x8x2_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0, d1}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbl3_u8(uint8x8x3_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0, d1, d2}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbl3_s8(int8x8x3_t list,
                                                   int8x8_t indexarr); /* VTBL.8 d0, {d0, d1, d2}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbl3_p8(poly8x8x3_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0, d1, d2}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbl4_u8(uint8x8x4_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0, d1, d2, d3}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbl4_s8(int8x8x4_t list,
                                                   int8x8_t indexarr); /* VTBL.8 d0, {d0, d1, d2, d3}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbl4_p8(poly8x8x4_t list,
                                                    uint8x8_t indexarr); /* VTBL.8 d0, {d0, d1, d2, d3}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbx1_u8(uint8x8_t defaults,
                                                    uint8x8_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbx1_s8(int8x8_t defaults,
                                                   int8x8_t list,
                                                   int8x8_t indexarr); /* VTBX.8 d0, {d0}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbx1_p8(poly8x8_t defaults,
                                                    poly8x8_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbx2_u8(uint8x8_t defaults,
                                                    uint8x8x2_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0, d1}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbx2_s8(int8x8_t defaults,
                                                   int8x8x2_t list,
                                                   int8x8_t indexarr); /* VTBX.8 d0, {d0, d1}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbx2_p8(poly8x8_t defaults,
                                                    poly8x8x2_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0, d1}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbx3_u8(uint8x8_t defaults,
                                                    uint8x8x3_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0, d1, d2}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbx3_s8(int8x8_t defaults,
                                                   int8x8x3_t list,
                                                   int8x8_t indexarr); /* VTBX.8 d0, {d0, d1, d2}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbx3_p8(poly8x8_t defaults,
                                                    poly8x8x3_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0, d1, d2}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vtbx4_u8(uint8x8_t defaults,
                                                    uint8x8x4_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0, d1, d2, d3}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vtbx4_s8(int8x8_t defaults,
                                                   int8x8x4_t list,
                                                   int8x8_t indexarr); /* VTBX.8 d0, {d0, d1, d2, d3}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vtbx4_p8(poly8x8_t defaults,
                                                    poly8x8x4_t list,
                                                    uint8x8_t indexarr); /* VTBX.8 d0, {d0, d1, d2, d3}, d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmla_n_s16(int16x4_t vec1,
                                                      int16x4_t vec2,
                                                      int16_t val3); /* VMLA.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmla_n_s32(int32x2_t vec1,
                                                      int32x2_t vec2,
                                                      int32_t val3); /* VMLA.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmla_n_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2,
                                                       uint16_t val3); /* VMLA.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmla_n_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2,
                                                       uint32_t val3); /* VMLA.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlaq_n_s16(int16x8_t vec1,
                                                       int16x8_t vec2,
                                                       int16_t val3); /* VMLA.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlaq_n_s32(int32x4_t vec1,
                                                       int32x4_t vec2,
                                                       int32_t val3); /* VMLA.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlaq_n_u16(uint16x8_t vec1,
                                                        uint16x8_t vec2,
                                                        uint16_t val3); /* VMLA.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlaq_n_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2,
                                                        uint32_t val3); /* VMLA.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmla_n_f32(float32x2_t vec1,
                                                        float32x2_t vec2,
                                                        float32_t val3); /* VMLA.F32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmlaq_n_f32(float32x4_t vec1,
                                                         float32x4_t vec2,
                                                         float32_t val3); /* VMLA.F32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlal_n_s16(int32x4_t vec1,
                                                       int16x4_t vec2,
                                                       int16_t val3); /* VMLAL.S16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmlal_n_s32(int64x2_t vec1,
                                                       int32x2_t vec2,
                                                       int32_t val3); /* VMLAL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlal_n_u16(uint32x4_t vec1,
                                                        uint16x4_t vec2,
                                                        uint16_t val3); /* VMLAL.U16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmlal_n_u32(uint64x2_t vec1,
                                                        uint32x2_t vec2,
                                                        uint32_t val3); /* VMLAL.U32 q0, d0, d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmlal_n_s16(int32x4_t vec1,
                                                  int16x4_t vec2,
                                                  int16_t val3); /* VQDMLAL.S16 q0, d0, d0[0] */
__EXTERNC __VALUE_IN_REGS int64x2_t vqdmlal_n_s32(int64x2_t vec1,
                                                  int32x2_t vec2,
                                                  int32_t val3); /* VQDMLAL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmls_n_s16(int16x4_t vec1,
                                                      int16x4_t vec2,
                                                      int16_t val3); /* VMLS.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmls_n_s32(int32x2_t vec1,
                                                      int32x2_t vec2,
                                                      int32_t val3); /* VMLS.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmls_n_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2,
                                                       uint16_t val3); /* VMLS.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmls_n_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2,
                                                       uint32_t val3); /* VMLS.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlsq_n_s16(int16x8_t vec1,
                                                       int16x8_t vec2,
                                                       int16_t val3); /* VMLS.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlsq_n_s32(int32x4_t vec1,
                                                       int32x4_t vec2,
                                                       int32_t val3); /* VMLS.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlsq_n_u16(uint16x8_t vec1,
                                                        uint16x8_t vec2,
                                                        uint16_t val3); /* VMLS.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlsq_n_u32(uint32x4_t vec1,
                                                        uint32x4_t vec2,
                                                        uint32_t val3); /* VMLS.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmls_n_f32(float32x2_t vec1,
                                                        float32x2_t vec2,
                                                        float32_t val3); /* VMLS.F32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmlsq_n_f32(float32x4_t vec1,
                                                         float32x4_t vec2,
                                                         float32_t val3); /* VMLS.F32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlsl_n_s16(int32x4_t vec1,
                                                       int16x4_t vec2,
                                                       int16_t val3); /* VMLSL.S16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmlsl_n_s32(int64x2_t vec1,
                                                       int32x2_t vec2,
                                                       int32_t val3); /* VMLSL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlsl_n_u16(uint32x4_t vec1,
                                                        uint16x4_t vec2,
                                                        uint16_t val3); /* VMLSL.U16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmlsl_n_u32(uint64x2_t vec1,
                                                        uint32x2_t vec2,
                                                        uint32_t val3); /* VMLSL.U32 q0, d0, d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmlsl_n_s16(int32x4_t vec1,
                                                  int16x4_t vec2,
                                                  int16_t val3); /* VQDMLSL.S16 q0, d0, d0[0] */
__EXTERNC __VALUE_IN_REGS int64x2_t vqdmlsl_n_s32(int64x2_t vec1,
                                                  int32x2_t vec2,
                                                  int32_t val3); /* VQDMLSL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmul_n_s16(int16x4_t vec1,
                                                      int16_t val2); /* VMUL.I16 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmul_n_s32(int32x2_t vec1,
                                                      int32_t val2); /* VMUL.I32 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmul_n_f32(float32x2_t vec1,
                                                        float32_t val2); /* VMUL.F32 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmul_n_u16(uint16x4_t vec1,
                                                       uint16_t val2); /* VMUL.I16 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmul_n_u32(uint32x2_t vec1,
                                                       uint32_t val2); /* VMUL.I32 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmulq_n_s16(int16x8_t vec1,
                                                       int16_t val2); /* VMUL.I16 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmulq_n_s32(int32x4_t vec1,
                                                       int32_t val2); /* VMUL.I32 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmulq_n_f32(float32x4_t vec1,
                                                         float32_t val2); /* VMUL.F32 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmulq_n_u16(uint16x8_t vec1,
                                                        uint16_t val2); /* VMUL.I16 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmulq_n_u32(uint32x4_t vec1,
                                                        uint32_t val2); /* VMUL.I32 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmull_n_s16(int16x4_t vec1,
                                                       int16_t val2); /* VMULL.S16 q0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmull_n_s32(int32x2_t vec1,
                                                       int32_t val2); /* VMULL.S32 q0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmull_n_u16(uint16x4_t vec1,
                                                        uint16_t val2); /* VMULL.U16 q0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmull_n_u32(uint32x2_t vec1,
                                                        uint32_t val2); /* VMULL.U32 q0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmull_n_s16(int16x4_t vec1,
                                                  int16_t val2); /* VQDMULL.S16 q0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int64x2_t vqdmull_n_s32(int32x2_t vec1,
                                                  int32_t val2); /* VQDMULL.S32 q0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmull_lane_s16(int16x4_t vec1,
                                                     int16x4_t vec2,
                                                     __constrange(0,3) int lane); /* VQDMULL.S16 q0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int64x2_t vqdmull_lane_s32(int32x2_t vec1,
                                                     int32x2_t vec2,
                                                     __constrange(0,1) int lane); /* VQDMULL.S32 q0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x4_t vqdmulh_n_s16(int16x4_t vec1,
                                                  int16_t val2); /* VQDMULH.S16 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x2_t vqdmulh_n_s32(int32x2_t vec1,
                                                  int32_t val2); /* VQDMULH.S32 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x8_t vqdmulhq_n_s16(int16x8_t vec1,
                                                   int16_t val2); /* VQDMULH.S16 q0,q0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmulhq_n_s32(int32x4_t vec1,
                                                   int32_t val2); /* VQDMULH.S32 q0,q0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x4_t vqdmulh_lane_s16(int16x4_t vec1,
                                                     int16x4_t vec2,
                                                     __constrange(0,3) int lane); /* VQDMULH.S16 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x2_t vqdmulh_lane_s32(int32x2_t vec1,
                                                     int32x2_t vec2,
                                                     __constrange(0,1) int lane); /* VQDMULH.S32 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x8_t vqdmulhq_lane_s16(int16x8_t vec1,
                                                      int16x4_t vec2,
                                                      __constrange(0,3) int lane); /* VQDMULH.S16 q0,q0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqdmulhq_lane_s32(int32x4_t vec1,
                                                      int32x2_t vec2,
                                                      __constrange(0,1) int lane); /* VQDMULH.S32 q0,q0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x4_t vqrdmulh_n_s16(int16x4_t vec1,
                                                   int16_t val2); /* VQRDMULH.S16 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x2_t vqrdmulh_n_s32(int32x2_t vec1,
                                                   int32_t val2); /* VQRDMULH.S32 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x8_t vqrdmulhq_n_s16(int16x8_t vec1,
                                                    int16_t val2); /* VQRDMULH.S16 q0,q0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqrdmulhq_n_s32(int32x4_t vec1,
                                                    int32_t val2); /* VQRDMULH.S32 q0,q0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x4_t vqrdmulh_lane_s16(int16x4_t vec1,
                                                      int16x4_t vec2,
                                                      __constrange(0,3) int lane); /* VQRDMULH.S16 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x2_t vqrdmulh_lane_s32(int32x2_t vec1,
                                                      int32x2_t vec2,
                                                      __constrange(0,1) int lane); /* VQRDMULH.S32 d0,d0,d0[0] */
__EXTERNC __VALUE_IN_REGS int16x8_t vqrdmulhq_lane_s16(int16x8_t vec1,
                                                       int16x4_t vec2,
                                                       __constrange(0,3) int lane); /* VQRDMULH.S16 q0,q0,d0[0] */
__EXTERNC __VALUE_IN_REGS int32x4_t vqrdmulhq_lane_s32(int32x4_t vec1,
                                                       int32x2_t vec2,
                                                       __constrange(0,1) int lane); /* VQRDMULH.S32 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmla_lane_s16(int16x4_t vec1,
                                                         int16x4_t vec2,
                                                         int16x4_t val3,
                                                         __constrange(0,3) int val4); /* VMLA.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmla_lane_s32(int32x2_t vec1,
                                                         int32x2_t vec2,
                                                         int32x2_t val3,
                                                         __constrange(0,1) int val4); /* VMLA.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmla_lane_u16(uint16x4_t vec1,
                                                          uint16x4_t vec2,
                                                          uint16x4_t val3,
                                                          __constrange(0,3) int val4); /* VMLA.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmla_lane_u32(uint32x2_t vec1,
                                                          uint32x2_t vec2,
                                                          uint32x2_t val3,
                                                          __constrange(0,1) int val4); /* VMLA.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmla_lane_f32(float32x2_t vec1,
                                                           float32x2_t vec2,
                                                           float32x2_t val3,
                                                           __constrange(0,1) int val4); /* VMLA.F32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlaq_lane_s16(int16x8_t vec1,
                                                          int16x8_t vec2,
                                                          int16x4_t val3,
                                                          __constrange(0,3) int val4); /* VMLA.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlaq_lane_s32(int32x4_t vec1,
                                                          int32x4_t vec2,
                                                          int32x2_t val3,
                                                          __constrange(0,1) int val4); /* VMLA.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlaq_lane_u16(uint16x8_t vec1,
                                                           uint16x8_t vec2,
                                                           uint16x4_t val3,
                                                           __constrange(0,3) int val4); /* VMLA.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlaq_lane_u32(uint32x4_t vec1,
                                                           uint32x4_t vec2,
                                                           uint32x2_t val3,
                                                           __constrange(0,1) int val4); /* VMLA.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmlaq_lane_f32(float32x4_t vec1,
                                                            float32x4_t vec2,
                                                            float32x2_t val3,
                                                            __constrange(0,1) int val4); /* VMLA.F32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlal_lane_s16(int32x4_t vec1,
                                                          int16x4_t vec2,
                                                          int16x4_t val3,
                                                          __constrange(0,3) int val4); /* VMLAL.S16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmlal_lane_s32(int64x2_t vec1,
                                                          int32x2_t vec2,
                                                          int32x2_t val3,
                                                          __constrange(0,1) int val4); /* VMLAL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlal_lane_u16(uint32x4_t vec1,
                                                           uint16x4_t vec2,
                                                           uint16x4_t val3,
                                                           __constrange(0,3) int val4); /* VMLAL.U16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmlal_lane_u32(uint64x2_t vec1,
                                                           uint32x2_t vec2,
                                                           uint32x2_t val3,
                                                           __constrange(0,1) int val4); /* VMLAL.U32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vqdmlal_lane_s16(int32x4_t vec1,
                                                            int16x4_t vec2,
                                                            int16x4_t val3,
                                                            __constrange(0,3) int val4); /* VQDMLAL.S16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vqdmlal_lane_s32(int64x2_t vec1,
                                                            int32x2_t vec2,
                                                            int32x2_t val3,
                                                            __constrange(0,1) int val4); /* VQDMLAL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmls_lane_s16(int16x4_t vec1,
                                                         int16x4_t vec2,
                                                         int16x4_t val3,
                                                         __constrange(0,3) int val4); /* VMLS.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmls_lane_s32(int32x2_t vec1,
                                                         int32x2_t vec2,
                                                         int32x2_t val3,
                                                         __constrange(0,1) int val4); /* VMLS.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmls_lane_u16(uint16x4_t vec1,
                                                          uint16x4_t vec2,
                                                          uint16x4_t val3,
                                                          __constrange(0,3) int val4); /* VMLS.I16 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmls_lane_u32(uint32x2_t vec1,
                                                          uint32x2_t vec2,
                                                          uint32x2_t val3,
                                                          __constrange(0,1) int val4); /* VMLS.I32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmls_lane_f32(float32x2_t vec1,
                                                           float32x2_t vec2,
                                                           float32x2_t val3,
                                                           __constrange(0,1) int val4); /* VMLS.F32 d0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmlsq_lane_s16(int16x8_t vec1,
                                                          int16x8_t vec2,
                                                          int16x4_t val3,
                                                          __constrange(0,3) int val4); /* VMLS.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlsq_lane_s32(int32x4_t vec1,
                                                          int32x4_t vec2,
                                                          int32x2_t val3,
                                                          __constrange(0,1) int val4); /* VMLS.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmlsq_lane_u16(uint16x8_t vec1,
                                                           uint16x8_t vec2,
                                                           uint16x4_t val3,
                                                           __constrange(0,3) int val4); /* VMLS.I16 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlsq_lane_u32(uint32x4_t vec1,
                                                           uint32x4_t vec2,
                                                           uint32x2_t val3,
                                                           __constrange(0,1) int val4); /* VMLS.I32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmlsq_lane_f32(float32x4_t vec1,
                                                            float32x4_t vec2,
                                                            float32x2_t val3,
                                                            __constrange(0,1) int val4); /* VMLS.F32 q0, q0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmlsl_lane_s16(int32x4_t vec1,
                                                          int16x4_t vec2,
                                                          int16x4_t val3,
                                                          __constrange(0,3) int val4); /* VMLSL.S16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmlsl_lane_s32(int64x2_t vec1,
                                                          int32x2_t vec2,
                                                          int32x2_t val3,
                                                          __constrange(0,1) int val4); /* VMLSL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmlsl_lane_u16(uint32x4_t vec1,
                                                           uint16x4_t vec2,
                                                           uint16x4_t val3,
                                                           __constrange(0,3) int val4); /* VMLSL.U16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmlsl_lane_u32(uint64x2_t vec1,
                                                           uint32x2_t vec2,
                                                           uint32x2_t val3,
                                                           __constrange(0,1) int val4); /* VMLSL.U32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vqdmlsl_lane_s16(int32x4_t vec1,
                                                            int16x4_t vec2,
                                                            int16x4_t val3,
                                                            __constrange(0,3) int val4); /* VQDMLSL.S16 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vqdmlsl_lane_s32(int64x2_t vec1,
                                                            int32x2_t vec2,
                                                            int32x2_t val3,
                                                            __constrange(0,1) int val4); /* VQDMLSL.S32 q0, d0, d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmull_lane_s16(int16x4_t vec1,
                                                          int16x4_t vec2,
                                                          __constrange(0,3) int lane); /* VMULL.S16 q0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vmull_lane_s32(int32x2_t vec1,
                                                          int32x2_t vec2,
                                                          __constrange(0,1) int lane); /* VMULL.S32 q0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmull_lane_u16(uint16x4_t vec1,
                                                           uint16x4_t vec2,
                                                           __constrange(0,3) int lane); /* VMULL.U16 q0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vmull_lane_u32(uint32x2_t vec1,
                                                           uint32x2_t vec2,
                                                           __constrange(0,1) int lane); /* VMULL.U32 q0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmul_lane_s16(int16x4_t vec1,
                                                         int16x4_t vec2,
                                                         __constrange(0,3) int lane); /* VMUL.I16 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmul_lane_s32(int32x2_t vec1,
                                                         int32x2_t vec2,
                                                         __constrange(0,1) int lane); /* VMUL.I32 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vmul_lane_f32(float32x2_t vec1,
                                                           float32x2_t vec2,
                                                           __constrange(0,1) int lane); /* VMUL.F32 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmul_lane_u16(uint16x4_t vec1,
                                                          uint16x4_t vec2,
                                                          __constrange(0,3) int lane); /* VMUL.I16 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmul_lane_u32(uint32x2_t vec1,
                                                          uint32x2_t vec2,
                                                          __constrange(0,1) int lane); /* VMUL.I32 d0,d0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmulq_lane_s16(int16x8_t vec1,
                                                          int16x4_t vec2,
                                                          __constrange(0,3) int lane); /* VMUL.I16 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmulq_lane_s32(int32x4_t vec1,
                                                          int32x2_t vec2,
                                                          __constrange(0,1) int lane); /* VMUL.I32 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vmulq_lane_f32(float32x4_t vec1,
                                                            float32x2_t vec2,
                                                            __constrange(0,1) int lane); /* VMUL.F32 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmulq_lane_u16(uint16x8_t vec1,
                                                           uint16x4_t vec2,
                                                           __constrange(0,3) int lane); /* VMUL.I16 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmulq_lane_u32(uint32x4_t vec1,
                                                           uint32x2_t vec2,
                                                           __constrange(0,1) int lane); /* VMUL.I32 q0,q0,d0[0] */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vext_s8(int8x8_t vec1,
                                                  int8x8_t vec2,
                                                  __constrange(0,7) int num); /* VEXT.8 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vext_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2,
                                                   __constrange(0,7) int num); /* VEXT.8 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vext_p8(poly8x8_t vec1,
                                                   poly8x8_t vec2,
                                                   __constrange(0,7) int num); /* VEXT.8 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vext_s16(int16x4_t vec1,
                                                    int16x4_t vec2,
                                                    __constrange(0,3) int num); /* VEXT.16 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vext_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2,
                                                     __constrange(0,3) int num); /* VEXT.16 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vext_p16(poly16x4_t vec1,
                                                     poly16x4_t vec2,
                                                     __constrange(0,3) int num); /* VEXT.16 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vext_s32(int32x2_t vec1,
                                                    int32x2_t vec2,
                                                    __constrange(0,1) int num); /* VEXT.32 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vext_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2,
                                                     __constrange(0,1) int num); /* VEXT.32 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vext_f32(float32x2_t vec1,
                                                      float32x2_t vec2,
                                                      __constrange(0,1) int num); /* VEXT.32 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vext_s64(int64x1_t vec1,
                                                    int64x1_t vec2,
                                                    __constrange(0,0) int num); /* VEXT.64 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vext_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2,
                                                     __constrange(0,0) int num); /* VEXT.64 d0,d0,d0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vextq_s8(int8x16_t vec1,
                                                    int8x16_t vec2,
                                                    __constrange(0,15) int num); /* VEXT.8 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vextq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2,
                                                     __constrange(0,15) int num); /* VEXT.8 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vextq_p8(poly8x16_t vec1,
                                                     poly8x16_t vec2,
                                                     __constrange(0,15) int num); /* VEXT.8 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vextq_s16(int16x8_t vec1,
                                                     int16x8_t vec2,
                                                     __constrange(0,7) int num); /* VEXT.16 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vextq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2,
                                                      __constrange(0,7) int num); /* VEXT.16 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vextq_p16(poly16x8_t vec1,
                                                      poly16x8_t vec2,
                                                      __constrange(0,7) int num); /* VEXT.16 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vextq_s32(int32x4_t vec1,
                                                     int32x4_t vec2,
                                                     __constrange(0,3) int num); /* VEXT.32 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vextq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2,
                                                      __constrange(0,3) int num); /* VEXT.32 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vextq_f32(float32x4_t vec1,
                                                       float32x4_t vec2,
                                                       __constrange(0,3) int num); /* VEXT.32 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vextq_s64(int64x2_t vec1,
                                                     int64x2_t vec2,
                                                     __constrange(0,1) int num); /* VEXT.64 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vextq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2,
                                                      __constrange(0,1) int num); /* VEXT.64 q0,q0,q0,#0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrev64_s8(int8x8_t vec); /* VREV64.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrev64_s16(int16x4_t vec); /* VREV64.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vrev64_s32(int32x2_t vec); /* VREV64.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrev64_u8(uint8x8_t vec); /* VREV64.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrev64_u16(uint16x4_t vec); /* VREV64.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrev64_u32(uint32x2_t vec); /* VREV64.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vrev64_p8(poly8x8_t vec); /* VREV64.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vrev64_p16(poly16x4_t vec); /* VREV64.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vrev64_f32(float32x2_t vec); /* VREV64.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vrev64q_s8(int8x16_t vec); /* VREV64.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vrev64q_s16(int16x8_t vec); /* VREV64.16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vrev64q_s32(int32x4_t vec); /* VREV64.32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vrev64q_u8(uint8x16_t vec); /* VREV64.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vrev64q_u16(uint16x8_t vec); /* VREV64.16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vrev64q_u32(uint32x4_t vec); /* VREV64.32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vrev64q_p8(poly8x16_t vec); /* VREV64.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vrev64q_p16(poly16x8_t vec); /* VREV64.16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vrev64q_f32(float32x4_t vec); /* VREV64.32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrev32_s8(int8x8_t vec); /* VREV32.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vrev32_s16(int16x4_t vec); /* VREV32.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrev32_u8(uint8x8_t vec); /* VREV32.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vrev32_u16(uint16x4_t vec); /* VREV32.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vrev32_p8(poly8x8_t vec); /* VREV32.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vrev32_p16(poly16x4_t vec); /* VREV32.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vrev32q_s8(int8x16_t vec); /* VREV32.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vrev32q_s16(int16x8_t vec); /* VREV32.16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vrev32q_u8(uint8x16_t vec); /* VREV32.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vrev32q_u16(uint16x8_t vec); /* VREV32.16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vrev32q_p8(poly8x16_t vec); /* VREV32.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vrev32q_p16(poly16x8_t vec); /* VREV32.16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vrev16_s8(int8x8_t vec); /* VREV16.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vrev16_u8(uint8x8_t vec); /* VREV16.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vrev16_p8(poly8x8_t vec); /* VREV16.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vrev16q_s8(int8x16_t vec); /* VREV16.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vrev16q_u8(uint8x16_t vec); /* VREV16.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vrev16q_p8(poly8x16_t vec); /* VREV16.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vabs_s8(int8x8_t vec); /* VABS.S8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vabs_s16(int16x4_t vec); /* VABS.S16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vabs_s32(int32x2_t vec); /* VABS.S32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vabs_f32(float32x2_t vec); /* VABS.F32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vabsq_s8(int8x16_t vec); /* VABS.S8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vabsq_s16(int16x8_t vec); /* VABS.S16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vabsq_s32(int32x4_t vec); /* VABS.S32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vabsq_f32(float32x4_t vec); /* VABS.F32 q0,q0 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqabs_s8(int8x8_t vec); /* VQABS.S8 d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqabs_s16(int16x4_t vec); /* VQABS.S16 d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqabs_s32(int32x2_t vec); /* VQABS.S32 d0,d0 */
__EXTERNC __VALUE_IN_REGS int8x16_t vqabsq_s8(int8x16_t vec); /* VQABS.S8 q0,q0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqabsq_s16(int16x8_t vec); /* VQABS.S16 q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqabsq_s32(int32x4_t vec); /* VQABS.S32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vneg_s8(int8x8_t vec); /* VNEG.S8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vneg_s16(int16x4_t vec); /* VNEG.S16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vneg_s32(int32x2_t vec); /* VNEG.S32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vneg_f32(float32x2_t vec); /* VNEG.F32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vnegq_s8(int8x16_t vec); /* VNEG.S8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vnegq_s16(int16x8_t vec); /* VNEG.S16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vnegq_s32(int32x4_t vec); /* VNEG.S32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vnegq_f32(float32x4_t vec); /* VNEG.F32 q0,q0 */
__EXTERNC __VALUE_IN_REGS int8x8_t vqneg_s8(int8x8_t vec); /* VQNEG.S8 d0,d0 */
__EXTERNC __VALUE_IN_REGS int16x4_t vqneg_s16(int16x4_t vec); /* VQNEG.S16 d0,d0 */
__EXTERNC __VALUE_IN_REGS int32x2_t vqneg_s32(int32x2_t vec); /* VQNEG.S32 d0,d0 */
__EXTERNC __VALUE_IN_REGS int8x16_t vqnegq_s8(int8x16_t vec); /* VQNEG.S8 q0,q0 */
__EXTERNC __VALUE_IN_REGS int16x8_t vqnegq_s16(int16x8_t vec); /* VQNEG.S16 q0,q0 */
__EXTERNC __VALUE_IN_REGS int32x4_t vqnegq_s32(int32x4_t vec); /* VQNEG.S32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vcls_s8(int8x8_t vec); /* VCLS.S8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vcls_s16(int16x4_t vec); /* VCLS.S16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vcls_s32(int32x2_t vec); /* VCLS.S32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vclsq_s8(int8x16_t vec); /* VCLS.S8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vclsq_s16(int16x8_t vec); /* VCLS.S16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vclsq_s32(int32x4_t vec); /* VCLS.S32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vclz_s8(int8x8_t vec); /* VCLZ.I8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vclz_s16(int16x4_t vec); /* VCLZ.I16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vclz_s32(int32x2_t vec); /* VCLZ.I32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vclz_u8(uint8x8_t vec); /* VCLZ.I8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vclz_u16(uint16x4_t vec); /* VCLZ.I16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vclz_u32(uint32x2_t vec); /* VCLZ.I32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vclzq_s8(int8x16_t vec); /* VCLZ.I8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vclzq_s16(int16x8_t vec); /* VCLZ.I16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vclzq_s32(int32x4_t vec); /* VCLZ.I32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vclzq_u8(uint8x16_t vec); /* VCLZ.I8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vclzq_u16(uint16x8_t vec); /* VCLZ.I16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vclzq_u32(uint32x4_t vec); /* VCLZ.I32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vcnt_u8(uint8x8_t vec); /* VCNT.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vcnt_s8(int8x8_t vec); /* VCNT.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vcnt_p8(poly8x8_t vec); /* VCNT.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vcntq_u8(uint8x16_t vec); /* VCNT.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vcntq_s8(int8x16_t vec); /* VCNT.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vcntq_p8(poly8x16_t vec); /* VCNT.8 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vrecpe_f32(float32x2_t vec); /* VRECPE.F32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrecpe_u32(uint32x2_t vec); /* VRECPE.U32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vrecpeq_f32(float32x4_t vec); /* VRECPE.F32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vrecpeq_u32(uint32x4_t vec); /* VRECPE.U32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vrsqrte_f32(float32x2_t vec); /* VRSQRTE.F32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vrsqrte_u32(uint32x2_t vec); /* VRSQRTE.U32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vrsqrteq_f32(float32x4_t vec); /* VRSQRTE.F32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vrsqrteq_u32(uint32x4_t vec); /* VRSQRTE.U32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_s8(int8x8_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_s16(int16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_s32(int32x2_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_f32(float32x2_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_u8(uint8x8_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_u16(uint16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_u32(uint32x2_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_p8(poly8x8_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_p16(poly16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_u64(uint64x1_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x4_t vreinterpret_f16_s64(int64x1_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vreinterpret_s8_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vreinterpret_s16_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vreinterpret_s32_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vreinterpret_f32_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vreinterpret_u8_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vreinterpret_u16_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vreinterpret_u32_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vreinterpret_p8_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vreinterpret_p16_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vreinterpret_u64_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vreinterpret_s64_f16(float16x4_t vec); /* NOP ;d0,d0,d0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_s8(int8x16_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_s16(int16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_s32(int32x4_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_f32(float32x4_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_u8(uint8x16_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_u16(uint16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_u32(uint32x4_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_p8(poly8x16_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_p16(poly16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_u64(uint64x2_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float16x8_t vreinterpretq_f16_s64(int64x2_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vreinterpretq_s8_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vreinterpretq_s16_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vreinterpretq_s32_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vreinterpretq_f32_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vreinterpretq_u8_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vreinterpretq_u16_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vreinterpretq_u32_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vreinterpretq_p8_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vreinterpretq_p16_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vreinterpretq_u64_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
#if __ARM_NEON_FP16_INTRINSICS
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vreinterpretq_s64_f16(float16x8_t vec); /* NOP ;q0,q0,q0 */
#endif
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vmvn_s8(int8x8_t vec); /* VMVN d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vmvn_s16(int16x4_t vec); /* VMVN d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vmvn_s32(int32x2_t vec); /* VMVN d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vmvn_u8(uint8x8_t vec); /* VMVN d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vmvn_u16(uint16x4_t vec); /* VMVN d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vmvn_u32(uint32x2_t vec); /* VMVN d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vmvn_p8(poly8x8_t vec); /* VMVN d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vmvnq_s8(int8x16_t vec); /* VMVN q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vmvnq_s16(int16x8_t vec); /* VMVN q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vmvnq_s32(int32x4_t vec); /* VMVN q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vmvnq_u8(uint8x16_t vec); /* VMVN q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vmvnq_u16(uint16x8_t vec); /* VMVN q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vmvnq_u32(uint32x4_t vec); /* VMVN q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vmvnq_p8(poly8x16_t vec); /* VMVN q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vand_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vand_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vand_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vand_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vand_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vand_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vand_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vand_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2); /* VAND d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vandq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vandq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vandq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vandq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vandq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vandq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vandq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vandq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2); /* VAND q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vorr_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vorr_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vorr_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vorr_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vorr_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vorr_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vorr_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vorr_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2); /* VORR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vorrq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vorrq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vorrq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vorrq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vorrq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vorrq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vorrq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vorrq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2); /* VORR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t veor_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t veor_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t veor_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t veor_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t veor_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t veor_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t veor_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t veor_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2); /* VEOR d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t veorq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t veorq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t veorq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t veorq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t veorq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t veorq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t veorq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t veorq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2); /* VEOR q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vbic_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vbic_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vbic_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vbic_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vbic_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vbic_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vbic_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vbic_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2); /* VBIC d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vbicq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vbicq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vbicq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vbicq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vbicq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vbicq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vbicq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vbicq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2); /* VBIC q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vorn_s8(int8x8_t vec1,
                                                  int8x8_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vorn_s16(int16x4_t vec1,
                                                    int16x4_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vorn_s32(int32x2_t vec1,
                                                    int32x2_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vorn_s64(int64x1_t vec1,
                                                    int64x1_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vorn_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vorn_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vorn_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vorn_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2); /* VORN d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vornq_s8(int8x16_t vec1,
                                                    int8x16_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vornq_s16(int16x8_t vec1,
                                                     int16x8_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vornq_s32(int32x4_t vec1,
                                                     int32x4_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vornq_s64(int64x2_t vec1,
                                                     int64x2_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vornq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vornq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vornq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vornq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2); /* VORN q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8_t vbsl_s8(uint8x8_t vec1,
                                                  int8x8_t vec2,
                                                  int8x8_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4_t vbsl_s16(uint16x4_t vec1,
                                                    int16x4_t vec2,
                                                    int16x4_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2_t vbsl_s32(uint32x2_t vec1,
                                                    int32x2_t vec2,
                                                    int32x2_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x1_t vbsl_s64(uint64x1_t vec1,
                                                    int64x1_t vec2,
                                                    int64x1_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8_t vbsl_u8(uint8x8_t vec1,
                                                   uint8x8_t vec2,
                                                   uint8x8_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4_t vbsl_u16(uint16x4_t vec1,
                                                     uint16x4_t vec2,
                                                     uint16x4_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2_t vbsl_u32(uint32x2_t vec1,
                                                     uint32x2_t vec2,
                                                     uint32x2_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x1_t vbsl_u64(uint64x1_t vec1,
                                                     uint64x1_t vec2,
                                                     uint64x1_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2_t vbsl_f32(uint32x2_t vec1,
                                                      float32x2_t vec2,
                                                      float32x2_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8_t vbsl_p8(uint8x8_t vec1,
                                                   poly8x8_t vec2,
                                                   poly8x8_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4_t vbsl_p16(uint16x4_t vec1,
                                                     poly16x4_t vec2,
                                                     poly16x4_t vec3); /* VBSL d0,d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x16_t vbslq_s8(uint8x16_t vec1,
                                                    int8x16_t vec2,
                                                    int8x16_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x8_t vbslq_s16(uint16x8_t vec1,
                                                     int16x8_t vec2,
                                                     int16x8_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x4_t vbslq_s32(uint32x4_t vec1,
                                                     int32x4_t vec2,
                                                     int32x4_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int64x2_t vbslq_s64(uint64x2_t vec1,
                                                     int64x2_t vec2,
                                                     int64x2_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x16_t vbslq_u8(uint8x16_t vec1,
                                                     uint8x16_t vec2,
                                                     uint8x16_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x8_t vbslq_u16(uint16x8_t vec1,
                                                      uint16x8_t vec2,
                                                      uint16x8_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x4_t vbslq_u32(uint32x4_t vec1,
                                                      uint32x4_t vec2,
                                                      uint32x4_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS uint64x2_t vbslq_u64(uint64x2_t vec1,
                                                      uint64x2_t vec2,
                                                      uint64x2_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x4_t vbslq_f32(uint32x4_t vec1,
                                                       float32x4_t vec2,
                                                       float32x4_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x16_t vbslq_p8(uint8x16_t vec1,
                                                     poly8x16_t vec2,
                                                     poly8x16_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x8_t vbslq_p16(uint16x8_t vec1,
                                                      poly16x8_t vec2,
                                                      poly16x8_t vec3); /* VBSL q0,q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8x2_t vtrn_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VTRN.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4x2_t vtrn_s16(int16x4_t vec1,
                                                      int16x4_t vec2); /* VTRN.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2x2_t vtrn_s32(int32x2_t vec1,
                                                      int32x2_t vec2); /* VTRN.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8x2_t vtrn_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VTRN.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4x2_t vtrn_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2); /* VTRN.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2x2_t vtrn_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2); /* VTRN.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2x2_t vtrn_f32(float32x2_t vec1,
                                                        float32x2_t vec2); /* VTRN.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8x2_t vtrn_p8(poly8x8_t vec1,
                                                     poly8x8_t vec2); /* VTRN.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4x2_t vtrn_p16(poly16x4_t vec1,
                                                       poly16x4_t vec2); /* VTRN.16 d0,d0 */
__EXTERNC __PURE int8x16x2_t vtrnq_s8(int8x16_t vec1,
                                      int8x16_t vec2); /* VTRN.8 q0,q0 */
__EXTERNC __PURE int16x8x2_t vtrnq_s16(int16x8_t vec1,
                                       int16x8_t vec2); /* VTRN.16 q0,q0 */
__EXTERNC __PURE int32x4x2_t vtrnq_s32(int32x4_t vec1,
                                       int32x4_t vec2); /* VTRN.32 q0,q0 */
__EXTERNC __PURE uint8x16x2_t vtrnq_u8(uint8x16_t vec1,
                                       uint8x16_t vec2); /* VTRN.8 q0,q0 */
__EXTERNC __PURE uint16x8x2_t vtrnq_u16(uint16x8_t vec1,
                                        uint16x8_t vec2); /* VTRN.16 q0,q0 */
__EXTERNC __PURE uint32x4x2_t vtrnq_u32(uint32x4_t vec1,
                                        uint32x4_t vec2); /* VTRN.32 q0,q0 */
__EXTERNC __PURE float32x4x2_t vtrnq_f32(float32x4_t vec1,
                                         float32x4_t vec2); /* VTRN.32 q0,q0 */
__EXTERNC __PURE poly8x16x2_t vtrnq_p8(poly8x16_t vec1,
                                       poly8x16_t vec2); /* VTRN.8 q0,q0 */
__EXTERNC __PURE poly16x8x2_t vtrnq_p16(poly16x8_t vec1,
                                        poly16x8_t vec2); /* VTRN.16 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8x2_t vzip_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VZIP.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4x2_t vzip_s16(int16x4_t vec1,
                                                      int16x4_t vec2); /* VZIP.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2x2_t vzip_s32(int32x2_t vec1,
                                                      int32x2_t vec2); /* VZIP.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8x2_t vzip_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VZIP.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4x2_t vzip_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2); /* VZIP.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2x2_t vzip_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2); /* VZIP.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8x2_t vzip_p8(poly8x8_t vec1,
                                                     poly8x8_t vec2); /* VZIP.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4x2_t vzip_p16(poly16x4_t vec1,
                                                       poly16x4_t vec2); /* VZIP.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2x2_t vzip_f32(float32x2_t vec1,
                                                        float32x2_t vec2); /* VZIP.32 d0,d0 */
__EXTERNC __PURE int8x16x2_t vzipq_s8(int8x16_t vec1,
                                      int8x16_t vec2); /* VZIP.8 q0,q0 */
__EXTERNC __PURE int16x8x2_t vzipq_s16(int16x8_t vec1,
                                       int16x8_t vec2); /* VZIP.16 q0,q0 */
__EXTERNC __PURE int32x4x2_t vzipq_s32(int32x4_t vec1,
                                       int32x4_t vec2); /* VZIP.32 q0,q0 */
__EXTERNC __PURE uint8x16x2_t vzipq_u8(uint8x16_t vec1,
                                       uint8x16_t vec2); /* VZIP.8 q0,q0 */
__EXTERNC __PURE uint16x8x2_t vzipq_u16(uint16x8_t vec1,
                                        uint16x8_t vec2); /* VZIP.16 q0,q0 */
__EXTERNC __PURE uint32x4x2_t vzipq_u32(uint32x4_t vec1,
                                        uint32x4_t vec2); /* VZIP.32 q0,q0 */
__EXTERNC __PURE poly8x16x2_t vzipq_p8(poly8x16_t vec1,
                                       poly8x16_t vec2); /* VZIP.8 q0,q0 */
__EXTERNC __PURE poly16x8x2_t vzipq_p16(poly16x8_t vec1,
                                        poly16x8_t vec2); /* VZIP.16 q0,q0 */
__EXTERNC __PURE float32x4x2_t vzipq_f32(float32x4_t vec1,
                                         float32x4_t vec2); /* VZIP.32 q0,q0 */
__EXTERNC __PURE __VALUE_IN_REGS int8x8x2_t vuzp_s8(int8x8_t vec1,
                                                    int8x8_t vec2); /* VUZP.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int16x4x2_t vuzp_s16(int16x4_t vec1,
                                                      int16x4_t vec2); /* VUZP.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS int32x2x2_t vuzp_s32(int32x2_t vec1,
                                                      int32x2_t vec2); /* VUZP.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint8x8x2_t vuzp_u8(uint8x8_t vec1,
                                                     uint8x8_t vec2); /* VUZP.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint16x4x2_t vuzp_u16(uint16x4_t vec1,
                                                       uint16x4_t vec2); /* VUZP.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS uint32x2x2_t vuzp_u32(uint32x2_t vec1,
                                                       uint32x2_t vec2); /* VUZP.32 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly8x8x2_t vuzp_p8(poly8x8_t vec1,
                                                     poly8x8_t vec2); /* VUZP.8 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS poly16x4x2_t vuzp_p16(poly16x4_t vec1,
                                                       poly16x4_t vec2); /* VUZP.16 d0,d0 */
__EXTERNC __PURE __VALUE_IN_REGS float32x2x2_t vuzp_f32(float32x2_t vec1,
                                                        float32x2_t vec2); /* VUZP.32 d0,d0 */
__EXTERNC __PURE int8x16x2_t vuzpq_s8(int8x16_t vec1,
                                      int8x16_t vec2); /* VUZP.8 q0,q0 */
__EXTERNC __PURE int16x8x2_t vuzpq_s16(int16x8_t vec1,
                                       int16x8_t vec2); /* VUZP.16 q0,q0 */
__EXTERNC __PURE int32x4x2_t vuzpq_s32(int32x4_t vec1,
                                       int32x4_t vec2); /* VUZP.32 q0,q0 */
__EXTERNC __PURE uint8x16x2_t vuzpq_u8(uint8x16_t vec1,
                                       uint8x16_t vec2); /* VUZP.8 q0,q0 */
__EXTERNC __PURE uint16x8x2_t vuzpq_u16(uint16x8_t vec1,
                                        uint16x8_t vec2); /* VUZP.16 q0,q0 */
__EXTERNC __PURE uint32x4x2_t vuzpq_u32(uint32x4_t vec1,
                                        uint32x4_t vec2); /* VUZP.32 q0,q0 */
__EXTERNC __PURE poly8x16x2_t vuzpq_p8(poly8x16_t vec1,
                                       poly8x16_t vec2); /* VUZP.8 q0,q0 */
__EXTERNC __PURE poly16x8x2_t vuzpq_p16(poly16x8_t vec1,
                                        poly16x8_t vec2); /* VUZP.16 q0,q0 */
__EXTERNC __PURE float32x4x2_t vuzpq_f32(float32x4_t vec1,
                                         float32x4_t vec2); /* VUZP.32 q0,q0 */
#endif /* def __TARGET_FEATURE_NEON */
#endif /* def__NEON_H_ */

