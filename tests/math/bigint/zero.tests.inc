macro BigIntegerZeroTests bits {

include '../src/math/bigint/zero/zero.inc'

BigIntegerZero bits

__bi_zero_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits
        mov     rax, rsp
        mov     dword [rax], 0x01234567
        mov     dword [rax + __BIG_INTEGER_DWORDS_#bits - 4], 0x89abcdef
        call    __bi_zero_#bits

        mov     rcx, __BIG_INTEGER_QWORDS_#bits
.loop:
        cmp     qword [rax], 0
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