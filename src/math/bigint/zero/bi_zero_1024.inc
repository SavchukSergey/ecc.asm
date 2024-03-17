if ~ definite bi_zero_1024

include 'bi_zero_512.inc'

;Zeroes bi1024 value
;input
; rcx - pointer to result
bi_zero_1024:
        call    bi_zero_512
        add     rcx, 64
        call    bi_zero_512
        sub     rcx, 64
        ret
end if