if ~ definite bi_mul_128_64_low_128

;Multiplies bi128 by bi64 values
;input
; rcx - pointer to left bi128 value
; rdx - right bi64 value
; r8 - result value (low 128 bits)
bi_mul_128_64_low_128:
        mov     r9, rdx

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, r9
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx

        mov     rdx, [rcx + 8]
        mulx    rdx, rax, r9
        add     [r8 + 8], rax

        ret
end if