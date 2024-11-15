;Calculates remainder of bi384 dividend by bi256
;input:
;   rcx - pointer to bi384 dividend
;   rdx - pointer to bi256 divisor
;   r8 - pointer to bi256 remainder

bi_rem_384_256:
    RemGuess64 384, 256
