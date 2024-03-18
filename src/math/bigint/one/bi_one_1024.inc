if ~ definite bi_one_1024

include '../zero/bi_zero_512.inc'
include 'bi_one_512.inc'

;Sets 1 to bi1024 value
;input
; rcx - pointer to result
bi_one_1024:
        call    bi_one_512
        add     rcx, 64
        call    bi_zero_512
        sub     rcx, 64
        ret
end if