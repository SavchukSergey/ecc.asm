if ~ definite bi_sub_assign_256_192

;Subtracts bi192 from bi256 values
;input:
;  rcx - left bi256 value. The modified value.
;  rdx - right bi192 value
; output:
;  rax, CF - set to 1 if overflow
bi_sub_assign_256_192:
        mov     rax, [rdx]
        sub     [rcx], rax
        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax
        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax
        sbb     qword [rcx + 24], 0
        setc    al
        movzx   rax, al
        ret
end if