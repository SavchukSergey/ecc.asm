if ~ definite bi_mul_128_64

;Multiplies bi128 by u64
;input
; rcx - left bi128 value
; rdx - right u64 value
; r8 - result bi256 value
bi_mul_128_64:
virtual at rsp
.locals_start:
  .left rq 1
  .right rq 1
  .result rq 1
  .z0 rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_256
        lea     rcx, [.z0]
        call    bi_zero_256

        mov     rcx, [.left]
        mov     rcx, [rcx + 0]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_64_64

        mov     rcx, [.left]
        mov     rcx, [rcx + 8]
        mov     rdx, [.right]
        lea     r8, [.z0 + 8]
        call    bi_mul_64_64

        mov     rcx, [.result]
        lea     rdx, [.z0]
        call    bi_add_assign_256_256

        leave
        ret
end if