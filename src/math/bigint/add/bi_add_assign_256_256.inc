if ~ definite bi_add_assign_256_256

;Adds two bi256 values
;input:
;  rcx - pointer to left bi256 value. The modified value
;  rdx - pointer to right bi256 value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_256_256:
        mov     rax, [rdx]
        add     [rcx], rax
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax
        mov     rax, [rdx + 16]
        adc     [rcx + 16], rax
        mov     rax, [rdx + 24]
        adc     [rcx + 24], rax
        setc    al
        movzx   rax, al
        ret
end if