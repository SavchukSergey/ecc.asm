;Clears a bit in bi256 value
;input:
;  rcx - pointer to bi256 value to change
;  rdx - bit
bi_bit_clear_256:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        btc     qword [rcx + 8 * rax], rdx
        ret
