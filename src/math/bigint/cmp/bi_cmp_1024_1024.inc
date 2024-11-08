if ~ definite bi_cmp_1024_1024

;Compares two bi1024 values
;input
; rcx - left bi1024 value
; rdx - right bi1024 value
; output
; rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_1024_1024:
    CheckRegBi1024Alignment rcx, 'bi_cmp_1024_1024 rcx'
    CheckRegBi1024Alignment rdx, 'bi_cmp_1024_1024 rdx'

        add     rcx, 64
        add     rdx, 64
        call    bi_cmp_512_512
        cmp     rax, 0
        jc      .end_1

        sub     rcx, 64
        sub     rdx, 64
        call    bi_cmp_512_512
        ret
.end_1:
        sub     rcx, 64
        sub     rdx, 64
        ;keep CPU flags
        cmp     rax, 0
        ret
end if
