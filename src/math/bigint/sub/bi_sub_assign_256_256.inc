if ~ definite bi_sub_assign_256_256

;Subtracts two bi256 values
;input:
;  rcx - left value. The modified value.
;  rdx - right value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_256_256:
        CheckRegAligned rcx, 'bi_sub_assign_256_256 rcx'
        CheckRegAligned rdx, 'bi_sub_assign_256_256 rdx'

        mov     rax, [rdx]
        sub     [rcx], rax

        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax

        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax

        mov     rax, [rdx + 24]
        sbb     [rcx + 24], rax

        setc    al
        movzx   rax, al
        ret

end if