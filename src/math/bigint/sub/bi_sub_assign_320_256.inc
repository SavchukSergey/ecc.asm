if ~ definite bi_sub_assign_320_256

;Subtracts bi256 from bi320 value
;input:
;  rcx - left bi320 value. The modified value.
;  rdx - right bi256 value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_320_256:
        mov     rax, [rdx]
        sub     [rcx], rax

        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax

        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax

        mov     rax, [rdx + 24]
        sbb     [rcx + 24], rax

        sbb     qword [rcx + 32], 0

        setc    al
        movzx   rax, al
        ret

end if