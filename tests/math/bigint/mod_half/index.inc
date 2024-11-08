include 'bi_mod_half_assign_256_test.inc'

align 16
__bi_mod_half_tests:
    dq __bi_mod_half_assign_256_test
    db 'bi_mod_half_assign_256', 0

dq 0