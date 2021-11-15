macro BigIntegerBitClear bits {

if ~ definite __bi_bit_clear_#bits

__bi_bit_clear_#bits:
        push    rbx rcx
        mov     rcx, rbx
        shr     rcx, 6
        and     rbx, 0x3f
        btr     qword [rax + 8 * rcx], rbx
        pop     rcx rbx
        ret

end if

}