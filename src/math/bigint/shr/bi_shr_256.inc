if ~ definite bi_shr_256

; Shifts right
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shr_256:
    CheckRegAligned rcx, 'bi_shr_256 rcx'
    CheckRegAligned rdx, 'bi_shr_256 rdx'

        xchg    rcx, rdx
        call    bi_copy_256
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shr_assign_256
        ret

end if