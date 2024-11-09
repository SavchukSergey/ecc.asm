include 'macro/bi_div_rem_guess_64.inc'

; sort by sum of dividend_bits and divisor_bits, then by dividend_bits

;192
include 'bi_div_rem_128_64.inc'

;256
include 'bi_div_rem_128_128.inc'
include 'bi_div_rem_192_64.inc'

;320
include 'bi_div_rem_192_128.inc'
include 'bi_div_rem_256_64.inc'

;384
include 'bi_div_rem_192_192.inc'
include 'bi_div_rem_256_128.inc'
include 'bi_div_rem_320_64.inc'

;448
include 'bi_div_rem_256_192.inc'
include 'bi_div_rem_320_128.inc'
include 'bi_div_rem_384_64.inc'

;512
include 'bi_div_rem_256_256.inc'
include 'bi_div_rem_320_192.inc'
include 'bi_div_rem_384_128.inc'
include 'bi_div_rem_448_64.inc'

;576
include 'bi_div_rem_320_256.inc'
include 'bi_div_rem_384_192.inc'
include 'bi_div_rem_448_128.inc'
include 'bi_div_rem_512_64.inc'

;640
include 'bi_div_rem_320_320.inc'
include 'bi_div_rem_384_256.inc'
include 'bi_div_rem_448_192.inc'
include 'bi_div_rem_512_128.inc'

;704
include 'bi_div_rem_384_320.inc'
include 'bi_div_rem_448_256.inc'
include 'bi_div_rem_512_192.inc'

;768
include 'bi_div_rem_384_384.inc'
include 'bi_div_rem_448_320.inc'
include 'bi_div_rem_512_256.inc'

;832
include 'bi_div_rem_448_384.inc'
include 'bi_div_rem_512_320.inc'

;896
include 'bi_div_rem_448_448.inc'
include 'bi_div_rem_512_384.inc'

;960
include 'bi_div_rem_512_448.inc'

;1024
include 'bi_div_rem_512_512.inc'


; Divide
include 'bi_div_128_64.inc'

; Remainder

;192
include 'bi_rem_128_64.inc'

;256
include 'bi_rem_128_128.inc'
include 'bi_rem_192_64.inc'

;320
include 'bi_rem_192_128.inc'
include 'bi_rem_256_64.inc'

;384
include 'bi_rem_192_192.inc'
include 'bi_rem_256_128.inc'
include 'bi_rem_320_64.inc'

;448
include 'bi_rem_256_192.inc'
include 'bi_rem_320_128.inc'
;include 'bi_rem_384_64.inc'

;512
include 'bi_rem_256_256.inc'
include 'bi_rem_320_192.inc'
;include 'bi_rem_384_128.inc'
;include 'bi_rem_448_64.inc'

;576
include 'bi_rem_320_256.inc'
;include 'bi_rem_384_192.inc'
;include 'bi_rem_448_128.inc'
include 'bi_rem_512_64.inc'

;640
include 'bi_rem_320_320.inc'
;include 'bi_rem_384_256.inc'
;include 'bi_rem_448_192.inc'
include 'bi_rem_512_128.inc'

;704
;include 'bi_rem_384_320.inc'
;include 'bi_rem_448_256.inc'
;include 'bi_rem_512_192.inc'

;768
;include 'bi_rem_384_384.inc'
;include 'bi_rem_448_320.inc'
include 'bi_rem_512_256.inc'

;832
;include 'bi_rem_448_384.inc'
;include 'bi_rem_512_320.inc'

;896
;include 'bi_rem_448_448.inc'
;include 'bi_rem_512_384.inc'

;960
;include 'bi_rem_512_448.inc'

;1024
;include 'bi_rem_512_512.inc'