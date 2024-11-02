include 'bi_sub_128_128_test.inc'
include 'bi_sub_192_192_test.inc'
include 'bi_sub_256_256_test.inc'
include 'bi_sub_512_512_test.inc'

__bi_sub_tests:
    dq __bi_sub_128_128_test
    db 'bi_sub_128_128', 0

    dq __bi_sub_192_192_test
    db 'bi_sub_192_192', 0

    dq __bi_sub_256_256_test
    db 'bi_sub_256_256', 0

    dq __bi_sub_512_512_test
    db 'bi_sub_512_512', 0

    dq 0