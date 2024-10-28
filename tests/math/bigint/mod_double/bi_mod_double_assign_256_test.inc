include '../../../../src/math/bigint/mod_add/bi_mod_double_assign_256.inc'
include '../../../assert.inc'

__bi_mod_double_assign_256_test_core:
virtual at rsp
.locals_start:
  .value BigInteger256
  .modulus BigInteger256
  .value_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
	PrologCheckStackAligned '__bi_mod_double_assign_256_test_core'
	CheckRegAligned rcx, '__bi_mod_double_assign_256_test_core rcx'
	CheckRegAligned rdx, '__bi_mod_double_assign_256_test_core rdx'
	CheckRegAligned r8, '__bi_mod_double_assign_256_test_core r8'

	  mov       [.value_hex], rcx
	  mov       [.modulus_hex], rdx
	  mov       [.expected_hex], r8

	  mov       rcx, [.value_hex]
	  lea       rdx, [.value]
	  call      bi_try_read_hex_256

	  mov       rcx, [.modulus_hex]
	  lea       rdx, [.modulus]
	  call	    bi_try_read_hex_256

	  lea       rcx, [.value]
	  lea       rdx, [.modulus]
      call      bi_mod_double_assign_256

      mov       rcx, [.expected_hex]
      lea       rdx, [.value]
      call      bi_assert_equal_hex_256

      call      test_context_start_measure
.chunk_loop:
	  lea       rcx, [.value]
    lea       rdx, [.modulus]
    call      bi_mod_double_assign_256
    call      test_context_measure_dec_chunk
    jnz       .chunk_loop
    call      test_context_end_measure

    add       rsp, .locals_end - .locals_start
	ret

__bi_mod_double_assign_256_test:
	sub		 rsp, 8
	mov		 rbx, __bi_mod_double_assign_256_test_cases
.loop:
	lea		 rcx, [rbx + 0]
	lea		 rdx, [.modulus_hex]
	lea		 r8, [rbx + 64]
	call	 __bi_mod_double_assign_256_test_core

	add      rbx, 64 + 64
	cmp		 rbx, __bi_mod_double_assign_256_test_cases.end
	jb		.loop

	add		rsp, 8

	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

align 16
__bi_mod_double_assign_256_test_cases:
  db 'e2f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebb953ef9a4'
  db 'c5e68034fd9b3b4171321976345ee47620f3c376053d28c436b43d782a7df719'

  db 'c5e68034fd9b3b4171321976345ee47620f3c376053d28c436b43d782a7df719'
  db '8bcd0069fb367682e26432ec68bdc8ec41e786ec0a7a51886d687af154fbf203'

  db '8bcd0069fb367682e26432ec68bdc8ec41e786ec0a7a51886d687af154fbf203'
  db '179a00d3f66ced05c4c865d8d17b91d883cf0dd814f4a310dad0f5e3a9f7e7d7'

  db '179a00d3f66ced05c4c865d8d17b91d883cf0dd814f4a310dad0f5e3a9f7e7d7'
  db '2f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.end: