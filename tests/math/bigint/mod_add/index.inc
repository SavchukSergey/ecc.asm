include 'bi_mod_add_assign_256_256_test.inc'

align 16
__bi_mod_add_tests:
    dq __bi_mod_add_assign_256_256_test
    db 'bi_mod_add_assign_256_256', 0

    dq 0