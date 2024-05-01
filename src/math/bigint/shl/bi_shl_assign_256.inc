if ~ definite bi_shl_assign_256

bi_shl_assign_256:

    CheckRegBi256Alignment rcx, 'bi_shr_assign_256 rcx'
;todo: it is full of write-after-read hazards, may work slower
        push    r10 r11

        mov     r8, [rcx]
        mov     r9, [rcx + 8]
        mov     r10, [rcx + 16]
        mov     r11, [rcx + 24]

        xor     rax, rax

        cmp     rdx, 256
        cmovae  r11, rax
        cmovae  r10, rax
        cmovae  r9, rax
        cmovae  r8, rax

        test    rdx, 128
        cmovnz  r11, r9
        cmovnz  r10, r8
        cmovnz  r9, rax
        cmovnz  r8, rax

        test    rdx, 64
        cmovnz  r11, r10
        cmovnz  r10, r9
        cmovnz  r9, r8
        cmovnz  r8, rax


        and     rdx, 0x3f
        xchg    rcx, rdx

        shld    r11, r10, cl
        shld    r10, r9, cl
        shld    r9, r8, cl
        shl     r8, cl

        mov     [rdx + 0], r8
        mov     [rdx + 8], r9
        mov     [rdx + 16], r10
        mov     [rdx + 24], r11

        pop     r11 r10
        ret

end if