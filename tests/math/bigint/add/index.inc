include 'bi_add_128_128_test.inc'
include 'bi_add_192_192_test.inc'
include 'bi_add_256_256_test.inc'
include 'bi_add_512_512_test.inc'

align 16
__bi_add_tests:
    dq __bi_add_128_128_test
    db 'bi_add_128_128', 0

    dq __bi_add_192_192_test
    db 'bi_add_192_192', 0

    dq __bi_add_256_256_test
    db 'bi_add_256_256', 0

    dq __bi_add_512_512_test
    db 'bi_add_512_512', 0

    dq 0