macro DivRemGuess64_RecheckMulti dividend_bits, divisor_bits {
.recheck_multi:
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_Cmp dividend_bits, divisor_bits
        jb      .end
        mov     rcx, [.quotient]
        Call_IncAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_SubAssign dividend_bits, divisor_bits
        jmp     .recheck_multi
}

macro RemGuess64_RecheckMulti dividend_bits, divisor_bits {
.recheck_multi:
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_Cmp dividend_bits, divisor_bits
        jb      .end
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_SubAssign dividend_bits, divisor_bits
        jmp     .recheck_multi
}
