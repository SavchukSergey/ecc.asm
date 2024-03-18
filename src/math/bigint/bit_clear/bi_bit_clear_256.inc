if ~ definite bi_bit_clear_256

;Sets a bit in bi256 value
;input:
;  rcx - value to change
;  rdx - bit
bi_bibi_bit_clear_256t_set_256:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        btc     qword [rcx + 8 * rax], rdx
        ret

end if
