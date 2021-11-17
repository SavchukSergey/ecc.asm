macro BigIntegerOneTests bits {

include '../src/math/bigint/one/one.inc'

BigIntegerOne bits

__bi_one_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits
        mov     rax, rsp
        mov     dword [rax], 0x01234567
        mov     dword [rax + __BIG_INTEGER_DWORDS_#bits - 4], 0x89abcdef
        call    test_context_start_measure
        call    __bi_one_#bits
        call    test_context_end_measure

        cmp     qword [rax], 0x01
        jne     .fail
        
        mov     rcx, __BIG_INTEGER_QWORDS_#bits - 1
.loop:
        cmp     qword [rax + 8 * rcx], 0
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