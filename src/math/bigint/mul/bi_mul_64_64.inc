if ~ definite bi_mul_64_64

;Multiplies two bi64 values
;input
;  rcx - left bi64 value
;  rdx - right bi64 value
;  r8 - pointer to result bi128 value
bi_mul_64_64:
    CheckRegAligned r8, 'bi_mul_64_64 r8'

        mov     rax, rcx
        mul     rdx
        mov     [r8], rax
        mov     [r8 + 8], rdx

        ret
end if