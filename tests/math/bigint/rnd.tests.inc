macro BigIntegerRndTests bits {

include '../src/math/bigint/rnd/rnd.inc'

BigIntegerRnd bits

__bi_rnd_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits
        mov     rax, rsp
        call    __bi_zero_#bits
        call    test_context_start_measure
        call    __bi_rnd_#bits
        call    test_context_end_measure

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