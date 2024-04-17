include '../src/math/bigint/read_hex.inc'

include 'bigint/add/index.inc'
include 'bigint/cmp/index.inc'
include 'bigint/copy/index.inc'
include 'bigint/div_rem/index.inc'
include 'bigint/is_zero/index.inc'
include 'bigint/lzcnt/index.inc'
include 'bigint/mod_add/index.inc'
include 'bigint/mod_inverse/index.inc'
include 'bigint/mod_mul/index.inc'
include 'bigint/mod_sub/index.inc'
include 'bigint/mul/index.inc'
include 'bigint/mul_low/index.inc'
include 'bigint/shl/index.inc'
include 'bigint/shr/index.inc'
include 'bigint/sub/index.inc'
include 'bigint/zero/index.inc'

;include 'bigint/bit_clear.tests.inc'
;include 'bigint/bit_set.tests.inc'
;include 'bigint/extend_low.tests.inc'
;include 'bigint/one.tests.inc'
;include 'bigint/read_hex.tests.inc'
;include 'bigint/rnd.tests.inc'

align 16
__bi_tests_128:
        dq __bi_zero_128_test
        db 'bi_zero_128', 0

        dq __bi_add_128_128_test
        db 'bi_add_128_128', 0
        dq __bi_sub_128_128_test
        db 'bi_sub_128_128', 0

        dq __bi_cmp_128_128_test
        db 'bi_cmp_128_128', 0

;        dq __bi_bit_clear_first_test_#bits
;        db 'bit_clear_first', 0
;        dq __bi_bit_clear_last_test_#bits
;        db 'bit_clear_last', 0
;        dq __bi_bit_clear_middle_test_#bits
;        db 'bit_clear_middle', 0
;        dq __bi_bit_clear_twice_test_#bits
;        db 'bit_clear_twice', 0

;        dq __bi_bit_set_first_test_#bits
;        db 'bit_set_first', 0
;        dq __bi_bit_set_last_test_#bits
;        db 'bit_set_last', 0
;        dq __bi_bit_set_middle_test_#bits
;        db 'bit_set_middle', 0
;        dq __bi_bit_set_twice_test_#bits
;        db 'bit_set_twice', 0

        dq __bi_shl_assign_128_1_test
        db 'bi_shl_assign_128_1', 0
        dq __bi_shl_assign_128_test
        db 'bi_shl_assign_128', 0

        dq __bi_shr_assign_128_1_test
        db 'bi_shr_assign_128_1', 0
        dq __bi_shr_assign_128_test
        db 'bi_shr_assign_128', 0

        dq __bi_div_rem_128_64_test
        db 'bi_div_rem_128_64', 0
        dq __bi_div_rem_128_128_test
        db 'bi_div_rem_128_128', 0

        dq __bi_rem_128_64_test
        db 'bi_rem_128_64', 0

        dq __bi_lzcnt_128_test
        db 'bi_lzcnt_128', 0

;        dq __bi_one_test_#bits
;        db 'one', 0

        dq __bi_mul_128_64_test
        db 'bi_mul_128_64', 0
        dq __bi_mul_128_128_test
        db 'bi_mul_128_128', 0
        dq __bi_mul_low_128_128_test
        db 'bi_mul_low_128_128', 0

;        dq __bi_read_hex_test_#bits
;        db 'read_hex', 0
;        dq __bi_rnd_test_#bits
;        db 'rnd', 0
        dq 0

align 16
__bi_tests_256:
        dq __bi_zero_256_test
        db 'bi_zero_256', 0
        dq __bi_is_zero_256_test
        db 'bi_is_zero_256', 0
        dq __bi_copy_256_test
        db 'bi_copy_256', 0
        dq __bi_add_256_256_test

        db 'bi_add_256_256', 0
        dq __bi_sub_256_256_test
        db 'bi_sub_256_256', 0

        dq __bi_cmp_256_256_test
        db 'bi_cmp_256_256', 0

        dq __bi_shl_assign_256_1_test
        db 'bi_shl_assign_256_1', 0
        dq __bi_shl_assign_256_64_test
        db 'bi_shl_assign_256_64', 0
        dq __bi_shl_assign_256_128_test
        db 'bi_shl_assign_256_128', 0

        dq __bi_shl_assign_256_test
        db 'bi_shl_assign_256', 0

        dq __bi_shr_assign_256_1_test
        db 'bi_shr_assign_256_1', 0
        dq __bi_shr_assign_256_64_test
        db 'bi_shr_assign_256_64', 0
        dq __bi_shr_assign_256_128_test
        db 'bi_shr_assign_256_128', 0

        dq __bi_shr_assign_256_test
        db 'bi_shr_assign_256', 0

        dq __bi_mul_256_64_test
        db 'bi_mul_256_64', 0
        dq __bi_mul_256_128_test
        db 'bi_mul_256_128', 0
        dq __bi_mul_256_256_test
        db 'bi_mul_256_256', 0
        dq __bi_mul_low_256_256_test
        db 'bi_mul_low_256_256', 0

        dq __bi_div_rem_256_64_test
        db 'bi_div_rem_256_64', 0
        dq __bi_div_rem_256_128_test
        db 'bi_div_rem_256_128', 0
        dq __bi_div_rem_256_256_test
        db 'bi_div_rem_256_256', 0

        dq __bi_mod_add_assign_256_256_test
        db 'bi_mod_add_assign_256_256', 0
        dq __bi_mod_sub_assign_256_256_test
        db 'bi_mod_sub_assign_256_256', 0
        dq __bi_mod_mul_256_256_test
        db 'bi_mod_mul_256_256', 0
        dq __bi_mod_inverse_256_test
        db 'bi_mod_inverse_256', 0

        dq __bi_lzcnt_256_test
        db 'bi_lzcnt_256', 0

        dq 0

align 16
__bi_tests_512:
        dq __bi_zero_512_test
        db 'bi_zero_512', 0
        dq __bi_is_zero_512_test
        db 'bi_is_zero_512', 0
        dq __bi_copy_512_test
        db 'bi_copy_512', 0
        
        dq __bi_add_512_512_test
        db 'bi_add_512_512', 0
        dq __bi_sub_512_512_test
        db 'bi_sub_512_512', 0

        dq __bi_cmp_512_512_test
        db 'bi_cmp_512_512', 0

        dq __bi_shl_assign_512_1_test
        db 'bi_shl_assign_512_1', 0
        dq __bi_shl_assign_512_64_test
        db 'bi_shl_assign_512_64', 0
        dq __bi_shl_assign_512_128_test
        db 'bi_shl_assign_512_128', 0
        dq __bi_shl_assign_512_256_test
        db 'bi_shl_assign_512_256', 0

        dq __bi_shl_assign_512_test
        db 'bi_shl_assign_512', 0

        dq __bi_shr_assign_512_1_test
        db 'bi_shr_assign_512_1', 0
        dq __bi_shr_assign_512_64_test
        db 'bi_shr_assign_512_64', 0
        dq __bi_shr_assign_512_128_test
        db 'bi_shr_assign_512_128', 0
        dq __bi_shr_assign_512_256_test
        db 'bi_shr_assign_512_256', 0

        dq __bi_shr_assign_512_test
        db 'bi_shr_assign_512', 0

        dq __bi_mul_512_512_test
        db 'bi_mul_512_512', 0

        dq __bi_mul_low_512_512_test
	db 'bi_mul_low_512_512', 0

        dq __bi_div_rem_512_64_test
        db 'bi_div_rem_512_64', 0

        dq __bi_div_rem_512_128_test
        db 'bi_div_rem_512_128', 0

        dq __bi_div_rem_512_256_test
        db 'bi_div_rem_512_256', 0

        dq __bi_rem_512_64_test
        db 'bi_rem_512_64', 0
        dq __bi_rem_512_128_test
        db 'bi_rem_512_128', 0
        dq __bi_rem_512_256_test
        db 'bi_rem_512_256', 0

        dq 0

align 16
__bi_tests_1024:
        dq __bi_zero_1024_test
        db 'bi_zero_1024', 0

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
