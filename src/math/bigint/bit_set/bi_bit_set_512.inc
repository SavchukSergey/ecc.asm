;Sets a bit in bi512 value
;input:
;  rcx - pointer to bi512 value to change
;  rdx - bit
bi_bit_set_512:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        bts     qword [rcx + 8 * rax], rdx
        ret
