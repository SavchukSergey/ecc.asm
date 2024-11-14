;Multiplies two bi256 values
;input:
; rcx - pointer to left bi256 value
; rdx - pointer to right bi256 value
; r8 - pointer to result bi512 value

bi_mul_256_256____128_128:
virtual at rsp
.locals_start:
  .temp BigInteger256
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mul_256_256'
        CheckRegBi256Alignment rcx, 'bi_mul_256_256 rcx'
        CheckRegBi256Alignment rdx, 'bi_mul_256_256 rdx'
        CheckRegBi512Alignment r8, 'bi_mul_256_256 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_512

; b * d (256 bit)
        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_128_128

; b * c (256 bit)
        mov     rcx, [.left]
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_256 / 2
        lea     r8, [.temp]
        call    bi_mul_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_384_256

; a * d (256 bit)
        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_384_256

; a * c (256 bit)
        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_256 / 2
        lea     r8, [.temp]
        call    bi_mul_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_256_256

        add     rsp, .locals_end - .locals_start
        ret

bi_mul_256_256____256_64:
virtual at rsp
.locals_start:
  .temp BigInteger320
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mul_256_128'
    CheckRegBi256Alignment rcx, 'bi_mul_256_128 rcx'
    CheckRegBi256Alignment rdx, 'bi_mul_256_128 rdx'
    CheckRegBi512Alignment r8, 'bi_mul_256_128 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        mov     qword [rcx + 40], 0
        mov     qword [rcx + 48], 0
        mov     qword [rcx + 56], 0

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

; result is 384 bit wide (256bit * 64bit * 64bit)
        mov     rcx, [.result]
        add     rcx, 8
        lea     rdx, [.temp]
        call    bi_add_assign_320_320


        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx + 16]
        lea     r8, [.temp]
        call    bi_mul_256_64

; result is 448 bit wide (256bit * 64bit * 64bit * 64bit)
        mov     rcx, [.result]
        add     rcx, 16
        lea     rdx, [.temp]
        call    bi_add_assign_384_320


        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx + 24]
        lea     r8, [.temp]
        call    bi_mul_256_64

        mov     rcx, [.result]
        add     rcx, 24
        lea     rdx, [.temp]
        call    bi_add_assign_320_320


        add     rsp, .locals_end - .locals_start
        ret

bi_mul_256_256 = bi_mul_256_256____256_64
