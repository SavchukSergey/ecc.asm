if ~ definite __bi_div_rem_guess_64

__bi_div_rem_guess_64 equ 0

;BI_DEV_REM_GUESS_64_DEBUG = 1
if definite BI_DEV_REM_GUESS_64_DEBUG
  include 'bi_div_rem_guess_debug.inc'
end if

include 'bi_div_rem_guess_64_epilog.inc'
include 'bi_div_rem_guess_64_recheck_once.inc'
include 'bi_div_rem_guess_64_recheck_multi.inc'
include 'bi_div_rem_guess_64_init_remainder.inc'
include 'bi_div_rem_guess_64_shift_remainder.inc'
include 'bi_div_rem_guess_64_fast_switch.inc'
include 'bi_div_rem_guess_64_prepare.inc'
include 'bi_div_rem_guess_64_prolog.inc'
include 'bi_div_rem_guess_64_shift_divisor.inc'

;todo: when approaching to divisorLZC switch to compare-and-subtract strategy
;todo: bi_exract_128_bits(remainderLZC) to get remainder first 128-bit meaningful bits
;todo: special case when dividend_bits = divisor_bits

macro DivRemGuess64 dividend_bits, divisor_bits {
  ;check if we can downgrade to narrower width
  DivRemGuess64_FastSwitch dividend_bits, divisor_bits

  ; prepare constants
  DivRemGuess64_Prepare dividend_bits, divisor_bits
virtual at rsp
  label .locals_start
  BigInteger .delta, dividend_bits
  .remainder_shifted BigInteger128

  .guess_128:
  BigInteger .guess_q, DIV_REM_GUESS_QUOTIENT_GUESS_SIZE

  .divisor_shifted rq 1
  
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

if dividend_bits = divisor_bits
else
  BigInteger .remainder_temp, dividend_bits
end if

  .divisor_lzcnt rq 1
  
  .correction rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
	DivRemGuess64_Prolog dividend_bits, divisor_bits
	DivRemGuess64_DivisorLzcnt dividend_bits, divisor_bits
	DivRemGuess64_PrepareLoop dividend_bits, divisor_bits
	DivRemGuess64_ShiftDivisor dividend_bits, divisor_bits

	DivRemGuess64_Loop dividend_bits, divisor_bits

.end:
	DivRemGuess64_Epilog dividend_bits, divisor_bits
	DivRemGuess64_RecheckOnce dividend_bits, divisor_bits
	DivRemGuess64_RecheckMulti dividend_bits, divisor_bits
}

macro RemGuess64 dividend_bits, divisor_bits {
  ;check if we can downgrade to narrower width
  RemGuess64_FastSwitch dividend_bits, divisor_bits

  ; prepare constants
  RemGuess64_Prepare dividend_bits, divisor_bits
virtual at rsp
  label .locals_start
  BigInteger .delta, dividend_bits
  .remainder_shifted BigInteger128

  .guess_128:
  BigInteger .guess_q, DIV_REM_GUESS_QUOTIENT_GUESS_SIZE

  .divisor_shifted rq 1
  
  .dividend rq 1
  .divisor rq 1
  .remainder rq 1

if dividend_bits = divisor_bits
else
  BigInteger .remainder_temp, dividend_bits
end if

  .divisor_lzcnt rq 1
  
  .correction rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
	RemGuess64_Prolog dividend_bits, divisor_bits
	DivRemGuess64_DivisorLzcnt dividend_bits, divisor_bits
	RemGuess64_PrepareLoop dividend_bits, divisor_bits
	DivRemGuess64_ShiftDivisor dividend_bits, divisor_bits

	RemGuess64_Loop dividend_bits, divisor_bits

.end:
	DivRemGuess64_Epilog dividend_bits, divisor_bits
	RemGuess64_RecheckOnce dividend_bits, divisor_bits
	RemGuess64_RecheckMulti dividend_bits, divisor_bits
}


macro DivRemGuess64_DivisorLzcnt dividend_bits, divisor_bits {
    mov     rcx, [.divisor]
    Call_Lzcnt divisor_bits
  if DIV_REM_GUESS_IMAGINARY_BITS > 0
      add     rax, DIV_REM_GUESS_IMAGINARY_BITS 
  end if
    mov     [.divisor_lzcnt], rax
}

macro DivRemGuess64_InitQuotient dividend_bits, divisor_bits {
  mov     rcx, [.quotient]
  Fast_Zero dividend_bits
}

macro DivRemGuess64_PrepareLoop dividend_bits, divisor_bits {
    DivRemGuess64_InitQuotient dividend_bits, divisor_bits
    DivRemGuess64_InitRemainder dividend_bits, divisor_bits
}

macro RemGuess64_PrepareLoop dividend_bits, divisor_bits {
    DivRemGuess64_InitRemainder dividend_bits, divisor_bits
}



macro DivRemGuess64_Guess dividend_bits, divisor_bits {
;divide highest 128 bit of remainder by highest 64 bit of divisor
        mov     r8, qword [.divisor_shifted]
        inc     r8 ; make pessimistic prediction, so our quotient is never bigger than real value
        jnz     .divisor_not_max
.divisor_max:
        mov     rdx, qword [.remainder_shifted + 8]; divide by 2^64
        mov     qword [.guess_128], rdx
if DIV_REM_GUESS_QUOTIENT_GUESS_SIZE > 64
        mov     qword [.guess_128 + 8], 0
end if
        jmp     .divisor_ok
.divisor_not_max:
; partial quotient is 65-bit wide max
        mov     rax, qword [.remainder_shifted + 0]
        mov     rdx, qword [.remainder_shifted + 8]
if DIV_REM_GUESS_QUOTIENT_GUESS_SIZE > 64
        mov     r9, rdx
        sub     r9, r8
        cmovnc  rdx, r9
        setnc   r9b
        movzx   r9, r9b
        mov     qword [.guess_128 + 8], r9
end if
        div     r8
        mov     qword [.guess_128 + 0], rax

.divisor_ok:
}

macro DivRemGuess64_CalcDelta dividend_bits, divisor_bits {
;precalculate delta = mul(.divisor, .guess_128), using narrowest possible mul
    DIV_REM_GUESS_DELTA_SIZE = dividend_bits

    DIV_REM_GUESS_DELTA_MUL_64_SIZE = (divisor_bits + 64)
    DIV_REM_GUESS_DELTA_MUL_128_SIZE = (divisor_bits + 128)

    ;.guess_128 is actually 65-bit wide, meaning high(.guess_128) is either 1 or 0
    ; let's use 64-bit multiplification, and then fix cases when high(.guess_128) is 1
    mov     rcx, [.divisor]
    mov     rdx, qword [.guess_128]
    lea     r8, [.delta]
  if DIV_REM_GUESS_DELTA_MUL_64_SIZE > DIV_REM_GUESS_DELTA_SIZE
    Call_MulLow divisor_bits, 64, DIV_REM_GUESS_DELTA_SIZE
  else
    Call_Mul divisor_bits, 64
  end if

  if DIV_REM_GUESS_DELTA_SIZE > DIV_REM_GUESS_DELTA_MUL_64_SIZE
    lea     rcx, [.delta]
    Call_ExtendAssign DIV_REM_GUESS_DELTA_SIZE, DIV_REM_GUESS_DELTA_MUL_64_SIZE
  end if


if DIV_REM_GUESS_QUOTIENT_GUESS_SIZE > 64
    cmp       qword [.guess_128 + 8], 0
    jz        .calc_delta_ok
.calc_delta_128:
    lea     rcx, [.delta + 8]
    mov     rdx, [.divisor]
    if DIV_REM_GUESS_DELTA_SIZE > divisor_bits
      Call_AddAssign (DIV_REM_GUESS_DELTA_SIZE - 64), divisor_bits
    else
      Call_AddAssign (DIV_REM_GUESS_DELTA_SIZE - 64), divisor_bits - 64
    end if
.calc_delta_ok:
end if
}

macro DivRemGuess64_ShiftDelta dividend_bits, divisor_bits {
    lea     rcx, [.delta]
    mov     rdx, [.correction]
    Call_ShlAssign DIV_REM_GUESS_DELTA_SIZE
}

macro DivRemGuess64_ExtendGuess dividend_bits, divisor_bits {
  ;do not care about large guess'es that will not fit into quotient
  DIV_REM_GUESS_QUOTIENT_HIGH_SIZE = DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE - 128
  if DIV_REM_GUESS_QUOTIENT_HIGH_SIZE = 64
    mov     qword [.guess_q + 128 / 8], 0
  else if DIV_REM_GUESS_QUOTIENT_HIGH_SIZE > 0
    lea     rcx, [.guess_q + 128 / 8]
    Fast_Zero DIV_REM_GUESS_QUOTIENT_HIGH_SIZE
  end if
}

macro DivRemGuess64_ShiftGuess dividend_bits, divisor_bits {
  if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE <= 64
    mov     rcx, [.correction]
    shl     qword [.guess_128], cl
  else
    lea     rcx, [.guess_q]
    mov     rdx, [.correction]
    Call_ShlAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
  end if
}

macro DivRemGuess64_ApplyDelta dividend_bits, divisor_bits {
if dividend_bits = divisor_bits
      mov     rcx, [.remainder]
else
      lea     rcx, [.remainder_temp]
end if
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
        DivRemGuess64_DumpDivisorShifted dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits

        DivRemGuess64_DumpGuess dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits
        DivRemGuess64_DumpDelta dividend_bits, divisor_bits
        DivRemGuess64_ExtendGuess dividend_bits, divisor_bits ;todo: remove?

        cmp     [.correction], 0
        jz     .correction_2_ok

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
        DivRemGuess64_ShiftGuess dividend_bits, divisor_bits
.correction_2_ok:

        DivRemGuess64_DumpGuessFixed dividend_bits, divisor_bits
        DivRemGuess64_DumpDeltaShifted dividend_bits, divisor_bits

        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits
        DivRemGuess64_UpdateQuotient dividend_bits, divisor_bits

        jmp     .loop
.loop_ok:
}

macro RemGuess64_Loop dividend_bits, divisor_bits {
.loop:
        DivRemGuess64_LoopStart dividend_bits, divisor_bits
        DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits
        DivRemGuess64_Guess dividend_bits, divisor_bits

        DivRemGuess64_CalcDelta dividend_bits, divisor_bits

        cmp     [.correction], 0
        jz     .correction_2_ok

        DivRemGuess64_ShiftDelta dividend_bits, divisor_bits
.correction_2_ok:

        DivRemGuess64_ApplyDelta dividend_bits, divisor_bits

        jmp     .loop
.loop_ok:
}

end if