macro BigIntegerBitClear bits {

if ~ definite __bi_bit_clear_#bits

__bi_bit_clear_#bits:
        push    rcx
        mov     rcx, rbx
        shr     rcx, 8
        btc     [rax + rcx], rbx
        pop     rcx
        ret

end if

}