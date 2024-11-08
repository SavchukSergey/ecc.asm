include 'bi_rnd_test_macro.inc'

include 'bi_rnd_64_test.inc'
include 'bi_rnd_128_test.inc'
include 'bi_rnd_192_test.inc'
include 'bi_rnd_256_test.inc'
include 'bi_rnd_320_test.inc'
include 'bi_rnd_384_test.inc'
include 'bi_rnd_448_test.inc'
include 'bi_rnd_512_test.inc'
;include 'bi_rnd_1024_test.inc'

align 16
__bi_rnd_tests:
    dq __bi_rnd_64_test
    db 'bi_rnd_64', 0

    dq __bi_rnd_128_test
    db 'bi_rnd_128', 0

    dq __bi_rnd_192_test
    db 'bi_rnd_192', 0

    dq __bi_rnd_256_test
    db 'bi_rnd_256', 0

    dq __bi_rnd_320_test
    db 'bi_rnd_320', 0

    dq __bi_rnd_384_test
    db 'bi_rnd_384', 0

    dq __bi_rnd_448_test
    db 'bi_rnd_448', 0

    dq __bi_rnd_512_test
    db 'bi_rnd_512', 0

;    dq __bi_rnd_1024_test
;    db 'bi_rnd_1024', 0

    dq 0