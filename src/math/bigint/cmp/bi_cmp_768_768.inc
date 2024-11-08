if ~ definite bi_cmp_768_768

;Compares two bi768 values
;input
;  rcx - pointer to left bi768 value
;  rdx - pointer to right bi768 value
;output
;  rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_768_768:
    CheckRegBi768Alignment rcx, 'bi_cmp_768_768 rcx'
    CheckRegBi768Alignment rdx, 'bi_cmp_768_768 rdx'

        mov     rax, [rcx + 88]
        cmp     rax, [rdx + 88]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 80]
        cmp     rax, [rdx + 80]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 72]
        cmp     rax, [rdx + 72]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 64]
        cmp     rax, [rdx + 64]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 56]
        cmp     rax, [rdx + 56]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 48]
        cmp     rax, [rdx + 48]
        jb      .less
        ja      .greater

        mov     rax, [rcx + 40]
        cmp     rax, [rdx + 40]
        jb      .less
        ja      .greater

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