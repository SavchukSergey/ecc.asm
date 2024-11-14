;Divides bi256 by bi256
;input:
;   rcx - pointer to bi256 divident
;   rdx - pointer to bi256 divisor
;   r8 - pointer to bi256 quotient
;   r9 - pointer to bi256 remainder

;include 'bi_div_rem_256_256_full_bits.inc'
;bi_div_rem_256_256 equ bi_div_rem_256_256_full_bits

;include 'bi_div_rem_256_256_bits.inc'
;bi_div_rem_256_256 equ bi_div_rem_256_256_bits

include 'bi_div_rem_256_256_guess.inc'
bi_div_rem_256_256 equ bi_div_rem_256_256_guess