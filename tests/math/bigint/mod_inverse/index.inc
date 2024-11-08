include 'bi_mod_inverse_256_test.inc'
include 'bi_mod_inverse_512_test.inc'

align 16
__bi_mod_inverse_tests:
    dq __bi_mod_inverse_256_test
    db 'bi_mod_inverse_256', 0

    dq __bi_mod_inverse_512_test
    db 'bi_mod_inverse_512', 0

    dq 0