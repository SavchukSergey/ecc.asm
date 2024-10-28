if ~ definite bi_mont_ctx_256_mul

include 'bi_mont_ctx_256.inc';
include '../mul/bi_mul_256_256.inc';

bi_mont_ctx_256_mul:
virtual at rsp
  label .locals_start
    .left rq 1
    .right rq 1
    .ctx rq 1
    .result rq 1
    .temp_512 BigInteger512
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.ctx], r8
        mov     [.result], r9

        mov     rcx, [.left]
        mov     rdx, [.right]
        lea     r8, [.temp_512]
        call    bi_mul_256_256

        lea     rcx, [.temp_512]             ; trim to lowest 256-bit
        mov     rdx, [.result]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_deconvert

        add     rsp, .locals_end - .locals_start
        ret

end if
