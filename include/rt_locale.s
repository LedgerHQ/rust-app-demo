; rt_locale.s
;
; Copyright 2005 ARM Limited. All rights reserved.
;
; $Rev$
; $Date$
; $Author$

        GBLS    locale_type
        GBLS    locale_name
        GBLS    locale_sym
        GBLA    locale_count
locale_count SETA 0

; ----------------------------------------------------------------------
; Macros common to all types of locale block. Only one of these is
; expected to be called directly by users: LC_index_end, at the
; very end of a chain of locale blocks.

        MACRO
        LC_ALL_begin $prefix, $name, $type
locale_name SETS "$name"
locale_type SETS "$type"
locale_sym SETS "$prefix"
        MEND

        MACRO
        LC_ALL_header
$locale_sym._index DCD $locale_sym._end - .
$locale_sym._name DCB locale_name, 0
        ALIGN
        DCD $locale_sym._name - $locale_sym._start
$locale_sym._start
        MEND

        MACRO
        LC_ALL_trailer
        ALIGN
$locale_sym._end
locale_count SETA locale_count+1
        MEND

        MACRO
        LC_index_end
        ALIGN
        DCD 0
        MEND

; ----------------------------------------------------------------------
; Macros for LC_CTYPE. Users are expected to call:
;  - LC_CTYPE_begin to provide the symbol prefix and locale name
;  - LC_CTYPE_table to provide exactly 256 table entries
;  - LC_CTYPE_full_wctype, optionally, to indicate that the locale
;    should use full Unicode wctype rather than the small
;    ASCII-only variety
;  - LC_CTYPE_multibyte, optionally, to indicate that the locale is
;    a multi-byte character set and to provide its _mbrtowc and
;    _wcrtomb functions and its maximum character length
;  - LC_CTYPE_end to actually output the locale block.

        GBLS    locale_ctype_table
        GBLL    locale_ctype_full_wctype
        GBLL    locale_ctype_multibyte
        GBLS    locale_ctype_mbrtowc
        GBLS    locale_ctype_wcrtomb
        GBLA    locale_ctype_mbcurmax

__S     EQU     1                       ; whitespace
__P     EQU     2                       ; punctuation
__B     EQU     4                       ; blank
__L     EQU     8                       ; lower case letter
__U     EQU     16                      ; upper case letter
__N     EQU     32                      ; (decimal) digit
__C     EQU     64                      ; control chars
__X     EQU     128                     ; A-F and a-f
__A     EQU     __N+__X                 ; alphabetic
IL      EQU     0                       ; illegal char (in no categories)

        MACRO
        LC_CTYPE_begin $prefix, $name
        LC_ALL_begin $prefix, $name, "LC_CTYPE"
locale_ctype_table SETS ""
locale_ctype_full_wctype SETL {FALSE}
locale_ctype_multibyte SETL {FALSE}
        MEND

        MACRO
        LC_CTYPE_table $data
        [ locale_ctype_table = ""
locale_ctype_table SETS "$data"
        |
locale_ctype_table SETS locale_ctype_table :CC: "," :CC: "$data"
        ]
        MEND

        MACRO
        LC_CTYPE_full_wctype
locale_ctype_full_wctype SETL {TRUE}
        MEND

        MACRO
        LC_CTYPE_multibyte $mbrtowc, $wcrtomb, $mbcurmax
locale_ctype_multibyte SETL {TRUE}
locale_ctype_mbrtowc SETS "$mbrtowc"
locale_ctype_wcrtomb SETS "$wcrtomb"
locale_ctype_mbcurmax SETA $mbcurmax
        MEND

        MACRO
        LC_CTYPE_end
        LC_ALL_header
        DCB 0
$locale_sym._table
        DCB $locale_ctype_table
1
        ASSERT %B1 - $locale_sym._table = 256 ; check table length
        [ locale_ctype_full_wctype
        DCB 1
        |
        DCB 0
        ]
        [ locale_ctype_multibyte
        DCB 1
        ALIGN
        [ {CONFIG} = 64
        DCQ $locale_ctype_mbrtowc - .
        DCQ $locale_ctype_wcrtomb - .
        |
        DCD $locale_ctype_mbrtowc - .
        DCD $locale_ctype_wcrtomb - .
        ]
        DCD locale_ctype_mbcurmax
        ]
        LC_ALL_trailer
        MEND

; ----------------------------------------------------------------------
; Macros for LC_COLLATE. Users are expected to call:
;  - LC_COLLATE_begin to provide the symbol prefix and locale name
;  - LC_COLLATE_table, optionally, to provide exactly 256 table
;    entries
;  - LC_COLLATE_no_table, alternatlvely, if the collation locale is
;    trivial
;  - LC_COLLATE_end to actually output the locale block.

        GBLS    locale_collate_table
        GBLL    locale_collate_started
        GBLL    locale_collate_using_table

        MACRO
        LC_COLLATE_begin $prefix, $name
        LC_ALL_begin $prefix, $name, "LC_COLLATE"
locale_collate_table SETS ""
locale_collate_started SETL {FALSE}
        MEND

        MACRO
        LC_COLLATE_table $data
        [ locale_collate_started
        ASSERT  locale_collate_using_table = {TRUE}
        |
locale_collate_using_table SETL {TRUE}
        ]
        [ locale_collate_table = ""
locale_collate_table SETS "$data"
        |
locale_collate_table SETS locale_collate_table :CC: "," :CC: "$data"
        ]
locale_collate_started SETL {TRUE}
        MEND

        MACRO
        LC_COLLATE_no_table $data
        [ locale_collate_started
        ASSERT  locale_collate_using_table = {FALSE}
        |
locale_collate_using_table SETL {FALSE}
        ]
locale_collate_started SETL {TRUE}
        MEND

        MACRO
        LC_COLLATE_end
        LC_ALL_header
        ASSERT  locale_collate_started = {TRUE}
        [ locale_collate_using_table
        DCD     4                       ; offset to table from start of block
1
        DCB     $locale_collate_table
2
        ASSERT %B2 - %B1 = 256          ; check table length
        |
        DCD     0                       ; means no table at all
        ]
        LC_ALL_trailer
        MEND

; ----------------------------------------------------------------------
; Macros for LC_TIME. Users are expected to call:
;  - LC_TIME_begin to provide the symbol prefix and locale name
;  - LC_TIME_week_short seven times to provide short weekday strings
;  - LC_TIME_week_long seven times to provide long weekday strings
;  - LC_TIME_month_short twelve times to provide short month strings
;  - LC_TIME_month_long twelve times to provide long month strings
;  - LC_TIME_am_pm to provide a.m. and p.m. strings
;  - LC_TIME_formats to provide default date+time, date and time
;    format strings
;  - LC_TIME_c99format to provide the C99 default 12-hour time (%r)
;  - LC_TIME_end to actually output the locale block.

        MACRO
        LC_TIME_defs $prefix,$limit
        LCLA    i
i       SETA    1
        WHILE   i <= $limit
        GBLS    $prefix._$i
i       SETA    i+1
        WEND
        MEND

        LC_TIME_defs locale_time_week_short, 7
        LC_TIME_defs locale_time_week_long, 7
        GBLA    locale_time_week_short_maxlen
        GBLA    locale_time_week_short_count
        GBLA    locale_time_week_long_maxlen
        GBLA    locale_time_week_long_count

        LC_TIME_defs locale_time_month_short, 12
        LC_TIME_defs locale_time_month_long, 12
        GBLA    locale_time_month_short_maxlen
        GBLA    locale_time_month_short_count
        GBLA    locale_time_month_long_maxlen
        GBLA    locale_time_month_long_count

        GBLS    locale_time_am
        GBLS    locale_time_pm
        GBLS    locale_time_datetime
        GBLS    locale_time_date
        GBLS    locale_time_time
        GBLS    locale_time_12hrtime
        GBLL    locale_time_got12hrtime

        MACRO
        LC_TIME_begin $prefix, $name
        LC_ALL_begin $prefix, $name, "LC_TIME"
locale_time_week_short_count SETA 0
locale_time_week_long_count SETA 0
locale_time_month_short_count SETA 0
locale_time_month_long_count SETA 0
locale_time_got12hrtime SETL {FALSE}
        MEND

        MACRO
        LC_TIME_addstr_inner $var, $str, $maxlen
$var    SETS    "$str"
        [ $maxlen < :LEN: $var + 1
$maxlen SETA    :LEN: $var + 1
        ]
        MEND

        MACRO
        LC_TIME_addstr_outer $prefix, $limit, $str
        ASSERT $prefix._count < $limit
$prefix._count SETA $prefix._count + 1
        LCLA    z
z       SETA    $prefix._count
        LC_TIME_addstr_inner $prefix._$z, "$str", $prefix._maxlen
        MEND

        MACRO
        LC_TIME_dump $prefix, $limit
        LCLA    i
        LCLA    j
i       SETA    1
        WHILE   i <= $limit
        DCB     $prefix._$i, 0
j       SETA    0
        ; The very last element of a string array doesn't need
        ; final padding, since there's nothing beyond it that needs
        ; to be correctly aligned.
        [ i < $limit
        WHILE   j + :LEN:$prefix._$i + 1 < $prefix._maxlen
        DCB     0
j       SETA    j+1
        WEND
        ]
i       SETA    i+1
        WEND
        MEND

        MACRO
        LC_TIME_week_short $str
        LC_TIME_addstr_outer locale_time_week_short, 7, "$str"
        MEND

        MACRO
        LC_TIME_week_long $str
        LC_TIME_addstr_outer locale_time_week_long, 7, "$str"
        MEND

        MACRO
        LC_TIME_month_short $str
        LC_TIME_addstr_outer locale_time_month_short, 12, "$str"
        MEND

        MACRO
        LC_TIME_month_long $str
        LC_TIME_addstr_outer locale_time_month_long, 12, "$str"
        MEND

        MACRO
        LC_TIME_am_pm $am, $pm
locale_time_am SETS "$am"
locale_time_pm SETS "$pm"
        MEND

        MACRO
        LC_TIME_formats $datetime, $date, $time
locale_time_datetime SETS "$datetime"
locale_time_date SETS "$date"
locale_time_time SETS "$time"
        MEND

        MACRO
        LC_TIME_c99format $twelve
locale_time_12hrtime SETS "$twelve"
locale_time_got12hrtime SETL {TRUE}
        MEND

        MACRO
        LC_TIME_end
        LC_ALL_header
        LCLA    j

        DCD     $locale_sym._week_short - $locale_sym._start
        DCD     $locale_sym._week_long - $locale_sym._start
        DCD     $locale_sym._month_short - $locale_sym._start
        DCD     $locale_sym._month_long - $locale_sym._start
        DCD     $locale_sym._am - $locale_sym._start
        DCD     $locale_sym._pm - $locale_sym._start
        DCD     $locale_sym._datetime - $locale_sym._start
        DCD     $locale_sym._date - $locale_sym._start
        DCD     $locale_sym._time - $locale_sym._start
        DCD     locale_time_week_short_maxlen
        DCD     locale_time_week_long_maxlen
        DCD     locale_time_month_short_maxlen
        DCD     locale_time_month_long_maxlen
        [ locale_time_got12hrtime
        DCD     $locale_sym._12hrtime - $locale_sym._start
        ]
$locale_sym._week_short
        LC_TIME_dump locale_time_week_short, 7
$locale_sym._week_long
        LC_TIME_dump locale_time_week_long, 7
$locale_sym._month_short
        LC_TIME_dump locale_time_month_short, 12
$locale_sym._month_long
        LC_TIME_dump locale_time_month_long, 12
$locale_sym._am
        DCB     locale_time_am, 0
$locale_sym._pm
        DCB     locale_time_pm, 0
$locale_sym._datetime
        DCB     locale_time_datetime, 0
$locale_sym._date
        DCB     locale_time_date, 0
$locale_sym._time
        DCB     locale_time_time, 0
        [ locale_time_got12hrtime
$locale_sym._12hrtime
        DCB     locale_time_12hrtime, 0
        ]
        LC_ALL_trailer
        MEND

; ----------------------------------------------------------------------
; Macros for LC_NUMERIC. Users are expected to call:
;  - LC_NUMERIC_begin to provide the symbol prefix and locale name
;  - LC_NUMERIC_point to provide the decimal point string
;  - LC_NUMERIC_thousands to provide the thousands separator
;  - LC_NUMERIC_grouping to provide the grouping string
;  - LC_NUMERIC_end to actually output the locale block.

        GBLS    locale_numeric_point
        GBLS    locale_numeric_thousands
        GBLS    locale_numeric_grouping

        MACRO
        LC_NUMERIC_begin $prefix, $name
        LC_ALL_begin $prefix, $name, "LC_NUMERIC"
        MEND

        MACRO
        LC_NUMERIC_point $point
locale_numeric_point SETS "$point"
        MEND

        MACRO
        LC_NUMERIC_thousands $thousands
locale_numeric_thousands SETS "$thousands"
        MEND

        MACRO
        LC_NUMERIC_grouping $grouping
locale_numeric_grouping SETS "$grouping"
        MEND

        MACRO
        LC_NUMERIC_end
        LC_ALL_header
        DCD     $locale_sym._point - $locale_sym._start
        DCD     $locale_sym._thousands - $locale_sym._start
        DCD     $locale_sym._grouping - $locale_sym._start
$locale_sym._point
        DCB     locale_numeric_point, 0
$locale_sym._thousands
        DCB     locale_numeric_thousands, 0
$locale_sym._grouping
        DCB     locale_numeric_grouping, 0
        LC_ALL_trailer
        MEND

; ----------------------------------------------------------------------
; Macros for LC_MONETARY. Users are expected to call:
;  - LC_MONETARY_begin to provide the symbol prefix and locale name
;  - LC_MONETARY_fracdigits to provide frac_digits and int_frac_digits
;  - LC_MONETARY_positive for p_cs_precedes, p_sep_by_space,
;    p_sign_posn and positive_sign
;  - LC_MONETARY_negative for all the negative equivalents
;  - LC_MONETARY_currsymbol to provide the currency symbols
;  - LC_MONETARY_point to provide the decimal point string
;  - LC_MONETARY_thousands to provide the thousands separator
;  - LC_MONETARY_grouping to provide the grouping string
;  - LC_MONETARY_end to actually output the locale block.

        GBLA    locale_monetary_int_frac_digits
        GBLA    locale_monetary_frac_digits
        GBLA    locale_monetary_p_cs_precedes
        GBLA    locale_monetary_p_sep_space
        GBLA    locale_monetary_p_sign_posn
        GBLS    locale_monetary_p_sign
        GBLA    locale_monetary_n_cs_precedes
        GBLA    locale_monetary_n_sep_space
        GBLA    locale_monetary_n_sign_posn
        GBLS    locale_monetary_n_sign
        GBLS    locale_monetary_curr_symbol
        GBLS    locale_monetary_int_curr_symbol
        GBLS    locale_monetary_point
        GBLS    locale_monetary_thousands
        GBLS    locale_monetary_grouping

        MACRO
        LC_MONETARY_begin $prefix, $name
        LC_ALL_begin $prefix, $name, "LC_MONETARY"
        MEND

        MACRO
        LC_MONETARY_fracdigits $frac, $int
locale_monetary_int_frac_digits SETA $int
locale_monetary_frac_digits SETA $frac
        MEND

        MACRO
        LC_MONETARY_pn $p, $cs, $space, $sign, $signtext
locale_monetary_$p._cs_precedes SETA $cs
locale_monetary_$p._sep_space SETA $space
locale_monetary_$p._sign_posn SETA $sign
locale_monetary_$p._sign SETS "$signtext"
        MEND

        MACRO
        LC_MONETARY_positive $cs, $space, $sign, $signtext
        LC_MONETARY_pn p, $cs, $space, $sign, "$signtext"
        MEND

        MACRO
        LC_MONETARY_negative $cs, $space, $sign, $signtext
        LC_MONETARY_pn n, $cs, $space, $sign, "$signtext"
        MEND

        MACRO
        LC_MONETARY_currsymbol $cs, $intcs
locale_monetary_curr_symbol SETS "$cs"
locale_monetary_int_curr_symbol SETS "$intcs"
        MEND

        MACRO
        LC_MONETARY_point $point
locale_monetary_point SETS "$point"
        MEND

        MACRO
        LC_MONETARY_thousands $thousands
locale_monetary_thousands SETS "$thousands"
        MEND

        MACRO
        LC_MONETARY_grouping $grouping
locale_monetary_grouping SETS "$grouping"
        MEND

        MACRO
        LC_MONETARY_end
        LC_ALL_header
        DCB     locale_monetary_int_frac_digits
        DCB     locale_monetary_frac_digits
        DCB     locale_monetary_p_cs_precedes
        DCB     locale_monetary_p_sep_space
        DCB     locale_monetary_n_cs_precedes
        DCB     locale_monetary_n_sep_space
        DCB     locale_monetary_p_sign_posn
        DCB     locale_monetary_n_sign_posn
        DCD     $locale_sym._int_curr_symbol - $locale_sym._start
        DCD     $locale_sym._curr_symbol - $locale_sym._start
        DCD     $locale_sym._mon_point - $locale_sym._start
        DCD     $locale_sym._mon_thous - $locale_sym._start
        DCD     $locale_sym._mon_grouping - $locale_sym._start
        DCD     $locale_sym._positive_sign - $locale_sym._start
        DCD     $locale_sym._negative_sign - $locale_sym._start
$locale_sym._int_curr_symbol
        DCB     locale_monetary_int_curr_symbol, 0
$locale_sym._curr_symbol
        DCB     locale_monetary_curr_symbol, 0
$locale_sym._mon_point
        DCB     locale_monetary_point, 0
$locale_sym._mon_thous
        DCB     locale_monetary_thousands, 0
$locale_sym._mon_grouping
        DCB     locale_monetary_grouping, 0
$locale_sym._positive_sign
        DCB     locale_monetary_p_sign, 0
$locale_sym._negative_sign
        DCB     locale_monetary_n_sign, 0
        LC_ALL_trailer
        MEND

        END

