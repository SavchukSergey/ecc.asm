if ~ definite bi_inc_assign_512

;Increments bi512 value
;input:
;  rcx - left value. The modified value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_inc_assign_512:
    CheckRegBi512Alignment rcx, 'bi_inc_assign_512 rcx'

        xor     rax, rax
        stc
        adc     [rcx], rax
        adc     [rcx + 8], rax
        adc     [rcx + 16], rax
        adc     [rcx + 24], rax
        adc     [rcx + 32], rax
        adc     [rcx + 40], rax
        adc     [rcx + 48], rax
        adc     [rcx + 56], rax
        setc    al
        movzx   rax, al
        ret
end if