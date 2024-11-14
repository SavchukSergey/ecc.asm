;@docs-ignore

macro DivRemGuess64_RecheckMulti dividend_bits, divisor_bits {
.recheck_multi:
if dividend_bits = divisor_bits
        mov     rcx, [.remainder]
else
        lea     rcx, [.remainder_temp]
end if
        mov     rdx, [.divisor]
        Call_Cmp dividend_bits, divisor_bits
        jb      .end
        mov     rcx, [.quotient]
        Call_IncAssign DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
if dividend_bits = divisor_bits
        mov     rcx, [.remainder]
else
        lea     rcx, [.remainder_temp]
end if
        mov     rdx, [.divisor]
        Call_SubAssign dividend_bits, divisor_bits
        jmp     .recheck_multi
}

macro RemGuess64_RecheckMulti dividend_bits, divisor_bits {
.recheck_multi:
if dividend_bits = divisor_bits
        mov     rcx, [.remainder]
else
        lea     rcx, [.remainder_temp]
end if
        mov     rdx, [.divisor]
        Call_Cmp dividend_bits, divisor_bits
        jb      .end
if dividend_bits = divisor_bits
        mov     rcx, [.remainder]
else
        lea     rcx, [.remainder_temp]
end if
        mov     rdx, [.divisor]
        Call_SubAssign dividend_bits, divisor_bits
        jmp     .recheck_multi
}
