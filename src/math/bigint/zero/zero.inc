include '../src/mem/zero_static.inc'

macro BigIntegerZero bits {

if ~ definite __bi_zero_#bits

;Zeroes bi value
;input
; rax - integer to zero
__bi_zero_#bits:
        MemoryZeroStatic rax, __BIG_INTEGER_BYTES_#bits
        ret

end if

}