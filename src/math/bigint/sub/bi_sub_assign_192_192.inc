if ~ definite bi_sub_assign_192_192

;Subtracts two bi192 values
;input:
;  rcx - left value. The modified value.
;  rdx - right value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_192_192:
        CheckRegBi192Alignment rcx, 'bi_sub_assign_192_192 rcx'
        CheckRegBi192Alignment rdx, 'bi_sub_assign_192_192 rdx'

        mov     rax, [rdx]
        sub     [rcx], rax

        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax

        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax

        setc    al
        movzx   rax, al
        ret

end if