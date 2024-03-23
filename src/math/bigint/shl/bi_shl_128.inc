if ~ definite bi_shl_128

include '../copy/bi_copy_128.inc'
include 'bi_shl_assign_128.inc'

; Shifts left
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shl_128:
        xchg    rcx, rdx
        call    bi_copy_128
        xchg    rcx, rdx

        push    rcx rdx
        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shl_assign_128
        pop     rdx rcx
        ret


end if