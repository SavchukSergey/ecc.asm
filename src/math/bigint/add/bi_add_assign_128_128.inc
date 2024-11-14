;Adds two bi128 values and assigns result to the left bi128 value
;input:
;  rcx - pointer to left bi128 value. The modified value
;  rdx - pointer to right bi128 value
;output:
;  rax, CF - set to 1 if overflow
bi_add_assign_128_128:
        CheckRegBi128Alignment rcx, 'bi_add_assign_128_128 rcx'
        CheckRegBi128Alignment rdx, 'bi_add_assign_128_128 rdx'
        
        mov     rax, [rdx]
        add     [rcx], rax
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax
        setc    al
        movzx   rax, al
        ret