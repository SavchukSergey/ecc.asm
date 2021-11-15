macro BigIntegerBitCheck bits {

if ~ definite __bi_bit_check_#bits

__bi_bit_check_#bits:
        push    rbx rcx
        mov     rcx, rbx
        shr     rcx, 6
        and     rbx, 0x3f
        bt      qword [rax + 8 * rcx], rbx
        setc    al
        movzx   rax, al
        pop     rcx rbx
        ret

end if

}