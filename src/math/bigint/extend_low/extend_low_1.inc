include '../../../mem/copy_static.inc'
include '../../../mem/zero_static.inc'

macro BigIntegerExtendLow1 bits {

if ~ definite __bi_extend_low_1_#bits

;Extends value from smaller bi
;input
; rax - source value
; rdi - destination value
__bi_extend_low_1_#bits:
        MemoryCopyStatic rax, rdi, __BIG_INTEGER_BYTES_#bits
        MemoryZeroStatic rdi + __BIG_INTEGER_BYTES_#bits, __BIG_INTEGER_BYTES_#bits
        ret
        
end if

}