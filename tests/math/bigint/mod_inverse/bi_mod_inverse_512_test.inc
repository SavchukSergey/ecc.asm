include '../src/math/bigint/mod_inverse/bi_mod_inverse_512.inc'
include '../../../assert.inc'

__bi_mod_inverse_512_test:
virtual at rsp
.locals_start:
  BigInteger512 .value
  BigInteger512 .modulus
  BigInteger512 .result
  .rbx_backup rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
	sub		rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mod_inverse_512_test'
	mov		[.rbx_backup], rbx

	lea	    rcx, [.modulus_hex]
	lea	    rdx, [.modulus]
	call    bi_try_read_hex_512

	mov		rbx, __bi_mod_inverse_512_test_cases
.loop:
	lea	    rcx, [rbx + 0]
	lea	    rdx, [.value]
	call    bi_try_read_hex_512

	lea	    rcx, [.value]
	lea	    rdx, [.modulus]
	lea	    r8, [.result]
	call    bi_mod_inverse_512

	lea	    rcx, [rbx + 128]
	lea	    rdx, [.result]
	call    bi_assert_equal_hex_512

	add		rbx, 128 + 128
	cmp		rbx, __bi_mod_inverse_512_test_cases.end
	jb		.loop

	lea	    rcx, [__bi_mod_inverse_512_test_cases + 0 * 128]
	lea	    rdx, [.value]
	call    bi_try_read_hex_512

	call    test_context_start_measure
.chunk_loop:
	lea	    rcx, [.value]
	lea	    rdx, [.modulus]
	lea	    r8, [.result]
	call    bi_mod_inverse_512
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
	call    test_context_end_measure

	mov		rbx, [.rbx_backup]
	add		rsp, .locals_end - .locals_start
	ret

align 16
.modulus_hex	db '0000000000000000000000000000000000000000000000000000000000000000fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'

;todo: better test cases
align 16
__bi_mod_inverse_512_test_cases:
  db '0000000000000000000000000000000000000000000000000000000000000000cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '00000000000000000000000000000000000000000000000000000000000000006a6c59bdd7a25d5fcd3b69d7f8b183194451df6a625bbecf68e7d86e194c21ac'

  db '0000000000000000000000000000000000000000000000000000000000000000316d08d62529326ff748d839a989bda40874d3dc39943f2becaa389b8c3667ab'
  db '000000000000000000000000000000000000000000000000000000000000000046a7b5a87a0510d5e5a2da79d310cd5ac896519f88fc6495d5b6df43e9717d6b'

.end:
