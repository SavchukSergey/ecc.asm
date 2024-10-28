if ~ definite bi_mont_ctx_256_mul

include 'bi_mont_ctx_256.inc';
include '../mul_low/bi_mul_low_256_256.inc';

bi_mont_ctx_256_mul:
virtual at rsp
  label .locals_start
    .ctx rq 1
    .result rq 1
    .temp BigInteger256
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.ctx], r8
        mov     [.result], r9

        lea     r8, [.temp]
        call    bi_mul_low_256_256             ; trim to lowest 256-bit

        lea     rcx, [.temp]
        mov     rdx, [.result]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_deconvert

        add     rsp, .locals_end - .locals_start
        ret

end if
