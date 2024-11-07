if ~ definite bi_sub_assign_448_320

;Subtracts bi320 from bi448 value
;input:
;  rcx - left bi448 value. The modified value.
;  rdx - right bi320 value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_448_320:
        mov     rax, [rdx]
        sub     [rcx], rax

        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax

        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax

        mov     rax, [rdx + 24]
        sbb     [rcx + 24], rax

        mov     rax, [rdx + 32]
        sbb     [rcx + 32], rax

        sbb     qword [rcx + 40], 0
        sbb     qword [rcx + 48], 0

        setc    al
        movzx   rax, al
        ret

end if