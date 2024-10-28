if ~ definite __bi_mont_ctx_256_pow_test

include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_init.inc'
include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_pow.inc'
include '../../../assert.inc'

__bi_mont_ctx_256_pow_test_core:
virtual at rsp
.locals_start:
  .value_hex rq 1
  .exponent_hex rq 1
  .context rq 1
  .expected_hex rq 1
  
  .exponent BigInteger256
  
  .value_mont BigInteger256
  .value_real BigInteger256

  .result_mont BigInteger256
  .result_real BigInteger256

  .pow_real BigInteger256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mont_ctx_256_pow_test_core'
    CheckRegAligned rcx, '__bi_mont_ctx_256_pow_test_core rcx'
    CheckRegAligned rdx, '__bi_mont_ctx_256_pow_test_core rdx'
    CheckRegAligned r8, '__bi_mont_ctx_256_pow_test_core r8'
    CheckRegAligned r9, '__bi_mont_ctx_256_pow_test_core r9'

	mov     [.value_hex], rcx
	mov     [.exponent_hex], rdx
	mov     [.context], r8
	mov     [.expected_hex], r9

	mov     rcx, [.value_hex]
	lea     rdx, [.value_mont]
	call	bi_try_read_hex_256

	mov     rcx, [.exponent_hex]
	lea     rdx, [.exponent]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.value_mont]
	lea     rdx, [.exponent]
	mov     r8, [.context]
	lea     r9, [.result_mont]
	call    bi_mont_ctx_256_pow
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result_mont]
	call	bi_assert_equal_hex_256

;recheck
	lea		rcx, [.value_mont]
	lea		rdx, [.value_real]
	mov		r8, [.context]
	call	bi_mont_ctx_256_redc_256

	lea		rcx, [.result_mont]
	lea		rdx, [.result_real]
	mov		r8, [.context]
	call	bi_mont_ctx_256_redc_256

	lea     rcx, [.value_real]
	lea     rdx, [.exponent]
	mov     r8, [.context]
	lea     r8, [r8 + MontgomeryContext256.modulus]
	lea     r9, [.pow_real]
	call    bi_mod_pow_256

	lea		rcx, [.pow_real]
	lea		rdx, [.result_real]
	call	bi_assert_equal_256

    add     rsp, .locals_end - .locals_start
	ret

__bi_mont_ctx_256_pow_test:
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
	lea     rdx, [.exponent_0_hex]
	lea     r8, [.context]
	lea     r9, [.expected_0_hex]
	call	__bi_mont_ctx_256_pow_test_core

	lea     rcx, [.value_hex]
	lea     rdx, [.exponent_1_hex]
	lea     r8, [.context]
	lea     r9, [.expected_1_hex]
	call	__bi_mont_ctx_256_pow_test_core

	lea     rcx, [.value_hex]
	lea     rdx, [.exponent_2_hex]
	lea     r8, [.context]
	lea     r9, [.expected_2_hex]
	call	__bi_mont_ctx_256_pow_test_core

	lea     rcx, [.value_hex]
	lea     rdx, [.exponent_hex]
	lea     r8, [.context]
	lea     r9, [.expected_hex]
	call	__bi_mont_ctx_256_pow_test_core

    add     rsp, .locals_end - .locals_start
	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'
.value_hex	    db '145c63d5cd4a7d9081682b4779c63489e7459d6c3599113eb0d3634c9b7e5d1b'

.exponent_0_hex    db '0000000000000000000000000000000000000000000000000000000000000000'
.expected_0_hex    db '00000000000000000000000000000000000000000000000000000001000003D1' ; this is 1 in montgomery form (equals to rm)

.exponent_1_hex    db '0000000000000000000000000000000000000000000000000000000000000001'
.expected_1_hex    db '145c63d5cd4a7d9081682b4779c63489e7459d6c3599113eb0d3634c9b7e5d1b'

.exponent_2_hex    db '0000000000000000000000000000000000000000000000000000000000000002'
.expected_2_hex    db 'FA06E3B927A10AA9C448C6F1A36F66DDE5455690C05EC4C7ED0282C394612022' ; square

.exponent_hex      db '0006e3be8abd2e089ed812475be9b51c3cfcc1a04fafa2ddb6ca6869bf272715'
.expected_hex      db '3DDFA7EE20B58293C4C30C04073C06D8628E29CB5849FEE6C4811CFB86DD1312'

end if