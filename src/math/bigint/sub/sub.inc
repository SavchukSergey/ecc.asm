macro BigIntegerSub bits {

if ~ definite __bi_sub_#bits

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
        repeat  __BIG_INTEGER_QWORDS_#bits
        mov     rdx, [.left + (% - 1) * 8]
        if % = 1
        sub     rdx, [.right + (% - 1) * 8]
        else
        sbb     rdx, [.right + (% - 1) * 8]
        end if
        mov     [.result + (% - 1) * 8], rdx
        end repeat
        pop     rdx
        ret

;Subs two bi values
;input
; rax - left value and destination
; rbx - right value
; rdi - destination value
__bi_sub_assign_#bits:
virtual at rax
  .left BigInteger#bits
end virtual
virtual at rbx
  .right BigInteger#bits
end virtual
        push    rdx
        repeat  __BIG_INTEGER_QWORDS_#bits
        mov     rdx, [.right + (% - 1) * 8]
        if % = 1
        sub     [.left + (% - 1) * 8], rdx
        else
        sbb     [.left + (% - 1) * 8], rdx
        end if
        end repeat
        pop     rdx
        ret

end if

}