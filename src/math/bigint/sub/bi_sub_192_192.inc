;Subtracts two bi192 values
;input:
; rcx - pointer to left bi192 value
; rdx - pointer to right bi192 value
; r8 - pointer to result bi192 value
; output:
; rax, CF - set to 1 if borrow
bi_sub_192_192:
        CheckRegBi192Alignment rcx, 'bi_sub_192_192 rcx'
        CheckRegBi192Alignment rdx, 'bi_sub_192_192 rdx'
        CheckRegBi192Alignment r8, 'bi_sub_192_192 r8'

        mov     rax, [rcx]
        sub     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        sbb     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        sbb     rax, [rdx + 16]
        mov     [r8 + 16], rax

        setc    al
        movzx   rax, al
        ret
