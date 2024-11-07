if ~ definite bi_sub_assign_192_128

;Subtracts bi128 from bi192 value
;input:
;  rcx - left bi192 value. The modified value.
;  rdx - right bi128 value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_192_128:
        mov     rax, [rdx]
        sub     [rcx], rax
        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax
        sbb     qword [rcx + 16], 0
        setc    al
        movzx   rax, al
        ret

end if