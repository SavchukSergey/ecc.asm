;@docs-ignore

macro DivRemGuess64_RecheckOnce dividend_bits, divisor_bits {
.recheck_once:
;remainder has same leading zeroes count as divisor so we can safely compare lowest divisor_bits bits
;the estimate error can exceed one divisor, so keep correcting in a loop
if dividend_bits = divisor_bits
        mov     rcx, [.remainder]
else
        lea     rcx, [.remainder_temp]
end if
        mov     rdx, [.divisor]
        Call_Cmp divisor_bits, divisor_bits
        jb      .end
        jmp     .recheck_multi
}

macro RemGuess64_RecheckOnce dividend_bits, divisor_bits {
.recheck_once:
;remainder has same leading zeroes count as divisor so we can safely compare lowest divisor_bits bits
;the estimate error can exceed one divisor, so keep correcting in a loop
if dividend_bits = divisor_bits
        mov     rcx, [.remainder]
else
        lea     rcx, [.remainder_temp]
end if
        mov     rdx, [.divisor]
        Call_Cmp divisor_bits, divisor_bits
        jb      .end
        jmp     .recheck_multi
}
