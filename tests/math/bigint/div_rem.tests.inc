include '../src/math/bigint/div_rem/index.inc'

__bi_div_rem_256_256_test_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .dividend rb __BIG_INTEGER_BYTES_256
  .divisor rb __BIG_INTEGER_BYTES_256
  .quotient rb __BIG_INTEGER_BYTES_256
  .remainder rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
	enter	.locals_end - .locals_start, 0
	mov	[.dividend_hex], rcx
	mov	[.divisor_hex], rdx
	mov	[.expected_quotient_hex], r8
	mov	[.expected_remainder_hex], r9

	mov	rcx, [.dividend_hex]
	lea	rdx, [.dividend]
	call	bi_try_read_hex_256

	mov	rcx, [.divisor_hex]
	lea	rdx, [.divisor]
	call	bi_try_read_hex_256

	lea	rcx, [.dividend]
	lea	rdx, [.divisor]
	lea	r8, [.quotient]
	lea	r9, [.remainder]
	call	test_context_start_measure
	call	bi_div_rem_256_256
	call	test_context_end_measure

	mov	rcx, [.expected_quotient_hex]
	lea	rdx, [.quotient]
	call	bi_assert_equal_hex_256

	mov	rcx, [.expected_remainder_hex]
	lea	rdx, [.remainder]
	call	bi_assert_equal_hex_256

	jmp	.pass

.fail:
	leave
	stc
	ret
.pass:
	leave
	clc
	ret


__bi_div_rem_256_256_test:
	lea	rcx, [.dividend_hex]
	lea	rdx, [.divisor_hex]
	lea	r8, [.expected_quotient_hex]
	lea	r9, [.expected_remainder_hex]
	call	__bi_div_rem_256_256_test_core
	ret
.dividend_hex	    db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
.divisor_hex	    db '000000000000000006e3be8abd2e089ed812475be9b51c3cfcc1a04fafa2ddb6'
.expected_quotient_hex	 db '00000000000000000000000000000000000000000000001dd15d2c949aeda9ea'
.expected_remainder_hex  db '0000000000000000027d46af53ee1002fbb6e3e86950400123835264ed349189'


macro BigIntegerDivRemTests bits, dbits {

BigIntegerDivRem bits, dbits

__bi_div_rem_test_#bits:
virtual at rsp
.locals_start:
  .divident rb __BIG_INTEGER_BYTES_#bits
  .divisor rb __BIG_INTEGER_BYTES_#bits
  .actual_quotient rb __BIG_INTEGER_BYTES_#bits
  .actual_reminder rb __BIG_INTEGER_BYTES_#bits
.locals_end:
end virtual
	enter	.locals_end - .locals_start, 0

	mov	rsi, __bi_div_rem_test.divident_#bits
	lea	rdi, [.divident]
	call	__bi_read_hex_#bits

	mov	rsi, __bi_div_rem_test.divisor_#bits
	lea	rdi, [.divisor]
	call	__bi_read_hex_#bits

	lea	rax, [.divident]
	lea	rbx, [.divisor]
	lea	rdi, [.actual_quotient]
	lea	rsi, [.actual_reminder]
	call	test_context_start_measure
	call	__bi_div_rem_#bits
	call	test_context_end_measure

	lea	rcx, [.actual_quotient]
	mov	rdx, __bi_div_rem_test.quotient_#bits
	call	bi_assert_equal__#bits
	jc	.failed

	lea	rcx, [.actual_reminder]
	mov	rdx, __bi_div_rem_test.reminder_#bits
	call	bi_assert_equal__#bits
	jc	.failed

.passed:
	leave
	clc
	ret
.failed:
	leave
	stc
	ret
}


__bi_div_rem_test:
  .divident_512  db '7c681252935e7dd6efa7cd4d0a8aa053dd738e96180c8faed59d30df3f5404566cab2e724a66e4fa3d4def6d8a006d18f1995d9797f82e28d4c536cf7fdf76c8'
  .divisor_512	 db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .quotient_512  db '0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000015C69E7ABD513E06BE959'
  .reminder_512  db '000000000000000000002A515773A0A4EDF99CBEC419428840CB7FDC7F825957CF563C5E5DD9B4C07900DDB317832E49A462E6B66121D630002BC25FDDFACF8E'

  .divident_256  db '7c681252935e7dd6efa7cd4d0a8aa053dd738e96180c8faed59d30df3f5404566cab2e724a66e4fa3d4def6d8a006d18f1995d9797f82e28d4c536cf7fdf76c8'
  .divisor_256	 db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .quotient_256  db '000000000000000000000000000000000000000000015C69E7ABD513E06BE959'
  .reminder_256  db '000000000000000000002A515773A0A4EDF99CBEC4198F3020FAC4B0A6696CE6'

  .divident_128  db '8a687e85d66a5db0eccf631fa58a556d'
  .divisor_128	 db '000000000259b679bade237c1fc5dd53'
  .quotient_128  db '00000000000000000000003AE2D4A9B9'
  .reminder_128  db '0000000000043DF4132FAB6681B59972'
