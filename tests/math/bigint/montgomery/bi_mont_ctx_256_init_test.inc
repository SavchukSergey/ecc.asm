include '../src/math/bigint/montgomery/bi_mont_ctx_256_init.inc'
include '../src/math/bigint/montgomery/bi_mont_ctx_256_convert.inc'
include '../../../assert.inc'

__bi_mont_ctx_256_init_test:
virtual at rsp
.locals_start:
  .context MontgomeryContext256
  BigInteger256 .modulus
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start

	lea     rcx, [.modulus_hex]
	lea     rdx, [.modulus]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea		rcx, [.modulus]
	lea		rdx, [.context]
	call	bi_mont_ctx_256_init
	
	call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	lea     rcx, [.modulus]
	lea		rdx, [.context + MontgomeryContext256.modulus]
	call	bi_assert_equal_256

	lea     rcx, [.r_hex]
	lea		rdx, [.context + MontgomeryContext256.r]
	call	bi_assert_equal_hex_512

	lea     rcx, [.rm_hex]
	lea		rdx, [.context + MontgomeryContext256.rm]
	call	bi_assert_equal_hex_256

    add     rsp, .locals_end - .locals_start
	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.r_hex          db '00000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000'
.rm_hex         db '00000000000000000000000000000000000000000000000000000001000003d1'
