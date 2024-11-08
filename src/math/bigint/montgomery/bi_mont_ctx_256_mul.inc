if ~ definite bi_mont_ctx_256_mul

bi_mont_ctx_256_mul:
virtual at rsp
  label .locals_start
    .ctx rq 1
    .result rq 1
    .temp_512 BigInteger512
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.ctx], r8
        mov     [.result], r9

        lea     r8, [.temp_512]
        call    bi_mul_256_256 

        lea     rcx, [.temp_512]
        mov     rdx, [.result]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_redc_512

        add     rsp, .locals_end - .locals_start
        ret

end if
