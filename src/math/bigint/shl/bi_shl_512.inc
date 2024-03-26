if ~ definite bi_shl_512

include '../copy/bi_copy_512.inc'
include 'bi_shl_assign_512.inc'

; Shifts left
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shl_512:
        xchg    rcx, rdx
        call    bi_copy_512
        xchg    rcx, rdx

        push    rcx rdx
        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shl_assign_512
        pop     rdx rcx
        ret


end if