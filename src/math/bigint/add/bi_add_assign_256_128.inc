if ~ definite bi_add_assign_256_128

;Adds two bi256 values
;input:
;  rcx - left value. The modified value
;  rdx - right value
;output:
;  rax - set to 1 if overflow
;  CF - set to 1 if overflow
bi_add_assign_256_128:
        mov     rax, [rdx]
        add     [rcx], rax

        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax

        adc     qword [rcx + 16], 0
        adc     qword [rcx + 24], 0

        setc    al
        movzx   rax, al
        ret
end if