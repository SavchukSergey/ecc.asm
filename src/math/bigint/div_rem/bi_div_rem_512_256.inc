if ~ definite bi_div_rem_512_256

include 'bi_div_rem_512_256_guess.inc'
include 'bi_div_rem_512_256_bits.inc'

bi_div_rem_512_256 equ bi_div_rem_512_256_guess
;bi_div_rem_512_256 equ bi_div_rem_512_256_bits

end if