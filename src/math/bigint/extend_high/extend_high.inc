include '../../../mem/copy_static.inc'
include '../../../mem/zero_static.inc'

macro BigIntegerExtendHigh bits {

if ~ definite __bi_extend_high_#bits

;Extend to high
;input
; rax - source value
; rdi - destination value
__bi_extend_high_#bits:
        MemoryZeroStatic rdi, __BIG_INTEGER_BYTES_#bits
        MemoryCopyStatic rax, rdi + __BIG_INTEGER_BYTES_#bits, __BIG_INTEGER_BYTES_#bits
        ret

end if

}