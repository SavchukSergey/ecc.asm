if ~ definite bi_bit_check_128

;Sets a bit in bi128 value
;input:
;  rcx - value to change
;  rdx - bit
;output:
;  rax - 1 if bit is set
bi_bit_check_128:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        bt      qword [rcx + 8 * rax], rdx
        setc    al
        movzx   rax, al
        ret

end if
