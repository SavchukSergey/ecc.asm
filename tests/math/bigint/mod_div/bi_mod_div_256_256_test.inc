include '../src/math/bigint/mod_div/bi_mod_div_256_256.inc'
include '../../../assert.inc'

__bi_mod_div_256_256_test_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  BigInteger256 .dividend
  BigInteger256 .divisor
  BigInteger256 .modulus
  BigInteger256 .result
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mod_div_256_256_test_core'
    CheckRegAligned rcx, '__bi_mod_div_256_256_test_core rcx'
    CheckRegAligned rdx, '__bi_mod_div_256_256_test_core rdx'
    CheckRegAligned r8, '__bi_mod_div_256_256_test_core r8'
    CheckRegAligned r9, '__bi_mod_div_256_256_test_core r9'

	mov     [.dividend_hex], rcx
	mov     [.divisor_hex], rdx
	mov     [.modulus_hex], r8
	mov     [.expected_hex], r9

	mov     rcx, [.dividend_hex]
	lea     rdx, [.dividend]
	call	bi_try_read_hex_256

	mov     rcx, [.divisor_hex]
	lea     rdx, [.divisor]
	call    bi_try_read_hex_256

	mov     rcx, [.modulus_hex]
	lea     rdx, [.modulus]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.dividend]
	lea     rdx, [.divisor]
	lea     r8, [.modulus]
	lea     r9, [.result]
	call	bi_mod_div_256_256
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result]
	call	bi_assert_equal_hex_256
	
    add     rsp, .locals_end - .locals_start
	ret

__bi_mod_div_256_256_test:
    sub		rsp, 8
	lea     rcx, [.dividend_hex]
	lea     rdx, [.divisor_hex]
	lea     r8, [.modulus_hex]
	lea     r9, [.expected_hex]
	call	__bi_mod_div_256_256_test_core

    add		rsp, 8

	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.dividend_hex	db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.divisor_hex	db '0006e3be8abd2e089ed812475be9b51c3cfcc1a04fafa2ddb6ca6869bf272715'
.expected_hex	db '182ff5254d4522b55f0ead2ebef2217bdd846824f3457dfdbbfc196ecc37453e'
