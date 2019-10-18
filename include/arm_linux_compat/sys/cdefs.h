/* cdefs.h: wrapper for ARM Linux sys/cdefs.h
 *
 * Copyright 2008 ARM Limited. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

/* Prevent glibc from using __builtin_va_arg_pack and __builtin_va_arg_pack_len
   in GCC 4.3 emulation */

#ifndef __ARMCC_SYS_CDEFS_H
#define __ARMCC_SYS_CDEFS_H

#include_next <sys/cdefs.h>
#if (__GNUC__ > 4 || \
     (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
#undef __va_arg_pack
#undef __va_arg_pack_len
#endif /* GCC 4.3 emulation */

#endif /* __ARMCC_SYS_CDEFS_H */

/* end of cdefs.h */

