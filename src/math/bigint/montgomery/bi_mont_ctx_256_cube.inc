if ~ definite bi_mont_ctx_256_cube

bi_mont_ctx_256_cube:
virtual at rsp
  label .locals_start
    .ctx rq 1
    .source rq 1
    .result rq 1
    .temp BigInteger256
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.source], rcx
        mov     [.ctx], rdx
        mov     [.result], r8

        mov     rcx, [.source]
        mov     rdx, [.ctx]
        lea     r8, [.temp]
        call    bi_mont_ctx_256_square

        mov     rcx, [.source]
        lea     rdx, [.temp]
        mov     r8, [.ctx]
        mov     r9, [.result]
        call    bi_mont_ctx_256_mul

        add     rsp, .locals_end - .locals_start
        ret

end if
