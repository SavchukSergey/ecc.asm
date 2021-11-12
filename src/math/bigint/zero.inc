macro BigIntegerZero bits {

;Zeroes bi value
;input
; rax - integer to zero
__bi_zero_#bits:
virtual at rax
  .value BigInteger#bits
end virtual
        push    rbx
        xor     rbx, rbx
        repeat  __BIG_INTEGER_QWORDS_#bits
        mov     [.value + (% - 1) * 8], rbx
        end repeat
        pop     rbx
        ret

}