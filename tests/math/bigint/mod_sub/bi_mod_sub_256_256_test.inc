include '../src/math/bigint/mod_sub/bi_mod_sub_256_256.inc'
include '../../../assert.inc'

__bi_mod_sub_256_256_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  BigInteger256 .left
  BigInteger256 .right
  BigInteger256 .modulus
  BigInteger256 .result
  AlignLocalsStackFrame
.locals_end:
end virtual
	sub		 rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mod_sub_256_256_test_core'

	mov      [.left_hex], rcx
	mov      [.right_hex], rdx
	mov      [.modulus_hex], r8
	mov      [.expected_hex], r9

	mov      rcx, [.left_hex]
	lea      rdx, [.left]
	call     bi_try_read_hex_256

	mov	     rcx, [.right_hex]
	lea	     rdx, [.right]
	call	 bi_try_read_hex_256

	mov	     rcx, [.modulus_hex]
	lea	     rdx, [.modulus]
	call	 bi_try_read_hex_256

	lea      rcx, [.left]
	lea      rdx, [.right]
	lea      r8, [.modulus]
	lea      r9, [.result]
	call     bi_mod_sub_256_256

    mov      rcx, [.expected_hex]
    lea      rdx, [.result]
    call     bi_assert_equal_hex_256

    call     test_context_start_measure
.chunk_loop:
	lea      rcx, [.left]
	lea      rdx, [.right]
    lea      r8, [.modulus]
	lea      r9, [.result]
    call     bi_mod_sub_256_256
    call     test_context_measure_dec_chunk
    jnz      .chunk_loop
    call     test_context_end_measure

	add		 rsp, .locals_end - .locals_start

	ret

__bi_mod_sub_256_256_test:
	sub		rsp, 8
    PrologCheckStackAligned '__bi_mod_sub_256_256_test'

	mov		rbx, __bi_mod_sub_256_256_test_cases
.loop:
	lea		rcx, [rbx + 0]
	lea		rdx, [rbx + 64]
	lea		r8, [.modulus_hex]
	lea		r9, [rbx + 128]
	call	__bi_mod_sub_256_256_test_core

	add		rbx, 64 + 64 + 64
	cmp		rbx, __bi_mod_sub_256_256_test_cases.end
	jb		.loop

	add		rsp, 8
	ret
align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'


align 16
__bi_mod_sub_256_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  db '2C45DA70A66CC2E10BBCDF55297BDA0E16C2E17F2FC304A06D6B608D9A3B5F5B'

  db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db 'D3BA258F59933D1EF44320AAD68425F1E93D1E80D03CFB5F92949F7165C49CD4'

.end: