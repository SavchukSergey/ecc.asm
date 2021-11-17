macro BigIntegerZeroTests bits {

include '../src/math/bigint/zero/zero.inc'

BigIntegerZero bits

__bi_zero_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits
        mov     rax, rsp
        mov     dword [rax], 0x01234567
        mov     dword [rax + __BIG_INTEGER_DWORDS_#bits - 4], 0x89abcdef
        call    test_context_start_measure
        call    __bi_zero_#bits
        call    test_context_end_measure

        mov     rcx, __BIG_INTEGER_QWORDS_#bits
.loop:
        cmp     qword [rax + 8 * rcx - 8], 0
        jne     .fail
        loop    .loop
.pass:
        add     rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret
.fail:
        add     rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret

}