if ~ definite bi_shr_assign_128

; Shifts right
;input
;  rcx - pointer to bi128
;  rdx - bits count
bi_shr_assign_128:
    CheckRegBi128Alignment rcx, 'bi_shr_assign_128 rcx'
        mov     r8, [rcx + 0]
        mov     r9, [rcx + 8]
        xor     rax, rax

        cmp     rdx, 128
        cmovae  r8, r9
        cmovae  r9, rax

        cmp     rdx, 64
        cmovae  r8, r9
        cmovae  r9, rax

        and     rdx, 0x3f

        xchg    rcx, rdx

        shrd    r8, r9, cl
        shr     r9, cl

        mov     [rdx + 0], r8
        mov     [rdx + 8], r9

        ret

end if