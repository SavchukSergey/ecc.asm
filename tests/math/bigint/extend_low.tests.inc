macro BigIntegerExtendLowTests bits {

include '../src/math/bigint/extend_low/extend_low_1.inc'

BigIntegerExtendLow1 bits

__bi_extend_low_test_#bits:
virtual at rsp
  .src rb __BIG_INTEGER_BYTES_#bits
  .result rb 2 * __BIG_INTEGER_BYTES_#bits
end virtual
        sub     rsp, 3 * __BIG_INTEGER_BYTES_#bits
        lea     rax, [.src]
        call    __bi_rnd_#bits

        lea     rax, [.src]
        lea     rdi, [.result]
        call    __bi_extend_low_#bits

        mov     rcx, __BIG_INTEGER_BYTES_#bits
.high_loop:
        cmp     byte [.result + rcx - 1 + __BIG_INTEGER_BYTES_#bits], 0
        jne     .failed
        loop    .high_loop

        mov     rcx, __BIG_INTEGER_BYTES_#bits
.low_loop:
        mov     al, [.result + rcx - 1]
        cmp     al, [.src + rcx - 1]
        jne     .failed
        loop    .low_loop
.passed:
        add     rsp, 3 * __BIG_INTEGER_BYTES_#bits
        clc
        ret

.failed:
        add     rsp, 3 * __BIG_INTEGER_BYTES_#bits
        stc
        ret

}

