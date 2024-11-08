if ~ definite bi_shl_assign_192

bi_shl_assign_192:
;todo: it is full of write-after-read hazards, may work slower
        push    r10

        mov     r8, [rcx]
        mov     r9, [rcx + 8]
        mov     r10, [rcx + 16]

        xor     rax, rax
        
        cmp     rdx, 64
        cmovae  r10, r9
        cmovae  r9, r8
        cmovae  r8, rax

        cmp     rdx, 128
        cmovae  r10, r9
        cmovae  r9, r8
        cmovae  r8, rax

        cmp     rdx, 192
        cmovae  r10, rax
        cmovae  r9, rax
        cmovae  r8, rax

        and     rdx, 0x3f
        xchg    rcx, rdx

        shld    r10, r9, cl
        shld    r9, r8, cl
        shl     r8, cl

        mov     [rdx + 0], r8
        mov     [rdx + 8], r9
        mov     [rdx + 16], r10

        pop     r10
        ret

end if