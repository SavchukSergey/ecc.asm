include '../src/math/bigint/extend_high/extend_high.inc'

macro BigIntegerExtendHigh2 bits {

if ~ definite __bi_extend_high_2_#bits

;Extends value from smaller bi
;input
; rax - pointer to source value
; output
; rdi - pointer to destination value
__bi_extend_high_2_#bits:
        BigIntegerExtendHighCode bits / 4, bits
end if

}