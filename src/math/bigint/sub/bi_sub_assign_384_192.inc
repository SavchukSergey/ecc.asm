if ~ definite bi_sub_assign_384_192

;Subtracts bi192 from bi384 value
;input:
;  rcx - left bi384 value. The modified value.
;  rdx - right bi192 value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_384_192:
        mov     rax, [rdx]
        sub     [rcx], rax

        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax

        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax

        sbb     qword [rcx + 24], 0
        sbb     qword [rcx + 32], 0
        sbb     qword [rcx + 40], 0

        setc    al
        movzx   rax, al
        ret

end if