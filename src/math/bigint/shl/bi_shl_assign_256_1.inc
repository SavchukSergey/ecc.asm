if ~ definite bi_shl_assign_256_1

; Shifts left bi256 by 1 bit
;input
; rcx - value
;output:
;  CF - 1 if overflow
;  rax - 1 if overflow
bi_shl_assign_256_1:
        shl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        rcl     qword [rcx + 16], 1
        rcl     qword [rcx + 24], 1
        setc    al
        movzx   rax, al
        ret

end if