if ~ definite bi_sub_assign_320_320

;Subtracts two bi320 values
;input:
;  rcx - left value. The modified value.
;  rdx - right value
; output:
;  rax, CF - set to 1 if overflow
bi_sub_assign_320_320:
        mov     rax, [rdx]
        sub     [rcx], rax
        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax
        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax
        mov     rax, [rdx + 24]
        sbb     [rcx + 24], rax
        mov     rax, [rdx + 32]
        sbb     [rcx + 32], rax
        setc    al
        movzx   rax, al
        ret
end if