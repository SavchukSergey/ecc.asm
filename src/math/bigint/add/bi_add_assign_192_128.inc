if ~ definite bi_add_assign_192_128

;Adds bi256 and bi128 values
;input:
;  rcx - pointer to left bi192 value. The modified value
;  rdx - pointer to right bi128 value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_192_128:
        mov     rax, [rdx]
        add     [rcx], rax
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax
        adc     qword [rcx + 16], 0
        setc    al
        movzx   rax, al
        ret
end if