if ~ definite bi_mod_mul_256_256

include '../mul/bi_mul_256_256.inc'
;include '../div_rem/bi_div_rem_512_256.inc'
include '../copy/bi_copy_256.inc'
;todo: for some reason it is slower than sum of bi_mul_256_256, bi_rem_512_256, bi_copy_256
bi_mod_mul_256_256:
virtual at rsp
  label .locals_start
    .left rq 1
    .right rq 1
    .modulus rq 1
    .result rq 1
    .result_512 rb __BIG_INTEGER_BYTES_512
    .reminder_512 rb __BIG_INTEGER_BYTES_512
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.modulus], r8
        mov     [.result], r9

        mov     rcx, [.left]
        mov     rdx, [.right]
        lea     r8, [.result_512]
        call    bi_mul_256_256

        lea     rcx, [.result_512]
        mov     rdx, [.modulus]
        lea     r8, [.reminder_512]
        call    bi_rem_512_256

        mov     rcx, [.result]
        lea     rdx, [.reminder_512]
        call    bi_copy_256

        add     rsp, .locals_end - .locals_start
        ret

end if