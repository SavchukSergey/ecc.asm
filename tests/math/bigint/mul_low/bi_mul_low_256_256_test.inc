include '../src/math/bigint/mul_low/bi_mul_low_256_256.inc'

__bi_mul_low_256_256_test_core:
virtual at rsp
.locals_start:
  .left rb __BIG_INTEGER_BYTES_256
  .right rb __BIG_INTEGER_BYTES_256
  .result rb __BIG_INTEGER_BYTES_256
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_mul_low_256_256_test_core'
    CheckRegAligned rcx, '__bi_mul_low_256_256_test_core rcx'
    CheckRegAligned rdx, '__bi_mul_low_256_256_test_core rdx'
    CheckRegAligned r8, '__bi_mul_low_256_256_test_core r8'

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
        call    bi_mul_low_256_256
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        add     rsp, .locals_end - .locals_start
        ret

__bi_mul_low_256_256_test:
        push    rbx

        mov     rbx, __bi_mul_low_256_256_test_cases
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [rbx + 64]
        lea     r8, [rbx + 128]
        call    __bi_mul_low_256_256_test_core

        add     rbx, 64 + 64 + 64
        cmp     rbx, __bi_mul_low_256_256_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_low_256_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  db '04E694CB437F2D9CC15785B06F34EC8FD5A04C896866EB433352AFC9E5F4756A'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '0000000000000000000000000000000000000000000000000000000000000001'
.end: