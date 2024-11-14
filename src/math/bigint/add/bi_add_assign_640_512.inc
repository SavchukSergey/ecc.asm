;Adds bi640 and bi512 values and assigns result to the left bi640 value
;input:
;  rcx - pointer to left bi640 value. The modified value
;  rdx - pointer to right bi512 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_640_512:
        mov     rax, [rdx]
        add     [rcx], rax
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax
        mov     rax, [rdx + 16]
        adc     [rcx + 16], rax
        mov     rax, [rdx + 24]
        adc     [rcx + 24], rax
        mov     rax, [rdx + 32]
        adc     [rcx + 32], rax
        mov     rax, [rdx + 40]
        adc     [rcx + 40], rax
        mov     rax, [rdx + 48]
        adc     [rcx + 48], rax
        mov     rax, [rdx + 56]
        adc     [rcx + 56], rax

        mov     rax, 0
        adc     [rcx + 64], rax
        adc     [rcx + 72], rax

        setc    al                 ;rax is cleared before
        ret
