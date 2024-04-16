include '../src/math/bigint/mul/bi_mul_512_512.inc'

__bi_mul_512_512_test_core:
virtual at rsp
.locals_start:
  .left rb __BIG_INTEGER_BYTES_512
  .right rb __BIG_INTEGER_BYTES_512
  .result rb __BIG_INTEGER_BYTES_1024
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub      rsp, .locals_end - .locals_start

        PrologCheckStackAligned '__bi_mul_512_512_test_core'
        CheckRegAligned rcx, '__bi_mul_512_512_test_core rcx'
        CheckRegAligned rdx, '__bi_mul_512_512_test_core rdx'
        CheckRegAligned r8, '__bi_mul_512_512_test_core r8'

        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_512

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_512

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_mul_512_512
        call    test_context_measure_dec_chunk
	jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_1024

        add      rsp, .locals_end - .locals_start
        ret


__bi_mul_512_512_test:
        lea     rbx, [__bi_mul_512_512_test_cases]

.loop:
        push    rbx

        lea     rcx, [rbx]
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 256]
        call    __bi_mul_512_512_test_core

        pop     rbx
        add     rbx, 128 + 128 + 256
        cmp     rbx, __bi_mul_512_512_test_cases.end
        jb      .loop

        ret

align 16
__bi_mul_512_512_test_cases:
  db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db 'e43220d5e39ee79e8098c2cf65094404f6aad8d12f8bbff8b4ca17b77183acf90bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
  db 'A60760ED29D467DFF75670E661F7C75B9FA1E44A3663EC336A8D29971CB9A4413E79B5D4C44DCACA37C1783C66190709C929C3E9E99C102EEFDD96D808A36E5748FD7B8E374D65AE3D3C44300792DFE36742E721D6B31674B2A1E1AC43730930E026EDE67DB201B686430ABBD19E122562FA64A62034AA671E02E409D09BC6C0'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'

.end:
