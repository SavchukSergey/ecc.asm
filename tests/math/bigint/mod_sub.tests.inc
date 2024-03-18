include '../src/math/bigint/mod_sub/bi_mod_sub_assign_256_256.inc'
include '../../assert.inc'

__bi_mod_sub_assign_256_256_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_256
  .right rb __BIG_INTEGER_BYTES_256
  .modulus rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
	enter	.locals_end - .locals_start, 0
	mov	    [.left_hex], rcx
	mov     [.right_hex], rdx
	mov     [.modulus_hex], r8
	mov     [.expected_hex], r9

	mov     rcx, [.left_hex]
	lea     rdx, [.left]
	call	bi_try_read_hex_256

	mov     rcx, [.right_hex]
	lea     rdx, [.right]
	call	bi_try_read_hex_256

	mov     rcx, [.modulus_hex]
	lea     rdx, [.modulus]
	call    bi_try_read_hex_256

	lea	    rcx, [.left]
	lea	    rdx, [.right]
	lea     r8, [.modulus]
	call	test_context_start_measure
	call	bi_mod_sub_assign_256_256
	call	test_context_end_measure

	mov     rcx, [.expected_hex]
	lea     rdx, [.left]
	call	bi_assert_equal_hex_256

	jmp     .pass

.fail:
	leave
	stc
	ret
.pass:
	leave
	clc
	ret

__bi_mod_sub_assign_256_256_test:
	lea     rcx, [.left_hex]
	lea     rdx, [.right_hex]
	lea     r8, [.modulus_hex]
	lea	    r9, [.expected_hex]
	call	__bi_mod_sub_assign_256_256_test_core

	lea     rcx, [.left_overflow_hex]
	lea     rdx, [.right_overflow_hex]
	lea	    r8, [.modulus_hex]
	lea     r9, [.expected_overflow_hex]
	call	__bi_mod_sub_assign_256_256_test_core

	ret
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

.left_hex	db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.right_hex	db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
.expected_hex	db '2C45DA70A66CC2E10BBCDF55297BDA0E16C2E17F2FC304A06D6B608D9A3B5F5B'

.left_overflow_hex	db 'af3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.right_overflow_hex	db 'b2ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
.expected_overflow_hex	db 'FC45DA70A66CC2E10BBCDF55297BDA0E16C2E17F2FC304A06D6B608C9A3B5B8A'
