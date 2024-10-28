if ~ definite __bi_mont_ctx_256_square_test

include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_init.inc'
include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_square.inc'
include '../../../assert.inc'

__bi_mont_ctx_256_square_test_core:
virtual at rsp
.locals_start:
  .value_hex rq 1
  .expected_hex rq 1
  .ctx rq 1
  .value_mont BigInteger256
  .expected_mont BigInteger256
  .result_mont BigInteger256

  .value_real BigInteger256
  .square_real BigInteger256
  .result_real BigInteger256

  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mont_ctx_256_square_test_core'
    CheckRegAligned rcx, '__bi_mont_ctx_256_square_test_core rcx'
    CheckRegAligned rdx, '__bi_mont_ctx_256_square_test_core rdx'
    CheckRegAligned r8, '__bi_mont_ctx_256_square_test_core r8'

	mov     [.value_hex], rcx
	mov     [.ctx], rdx
	mov     [.expected_hex], r8

	mov     rcx, [.value_hex]
	lea     rdx, [.value_mont]
	call    bi_try_read_hex_256

	mov     rcx, [.expected_hex]
	lea     rdx, [.expected_mont]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.value_mont]
	mov     rdx, [.ctx]
	lea     r8, [.result_mont]
	call	bi_mont_ctx_256_square
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result_mont]
	call	bi_assert_equal_hex_256

	lea     rcx, [.value_mont]
	lea     rdx, [.value_real]
	mov     r8, [.ctx]
	call	bi_mont_ctx_256_redc_256

	lea     rcx, [.value_real]
	mov     rdx, [.ctx]
	lea     rdx, [rdx + MontgomeryContext256.modulus]
	lea     r8, [.square_real]
	call	bi_mod_square_256

	lea     rcx, [.result_mont]
	lea     rdx, [.result_real]
	mov     r8, [.ctx]
	call	bi_mont_ctx_256_redc_256

	lea     rcx, [.square_real]
	lea     rdx, [.result_real]
	call	bi_assert_equal_256
	
    add     rsp, .locals_end - .locals_start
	ret

__bi_mont_ctx_256_square_test:
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

	lea     rcx, [.value_hex]
	lea		rdx, [.context]
	lea     r8, [.result_hex]
	call	__bi_mont_ctx_256_square_test_core

    add     rsp, .locals_end - .locals_start
	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.value_hex            db '145c63d5cd4a7d9081682b4779c63489e7459d6c3599113eb0d3634c9b7e5d1b'
.result_hex	          db 'FA06E3B927A10AA9C448C6F1A36F66DDE5455690C05EC4C7ED0282C394612022'

end if