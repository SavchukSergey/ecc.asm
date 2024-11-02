format pe64 console
entry start

include 'win64a.inc'

ECC_TESTS = 1
TARGET_OS='WIN'

section '.text' code readable executable
start:
	and     rsp, 0xffff_ffff_ffff_fff0

	call	bind_thread_to_single_core

	call	enable_vt_processing

    call    ecc_run_tests

	sub	    rsp, 0x28
	xor		rcx, rcx
	call	[ExitProcess]
	add	    rsp, 0x28
	ret

include 'console/enable_vt_processing.inc'
include 'test_output_html.inc'
include 'framework/bind_thread_to_single_core.inc'
include 'ecc_run_tests.inc'

section '.bss' data readable writeable
calibration_shift rq 1

section '.idata' import data readable writeable

  library kernel,'KERNEL32.DLL'

  import kernel,\
	 ExitProcess,'ExitProcess', \
	 GetCurrentThread,'GetCurrentThread', \
	 SetThreadAffinityMask,'SetThreadAffinityMask', \
	 GetCurrentProcessorNumber ,'GetCurrentProcessorNumber', \
	 GetStdHandle, 'GetStdHandle', \
	 GetConsoleMode, 'GetConsoleMode', \
	 SetConsoleMode, 'SetConsoleMode', \
	 WriteFile, 'WriteFile'
