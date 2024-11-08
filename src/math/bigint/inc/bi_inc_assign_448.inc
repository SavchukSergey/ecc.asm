if ~ definite bi_inc_assign_448

;Increments bi448 value
;input:
;  rcx - left value. The modified value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_inc_assign_448:
        xor     rax, rax
        stc
        adc     [rcx], rax
        adc     [rcx + 8], rax
        adc     [rcx + 16], rax
        adc     [rcx + 24], rax
        adc     [rcx + 32], rax
        adc     [rcx + 40], rax
        adc     [rcx + 48], rax
        setc    al
        movzx   rax, al
        ret
end if