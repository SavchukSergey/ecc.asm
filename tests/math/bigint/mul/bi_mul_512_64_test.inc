include '../src/math/bigint/mul/bi_mul_512_64.inc'

__bi_mul_512_64_test_core:
virtual at rsp
.locals_start:
  BigInteger512 .left
  BigInteger512 .right
  BigInteger1024 .result
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub      rsp, .locals_end - .locals_start

        PrologCheckStackAligned '__bi_mul_512_64_test_core'
        CheckRegAligned rcx, '__bi_mul_512_64_test_core rcx'
        CheckRegAligned rdx, '__bi_mul_512_64_test_core rdx'
        CheckRegAligned r8, '__bi_mul_512_64_test_core r8'

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
        mov     rdx, qword [.right]
        lea     r8, [.result]
        call    bi_mul_512_64
        call    test_context_measure_dec_chunk
	jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_1024

        add      rsp, .locals_end - .locals_start
        ret


__bi_mul_512_64_test:
        push    rbx
        lea     rbx, [__bi_mul_512_64_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 256]
        call    __bi_mul_512_64_test_core

        add     rbx, 128 + 128 + 256
        cmp     rbx, __bi_mul_512_64_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_512_64_test_cases:
  db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000042ee2737466d172a'
  db '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000030b25351f083e791a1ca7269d63a8402d2e279e66a737af4267b49103a3ab5dd6a9ed93e79e60f052883d91a68be2ed58c26a98ac1797b9260416b20926c15ec94155a70143a1c10'
  
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ffffffffffffffff'
  db '0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000fffffffffffffffeffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000000001'

.end:
