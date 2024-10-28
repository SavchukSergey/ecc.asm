include '../../../../src/math/bigint/square/bi_square_256.inc'

__bi_square_256_test_core:
virtual at rsp
.locals_start:
  .value BigInteger256
  .result BigInteger512
  .value_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_square_256_test_core'
    CheckRegAligned rcx, '__bi_square_256_test_core rcx'
    CheckRegAligned rdx, '__bi_square_256_test_core rdx'
    CheckRegAligned r8, '__bi_square_256_test_core r8'

        mov     [.value_hex], rcx
        mov     [.expected_hex], rdx

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        lea     rdx, [.result]
        call    bi_square_256
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        add     rsp, .locals_end - .locals_start
        ret


__bi_square_256_test:
        sub     rsp, 8
        lea     rbx, [__bi_square_256_test_cases]
.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + 64]
        call    __bi_square_256_test_core

        add     rbx, 64 + 128
        cmp     rbx, __bi_square_256_test_cases.end
        jb      .loop

        add     rsp, 8
        ret

align 16
__bi_square_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '304e24004b9fe197290c69000ee7803b20246ec8ecf0defa3c2d2715c03453e94ce330e2a6a232c43bee4f41fdeeabcdc99c076ad6b2f179267fb5d4435eda44'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0000000000000000000000000000000000000000000000000000000000000001'

.end:
