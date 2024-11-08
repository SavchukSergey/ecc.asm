if ~ definite bi_mul_64_64

;Multiplies two bi64 values
;input
;  rcx - left bi64 value
;  rdx - right bi64 value
;  r8 - pointer to result bi128 value
bi_mul_64_64:
    CheckRegBi128Alignment r8, 'bi_mul_64_64 r8'

    if BMI2_ENABLED
        mulx    rdx, rax, rcx
        mov     [r8], rax
        mov     [r8 + 8], rdx
    else
        mov     rax, rcx
        mul     rdx
        mov     [r8], rax
        mov     [r8 + 8], rdx
    end if
        ret


end if