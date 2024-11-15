;Calculates remainder of bi384 dividend by bi384
;input:
;   rcx - pointer to bi384 dividend
;   rdx - pointer to bi384 divisor
;   r8 - pointer to bi384 remainder

bi_rem_384_384:
    RemGuess64 384, 384
