;Divides bi256 by bi128
;input:
;   rcx - pointer to bi256 divident
;   rdx - pointer to bi128 divisor
;   r8 - pointer to bi256 quotient
;   r9 - pointer to bi128 remainder

include 'bi_div_rem_256_128_guess.inc'

bi_div_rem_256_128 equ bi_div_rem_256_128_guess