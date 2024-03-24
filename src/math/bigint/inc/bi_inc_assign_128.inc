if ~ definite bi_inc_assign_128

;Increments bi128 value
;input:
;  rcx - left value. The modified value
;output:
;  rax - set to 1 if overflow
;  CF - set to 1 if overflow
bi_inc_assign_128:
        xor     rax, rax
        stc
        adc     [rcx], rax
        adc     [rcx + 8], rax
        setc    al
        movzx   rax, al
        ret
end if