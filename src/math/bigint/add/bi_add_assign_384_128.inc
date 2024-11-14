;Adds bi384 and bi128 values and assigns result to the left bi384 value
;input:
;  rcx - pointer to left bi384 value. The modified value
;  rdx - pointer to right bi128 value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_384_128:
        mov     rax, [rdx]
        add     [rcx], rax
        
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        mov     rax, 0
        adc     qword [rcx + 16], rax
        adc     qword [rcx + 24], rax
        adc     qword [rcx + 32], rax
        adc     qword [rcx + 40], rax

        setc    al                 ;rax is cleared before
        ret
