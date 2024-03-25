include '../src/math/bigint/mul/bi_mul_256_256.inc'

__bi_mul_256_256_test_core:
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
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_mul_256_256
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret


__bi_mul_256_256_test:
        lea     rbx, [__bi_mul_256_256_test_cases]

.loop:
        push    rbx

        lea     rcx, [rbx]
        lea     rdx, [rbx + 64]
        lea     r8, [rbx + 128]
        call    __bi_mul_256_256_test_core

        pop     rbx
        add     rbx, 64 + 64 + 128
        cmp     rbx, __bi_mul_256_256_test_cases.end
        jb      .loop

        ret

__bi_mul_256_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  db '1D12DBCFC432E89183D10D1EAE34260870F397B818DF8118FC9B9A7A85E7322B04E694CB437F2D9CC15785B06F34EC8FD5A04C896866EB433352AFC9E5F4756A'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0000000000000000000000000000000000000000000000000000000000000001'

.end:
