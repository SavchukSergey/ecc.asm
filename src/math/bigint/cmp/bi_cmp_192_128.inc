if ~ definite bi_cmp_192_128

;Compares bi192 to bi128 values
;input
;  rcx - pointer to bi192 left value
;  rdx - pointer to bi128 right value
;output
;  rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_192_128:
    CheckRegAligned rcx, 'bi_cmp_192_128 rcx'
    CheckRegAligned rdx, 'bi_cmp_192_128 rdx'

        cmp     qword [rcx + 16], 0
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