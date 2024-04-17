if ~ definite bi_shr_128

include '../copy/bi_copy_128.inc'
include 'bi_shr_assign_128.inc'

; Shifts right
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shr_128:
    CheckRegAligned rcx, 'bi_shr_128 rcx'
    CheckRegAligned rdx, 'bi_shr_128 rdx'

        xchg    rcx, rdx
        call    bi_copy_128
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shr_assign_128
        ret

end if