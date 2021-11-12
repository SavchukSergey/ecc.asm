macro BigIntegerSub bits {

;Subs two bi values
;input
; rax - left value
; rbx - right value
; rdi - destination value
__bi_sub_#bits:
virtual at rax
  .left BigInteger#bits
end virtual
virtual at rbx
  .right BigInteger#bits
end virtual
virtual at rdi
  .result BigInteger#bits
end virtual
        push    rdx
        clc
        repeat  __BIG_INTEGER_QWORDS_#bits
        mov     rdx, [.left + (% - 1) * 8]
        sbb     rdx, [.right + (% - 1) * 8]
        mov     [.result + (% - 1) * 8], rdx
        end repeat
        pop     rdx
        ret

}