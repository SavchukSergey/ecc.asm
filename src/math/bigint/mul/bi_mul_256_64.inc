if ~ definite bi_mul_256_64

;Multiplies bi256 by u64
;input
; rcx - left bi256 value
; rdx - right u64 value
; r8 - result bi512 value
bi_mul_256_64:
virtual at rsp
.locals_start:
  .left rq 1
  .right rq 1
  .result rq 1
  .z0 rb __BIG_INTEGER_BYTES_512
  .z1 rb __BIG_INTEGER_BYTES_512
  .z2 rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_512
        lea     rcx, [.z0]
        call    bi_zero_512
        lea     rcx, [.z1]
        call    bi_zero_512
        lea     rcx, [.z2]
        call    bi_zero_512

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

        mov     rcx, [.left]
        mov     rcx, [rcx + 16]
        mov     rdx, [.right]
        lea     r8, [.z1 + 16]
        call    bi_mul_64_64

        mov     rcx, [.left]
        mov     rcx, [rcx + 24]
        mov     rdx, [.right]
        lea     r8, [.z2 + 24]
        call    bi_mul_64_64

        mov     rcx, [.result]
        lea     rdx, [.z0]
        call    bi_add_assign_512_512

        mov     rcx, [.result]
        lea     rdx, [.z1]
        call    bi_add_assign_512_512

        mov     rcx, [.result]
        lea     rdx, [.z2]
        call    bi_add_assign_512_512

        add     rsp, .locals_end - .locals_start
        ret
end if