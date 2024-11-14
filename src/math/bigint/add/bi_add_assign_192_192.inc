;Adds two bi192 values and assigns result to the left bi192 value
;input:
;  rcx - pointer to left bi192 value. The modified value
;  rdx - pointer to right bi192 value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_192_192:
        mov     rax, [rdx]
        add     [rcx], rax
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax
        mov     rax, [rdx + 16]
        adc     [rcx + 16], rax
        setc    al
        movzx   rax, al
        ret