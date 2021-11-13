macro BigIntegerCmp bits {

;Compares two bi values
;input
; rax - left value
; rbx - right value
; output
; rax - sign: 0 values are equal, 1 left value is gerater then right value, -1 otherwise
__bi_cmp_#bits:
virtual at rax
  .left BigInteger#bits
end virtual
virtual at rbx
  .right BigInteger#bits
end virtual
        push    rdx
        repeat  __BIG_INTEGER_QWORDS_#bits
        mov     rdx, [.left + __BIG_INTEGER_BYTES_#bits - % * 8]
        cmp     rdx, [.right + __BIG_INTEGER_BYTES_#bits - % * 8]
        jb      .less
        ja      .greater
        end repeat
.equal:
        ;keep CPU flags
        pop     rdx
        mov     rax, 0
        ret
.less:
        ;keep CPU flags
        pop     rdx
        mov     rax, -1
        ret
.greater:
        ;keep CPU flags
        pop     rdx
        mov     rax, 1
        ret

}