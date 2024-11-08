if ~ definite bi_shr_128

; Shifts right
;input
;  rcx - source value
;  rdx - target value
;  r8 - bits
bi_shr_128:
    CheckRegBi128Alignment rcx, 'bi_shr_128 rcx'
    CheckRegBi128Alignment rdx, 'bi_shr_128 rdx'

        xchg    rcx, rdx
        call    bi_copy_128
        xchg    rcx, rdx

        mov     rcx, rdx
        mov     rdx, r8
        call    bi_shr_assign_128
        ret

end if