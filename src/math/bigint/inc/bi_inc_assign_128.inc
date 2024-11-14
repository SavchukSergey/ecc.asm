;Increments bi128 value
;input:
;  rcx - pointer to left bi128 value. The modified value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_inc_assign_128:
        xor     rax, rax
        stc
        adc     [rcx], rax
        adc     [rcx + 8], rax
        setc    al
        movzx   rax, al
        ret