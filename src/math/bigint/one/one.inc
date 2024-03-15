include '../../../mem/zero_static.inc'

macro BigIntegerOne bits {

if ~ definite __bi_one_#bits

;Ones bi value
;input
; rax - integer to set to one
__bi_one_#bits:
        mov     qword [rax], 0x01
        MemoryZeroStatic rax + 8, __BIG_INTEGER_BYTES_#bits - 8
        ret

end if

}