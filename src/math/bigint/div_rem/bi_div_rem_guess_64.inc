;BI_DEV_REM_GUESS_64_DEBUG = 1

if definite BI_DEV_REM_GUESS_64_DEBUG
  include 'bi_div_rem_guess_debug.inc'
end if

include '../macro/call.inc'



macro DivRemGuess64_DumpArgs dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    call    Console_WriteLine

    DivRemGuess64_DumpDividend dividend_bits, divisor_bits
    DivRemGuess64_DumpDivisor dividend_bits, divisor_bits
  end if
}

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
    cmp     rax, dividend_bits - (divisor_bits / 2)
    jb      .divisor_large

    if divisor_bits >= 512
      cmp     rax, dividend_bits - 128
      jb      .divisor_256
    end if

    if divisor_bits >= 256
      cmp     rax, dividend_bits - 64
      jb      .divisor_128
    end if

.divisor_64:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     rdx, [rdx + 0]
    mov     r8, [.quotient]
    mov     r9, [.remainder]
    Call_DivRem dividend_bits, 64
    jmp     .end
  if divisor_bits >= 256
.divisor_128:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.quotient]
    mov     r9, [.remainder]
    Call_DivRem dividend_bits, 128
    jmp     .end
  end if
  if divisor_bits >= 512
.divisor_256:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.quotient]
    mov     r9, [.remainder]
    Call_DivRem dividend_bits, 256
    jmp     .end
  end if
.divisor_large:
  end if
}

macro RemGuess64_DivisorSwitch dividend_bits, divisor_bits {
  if divisor_bits >= 128
    ;check for large divisor first than try to use smaller ones
    cmp     rax, dividend_bits - (divisor_bits / 2)
    jb      .divisor_large

    if divisor_bits >= 512
      cmp     rax, dividend_bits - 128
      jb      .divisor_256
    end if

    if divisor_bits >= 256
      cmp     rax, dividend_bits - 64
      jb      .divisor_128
    end if

.divisor_64:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     rdx, [rdx + 0]
    mov     r8, [.remainder]
    Call_Rem dividend_bits, 64
    jmp     .end
  if divisor_bits >= 256
.divisor_128:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.remainder]
    Call_Rem dividend_bits, 128
    jmp     .end
  end if
  if divisor_bits >= 512
.divisor_256:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.remainder]
    Call_Rem dividend_bits, 256
    jmp     .end
  end if
.divisor_large:
  end if
}

macro DivRemGuess64_Prepare dividend_bits, divisor_bits {
    DIV_REM_PARTIAL_DIVIDEND_SIZE = 128
    DIV_REM_PARTIAL_DIVISOR_SIZE = 64
    DIV_REM_MAX_REMAINDER_BOOST = (dividend_bits - DIV_REM_PARTIAL_DIVIDEND_SIZE)

    DIV_REM_PARTIAL_DIVIDEND_START = (dividend_bits - DIV_REM_PARTIAL_DIVIDEND_SIZE) / 8
    DIV_REM_PARTIAL_DIVISOR_START = (divisor_bits - DIV_REM_PARTIAL_DIVISOR_SIZE) / 8

    ; Because of preliminary checks at the begining
    ; divisor_bits/2 < divisor width <= divisor_bits
    DIV_REM_GUESS_MIN_DIVISOR_SIZE = (divisor_bits/2)
    
    ; divisor_lzcnt contains value as if divisor had same width as dividend
    DIV_REM_GUESS_IMAGINARY_BITS = dividend_bits - divisor_bits
    
    DIV_REM_GUESS_QUOTIENT_SIZE = dividend_bits
    DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE = (dividend_bits - DIV_REM_GUESS_MIN_DIVISOR_SIZE)
}

macro DivRemGuess64_PrepareLoop dividend_bits, divisor_bits {
    mov     rcx, [.quotient]
    Call_Zero dividend_bits

    mov     rcx, [.remainder]
    mov     rdx, [.dividend]
    Call_Copy dividend_bits
}

macro RemGuess64_PrepareLoop dividend_bits, divisor_bits {
    mov     rcx, [.remainder]
    mov     rdx, [.dividend]
    Call_Copy dividend_bits
}

macro DivRemGuess64_ShiftDivisor dividend_bits, divisor_bits {
;shift divisor to the left, so the most meaningful bit is always the highest bit
    mov     rcx, [.divisor]
    lea     rdx, [.divisor_shifted]
    mov     r8, [.divisor_lzcnt]
  if DIV_REM_GUESS_IMAGINARY_BITS > 0
    sub     r8, DIV_REM_GUESS_IMAGINARY_BITS 
  end if
    Call_Shl divisor_bits

    DivRemGuess64_DumpDivisorShifted dividend_bits, divisor_bits
}

macro DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits {
;shift remainder to the left, so the most meaningful bit is always the highest bit
      mov     rcx, [.remainder]
      Call_Lzcnt dividend_bits
      cmp     rax, [.divisor_lzcnt]
      jae     .recheck_once
      mov     [.remainder_lzcnt], rax

      mov     rcx, [.remainder]
      lea     rdx, [.remainder_shifted]
      mov     r8, [.remainder_lzcnt]
      Call_Shl dividend_bits
}

macro DivRemGuess64_Guess dividend_bits, divisor_bits {
;divide highest 128 bit of remainder by highest 64 bit of divisor
        mov     rdx, qword [.divisor_shifted + DIV_REM_PARTIAL_DIVISOR_START]
        inc     rdx ; make pessimistic prediction, so our quotient is never bigger than real value
        jnz     .divisor_not_max
.divisor_max:
        mov     rcx, qword [.remainder_shifted + (dividend_bits - 64) / 8]; divide by 2^64
        mov     qword [.guess_128], rcx
        mov     qword [.guess_128 + 8], 0
        jmp     .divisor_ok
.divisor_not_max:
;todo: compare reminder high 64  bits with divisor. if less then we can use 64-bit airthmentics instead of 128-bit
        lea     rcx, qword [.remainder_shifted  + DIV_REM_PARTIAL_DIVIDEND_START]
        lea     r8, [.guess_128]
        call    bi_div_128_64
.divisor_ok:
}

macro DivRemGuess64_FixGuess dividend_bits, divisor_bits {
      mov     rax, [.remainder_lzcnt]
      sub     rax, [.divisor_lzcnt]
      add     rax, 64                    ;partial remainder was 128-bit wide, but partial divisor only 64 bit-wide
      mov     [.correction], rax

      cmp     [.correction], 0
      jle     .correction_ok
;todo: guess_128 is less than 2^65 (not 2^64). Try to optimize everything
; scale down guess to trim fraction part of division
      lea     rcx, [.guess_128]
      mov     rdx, [.correction]
      call    bi_shr_assign_128
      mov     [.correction], 0
.correction_ok:
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
    Call_AddAssign DIV_REM_GUESS_DELTA_RAW_SIZE, divisor_bits
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
        Call_SubAssign divisor_bits
        jmp     .end
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
        Call_SubAssign divisor_bits
        jmp     .end
}





macro DivRemGuess64_Loop dividend_bits, divisor_bits {
.loop:
        DivRemGuess64_LoopStart dividend_bits, divisor_bits
        DivRemGuess64_DumpRemainder dividend_bits, divisor_bits
        DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits
        DivRemGuess64_DumpRemainderShifted dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits
        DivRemGuess64_DumpGuess dividend_bits, divisor_bits
        DivRemGuess64_FixGuess dividend_bits, divisor_bits
        DivRemGuess64_DumpGuessFixed dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits
        DivRemGuess64_DumpDelta dividend_bits, divisor_bits
        DivRemGuess64_ExtendGuess dividend_bits, divisor_bits

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
        DivRemGuess64_ShiftGuess dividend_bits, divisor_bits
.correction_2_ok:

        DivRemGuess64_DumpDeltaShifted dividend_bits, divisor_bits
        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits
        DivRemGuess64_UpdateQuotient dividend_bits, divisor_bits
        DivRemGuess64_DumpNewValues dividend_bits, divisor_bits

        jmp     .loop
.loop_ok:
}

macro RemGuess64_Loop dividend_bits, divisor_bits {
.loop:
        DivRemGuess64_LoopStart dividend_bits, divisor_bits
        DivRemGuess64_DumpRemainder dividend_bits, divisor_bits
        DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits
        DivRemGuess64_DumpRemainderShifted dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits
        DivRemGuess64_DumpGuess dividend_bits, divisor_bits
        DivRemGuess64_FixGuess dividend_bits, divisor_bits
        DivRemGuess64_DumpGuessFixed dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits
        DivRemGuess64_DumpDelta dividend_bits, divisor_bits

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
.correction_2_ok:

        DivRemGuess64_DumpDeltaShifted dividend_bits, divisor_bits
        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits
        DivRemGuess64_DumpNewValues dividend_bits, divisor_bits

        jmp     .loop
.loop_ok:
}