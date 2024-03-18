if ~ definite bi_cmp_128_128

;Compares two bi values
;input
; rcx - left value
; rdx - right value
; output
; rax - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

bi_cmp_128_128:
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