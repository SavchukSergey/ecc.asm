if ~ definite bi_sub_assign_512_512

;Subtracts two bi512 values
;input:
;  rcx - left value. The modified value.
;  rdx - right value
; output:
;  rax, CF - set to 1 if overflow
bi_sub_assign_512_512:
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
        mov     rax, [rdx + 40]
        sbb     [rcx + 40], rax
        mov     rax, [rdx + 48]
        sbb     [rcx + 48], rax
        mov     rax, [rdx + 56]
        sbb     [rcx + 56], rax
        setc    al
        movzx   rax, al
        ret
end if