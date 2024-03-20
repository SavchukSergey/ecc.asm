include '../src/math/bigint/mul_low/bi_mul_low_512_512.inc'

__bi_mul_low_512_512_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_512
  .right rb __BIG_INTEGER_BYTES_512
  .result rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
	enter	.locals_end - .locals_start, 0
	mov	[.left_hex], rcx
	mov	[.right_hex], rdx
	mov	[.expected_hex], r8

	mov	rcx, [.left_hex]
	lea	rdx, [.left]
	call	bi_try_read_hex_512

	mov	rcx, [.right_hex]
	lea	rdx, [.right]
	call	bi_try_read_hex_512

	lea	rcx, [.left]
	lea	rdx, [.right]
	lea	r8, [.result]
	call	test_context_start_measure
	call	bi_mul_low_512_512
	call	test_context_end_measure

	mov	rcx, [.expected_hex]
	lea	rdx, [.result]
	call	bi_assert_equal_hex_512

	jmp	.pass

.fail:
	leave
	stc
	ret
.pass:
	leave
	clc
	ret


__bi_mul_low_512_512_test:
	lea	rcx, [.left_hex]
	lea	rdx, [.right_hex]
	lea	r8, [.expected_hex]
	call	__bi_mul_low_512_512_test_core
	ret
.left_hex	db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
.right_hex	db 'e43220d5e39ee79e8098c2cf65094404f6aad8d12f8bbff8b4ca17b77183acf90bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
.expected_hex	db '48FD7B8E374D65AE3D3C44300792DFE36742E721D6B31674B2A1E1AC43730930E026EDE67DB201B686430ABBD19E122562FA64A62034AA671E02E409D09BC6C0'

__bi_mul_low_512_512_max_test:
	lea	rcx, [.left_hex]
	lea	rdx, [.right_hex]
	lea	r8, [.expected_hex]
	call	__bi_mul_low_512_512_test_core
	ret
.left_hex	db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.right_hex	db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.expected_hex	db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'