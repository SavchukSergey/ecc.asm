macro BigIntegerBitClear bits {

if ~ definite __bi_bit_clear_#bits

__bi_bit_clear_#bits:
        btr     qword [rax], rbx
        ret

end if

}