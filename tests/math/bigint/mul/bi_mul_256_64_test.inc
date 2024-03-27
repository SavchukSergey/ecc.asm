include '../src/math/bigint/mul/bi_mul_256_64.inc'

__bi_mul_256_64_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_256
  .right rb __BIG_INTEGER_BYTES_256
  .result rb __BIG_INTEGER_BYTES_512
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
        mov     rdx, qword [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_mul_256_64
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        leave
        ret


__bi_mul_256_64_test:
        lea     rbx, [__bi_mul_256_64_test_cases]

.loop:
        push    rbx

        lea     rcx, [rbx]
        lea     rdx, [rbx + 64]
        lea     r8, [rbx + 128]
        call    __bi_mul_256_64_test_core

        pop     rbx
        add     rbx, 64 + 64 + 128
        cmp     rbx, __bi_mul_256_64_test_cases.end
        jb      .loop

        ret

__bi_mul_256_64_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '00000000000000000000000000000000000000000000000042ee2737466d172a'
  db '0000000000000000000000000000000000000000000000001d12dbcfc432e8914d2899c63529058e5d54d3186cfb20cdd8dccf673140075dbe7f07855216b48c'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '000000000000000000000000000000000000000000000000ffffffffffffffff'
  db '000000000000000000000000000000000000000000000000fffffffffffffffeffffffffffffffffffffffffffffffffffffffffffffffff0000000000000001'

.end:
