include 'bi_copy_128_test.inc'
include 'bi_copy_192_test.inc'
include 'bi_copy_256_test.inc'
include 'bi_copy_512_test.inc'
include 'bi_copy_768_test.inc'

align 16
__bi_copy_tests:
    dq __bi_copy_128_test
    db 'bi_copy_128', 0

    dq __bi_copy_192_test
    db 'bi_copy_192', 0

    dq __bi_copy_256_test
    db 'bi_copy_256', 0

    dq __bi_copy_512_test
    db 'bi_copy_512', 0

    dq __bi_copy_768_test
    db 'bi_copy_768', 0

;    dq __bi_copy_1024_test
;    db 'bi_copy_1024', 0

    dq 0