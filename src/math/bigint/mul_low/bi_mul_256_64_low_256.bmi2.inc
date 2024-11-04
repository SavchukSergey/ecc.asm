if ~ definite bi_mul_256_64_low_256_bmi2

;Multiplies bi256 by bi64 value and return low 256 bits
;input
;  rcx - pointer to bi256 left value
;  rdx - bi64 right value
;  r8 - result value (low 256 bits)
bi_mul_256_64_low_256_bmi2:
    CheckRegBi256Alignment rcx, 'bi_mul_256_64_low_256_bmi2 rcx'
    CheckRegBi256Alignment r8, 'bi_mul_256_64_low_256_bmi2 r8'

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
        adc     [r8 + 24], rax

        ret

end if