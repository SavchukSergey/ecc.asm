;Subtracts two bi512 values
;input:
; rcx - pointer to left bi512 value
; rdx - pointer to right bi512 value
; r8 - pointer to result bi512 value
; output:
; rax, CF - set to 1 if borrow
bi_sub_512_512:
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

        mov     rax, [rcx + 32]
        sbb     rax, [rdx + 32]
        mov     [r8 + 32], rax

        mov     rax, [rcx + 40]
        sbb     rax, [rdx + 40]
        mov     [r8 + 40], rax

        mov     rax, [rcx + 48]
        sbb     rax, [rdx + 48]
        mov     [r8 + 48], rax

        mov     rax, [rcx + 56]
        sbb     rax, [rdx + 56]
        mov     [r8 + 56], rax

        setc    al
        movzx   rax, al
        ret
