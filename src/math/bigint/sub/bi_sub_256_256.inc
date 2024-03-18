if ~ definite bi_sub_256_256

;Subtracts two bi256 values
;input
;  rcx - left value
;  rdx - right value
;  r8 - result value
;output
;  rax - set to 1 if borrow
;  CF - set to 1 if borrow
bi_sub_256_256:
        mov     rax, [rcx]
        sub     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        sbb     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        sbb     rax, [rdx + 16]
        mov     [r8 + 16], rax

        mov     rax, [rcx + 24]
        sbb     rax, [rdx + 24]
        mov     [r8 + 24], rax

        setc    al
        movzx   rax, al
        ret

end if