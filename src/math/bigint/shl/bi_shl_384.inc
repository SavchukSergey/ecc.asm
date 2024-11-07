if ~ definite bi_shl_384

include '../copy/bi_copy_384.inc'
include 'bi_shl_assign_384.inc'

; Shifts left
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shl_384:
    CheckRegAligned rcx, 'bi_shl_384 rcx'
    CheckRegAligned rdx, 'bi_shl_384 rdx'

        xchg    rcx, rdx
        call    bi_copy_384
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shl_assign_384
        ret

end if