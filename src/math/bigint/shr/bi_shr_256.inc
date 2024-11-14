;Shifts right bi256 value
;input:
;  rcx - pointer to source bi256 value
;  rdx - pointer to target bi256 value
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