macro BigIntegerBitCheck bits {

if ~ definite __bi_bit_check_#bits

__bi_bit_check_#bits:
        bt      qword [rax], rbx
        setc    al
        movzx   rax, al
        ret

end if

}