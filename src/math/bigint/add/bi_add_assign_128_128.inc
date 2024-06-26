if ~ definite bi_add_assign_128_128

;Adds two bi128 values
;input:
;  rcx - left value. The modified value
;  rdx - right value
;output:
;  rax - set to 1 if overflow
bi_add_assign_128_128:
;        CheckRegAligned rcx, 'bi_add_assign_128_128 rcx'
;        CheckRegAligned rdx, 'bi_add_assign_128_128 rdx'
        
        mov     rax, [rdx]
        add     [rcx], rax
        mov     rax, [rdx + 8]
        adc     [rcx + 8], rax
        setc    al
        movzx   rax, al
        ret
end if