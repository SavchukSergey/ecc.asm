if ~ definite bi_mul_256_128

include '../add/bi_add_assign_512_512.inc'
include '../add/bi_add_assign_320_256.inc'
include '../mul/bi_mul_128_128.inc'
include '../zero/bi_zero_512.inc'

;Multiplies bi256 value by bi128 value
;input
;  rcx - left bi256 value
;  rdx - right bi128 value
;  r8 - result bi512 value
bi_mul_256_128____128_128:
virtual at rsp
.locals_start:
  .z0 BigInteger256
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mul_256_128'
    CheckRegAligned rcx, 'bi_mul_256_128 rcx'
    CheckRegAligned rdx, 'bi_mul_256_128 rdx'
    CheckRegAligned r8, 'bi_mul_256_128 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

;todo: clean upper only, bi_extend_assign_256_128?
        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        call    bi_zero_256

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_128_128

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        lea     r8, [.z0]
        call    bi_mul_128_128

;result will never exceed 384 so it is safe to use 256-bit addition here
;todo: Check everywhere
        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        lea     rdx, [.z0]
        call    bi_add_assign_256_256

        add     rsp, .locals_end - .locals_start
        ret



;Multiplies bi256 value by bi128 value
;input
;  rcx - left bi256 value
;  rdx - right bi128 value
;  r8 - result bi512 value
bi_mul_256_128____256_64:
virtual at rsp
.locals_start:
  .temp BigInteger512
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mul_256_128'
    CheckRegAligned rcx, 'bi_mul_256_128 rcx'
    CheckRegAligned rdx, 'bi_mul_256_128 rdx'
    CheckRegAligned r8, 'bi_mul_256_128 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx]
        mov     r8, [.result]
        call    bi_mul_256_64

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx + 8]
        lea     r8, [.temp]
        call    bi_mul_256_64

        mov     rcx, [.result]
        add     rcx, 8
        lea     rdx, [.temp]
        call    bi_add_assign_320_256

        add     rsp, .locals_end - .locals_start
        ret

bi_mul_256_128 = bi_mul_256_128____256_64

end if