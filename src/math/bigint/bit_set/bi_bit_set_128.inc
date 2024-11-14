;Sets a bit in bi128 value
;input:
;  rcx - pointer to bi128 value to change
;  rdx - bit
bi_bit_set_128:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        bts     qword [rcx + 8 * rax], rdx
        ret
