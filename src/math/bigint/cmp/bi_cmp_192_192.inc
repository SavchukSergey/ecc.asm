if ~ definite bi_cmp_192_192

;Compares two bi192 values
;input
;  rcx - pointer to left bi192 value
;  rdx - pointer to right bi192 value
;output
;  rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_192_192:
    CheckRegAligned rcx, 'bi_cmp_192_192 rcx'
    CheckRegAligned rdx, 'bi_cmp_192_192 rdx'

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