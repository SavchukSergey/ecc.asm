macro BigIntegerDivRemTests bits, dbits {

include '../src/math/bigint/div_rem/div_rem.inc'
BigIntegerDivRem bits, dbits

__bi_div_rem_test_#bits:
        stc
        ret

}