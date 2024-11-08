include 'bi_mont_ctx_256_convert_test.inc'
include 'bi_mont_ctx_256_init_test.inc'
include 'bi_mont_ctx_256_mul_test.inc'
include 'bi_mont_ctx_256_pow_test.inc'
include 'bi_mont_ctx_256_redc_256_test.inc'
include 'bi_mont_ctx_256_redc_512_test.inc'
include 'bi_mont_ctx_256_square_test.inc'

align 16
__bi_mont_tests:
    dq __bi_mont_ctx_256_init_test
    db 'bi_mont_ctx_256_init', 0
    dq __bi_mont_ctx_256_convert_test
    db 'bi_mont_ctx_256_convert', 0
    dq __bi_mont_ctx_256_redc_256_test
    db 'bi_mont_ctx_256_redc_256', 0
    dq __bi_mont_ctx_256_redc_512_test
    db 'bi_mont_ctx_256_redc_512', 0
    dq __bi_mont_ctx_256_mul_test
    db 'bi_mont_ctx_256_mul', 0
    dq __bi_mont_ctx_256_square_test
    db 'bi_mont_ctx_256_square', 0
    dq __bi_mont_ctx_256_pow_test
    db 'bi_mont_ctx_256_pow', 0

dq 0