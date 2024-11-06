include 'framework/run_test_fixture.inc'
include 'framework/run_test_calibrate.inc'
include 'framework/guard.inc'
include '../src/macro/align.inc'
include '../src/math/bigint.inc'
include '../src/math/bigint/hex/index.inc'
include 'test_context.inc'
include 'asserts/index.inc'

ecc_run_tests:
	call	run_test_calibrate

	call	test_output_start

	mov     rax, __bi_zero_tests
	mov     rsi, .bi_zero_fixture_name
	call	run_test_fixture

	mov     rax, __bi_copy_tests
	mov     rsi, .bi_copy_fixture_name
	call	run_test_fixture

	mov     rax, __bi_add_tests
	mov     rsi, .bi_add_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_sub_tests
	mov     rsi, .bi_sub_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mul_tests
	mov     rsi, .bi_mul_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mul_low_tests
	mov     rsi, .bi_mul_low_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_div_rem_tests
	mov     rsi, .bi_div_rem_tests_fixture_name
	call	run_test_fixture

	mov     rax, __secp256k1_tests
	mov     rsi, .ecc_fixture_name
	call	run_test_fixture

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

	call	test_output_end
    ret

.empty_fixture_name db 'calibrate', 0
.bi128_fixture_name db 'bi128', 0
.bi192_fixture_name db 'bi192', 0
.bi256_fixture_name db 'bi256', 0
.bi512_fixture_name db 'bi512', 0
.bi_zero_fixture_name db 'bi_zero', 0
.bi_copy_fixture_name db 'bi_copy', 0
.bi_add_tests_fixture_name db 'bi_add', 0
.bi_sub_tests_fixture_name db 'bi_sub', 0
.bi_mul_tests_fixture_name db 'bi_mul', 0
.bi_mul_low_tests_fixture_name db 'bi_mul_low', 0
.bi_div_rem_tests_fixture_name db 'bi_div_rem', 0
.ecc_fixture_name db 'ecc', 0

include 'math/bigint.tests.inc'
include 'math/ecc.tests.inc'
