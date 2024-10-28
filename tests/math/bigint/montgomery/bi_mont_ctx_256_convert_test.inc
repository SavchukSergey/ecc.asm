include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_init.inc'
include '../../../../src/math/bigint/montgomery/bi_mont_ctx_256_convert.inc'
include '../../../assert.inc'

__bi_mont_ctx_256_convert_test_core:
virtual at rsp
.locals_start:
  .source_hex rq 1
  .expected_hex rq 1
  .ctx rq 1
  .source BigInteger256
  .result BigInteger256
  .expected BigInteger256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mont_ctx_256_convert_test_core'
    CheckRegAligned rcx, '__bi_mont_ctx_256_convert_test_core rcx'
    CheckRegAligned rdx, '__bi_mont_ctx_256_convert_test_core rdx'
    CheckRegAligned r8, '__bi_mont_ctx_256_convert_test_core r8'

	mov     [.source_hex], rcx
	mov     [.expected_hex], rdx
	mov     [.ctx], r8

	mov     rcx, [.source_hex]
	lea     rdx, [.source]
	call    bi_try_read_hex_256

	mov     rcx, [.expected_hex]
	lea     rdx, [.expected]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.source]
	lea     rdx, [.result]
	mov     r8, [.ctx]
	call	bi_mont_ctx_256_convert
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result]
	call	bi_assert_equal_hex_256
	
    add     rsp, .locals_end - .locals_start
	ret

__bi_mont_ctx_256_convert_test:
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

	lea     rcx, [.source_small_hex]
	lea     rdx, [.expected_small_hex]
	lea		r8, [.context]
	call	__bi_mont_ctx_256_convert_test_core

	lea     rcx, [.source_big_hex]
	lea     rdx, [.expected_big_hex]
	lea		r8, [.context]
	call	__bi_mont_ctx_256_convert_test_core

    add     rsp, .locals_end - .locals_start
	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.source_small_hex   db '0000000000000000000000000000000023e0715c2534cec45e6ac5894b97fccd'
.expected_small_hex db '00000000000000000000000023e071e510c56f6e5cf3e0f5a113ddc67f0bca5d'

.source_big_hex	    db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.expected_big_hex   db '145c63d5cd4a7d9081682b4779c63489e7459d6c3599113eb0d3634c9b7e5d1b'
