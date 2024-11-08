if ~ definite bi_add_assign_1024_1024

;Adds two bi1024 values
;input:
;  rcx - pointer to left bi1024 value. The modified value
;  rdx - pointer to right bi1024 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_1024_1024:
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

        mov     rax, [rdx + 64]
        add     [rcx + 64], rax
        mov     rax, [rdx + 72]
        adc     [rcx + 72], rax
        mov     rax, [rdx + 80]
        adc     [rcx + 80], rax
        mov     rax, [rdx + 88]
        adc     [rcx + 88], rax
        mov     rax, [rdx + 96]
        adc     [rcx + 96], rax
        mov     rax, [rdx + 104]
        adc     [rcx + 104], rax
        mov     rax, [rdx + 112]
        adc     [rcx + 112], rax
        mov     rax, [rdx + 120]
        adc     [rcx + 120], rax

        setc    al
        movzx   rax, al
        ret

end if