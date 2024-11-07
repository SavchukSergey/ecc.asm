if ~ definite bi_cmp_512_320

;Compares bi512 to bi320 values
;input
;  rcx - pointer to left bi512 value
;  rdx - pointer to right bi320 value
;output
;  rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_512_320:
    CheckRegAligned rcx, 'bi_cmp_512_320 rcx'
    CheckRegAligned rdx, 'bi_cmp_512_320 rdx'

        mov     rax, [rcx + 56]
        or      rax, [rcx + 48]
        or      rax, [rcx + 40]
        jnz     .greater

        mov     rax, [rcx + 32]
        cmp     rax, [rdx + 32]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 24]
        cmp     rax, [rdx + 24]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 16]
        cmp     rax, [rdx + 16]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 8]
        cmp     rax, [rdx + 8]
        jb      .less
        ja      .greater

        mov     rax, [rcx]
        cmp     rax, [rdx]
        jb      .less
        ja      .greater

.equal:
        ;keep CPU flags
        mov     rax, 0
        ret
.less:
        ;keep CPU flags
        mov     rax, -1
        ret
.greater:
        ;keep CPU flags
        mov     rax, 1
        ret

end if