if ~ definite bi_mont_ctx_256_redc_256

include '../mul_low/bi_mul_256_256_low_256.inc';
include 'bi_mont_ctx_256.inc';

bi_mont_ctx_256_redc_256:
virtual at rsp
  label .locals_start
    .source_256 rq 1
    .destination rq 1
    .ctx rq 1
    .m_256 BigInteger256
    .temp_1_512 BigInteger512
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.source_256], rcx
        mov     [.destination], rdx
        mov     [.ctx], r8

        mov     rcx, [.source_256]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.mod_inv_r]
        lea     r8, [.m_256]
        call    bi_mul_256_256_low_256

        lea     rcx, [.m_256]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        lea     r8, [.temp_1_512]
        call    bi_mul_256_256

        lea     rcx, [.temp_1_512]
        mov     rdx, [.source_256]
        call    bi_add_assign_512_256
        jc      .norm

        lea     rcx, [.temp_1_512 + 32]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        call    bi_cmp_256_256
        jb      .norm_ok
.norm:
        lea     rcx, [.temp_1_512 + 32]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        call    bi_sub_assign_256_256
.norm_ok:
        mov     rcx, [.destination]
        lea     rdx, [.temp_1_512 + 32]
        call    bi_copy_256

        add     rsp, .locals_end - .locals_start
        ret

end if
