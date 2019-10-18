/* wchar.h: C99 header */
/* Copyright 2002 ARM Limited. All rights reserved.            */
/*
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author: agrant $
 */

#ifndef __wchar_h
#define __wchar_h
#define __ARMCLIB_VERSION 6090000

#if defined(_ARM_OVERRIDE_PCS)
#define _ARMABI __attribute__((nothrow)) _ARM_OVERRIDE_PCS
#else
#define _ARMABI __attribute__((nothrow))
#endif

  #ifndef __WCHAR_DECLS
  #define __WCHAR_DECLS

    #undef __CLIBNS
    #ifdef __cplusplus
        #define __CLIBNS ::std::
        namespace std {
        extern "C" {
    #else /* ndef __cplusplus */
      #define __CLIBNS
    #endif /* ndef __cplusplus */

    #if defined(__cplusplus) || !defined(__STRICT_ANSI__) || !defined(__size_t)
     /* always defined in C++ and non-strict C for consistency of debug info */
      #if __sizeof_ptr == 8
        typedef unsigned long size_t;   /* see <stddef.h> */
      #else
        typedef unsigned int size_t;   /* see <stddef.h> */
      #endif
      #if !defined(__cplusplus) && defined(__STRICT_ANSI__)
        #define __size_t 1
      #endif
    #endif

    #ifndef __cplusplus  /* wchar_t is a builtin type for C++ */
      #if !defined(__STRICT_ANSI__) || !defined(__wchar_t)
       /* always defined in non-strict C for consistency of debug info */
        #if defined(__WCHAR32) || (defined(__ARM_SIZEOF_WCHAR_T) && __ARM_SIZEOF_WCHAR_T == 4)
          typedef unsigned int wchar_t; /* see <stddef.h> */
        #else
          typedef unsigned short wchar_t; /* see <stddef.h> */
        #endif
        #ifdef __STRICT_ANSI__
          #define __wchar_t 1
        #endif
      #endif
    #endif

    #if defined(__cplusplus) || !defined(__STRICT_ANSI__) || !defined(__wint_t)
     /* always defined in C++ and non-strict C for consistency of debug info */
      typedef int wint_t;   /* see also <wctype.h> */
      #if !defined(__cplusplus) && defined(__STRICT_ANSI__)
        #define __wint_t 1
      #endif
    #endif

        /* limits of wchar_t */
        /* NB we have to undef and redef because they're defined in both
         * stdint.h and wchar.h */
    #undef WCHAR_MIN
    #undef WCHAR_MAX

    #if defined(__WCHAR32)  || (defined(__ARM_SIZEOF_WCHAR_T) && __ARM_SIZEOF_WCHAR_T == 4)
      #define WCHAR_MIN   0
      #define WCHAR_MAX   0xffffffffU
    #else
      #define WCHAR_MIN   0
      #define WCHAR_MAX   65535
    #endif

    #undef NULL
    #define NULL 0                   /* see <stddef.h> */

    /* ANSI forbids va_list to be defined here */
    /* keep in step with <stdarg.h> and <stdio.h> */
    #if !defined(__va_list) && (defined(__cplusplus) || !defined(__STRICT_ANSI__) || !defined(__va_list_defined))
    /* always defined in C++ and non-strict C for consistency of debug info */
      #ifdef __clang__
        typedef __builtin_va_list __va_list;
      #else
        typedef struct __va_list __va_list;
      #endif
      #if !defined(__cplusplus) && defined(__STRICT_ANSI__)
        #define __va_list_defined 1
      #endif
    #endif

  #ifndef __ARM_WCHAR_NO_IO
    #undef WEOF
    #define WEOF ((__CLIBNS wint_t)-1)

    /* ANSI forbids FILE to be defined here */
    #if !defined(__STRICT_ANSI__)
    /* always defined in non-strict C/C++ for consistency of debug info */
      typedef struct __FILE FILE;
    #else
      struct __FILE;
    #endif
  #endif /* __ARM_WCHAR_NO_IO */

    /*
     * If the compiler supports signalling nans as per N965 then it
     * will define __SUPPORT_SNAN__, in which case a user may define
     * _WANT_SNAN in order to obtain compliant versions of the
     * fwprintf, fwscanf, and wcstod families of functions.
     */
    #if defined(__SUPPORT_SNAN__) && defined(_WANT_SNAN)
    #pragma import(__use_snan)
    #endif


    /*
     * mbstate_t must be able to contain all the data from an
     * incomplete MB character, plus shift states. CJK-specific
     * encodings seem to tend to have at most three bytes per
     * character, and a single-figure number of shift states, so 32
     * bits is sufficient for any of these. UTF-8 encoding a full
     * 32-bit value is the hardest thing to deal with, and in that
     * situation the worst case is having to store 25 bits of
     * character (1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx) plus
     * a few bits saying what sort of state is being stored. This is
     * still easy enough to fit into 32 bits, so I think a single
     * 32-bit integer is enough in here.
     */
    #if !defined(__mbstate_t_defined)
      typedef struct __mbstate_t {
          unsigned int __state, __state2;
      } mbstate_t;
      #define __mbstate_t_defined 1
    #endif

    /*
     * `struct tm' must be declared in this header as an incomplete
     * type.
     */
    struct tm;
            
    extern _ARMABI size_t wcsftime(wchar_t * __restrict /*s*/, size_t /*maxsize*/,
                       const wchar_t * __restrict /*format*/, const struct tm * __restrict /*timeptr*/) __attribute__((__nonnull__(1,3,4)));

  #ifndef __ARM_WCHAR_NO_IO
    /*
     * Formatted wide-character I/O functions
     */
#pragma __printf_args
    int swprintf(wchar_t * __restrict /*s*/, size_t /*n*/,
                 const wchar_t * __restrict /*format*/, ...) __attribute__((__nonnull__(3)));
#pragma __printf_args
    int vswprintf(wchar_t * __restrict /*s*/, size_t /*n*/,
                  const wchar_t * __restrict /*format*/, __va_list /*arg*/) __attribute__((__nonnull__(3)));
#pragma __scanf_args
    int swscanf(const wchar_t * __restrict /*s*/,
                const wchar_t * __restrict /*format*/, ...) __attribute__((__nonnull__(1,2)));
#pragma __scanf_args
    int vswscanf(const wchar_t * __restrict /*s*/,
                 const wchar_t * __restrict /*format*/, __va_list /*arg*/) __attribute__((__nonnull__(1,2)));


#pragma __printf_args
    int fwprintf(struct __FILE * __restrict /*stream*/,
                 const wchar_t * __restrict /*format*/, ...) __attribute__((__nonnull__(1,2)));
#pragma __printf_args
    int vfwprintf(struct __FILE * __restrict /*stream*/,
                  const wchar_t * __restrict /*format*/, __va_list /*arg*/) __attribute__((__nonnull__(1,2)));
#pragma __scanf_args
    int fwscanf(struct __FILE * __restrict /*stream*/,
                const wchar_t * __restrict /*format*/, ...) __attribute__((__nonnull__(1,2)));
#pragma __scanf_args
    int vfwscanf(struct __FILE * __restrict /*stream*/,
                 const wchar_t * __restrict /*format*/, __va_list /*arg*/) __attribute__((__nonnull__(1,2)));


#pragma __printf_args
    int wprintf(const wchar_t * __restrict /*format*/, ...) __attribute__((__nonnull__(1)));
#pragma __printf_args
    int vwprintf(const wchar_t * __restrict /*format*/, __va_list /*arg*/) __attribute__((__nonnull__(1)));
#pragma __scanf_args
    int wscanf(const wchar_t * __restrict /*format*/, ...) __attribute__((__nonnull__(1)));
#pragma __scanf_args
    int vwscanf(const wchar_t * __restrict /*format*/, __va_list /*arg*/) __attribute__((__nonnull__(1)));

    /* 
     * Unformatted wide-character I/O functions
     */
    wint_t fgetwc(struct __FILE * /*stream*/) __attribute__((__nonnull__(1)));
    wchar_t *fgetws(wchar_t * __restrict /*s*/, int /*n*/, struct __FILE * __restrict /*stream*/) __attribute__((__nonnull__(1,3)));
    wint_t fputwc(wchar_t /*c*/, struct __FILE * /*stream*/) __attribute__((__nonnull__(2)));
    int fputws(const wchar_t * __restrict /*s*/, struct __FILE * __restrict /*stream*/) __attribute__((__nonnull__(1,2)));
    int fwide(struct __FILE * /*stream*/, int /*mode*/) __attribute__((__nonnull__(1)));
    wint_t getwc(struct __FILE * /*stream*/) __attribute__((__nonnull__(1)));
    wint_t getwchar(void);
    wint_t putwc(wchar_t /*c*/, struct __FILE * /*stream*/) __attribute__((__nonnull__(2)));
    wint_t putwchar(wchar_t /*c*/);
    wint_t ungetwc(wint_t /*c*/, struct __FILE * /*stream*/) __attribute__((__nonnull__(2)));
  #endif /* __ARM_WCHAR_NO_IO */

    wint_t btowc(int /*c*/);
    wint_t wctob(int /*c*/);
    int mbsinit(const mbstate_t * /*ps*/);
    size_t mbrlen(const char * __restrict /*s*/, size_t /*n*/,
                  mbstate_t * __restrict /*ps*/);
    size_t mbrtowc(wchar_t * __restrict /*pwc*/,
                   const char * __restrict /*s*/,
                   size_t /*n*/, mbstate_t * __restrict /*ps*/);
    size_t wcrtomb(char * __restrict /*s*/, wchar_t /*wc*/,
                   mbstate_t * __restrict /*ps*/);
    size_t mbsrtowcs(wchar_t * __restrict /*dst*/,
                     const char ** __restrict /*src*/,
                     size_t /*len*/, mbstate_t * __restrict /*ps*/) __attribute__((__nonnull__(2)));
    size_t wcsrtombs(char * __restrict /*dst*/,
                     const wchar_t ** __restrict /*src*/,
                     size_t /*len*/, mbstate_t * __restrict /*ps*/) __attribute__((__nonnull__(2)));
    size_t _mbsnrtowcs(wchar_t * __restrict /*dst*/,
                       const char ** __restrict /*src*/,
                       size_t /*nmb*/,
                       size_t /*len*/, mbstate_t * __restrict /*ps*/) __attribute__((__nonnull__(2)));
    size_t _wcsnrtombs(char * __restrict /*dst*/,
                       const wchar_t ** __restrict /*src*/,
                       size_t /*nwc*/,
                       size_t /*len*/, mbstate_t * __restrict /*ps*/) __attribute__((__nonnull__(2)));
#if !defined(__STRICT_ANSI__)
    size_t mbsnrtowcs(wchar_t * __restrict /*dst*/,
                      const char ** __restrict /*src*/,
                      size_t /*nmb*/,
                      size_t /*len*/, mbstate_t * __restrict /*ps*/) __attribute__((__nonnull__(2)));
    size_t wcsnrtombs(char * __restrict /*dst*/,
                      const wchar_t ** __restrict /*src*/,
                      size_t /*nwc*/,
                      size_t /*len*/, mbstate_t * __restrict /*ps*/) __attribute__((__nonnull__(2)));
#endif

    /*
     * Wide-character string-to-number conversions. Parallel to strto*.
     */
    _ARMABI double wcstod(const wchar_t * /*nptr*/, wchar_t ** /*endptr*/) __attribute__((__nonnull__(1)));
    _ARMABI float wcstof(const wchar_t * /*nptr*/, wchar_t ** /*endptr*/) __attribute__((__nonnull__(1)));
    _ARMABI long double wcstold(const wchar_t * /*nptr*/, wchar_t ** /*endptr*/) __attribute__((__nonnull__(1)));
    long int wcstol(const wchar_t * /*nptr*/, wchar_t ** /*endptr*/,
                    int /*base*/) __attribute__((__nonnull__(1)));
    unsigned long int wcstoul(const wchar_t * /*nptr*/,
                              wchar_t ** /*endptr*/, int /*base*/) __attribute__((__nonnull__(1)));
#if !defined(__STRICT_ANSI__) || defined(__USE_C99_ALL) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
    long long int wcstoll(const wchar_t * __restrict /*nptr*/,
                          wchar_t ** __restrict /*endptr*/, int /*base*/) __attribute__((__nonnull__(1)));
    unsigned long long int wcstoull(const wchar_t * __restrict /*nptr*/,
                                    wchar_t ** __restrict /*endptr*/,
                                    int /*base*/) __attribute__((__nonnull__(1)));
#endif

    /*
     * General wide-character string utilities.
     */
    wchar_t *wcscpy(wchar_t * __restrict /*s1*/,
                    const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wcsncpy(wchar_t * __restrict /*s1*/,
                     const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wmemcpy(wchar_t * __restrict /*s1*/,
                     const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wmemmove(wchar_t * __restrict /*s1*/,
                      const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wcscat(wchar_t * __restrict /*s1*/,
                    const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wcsncat(wchar_t * __restrict /*s1*/,
                     const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
    int wcscmp(const wchar_t * __restrict /*s1*/,
               const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    int wcsncmp(const wchar_t * __restrict /*s1*/,
                const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
    int wcscasecmp(const wchar_t * __restrict /*s1*/,
                   const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    int wcsncasecmp(const wchar_t * __restrict /*s1*/,
                    const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
    int wcscoll(const wchar_t * __restrict /*s1*/,
                const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    size_t wcsxfrm(wchar_t * __restrict /*s1*/,
                   const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(2)));
    int wmemcmp(const wchar_t * __restrict /*s1*/,
                const wchar_t * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
    size_t wcscspn(const wchar_t * __restrict /*s1*/,
                   const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    size_t wcsspn(const wchar_t * __restrict /*s1*/,
                  const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wcstok(wchar_t * __restrict /*s1*/,
                    const wchar_t * __restrict /*s2*/,
                    wchar_t ** __restrict /*ptr*/) __attribute__((__nonnull__(2,3)));
    size_t wcslen(const wchar_t * __restrict /*s*/) __attribute__((__nonnull__(1)));
    wchar_t *wmemset(wchar_t * __restrict /*s*/, wchar_t /*c*/, size_t /*n*/) __attribute__((__nonnull__(1)));

#if defined(__cplusplus) && !defined(__ARMCOMPILER_LIBCXX)
    /*
     * C++'s overloading allows us to provide versions of these
     * functions which search a const string and return a const
     * pointer into it, and separate versions which search a
     * non-const string and return a non-const pointer.
     */
    const wchar_t *wcschr(const wchar_t * __restrict /*s*/, wchar_t /*c*/) __attribute__((__nonnull__(1)));
    const wchar_t *wcspbrk(const wchar_t * __restrict /*s1*/,
                           const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    const wchar_t *wcsrchr(const wchar_t * __restrict /*s*/, wchar_t /*c*/) __attribute__((__nonnull__(1)));
    const wchar_t *wcsstr(const wchar_t * __restrict /*s1*/,
                          const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    const wchar_t *wmemchr(const wchar_t * __restrict /*s*/, wchar_t /*c*/,
                           size_t /*n*/) __attribute__((__nonnull__(1)));
#ifndef __WCHAR_DISABLED
    extern "C++" wchar_t *wcschr(wchar_t * __restrict __s, wchar_t __c) __attribute__((__nonnull__(1)));
    extern "C++" inline wchar_t *wcschr(wchar_t * __restrict __s, wchar_t __c)
      { return const_cast<wchar_t *>(wcschr(const_cast<const wchar_t *>(__s), __c)); }
    extern "C++" wchar_t *wcspbrk(wchar_t * __restrict __s1, const wchar_t * __restrict __s2) __attribute__((__nonnull__(1,2)));
    extern "C++" inline wchar_t *wcspbrk(wchar_t * __restrict __s1, const wchar_t * __restrict __s2)
      { return const_cast<wchar_t *>(wcspbrk(const_cast<const wchar_t *>(__s1), __s2)); }
    extern "C++" wchar_t *wcsrchr(wchar_t * __restrict __s, wchar_t __c) __attribute__((__nonnull__(1)));
    extern "C++" inline wchar_t *wcsrchr(wchar_t * __restrict __s, wchar_t __c)
      { return const_cast<wchar_t *>(wcsrchr(const_cast<const wchar_t *>(__s), __c)); }
    extern "C++" wchar_t *wcsstr(wchar_t * __restrict __s1,
                          const wchar_t * __restrict __s2) __attribute__((__nonnull__(1,2)));
    extern "C++" inline wchar_t *wcsstr(wchar_t * __restrict __s1,
                          const wchar_t * __restrict __s2)
      { return const_cast<wchar_t *>(wcsstr(const_cast<const wchar_t *>(__s1), __s2)); }
    extern "C++" wchar_t *wmemchr(wchar_t * __restrict __s, wchar_t __c,
                                  size_t __n) __attribute__((__nonnull__(1)));
    extern "C++" inline wchar_t *wmemchr(wchar_t * __restrict __s, wchar_t __c,
                                  size_t __n)
    { return const_cast<wchar_t *>(wmemchr(const_cast<const wchar_t *>(__s), __c, __n)); }
#endif
#else
    /*
     * C's approximation to the above is to have all of these
     * functions search a const string and return a non-const
     * pointer. This is the only way to prevent compile errors in
     * all sensible uses of the functions, but unfortunately
     * renders them unable to spot a lot of the possible error
     * cases.
     */
#if defined(__cplusplus) && defined(__ARMCOMPILER_LIBCXX)
  }  /* extern "C" */
  }  /* namespace std */
  extern "C" {
#endif
    wchar_t *wcschr(const wchar_t * __restrict /*s*/, wchar_t /*c*/) __attribute__((__nonnull__(1)));
    wchar_t *wcspbrk(const wchar_t * __restrict /*s1*/,
                     const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wcsrchr(const wchar_t * __restrict /*s*/, wchar_t /*c*/) __attribute__((__nonnull__(1)));
    wchar_t *wcsstr(const wchar_t * __restrict /*s1*/,
                    const wchar_t * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
    wchar_t *wmemchr(const wchar_t * __restrict /*s*/, wchar_t /*c*/,
                     __CLIBNS size_t /*n*/) __attribute__((__nonnull__(1)));
#if defined(__cplusplus) && defined(__ARMCOMPILER_LIBCXX)
  }  /* extern "C" */
  namespace std {
  extern "C" {
#endif
#endif

    #ifdef __cplusplus
         }  /* extern "C" */
      }  /* namespace std */
    #endif /* __cplusplus */
  #endif /* __WCHAR_DECLS */

  #if _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
    #define _AEABI_PORTABLE
  #endif

  #ifdef __cplusplus
    #ifndef __WCHAR_NO_EXPORTS
      using ::std::size_t;
      using ::std::wint_t;
      using ::std::mbstate_t;
      using ::std::tm;
      using ::std::wcsftime;
    #ifndef __ARM_WCHAR_NO_IO
      using ::std::swprintf;
      using ::std::vswprintf;
      using ::std::swscanf;
      using ::std::vswscanf;
      using ::std::fwprintf;
      using ::std::vfwprintf;
      using ::std::fwscanf;
      using ::std::vfwscanf;
      using ::std::wprintf;
      using ::std::vwprintf;
      using ::std::wscanf;
      using ::std::vwscanf;
      using ::std::fgetwc;
      using ::std::fgetws;
      using ::std::fputwc;
      using ::std::fputws;
      using ::std::fwide;
      using ::std::getwc;
      using ::std::getwchar;
      using ::std::putwc;
      using ::std::putwchar;
      using ::std::ungetwc;
      using ::std::btowc;
    #endif /* __ARM_WCHAR_NO_IO */
      using ::std::wctob;
      using ::std::mbsinit;
      using ::std::mbrlen;
      using ::std::mbrtowc;
      using ::std::wcrtomb;
      using ::std::mbsrtowcs;
      using ::std::wcsrtombs;
      using ::std::_mbsnrtowcs;
      using ::std::_wcsnrtombs;
#if !defined(__STRICT_ANSI__)
      using ::std::mbsnrtowcs;
      using ::std::wcsnrtombs;
#endif
      using ::std::wcstod;
      using ::std::wcstof;
      using ::std::wcstold;
      using ::std::wcstol;
      using ::std::wcstoul;
#if !defined(__STRICT_ANSI__) || defined(__USE_C99_ALL) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
      using ::std::wcstoll;
      using ::std::wcstoull;
#endif /* !defined(__STRICT_ANSI__) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus) */
      using ::std::wcscpy;
      using ::std::wcsncpy;
      using ::std::wmemcpy;
      using ::std::wmemmove;
      using ::std::wcscat;
      using ::std::wcsncat;
      using ::std::wcscmp;
      using ::std::wcsncmp;
      using ::std::wcscasecmp;
      using ::std::wcsncasecmp;
      using ::std::wcscoll;
      using ::std::wcsxfrm;
      using ::std::wmemcmp;
#if defined(__cplusplus) && !defined(__ARMCOMPILER_LIBCXX)
      using ::std::wcschr;
      using ::std::wcspbrk;
      using ::std::wcsrchr;
      using ::std::wcsstr;
      using ::std::wmemchr;
#endif /* defined(__cplusplus) && !defined(__ARMCOMPILER_LIBCXX) */
      using ::std::wcscspn;
      using ::std::wcsspn;
      using ::std::wcstok;
      using ::std::wcslen;
      using ::std::wmemset;
#if !defined(__STRICT_ANSI__) && !defined(__ARM_WCHAR_NO_IO)
      using ::std::FILE;
#endif
    #endif /* __WCHAR_NO_EXPORTS */
  #endif /* __cplusplus */
#endif /* ndef __wchar_h */

/* end of wchar.h */

