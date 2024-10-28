format ELF64 executable 3

segment readable executable

ECC_TESTS = 1
TARGET_OS='LINUX'

entry $
    call    ecc_run_tests

	xor      edi, edi 	; exit code 0
	mov      eax, 60	; sys_exit
	syscall

include 'test_output_html.inc'
include 'ecc_run_tests.inc'

segment readable writeable
calibration_shift rq 1
