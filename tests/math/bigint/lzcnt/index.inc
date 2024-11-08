include 'bi_lzcnt_128_test.inc'
include 'bi_lzcnt_192_test.inc'
include 'bi_lzcnt_256_test.inc'

align 16
__bi_lzcnt_tests:
    dq __bi_lzcnt_128_test
    db 'bi_lzcnt_128', 0

    dq __bi_lzcnt_192_test
    db 'bi_lzcnt_192', 0

    dq __bi_lzcnt_256_test
    db 'bi_lzcnt_256', 0


dq 0