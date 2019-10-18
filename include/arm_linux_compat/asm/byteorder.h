/* byteorder.h: wrapper for ARM Linux asm/byteorder.h
 *
 * Copyright 2008 ARM Limited. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

/* Define Thumb preprocessor symbol to avoid GNU inline assembly */
#ifndef __thumb__
#define __thumb__
#include_next <asm/byteorder.h>
#undef __thumb__
#else
#include_next <asm/byteorder.h>
#endif

/* end of byteorder.h */

