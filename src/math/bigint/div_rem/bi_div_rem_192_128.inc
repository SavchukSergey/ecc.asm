;Divides bi192 by bi128
;input:
;   rcx - pointer to bi192 divident
;   rdx - pointer to bi128 divisor
;   r8 - pointer to bi192 quotient
;   r9 - pointer to bi128 remainder

if ~ definite bi_div_rem_192_128

include 'bi_div_rem_192_128_guess.inc'

bi_div_rem_192_128 equ bi_div_rem_192_128_guess

end if