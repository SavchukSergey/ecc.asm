if ~ definite bi_add_128_128

;Adds two bi128 values
;input:
;  rcx - left value
;  rdx - right value
;  r8 - result value
;output:
;  rax, CF - set to 1 if overflow
bi_add_128_128:
    CheckRegAligned rcx, 'bi_add_128_128 rcx'
    CheckRegAligned rdx, 'bi_add_128_128 rdx'
    CheckRegAligned r8, 'bi_add_128_128 r8'

        mov     rax, [rcx]
        add     rax, [rdx]
        mov     [r8], rax
        mov     rax, [rcx + 8]
        adc     rax, [rdx + 8]
        mov     [r8 + 8], rax
        setc    al
        movzx   rax, al
        ret

end if
