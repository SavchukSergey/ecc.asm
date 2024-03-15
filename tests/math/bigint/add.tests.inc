include '../src/math/bigint/add/add.inc'
include '../src/math/bigint/zero/zero.inc'
include '../../assert.inc'

__bi_add_128_128_test:
virtual at rsp
  .result rb __BIG_INTEGER_BYTES_128
end virtual
        sub     rsp, 1 * __BIG_INTEGER_BYTES_128

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_add_128_128

        call    test_context_end_measure

        lea     rcx, [.expected]
        lea     rdx, [.result]
        call    bi_assert_equal_128

        jmp     .pass

.fail:
        add     rsp, 1 * __BIG_INTEGER_BYTES_128
        stc
        ret
.pass:
        add     rsp, 1 * __BIG_INTEGER_BYTES_128
        clc
        ret
.left dq 0x0123456789abcdef, 0xfedcba9876543210
.right dq 0x3333333333333333, 0x4444444444444444
.expected dq 0x3456789ABCDF0122, 0x4320FEDCBA987654

__bi_add_256_256_test:
virtual at rsp
  .result rb __BIG_INTEGER_BYTES_256
end virtual
        sub     rsp, 1 * __BIG_INTEGER_BYTES_256

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_add_256_256

        call    test_context_end_measure

        lea     rcx, [.expected]
        lea     rdx, [.result]
        call    bi_assert_equal_256

        jmp     .pass

.fail:
        add     rsp, 1 * __BIG_INTEGER_BYTES_256
        stc
        ret
.pass:
        add     rsp, 1 * __BIG_INTEGER_BYTES_256
        clc
        ret
.left dq 0x0123456789abcdef, 0xfedcba9876543210, 0xfedcba9876543210, 0x0123456789abcdef
.right dq 0x3333333333333333, 0x4444444444444444, 0x4444444444444444, 0x3333333333333333
.expected dq 0x3456789ABCDF0122, 0x4320FEDCBA987654, 0x4320FEDCBA987655, 0x3456789ABCDF0123