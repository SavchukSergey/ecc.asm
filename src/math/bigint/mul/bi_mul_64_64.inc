if ~ definite bi_mul_64_64

;Multiplies two bi128 values
; Note: values provided are 64 actual values not references
;input
; rcx - left value
; rdx - right value
; r8 - pointer to result value
bi_mul_64_64:
        mov     rax, rcx
        mul     rdx
        mov     [r8], rax
        mov     [r8 + 8], rdx

        ret
end if