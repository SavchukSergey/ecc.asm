;@docs-ignore

macro DivRemGuess64_FastSwitch dividend_bits, divisor_bits {
    cmp   qword [rdx + (divisor_bits / 8) - 8], 0
    jnz   .fast_divisor_switch_ok

if divisor_bits = 128
    mov   rdx, [rdx]
end if

    mov   qword [r9 + (divisor_bits / 8) - 8], 0     ; clear high bi64 of remainder
    Jmp_DivRem dividend_bits, (divisor_bits - 64)
.fast_divisor_switch_ok:


if dividend_bits > divisor_bits

    cmp   qword [rcx + (dividend_bits / 8) - 8], 0
    jnz   .fast_dividend_switch_ok
    mov   qword [r8 + (dividend_bits / 8) - 8], 0     ; clear high bi64 of quotient

if dividend_bits = 128
    mov   rcx, [rcx]
end if
    Jmp_DivRem (dividend_bits - 64), divisor_bits
.fast_dividend_switch_ok:

end if

}

macro RemGuess64_FastSwitch dividend_bits, divisor_bits {
    cmp   qword [rdx + (divisor_bits / 8) - 8], 0
    jnz   .fast_divisor_switch_ok

if divisor_bits = 128
    mov   rdx, [rdx]
end if

    mov   qword [r8 + (divisor_bits / 8) - 8], 0     ; clear high bi64 of remainder
    Jmp_Rem dividend_bits, (divisor_bits - 64)
.fast_divisor_switch_ok:


if dividend_bits > divisor_bits

    cmp   qword [rcx + (dividend_bits / 8) - 8], 0
    jnz   .fast_dividend_switch_ok

if dividend_bits = 128
    mov   rcx, [rcx]
end if
    Jmp_Rem (dividend_bits - 64), divisor_bits
.fast_dividend_switch_ok:

end if

}
