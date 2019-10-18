/*===---- arm_cmse.h - ARM CMSE support ------------------------------------===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */
#ifndef __ARM_CMSE_H
#define __ARM_CMSE_H

#if (__ARM_FEATURE_CMSE & 0x1)
#include <stdint.h>
#include <stddef.h>

#define __CMSE_SECURE_MODE (__ARM_FEATURE_CMSE & 0x2)
#define CMSE_MPU_READWRITE 1              /*checks if readwrite_ok field is set*/
#define CMSE_AU_NONSECURE  2              /*checks if permissions have secure field unset*/
#define CMSE_MPU_UNPRIV    4              /*sets T flag on TT insrtuction*/
#define CMSE_MPU_READ      8              /*checks if read_ok field is set*/
#define CMSE_MPU_NONSECURE 16             /*sets A flag, checks if secure field unset*/
#define CMSE_NONSECURE     (CMSE_AU_NONSECURE | CMSE_MPU_NONSECURE)
#define cmse_check_pointed_object(p, f) (cmse_check_address_range(p, sizeof(*p), f))

#if defined(__cplusplus)
extern "C" {
#endif
typedef union {
  struct cmse_address_info {
#ifdef __ARM_BIG_ENDIAN
      /* __ARM_BIG_ENDIAN */
#if (__CMSE_SECURE_MODE)
    unsigned idau_region:8;            /*bit 31-24*/
    unsigned idau_region_valid:1;      /*bit 23-23*/
    unsigned secure:1;                 /*bit 22-22*/
    unsigned nonsecure_readwrite_ok:1; /*bit 21-21*/
    unsigned nonsecure_read_ok:1;      /*bit 20-20*/
#else
    unsigned :12;                      /*bit 31-20*/
#endif
    unsigned readwrite_ok:1;           /*bit 19-19*/
    unsigned read_ok:1;                /*bit 18-18*/
#if (__CMSE_SECURE_MODE)
    unsigned sau_region_valid:1;       /*bit 17-17*/
#else
    unsigned :1;                       /*bit 17-17*/
#endif
    unsigned mpu_region_valid:1;       /*bit 16-16*/
#if (__CMSE_SECURE_MODE)
    unsigned sau_region:8;             /*bit 15-08*/
#else
    unsigned :8;                       /*bit 15-08*/
#endif
    unsigned mpu_region:8;             /*bit 07-00*/

#else /* __ARM_LITTLE_ENDIAN */
    unsigned mpu_region:8;             /*bit 31-24*/
#if (__CMSE_SECURE_MODE)
    unsigned sau_region:8;             /*bit 23-16*/
#else
    unsigned :8;                       /*bit 23-16*/
#endif
    unsigned mpu_region_valid:1;       /*bit 15-15*/
#if (__CMSE_SECURE_MODE)
    unsigned sau_region_valid:1;       /*bit 14-14*/
#else
    unsigned :1;                       /*bit 14-14*/
#endif
    unsigned read_ok:1;                /*bit 13-13*/
    unsigned readwrite_ok:1;           /*bit 12-12*/
#if (__CMSE_SECURE_MODE)
    unsigned nonsecure_read_ok:1;      /*bit 11-11*/
    unsigned nonsecure_readwrite_ok:1; /*bit 10-10*/
    unsigned secure:1;                 /*bit 09-09*/
    unsigned idau_region_valid:1;      /*bit 08-08*/
    unsigned idau_region:8;            /*bit 07-00*/
#else
    unsigned :12;                      /*bit 11-00*/
#endif
#endif /*__ARM_LITTLE_ENDIAN */
  } flags;
  unsigned value;
} cmse_address_info_t;


static cmse_address_info_t  __attribute__((__always_inline__, __nodebug__)) cmse_TT(void *p) {
  cmse_address_info_t u;
  u.value = __builtin_arm_cmse_TT(p);
  return u;
}
static cmse_address_info_t  __attribute__((__always_inline__, __nodebug__)) cmse_TTT(void *p) {
  cmse_address_info_t u;
  u.value = __builtin_arm_cmse_TTT(p);
  return u;
}

#if __CMSE_SECURE_MODE
static cmse_address_info_t  __attribute__((__always_inline__, __nodebug__)) cmse_TTA(void *p) {
  cmse_address_info_t u;
  u.value = __builtin_arm_cmse_TTA(p);
  return u;
}
static cmse_address_info_t  __attribute__((__always_inline__, __nodebug__)) cmse_TTAT(void *p) {
  cmse_address_info_t u;
  u.value = __builtin_arm_cmse_TTAT(p);
  return u;
}
#endif

#define cmse_TT_fptr(p) (cmse_TT((void*)p))
#define cmse_TTT_fptr(p) (cmse_TTT((void*)p))

#if __CMSE_SECURE_MODE
#define cmse_TTA_fptr(p) (cmse_TTA((void*)p))
#define cmse_TTAT_fptr(p) (cmse_TTAT((void*)p))
#endif

static void* __attribute__((__always_inline__)) cmse_check_address_range(void *p, size_t s, int flags){
  cmse_address_info_t permb, perme;
  char *pb = (char *)p;
  char *pe = pb + s -1;

  if ((uintptr_t)pe < (uintptr_t)pb) return NULL; // wrap around check

  // execute the right variant of the TT instructions
  const int singleCheck = (((uintptr_t) pb ^ (uintptr_t) pe) < 0x20u);

  switch (flags & (CMSE_MPU_UNPRIV | CMSE_MPU_NONSECURE)) {
    case 0:
      permb = cmse_TT(pb);
      perme = singleCheck ? permb : cmse_TT(pe);
      break;
    case CMSE_MPU_UNPRIV:
      permb = cmse_TTT(pb);
      perme = singleCheck ? permb : cmse_TTT(pe);
      break;
#if __CMSE_SECURE_MODE
    case CMSE_MPU_NONSECURE:
      permb = cmse_TTA(pb);
      perme = singleCheck ? permb : cmse_TTA(pe);
      break;
    case CMSE_MPU_UNPRIV | CMSE_MPU_NONSECURE:
      permb = cmse_TTAT(pb);
      perme = singleCheck ? permb : cmse_TTAT(pe);
      break;
#endif
    // if CMSE_NONSECURE is specified w/o __CMSE_SECURE_MODE
    default:
      return NULL;
  }

  // check that the range does not cross MPU, SAU, or IDAU region boundaries
  if (permb.value != perme.value) return NULL;
#if ! (__CMSE_SECURE_MODE)
    // CMSE_AU_NONSECURE is only supported when __ARM_FEATURE_CMSE & 0x2
  if (flags & CMSE_AU_NONSECURE) return NULL;
#endif

  // check the permission on the range
  switch (flags & ~(CMSE_MPU_UNPRIV|CMSE_MPU_NONSECURE)) {
#if (__CMSE_SECURE_MODE)
    case CMSE_MPU_READ|CMSE_MPU_READWRITE|CMSE_AU_NONSECURE:
    case CMSE_MPU_READWRITE|CMSE_AU_NONSECURE:
      return permb.flags.nonsecure_readwrite_ok ? p : NULL;

    case CMSE_MPU_READ|CMSE_AU_NONSECURE:
      return permb.flags.nonsecure_read_ok ? p : NULL;

    case CMSE_AU_NONSECURE:
      return permb.flags.secure ? NULL : p;
#endif
    case CMSE_MPU_READ|CMSE_MPU_READWRITE:
    case               CMSE_MPU_READWRITE:
      return permb.flags.readwrite_ok ? p : NULL;

    case CMSE_MPU_READ:
      return permb.flags.read_ok ? p : NULL;

   default:
     return NULL;
  }
}

#if __CMSE_SECURE_MODE
static int __attribute__((__always_inline__, __nodebug__)) cmse_nonsecure_caller(void) {
  return !((intptr_t)__builtin_return_address(0) & 1);
}

#define cmse_nsfptr_create(p)   ((__typeof__(p)) ((intptr_t) p & ~1))
#define cmse_is_nsfptr(p)       (!((intptr_t) p & 1))
#endif // __CMSE_SECURE_MODE

void __attribute__((__noreturn__)) cmse_abort(void);
#if defined(__cplusplus)
}
#endif
#endif /* (__ARM_FEATURE_CMSE & 0x1) */
#endif /* __ARM_CMSE_H */
