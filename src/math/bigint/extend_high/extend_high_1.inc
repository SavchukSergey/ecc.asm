include '../src/math/bigint/extend_high/extend_high.inc'

macro BigIntegerExtendHigh1 bits {

if ~ definite __bi_extend_high_#bits

;Extends value from smaller bi
;input
; rax - pointer to source value
; output
; rdi - pointer to destination value
__bi_extend_high_#bits:
        BigIntegerExtendHighCode bits / 2, bits
end if

}