include '../src/math/bigint/extend_low/extend_low.inc'

macro BigIntegerExtendLow1 bits {

if ~ definite __bi_extend_low_#bits

;Extends value from smaller bi
;input
; rax - pointer to source value
; output
; rdi - pointer to destination value
__bi_extend_low_#bits:
        BigIntegerExtendLowCode (bits) / 2, bits
end if

}