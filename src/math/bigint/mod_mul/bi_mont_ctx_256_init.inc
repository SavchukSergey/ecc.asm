if ~ definite bi_mont_ctx_256_init

bi_mont_ctx_256_init:
virtual at rsp
  label .locals_start
    .modulus rq 1
    .ctx rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.modulus], rcx
        mov     [.ctx], rdx

        mov     rcx, [.ctx]
        lea     rcx, [rcx + MontgomeryContext256.modulus]
        mov     rdx, [.modulus]
        call    bi_copy_256

        mov     rcx, [.ctx]
        lea     rcx, [rcx + MontgomeryContext256.r]
        call    bi_zero_512
        mov     rcx, [.ctx]
        mov     qword [rcx + 32], 1

;todo:

        add     rsp, .locals_end - .locals_start
        ret

end if
