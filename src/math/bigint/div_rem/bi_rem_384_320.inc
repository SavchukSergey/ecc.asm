;Calculates remainder of bi384 dividend by bi320
;input:
;   rcx - pointer to bi384 dividend
;   rdx - pointer to bi320 divisor
;   r8 - pointer to bi320 remainder

bi_rem_384_320:
    RemGuess64 384, 320
