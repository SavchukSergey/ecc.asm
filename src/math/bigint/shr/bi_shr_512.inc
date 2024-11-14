;Shifts right bi512 value
;input:
;  rcx - pointer to source bi512 value
;  rdx - pointer to target bi512 value
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
