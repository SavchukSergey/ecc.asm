;Shifts right bi128 value
;input:
;  rcx - pointer to source bi128 value
;  rdx - pointer to target bi128 value
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