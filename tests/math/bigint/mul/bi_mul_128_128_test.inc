include '../src/math/bigint/mul/bi_mul_128_128.inc'

__bi_mul_128_128_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_128
  .right rb __BIG_INTEGER_BYTES_128
  .result rb __BIG_INTEGER_BYTES_256
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

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_mul_128_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        leave
        ret


__bi_mul_128_128_test:
        lea     rbx, [__bi_mul_128_128_test_cases]

.loop:
        push    rbx

        lea     rcx, [rbx]
        lea     rdx, [rbx + 32]
        lea     r8, [rbx + 64]
        call    __bi_mul_128_128_test_core

        pop     rbx
        add     rbx, 32 + 32 + 64
        cmp     rbx, __bi_mul_128_128_test_cases.end
        jb      .loop

        ret

__bi_mul_128_128_test_cases:
  db '23e0715c2534cec45e6ac5894b97fccd'
  db '6dce92970406d93ad874a75e73460deb'
  db '0F63836A9E974E93A64D9962DE4654E2DC6ED62958AC31543527CE445369792F'

  db 'ffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffff'
  db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE00000000000000000000000000000001'

.end:
