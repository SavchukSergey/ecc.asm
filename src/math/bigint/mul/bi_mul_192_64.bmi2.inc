if ~ definite bi_mul_192_64_bmi2

;Multiplies bi192 by u64
;input
; rcx - left bi192 value
; rdx - right u64 value
; r8 - result bi256 value
bi_mul_192_64_bmi2:
    CheckRegAligned rcx, 'bi_mul_192_64_bmi2 rcx'
    CheckRegAligned r8, 'bi_mul_192_64_bmi2 r8'

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
        adc     rdx, 0
        mov     [r8 + 24], rdx
        ret

end if
