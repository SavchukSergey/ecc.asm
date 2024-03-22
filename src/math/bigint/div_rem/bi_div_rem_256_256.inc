if ~ definite bi_div_rem_256_256

include 'bi_div_rem_256_256_full_bits.inc'
include 'bi_div_rem_256_256_guess.inc'

bi_div_rem_256_256 equ bi_div_rem_256_256_full_bits
;todo: switch to bi_div_rem_256_256_guess. It provided 10x better performance

end if