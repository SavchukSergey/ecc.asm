if ~ definite bi_div_rem_256_192

;include 'bi_div_rem_256_192_full_bits.inc'
;bi_div_rem_256_192 equ bi_div_rem_256_192_full_bits

;include 'bi_div_rem_256_192_bits.inc'
;bi_div_rem_256_192 equ bi_div_rem_256_192_bits

include 'bi_div_rem_256_192_guess.inc'
bi_div_rem_256_192 equ bi_div_rem_256_192_guess

end if