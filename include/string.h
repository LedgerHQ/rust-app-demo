/* string.h: ANSI 'C' (X3J11 Oct 88) library header, section 4.11 */
/* Copyright (C) Codemist Ltd., 1988-1993.                        */
/* Copyright 1991-1993 ARM Limited. All rights reserved.          */
/* version 0.04 */

/*
 * RCS $Revision$
 * Checkin $Date$
 */

/*
 * string.h declares one type and several functions, and defines one macro
 * useful for manipulating character arrays and other objects treated as
 * character arrays. Various methods are used for determining the lengths of
 * the arrays, but in all cases a char * or void * argument points to the
 * initial (lowest addresses) character of the array. If an array is written
 * beyond the end of an object, the behaviour is undefined.
 */

#ifndef __string_h
#define __string_h
#define __ARMCLIB_VERSION 6090000

#define _ARMABI __attribute__((nothrow))

  #ifndef __STRING_DECLS
  #define __STRING_DECLS

    #undef __CLIBNS

    #ifdef __cplusplus
        namespace std {
        #define __CLIBNS std::
        extern "C" {
    #else
      #define __CLIBNS
    #endif  /* __cplusplus */

#if defined(__cplusplus) || !defined(__STRICT_ANSI__)
 /* unconditional in C++ and non-strict C for consistency of debug info */
  #if __sizeof_ptr == 8
    typedef unsigned long size_t;   /* see <stddef.h> */
  #else
    typedef unsigned int size_t;   /* see <stddef.h> */
  #endif
#elif !defined(__size_t)
  #define __size_t 1
  #if __sizeof_ptr == 8
    typedef unsigned long size_t;   /* see <stddef.h> */
  #else
    typedef unsigned int size_t;   /* see <stddef.h> */
  #endif
#endif

#undef NULL
#define NULL 0                   /* see <stddef.h> */

extern _ARMABI void *memcpy(void * __restrict /*s1*/,
                    const void * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
   /*
    * copies n characters from the object pointed to by s2 into the object
    * pointed to by s1. If copying takes place between objects that overlap,
    * the behaviour is undefined.
    * Returns: the value of s1.
    */
extern _ARMABI void *memmove(void * /*s1*/,
                    const void * /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
   /*
    * copies n characters from the object pointed to by s2 into the object
    * pointed to by s1. Copying takes place as if the n characters from the
    * object pointed to by s2 are first copied into a temporary array of n
    * characters that does not overlap the objects pointed to by s1 and s2,
    * and then the n characters from the temporary array are copied into the
    * object pointed to by s1.
    * Returns: the value of s1.
    */
extern _ARMABI char *strcpy(char * __restrict /*s1*/, const char * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
   /*
    * copies the string pointed to by s2 (including the terminating nul
    * character) into the array pointed to by s1. If copying takes place
    * between objects that overlap, the behaviour is undefined.
    * Returns: the value of s1.
    */
extern _ARMABI char *strncpy(char * __restrict /*s1*/, const char * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
   /*
    * copies not more than n characters (characters that follow a null
    * character are not copied) from the array pointed to by s2 into the array
    * pointed to by s1. If copying takes place between objects that overlap,
    * the behaviour is undefined.
    * Returns: the value of s1.
    */

extern _ARMABI char *strcat(char * __restrict /*s1*/, const char * __restrict /*s2*/) __attribute__((__nonnull__(1,2)));
   /*
    * appends a copy of the string pointed to by s2 (including the terminating
    * null character) to the end of the string pointed to by s1. The initial
    * character of s2 overwrites the null character at the end of s1.
    * Returns: the value of s1.
    */
extern _ARMABI char *strncat(char * __restrict /*s1*/, const char * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
   /*
    * appends not more than n characters (a null character and characters that
    * follow it are not appended) from the array pointed to by s2 to the end of
    * the string pointed to by s1. The initial character of s2 overwrites the
    * null character at the end of s1. A terminating null character is always
    * appended to the result.
    * Returns: the value of s1.
    */

/*
 * The sign of a nonzero value returned by the comparison functions is
 * determined by the sign of the difference between the values of the first
 * pair of characters (both interpreted as unsigned char) that differ in the
 * objects being compared.
 */

extern _ARMABI int memcmp(const void * /*s1*/, const void * /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
   /*
    * compares the first n characters of the object pointed to by s1 to the
    * first n characters of the object pointed to by s2.
    * Returns: an integer greater than, equal to, or less than zero, according
    *          as the object pointed to by s1 is greater than, equal to, or
    *          less than the object pointed to by s2.
    */
extern _ARMABI int strcmp(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
   /*
    * compares the string pointed to by s1 to the string pointed to by s2.
    * Returns: an integer greater than, equal to, or less than zero, according
    *          as the string pointed to by s1 is greater than, equal to, or
    *          less than the string pointed to by s2.
    */
extern _ARMABI int strncmp(const char * /*s1*/, const char * /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
   /*
    * compares not more than n characters (characters that follow a null
    * character are not compared) from the array pointed to by s1 to the array
    * pointed to by s2.
    * Returns: an integer greater than, equal to, or less than zero, according
    *          as the string pointed to by s1 is greater than, equal to, or
    *          less than the string pointed to by s2.
    */
extern _ARMABI int strcasecmp(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
   /*
    * compares the string pointed to by s1 to the string pointed to by s2,
    * case-insensitively as defined by the current locale.
    * Returns: an integer greater than, equal to, or less than zero, according
    *          as the string pointed to by s1 is greater than, equal to, or
    *          less than the string pointed to by s2.
    */
extern _ARMABI int strncasecmp(const char * /*s1*/, const char * /*s2*/, size_t /*n*/) __attribute__((__nonnull__(1,2)));
   /*
    * compares not more than n characters (characters that follow a null
    * character are not compared) from the array pointed to by s1 to the array
    * pointed to by s2, case-insensitively as defined by the current locale.
    * Returns: an integer greater than, equal to, or less than zero, according
    *          as the string pointed to by s1 is greater than, equal to, or
    *          less than the string pointed to by s2.
    */
extern _ARMABI int strcoll(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
   /*
    * compares the string pointed to by s1 to the string pointed to by s2, both
    * interpreted as appropriate to the LC_COLLATE category of the current
    * locale.
    * Returns: an integer greater than, equal to, or less than zero, according
    *          as the string pointed to by s1 is greater than, equal to, or
    *          less than the string pointed to by s2 when both are interpreted
    *          as appropriate to the current locale.
    */

extern _ARMABI size_t strxfrm(char * __restrict /*s1*/, const char * __restrict /*s2*/, size_t /*n*/) __attribute__((__nonnull__(2)));
   /*
    * transforms the string pointed to by s2 and places the resulting string
    * into the array pointed to by s1. The transformation function is such that
    * if the strcmp function is applied to two transformed strings, it returns
    * a value greater than, equal to or less than zero, corresponding to the
    * result of the strcoll function applied to the same two original strings.
    * No more than n characters are placed into the resulting array pointed to
    * by s1, including the terminating null character. If n is zero, s1 is
    * permitted to be a null pointer. If copying takes place between objects
    * that overlap, the behaviour is undefined.
    * Returns: The length of the transformed string is returned (not including
    *          the terminating null character). If the value returned is n or
    *          more, the contents of the array pointed to by s1 are
    *          indeterminate.
    */


#ifdef __cplusplus
extern _ARMABI const void *memchr(const void * /*s*/, int /*c*/, size_t /*n*/) __attribute__((__nonnull__(1)));
extern "C++" void *memchr(void * __s, int __c, size_t __n) __attribute__((__nonnull__(1)));
extern "C++" inline void *memchr(void * __s, int __c, size_t __n)
    { return const_cast<void *>(memchr(const_cast<const void *>(__s), __c, __n)); }
#else
extern _ARMABI void *memchr(const void * /*s*/, int /*c*/, size_t /*n*/) __attribute__((__nonnull__(1)));
#endif
   /*
    * locates the first occurence of c (converted to an unsigned char) in the
    * initial n characters (each interpreted as unsigned char) of the object
    * pointed to by s.
    * Returns: a pointer to the located character, or a null pointer if the
    *          character does not occur in the object.
    */

#ifdef __cplusplus
extern _ARMABI const char *strchr(const char * /*s*/, int /*c*/) __attribute__((__nonnull__(1)));
extern "C++" char *strchr(char * __s, int __c) __attribute__((__nonnull__(1)));
extern "C++" inline char *strchr(char * __s, int __c)
    { return const_cast<char *>(strchr(const_cast<const char *>(__s), __c)); }
#else
extern _ARMABI char *strchr(const char * /*s*/, int /*c*/) __attribute__((__nonnull__(1)));
#endif
   /*
    * locates the first occurence of c (converted to an char) in the string
    * pointed to by s (including the terminating null character).
    * Returns: a pointer to the located character, or a null pointer if the
    *          character does not occur in the string.
    */

extern _ARMABI size_t strcspn(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
   /*
    * computes the length of the initial segment of the string pointed to by s1
    * which consists entirely of characters not from the string pointed to by
    * s2. The terminating null character is not considered part of s2.
    * Returns: the length of the segment.
    */

#ifdef __cplusplus
extern _ARMABI const char *strpbrk(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
extern "C++" char *strpbrk(char * __s1, const char * __s2) __attribute__((__nonnull__(1,2)));
extern "C++" inline char *strpbrk(char * __s1, const char * __s2)
    { return const_cast<char *>(strpbrk(const_cast<const char *>(__s1), __s2)); }
#else
extern _ARMABI char *strpbrk(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
#endif
   /*
    * locates the first occurence in the string pointed to by s1 of any
    * character from the string pointed to by s2.
    * Returns: returns a pointer to the character, or a null pointer if no
    *          character form s2 occurs in s1.
    */

#ifdef __cplusplus
extern _ARMABI const char *strrchr(const char * /*s*/, int /*c*/) __attribute__((__nonnull__(1)));
extern "C++" char *strrchr(char * __s, int __c) __attribute__((__nonnull__(1)));
extern "C++" inline char *strrchr(char * __s, int __c)
    { return const_cast<char *>(strrchr(const_cast<const char *>(__s), __c)); }
#else
extern _ARMABI char *strrchr(const char * /*s*/, int /*c*/) __attribute__((__nonnull__(1)));
#endif
   /*
    * locates the last occurence of c (converted to a char) in the string
    * pointed to by s. The terminating null character is considered part of
    * the string.
    * Returns: returns a pointer to the character, or a null pointer if c does
    *          not occur in the string.
    */

extern _ARMABI size_t strspn(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
   /*
    * computes the length of the initial segment of the string pointed to by s1
    * which consists entirely of characters from the string pointed to by S2
    * Returns: the length of the segment.
    */

#ifdef __cplusplus
extern _ARMABI const char *strstr(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
extern "C++" char *strstr(char * __s1, const char * __s2) __attribute__((__nonnull__(1,2)));
extern "C++" inline char *strstr(char * __s1, const char * __s2)
    { return const_cast<char *>(strstr(const_cast<const char *>(__s1), __s2)); }
#else
extern _ARMABI char *strstr(const char * /*s1*/, const char * /*s2*/) __attribute__((__nonnull__(1,2)));
#endif
   /*
    * locates the first occurence in the string pointed to by s1 of the
    * sequence of characters (excluding the terminating null character) in the
    * string pointed to by s2.
    * Returns: a pointer to the located string, or a null pointer if the string
    *          is not found.
    */

extern _ARMABI char *strtok(char * __restrict /*s1*/, const char * __restrict /*s2*/) __attribute__((__nonnull__(2)));
extern _ARMABI char *_strtok_r(char * /*s1*/, const char * /*s2*/, char ** /*ptr*/) __attribute__((__nonnull__(2,3)));
#ifndef __STRICT_ANSI__
extern _ARMABI char *strtok_r(char * /*s1*/, const char * /*s2*/, char ** /*ptr*/) __attribute__((__nonnull__(2,3)));
#endif
   /*
    * A sequence of calls to the strtok function breaks the string pointed to
    * by s1 into a sequence of tokens, each of which is delimited by a
    * character from the string pointed to by s2. The first call in the
    * sequence has s1 as its first argument, and is followed by calls with a
    * null pointer as their first argument. The separator string pointed to by
    * s2 may be different from call to call.
    * The first call in the sequence searches for the first character that is
    * not contained in the current separator string s2. If no such character
    * is found, then there are no tokens in s1 and the strtok function returns
    * a null pointer. If such a character is found, it is the start of the
    * first token.
    * The strtok function then searches from there for a character that is
    * contained in the current separator string. If no such character is found,
    * the current token extends to the end of the string pointed to by s1, and
    * subsequent searches for a token will fail. If such a character is found,
    * it is overwritten by a null character, which terminates the current
    * token. The strtok function saves a pointer to the following character,
    * from which the next search for a token will start.
    * Each subsequent call, with a null pointer as the value for the first
    * argument, starts searching from the saved pointer and behaves as
    * described above.
    * Returns: pointer to the first character of a token, or a null pointer if
    *          there is no token.
    *
    * strtok_r() is a common extension which works exactly like
    * strtok(), but instead of storing its state in a hidden
    * library variable, requires the user to pass in a pointer to a
    * char * variable which will be used instead. Any sequence of
    * calls to strtok_r() passing the same char ** pointer should
    * behave exactly like the corresponding sequence of calls to
    * strtok(). This means that strtok_r() can safely be used in
    * multi-threaded programs, and also that you can tokenise two
    * strings in parallel.
    */

extern _ARMABI void *memset(void * /*s*/, int /*c*/, size_t /*n*/) __attribute__((__nonnull__(1)));
   /*
    * copies the value of c (converted to an unsigned char) into each of the
    * first n charactes of the object pointed to by s.
    * Returns: the value of s.
    */
extern _ARMABI char *strerror(int /*errnum*/);
   /*
    * maps the error number in errnum to an error message string.
    * Returns: a pointer to the string, the contents of which are
    *          implementation-defined. The array pointed to shall not be
    *          modified by the program, but may be overwritten by a
    *          subsequent call to the strerror function.
    */
extern _ARMABI size_t strlen(const char * /*s*/) __attribute__((__nonnull__(1)));
   /*
    * computes the length of the string pointed to by s.
    * Returns: the number of characters that precede the terminating null
    *          character.
    */

extern _ARMABI size_t strlcpy(char * /*dst*/, const char * /*src*/, size_t /*len*/) __attribute__((__nonnull__(1,2)));
   /*
    * copies the string src into the string dst, using no more than
    * len bytes of dst. Always null-terminates dst _within the
    * length len (i.e. will copy at most len-1 bytes of string plus
    * a NUL), unless len is actually zero.
    * 
    * Return value is the length of the string that _would_ have
    * been written, i.e. the length of src. Thus, the operation
    * succeeded without truncation if and only if ret < len;
    * otherwise, the value in ret tells you how big to make dst if
    * you decide to reallocate it. (That value does _not_ include
    * the NUL.)
    * 
    * This is a BSD-derived library extension, which we are
    * permitted to declare in a standard header because ISO defines
    * function names beginning with 'str' as reserved for future
    * expansion of <string.h>.
    */

extern _ARMABI size_t strlcat(char * /*dst*/, const char * /*src*/, size_t /*len*/) __attribute__((__nonnull__(1,2)));
   /*
    * concatenates the string src to the string dst, using no more
    * than len bytes of dst. Always null-terminates dst _within the
    * length len (i.e. will copy at most len-1 bytes of string plus
    * a NUL), unless len is actually zero.
    * 
    * Return value is the length of the string that _would_ have
    * been written, i.e. the length of src plus the original length
    * of dst. Thus, the operation succeeded without truncation if
    * and only if ret < len; otherwise, the value in ret tells you
    * how big to make dst if you decide to reallocate it. (That
    * value does _not_ include the NUL.)
    * 
    * If no NUL is encountered within the first len bytes of dst,
    * then the length of dst is considered to have been equal to
    * len for the purposes of the return value (as if there were a
    * NUL at dst[len]). Thus, the return value in this case is len
    * + strlen(src).
    * 
    * This is a BSD-derived library extension, which we are
    * permitted to declare in a standard header because ISO defines
    * function names beginning with 'str' as reserved for future
    * expansion of <string.h>.
    */

extern _ARMABI void _membitcpybl(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitcpybb(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitcpyhl(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitcpyhb(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitcpywl(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitcpywb(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitmovebl(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitmovebb(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitmovehl(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitmovehb(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitmovewl(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
extern _ARMABI void _membitmovewb(void * /*dest*/, const void * /*src*/, int /*destoffset*/, int /*srcoffset*/, size_t /*nbits*/) __attribute__((__nonnull__(1,2)));
    /*
     * Copies or moves a piece of memory from one place to another,
     * with one-bit granularity. So you can start or finish a copy
     * part way through a byte, and you can copy between regions
     * with different alignment within a byte.
     * 
     * All these functions have the same prototype: two void *
     * pointers for destination and source, then two integers
     * giving the bit offset from those pointers, and finally the
     * number of bits to copy.
     * 
     * Just like memcpy and memmove, the "cpy" functions copy as
     * fast as they can in the assumption that the memory regions
     * do not overlap, while the "move" functions cope correctly
     * with overlap.
     *
     * Treating memory as a stream of individual bits requires
     * defining a convention about what order those bits are
     * considered to be arranged in. The above functions support
     * multiple conventions:
     * 
     *  - the "bl" functions consider the unit of memory to be the
     *    byte, and consider the bits within each byte to be
     *    arranged in little-endian fashion, so that the LSB comes
     *    first. (For example, membitcpybl(a,b,0,7,1) would copy
     *    the MSB of the byte at b to the LSB of the byte at a.)
     * 
     *  - the "bb" functions consider the unit of memory to be the
     *    byte, and consider the bits within each byte to be
     *    arranged in big-endian fashion, so that the MSB comes
     *    first.
     * 
     *  - the "hl" functions consider the unit of memory to be the
     *    16-bit halfword, and consider the bits within each word
     *    to be arranged in little-endian fashion.
     * 
     *  - the "hb" functions consider the unit of memory to be the
     *    16-bit halfword, and consider the bits within each word
     *    to be arranged in big-endian fashion.
     * 
     *  - the "wl" functions consider the unit of memory to be the
     *    32-bit word, and consider the bits within each word to be
     *    arranged in little-endian fashion.
     * 
     *  - the "wb" functions consider the unit of memory to be the
     *    32-bit word, and consider the bits within each word to be
     *    arranged in big-endian fashion.
     */

    #ifdef __cplusplus
         }  /* extern "C" */
      }  /* namespace std */
    #endif /* __cplusplus */
  #endif /* __STRING_DECLS */

  #ifdef __cplusplus
    #ifndef __STRING_NO_EXPORTS
      using ::std::size_t;
      using ::std::memcpy;
      using ::std::memmove;
      using ::std::strcpy;
      using ::std::strncpy;
      using ::std::strcat;
      using ::std::strncat;
      using ::std::memcmp;
      using ::std::strcmp;
      using ::std::strncmp;
      using ::std::strcasecmp;
      using ::std::strncasecmp;
      using ::std::strcoll;
      using ::std::strxfrm;
      using ::std::memchr;
      using ::std::strchr;
      using ::std::strcspn;
      using ::std::strpbrk;
      using ::std::strrchr;
      using ::std::strspn;
      using ::std::strstr;
      using ::std::strtok;
#ifndef __STRICT_ANSI__
      using ::std::strtok_r;
#endif
      using ::std::_strtok_r;
      using ::std::memset;
      using ::std::strerror;
      using ::std::strlen;
      using ::std::strlcpy;
      using ::std::strlcat;
      using ::std::_membitcpybl;
      using ::std::_membitcpybb;
      using ::std::_membitcpyhl;
      using ::std::_membitcpyhb;
      using ::std::_membitcpywl;
      using ::std::_membitcpywb;
      using ::std::_membitmovebl;
      using ::std::_membitmovebb;
      using ::std::_membitmovehl;
      using ::std::_membitmovehb;
      using ::std::_membitmovewl;
      using ::std::_membitmovewb;
    #endif /* __STRING_NO_EXPORTS */
  #endif /* __cplusplus */

#endif

/* end of string.h */

