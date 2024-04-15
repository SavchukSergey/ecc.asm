if ~ definite bi_div_rem_512_128

include 'bi_div_rem_512_128_guess.inc'
include 'bi_div_rem_512_128_dac.inc'

;bi_div_rem_512_128 equ bi_div_rem_512_128_guess
bi_div_rem_512_128 equ bi_div_rem_512_128_dac

end if