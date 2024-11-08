;include 'bi_is_zero_128_test.inc'
include 'bi_is_zero_256_test.inc'
include 'bi_is_zero_512_test.inc'
;include 'bi_is_zero_1024_test.inc'

align 16
__bi_is_zero_tests:

    dq __bi_is_zero_256_test
    db 'bi_is_zero_256', 0

    dq __bi_is_zero_512_test
    db 'bi_is_zero_512', 0
    
    dq 0