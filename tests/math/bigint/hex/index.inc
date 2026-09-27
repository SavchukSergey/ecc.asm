include 'bi_try_read_hex_test.inc'

align 16
__bi_hex_tests:

    dq __bi_try_read_hex_256_test
    db 'bi_try_read_hex_256', 0

    dq 0
