if ~ definite bi_mul_64_64_low_64

;Multiplies two bi64 values
;input
;  rcx - left bi64 value
;  rdx - right bi64 value
;output
;  rax - result bi64 value (low 64 bits)
bi_mul_64_64_low_64:
;todo: bmi2
        mov     rax, rcx
        mul     rdx
        ret
end if