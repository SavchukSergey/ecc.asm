include '../src/math/bigint.inc'
include '../src/math/bigint/index.inc'
include '../src/math/ecc/index.inc'
include 'console/index.inc'
include 'framework/index.inc'
include 'asserts/index.inc'

include 'output/shared/index.inc'

include 'math/bigint.tests.inc'
include 'math/ecc/index.inc'

ecc_run_tests:
	call	bind_thread_to_single_core

	call	run_test_calibrate

	call	test_output_start

	mov     rax, __bi_zero_tests
	mov     rsi, .bi_zero_fixture_name
	call	run_test_fixture

	mov     rax, __bi_copy_tests
	mov     rsi, .bi_copy_fixture_name
	call	run_test_fixture

	mov     rax, __bi_is_zero_tests
	mov     rsi, .bi_is_zero_fixture_name
	call	run_test_fixture

	mov     rax, __bi_rnd_tests
	mov     rsi, .bi_rnd_fixture_name
	call	run_test_fixture

	mov     rax, __bi_add_tests
	mov     rsi, .bi_add_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_sub_tests
	mov     rsi, .bi_sub_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_lzcnt_tests
	mov     rsi, .bi_lzcnt_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_shl_tests
	mov     rsi, .bi_shl_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_shr_tests
	mov     rsi, .bi_shr_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_cmp_tests
	mov     rsi, .bi_cmp_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mul_tests
	mov     rsi, .bi_mul_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mul_low_tests
	mov     rsi, .bi_mul_low_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_square_tests
	mov     rsi, .bi_square_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_div_rem_tests
	mov     rsi, .bi_div_rem_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_add_tests
	mov     rsi, .bi_mod_add_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_double_tests
	mov     rsi, .bi_mod_double_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_tripple_tests
	mov     rsi, .bi_mod_tripple_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_half_tests
	mov     rsi, .bi_mod_half_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_sub_tests
	mov     rsi, .bi_mod_sub_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_mul_tests
	mov     rsi, .bi_mod_mul_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_div_tests
	mov     rsi, .bi_mod_div_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_square_tests
	mov     rsi, .bi_mod_square_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_cube_tests
	mov     rsi, .bi_mod_cube_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_pow_tests
	mov     rsi, .bi_mod_pow_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mod_inverse_tests
	mov     rsi, .bi_mod_inverse_tests_fixture_name
	call	run_test_fixture

	mov     rax, __bi_mont_tests
	mov     rsi, .bi_mont_tests_fixture_name
	call	run_test_fixture

	mov     rax, __ec_affine_point_tests
	mov     rsi, .ec_affine_point_fixture_name
	call	run_test_fixture

	mov     rax, __ec_projective_point_tests
	mov     rsi, .ec_projective_point_fixture_name
	call	run_test_fixture

	mov     rax, __ec_projective_mont_point_tests
	mov     rsi, .ec_projective_mont_point_fixture_name
	call	run_test_fixture

	call	test_output_end
    ret

.empty_fixture_name db 'calibrate', 0
.bi_zero_fixture_name db 'bi_zero', 0
.bi_copy_fixture_name db 'bi_copy', 0
.bi_is_zero_fixture_name db 'bi_is_zero', 0
.bi_rnd_fixture_name db 'bi_rnd', 0
.bi_add_tests_fixture_name db 'bi_add', 0
.bi_sub_tests_fixture_name db 'bi_sub', 0
.bi_lzcnt_tests_fixture_name db 'bi_lzcnt', 0
.bi_shl_tests_fixture_name db 'bi_shl', 0
.bi_shr_tests_fixture_name db 'bi_shr', 0
.bi_cmp_tests_fixture_name db 'bi_cmp', 0
.bi_mul_tests_fixture_name db 'bi_mul', 0
.bi_mul_low_tests_fixture_name db 'bi_mul_low', 0
.bi_div_rem_tests_fixture_name db 'bi_div_rem', 0
.bi_mod_add_tests_fixture_name db 'bi_mod_add', 0
.bi_mod_double_tests_fixture_name db 'bi_mod_add', 0
.bi_mod_tripple_tests_fixture_name db 'bi_mod_tripple', 0
.bi_mod_sub_tests_fixture_name db 'bi_mod_add', 0
.bi_mod_half_tests_fixture_name db 'bi_mod_half', 0
.bi_mod_mul_tests_fixture_name db 'bi_mod_mul', 0
.bi_mod_div_tests_fixture_name db 'bi_mod_div', 0
.bi_mod_pow_tests_fixture_name db 'bi_mod_pow', 0
.bi_mod_square_tests_fixture_name db 'bi_mod_square', 0
.bi_mod_cube_tests_fixture_name db 'bi_mod_cube', 0
.bi_mod_inverse_tests_fixture_name db 'bi_mod_inverse', 0
.bi_mont_tests_fixture_name db 'bi_mont', 0
.bi_square_tests_fixture_name db 'bi_square', 0
.ec_affine_point_fixture_name db 'ec_affine_point', 0
.ec_projective_point_fixture_name db 'ec_projective_point', 0
.ec_projective_mont_point_fixture_name db 'ec_projective_mont_point', 0
