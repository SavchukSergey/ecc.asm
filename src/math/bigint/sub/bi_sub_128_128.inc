if ~ definite bi_sub_128_128

;Subtracts two bi128 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax, CF - set to 1 if overflow
bi_sub_128_128:
        mov     rax, [rcx]
        sub     rax, [rdx]
        mov     [r8], rax
        mov     rax, [rcx + 8]
        sbb     rax, [rdx + 8]
        mov     [r8 + 8], rax
        setc    al
        movzx   rax, al
        ret

end if