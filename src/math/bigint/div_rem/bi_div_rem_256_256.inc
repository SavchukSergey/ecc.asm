if ~ definite bi_div_rem_256_256

;include 'bi_div_rem_256_256_full_bits.inc'
;bi_div_rem_256_256 equ bi_div_rem_256_256_full_bits

;include 'bi_div_rem_256_256_bits.inc'
;bi_div_rem_256_256 equ bi_div_rem_256_256_bits

include 'bi_div_rem_256_256_guess.inc'
bi_div_rem_256_256 equ bi_div_rem_256_256_guess

end if