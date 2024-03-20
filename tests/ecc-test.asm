format pe64 console
entry start

include 'win64a.inc'

section '.text' code readable executable
start:
	call	enable_vt_processing

	sub	rsp, 0x28

	mov	rsi, .welcome
	call	Console_WriteString

	call	run_test_calibrate

	mov	rax, __bi_tests_128
	mov	rsi, .bi128_fixture_name
	call	run_test_fixture

	mov	rax, __bi_tests_256
	mov	rsi, .bi256_fixture_name
	call	run_test_fixture

	mov	rax, __bi_tests_512
	mov	rsi, .bi512_fixture_name
	call	run_test_fixture

	mov	rsi, .bye
	call	Console_WriteString

	invoke	ExitProcess, 0
	add	rsp, 0x28
	ret
.welcome db 'ecc.js tests', 13, 10, 0
.bye db 'finished', 13, 10, 0
.empty_fixture_name db 'calibrate', 0
.bi128_fixture_name db 'bi128', 0
.bi256_fixture_name db 'bi256', 0
.bi512_fixture_name db 'bi512', 0

include '../src/console/enable_vt_processing.inc'
include '../src/console/write_u64.inc'
include 'test_context.inc'

run_test_calibrate:
virtual at rsp
  .locals_start:
    .result TestContext
  .locals_end:
end virtual
	enter	.locals_end - .locals_start, 0
	lea	TestContextReg, [.result]
	mov	[calibration_shift], 0
	mov	rbx, -1
	mov	rcx, 10000
.count_loop:
	push	rbx rcx
	call	test_context_init
	call	[.empty_ref]
	pop	rcx rbx

	mov	rax, [.result.measures_avg]

	cmp	rax, rbx
	cmovb	rbx, rax
	loop	.count_loop

	mov	[calibration_shift], rbx
	leave
	ret
.empty:
	call	test_context_start_measure
	call	test_context_end_measure
	ret
.empty_ref dq .empty

run_test_fixture:
	push	rax rbx rsi
virtual at rsp
  .locals_start:
  .test rq 1
  .test_proc rq 1
  .test_duration rq 1
  .test_min_duration rq 1
  .test_max_duration rq 1
  .test_result rq 1
  .test_count rq 1
  .test_successes rq 1
  .test_failures rq 1
  .result TestContext
  .locals_end:
end virtual
	enter	.locals_end - .locals_start, 0
	mov	[.test], rax

	call	Console_WriteString

	mov	rsi, .tests_suffix
	call	Console_WriteString

	call	Console_WriteLine

	mov	rsi, .tests_header
	call	Console_WriteString

.loop:
	mov	rax, [.test]
	mov	rbx, [rax]
	test	rbx, rbx
	jz	.end
	mov	[.test_proc], rbx
	add	qword [.test], 8

	mov	rsi, .test_name_prefix
	call	Console_WriteString
	mov	rsi, [.test]
	call	Console_WriteString
	mov	rsi, .test_name_suffix
	call	Console_WriteString

.test_name_end_loop:
	mov	rax, [.test]
	cmp	byte [rax], 0
	je	.test_name_end
	inc	[.test]
	jmp	.test_name_end_loop
.test_name_end:
	inc	[.test]

	mov	qword [.test_count], 0
	mov	qword [.test_successes], 0
	mov	qword [.test_failures], 0
	mov	qword [.test_min_duration], -1
	mov	qword [.test_max_duration], 0

	lea	TestContextReg, [.result]
.count_loop:
	call	test_context_init
	call	[.test_proc]
	setc	byte [.test_result]
	cmp	byte [.test_result], 0x00
	je	.count_pass
.count_fail:
	inc	qword [.test_failures]
	jmp	.count_continue
.count_pass:
	inc	qword [.test_successes]
	jmp	.count_continue
.count_continue:
	mov	rax, [.result.measures_avg]
	mov	[.test_duration], rax

	mov	rax, [.test_min_duration]
	cmp	rax, [.test_duration]
	cmova	rax, [.test_duration]
	mov	[.test_min_duration], rax

	mov	rax, [.test_max_duration]
	cmp	rax, [.test_duration]
	cmovb	rax, [.test_duration]
	mov	[.test_max_duration], rax

	inc	[.test_count]

	cmp	[.test_failures], 0
	jne	.test_fail
	cmp	qword [.test_count], 5000
	jb	.count_loop


	cmp	[.test_failures], 0x00
	je	.test_ok
.test_fail:
	mov	rsi, .failed
	call	Console_WriteString
	jmp	.test_end
.test_ok:
	mov	rsi, .passed
	call	Console_WriteString
	jmp	.test_end
.test_end:
	mov	rsi, .time_min_prefix
	call	Console_WriteString
	mov	rax, [.test_min_duration]
	call	Console_WriteUInt64
	mov	rsi, .time_min_suffix
	call	Console_WriteString

	mov	rsi, .time_max_prefix
	call	Console_WriteString
	mov	rax, [.test_max_duration]
	call	Console_WriteUInt64
	mov	rsi, .time_max_suffix
	call	Console_WriteString

	call	Console_WriteLine

	jmp	.loop
.end:
	mov	rsi, .tests_footer
	call	Console_WriteString

	leave
	pop	rsi rbx rax
	ret

.tests_suffix db ' tests', 0
.tests_header db \
'+------------------------+--------+---------------+---------------+', 13, 10, \
'| Name                   | Status | Min CPU ticks | Max CPU ticks |', 13, 10, \
'+------------------------+--------+---------------+---------------+', 13, 10, \
0
.tests_footer db \
'+------------------------+--------+---------------+---------------+', 13, 10, \
0

.test_name_prefix db '| ', 0
.test_name_suffix db 0x1b, '[25G', ' |', 0

.failed db TEXT_COLOR_ERROR, ' FAILED ', TEXT_COLOR_DEFAULT, '|', 0
.passed db TEXT_COLOR_SUCCESS, ' PASSED ', TEXT_COLOR_DEFAULT, '|', 0
.time_min_prefix db 0x1b, '[37G', 0
.time_min_suffix db 0x1b, '[50G |', 0
.time_max_prefix db 0x1b, '[52G ', 0
.time_max_suffix db 0x1b, '[66G |', 0

include '../src/math/bigint.inc'
include 'math/bigint.tests.inc'
include '../src/math/rnd.inc'
include '../src/console/write_string.inc'
include '../src/console/write_line.inc'

section '.bss' data readable writeable
calibration_shift rq 1


section '.idata' import data readable writeable

  library kernel,'KERNEL32.DLL'

  import kernel,\
	 ExitProcess,'ExitProcess', \
	 GetStdHandle, 'GetStdHandle', \
	 GetConsoleMode, 'GetConsoleMode', \
	 SetConsoleMode, 'SetConsoleMode', \
	 WriteFile, 'WriteFile'
