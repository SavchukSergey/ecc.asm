include 'bi_square_128_test.inc'
include 'bi_square_256_test.inc'

align 16
__bi_square_tests:
    dq __bi_square_128_test
    db 'bi_square_128', 0

    dq __bi_square_256_test
    db 'bi_square_256', 0

dq 0