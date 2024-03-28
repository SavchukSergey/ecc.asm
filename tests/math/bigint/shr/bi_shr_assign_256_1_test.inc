include '../src/math/bigint/shr/bi_shr_assign_256_1.inc'

__bi_shr_assign_256_1_test:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
	enter	.locals_end - .locals_start, 0

	lea     rcx, [.value_hex]
	lea     rdx, [.value]
	call	bi_try_read_hex_256

	lea     rcx, [.value]
	call	bi_shr_assign_256_1

	lea     rcx, [.expected_hex]
	lea     rdx, [.value]
	call	bi_assert_equal_hex_256

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.value]
    call    bi_shr_assign_256_1
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

	leave
	ret

.value_hex	 db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
.expected_hex	db '0462D1E53ACC2BB6A83A5A9AF7F88A3FC8816296AB1989860A29E04792D6A0E8'
