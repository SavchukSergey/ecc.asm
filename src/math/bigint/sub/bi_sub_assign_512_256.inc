if ~ definite bi_sub_assign_512_256

;Subtracts bi256 from bi512 value
;input:
;  rcx - left bi512 value. The modified value.
;  rdx - right bi128 value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_512_256:
        mov     rax, [rdx]
        sub     [rcx], rax

        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax

        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax

        mov     rax, [rdx + 24]
        sbb     [rcx + 24], rax

        sbb     qword [rcx + 32], 0
        sbb     qword [rcx + 40], 0
        sbb     qword [rcx + 48], 0
        sbb     qword [rcx + 56], 0

        setc    al
        movzx   rax, al
        ret

end if