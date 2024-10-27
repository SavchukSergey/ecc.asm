if ~ definite bi_mont_ctx_256_deconvert

include 'bi_mont_ctx_256.inc';

bi_mont_ctx_256_deconvert:
virtual at rsp
  label .locals_start
    .source rq 1
    .destination rq 1
    .ctx rq 1
    BigInteger256 .temp
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.source], rcx
        mov     [.destination], rdx
        mov     [.ctx], r8

        lea     rcx, [.temp]
        mov     rdx, [.source]
        call    bi_copy_256

        lea     rcx, [.temp]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        call    bi_cmp_256_256
        jb      .norm_ok
        lea     rcx, [.temp]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        call    bi_sub_assign_256_256
.norm_ok:
        mov     rcx, [.source]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.rm]
        mov     r8, [.ctx]
        lea     r8, [r8 + MontgomeryContext256.modulus]
        mov     r9, [.destination]
        call    bi_mod_mul_256_256

        add     rsp, .locals_end - .locals_start
        ret

end if
