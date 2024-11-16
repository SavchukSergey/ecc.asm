;Subtracts two bi256 values
;input:
; rcx - pointer to left bi256 value
; rdx - pointer to right bi256 value
; r8 - pointer to result bi256 value
; output:
; rax, CF - set to 1 if borrow
bi_sub_256_256:
        CheckRegBi256Alignment rcx, 'bi_sub_256_256 rcx'
        CheckRegBi256Alignment rdx, 'bi_sub_256_256 rdx'
        CheckRegBi256Alignment r8, 'bi_sub_256_256 r8'

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
