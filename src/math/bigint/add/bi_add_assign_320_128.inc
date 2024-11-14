;Adds bi320 and bi128 values and assigns result to the left bi320 value
;input:
;  rcx - pointer to left bi320 value. The modified value
;  rdx - pointer to right bi320 value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_320_128:
        mov     rax, [rdx]
        add     [rcx], rax
        
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        mov     rax, 0
        adc     qword [rcx + 16], rax
        adc     qword [rcx + 24], rax
        adc     qword [rcx + 32], rax

        setc    al                 ;rax is cleared before
        ret