macro BigIntegerDivRem bits {

if ~ definite __bi_div_rem_#bits

include '../src/math/bigint/extend_high/extend_high.inc'

;Divides two bi values
;input
; rax - divident value
; rbx - divisor value
; rdi - quotient value
; rsi - reminder value
__bi_div_rem_#bits:
virtual at rax
  .divident BigInteger#bits
end virtual
virtual at rbx
  .divisor BigInteger#bits
end virtual
virtual at rdi
  .quotient BigInteger#bits
end virtual
virtual at rdi
  .reminder BigInteger#bits
end virtual
        sub     rsp, __BIG_INTEGER_QWORDS_#bits * 2
        mov     rdi, rsp
        call    __bi_extend_high_#bits
        add     rsp, __BIG_INTEGER_QWORDS_#bits * 2
        ret

end if

}