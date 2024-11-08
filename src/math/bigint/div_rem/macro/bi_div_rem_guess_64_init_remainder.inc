macro DivRemGuess64_InitRemainder dividend_bits, divisor_bits {
    mov     rcx, [.remainder]
    mov     rdx, [.dividend]
    Fast_Copy dividend_bits
}
