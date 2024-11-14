;Adds two bi256 values
;input:
;  rcx - pointer to left bi256 value
;  rdx - pointer to right bi256 value
;  r8 - pointer to result bi256 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_256_256:
    CheckRegBi256Alignment rcx, 'bi_add_256_256 rcx'
    CheckRegBi256Alignment rdx, 'bi_add_256_256 rdx'
    CheckRegBi256Alignment r8, 'bi_add_256_256 r8'

        mov     rax, [rcx]
        add     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        adc     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        adc     rax, [rdx + 16]
        mov     [r8 + 16], rax

        mov     rax, [rcx + 24]
        adc     rax, [rdx + 24]
        mov     [r8 + 24], rax

        setc    al
        movzx   rax, al
        ret
