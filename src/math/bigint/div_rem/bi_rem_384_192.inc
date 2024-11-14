;Calculates remainder of bi384 dividend by bi192
;input:
;   rcx - pointer to bi384 dividend
;   rdx - pointer to bi192 divisor
;   r8 - pointer to bi192 remainder
bi_rem_384_192:
    RemGuess64 384, 192
