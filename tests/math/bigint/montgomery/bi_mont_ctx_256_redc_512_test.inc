if ~ definite __bi_mont_ctx_256_redc_512_test

__bi_mont_ctx_256_redc_512_test_core:
virtual at rsp
.locals_start:
  .source_hex rq 1
  .expected_hex rq 1
  .ctx rq 1
  .source_512 BigInteger512
  .result BigInteger256
  .expected BigInteger256
  .rm_inv BigInteger256
  .naive_recheck BigInteger256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mont_ctx_256_redc_512_test_core'
    CheckRegAligned rcx, '__bi_mont_ctx_256_redc_512_test_core rcx'
    CheckRegAligned rdx, '__bi_mont_ctx_256_redc_512_test_core rdx'
    CheckRegAligned r8, '__bi_mont_ctx_256_redc_512_test_core r8'

	mov     [.source_hex], rcx
	mov     [.expected_hex], rdx
	mov     [.ctx], r8

	mov     rcx, [.source_hex]
	lea     rdx, [.source_512]
	call    bi_try_read_hex_512

	mov     rcx, [.expected_hex]
	lea     rdx, [.expected]
	call    bi_try_read_hex_256

	call	test_context_start_measure
.chunk_loop:
	lea     rcx, [.source_512]
	lea     rdx, [.result]
	mov     r8, [.ctx]
	call	bi_mont_ctx_256_redc_512
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.result]
	call	bi_assert_equal_hex_256

    add     rsp, .locals_end - .locals_start
	ret

__bi_mont_ctx_256_redc_512_test:
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

	lea     rcx, [.source_1_hex]
	lea     rdx, [.expected_1_hex]
	lea		r8, [.context]
	call	__bi_mont_ctx_256_redc_512_test_core

    add     rsp, .locals_end - .locals_start
	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.source_1_hex	db '070e8ec4d1e089f01e6ec9963bdbb70f04e9d0fbb2942a281be9ea4eb9f540eee346335f6a9a829c3d5db39ad21dfb6816f18830c16a03cdf77821220eb1aa1b'
.expected_1_hex db 'F4D2F4094AA042FEB5580B848904CC355D3E150CAFEDED81F9C164242050FE4A'

end if