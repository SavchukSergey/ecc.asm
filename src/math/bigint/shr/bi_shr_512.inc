if ~ definite bi_shr_512

; Shifts right
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shr_512:
    CheckRegAligned rcx, 'bi_shr_512 rcx'
    CheckRegAligned rdx, 'bi_shr_512 rdx'

        xchg    rcx, rdx
        call    bi_copy_512
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shr_assign_512
        ret

end if