if ~ definite bi_add_assign_384_128

;Adds two bi384 values
;input:
;  rcx - left value. The modified value
;  rdx - right value
;output:
;  rax - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_384_128:
        mov     rax, [rdx]
        add     [rcx], rax
        
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        adc     qword [rcx + 16], 0
        adc     qword [rcx + 24], 0
        adc     qword [rcx + 32], 0
        adc     qword [rcx + 40], 0

        setc    al
        movzx   rax, al
        ret
end if