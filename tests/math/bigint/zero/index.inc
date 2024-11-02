include 'bi_zero_128_test.inc'
include 'bi_zero_192_test.inc'
include 'bi_zero_256_test.inc'
include 'bi_zero_512_test.inc'
include 'bi_zero_1024_test.inc'

__bi_zero_tests:
    dq __bi_zero_128_test
    db 'bi_zero_128', 0

    dq __bi_zero_192_test
    db 'bi_zero_192', 0

    dq __bi_zero_256_test
    db 'bi_zero_256', 0

    dq __bi_zero_512_test
    db 'bi_zero_512', 0

    dq __bi_zero_1024_test
    db 'bi_zero_1024', 0

    dq 0