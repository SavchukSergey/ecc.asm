if ~ definite bi_shl_128

; Shifts left
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shl_128:
    CheckRegAligned rcx, 'bi_shl_128 rcx'
    CheckRegAligned rdx, 'bi_shl_128 rdx'

        xchg    rcx, rdx
        call    bi_copy_128
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shl_assign_128
        ret

end if