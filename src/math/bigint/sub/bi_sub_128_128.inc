;Subtracts two bi128 values
;input:
; rcx - pointer to left bi128 value
; rdx - pointer to right bi128 value
; r8 - pointer to result bi128 value
; output:
; rax, CF - set to 1 if borrow
bi_sub_128_128:
        mov     rax, [rcx]
        sub     rax, [rdx]
        mov     [r8], rax
        mov     rax, [rcx + 8]
        sbb     rax, [rdx + 8]
        mov     [r8 + 8], rax
        setc    al
        movzx   rax, al
        ret