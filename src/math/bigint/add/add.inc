macro BigIntegerAdd bits {

if ~ definite __bi_add_#bits

;Adds two bi values
;input
; rax - left value
; rbx - right value
; rdi - destination value
__bi_add_#bits:
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
        add     rdx, [.right + (% - 1) * 8]
        else
        adc     rdx, [.right + (% - 1) * 8]
        end if
        mov     [.result + (% - 1) * 8], rdx
        end repeat
        pop     rdx
        ret

;Adds two bi values
;input
; rax - left value and destination
; rbx - right value
__bi_add_assign_#bits:
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
        mov     rdx, [.right + (% - 1) * 8]
        if % = 1
        add     [.left + (% - 1) * 8], rdx
        else
        adc     [.left + (% - 1) * 8], rdx
        end if
        end repeat
        pop     rdx
        ret


end if

}