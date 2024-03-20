if ~ definite bi_mul_low_64_64

;Multiplies two bi64 values
;input
;  rcx - left value
;  rdx - right value
;output
;  rax - result value (low 64 bits)
bi_mul_low_64_64:
        mov     rax, rcx
        mul     rdx
        ret
end if