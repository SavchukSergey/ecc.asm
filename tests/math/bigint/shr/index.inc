include 'bi_shr_assign_128_test.inc'
include 'bi_shr_assign_256_test.inc'
include 'bi_shr_assign_512_test.inc'

include 'bi_shr_assign_128_1_test.inc'
include 'bi_shr_assign_256_1_test.inc'
include 'bi_shr_assign_256_64_test.inc'
include 'bi_shr_assign_256_128_test.inc'
include 'bi_shr_assign_512_1_test.inc'
include 'bi_shr_assign_512_64_test.inc'
include 'bi_shr_assign_512_128_test.inc'
include 'bi_shr_assign_512_256_test.inc'

align 16
__bi_shr_tests:
    dq __bi_shr_assign_128_1_test
    db 'bi_shr_assign_128_1', 0
    dq __bi_shr_assign_128_test
    db 'bi_shr_assign_128', 0

    dq __bi_shr_assign_256_1_test
    db 'bi_shr_assign_256_1', 0
    dq __bi_shr_assign_256_64_test
    db 'bi_shr_assign_256_64', 0
    dq __bi_shr_assign_256_128_test
    db 'bi_shr_assign_256_128', 0

    dq __bi_shr_assign_256_test
    db 'bi_shr_assign_256', 0

    dq __bi_shr_assign_512_1_test
    db 'bi_shr_assign_512_1', 0
    dq __bi_shr_assign_512_64_test
    db 'bi_shr_assign_512_64', 0
    dq __bi_shr_assign_512_128_test
    db 'bi_shr_assign_512_128', 0
    dq __bi_shr_assign_512_256_test
    db 'bi_shr_assign_512_256', 0

    dq __bi_shr_assign_512_test
    db 'bi_shr_assign_512', 0

dq 0