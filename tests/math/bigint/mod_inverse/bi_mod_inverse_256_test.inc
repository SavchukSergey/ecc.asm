include '../src/math/bigint/mod_inverse/bi_mod_inverse_256.inc'
include '../../../assert.inc'

__bi_mod_inverse_256_test:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_256
  .modulus rb __BIG_INTEGER_BYTES_256
  .result rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
	enter	.locals_end - .locals_start, 0
	lea	    rcx, [.value_hex]
	lea	    rdx, [.value]
	call    bi_try_read_hex_256

	lea	    rcx, [.modulus_hex]
	lea	    rdx, [.modulus]
	call    bi_try_read_hex_256

	call    test_context_start_measure
.chunk_loop:
	lea	    rcx, [.value]
	lea	    rdx, [.modulus]
	lea	    r8, [.result]
	call    bi_mod_inverse_256
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call    test_context_end_measure

	lea	    rcx, [.expected_hex]
	lea	    rdx, [.result]
	call    bi_assert_equal_hex_256

	leave
	ret

.value_hex	db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'
.expected_hex	db '6a6c59bdd7a25d5fcd3b69d7f8b183194451df6a625bbecf68e7d86e194c21ac'
