format ELF64 executable 3

segment readable executable

ECC_TESTS = 1
TARGET_OS='LINUX'

entry $
    call    ecc_run_tests

	xor      edi, edi 	; exit code 0
	mov      eax, 60	; sys_exit
	syscall

include 'output/html/index.inc'
include 'ecc_run_tests.inc'

segment readable
include '../src/data.inc'

segment readable writeable
calibration_shift rq 1
