include 'bigint/add.tests.inc'
include 'bigint/cmp.tests.inc'
include 'bigint/extend_high.tests.inc'
include 'bigint/read_hex.tests.inc'
include 'bigint/rnd.tests.inc'
include 'bigint/sub.tests.inc'
include 'bigint/zero.tests.inc'

macro BigIntegerTests bits {

align 16
__bi_tests_#bits:
        dq __bi_add_test_#bits
        db 'add', 0

        dq __bi_cmp_equal_test_#bits
        db 'cmp_equal', 0
        dq __bi_cmp_less_test_#bits
        db 'cmp_less', 0
        dq __bi_cmp_greater_test_#bits
        db 'cmp_greater', 0

        dq __bi_extend_high_test_#bits
        db 'extend_high', 0

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
BigIntegerCmpTests bits
BigIntegerExtendHighTests bits
BigIntegerReadHexTests bits
BigIntegerRndTests bits
BigIntegerSubTests bits
BigIntegerZeroTests bits
}

BigIntegerTests 128
BigIntegerTests 256
BigIntegerTests 512
