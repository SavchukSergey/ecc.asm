if ~ definite bi_bit_clear_512

;Sets a bit in bi512 value
;input:
;  rcx - value to change
;  rdx - bit
bi_bit_clear_512:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        btc     qword [rcx + 8 * rax], rdx
        ret

end if
