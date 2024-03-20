include '../src/math/bigint/mul_low/bi_mul_low_256_256.inc'

__bi_mul_low_256_256_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_256
  .right rb __BIG_INTEGER_BYTES_256
  .result rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_256

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_256

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_mul_low_256_256
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret

__bi_mul_low_256_256_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_low_256_256_test_core
        ret
.left_hex       db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.right_hex      db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
.expected_hex   db '04E694CB437F2D9CC15785B06F34EC8FD5A04C896866EB433352AFC9E5F4756A'

__bi_mul_low_256_256_max_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_low_256_256_test_core
        ret
.left_hex       db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.right_hex      db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.expected_hex   db '0000000000000000000000000000000000000000000000000000000000000001'
