;Compares bi448 to bi128 values
;input:
;  rcx - pointer to bi448 left value
;  rdx - pointer to bi128 right value
;output:
;  rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_448_128:
    CheckRegBi448Alignment rcx, 'bi_cmp_448_128 rcx'
    CheckRegBi128Alignment rdx, 'bi_cmp_448_128 rdx'

        mov     rax, [rcx + 48]
        or      rax, [rcx + 40]
        or      rax, [rcx + 32]
        or      rax, [rcx + 24]
        or      rax, [rcx + 16]
        jnz     .greater

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