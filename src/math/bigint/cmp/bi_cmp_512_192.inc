if ~ definite bi_cmp_512_192

;Compares bi512 to bi192 values
;input
;  rcx - pointer to bi512 left value
;  rdx - pointer to bi192 right value
;output
;  rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_512_192:
    CheckRegAligned rcx, 'bi_cmp_512_192 rcx'
    CheckRegAligned rdx, 'bi_cmp_512_192 rdx'

        mov     rax, [rcx + 56]
        or      rax, [rcx + 48]
        or      rax, [rcx + 40]
        or      rax, [rcx + 32]
        or      rax, [rcx + 24]
        jnz     .greater
        
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