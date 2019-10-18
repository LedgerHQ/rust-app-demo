/* locale.h: ANSI 'C' (X3J11 Oct 88) library header, section 4.3 */
/* Copyright (C) Codemist Ltd., 1988                            */
/* Copyright 1991,1999,2014 ARM Limited. All rights reserved.   */
/* version 0.03 */

/*
 * RCS $Revision$
 * Checkin $Date$
 * Revising $Author: drodgman $
 */

#ifndef __locale_h
#define __locale_h
#define __ARMCLIB_VERSION 6090000

#define _ARMABI __attribute__((nothrow))

  #ifndef __LOCALE_DECLS
  #define __LOCALE_DECLS

    #undef __CLIBNS

    #ifdef __cplusplus
      namespace std {
          #define __CLIBNS std::
          extern "C" {
    #else
      #define __CLIBNS
    #endif  /* __cplusplus */

/* Handles national characteristics */

#if _AEABI_PORTABILITY_LEVEL != 0 || (!defined _AEABI_PORTABILITY_LEVEL && __DEFAULT_AEABI_PORTABILITY_LEVEL != 0)
extern const int __aeabi_LC_COLLATE;
#define LC_COLLATE (__CLIBNS __aeabi_LC_COLLATE)
extern const int __aeabi_LC_CTYPE;
#define LC_CTYPE (__CLIBNS __aeabi_LC_CTYPE)
extern const int __aeabi_LC_MONETARY;
#define LC_MONETARY (__CLIBNS __aeabi_LC_MONETARY)
extern const int __aeabi_LC_NUMERIC;
#define LC_NUMERIC (__CLIBNS __aeabi_LC_NUMERIC)
extern const int __aeabi_LC_TIME;
#define LC_TIME (__CLIBNS __aeabi_LC_TIME)
extern const int __aeabi_LC_ALL;
#define LC_ALL (__CLIBNS __aeabi_LC_ALL)
#else
#define LC_COLLATE  1
    /* affects the behaviour of the strcoll function */
#define LC_CTYPE    2
    /* affects the behaviour of the character handling functions */
    /* (isdigit, isspace and isxdigit are not affected) */
#define LC_MONETARY 4
    /* affects the monetary formatting information returned by the */
    /* localeconv function. */
#define LC_NUMERIC  8
    /* affects the decimal-point character for the formatted input/output */
    /* functions and the string conversion functions */
#define LC_TIME    16
    /* could affect the behaviour of the strftime function but doesn't */
    /* for currently supported locales */
#define LC_ALL      (LC_TIME|LC_NUMERIC|LC_MONETARY|LC_CTYPE|LC_COLLATE)
    /* program's entire locale */
#endif

extern _ARMABI char *setlocale(int /*category*/, const char * /*locale*/);
  /*
   * Selects the appropriate piece of the program's locale as specified by the
   * category and locale arguments. The setlocale function may be used to
   * change or query the program's entire current locale or portions thereof.
   * The effect of the category argument for each value is described above.
   * A value of "C" for locale specifies the minimal environment for C
   * translation; a value of "" for locale specifies the implementation-defined
   * native environment. At program startup the equivalent of
   * setlocale(LC_ALL, "C") is executed.
   *
   * Return value:
   * If a pointer to string is given for locale and the selection can be
   * honoured, the string associated with the specified category for the new
   * locale is returned. If the selction can not be honoured, a null pointer
   * is returned and the program's locale is not changed.
   * A null pointer for locale causes the string associated with the category
   * for the program's current locale to be returned and the program's locale
   * is not changed. If the category is LC_ALL and the most recent successful
   * locale-setting call used a category other than LC_ALL a composite string
   * may need to be returned.
   * The string returned is such that a subsequent call with that string and
   * its associated category will restore that part of the program's locale.
   * The string returned shall not be modified by the program, but may be
   * overwritten by a subsequent call to setlocale.
   */

#if __sizeof_ptr == 8
#define _SETLOCALE_R_BUFSIZE 82
#else
#define _SETLOCALE_R_BUFSIZE 42
#endif
extern _ARMABI char *_setlocale_r(char * /*buffer*/, int /*category*/, const char * /*locale*/);
  /*
   * Same as setlocale(), but writes the output string into a buffer
   * provided by the user instead of a static one. The buffer must
   * be at least _SETLOCALE_R_BUFSIZE bytes long (including space
   * for a trailing NUL).
   *
   * Note that these functions are not necessarily thread-safe: when
   * called in a mode which changes the locale setting, they still
   * modify the locale state without any locking protection. It's
   * only the output buffer which is made safe by using these.
   */

#if __ARMCOMPILER_VERSION < 6000000
#pragma push
#pragma anon_unions
#endif
struct lconv {
  char *decimal_point;
       /* The decimal point character used to format non-monetary quantities */
  char *thousands_sep;
       /* The character used to separate groups of digits to the left of the */
       /* decimal point character in formatted non-monetary quantities.      */
  char *grouping;
       /* A string whose elements indicate the size of each group of digits  */
       /* in formatted non-monetary quantities. See below for more details.  */
  char *int_curr_symbol;
       /* The international currency symbol applicable to the current locale.*/
       /* The first three characters contain the alphabetic international    */
       /* currency symbol in accordance with those specified in ISO 4217     */
       /* Codes for the representation of Currency and Funds. The fourth     */
       /* character (immediately preceding the null character) is the        */
       /* character used to separate the international currency symbol from  */
       /* the monetary quantity.                                             */
  char *currency_symbol;
       /* The local currency symbol applicable to the current locale.        */
  char *mon_decimal_point;
       /* The decimal-point used to format monetary quantities.              */
  char *mon_thousands_sep;
       /* The separator for groups of digits to the left of the decimal-point*/
       /* in formatted monetary quantities.                                  */
  char *mon_grouping;
       /* A string whose elements indicate the size of each group of digits  */
       /* in formatted monetary quantities. See below for more details.      */
  char *positive_sign;
       /* The string used to indicate a nonnegative-valued formatted         */
       /* monetary quantity.                                                 */
  char *negative_sign;
       /* The string used to indicate a negative-valued formatted monetary   */
       /* quantity.                                                          */
  char int_frac_digits;
       /* The number of fractional digits (those to the right of the         */
       /* decimal-point) to be displayed in an internationally formatted     */
       /* monetary quantities.                                               */
  char frac_digits;
       /* The number of fractional digits (those to the right of the         */
       /* decimal-point) to be displayed in a formatted monetary quantity.   */
  char p_cs_precedes;
       /* Set to 1 or 0 if the currency_symbol respectively precedes or      */
       /* succeeds the value for a nonnegative formatted monetary quantity.  */
  char p_sep_by_space;
       /* Set to 1 or 0 if the currency_symbol respectively is or is not     */
       /* separated by a space from the value for a nonnegative formatted    */
       /* monetary quantity.                                                 */
  char n_cs_precedes;
       /* Set to 1 or 0 if the currency_symbol respectively precedes or      */
       /* succeeds the value for a negative formatted monetary quantity.     */
  char n_sep_by_space;
       /* Set to 1 or 0 if the currency_symbol respectively is or is not     */
       /* separated by a space from the value for a negative formatted       */
       /* monetary quantity.                                                 */
  char p_sign_posn;
       /* Set to a value indicating the position of the positive_sign for a  */
       /* nonnegative formatted monetary quantity. See below for more details*/
  char n_sign_posn;
       /* Set to a value indicating the position of the negative_sign for a  */
       /* negative formatted monetary quantity. See below for more details.  */

  /*
   * The elements of grouping amd mon_grouping are interpreted according to
   * the following:
   * CHAR_MAX   No further grouping is to be performed.
   * 0          The previous element is to be repeatedly used for the
   *            remainder of the digits.
   * other      The value is the number of digits that compromise the current
   *            group. The next element is examined to determine the size of
   *            the next group of digits to the left of the current group.
   *
   * The value of p_sign_posn and n_sign_posn is interpreted according to
   * the following:
   * 0          Parentheses surround the quantity and currency_symbol.
   * 1          The sign string preceeds the quantity and currency_symbol.
   * 2          The sign string succeeds the quantity and currency_symbol.
   * 3          The sign string immediately preceeds the currency_symbol.
   * 4          The sign string immediately succeeds the currency_symbol.
   */

    /* The following are new fields introduced in the C99 standard.
     * 
     * In order to not break compatibility with the C89/90 standard, the fields
     * are conditionally included. However, to keep the struct size the same
     * between objects compiled for different standards, we unconditionally
     * define an __XX member just to reserve the space (aliased). Note that
     * __XX symbols should not clash with user defined symbols as such names are
     * reserved by the standard.
     */
    union {
        char __int_p_cs_precedes;
#if !defined(int_p_cs_precedes) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_p_cs_precedes;
#endif
    };
    union {
        char __int_n_cs_precedes;
#if !defined(int_n_cs_precedes) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_n_cs_precedes;
#endif
    };
    union {
        char __int_p_sep_by_space;
#if !defined(int_p_sep_by_space) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_p_sep_by_space;
#endif
    };
    union {
        char __int_n_sep_by_space;
#if !defined(int_n_sep_by_space) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_n_sep_by_space;
#endif
    };
    union {
        char __int_p_sign_posn;
#if !defined(int_p_sign_posn) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_p_sign_posn;
#endif
    };
    union {
        char __int_n_sign_posn;
#if !defined(int_n_sign_posn) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_n_sign_posn;
#endif
    };
};
#if __ARMCOMPILER_VERSION < 6000000
#pragma pop /* restore setting of anon_unions */
#endif

extern _ARMABI struct lconv *localeconv(void);
  /*
   * Sets the components of an object with type struct lconv with values
   * appropriate for the formatting of numeric quantities (monetary and
   * otherwise) according to the rules of the current locale.
   * The members of the structure with type char * are strings, any of which
   * (except decimal_point) can point to "", to indicate that the value is not
   * available in the current locale or is of zero length. The members with
   * type char are nonnegative numbers, any of which can be CHAR_MAX to
   * indicate that the value is not available in the current locale.
   * The members included are described above.
   *
   * Return value:
   * A pointer to the filled in object. The structure pointed to by the return
   * value shall not be modified by the program, but may be overwritten by a
   * subsequent call to the localeconv function. In addition, calls to the
   * setlocale function with categories LC_ALL, LC_MONETARY, or LC_NUMERIC may
   * overwrite the contents of the structure.
   */

extern _ARMABI void _get_lconv(struct lconv * /*result*/) __attribute__((__nonnull__(1)));
    /*
     * Fills in the provided `lconv' structure exactly as
     * localeconv does. This ANSI extension removes the need for
     * static data within the library.
     */

/*
 * EABI-defined version of the lconv structure.
 */
#if __ARMCOMPILER_VERSION < 6000000
#pragma push
#pragma anon_unions
#endif
struct __aeabi_lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    /* The  following fields are added by C99 */

    union {
        char __int_p_cs_precedes;
#if !defined(int_p_cs_precedes) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_p_cs_precedes;
#endif
    };
    union {
        char __int_n_cs_precedes;
#if !defined(int_n_cs_precedes) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_n_cs_precedes;
#endif
    };
    union {
        char __int_p_sep_by_space;
#if !defined(int_p_sep_by_space) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_p_sep_by_space;
#endif
    };
    union {
        char __int_n_sep_by_space;
#if !defined(int_n_sep_by_space) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_n_sep_by_space;
#endif
    };
    union {
        char __int_p_sign_posn;
#if !defined(int_p_sign_posn) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_p_sign_posn;
#endif
    };
    union {
        char __int_n_sign_posn;
#if !defined(int_n_sign_posn) || (defined(__STDC_VERSION__) && 199901L <= __STDC_VERSION__) || (defined(__cplusplus) && 201103L <= __cplusplus)
        char int_n_sign_posn;
#endif
    };
};
#if __ARMCOMPILER_VERSION < 6000000
#pragma pop /* restore setting of anon_unions */
#endif

extern _ARMABI struct __aeabi_lconv *__aeabi_localeconv(void);
extern _ARMABI void _get_aeabi_lconv(struct __aeabi_lconv * /*result*/) __attribute__((__nonnull__(1)));

#undef NULL
#define NULL 0                   /* see <stddef.h> */

    #ifdef __cplusplus
         }  /* extern "C" */
      }  /* namespace std */
    #endif /* __cplusplus */
  #endif /* __LOCALE_DECLS */

  #if _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
    #define _AEABI_PORTABLE
  #endif

  #ifdef __cplusplus
    #ifndef __LOCALE_NO_EXPORTS
      using ::std::setlocale;
      using ::std::_setlocale_r;
      using ::std::lconv;
      using ::std::localeconv;
      using ::std::_get_lconv;
      using ::std::__aeabi_lconv;
      using ::std::__aeabi_localeconv;
      using ::std::_get_aeabi_lconv;
    #endif 
  #endif /* __cplusplus */

#endif

/* end of locale.h */

