include 'bi_mod_square_256_test.inc'

align 16
__bi_mod_square_tests:
    dq __bi_mod_square_256_test
    db 'bi_mod_square_256', 0

    dq 0
