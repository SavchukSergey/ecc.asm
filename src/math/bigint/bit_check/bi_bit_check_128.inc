;Checks bit in bi128 value
;input:
;  rcx - pointer of bi128 value to test
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
