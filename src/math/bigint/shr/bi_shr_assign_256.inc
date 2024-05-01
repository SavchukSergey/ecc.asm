if ~ definite bi_shr_assign_256

bi_shr_assign_256:

    CheckRegBi256Alignment rcx, 'bi_shr_assign_256 rcx'
;todo: it is full of write-after-read hazards, may work slower
        push    r10 r11

        mov     r8, [rcx]
        mov     r9, [rcx + 8]
        mov     r10, [rcx + 16]
        mov     r11, [rcx + 24]

        xor     rax, rax

        cmp     rdx, 256
        cmovae  r8, rax
        cmovae  r9, rax
        cmovae  r10, rax
        cmovae  r11, rax

        test    rdx, 128
        cmovnz  r8, r10
        cmovnz  r9, r11
        cmovnz  r10, rax
        cmovnz  r11, rax

        test    rdx, 64
        cmovnz  r8, r9
        cmovnz  r9, r10
        cmovnz  r10, r11
        cmovnz  r11, rax


        and     rdx, 0x3f
        xchg    rcx, rdx

        shrd    r8, r9, cl
        shrd    r9, r10, cl
        shrd    r10, r11, cl
        shr     r11, cl

        mov     [rdx + 0], r8
        mov     [rdx + 8], r9
        mov     [rdx + 16], r10
        mov     [rdx + 24], r11

        pop     r11 r10
        ret

end if