macro BigIntegerExtendLowTests bits, dbits {

include '../src/math/bigint/extend_low/extend_low_1.inc'

BigIntegerExtendLow1 bits

__bi_extend_low_test_#bits:
virtual at rsp
  .src rb __BIG_INTEGER_BYTES_#bits
  .result rb __BIG_INTEGER_BYTES_#bits
end virtual
        sub     rsp, 2 * __BIG_INTEGER_BYTES_#bits

        mov     rcx, __BIG_INTEGER_BYTES_#bits
.fill_loop:
        mov     byte [.src + rcx - 1], 1
        loop    .fill_loop

        lea     rax, [.src]
        lea     rdi, [.result]
        call    test_context_start_measure
        call    __bi_extend_low_#bits
        call    test_context_end_measure

        mov     rcx, __BIG_INTEGER_BYTES_#bits / 2
.high_loop:
        cmp     byte [.result + rcx - 1 + __BIG_INTEGER_BYTES_#bits / 2], 0
        jne     .failed
        loop    .high_loop

        mov     rcx, __BIG_INTEGER_BYTES_#bits / 2
.low_loop:
        mov     al, [.result + rcx - 1]
        cmp     al, [.src + rcx - 1]
        jne     .failed
        loop    .low_loop
.passed:
        add     rsp, 2 * __BIG_INTEGER_BYTES_#bits
        clc
        ret

.failed:
        add     rsp, 2 * __BIG_INTEGER_BYTES_#bits
        stc
        ret

}

