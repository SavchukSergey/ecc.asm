if ~ definite bi_sub_assign_128_128

;Subtracts two bi128 values
;input:
;  rcx - left value. The modified value.
;  rdx - right value
; output:
;  rax, CF - set to 1 if overflow
bi_sub_assign_128_128:
        mov     rax, [rdx]
        sub     [rcx], rax
        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax
        setc    al
        movzx   rax, al
        ret
end if