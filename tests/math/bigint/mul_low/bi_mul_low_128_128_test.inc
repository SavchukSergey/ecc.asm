include '../src/math/bigint/mul_low/bi_mul_low_128_128.inc'

__bi_mul_low_128_128_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_128
  .right rb __BIG_INTEGER_BYTES_128
  .result rb __BIG_INTEGER_BYTES_128
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_128

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_128

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_mul_low_128_128
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_128

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret

__bi_mul_low_128_128_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_low_128_128_test_core
        ret
.left_hex       db '23e0715c2534cec45e6ac5894b97fccd'
.right_hex      db '6dce92970406d93ad874a75e73460deb'
.expected_hex   db 'DC6ED62958AC31543527CE445369792F'


__bi_mul_low_128_128_max_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_low_128_128_test_core
        ret
.left_hex       db 'ffffffffffffffffffffffffffffffff'
.right_hex      db 'ffffffffffffffffffffffffffffffff'
.expected_hex   db '00000000000000000000000000000001'
