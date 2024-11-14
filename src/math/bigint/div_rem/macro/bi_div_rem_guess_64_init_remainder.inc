;@docs-ignore

macro DivRemGuess64_InitRemainder dividend_bits, divisor_bits {
if dividend_bits = divisor_bits
    mov     rcx, [.remainder]
else
    lea     rcx, [.remainder_temp]
end if
    mov     rdx, [.dividend]
    Fast_Copy dividend_bits
}
