if ~ definite bi_add_assign_512_256

;Adds two bi512 values
;input:
;  rcx - left value. The modified value
;  rdx - right value
;output:
;  rax - set to 1 if overflow
bi_add_assign_512_256:
        mov     rax, [rdx]
        add     [rcx], rax

        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        mov     rax, [rdx + 16]
        adc     [rcx + 16], rax

        mov     rax, [rdx + 24]
        adc     [rcx + 24], rax

        mov     rax, 0
        adc     [rcx + 32], rax
        adc     [rcx + 40], rax
        adc     [rcx + 48], rax
        adc     [rcx + 56], rax

        setc    al                 ;rax is cleared before
        ret
end if