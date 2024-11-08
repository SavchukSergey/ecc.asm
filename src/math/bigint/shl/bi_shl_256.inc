if ~ definite bi_shl_256

;todo: rcx as target, rdx as input

; Shifts left
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shl_256:
    CheckRegAligned rcx, 'bi_shl_256 rcx'
    CheckRegAligned rdx, 'bi_shl_256 rdx'

        xchg    rcx, rdx
        call    bi_copy_256
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shl_assign_256
        ret

end if