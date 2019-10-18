; rt_memory.s: template for writing a memory model implementation
;
; Copyright 1999,2007 ARM Limited. All rights reserved.
;
; RCS $Revision$
; Checkin $Date$
; Revising $Author$

; This module gives a framework for writing custom memory models
; in. It actually implements a very simple memory model, in which:
;
;  - the stack grows down from 0x80000000
;  - the heap is 128Kb and grows up from 0x60000000
;  - no extra memory is available for the heap

        IMPORT  __rt_stackheap_storage

        AREA    |.text|, CODE, READONLY

; --------------------------------------------------

        ; Initialisation function. This routine isn't required to
        ; preserve any registers, although obviously it shouldn't
        ; lose LR because it won't know where to return to. On
        ; exit, SP should point to the top of the desired stack,
        ; and [a1,a2) should be the initial block to use for the
        ; heap.
        ;
        ; Returning a1==a2 is allowed.

        EXPORT  __rt_stackheap_init
__rt_stackheap_init

        ; Set up some example values.
        MOV     sp, #0x80000000
        MOV     a1, #0x60000000
        ADD     a2, a1, #0x20000

        MOV     pc, lr

; --------------------------------------------------

        ; The heap extend function. This is called using the
        ; ordinary ATPCS calling convention.
        ;
        ; On input: a1 is the minimum size of memory required
        ;              (guaranteed to be a multiple of 4)
        ;           a2 is a pointer to a word of memory, W, in which
        ;              to store the address of the block
        ;
        ; On exit:  a1 is size of returned block
        ;           W  contains base address of returned block
        ;      Or:  a1 is zero
        ;           W  has undefined contents

        EXPORT  __rt_heap_extend
__rt_heap_extend

        ; Refuse all requests for extra heap space.
        MOV     a1, #0

        LDMFD   sp!, {pc}

        END

