if ~ definite bi_bit_set_256

;Sets a bit in bi256 value
;input:
;  rcx - value to change
;  rdx - bit
bi_bit_set_256:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        bts     qword [rcx + 8 * rax], rdx
        ret

end if

macro BigIntegerBitSet bits {

if ~ definite __bi_bit_set_#bits

__bi_bit_set_#bits:
        bts     qword [rax], rbx
        ret

end if

}