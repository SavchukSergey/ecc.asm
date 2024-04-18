include '../src/math/bigint/mod_mul/bi_mod_mul_256_256.inc'
include '../../../assert.inc'

__bi_mod_mul_256_256_test_core:
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
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mod_mul_256_256_test_core'
    CheckRegAligned rcx, '__bi_mod_mul_256_256_test_core rcx'
    CheckRegAligned rdx, '__bi_mod_mul_256_256_test_core rdx'
    CheckRegAligned r8, '__bi_mod_mul_256_256_test_core r8'
    CheckRegAligned r9, '__bi_mod_mul_256_256_test_core r9'

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
	
    add     rsp, .locals_end - .locals_start
	ret

__bi_mod_mul_256_256_test:
    sub		rsp, 8
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

    add		rsp, 8

	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.left_hex	    db '0000000000000000000000000000000023e0715c2534cec45e6ac5894b97fccd'
.right_hex	    db '000000000000000000000000000000006dce92970406d93ad874a75e73460deb'
.expected_hex	db '0F63836A9E974E93A64D9962DE4654E2DC6ED62958AC31543527CE445369792F'

.left_overflow_hex	    db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.right_overflow_hex	    db '223d2bb3ad4647eb58fe9bbec7364ecaf8b3a977d6372d39805b3fc21efd0ffb'
.expected_overflow_hex	db '42600ED6A43A52E08809F817874C39B92F1C80789177C8E985C82A4A2677EE57'
