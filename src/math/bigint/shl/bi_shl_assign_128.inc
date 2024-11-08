if ~ definite bi_shl_assign_128

; Shifts left
;input
;  rcx - pointer to bi128
;  rdx - bits count
bi_shl_assign_128:
    CheckRegBi128Alignment rcx, 'bi_shl_assign_128 rcx'
        mov     r8, [rcx + 0]
        mov     r9, [rcx + 8]
        xor     rax, rax

        cmp     rdx, 128
        cmovae  r9, r8
        cmovae  r8, rax

        cmp     rdx, 64
        cmovae  r9, r8
        cmovae  r8, rax

        xchg    rcx, rdx

        shld    r9, r8, cl
        shl     r8, cl

        mov     [rdx + 8], r9
        mov     [rdx + 0], r8

        ret

end if