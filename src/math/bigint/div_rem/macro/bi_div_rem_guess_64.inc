;BI_DEV_REM_GUESS_64_DEBUG = 1

if definite BI_DEV_REM_GUESS_64_DEBUG
  include 'bi_div_rem_guess_debug.inc'
end if

include 'bi_div_rem_guess_64_small_divisor.inc'
include 'bi_div_rem_guess_64_epilog.inc'
include 'bi_div_rem_guess_64_recheck_once.inc'
include 'bi_div_rem_guess_64_recheck_multi.inc'
include 'bi_div_rem_guess_64_init_remainder.inc'

include '../../config.inc'
include '../../macro/call.inc'

;todo: when approaching to divisorLZC switch to compare-and-subtract strategy
;todo: bi_exract_128_bits(remainderLZC) to get remainder first 128-bit meaningful bits

macro DivRemGuess64_Prolog dividend_bits, divisor_bits {
    sub     rsp, .locals_end - .locals_start
    mov     [.dividend], rcx
    mov     [.divisor], rdx
    mov     [.quotient], r8
    mov     [.remainder], r9

    PrologCheckStackAligned 'DivRemGuess64_Prolog'
    CheckRegAligned rcx, 'DivRemGuess64_Prolog rcx'
    CheckRegAligned rdx, 'DivRemGuess64_Prolog rdx'
    CheckRegAligned r8, 'DivRemGuess64_Prolog r8'
    CheckRegAligned r9, 'DivRemGuess64_Prolog r9'


    DivRemGuess64_DumpArgs dividend_bits, divisor_bits
}

macro RemGuess64_Prolog dividend_bits, divisor_bits {
    sub     rsp, .locals_end - .locals_start
    mov     [.dividend], rcx
    mov     [.divisor], rdx
    mov     [.remainder], r8

    PrologCheckStackAligned 'RemGuess64_Prolog'
    CheckRegAligned rcx, 'RemGuess64_Prolog rcx'
    CheckRegAligned rdx, 'RemGuess64_Prolog rdx'
    CheckRegAligned r8, 'RemGuess64_Prolog r8'

    DivRemGuess64_DumpArgs dividend_bits, divisor_bits
}


macro DivRemGuess64_DivisorLzcnt dividend_bits, divisor_bits {
    mov     rcx, [.divisor]
    Call_Lzcnt divisor_bits
  if DIV_REM_GUESS_IMAGINARY_BITS > 0
      add     rax, DIV_REM_GUESS_IMAGINARY_BITS 
  end if
    mov     [.divisor_lzcnt], rax
}

macro DivRemGuess64_DivisorSwitch dividend_bits, divisor_bits {
  if divisor_bits >= 128
    ;check for large divisor first than try to use smaller ones
    cmp     rax, dividend_bits - (divisor_bits / 2)            ;todo: dividend_bits must be divisor_bits?
    jae      .divisor_small
  end if
}

macro RemGuess64_DivisorSwitch dividend_bits, divisor_bits {
  if divisor_bits >= 128
    ;check for large divisor first than try to use smaller ones
    cmp     rax, dividend_bits - (divisor_bits / 2)            ;todo: dividend_bits must be divisor_bits?
    jae      .divisor_small
  end if
}








macro DivRemGuess64_Prepare dividend_bits, divisor_bits {
    DIV_REM_PARTIAL_DIVIDEND_SIZE = 128
    DIV_REM_PARTIAL_DIVISOR_SIZE = 64
    DIV_REM_MAX_REMAINDER_BOOST = (dividend_bits - DIV_REM_PARTIAL_DIVIDEND_SIZE)

    DIV_REM_PARTIAL_DIVISOR_START = (divisor_bits - DIV_REM_PARTIAL_DIVISOR_SIZE) / 8

    ; Because of preliminary checks at the begining
    ; divisor_bits/2 < divisor width <= divisor_bits
    DIV_REM_GUESS_MIN_DIVISOR_SIZE = (divisor_bits/2)
    
    ; divisor_lzcnt contains value as if divisor had same width as dividend
    DIV_REM_GUESS_IMAGINARY_BITS = dividend_bits - divisor_bits
    
    DIV_REM_GUESS_QUOTIENT_SIZE = dividend_bits
    DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE = (dividend_bits - DIV_REM_GUESS_MIN_DIVISOR_SIZE)
    DIV_REM_GUESS_REMAINDER_SIZE = dividend_bits
    DIV_REM_GUESS_REMAINDER_ACTUAL_SIZE = divisor_bits
}


macro DivRemGuess64_InitQuotient dividend_bits, divisor_bits {
    mov     rcx, [.quotient]
if dividend_bits = 256
  if AVX2_ENABLED = 1
    vpxor   ymm1, ymm1, ymm1
    vmovdqu [rcx], ymm1
  else
    Call_Zero dividend_bits
  end if
else if dividend_bits = 128
 if AVX2_ENABLED = 1
    vpxor   xmm1, xmm1, xmm1
    vmovdqu [rcx], xmm1
  else
    Call_Zero dividend_bits
  end if
else
    Call_Zero dividend_bits
end if
}

macro DivRemGuess64_PrepareLoop dividend_bits, divisor_bits {
    DivRemGuess64_InitQuotient dividend_bits, divisor_bits
    DivRemGuess64_InitRemainder dividend_bits, divisor_bits
}

macro RemGuess64_PrepareLoop dividend_bits, divisor_bits {
    DivRemGuess64_InitRemainder dividend_bits, divisor_bits
}

macro DivRemGuess64_ShiftDivisor dividend_bits, divisor_bits {
if divisor_bits = 128
      mov     r8, [.divisor]
      mov     rdx, [r8 + 8]
      mov     rax, [r8 + 0]
      lzcnt   rcx, rdx
      shld    rdx, rax, cl
      mov     qword [.divisor_shifted], rdx
else
;shift divisor to the left, so the most meaningful bit is always the highest bit
    mov     rax, [.divisor_lzcnt]
  if DIV_REM_GUESS_IMAGINARY_BITS > 0
    sub     rax, DIV_REM_GUESS_IMAGINARY_BITS    ;todo: remove
  end if
  ;todo: if divisor is 128 bit can be simplified
; divisor_bits is at least 128-bit wide
      mov     rcx, rax
      and     rax, -64
      shr     rax, 3                              ; rax now is count of highest zero qwords multiplied by 8
      mov     rdx, (divisor_bits shr 3) - 16      ; we need two qwords to build one
      sub     rdx, rax

      mov     rax, [.divisor]
      mov     r8, [rax + rdx]
      mov     r9, [rax + rdx + 8]
      shld    r9, r8, cl
      mov     qword [.divisor_shifted], r9

end if
}

macro DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits {
;shift remainder to the left, so the most meaningful bit is always the highest bit
      mov     rcx, [.remainder]
      Call_Lzcnt dividend_bits
      cmp     rax, [.divisor_lzcnt]
      jae     .recheck_once

if dividend_bits > 128
      mov     [.remainder_lzcnt], rax
      mov     rcx, rax
      and     rax, -64
      sar     rax, 3                              ; rax now is count of highest zero qwords multiplied by 8
      mov     rdx, (dividend_bits shr 3) - 24     ; we need three qwords to build two
      xor     r9, r9
      sub     rdx, rax
; remainder has at least same bits as divisor, and divisor is at least 65-bit wide
; so at least two qwords are accessible
; but third one may be out of range
      mov     rax, [.remainder]
      cmovns  r9, [rax + rdx]
      mov     r8, [rax + rdx + 8]
      mov     rax, [rax + rdx + 16]
      shld    rax, r8, cl
      shld    r8, r9, cl
      mov     qword [.remainder_shifted], r8
      mov     qword [.remainder_shifted + 8], rax
else
      mov     rdx, [.remainder]
      vmovdqu xmm1, [rdx]
      vmovdqu dqword [.remainder_shifted], xmm1
end if
}

macro DivRemGuess64_Guess dividend_bits, divisor_bits {
;divide highest 128 bit of remainder by highest 64 bit of divisor
        mov     r8, qword [.divisor_shifted]
        inc     r8 ; make pessimistic prediction, so our quotient is never bigger than real value
        jnz     .divisor_not_max
.divisor_max:
        mov     rdx, qword [.remainder_shifted + 8]; divide by 2^64
        mov     qword [.guess_128], rdx
        mov     qword [.guess_128 + 8], 0
        jmp     .divisor_ok
.divisor_not_max:
; partial quotient is 65-bit wide max
        mov     rax, qword [.remainder_shifted + 0]
        mov     rdx, qword [.remainder_shifted + 8]
        mov     r9, rdx
        sub     r9, r8
        cmovnc  rdx, r9
        setnc   r9b
        movzx   r9, r9b
        mov     qword [.guess_128 + 8], r9
        div     r8
        mov     qword [.guess_128 + 0], rax

.divisor_ok:
}

macro DivRemGuess64_FixGuess dividend_bits, divisor_bits {
if dividend_bits > 128
      mov     rcx, [.remainder_lzcnt]
      add     rcx, 64                    ;partial remainder was 128-bit wide, but partial divisor only 64 bit-wide
      sub     rcx, [.divisor_lzcnt]
      jbe     .correction_ok
;todo: guess_128 is less than 2^65 (not 2^64). Try to optimize everything
; scale down guess to trim fraction part of division
      mov     rax, qword [.guess_128 + 8]
      shrd    qword [.guess_128 + 0], rax, cl
      shr     qword [.guess_128 + 8], cl
      xor     rcx, rcx
.correction_ok:
      mov     [.correction], rcx
else
      mov     rcx, 64                    ;partial remainder was 128-bit wide, but partial divisor only 64 bit-wide
      sub     rcx, [.divisor_lzcnt]
;todo: guess_128 is less than 2^65 (not 2^64). Try to optimize everything
; scale down guess to trim fraction part of division
      mov     rax, qword [.guess_128 + 8]
      shrd    qword [.guess_128 + 0], rax, cl
      shr     qword [.guess_128 + 8], cl
      mov     [.correction], 0
end if
}

macro DivRemGuess64_CalcDelta dividend_bits, divisor_bits {
;precalculate delta = mul(.divisor, .guess_128), using narrowest possible mul
    DIV_REM_GUESS_DELTA_SIZE = dividend_bits

    ; mul(.divisor, .guess_128) returns result of 2 * divisor_bits width
    DIV_REM_GUESS_DELTA_MUL_FULL_SIZE = 2 * divisor_bits

    ; mul_low(.divisor, .guess_128) returns result of divisor_bits width
    DIV_REM_GUESS_DELTA_MUL_LOW_SIZE = divisor_bits

  if DIV_REM_GUESS_DELTA_MUL_LOW_SIZE >= DIV_REM_GUESS_DELTA_SIZE
    DIV_REM_GUESS_DELTA_RAW_SIZE = DIV_REM_GUESS_DELTA_MUL_LOW_SIZE
  else
    DIV_REM_GUESS_DELTA_RAW_SIZE = DIV_REM_GUESS_DELTA_MUL_FULL_SIZE
  end if
    
    ;.guess_128 is actually 65-bit wide, meaning high(.guess_128) is either 1 or 0
    ; let's use 64-bit multiplification, and then fix cases when high(.guess_128) is 1
    mov     rcx, [.divisor]
    mov     rdx, qword [.guess_128]
    lea     r8, [.delta]
  if DIV_REM_GUESS_DELTA_MUL_LOW_SIZE >= DIV_REM_GUESS_DELTA_SIZE
    Call_MulLowX64 divisor_bits
  else
    Call_MulX64 divisor_bits
  end if

    cmp       qword [.guess_128 + 8], 0
    jz        .calc_delta_ok
.calc_delta_128:
    lea     rcx, [.delta + 8]
    mov     rdx, [.divisor]
    Call_AddAssign DIV_REM_GUESS_DELTA_RAW_SIZE, divisor_bits    ; todo: DIV_REM_GUESS_DELTA_RAW_SIZE - 64
.calc_delta_ok:

  if DIV_REM_GUESS_DELTA_RAW_SIZE < DIV_REM_GUESS_DELTA_SIZE
    lea     rcx, [.delta]
    Call_ExtendAssign DIV_REM_GUESS_DELTA_SIZE, DIV_REM_GUESS_DELTA_RAW_SIZE
  end if
}

macro DivRemGuess64_ShiftDelta dividend_bits, divisor_bits {
    lea     rcx, [.delta]
    mov     rdx, [.correction]
    Call_ShlAssign DIV_REM_GUESS_DELTA_SIZE
}

macro DivRemGuess64_ExtendGuess dividend_bits, divisor_bits {
  if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE > 128
    ;todo: .guess_q and guess_128 can be combined if guess_q is cleared at start. Check everywhere
    lea     rcx, [.guess_q]
    lea     rdx, [.guess_128]
    Call_ExtendX128 DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
  end if
}

macro DivRemGuess64_ShiftGuess dividend_bits, divisor_bits {
  if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE <= 64
    mov     rcx, [.correction]
    shl     qword [.guess_128], cl
  else
    if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE <= 128
      lea     rcx, [.guess_128]
      mov     rdx, [.correction]
      Call_ShlAssign 128
    else
      lea     rcx, [.guess_q]
      mov     rdx, [.correction]
      Call_ShlAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
    end if
  end if
}

macro DivRemGuess64_ApplyDelta dividend_bits, divisor_bits {
      mov     rcx, [.remainder]
      lea     rdx, [.delta]
      Call_SubAssign dividend_bits, dividend_bits
}

macro DivRemGuess64_UpdateQuotient dividend_bits, divisor_bits {
      mov     rcx, [.quotient]
  if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE = 64
      mov     rdx, qword [.guess_128 + 0]
  else if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE <= 128
      lea     rdx, [.guess_128]
  else
      lea     rdx, [.guess_q]
  end if
      Call_AddAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE, DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
}


macro DivRemGuess64_Loop dividend_bits, divisor_bits {
.loop:
        DivRemGuess64_LoopStart dividend_bits, divisor_bits
        DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits
        DivRemGuess64_FixGuess dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits
        DivRemGuess64_ExtendGuess dividend_bits, divisor_bits

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
        DivRemGuess64_ShiftGuess dividend_bits, divisor_bits
.correction_2_ok:

        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits
        DivRemGuess64_UpdateQuotient dividend_bits, divisor_bits

        jmp     .loop
        DivRemGuess64_DivisorSmallSwitch dividend_bits, divisor_bits
.loop_ok:
}

macro RemGuess64_Loop dividend_bits, divisor_bits {
.loop:
        DivRemGuess64_LoopStart dividend_bits, divisor_bits
        DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits
        DivRemGuess64_FixGuess dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
.correction_2_ok:

        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits

        jmp     .loop
        RemGuess64_DivisorSmallSwitch dividend_bits, divisor_bits
.loop_ok:
}