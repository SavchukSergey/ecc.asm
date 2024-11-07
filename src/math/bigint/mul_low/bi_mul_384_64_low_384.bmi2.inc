if ~ definite bi_mul_384_64_low_384_bmi2

;Multiplies bi384 by bi64 value and return low 384 bits
;input
;  rcx - pointer to bi384 left value
;  rdx - bi64 right value
;  r8 - result value (low 384 bits)
bi_mul_384_64_low_384_bmi2:
    CheckRegBi384Alignment rcx, 'bi_mul_384_64_low_384_bmi2 rcx'
    CheckRegBi384Alignment r8, 'bi_mul_384_64_low_384_bmi2 r8'

        mov     r9, rcx
        mov     rcx, rdx
        xor     rax, rax             ; CF = 0,

        mov     rdx, [r9 + 0]
        mulx    rdx, rax, rcx
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx

        mov     rdx, [r9 + 8]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 8]        ; CF = carry for [result + 16]
        mov     [r8 + 8], rax
        mov     [r8 + 16], rdx

        mov     rdx, [r9 + 16]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 16]       ; CF = carry for [result + 24]
        mov     [r8 + 16], rax
        mov     [r8 + 24], rdx

        mov     rdx, [r9 + 24]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 24]       ; CF = carry for [result + 32]
        mov     [r8 + 24], rax
        mov     [r8 + 32], rdx

        mov     rdx, [r9 + 32]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 32]       ; CF = carry for [result + 40]
        mov     [r8 + 32], rax
        mov     [r8 + 40], rdx

        mov     rdx, [r9 + 40]
        mulx    rdx, rax, rcx
        adc     [r8 + 40], rax

        ret

end if