include '../src/math/bigint/mod_add/bi_mod_tripple_assign_256.inc'
include '../../../assert.inc'

__bi_mod_tripple_assign_256_test_core:
virtual at rsp
.locals_start:
  .value_hex rq 1
  .modulus_hex rq 1
  .expected_hex rq 1
  BigInteger256 .value
  BigInteger256 .modulus
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start
	PrologCheckStackAligned '__bi_mod_tripple_assign_256_test_core'
	CheckRegAligned rcx, '__bi_mod_tripple_assign_256_test_core rcx'
	CheckRegAligned rdx, '__bi_mod_tripple_assign_256_test_core rdx'
	CheckRegAligned r8, '__bi_mod_tripple_assign_256_test_core r8'

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
    call      bi_mod_tripple_assign_256

    mov       rcx, [.expected_hex]
    lea       rdx, [.value]
    call      bi_assert_equal_hex_256

    call      test_context_start_measure
.chunk_loop:
	  lea       rcx, [.value]
    lea       rdx, [.modulus]
    call      bi_mod_tripple_assign_256
    call      test_context_measure_dec_chunk
    jnz       .chunk_loop
    call      test_context_end_measure

    add       rsp, .locals_end - .locals_start
	ret

__bi_mod_tripple_assign_256_test:
	sub		 rsp, 8
	mov		 rbx, __bi_mod_tripple_assign_256_test_cases
.loop:
	lea		 rcx, [rbx + 0]
	lea		 rdx, [.modulus_hex]
	lea		 r8, [rbx + 64]
	call	 __bi_mod_tripple_assign_256_test_core

	add      rbx, 64 + 64
	cmp		 rbx, __bi_mod_tripple_assign_256_test_cases.end
	jb		.loop

	add		rsp, 8

	ret

align 16
.modulus_hex	db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

align 16
__bi_mod_tripple_assign_256_test_cases:
  db '00000000000000000000000000000000000000000000000042ee2737466d172a'
  db '000000000000000000000000000000000000000000000000c8ca75a5d347457e'

  db '2f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '8d9c04f7c68d8e229cb26314e8e56b1316da53107dbbd26520e5c355fbcf6f0a'

  db '4f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db 'ed9c04f7c68d8e229cb26314e8e56b1316da53107dbbd26520e5c355fbcf6f0a'

  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '4d9c04f7c68d8e229cb26314e8e56b1316da53107dbbd26520e5c356fbcf72db'

  db '8f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db 'ad9c04f7c68d8e229cb26314e8e56b1316da53107dbbd26520e5c356fbcf72db'

  db 'bf3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '3d9c04f7c68d8e229cb26314e8e56b1316da53107dbbd26520e5c357fbcf76ac'

.end: