macro BigIntegerBitSet bits {

if ~ definite __bi_bit_set_#bits

__bi_bit_set_#bits:
        push    rbx rcx
        mov     rcx, rbx
        shr     rcx, 6
        and     rbx, 0x3f
        bts     qword [rax + 8 * rcx], rbx
        pop     rcx rbx
        ret

end if

}