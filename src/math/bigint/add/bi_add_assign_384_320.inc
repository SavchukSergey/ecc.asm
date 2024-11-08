if ~ definite bi_add_assign_384_320

;Adds bi384 and bi320 values
;input:
;  rcx - pointer to left bi384 value. The modified value
;  rdx - pointer to right bi320 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_384_320:
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

        mov     rax, 0
        adc     [rcx + 40], rax

        setc    al                 ;rax is cleared before
        ret
end if