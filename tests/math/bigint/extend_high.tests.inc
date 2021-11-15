macro BigIntegerExtendHighTests bits, dbits {

include '../src/math/bigint/extend_high/extend_high_1.inc'

BigIntegerExtendHigh1 bits

__bi_extend_high_test_#bits:
virtual at rsp
  .src rb __BIG_INTEGER_BYTES_#bits
  .result rb 2 * __BIG_INTEGER_BYTES_#bits
end virtual
        sub     rsp, 3 * __BIG_INTEGER_BYTES_#bits
        lea     rax, [.src]
        call    __bi_rnd_#bits

        lea     rax, [.src]
        lea     rdi, [.result]
        call    __bi_extend_high_#bits

        mov     rcx, __BIG_INTEGER_BYTES_#bits
.high_loop:
        mov     al, [.result + rcx - 1 +  __BIG_INTEGER_BYTES_#bits]
        cmp     al, [.src + rcx - 1]
        jne     .failed
        loop    .high_loop

        mov     rcx, __BIG_INTEGER_BYTES_#bits
.low_loop:
        cmp     byte [.result + rcx - 1], 0
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

