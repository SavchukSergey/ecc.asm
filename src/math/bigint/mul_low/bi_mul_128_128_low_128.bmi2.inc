if ~ definite bi_mul_128_128_low_128_bmi2

;Multiplies two bi128 values
;input
; rcx - pointer to left bi128 value
; rdx - pointer to right bi128 value
; r8 - pointer to result bi128 value (low 128 bits)
bi_mul_128_128_low_128_bmi2:
        mov     r9, rdx

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, qword [r9 + 0]
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, qword [r9 + 8]
        add     [r8 + 8], rax

        mov     rdx, [rcx + 8]
        mulx    rdx, rax, qword [r9 + 0]
        add     [r8 + 8], rax

        ret

end if