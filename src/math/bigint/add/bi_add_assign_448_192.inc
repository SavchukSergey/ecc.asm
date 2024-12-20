;Adds bi448 and bi192 values and assigns result to the left bi448 value
;input:
;  rcx - pointer to left bi448 value. The modified value
;  rdx - pointer to right bi192 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_448_192:
        mov     rax, [rdx]
        add     [rcx], rax

        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        mov     rax, [rdx + 16]
        adc     [rcx + 16], rax

        mov     rax, 0
        adc     [rcx + 24], rax
        adc     [rcx + 32], rax
        adc     [rcx + 40], rax
        adc     [rcx + 48], rax

        setc    al                 ;rax is cleared before
        ret