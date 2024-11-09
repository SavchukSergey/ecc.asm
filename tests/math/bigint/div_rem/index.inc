include 'bi_div_rem_test_macro.inc'
include 'bi_rem_test_macro.inc'

include 'bi_div_rem_test_cases.inc'

include 'bi_div_rem_128_64_test.inc'
include 'bi_div_rem_128_128_test.inc'
include 'bi_div_rem_192_64_test.inc'
include 'bi_div_rem_192_128_test.inc'
include 'bi_div_rem_192_192_test.inc'
include 'bi_div_rem_256_64_test.inc'
include 'bi_div_rem_256_128_test.inc'
include 'bi_div_rem_256_192_test.inc'
include 'bi_div_rem_256_256_test.inc'
include 'bi_div_rem_320_64_test.inc'
include 'bi_div_rem_320_128_test.inc'
include 'bi_div_rem_320_192_test.inc'
include 'bi_div_rem_320_256_test.inc'
include 'bi_div_rem_320_320_test.inc'
include 'bi_div_rem_384_64_test.inc'
include 'bi_div_rem_384_128_test.inc'
include 'bi_div_rem_448_64_test.inc'
include 'bi_div_rem_448_128_test.inc'
include 'bi_div_rem_512_64_test.inc'
include 'bi_div_rem_512_128_test.inc'
include 'bi_div_rem_512_256_test.inc'
;include 'bi_div_rem_512_448_test.inc'
include 'bi_div_rem_512_512_test.inc'

include 'bi_rem_128_64_test.inc'
include 'bi_rem_128_128_test.inc'
include 'bi_rem_192_64_test.inc'
include 'bi_rem_192_128_test.inc'
include 'bi_rem_192_192_test.inc'
include 'bi_rem_256_64_test.inc'
include 'bi_rem_256_128_test.inc'
include 'bi_rem_256_192_test.inc'
include 'bi_rem_256_256_test.inc'
include 'bi_rem_320_64_test.inc'
include 'bi_rem_320_128_test.inc'
include 'bi_rem_320_192_test.inc'
include 'bi_rem_320_256_test.inc'
include 'bi_rem_320_320_test.inc'
include 'bi_rem_512_64_test.inc'
include 'bi_rem_512_128_test.inc'
include 'bi_rem_512_256_test.inc'

align 16
__bi_div_rem_tests:
    dq __bi_div_rem_128_64_test
    db 'bi_div_rem_128_64', 0

    dq __bi_div_rem_128_128_test
    db 'bi_div_rem_128_128', 0

    dq __bi_div_rem_192_64_test
    db 'bi_div_rem_192_64', 0

    dq __bi_div_rem_192_128_test
    db 'bi_div_rem_192_128', 0

    dq __bi_div_rem_192_192_test
    db 'bi_div_rem_192_192', 0

    dq __bi_div_rem_256_64_test
    db 'bi_div_rem_256_64', 0

    dq __bi_div_rem_256_128_test
    db 'bi_div_rem_256_128', 0

    dq __bi_div_rem_256_192_test
    db 'bi_div_rem_256_192', 0

    dq __bi_div_rem_256_256_test
    db 'bi_div_rem_256_256', 0

    dq __bi_div_rem_320_64_test
    db 'bi_div_rem_320_64', 0

    dq __bi_div_rem_320_128_test
    db 'bi_div_rem_320_128', 0

    dq __bi_div_rem_320_192_test
    db 'bi_div_rem_320_192', 0

    dq __bi_div_rem_320_256_test
    db 'bi_div_rem_320_256', 0

    dq __bi_div_rem_320_320_test
    db 'bi_div_rem_320_320', 0
    
    dq __bi_div_rem_384_64_test
    db 'bi_div_rem_384_64', 0
    
    dq __bi_div_rem_384_128_test
    db 'bi_div_rem_384_128', 0

    dq __bi_div_rem_448_64_test
    db 'bi_div_rem_448_64', 0
    
    dq __bi_div_rem_448_128_test
    db 'bi_div_rem_448_128', 0

    dq __bi_div_rem_512_64_test
    db 'bi_div_rem_512_64', 0

    dq __bi_div_rem_512_128_test
    db 'bi_div_rem_512_128', 0

    dq __bi_div_rem_512_256_test
    db 'bi_div_rem_512_256', 0
;
;    dq __bi_div_rem_512_448_test
;    db 'bi_div_rem_512_448', 0

    dq __bi_div_rem_512_512_test
    db 'bi_div_rem_512_512', 0

    dq __bi_rem_128_64_test
    db 'bi_rem_128_64', 0

    dq __bi_rem_128_128_test
    db 'bi_rem_128_128', 0

    dq __bi_rem_192_64_test
    db 'bi_rem_192_64', 0

    dq __bi_rem_192_128_test
    db 'bi_rem_192_128', 0

    dq __bi_rem_192_192_test
    db 'bi_rem_192_192', 0

    dq __bi_rem_256_64_test
    db 'bi_rem_256_64', 0

    dq __bi_rem_256_128_test
    db 'bi_rem_256_128', 0

    dq __bi_rem_256_192_test
    db 'bi_rem_256_192', 0

    dq __bi_rem_256_256_test
    db 'bi_rem_256_256', 0

    dq __bi_rem_320_64_test
    db 'bi_rem_320_64', 0

    dq __bi_rem_320_128_test
    db 'bi_rem_320_128', 0

    dq __bi_rem_320_192_test
    db 'bi_rem_320_192', 0

    dq __bi_rem_320_256_test
    db 'bi_rem_320_256', 0

    dq __bi_rem_320_320_test
    db 'bi_rem_320_320', 0

    dq __bi_rem_512_64_test
    db 'bi_rem_512_64', 0

    dq __bi_rem_512_128_test
    db 'bi_rem_512_128', 0

    dq __bi_rem_512_256_test
    db 'bi_rem_512_256', 0

    dq 0