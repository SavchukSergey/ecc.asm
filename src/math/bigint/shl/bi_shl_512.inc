if ~ definite bi_shl_512

; Shifts left
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shl_512:
    CheckRegAligned rcx, 'bi_shl_512 rcx'
    CheckRegAligned rdx, 'bi_shl_512 rdx'

        xchg    rcx, rdx
        call    bi_copy_512
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shl_assign_512
        ret

end if