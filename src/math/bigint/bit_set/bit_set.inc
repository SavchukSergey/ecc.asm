macro BigIntegerBitSet bits {

if ~ definite __bi_bit_set_#bits

__bi_bit_set_#bits:
        bts     qword [rax], rbx
        ret

end if

}