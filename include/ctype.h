/* ctype.h: ANSI 'C' (X3J11 Oct 88) library header, section 4.3 */
/* Copyright (C) Codemist Ltd. 1988-1993.                       */
/* Copyright 1991-1993 ARM Limited. All rights reserved.        */
/* version 0.03 */

/*
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author: agrant $
 */

/*
 * ctype.h declares several functions useful for testing and mapping
 * characters. In all cases the argument is an int, the value of which shall
 * be representable as an unsigned char or shall equal the value of the
 * macro EOF. If the argument has any other value, the behaviour is undefined.
 */

#ifndef __ctype_h
#define __ctype_h
#define __ARMCLIB_VERSION 6090000

#define _ARMABI __attribute__((nothrow))
#define _ARMABI_PURE __attribute__((nothrow)) __attribute__((const))

#ifdef __cplusplus
#define _ARMABI_INLINE_DEF inline
#elif defined(__GNUC__) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__)
#define _ARMABI_INLINE_DEF static inline
#elif defined(_USE_STATIC_INLINE)
#define _ARMABI_INLINE_DEF static __inline
#else
#define _ARMABI_INLINE_DEF __inline
#endif

  #ifndef __CTYPE_DECLS
  #define __CTYPE_DECLS

    #undef __CLIBNS

    #ifdef __cplusplus
      
        namespace std {
        #define __CLIBNS std::
        extern "C" {
    #else
      #define __CLIBNS
    #endif  /* __cplusplus */

/* AEABI portable ctype flag bits */
#define _ABI_A    1       /* alphabetic        */
#define _ABI_X    2       /* A-F, a-f and 0-9  */
#define _ABI_P    4       /* punctuation       */
#define _ABI_B    8       /* blank             */
#define _ABI_S   16       /* white space       */
#define _ABI_L   32       /* lower case letter */
#define _ABI_U   64       /* upper case letter */
#define _ABI_C  128       /* control chars     */

/* ARM internal ctype flag bits */
/* N.B. - keep in step with <ctype.c> */

/*
 * __ARM_CT_A (alphabetic) is required because characters in some locales
 * (e.g. Japanese) can be alphabetic but neither uppercase nor
 * lowercase. Unfortunately there wasn't a bit free for this, so
 * instead we've defined __ARM_CT_A as __ARM_CT_N+__ARM_CT_X (on the grounds that this
 * was a previously unused combination). Hence some of the ctype
 * predicates below are slightly less than obvious in
 * implementation.
 */
#define __ARM_CT_S 1            /* whitespace           */
#define __ARM_CT_P 2            /* punctuation          */
#define __ARM_CT_B 4            /* blank                */
#define __ARM_CT_L 8            /* lower case letter    */
#define __ARM_CT_U 16           /* upper case letter    */
#define __ARM_CT_N 32           /* (decimal) digit      */
#define __ARM_CT_C 64           /* control chars        */
#define __ARM_CT_X 128          /* A-F and a-f          */
#define __ARM_CT_A (__ARM_CT_N+__ARM_CT_X)    /* alphabetic           */

#if _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
  #define _AEABI_PORTABLE
#endif

#if _AEABI_PORTABILITY_LEVEL != 0 || (!defined _AEABI_PORTABILITY_LEVEL && __DEFAULT_AEABI_PORTABILITY_LEVEL != 0)

extern int (isalnum)(int /*c*/);
extern int (isalpha)(int /*c*/);
extern int (isblank)(int /*c*/);
extern int (iscntrl)(int /*c*/);
extern int (isdigit)(int /*c*/);
extern int (isgraph)(int /*c*/);
extern int (islower)(int /*c*/);
extern int (isprint)(int /*c*/);
extern int (ispunct)(int /*c*/);
extern int (isspace)(int /*c*/);
extern int (isupper)(int /*c*/);
extern int (isxdigit)(int /*c*/);

/* Mandatory character attribute arrays indexed from 0 to 256 */
extern unsigned char const __aeabi_ctype_table_C[257];  /* "C" locale */
extern unsigned char const __aeabi_ctype_table_[257];   /* default locale */
         /* The default locale might be the C locale */
/* Optional character attribute arrays indexed from 0 to 256.        */
/* These do not have to be provided by every execution environment   */
/* but, if provided, shall be provided with these names and meaning. */
extern unsigned char const __aeabi_ctype_table_ISO8859_1[257];
extern unsigned char const __aeabi_ctype_table_SJIS[257];
extern unsigned char const __aeabi_ctype_table_BIG5[257];
extern unsigned char const __aeabi_ctype_table_UTF8[257];
#ifdef _AEABI_LC_CTYPE
# define _AEABI_CTYPE_TABLE(_X) __aeabi_ctype_table_ ## _X
# define _AEABI_CTYPE(_X) _AEABI_CTYPE_TABLE(_X)
# define __aeabi_ctype_table _AEABI_CTYPE(_AEABI_LC_CTYPE)
#else
# define __aeabi_ctype_table __aeabi_ctype_table_
#endif

#define isspace(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] & _ABI_S)
#define isalpha(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] & _ABI_A)
#define isalnum(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] << 30) /* test for _ABI_A and _ABI_X */
#define isprint(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] << 28) /* test for _ABI_A, _ABI_X, _ABI_P and _ABI_B */
#define isupper(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] & _ABI_U)
#define islower(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] & _ABI_L)
#define isxdigit(x) ((__CLIBNS __aeabi_ctype_table+1)[(x)] & _ABI_X)
#define isgraph(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] << 29) /* test for _ABI_A, _ABI_X and _ABI_P */
#define iscntrl(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] & _ABI_C)
#define ispunct(x)  ((__CLIBNS __aeabi_ctype_table+1)[(x)] & _ABI_P)
#define isdigit(c)  (((unsigned)(c) - '0') < 10)

#else /* __AEABI_PORTABILITY_LEVEL */

extern _ARMABI_PURE unsigned char **__rt_ctype_table(void);

#define __arm_ctype (*__CLIBNS __rt_ctype_table())

#ifdef __cplusplus
    inline int isalnum(int __c) { return (__arm_ctype[__c] & (__ARM_CT_U+__ARM_CT_L+__ARM_CT_N)); }
#else
    #define isalnum(c) (__arm_ctype[c] & (__ARM_CT_U+__ARM_CT_L+__ARM_CT_N))
    extern int (isalnum)(int /*c*/);
#endif
    /* non-0 iff c is alphabetic or numeric */

#ifdef __cplusplus
    inline int isalpha(int __c) { return (__arm_ctype[__c] & (__ARM_CT_U+__ARM_CT_L+__ARM_CT_X)); }
#else
    #define isalpha(c) (__arm_ctype[c] & (__ARM_CT_U+__ARM_CT_L+__ARM_CT_X))
    extern int (isalpha)(int /*c*/);
#endif
    /* non-0 iff c is alphabetic */

#ifdef __cplusplus
    inline int iscntrl(int __c) { return (__arm_ctype[__c] & __ARM_CT_C); }
#else
    #define iscntrl(c) (__arm_ctype[c] & __ARM_CT_C)
    extern int (iscntrl)(int /*c*/);
#endif
    /* non-0 iff c is a control character - in the "C" locale */
    /*       this means (c < ' ') || (c > '~')                */

/* isdigit must test for the presence of _only_ __ARM_CT_N, not just __ARM_CT_N at all. */
#ifdef __cplusplus
    inline int isdigit(int __c) { return (__arm_ctype[__c] == __ARM_CT_N); }
#else
    #define isdigit(c) (__arm_ctype[c] == __ARM_CT_N)
    extern int (isdigit)(int /*c*/);
#endif
    /* non-0 iff c is a decimal digit */

    extern int (isblank)(int /*c*/);
    /* non-0 iff c is ' ', '\t' or some other locale-specific, */
    /* word-separating character (there are no others in "C"   */
    /* locale) */

#ifdef __cplusplus
    inline int isgraph(int __c) {return(__arm_ctype[__c] & (__ARM_CT_L+__ARM_CT_U+__ARM_CT_N+__ARM_CT_X+__ARM_CT_P));}
#else
    #define isgraph(c) (__arm_ctype[c]&(__ARM_CT_L+__ARM_CT_U+__ARM_CT_N+__ARM_CT_X+__ARM_CT_P))
    extern int (isgraph)(int /*c*/);
#endif
    /* non-0 iff c is any printing character other than ' ' */

#ifdef __cplusplus
    inline int islower(int __c) { return (__arm_ctype[__c] & __ARM_CT_L); }
#else
    #define islower(c) (__arm_ctype[c] & __ARM_CT_L)
    extern int (islower)(int /*c*/);
#endif
    /* non-0 iff c is a lower-case letter */

#ifdef __cplusplus
    inline int isprint(int __c) { return (__arm_ctype[__c] & (__ARM_CT_L+__ARM_CT_U+__ARM_CT_N+__ARM_CT_P+__ARM_CT_B)); }
#else
    #define isprint(c) (__arm_ctype[c] & (__ARM_CT_L+__ARM_CT_U+__ARM_CT_N+__ARM_CT_P+__ARM_CT_B))
    extern int (isprint)(int /*c*/);
#endif
    /* non-0 iff c is a printing character - in the "C" locale */
    /*       this means 0x20 (space) -> 0x7E (tilde)           */

#ifdef __cplusplus
    inline int ispunct(int __c) { return (__arm_ctype[__c] & __ARM_CT_P); }
#else
    #define ispunct(c) (__arm_ctype[c] & __ARM_CT_P)
    extern int (ispunct)(int /*c*/);
#endif
    /* non-0 iff c is a non-space, non-alpha-numeric, printing character */

#ifdef __cplusplus
    inline int isspace(int __c) { return (__arm_ctype[__c] & __ARM_CT_S); }
#else
    #define isspace(c) (__arm_ctype[c] & __ARM_CT_S)
    extern int (isspace)(int /*c*/);
#endif
    /* non-0 iff c is a white-space char: ' ', '\f', '\n', '\r', '\t', '\v'. */

#ifdef __cplusplus
    inline int isupper(int __c) { return (__arm_ctype[__c] & __ARM_CT_U); }
#else
    #define isupper(c) (__arm_ctype[c] & __ARM_CT_U)
    extern int (isupper)(int /*c*/);
#endif
    /* non-0 iff c is an upper-case letter */

/* isxdigit must test for the presence of __ARM_CT_N or __ARM_CT_X but not both. */
/* This helper function avoids needing to evaluate c twice. */

_ARMABI_INLINE_DEF int __isxdigit_helper(int __t) { return (__t ^ (__t << 2)); }
#ifdef __cplusplus
    inline int isxdigit(int __c){return __isxdigit_helper(__arm_ctype[__c]) & __ARM_CT_X;}
#else
    #define isxdigit(c) (__isxdigit_helper(__arm_ctype[c]) & __ARM_CT_X)
    extern int (isxdigit)(int /*c*/);
#endif
    /* non-0 iff c is a digit, in 'a'..'f', or in 'A'..'F' */

#endif /* __AEABI_PORTABILITY_LEVEL */

extern int tolower(int /*c*/);
    /* if c is an upper-case letter then return the corresponding */
    /* lower-case letter, otherwise return c.                     */

extern int toupper(int /*c*/);
    /* if c is an lower-case letter then return the corresponding */
    /* upper-case letter, otherwise return c.                     */

    #ifdef __cplusplus
         }  /* extern "C" */
      }  /* namespace std */
    #endif /* __cplusplus */
  #endif /* __CTYPE_DECLS */

  #ifdef __cplusplus
    #ifndef __CTYPE_NO_EXPORTS
      using ::std::isalnum;
      using ::std::isalpha;
      using ::std::iscntrl;
      using ::std::isdigit;
      using ::std::isblank;
      using ::std::isgraph;
      using ::std::islower;
      using ::std::isprint;
      using ::std::ispunct;
      using ::std::isspace;
      using ::std::isupper;
      using ::std::isxdigit;
      using ::std::tolower;
      using ::std::toupper;
    #endif /* __CTYPE_NO_EXPORTS */
  #endif /* __cplusplus */

#endif

/* end of ctype.h */

