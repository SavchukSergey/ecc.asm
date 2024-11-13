run_test_fixture:
	push	rax rbx rsi
virtual at rsp
  .locals_start:
  .test rq 1
  .test_proc rq 1
  .test_count rq 1
  .test_successes rq 1
  .test_failures rq 1
  .result TestContext
  AlignLocalsStackFrame
  .locals_end:
end virtual
virtual at TestContextReg
  .context TestContext
end virtual
	enter	.locals_end - .locals_start, 0
    PrologCheckStackAligned 'run_test_fixture'

	mov	    [.test], rax

	call	test_output_start_chapter

	mov	    rcx, rsi
	call	test_output_chapter_title

	call	test_output_start_chapter_table

.loop:
	mov     rax, [.test]
	mov     rbx, [rax]
	test	rbx, rbx
	jz      .end
	mov     [.test_proc], rbx
	add     qword [.test], 8

	call	test_output_start_test

	mov     rcx, [.test]
	call	test_output_test_name_cell

.test_name_end_loop:
	mov     rax, [.test]
	cmp     byte [rax], 0
	je      .test_name_end
	inc     [.test]
	jmp     .test_name_end_loop
.test_name_end:
	inc     [.test]

	mov     qword [.test_count], 0
	mov     qword [.test_successes], 0
	mov     qword [.test_failures], 0

	lea     TestContextReg, [.result]
	call	test_context_init
.count_loop:
	call    [.test_proc]
	cmp     [.context.assert_fails], 0
	jz      .count_pass
.count_fail:
	inc     qword [.test_failures]
	jmp     .count_continue
.count_pass:
	inc     qword [.test_successes]
	jmp     .count_continue
.count_continue:
	inc     [.test_count]
	cmp     [.test_failures], 0
	jne     .count_loop_end
	cmp     qword [.test_count], 20
	jb      .count_loop

.count_loop_end:
	call    test_context_finalize

	cmp     [.test_failures], 0x00
	je      .test_ok
.test_fail:
	mov     rcx, 1
	call    test_output_test_status_cell
	jmp     .test_end
.test_ok:
	xor	    rcx, rcx
	call	test_output_test_status_cell
	jmp	    .test_end
.test_end:
    xor     rax, rax
	mov     rcx, [.context.measures_min]
	test    rcx, rcx
	cmovs   rcx, rax
	call	test_output_test_min_ticks_cell

	mov	    rcx, [.context.measures_max]
	call	test_output_test_max_ticks_cell
 
    xor     rax, rax
	mov     rbx, [.context.measures_min]
	test    rbx, rbx
	cmovs   rbx, rax
	test    rbx, rbx
	jz      .rps_na
.rps_available:
    xor     rdx, rdx
	mov     rax, 3000000000
	div     rbx
	mov     rcx, rax
	call    test_output_test_rps_cell
	jmp     .rps_ok
.rps_na:
    mov     rcx, -1
	call    test_output_test_rps_cell
.rps_ok:

	call	test_output_end_test

	jmp	.loop
.end:
	call	test_output_end_chapter_table

	call	test_output_end_chapter

	leave
	pop     rsi rbx rax
	ret
