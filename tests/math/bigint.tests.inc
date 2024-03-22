include 'bigint/add/index.inc'
include 'bigint/sub.tests.inc'
include 'bigint/cmp.tests.inc'
include 'bigint/shl.tests.inc'
include 'bigint/shr.tests.inc'
include 'bigint/mul/index.inc'
include 'bigint/mul_low/index.inc'
include 'bigint/div_rem.tests.inc'
include 'bigint/zero.tests.inc'
include 'bigint/mod_add/index.inc'
include 'bigint/mod_sub.tests.inc'
include 'bigint/mod_mul/index.inc'
include 'bigint/mod_inverse/index.inc'
include 'bigint/lzcnt/index.inc'
;include 'bigint/bit_clear.tests.inc'
;include 'bigint/bit_set.tests.inc'
;include 'bigint/extend_high.tests.inc'
;include 'bigint/extend_low.tests.inc'
;include 'bigint/one.tests.inc'
;include 'bigint/read_hex.tests.inc'
;include 'bigint/rnd.tests.inc'

align 16
__bi_tests_128:
	dq __bi_zero_128_test
	db 'zero', 0

	dq __bi_add_128_128_test
	db 'add', 0

;	 dq __bi_bit_clear_first_test_#bits
;	 db 'bit_clear_first', 0
;	 dq __bi_bit_clear_last_test_#bits
;	 db 'bit_clear_last', 0
;	 dq __bi_bit_clear_middle_test_#bits
;	 db 'bit_clear_middle', 0
;	 dq __bi_bit_clear_twice_test_#bits
;	 db 'bit_clear_twice', 0

;	 dq __bi_bit_set_first_test_#bits
;	 db 'bit_set_first', 0
;	 dq __bi_bit_set_last_test_#bits
;	 db 'bit_set_last', 0
;	 dq __bi_bit_set_middle_test_#bits
;	 db 'bit_set_middle', 0
;	 dq __bi_bit_set_twice_test_#bits
;	 db 'bit_set_twice', 0

	dq __bi_cmp_128_128_equal_test
	db 'cmp_equal', 0
	dq __bi_cmp_128_128_less_test
	db 'cmp_less', 0
	dq __bi_cmp_128_128_greater_test
	db 'cmp_greater', 0
	dq __bi_cmp_128_128_close_test
	db 'cmp_close', 0

	dq __bi_shl_assign_128_1_test
	db '<<= 1', 0
	dq __bi_shr_assign_128_1_test
	db '>>= 1', 0

	dq __bi_shl_assign_128_test
	db '<<=', 0


;	 dq __bi_div_rem_test_#bits
;	 db 'div_rem', 0
	dq __bi_div_rem_128_64_test
	db 'div_rem u64', 0

;	 dq __bi_extend_high_test_#bits
;	 db 'extend_high', 0
;	 dq __bi_extend_low_test_#bits
;	 db 'extend_low', 0

;	 dq __bi_one_test_#bits
;	 db 'one', 0

;todo: sub positive, sub equal
	dq __bi_sub_128_128_test
	db 'sub negative', 0

	dq __bi_mul_128_128_test
	db 'mul', 0
	dq __bi_mul_128_128_max_test
	db 'mul max', 0

	dq __bi_mul_low_128_128_test
	db 'mul_low', 0
	dq __bi_mul_low_128_128_max_test
	db 'mul_low max', 0

;	 dq __bi_read_hex_test_#bits
;	 db 'read_hex', 0
;	 dq __bi_rnd_test_#bits
;	 db 'rnd', 0
	dq 0

align 16
__bi_tests_256:
	dq __bi_add_256_256_test
	db 'add', 0
	dq __bi_cmp_256_256_equal_test
	db 'cmp_equal', 0
	dq __bi_cmp_256_256_less_test
	db 'cmp_less', 0
	dq __bi_cmp_256_256_greater_test
	db 'cmp_greater', 0
	dq __bi_cmp_256_256_close_test
	db 'cmp_close', 0

	dq __bi_shl_assign_256_1_test
	db '<<= 1', 0
	dq __bi_shr_assign_256_1_test
	db '>>= 1', 0

	dq __bi_shl_assign_256_test
	db '<<=', 0

;todo: sub positive, sub equal
	dq __bi_sub_256_256_test
	db 'sub negative', 0

	dq __bi_mul_256_256_test
	db 'mul', 0
	dq __bi_mul_256_256_max_test
	db 'mul max', 0
	dq __bi_mul_low_256_256_test
	db 'mul_low', 0
	dq __bi_mul_low_256_256_max_test
	db 'mul_low max', 0

	dq __bi_div_rem_256_256_test
	db 'div_rem', 0

	dq __bi_mod_add_assign_256_256_test
	db 'mod_add', 0
	dq __bi_mod_sub_assign_256_256_test
	db 'mod_sub', 0
	dq __bi_mod_mul_256_256_test
	db 'mod_mul', 0
	dq __bi_mod_inverse_256_test
	db 'mod_inverse', 0

	dq __bi_lzcnt_256_test
	db 'lzcnt', 0

	dq 0
;	 dq __bi_zero_test_#bits
;	 db 'zero', 0

align 16
__bi_tests_512:
	dq __bi_add_512_512_test
	db 'add', 0
	dq __bi_cmp_512_512_equal_test
	db 'cmp_equal', 0
	dq __bi_cmp_512_512_less_test
	db 'cmp_less', 0
	dq __bi_cmp_512_512_greater_test
	db 'cmp_greater', 0
	dq __bi_cmp_512_512_close_test
	db 'cmp_close', 0

	dq __bi_shl_assign_512_1_test
	db '<<= 1', 0
	dq __bi_shr_assign_512_1_test
	db '>>= 1', 0

	dq __bi_shl_assign_512_test
	db '<<=', 0

;todo: sub positive, sub equal
	dq __bi_sub_512_512_test
	db 'sub negative', 0

	dq __bi_mul_512_512_test
	db 'mul', 0
	dq __bi_mul_512_512_max_test
	db 'mul max', 0

	dq __bi_mul_low_512_512_test
	db 'mul_low', 0
	dq __bi_mul_low_512_512_max_test
	db 'mul_low max', 0

	dq 0

macro BigIntegerTests bits, dbits {




;BigIntegerBitSetTests bits
;BigIntegerBitClearTests bits
;BigIntegerExtendHighTests bits, dbits
;BigIntegerExtendLowTests bits, dbits
;BigIntegerOneTests bits
;BigIntegerReadHexTests bits
;BigIntegerRndTests bits
}

;BigIntegerTests 128, 256
;BigIntegerTests 256, 512
;BigIntegerTests 512, 1024
