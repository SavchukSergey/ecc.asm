bi_bit_set_256:
        mov     rax, rdx
        shr     rax, 6
        and     rdx, 0x3f
        bts     qword [rcx + 8 * rax], rdx
        ret

macro BigIntegerBitSet bits {

if ~ definite __bi_bit_set_#bits

__bi_bit_set_#bits:
        bts     qword [rax], rbx
        ret

end if

}