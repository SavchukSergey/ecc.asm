macro BigIntegerBitSet bits {

if ~ definite __bi_bit_set_#bits

__bi_bit_set_#bits:
        push    rcx
        mov     rcx, rbx
        shr     rcx, 8
        bts     [rax + rcx], rbx
        pop     rcx
        ret

end if

}