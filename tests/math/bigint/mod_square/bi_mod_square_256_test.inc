include '../../../../src/math/bigint/mod_square/bi_mod_square_256.inc'
include '../../../assert.inc'

__bi_mod_square_256_test_core:
virtual at rsp
.locals_start:
  .value BigInteger256
  .modulus BigInteger256
  .result BigInteger256
  .value_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mod_square_256_test_core'
    CheckRegAligned rcx, '__bi_mod_square_256_test_core rcx'
    CheckRegAligned rdx, '__bi_mod_square_256_test_core rdx'
    CheckRegAligned r8, '__bi_mod_square_256_test_core r8'

	mov     [.value_hex], rcx
	mov     [.modulus_hex], rdx
	mov     [.expected_hex], r8

	mov     rcx, [.value_hex]
	lea     rdx, [.value]
	call	bi_try_read_hex_256

	mov     rcx, [.modulus_hex]
	lea     rdx, [.modulus]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.value]
	lea     rdx, [.modulus]
	lea     r8, [.result]
	call	bi_mod_square_256
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result]
	call	bi_assert_equal_hex_256
	
    add     rsp, .locals_end - .locals_start
	ret

__bi_mod_square_256_test:
    sub		rsp, 8
	lea     rcx, [.value_hex]
	lea     rdx, [.modulus_hex]
	lea     r8, [.expected_hex]
	call	__bi_mod_square_256_test_core

	lea     rcx, [.value_overflow_hex]
	lea     rdx, [.modulus_hex]
	lea     r8, [.expected_overflow_hex]
	call	__bi_mod_square_256_test_core

    add		rsp, 8

	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.value_hex	        db '0000000000000000000000000000000023e0715c2534cec45e6ac5894b97fccd'
.expected_hex	    db '050723C5C5A006F6EB5CB404C422DF93730557A7527FD565CFD67DC6517A3C29'

.value_overflow_hex	    db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.expected_overflow_hex	db 'f68d6baa084effcf7222c3f72d9ae49c974ced4078afe384291b7966149ac12c'
