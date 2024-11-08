include 'bi_cmp_128_128_test.inc'
include 'bi_cmp_192_192_test.inc'
include 'bi_cmp_256_256_test.inc'
include 'bi_cmp_512_512_test.inc'

align 16
__bi_cmp_tests:
    dq __bi_cmp_128_128_test
    db 'bi_cmp_128_128', 0

    dq __bi_cmp_192_192_test
    db 'bi_cmp_192_192', 0

    dq __bi_cmp_256_256_test
    db 'bi_cmp_256_256', 0

    dq __bi_cmp_512_512_test
    db 'bi_cmp_512_512', 0

    dq 0