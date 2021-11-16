include 'bigint/add.tests.inc'
include 'bigint/bit_clear.tests.inc'
include 'bigint/bit_set.tests.inc'
include 'bigint/cmp.tests.inc'
include 'bigint/div_rem.tests.inc'
include 'bigint/extend_high.tests.inc'
include 'bigint/extend_low.tests.inc'
include 'bigint/read_hex.tests.inc'
include 'bigint/rnd.tests.inc'
include 'bigint/sub.tests.inc'
include 'bigint/zero.tests.inc'

macro BigIntegerTests bits, dbits {

align 16
__bi_tests_#bits:
        dq __bi_add_test_#bits
        db 'add', 0

        dq __bi_bit_clear_first_test_#bits
        db 'bit_clear_first', 0
        dq __bi_bit_clear_last_test_#bits
        db 'bit_clear_last', 0
        dq __bi_bit_clear_middle_test_#bits
        db 'bit_clear_middle', 0
        dq __bi_bit_clear_twice_test_#bits
        db 'bit_clear_twice', 0

        dq __bi_bit_set_first_test_#bits
        db 'bit_set_first', 0
        dq __bi_bit_set_last_test_#bits
        db 'bit_set_last', 0
        dq __bi_bit_set_middle_test_#bits
        db 'bit_set_middle', 0
        dq __bi_bit_set_twice_test_#bits
        db 'bit_set_twice', 0

        dq __bi_cmp_equal_test_#bits
        db 'cmp_equal', 0
        dq __bi_cmp_less_test_#bits
        db 'cmp_less', 0
        dq __bi_cmp_greater_test_#bits
        db 'cmp_greater', 0

        dq __bi_div_rem_test_#bits
        db 'div_rem', 0

        dq __bi_extend_high_test_#bits
        db 'extend_high', 0
        dq __bi_extend_low_test_#bits
        db 'extend_low', 0

        dq __bi_read_hex_test_#bits
        db 'read_hex', 0
        dq __bi_rnd_test_#bits
        db 'rnd', 0
        dq __bi_sub_neg_test_#bits
        db 'sub negative', 0
        dq __bi_sub_pos_test_#bits
        db 'sub positive', 0
        dq __bi_zero_test_#bits
        db 'zero', 0
        dq 0


BigIntegerAddTests bits
BigIntegerBitSetTests bits
BigIntegerBitClearTests bits
BigIntegerCmpTests bits
BigIntegerDivRemTests bits, dbits
BigIntegerExtendHighTests bits, dbits
BigIntegerExtendLowTests bits, dbits
BigIntegerReadHexTests bits
BigIntegerRndTests bits
BigIntegerSubTests bits
BigIntegerZeroTests bits
}

BigIntegerTests 128, 256
BigIntegerTests 256, 512
BigIntegerTests 512, 1024
