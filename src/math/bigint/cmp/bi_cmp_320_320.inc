;Compares two bi320 values
;input:
;  rcx - pointer to left bi320 value
;  rdx - pointer to right bi320 value
;output:
;  rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_320_320:
    CheckRegBi320Alignment rcx, 'bi_cmp_320_320 rcx'
    CheckRegBi320Alignment rdx, 'bi_cmp_320_320 rdx'

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