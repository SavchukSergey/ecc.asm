if ~ definite __bi_mont_ctx_256_mul_test

include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_init.inc'
include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_mul.inc'
include '../../../assert.inc'

__bi_mont_ctx_256_mul_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .ctx rq 1
  .left_mont BigInteger256
  .right_mont BigInteger256
  .expected_mont BigInteger256
  .result_mont BigInteger256

  .left_real BigInteger256
  .right_real BigInteger256
  .mul_real BigInteger256
  .result_real BigInteger256

  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mont_ctx_256_mul_test_core'
    CheckRegAligned rcx, '__bi_mont_ctx_256_mul_test_core rcx'
    CheckRegAligned rdx, '__bi_mont_ctx_256_mul_test_core rdx'
    CheckRegAligned r8, '__bi_mont_ctx_256_mul_test_core r8'
    CheckRegAligned r9, '__bi_mont_ctx_256_mul_test_core r9'

	mov     [.left_hex], rcx
	mov     [.right_hex], rdx
	mov     [.ctx], r8
	mov     [.expected_hex], r9

	mov     rcx, [.left_hex]
	lea     rdx, [.left_mont]
	call    bi_try_read_hex_256

	mov     rcx, [.right_hex]
	lea     rdx, [.right_mont]
	call    bi_try_read_hex_256

	mov     rcx, [.expected_hex]
	lea     rdx, [.expected_mont]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.left_mont]
	lea     rdx, [.right_mont]
	mov     r8, [.ctx]
	lea     r9, [.result_mont]
	call	bi_mont_ctx_256_mul
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result_mont]
	call	bi_assert_equal_hex_256

	lea     rcx, [.left_mont]
	lea     rdx, [.left_real]
	mov     r8, [.ctx]
	call	bi_mont_ctx_256_deconvert

	lea     rcx, [.right_mont]
	lea     rdx, [.right_real]
	mov     r8, [.ctx]
	call	bi_mont_ctx_256_deconvert

	lea     rcx, [.left_real]
	lea     rdx, [.right_real]
	mov     r8, [.ctx]
	lea     r8, [r8 + MontgomeryContext256.modulus]
	lea     r9, [.mul_real]
	call	bi_mod_mul_256_256

	lea     rcx, [.result_mont]
	lea     rdx, [.result_real]
	mov     r8, [.ctx]
	call	bi_mont_ctx_256_deconvert

	lea     rcx, [.mul_real]
	lea     rdx, [.result_real]
	call	bi_assert_equal_256
	
    add     rsp, .locals_end - .locals_start
	ret

__bi_mont_ctx_256_mul_test:
virtual at rsp
.locals_start:
  .context MontgomeryContext256
  .modulus BigInteger256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start

	lea     rcx, [.modulus_hex]
	lea     rdx, [.modulus]
	call    bi_try_read_hex_256

	lea		rcx, [.modulus]
	lea		rdx, [.context]
	call	bi_mont_ctx_256_init

	lea     rcx, [.left_hex]
	lea     rdx, [.right_hex]
	lea		r8, [.context]
	lea     r9, [.result_hex]
	call	__bi_mont_ctx_256_mul_test_core

    add     rsp, .locals_end - .locals_start
	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.left_hex             db '145c63d5cd4a7d9081682b4779c63489e7459d6c3599113eb0d3634c9b7e5d1b'
.right_hex	          db '58BA10A3A23714ED6AE6B1E13EF65E16FBE0EF9208EED8351D78908BEF3FB701'
.result_hex	          db 'EDC4654478BFB90E96E941EE4D29152658544410FD59C359DDD779D5665BBD5C'

end if