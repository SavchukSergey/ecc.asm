include 'bi_mul_128_64_low_128_test.inc'
include 'bi_mul_128_128_low_128_test.inc'
include 'bi_mul_256_64_low_256_test.inc'
include 'bi_mul_low_256_128_test.inc'
include 'bi_mul_256_256_low_256_test.inc'
include 'bi_mul_low_512_64_test.inc'
include 'bi_mul_low_512_512_test.inc'

__bi_mul_low_tests:
    dq __bi_mul_128_64_low_128_test
    db 'bi_mul_128_64_low_128', 0
    dq __bi_mul_128_128_low_128_test
    db 'bi_mul_128_128_low_128', 0


    dq __bi_mul_256_64_low_256_test
    db 'bi_mul_256_64_low_256', 0
    dq __bi_mul_low_256_128_test
    db 'bi_mul_low_256_128', 0
    dq __bi_mul_256_256_low_256_test
    db 'bi_mul_256_256_low_256', 0

    dq __bi_mul_low_512_64_test
	db 'bi_mul_low_512_64', 0
    dq __bi_mul_low_512_512_test
	db 'bi_mul_low_512_512', 0

dq 0
