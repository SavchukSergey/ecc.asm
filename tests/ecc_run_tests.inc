include 'framework/run_test_fixture.inc'
include 'framework/run_test_calibrate.inc'
include '../src/macro/align.inc'
include '../src/math/bigint.inc'
include 'test_context.inc'

ecc_run_tests:
	call	run_test_calibrate

	call	test_output_start

	mov     rax, __bi_tests_128
	mov     rsi, .bi128_fixture_name
	call	run_test_fixture

	mov     rax, __bi_tests_192
	mov     rsi, .bi192_fixture_name
	call	run_test_fixture

	mov     rax, __bi_tests_256
	mov     rsi, .bi256_fixture_name
	call	run_test_fixture

	mov     rax, __bi_tests_512
	mov     rsi, .bi512_fixture_name
	call	run_test_fixture

	mov     rax, __bi_tests_1024
	mov     rsi, .bi1024_fixture_name
	call	run_test_fixture

	mov     rax, __bi_div_rem_tests
	mov     rsi, .bi_div_rem_tests_fixture_name
	call	run_test_fixture

	mov     rax, __secp256k1_tests
	mov     rsi, .ecc_fixture_name
	call	run_test_fixture

	call	test_output_end
    ret

.empty_fixture_name db 'calibrate', 0
.bi128_fixture_name db 'bi128', 0
.bi192_fixture_name db 'bi192', 0
.bi256_fixture_name db 'bi256', 0
.bi512_fixture_name db 'bi512', 0
.bi1024_fixture_name db 'bi1024', 0
.bi_div_rem_tests_fixture_name db 'div_rem', 0
.ecc_fixture_name db 'ecc', 0

include 'math/bigint.tests.inc'
include 'math/ecc.tests.inc'
