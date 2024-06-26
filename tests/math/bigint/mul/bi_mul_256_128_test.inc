include '../src/math/bigint/mul/bi_mul_256_128.inc'

__bi_mul_256_128_test_core:
virtual at rsp
.locals_start:
  BigInteger256 .left
  BigInteger256 .right
  BigInteger512 .result
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mul_256_128_test_core'
    CheckRegAligned rcx, '__bi_mul_256_128_test_core rcx'
    CheckRegAligned rdx, '__bi_mul_256_128_test_core rdx'
    CheckRegAligned r8, '__bi_mul_256_128_test_core r8'

        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_256

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_mul_256_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        add     rsp, .locals_end - .locals_start
        ret


__bi_mul_256_128_test:
        push    rbx
        lea     rbx, [__bi_mul_256_128_test_cases]

.loop:

        lea     rcx, [rbx]
        lea     rdx, [rbx + 64]
        lea     r8, [rbx + 128]
        call    __bi_mul_256_128_test_core

        add     rbx, 64 + 64 + 128
        cmp     rbx, __bi_mul_256_128_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_256_128_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '0000000000000000000000000000000042ee2737466d172a7dd3ec5c797b49a2'
  db '000000000000000000000000000000001d12dbcfc432e89183d10d1eae34260808539b663161e360464cfb5ff27c491397da3a52329343fcfc31c2fc86940a1c'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000000ffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000000fffffffffffffffffffffffffffffffeffffffffffffffffffffffffffffffff00000000000000000000000000000001'

.end:
