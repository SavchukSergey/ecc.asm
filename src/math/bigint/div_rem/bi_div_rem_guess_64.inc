;BI_DEV_REM_GUESS_64_DEBUG = 1

if definite BI_DEV_REM_GUESS_64_DEBUG
  include 'bi_dev_rem_debug.inc'
end if

macro DisplayDec value {
  if value > 100
    display '0' + (value / 100)
    display '0' + (value mod 100) / 10
    display '0' + (value mod 10)
  end if
}

macro DivRemGuess64_Shl bits {
  if bits = 128
      call    bi_shl_128
  end if
  if bits = 256
      call    bi_shl_256
  end if
  if bits = 512
      call    bi_shl_512
  end if
}

macro DivRemGuess64_ShlAssign bits {
  if bits = 128
      call    bi_shl_assign_128
  end if
  if bits = 256
      call    bi_shl_assign_256
  end if
  if bits = 512
      call    bi_shl_assign_512
  end if
}

macro DivRemGuess64_IncAssign bits {
  if bits = 128
      call    bi_inc_assign_128
  end if
  if bits = 256
      call    bi_inc_assign_256
  end if
  if bits = 512
      call    bi_inc_assign_512
  end if
}

macro DivRemGuess64_Lzcnt bits {
  if bits = 128
      call    bi_lzcnt_128
  end if
  if bits = 256
      call    bi_lzcnt_256
  end if
  if bits = 512
      call    bi_lzcnt_512
  end if
}

macro DivRemGuess64_Cmp bits {
  if bits = 128
      call    bi_cmp_128_128
  end if
  if bits = 256
      call    bi_cmp_256_256
  end if
  if bits = 512
      call    bi_cmp_512_512
  end if
}

macro DivRemGuess64_SubAssign bits {
  if bits = 128
      call    bi_sub_assign_128_128
  end if
  if bits = 256
      call    bi_sub_assign_256_256
  end if
  if bits = 512
      call    bi_sub_assign_512_512
  end if
}

macro DivRemGuess64_AddAssign bits {
  if bits = 64
      add     [rcx], rdx
  else if bits = 128
      call    bi_add_assign_128_128
  else if bits = 192 ; 256 - 64
      call    bi_add_assign_256_256 ; todo: 
  else if bits = 256
      call    bi_add_assign_256_256
  else if bits = 384 ; 512 - 128
      call    bi_add_assign_512_512 ;todo:
  else if bits = 448 ; 512 - 64
      call    bi_add_assign_512_512 ;todo:
  else if bits = 512
      call    bi_add_assign_512_512
  else
      display 'unknown add assign '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro DivRemGuess64_MulX128 bits {
  if bits = 128
      call    bi_mul_128_128
  else if bits = 256
      call    bi_mul_256_128
  else if bits = 512
      call    bi_mul_512_128
  else
      display 'unknown mul '
      DisplayDec bits
      display 13, 10
      err
  end if
}

macro DivRemGuess64_MulLowX128 bits {
  if bits = 128
      call    bi_mul_low_128_128
  else if bits = 256
      call    bi_mul_low_256_128
  else if bits = 512
      call    bi_mul_low_512_128
  else
      display 'unknown mul_low '
      DisplayDec bits
      display 13, 10
      err
  end if
}

macro DivRemGuess64_WriteUIntHex bits {
  if bits = 128
      call    Console_WriteUInt128Hex
  end if
  if bits = 256
      call    Console_WriteUInt256Hex
  end if
  if bits = 512
      call    Console_WriteUInt1024Hex
  end if
}

macro DivRemGuess64_DumpDividend dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
      push    rsi
      lea     rsi, [bi_div_rem_dump_dividend_msg]
      call    Console_WriteString
      pop     rsi

      mov     rcx, [.dividend]
      DivRemGuess64_WriteUIntHex dividend_bits
  end if
}

macro DivRemGuess64_DumpDivisorShifted dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
      push    rsi
      lea     rsi, [bi_div_rem_dump_divisor_shifted_msg]
      call    Console_WriteString
      pop     rsi

      lea     rcx, [.divisor_shifted]
      DivRemGuess64_WriteUIntHex divisor_bits
      call    Console_WriteLine
  end if
}

macro DivRemGuess64_DumpRemainder dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
      push    rsi
      lea     rsi, [bi_div_rem_dump_remainder_msg]
      call    Console_WriteString
      pop     rsi

      mov     rcx, [.remainder]
      DivRemGuess64_WriteUIntHex dividend_bits
  end if
}

macro DivRemGuess64_DumpGuess dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG

      push    rsi
      lea     rsi, [bi_div_rem_dump_guess_msg]
      call    Console_WriteString
      pop     rsi

      mov     rcx, [.guess_128]
      call    Console_WriteUInt128Hex
      call    Console_WriteLine

  end if
}

macro DivRemGuess64_DumpRemainderShifted dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
      push    rsi
      lea     rsi, [bi_div_rem_dump_remainder_shifted_msg]
      call    Console_WriteString
      pop     rsi

      lea     rcx, [.remainder_shifted]
      DivRemGuess64_WriteUIntHex dividend_bits
  end if
}

macro DivRemGuess64_DumpDeltaShifted dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
      push    rsi
      lea     rsi, [bi_div_rem_dump_delta_shifted_msg]
      call    Console_WriteString
      pop     rsi

      lea     rcx, [.delta]
      DivRemGuess64_WriteUIntHex dividend_bits
  end if
}

macro DivRemGuess64_DumpNewValues dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG

      push    rsi
      lea     rsi, [bi_div_rem_dump_new_quotient_msg]
      call    Console_WriteString
      pop     rsi

      mov     rcx, [.quotient]
      DivRemGuess64_WriteUIntHex dividend_bits
      call    Console_WriteLine

      push    rsi
      lea     rsi, [bi_div_rem_dump_new_remainder_msg]
      call    Console_WriteString
      pop     rsi

      mov     rcx, [.remainder]
      DivRemGuess64_WriteUIntHex dividend_bits
      call    Console_WriteLine

  end if
}

macro DivRemGuess64_Prolog dividend_bits, divisor_bits {
      sub     rsp, .locals_end - .locals_start
      mov     [.dividend], rcx
      mov     [.divisor], rdx
      mov     [.quotient], r8
      mov     [.remainder], r9

if definite BI_DEV_REM_GUESS_64_DEBUG
      call    Console_WriteLine

      DivRemGuess64_DumpDividend dividend_bits, divisor_bits
      
      push    rsi
      lea     rsi, [bi_div_rem_dump_divisor_msg]
      call    Console_WriteString
      pop     rsi

      mov     rcx, [.divisor]
      DivRemGuess64_WriteUIntHex divisor_bits
      
      call    Console_WriteLine
end if

}

macro DivRemGuess64_Prepare dividend_bits, divisor_bits {
    ; Because of preliminary checks at the begining
    ; divisor_bits/2 < divisor width <= divisor_bits
    DIV_REM_GUESS_MIN_DIVISOR_SIZE = (divisor_bits/2)

    DIV_REM_GUESS_QUOTIENT_SIZE = dividend_bits
    DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE = (dividend_bits - DIV_REM_GUESS_MIN_DIVISOR_SIZE)
}

macro DivRemGuess64_ShiftDivisor dividend_bits, divisor_bits {
;shift divisor to the left, so the most meaningful bit is always the highest bit
      mov     rcx, [.divisor]
      lea     rdx, [.divisor_shifted]
      mov     r8, [.divisor_lzcnt]
  if dividend_bits <> divisor_bits
      sub     r8, dividend_bits - divisor_bits ; divisor_lzcnt contains value if divisor_bits were the same as dividend_bits 
  end if
      DivRemGuess64_Shl divisor_bits

      DivRemGuess64_DumpDivisorShifted dividend_bits, divisor_bits
}

macro DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits {
;shift remainder to the left, so the most meaningful bit is always the highest bit
      mov     rcx, [.remainder]
      DivRemGuess64_Lzcnt dividend_bits
      mov     [.remainder_lzcnt], rax

      cmp     rax, [.divisor_lzcnt]
      jae     .recheck_once

      mov     rcx, [.remainder]
      lea     rdx, [.remainder_shifted]
      mov     r8, [.remainder_lzcnt]
      DivRemGuess64_Shl dividend_bits
}

macro DivRemGuess64_Guess dividend_bits, divisor_bits {
;divide highest 128 bit of remainder by highest 64 bit of divisor
        mov     rdx, qword [.divisor_shifted + (divisor_bits - 64) / 8]
        inc     rdx ; make pessimistic prediction, so our quotient is never bigger than real value
        jnz     .divisor_not_max
.divisor_max:
        mov     rcx, qword [.remainder_shifted + (dividend_bits - 64) / 8]; divide by 2^64
        mov     qword [.guess_128], rcx
        mov     qword [.guess_128 + 8], 0
        jmp     .divisor_ok
.divisor_not_max:
        lea     rcx, qword [.remainder_shifted  + (dividend_bits - 128) / 8]
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
;todo: guess_128 is less than 2^65 (not 2^64). Try to optimze everything
      lea     rcx, [.guess_128]
      mov     rdx, [.correction]
      call    bi_shr_assign_128
      mov     [.correction], 0
.correction_ok:
}

macro DivRemGuess64_CalcDelta dividend_bits, divisor_bits {
;precalculate delta, using narrowest pissible mul
    mov     rcx, [.divisor]
    lea     rdx, [.guess_128]
    lea     r8, [.delta]

    DIV_REM_GUESS_DELTA_EXPECTED_SIZE = dividend_bits

    ; mul returns result of 2 * max(left_bits, right_bits) bits
    ; as guess_size is 128 and divisor_bits >= 128 we can simplify it just to 2 * divisor_bits
    DIV_REM_GUESS_DELTA_MUL_FULL_SIZE = 2 * divisor_bits

    ; mul_low returns result of max(left_bits, right_bits) bits
    ; as guess_size is 128 and divisor_bits >= 128 we can simplify it just to divisor_bits
    DIV_REM_GUESS_DELTA_MUL_LOW_SIZE = divisor_bits

  if DIV_REM_GUESS_DELTA_MUL_LOW_SIZE >= DIV_REM_GUESS_DELTA_EXPECTED_SIZE
    DivRemGuess64_MulLowX128 divisor_bits
  else
    DivRemGuess64_MulX128 divisor_bits
  end if
    DisplayDec DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
    display 13, 10
}

macro DivRemGuess64_ShiftDelta dividend_bits, divisor_bits {
    lea     rcx, [.delta + 0]
    mov     rdx, [.correction]
    DivRemGuess64_ShlAssign dividend_bits
}

macro DivRemGuess64_ApplyDelta dividend_bits, divisor_bits {
      mov     rcx, [.remainder]
      lea     rdx, [.delta]
      DivRemGuess64_SubAssign dividend_bits
      mov     rcx, [.quotient]
  if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE = 64
      mov     rdx, qword [.guess_128 + 0]
  else if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE <= 128
      lea     rdx, [.guess_128]
  else
      lea     rdx, [.guess_q]
  end if
      DivRemGuess64_AddAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
}

macro DivRemGuess64_RecheckOnce dividend_bits, divisor_bits {
.recheck_once:
;reminder has same leading zeroes count as divisor so we can safely compare lowest divisor_bits bits
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        DivRemGuess64_Cmp divisor_bits
        jb      .end
        mov     rcx, [.quotient]
        DivRemGuess64_IncAssign dividend_bits
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        DivRemGuess64_SubAssign divisor_bits
        jmp     .end
}


if ~ definite bi_div_rem_guess_debug

bi_div_rem_guess_debug:
bi_div_rem_dump_dividend_msg:          db 'dividend:          ', 0
bi_div_rem_dump_divisor_msg:           db 'divisor:           ', 0
bi_div_rem_dump_divisor_shifted_msg:   db 'divisor shifted:   ', 0
bi_div_rem_dump_remainder_msg:         db 'remainder:         ', 0
bi_div_rem_dump_remainder_shifted_msg: db 'remainder shifted: ', 0
bi_div_rem_dump_guess_msg:             db 'guess:             ', 0
bi_div_rem_dump_delta_shifted_msg:     db 'delta shifted:     ', 0
bi_div_rem_dump_new_quotient_msg:      db 'new quotient:      ', 0
bi_div_rem_dump_new_remainder_msg:     db 'new remainder:     ', 0

end if