if ~ definite bi_inc_assign_256

;Increments bi256 value
;input:
;  rcx - left value. The modified value
;output:
;  rax - set to 1 if overflow
;  CF - set to 1 if overflow
bi_inc_assign_256:
    CheckRegAligned rcx, 'bi_inc_assign_256 rcx'

        xor     rax, rax
        stc
        adc     [rcx], rax
        adc     [rcx + 8], rax
        adc     [rcx + 16], rax
        adc     [rcx + 24], rax
        setc    al
        movzx   rax, al
        ret
end if