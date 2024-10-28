include '../../../../src/math/bigint/mod_div/bi_mod_div_256_256.inc'
include '../../../assert.inc'

__bi_mod_div_256_256_test_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  .dividend BigInteger256
  .divisor BigInteger256
  .modulus BigInteger256
  .result BigInteger256
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
	push	rbx
	mov		rbx, __bi_mod_div_256_256_test_cases
.loop:
	lea     rcx, [rbx + 0]
	lea     rdx, [rbx + 64]
	lea     r8, [.modulus_hex]
	lea     r9, [rbx + 128]
	call	__bi_mod_div_256_256_test_core

	add		rbx, 64 + 64 + 64
	cmp		rbx, __bi_mod_div_256_256_test_cases.end
	jb		.loop

    pop		rbx

	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

__bi_mod_div_256_256_test_cases:
  db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '0006e3be8abd2e089ed812475be9b51c3cfcc1a04fafa2ddb6ca6869bf272715'
  db '182ff5254d4522b55f0ead2ebef2217bdd846824f3457dfdbbfc196ecc37453e'

  db '69da3443f1d1f170cb9eec2f97fd323c7b2fd98455225e738723897d391e56cb'
  db '316d08d62529326ff748d839a989bda40874d3dc39943f2becaa389b8c3667ab'
  db '0a802087683218fc2a0ecb6fc9f1cb9399ebef167ced2551ca71a2a5635944ab'

.end: