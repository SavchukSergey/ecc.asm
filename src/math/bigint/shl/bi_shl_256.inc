if ~ definite bi_shl_256

include '../copy/bi_copy_256.inc'

; Shifts left
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shl_256:
        xchg    rcx, rdx
        call    bi_copy_256
        xchg    rcx, rdx

        push    rcx rdx
        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shl_assign_256
        pop     rdx rcx
        ret


end if