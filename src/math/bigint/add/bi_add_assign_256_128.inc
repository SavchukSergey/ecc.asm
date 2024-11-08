if ~ definite bi_add_assign_256_128

;Adds two bi256 values
;input:
;  rcx - left bi256 value. The modified value
;  rdx - right bi128 value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_256_128:
    CheckRegBi256Alignment rcx, 'bi_add_assign_256_128 rcx'
    CheckRegBi128Alignment rdx, 'bi_add_assign_256_128 rdx'

        mov     rax, [rdx]
        add     [rcx], rax

        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        mov     rax, 0
        adc     qword [rcx + 16], rax
        adc     qword [rcx + 24], rax

        setc    al                 ;rax is cleared before
        ret
end if