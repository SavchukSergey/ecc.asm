;Adds two bi320 values and assigns result to the left bi320 value
;input:
;  rcx - left value. The modified value
;  rdx - right value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_320_320:
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
        setc    al
        movzx   rax, al
        ret