include '../src/math/bigint/mul/bi_mul_512_512.inc'

__bi_mul_512_512_test_core:
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
        push    rbx
        lea     rbx, [__bi_mul_512_512_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 256]
        call    __bi_mul_512_512_test_core

        add     rbx, 128 + 128 + 256
        cmp     rbx, __bi_mul_512_512_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_512_512_test_cases:
  db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db 'e43220d5e39ee79e8098c2cf65094404f6aad8d12f8bbff8b4ca17b77183acf90bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
  db 'a60760ed29d467dff75670e661f7c75b9fa1e44a3663ec336a8d29971cb9a4413e79b5d4c44dcaca37c1783c66190709c929c3e9e99c102eefdd96d808a36e5748fd7b8e374d65ae3d3c44300792dfe36742e721d6b31674b2a1e1ac43730930e026ede67db201b686430abbd19e122562fa64a62034aa671e02e409d09bc6c0'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'

.end:
