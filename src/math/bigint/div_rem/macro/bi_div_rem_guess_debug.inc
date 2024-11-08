if ~ definite bi_div_rem_guess_debug

bi_div_rem_guess_debug:


macro DivRemGuess64_DumpArgs dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    call    Console_WriteLine

    DivRemGuess64_DumpDividend dividend_bits, divisor_bits
    DivRemGuess64_DumpDivisor dividend_bits, divisor_bits
  end if
}

macro DivRemGuess64_WriteUIntHex bits {
  if bits = 64
    call    Console_WriteUInt64Hex
  else if bits = 128
    call    Console_WriteUInt128Hex
  else if bits = 192
    call    Console_WriteUInt192Hex
  else if bits = 256
    call    Console_WriteUInt256Hex
  else if bits = 320
    call    Console_WriteUInt320Hex
  else if bits = 512
    call    Console_WriteUInt512Hex
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

    call    Console_WriteLine
  end if
}

macro DivRemGuess64_DumpDivisor dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    push    rsi
    lea     rsi, [bi_div_rem_dump_divisor_msg]
    call    Console_WriteString
    pop     rsi

    mov     rcx, [.divisor]
    DivRemGuess64_WriteUIntHex divisor_bits

    call    Console_WriteLine
  end if
}

macro DivRemGuess64_DumpDivisorShifted dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    push    rsi
    lea     rsi, [bi_div_rem_dump_divisor_shifted_msg]
    call    Console_WriteString
    pop     rsi

    mov     rcx, [.divisor_shifted]
    DivRemGuess64_WriteUIntHex 64

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

    call    Console_WriteLine
  end if
}

macro DivRemGuess64_DumpGuess dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    push    rsi
    lea     rsi, [bi_div_rem_dump_guess_msg]
    call    Console_WriteString
    pop     rsi

    lea     rcx, [.guess_128]
    call    Console_WriteUInt128Hex

    call    Console_WriteLine
  end if
}

macro DivRemGuess64_DumpGuessFixed dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    push    rsi
    lea     rsi, [bi_div_rem_dump_guess_corrected_msg]
    call    Console_WriteString
    pop     rsi

    lea     rcx, qword [.guess_128]
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
    DivRemGuess64_WriteUIntHex 128

    call    Console_WriteLine
  end if
}

macro DivRemGuess64_DumpDelta dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    push    rsi
    lea     rsi, [bi_div_rem_dump_delta_msg]
    call    Console_WriteString
    pop     rsi

    lea     rcx, [.delta]
    DivRemGuess64_WriteUIntHex dividend_bits

    call    Console_WriteLine
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

    call    Console_WriteLine
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

macro DivRemGuess64_LoopStart dividend_bits, divisor_bits {
  if definite BI_DEV_REM_GUESS_64_DEBUG
    push    rsi
    lea     rsi, [bi_div_rem_dump_loop_msg]
    call    Console_WriteString
    pop     rsi
  end if
}

bi_div_rem_dump_dividend_msg:          db 'dividend:          ', 0
bi_div_rem_dump_divisor_msg:           db 'divisor:           ', 0
bi_div_rem_dump_divisor_shifted_msg:   db 'divisor shifted:   ', 0
bi_div_rem_dump_remainder_msg:         db 'remainder:         ', 0
bi_div_rem_dump_remainder_shifted_msg: db 'remainder shifted: ', 0
bi_div_rem_dump_guess_msg:             db 'guess:             ', 0
bi_div_rem_dump_guess_corrected_msg:   db 'guess (corrected): ', 0
bi_div_rem_dump_delta_msg:             db 'delta:             ', 0
bi_div_rem_dump_delta_shifted_msg:     db 'delta shifted:     ', 0
bi_div_rem_dump_new_quotient_msg:      db 'new quotient:      ', 0
bi_div_rem_dump_new_remainder_msg:     db 'new remainder:     ', 0
bi_div_rem_dump_loop_msg:              db '----------------------------------', 13, 10, 0

end if