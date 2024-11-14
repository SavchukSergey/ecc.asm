;Adds two bi192 values
;input:
;  rcx - pointer to left bi192 value
;  rdx - pointer to right bi192 value
;  r8 - pointer to result bi192 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_192_192:
    CheckRegBi192Alignment rcx, 'bi_add_192_192 rcx'
    CheckRegBi192Alignment rdx, 'bi_add_192_192 rdx'
    CheckRegBi192Alignment r8, 'bi_add_192_192 r8'

        mov     rax, [rcx]
        add     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        adc     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        adc     rax, [rdx + 16]
        mov     [r8 + 16], rax

        setc    al
        movzx   rax, al
        ret
