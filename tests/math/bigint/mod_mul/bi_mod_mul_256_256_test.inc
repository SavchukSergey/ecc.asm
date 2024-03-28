include '../src/math/bigint/mod_mul/bi_mod_mul_256_256.inc'
include '../../../assert.inc'

__bi_mod_mul_256_256_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_256
  .right rb __BIG_INTEGER_BYTES_256
  .modulus rb __BIG_INTEGER_BYTES_256
  .result rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
	enter   .locals_end - .locals_start, 0
	mov     [.left_hex], rcx
	mov     [.right_hex], rdx
	mov     [.modulus_hex], r8
	mov     [.expected_hex], r9

	mov     rcx, [.left_hex]
	lea     rdx, [.left]
	call	bi_try_read_hex_256

	mov     rcx, [.right_hex]
	lea     rdx, [.right]
	call    bi_try_read_hex_256

	mov     rcx, [.modulus_hex]
	lea     rdx, [.modulus]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.left]
	lea     rdx, [.right]
	lea     r8, [.modulus]
	lea     r9, [.result]
	call	bi_mod_mul_256_256
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result]
	call	bi_assert_equal_hex_256
	
	leave
	ret

__bi_mod_mul_256_256_test:
	lea     rcx, [.left_hex]
	lea     rdx, [.right_hex]
	lea     r8, [.modulus_hex]
	lea     r9, [.expected_hex]
	call	__bi_mod_mul_256_256_test_core

	lea     rcx, [.left_overflow_hex]
	lea     rdx, [.right_overflow_hex]
	lea     r8, [.modulus_hex]
	lea     r9, [.expected_overflow_hex]
	call	__bi_mod_mul_256_256_test_core

	ret
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.left_hex	db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.right_hex	db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.expected_hex	db 'f68d6baa084effcf7222c3f72d9ae49c974ced4078afe384291b7966149ac12c'

.left_overflow_hex	db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.right_overflow_hex	db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.expected_overflow_hex	db 'f68d6baa084effcf7222c3f72d9ae49c974ced4078afe384291b7966149ac12c'
