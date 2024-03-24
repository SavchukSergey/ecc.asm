if ~ definite bi_sub_assign_256_128

;Subtracts bi128 from bi256 value
;input:
;  rcx - left bi256 value. The modified value.
;  rdx - right bi128 value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_assign_256_128:
        mov     rax, [rdx]
        sub     [rcx], rax
        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax
        sbb     qword [rcx + 16], 0
        sbb     qword [rcx + 24], 0
        setc    al
        movzx   rax, al
        ret

end if