macro DivRemGuess64_RecheckOnce dividend_bits, divisor_bits {
.recheck_once:
;remainder has same leading zeroes count as divisor so we can safely compare lowest divisor_bits bits
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_Cmp divisor_bits, divisor_bits
        jb      .end
        mov     rcx, [.quotient]
        Call_IncAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_SubAssign DIV_REM_GUESS_REMAINDER_ACTUAL_SIZE, divisor_bits
        DivRemGuess64_Epilog dividend_bits, divisor_bits
}

macro RemGuess64_RecheckOnce dividend_bits, divisor_bits {
.recheck_once:
;remainder has same leading zeroes count as divisor so we can safely compare lowest divisor_bits bits
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_Cmp divisor_bits, divisor_bits
        jb      .end
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        Call_SubAssign DIV_REM_GUESS_REMAINDER_ACTUAL_SIZE, divisor_bits
        DivRemGuess64_Epilog dividend_bits, divisor_bits
}
