;Adds two bi128 values
;input:
;  rcx - pointer to left bi128 value
;  rdx - pointer to right bi128 value
;  r8 - pointer to result bi128  value
;output:
;  rax, CF - set to 1 if overflow
bi_add_128_128:
    CheckRegBi128Alignment rcx, 'bi_add_128_128 rcx'
    CheckRegBi128Alignment rdx, 'bi_add_128_128 rdx'
    CheckRegBi128Alignment r8, 'bi_add_128_128 r8'

        mov     rax, [rcx]
        add     rax, [rdx]
        mov     [r8], rax
        mov     rax, [rcx + 8]
        adc     rax, [rdx + 8]
        mov     [r8 + 8], rax
        setc    al
        movzx   rax, al
        ret
