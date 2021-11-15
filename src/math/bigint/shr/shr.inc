macro BigIntegerShr bits {

; Shifts right
;input
; rax - value
__bi_shr_#bits:
virtual at rax
  .value BigInteger#bits
end virtual
        clc
        repeat  __BIG_INTEGER_QWORDS_#bits
        rcr     qword [.value - % * 8 + __BIG_INTEGER_BYTES_#bits], 1
        end repeat
        ret

}