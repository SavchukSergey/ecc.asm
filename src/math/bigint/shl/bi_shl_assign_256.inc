if ~ definite bi_shl_assign_256

bi_shl_assign_256:

    CheckRegBi256Alignment rcx, 'bi_shr_assign_256 rcx'
;todo: it is full of write-after-read hazards, may work slower
        push    rbx r10 r11

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

;todo: avx2

        and     rdx, 0x3f
        xchg    rcx, rdx

        mov     bl, 64
        mov     bh, cl
        sub     bl, cl
 
        shl     r11, cl
        bextr   rax, r10, rbx
        or      r11, rax
        ; shld    r11, r10, cl
        
        shl     r10, cl
        bextr   rax, r9, rbx
        or      r10, rax
        ; shld    r10, r9, cl

        shl     r9, cl
        bextr   rax, r8, rbx
        or      r9, rax
        ; shld    r9, r8, cl

        shl     r8, cl

        mov     [rdx + 0], r8
        mov     [rdx + 8], r9
        mov     [rdx + 16], r10
        mov     [rdx + 24], r11

        pop     r11 r10 rbx
        ret

end if