;Squares bi64 value
;input:
;  rcx - left bi64 value
;  rdx - pointer to result bi128 value
bi_square_64:
    CheckRegAligned r8, 'bi_square_64 rdx'
        mov     r8, rdx

        mov     rax, rcx
        mul     rcx
        mov     [r8], rax
        mov     [r8 + 8], rdx

        ret