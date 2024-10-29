if ~ definite bi_dec_assign_256

;Decrements bi256 value
;input:
;  rcx - left value. The modified value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_dec_assign_256:
    CheckRegAligned rcx, 'bi_dec_assign_256 rcx'

        xor     rax, rax
        stc
        sbb     [rcx], rax
        sbb     [rcx + 8], rax
        sbb     [rcx + 16], rax
        sbb     [rcx + 24], rax
        setc    al
        movzx   rax, al
        ret
end if