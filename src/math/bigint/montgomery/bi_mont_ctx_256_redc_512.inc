if ~ definite bi_mont_ctx_256_redc_512

include '../mul_low/bi_mul_256_256_low_256.inc';
include 'bi_mont_ctx_256.inc';

bi_mont_ctx_256_redc_512:
virtual at rsp
  label .locals_start
    .source_512 rq 1
    .destination rq 1
    .ctx rq 1
    .m_256 BigInteger256
    .t_512 BigInteger512
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     [.source_512], rcx
        mov     [.destination], rdx
        mov     [.ctx], r8

        mov     rcx, [.source_512]            ; take lowest 256-bit (source mod R)
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.mod_inv_r]
        lea     r8, [.m_256]
        call    bi_mul_256_256_low_256

        lea     rcx, [.m_256]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        lea     r8, [.t_512]
        call    bi_mul_256_256

        lea     rcx, [.t_512]
        mov     rdx, [.source_512]
        call    bi_add_assign_512_512
        jc      .norm

        lea     rcx, [.t_512 + 32]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        call    bi_cmp_256_256
        jb      .norm_ok
.norm:
        lea     rcx, [.t_512 + 32]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        call    bi_sub_assign_256_256
.norm_ok:
        mov     rcx, [.destination]
        lea     rdx, [.t_512 + 32]
        call    bi_copy_256

        add     rsp, .locals_end - .locals_start
        ret

end if
