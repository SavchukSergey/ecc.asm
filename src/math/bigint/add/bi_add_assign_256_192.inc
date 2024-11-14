;Adds bi256 and bi192 values and assigns result to the left bi256 value
;input:
;  rcx - pointer to left bi256 value. The modified value
;  rdx - pointer to right bi192 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_256_192:
        mov     rax, [rdx]
        add     [rcx], rax

        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        mov     rax, [rdx + 16]
        adc     [rcx + 16], rax

        mov     rax, 0
        adc     [rcx + 24], rax

        setc    al                 ;rax is cleared before
        ret