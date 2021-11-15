macro BigIntegerShl bits {

if ~ definite __bi_shl_#bits

; Shifts right
;input
; rax - value
__bi_shl_#bits:
virtual at rax
  .value BigInteger#bits
end virtual
        clc
        repeat  __BIG_INTEGER_QWORDS_#bits
        rcl     qword [.value + (% - 1) * 8], 1
        end repeat
        ret

end if
}