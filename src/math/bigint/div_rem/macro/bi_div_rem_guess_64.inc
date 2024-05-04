;BI_DEV_REM_GUESS_64_DEBUG = 1

if definite BI_DEV_REM_GUESS_64_DEBUG
  include 'bi_div_rem_guess_debug.inc'
end if

include 'bi_div_rem_guess_64_small_divisor.inc'

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

macro DivRemGuess64_InitRemainder dividend_bits, divisor_bits {
    mov     rcx, [.remainder]
    mov     rdx, [.dividend]
if dividend_bits = 256
  if AVX2_ENABLED = 1
    vmovdqu ymm1, [rdx]
    vmovdqu [rcx], ymm1
  else
    Call_Copy dividend_bits
  end if
else
    Call_Copy dividend_bits
end if
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
;shift divisor to the left, so the most meaningful bit is always the highest bit
    mov     rax, [.divisor_lzcnt]
  if DIV_REM_GUESS_IMAGINARY_BITS > 0
    sub     rax, DIV_REM_GUESS_IMAGINARY_BITS 
  end if
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

    DivRemGuess64_DumpDivisorShifted dividend_bits, divisor_bits
}

macro DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits {
;shift remainder to the left, so the most meaningful bit is always the (highest - 1) bit
      mov     rcx, [.remainder]
      Call_Lzcnt dividend_bits
      cmp     rax, [.divisor_lzcnt]
      jae     .recheck_once
      dec     rax
      mov     [.remainder_lzcnt], rax

if dividend_bits > 128
      mov     rcx, rax
      and     rax, -64
      shr     rax, 3                              ; rax now is count of highest zero qwords multiplied by 8
      mov     rdx, (dividend_bits shr 3) - 24     ; we need three qwords to build two
      xor     r9, r9
      sub     rdx, rax
; remainder has at least same bits as divisor, and divisor is at least 65-bit wide
; so at least two qwords are accessible
; but third one may be out of range
      mov     rax, [.remainder]
      cmovnc  r9, [rax + rdx]
      mov     r8, [rax + rdx + 8]
      mov     rax, [rax + rdx + 16]
      shld    rax, r8, cl
      shld    r8, r9, cl
      mov     qword [.remainder_shifted], r8
      mov     qword [.remainder_shifted + 8], rax
else
      mov     rcx, rax
      mov     rdx, [.remainder]
      mov     r8, [rdx]
      mov     r9, [rdx + 8]
      shld    r9, r8, cl
      shl     r8, cl
      mov     qword [.remainder_shifted], r8
      mov     qword [.remainder_shifted + 8], r9
end if
.remainder_shifted_ready:
}

macro DivRemGuess64_Guess dividend_bits, divisor_bits {
;divide highest 128 bit of remainder by highest 64 bit of divisor
        mov     r8, qword [.divisor_shifted]
        inc     r8 ; make pessimistic prediction, so our quotient is never bigger than real value
        jnz     .divisor_not_max
.divisor_max:
        mov     rdx, qword [.remainder_shifted + 8]; divide by 2^64
        mov     qword [.guess_64], rdx
        jmp     .divisor_ok
.divisor_not_max:
; partial quotient is 64-bit wide max
        mov     rax, qword [.remainder_shifted + 0]
        mov     rdx, qword [.remainder_shifted + 8]
        div     r8
        mov     qword [.guess_64], rax

.divisor_ok:
}

macro DivRemGuess64_FixGuess dividend_bits, divisor_bits {
      mov     rcx, [.remainder_lzcnt]
      add     rcx, 64                    ;partial remainder was 128-bit wide, but partial divisor only 64 bit-wide
      sub     rcx, [.divisor_lzcnt]
      ja      .scale_down                ; scale down guess to trim fractional part of division
.correction_ok:
      neg     rcx
      mov     [.correction], rcx

}

macro DivRemGuess64_CalcDelta dividend_bits, divisor_bits {
;precalculate delta = mul(.divisor, .guess_64), using narrowest possible mul
    DIV_REM_GUESS_DELTA_SIZE = dividend_bits

    ; mul(.divisor, .guess_64) returns result of 2 * divisor_bits width
    DIV_REM_GUESS_DELTA_MUL_FULL_SIZE = 2 * divisor_bits

    ; mul_low(.divisor, .guess_64) returns result of divisor_bits width
    DIV_REM_GUESS_DELTA_MUL_LOW_SIZE = divisor_bits

  if DIV_REM_GUESS_DELTA_MUL_LOW_SIZE >= DIV_REM_GUESS_DELTA_SIZE
    DIV_REM_GUESS_DELTA_RAW_SIZE = DIV_REM_GUESS_DELTA_MUL_LOW_SIZE
  else
    DIV_REM_GUESS_DELTA_RAW_SIZE = DIV_REM_GUESS_DELTA_MUL_FULL_SIZE
  end if
    
    mov     rcx, [.divisor]
    mov     rdx, qword [.guess_64]
    lea     r8, [.delta]
  if DIV_REM_GUESS_DELTA_MUL_LOW_SIZE >= DIV_REM_GUESS_DELTA_SIZE
    Call_MulLowX64 divisor_bits
  else
    Call_MulX64 divisor_bits
  end if

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
  if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE > 64
    lea     rcx, [.guess]
    Call_ExtendAssignX64 DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
  end if
}

macro DivRemGuess64_ShiftGuess dividend_bits, divisor_bits {
  if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE <= 64
    mov     rcx, [.correction]
    shl     qword [.guess_64], cl
  else
    if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE <= 128
      mov     rcx, [.correction]
      mov     rax, qword [.guess_128 + 0]
      shld    qword [.guess_128 + 8], rax, cl
      shl     qword [.guess_128 + 0], cl
    else
      lea     rcx, [.guess]
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
      mov     rdx, qword [.guess_64]
  else
      lea     rdx, [.guess]
  end if
      Call_AddAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE, DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
}

macro DivRemGuess64_RemainderFull dividend_bits, divisor_bits {
.remainder_full:
; remainder has first bit set. If we take all highest 128-bit of remainder we may get 65-bit partial quotient
        mov     qword [.remainder_lzcnt], -1
        mov     rcx, [.remainder]
        mov     r8, [rcx + dividend_bits/8 - 16]
        mov     r9, [rcx + dividend_bits/8 - 8]
        shr     r9, 1
        rcr     r8, 1
        mov     qword [.remainder_shifted + 0], r8
        mov     qword [.remainder_shifted + 8], r9
        jmp     .remainder_shifted_ready
}

macro DivRemGuess64_RecheckOnce dividend_bits, divisor_bits {
.recheck_once:
;remainder has same leading zeroes count as divisor so we can safely compare lowest divisor_bits bits
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_Cmp divisor_bits
        jb      .end
        mov     rcx, [.quotient]
        Call_IncAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_SubAssign DIV_REM_GUESS_REMAINDER_ACTUAL_SIZE, divisor_bits
        jmp     .end
DivRemGuess64_RemainderFull dividend_bits, divisor_bits
}

macro RemGuess64_RecheckOnce dividend_bits, divisor_bits {
.recheck_once:
;reminder has same leading zeroes count as divisor so we can safely compare lowest divisor_bits bits
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_Cmp divisor_bits
        jb      .end
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_SubAssign DIV_REM_GUESS_REMAINDER_ACTUAL_SIZE, divisor_bits
        jmp     .end
DivRemGuess64_RemainderFull dividend_bits, divisor_bits
}





macro DivRemGuess64_BeforeLoop dividend_bits, divisor_bits {
      mov     rcx, [.remainder]
      Call_Lzcnt dividend_bits    ;todo: check once per loop
      cmp     rax, [.divisor_lzcnt]
      jae     .recheck_once
      test    rax, rax
      jz      .remainder_full
      dec     rax
      mov     [.remainder_lzcnt], rax
}

macro DivRemGuess64_Loop dividend_bits, divisor_bits {
        DivRemGuess64_BeforeLoop dividend_bits, divisor_bits
.loop:
        DivRemGuess64_LoopStart dividend_bits, divisor_bits
        DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits
        DivRemGuess64_FixGuess dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits
        DivRemGuess64_ExtendGuess dividend_bits, divisor_bits

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
        DivRemGuess64_ShiftGuess dividend_bits, divisor_bits

        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits
        DivRemGuess64_UpdateQuotient dividend_bits, divisor_bits

        jmp     .loop
        DivRemGuess64_DivisorSmallSwitch dividend_bits, divisor_bits
.scale_down:
        shr     qword [.guess_64], cl
        DivRemGuess64_CalcDelta dividend_bits, divisor_bits
        DivRemGuess64_ExtendGuess dividend_bits, divisor_bits
        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits
        DivRemGuess64_UpdateQuotient dividend_bits, divisor_bits
        jmp     .loop  ; todo: recheck_once is not enough...
.loop_ok:
}

macro RemGuess64_Loop dividend_bits, divisor_bits {
        DivRemGuess64_BeforeLoop dividend_bits, divisor_bits
.loop:
        DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits
        DivRemGuess64_FixGuess dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits

        jmp     .loop
        RemGuess64_DivisorSmallSwitch dividend_bits, divisor_bits
.scale_down:
        shr     qword [.guess_64], cl
        DivRemGuess64_CalcDelta dividend_bits, divisor_bits
        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits
        jmp     .loop  ; todo: recheck_once is not enough...
.loop_ok:
}