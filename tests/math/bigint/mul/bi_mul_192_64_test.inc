include '../../../../src/math/bigint/mul/bi_mul_192_64.inc'

__bi_mul_192_64_test_core:
virtual at rsp
.locals_start:
  .left BigInteger192
  .right BigInteger192
  .result BigInteger256
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mul_192_64_test_core'
    CheckRegAligned rcx, '__bi_mul_192_64_test_core rcx'
    CheckRegAligned rdx, '__bi_mul_192_64_test_core rdx'
    CheckRegAligned r8, '__bi_mul_192_64_test_core r8'

        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_192

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_192

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        mov     rdx, qword [.right]
        lea     r8, [.result]
        call    bi_mul_192_64
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        add     rsp, .locals_end - .locals_start
        ret


__bi_mul_192_64_test:
        push    rbx
        lea     rbx, [__bi_mul_192_64_test_cases]
.loop:

        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_192]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_192 * 2]
        call    __bi_mul_192_64_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_192 + __BIG_INTEGER_HEX_DIGITS_192 + __BIG_INTEGER_HEX_DIGITS_256
        cmp     rbx, __bi_mul_192_64_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_192_64_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621'
  db '0000000000000000000000000000000042ee2737466d172a'
  db '1d12dbcfc432e8914d2899c63529058e5d54d3186cfb20cda9601841b79f786a'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000000ffffffffffffffff'
  db 'fffffffffffffffeffffffffffffffffffffffffffffffff0000000000000001'

.end: