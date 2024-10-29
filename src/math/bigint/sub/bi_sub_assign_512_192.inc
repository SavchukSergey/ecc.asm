if ~ definite bi_sub_assign_512_192

;Subtracts bi192 from bi512 values
;input:
;  rcx - left bi512 value. The modified value.
;  rdx - right bi192 value
; output:
;  rax, CF - set to 1 if overflow
bi_sub_assign_512_192:
        mov     rax, [rdx]
        sub     [rcx], rax
        mov     rax, [rdx + 8]
        sbb     [rcx + 8], rax
        mov     rax, [rdx + 16]
        sbb     [rcx + 16], rax
        sbb     qword [rcx + 24], 0
        sbb     qword [rcx + 32], 0
        sbb     qword [rcx + 40], 0
        sbb     qword [rcx + 48], 0
        sbb     qword [rcx + 56], 0
        setc    al
        movzx   rax, al
        ret
end if