macro BigIntegerRndTests bits {

__bi_rnd_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits
        mov     rax, rsp
        call    __bi_zero_#bits
        call    __bi_rnd_#bits

        mov     rcx, __BIG_INTEGER_QWORDS_#bits
.loop:
        cmp     qword [rax], 0
        jne     .pass
        loop    .loop
.fail:
        add     rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret
.pass:
        add     rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret

}