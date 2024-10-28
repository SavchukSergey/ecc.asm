if ~ definite bi_mont_ctx_256_square

include 'bi_mont_ctx_256.inc';
include 'bi_mont_ctx_256_redc_512.inc';
include '../square/bi_square_256.inc';

bi_mont_ctx_256_square:
virtual at rsp
  label .locals_start
    .ctx rq 1
    .result rq 1
    .temp_512 BigInteger512
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.ctx], rdx
        mov     [.result], r8

        lea     rdx, [.temp_512]
        call    bi_square_256 

        lea     rcx, [.temp_512]
        mov     rdx, [.result]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_redc_512

        add     rsp, .locals_end - .locals_start
        ret

end if
