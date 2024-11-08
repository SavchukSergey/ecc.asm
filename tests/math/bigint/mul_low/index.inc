include 'bi_mul_low_test_macro.inc'

include 'bi_mul_128_64_low_128_test.inc'
include 'bi_mul_128_128_low_128_test.inc'
include 'bi_mul_192_64_low_192_test.inc'
include 'bi_mul_256_64_low_256_test.inc'
include 'bi_mul_256_128_low_256_test.inc'
include 'bi_mul_256_256_low_256_test.inc'
include 'bi_mul_512_64_low_512_test.inc'
include 'bi_mul_512_512_low_512_test.inc'

align 16
__bi_mul_low_tests:
    dq __bi_mul_128_64_low_128_test
    db 'bi_mul_128_64_low_128', 0
    dq __bi_mul_128_128_low_128_test
    db 'bi_mul_128_128_low_128', 0

    dq __bi_mul_192_64_low_192_test
    db 'bi_mul_192_64_low_192', 0

    dq __bi_mul_256_64_low_256_test
    db 'bi_mul_256_64_low_256', 0
    dq __bi_mul_256_128_low_256_test
    db 'bi_mul_256_128_low_256', 0
    dq __bi_mul_256_256_low_256_test
    db 'bi_mul_256_256_low_256', 0

    dq __bi_mul_512_64_low_512_test
	db 'bi_mul_512_64_low_512', 0
    dq __bi_mul_512_512_low_512_test
	db 'bi_mul_512_512_low_512', 0

dq 0
