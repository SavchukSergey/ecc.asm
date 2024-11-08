if ~ definite bi_add_assign_448_128

;Adds two bi448 values
;input:
;  rcx - left value. The modified value
;  rdx - right value
;output:
;  rax, CF - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_448_128:
        mov     rax, [rdx]
        add     [rcx], rax
        
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        mov     rax, 0
        adc     qword [rcx + 16], rax
        adc     qword [rcx + 24], rax
        adc     qword [rcx + 32], rax
        adc     qword [rcx + 40], rax
        adc     qword [rcx + 48], rax

        setc    al                 ;rax is cleared before
        ret
end if