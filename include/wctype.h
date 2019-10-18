/* wctype.h: C99 header */
/* Copyright 2002 ARM Limited. All rights reserved.            */
/*
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author: drodgman $
 */

#ifndef __wctype_h
#define __wctype_h
#define __ARMCLIB_VERSION 6090000

#define _ARMABI __attribute__((nothrow))

  #ifndef __WCTYPE_DECLS
  #define __WCTYPE_DECLS

    #undef __CLIBNS
    #ifdef __cplusplus
        #define __CLIBNS ::std::
        namespace std {
      extern "C" {
    #else /* ndef __cplusplus */
      #define __CLIBNS
    #endif /* ndef __cplusplus */

    #if defined(__cplusplus) || !defined(__STRICT_ANSI__) || !defined(__wint_t)
     /* always defined in C++ and non-strict C for consistency of debug info */
      typedef int wint_t;   /* see also <wchar.h> */
      #if !defined(__cplusplus) && defined(__STRICT_ANSI__)
        #define __wint_t 1
      #endif
    #endif

    typedef void *wctype_t;
    typedef void *wctrans_t;

    #undef WEOF
    #define WEOF ((__CLIBNS wint_t)-1)

    _ARMABI int iswalnum(wint_t /* wc */);
    _ARMABI int iswalpha(wint_t /* wc */);
    _ARMABI int iswblank(wint_t /* wc */);
    _ARMABI int iswcntrl(wint_t /* wc */);
    _ARMABI int iswgraph(wint_t /* wc */);
    _ARMABI int iswprint(wint_t /* wc */);
    _ARMABI int iswpunct(wint_t /* wc */);
    _ARMABI int iswspace(wint_t /* wc */);
    _ARMABI int iswlower(wint_t /* wc */);
    _ARMABI int iswupper(wint_t /* wc */);
    _ARMABI int iswdigit(wint_t /* wc */);
    _ARMABI int iswxdigit(wint_t /* wc */);
    _ARMABI wint_t towlower(wint_t /* wc */);
    _ARMABI wint_t towupper(wint_t /* wc */);

    _ARMABI wctype_t wctype(const char * /* property */) __attribute__((__nonnull__(1)));
    _ARMABI int iswctype(wint_t /* wc */, wctype_t /* desc */);

    _ARMABI wctrans_t wctrans(const char * /* property */) __attribute__((__nonnull__(1)));
    _ARMABI wint_t towctrans(wint_t /* wc */, wctrans_t /* desc */);

    #ifdef __cplusplus
         }  /* extern "C" */
      }  /* namespace std */
    #endif /* __cplusplus */
  #endif /* __WCTYPE_DECLS */

  #if _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
    #define _AEABI_PORTABLE
  #endif

  #ifdef __cplusplus
    #ifndef __WCTYPE_NO_EXPORTS
      using ::std::wint_t;
      using ::std::wctype_t;
      using ::std::wctrans_t;
      using ::std::iswalnum;
      using ::std::iswalpha;
      using ::std::iswblank;
      using ::std::iswcntrl;
      using ::std::iswgraph;
      using ::std::iswprint;
      using ::std::iswpunct;
      using ::std::iswspace;
      using ::std::iswlower;
      using ::std::iswupper;
      using ::std::iswdigit;
      using ::std::iswxdigit;
      using ::std::towlower;
      using ::std::towupper;
      using ::std::wctype;
      using ::std::iswctype;
      using ::std::wctrans;
      using ::std::towctrans;
    #endif /* __WCTYPE_NO_EXPORTS */
  #endif /* __cplusplus */
#endif /* ndef __wctype_h */

/* end of wctype.h */

