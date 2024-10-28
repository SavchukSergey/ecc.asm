run_test_calibrate:
virtual at rsp
  .locals_start:
    .result TestContext
  .locals_end:
end virtual
	enter	.locals_end - .locals_start, 0
	lea     TestContextReg, [.result]
	call	test_context_init

	mov     [calibration_shift], 0
	mov	    rbx, -1
	mov	    rcx, 1000
.count_loop:
	push	rbx rcx
	call	[.empty_ref]
	pop	    rcx rbx
	loop	.count_loop

	call	test_context_finalize
	mov	    rax, [.result.measures_min]
	mov	    [calibration_shift], rax

	leave
	ret
.sub_empty:
	ret
.empty:
	call	test_context_start_measure
.loop:
	call	.sub_empty
	call	test_context_measure_dec_chunk
	jnz	.loop
	call	test_context_end_measure

	ret
.empty_ref dq .empty