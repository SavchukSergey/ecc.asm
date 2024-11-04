macro DivRemGuess64_FastSwitch dividend_bits, divisor_bits {
    cmp   qword [rdx + (divisor_bits / 8) - 8], 0
    jnz   .fast_divisor_switch_ok

if divisor_bits = 128
    mov   rdx, [rdx]
end if

    mov   qword [r9 + (dividend_bits / 8) - 8], 0     ; clear high u64 of remainder
    ;todo: Jmp_DivRem
    ;todo: refactor all div_rem to return remainder same same as divisor
    Call_DivRem dividend_bits, (divisor_bits - 64)
    ret
.fast_divisor_switch_ok:
DIV_REM_GUESS_MIN_DIVISOR_SIZE = (divisor_bits - 64)


if dividend_bits > divisor_bits

    cmp   qword [rcx + (dividend_bits / 8) - 8], 0
    jnz   .fast_dividend_switch_ok
    mov   qword [r8 + (dividend_bits / 8) - 8], 0     ; clear high u64 of quotient

if dividend_bits = 128
    mov   rcx, [rcx]
end if
    ;todo: Jmp_DivRem
    Call_DivRem (dividend_bits - 64), divisor_bits
    ret
.fast_dividend_switch_ok:

end if

}

;todo: fast switch for rem