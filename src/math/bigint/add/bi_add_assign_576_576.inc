if ~ definite bi_add_assign_576_576

;Adds two bi576 values
;input:
;  rcx - left value. The modified value
;  rdx - right value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_576_576:
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
        adc     [rcx + 64], rax
        setc    al
        movzx   rax, al
        ret
end if