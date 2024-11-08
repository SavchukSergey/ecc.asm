if ~ definite bi_inc_assign_192

;Increments bi192 value
;input:
;  rcx - left value. The modified value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_inc_assign_192:
        xor     rax, rax
        stc
        adc     [rcx], rax
        adc     [rcx + 8], rax
        adc     [rcx + 16], rax
        setc    al
        movzx   rax, al
        ret
end if