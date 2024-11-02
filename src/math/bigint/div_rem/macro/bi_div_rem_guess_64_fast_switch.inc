macro DivRemGuess64_FastSwitch dividend_bits, divisor_bits {
    cmp   qword [rdx + (divisor_bits / 8) - 8], 0
    jnz   .fast_divisor_switch_ok

if divisor_bits = 128
    mov   rdx, [rdx]
end if

    mov   qword [r9 + (dividend_bits / 8) - 8], 0     ; clear high u64 of remainder
    ;todo: Jmp_DivRem
    ;todo: after refactoring of remainder output width -> clear highest remainder qword before jump
    Call_DivRem dividend_bits, (divisor_bits - 64)
    ret
.fast_divisor_switch_ok:


    cmp   qword [rcx + (dividend_bits / 8) - 8], 0
    jnz   .fast_dividend_switch_ok
    mov   qword [r8 + (dividend_bits / 8) - 8], 0     ; clear high u64 of quotient
    mov   qword [r9 + (dividend_bits / 8) - 8], 0     ; clear high u64 of remainder, todo: actually no need to set it after rfactoring

if dividend_bits = 128
    mov   rcx, [rcx]
end if
    ;todo: Jmp_DivRem
    Call_DivRem (dividend_bits - 64), divisor_bits
    ret
.fast_dividend_switch_ok:

}

;todo: fast switch for rem