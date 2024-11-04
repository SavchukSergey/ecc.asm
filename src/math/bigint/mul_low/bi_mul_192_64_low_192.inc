if ~ definite bi_mul_192_64_low_192

;Multiplies bi192 by bi64 value and return low 192 bits
;input
;  rcx - pointer to bi192 left value
;  rdx - bi64 right value
;  r8 - result value (low 192 bits)
bi_mul_192_64_low_192:
    CheckRegBi192Alignment rcx, 'bi_mul_192_64_low_192 rcx'
    CheckRegBi192Alignment r8, 'bi_mul_192_64_low_192 r8'

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

        ret

end if