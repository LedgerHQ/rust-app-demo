/* rt_locale.h: definitions to enable retargetting of locale mechanism
 *
 * Copyright 1999 ARM Limited. All rights reserved.
 *
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author$
 */

#ifndef __RT_LOCALE_H
#define __RT_LOCALE_H
#define __ARMCLIB_VERSION 6090000

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The _findlocale function for performing index searches.
 */
extern void const *_findlocale(void const * /*index*/, char const * /*name*/);

/*
 * The _get_lc_CATEGORY functions. Override these to retarget
 * locales.
 */
void const *_get_lc_collate(void const * /*null*/, char const * /*name*/);
void const *_get_lc_ctype(void const * /*null*/, char const * /*name*/);
void const *_get_lc_monetary(void const * /*null*/, char const * /*name*/);
void const *_get_lc_numeric(void const * /*null*/, char const * /*name*/);
void const *_get_lc_time(void const * /*null*/, char const * /*name*/);

#ifdef __cplusplus
}
#endif

#endif

