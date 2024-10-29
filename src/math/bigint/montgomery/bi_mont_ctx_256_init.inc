if ~ definite bi_mont_ctx_256_init

include 'bi_mont_ctx_256.inc';
include '../div_rem/bi_div_rem_512_256.inc';
include '../extend_low/bi_extend_512_256.inc';
include '../mod_inverse/bi_mod_inverse_512.inc';
include '../mod_negate/bi_mod_negate_256.inc';

bi_mont_ctx_256_init:
virtual at rsp
  label .locals_start
    .temp_512 BigInteger512
    .remainder_512 BigInteger512
    .modulus_512 BigInteger512 
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
        mov     byte [rcx + MontgomeryContext256.r + 32], 1

        mov     rcx, [.ctx]
        lea     rcx, [rcx + MontgomeryContext256.r]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        lea     r8, [.temp_512]
        lea     r9, [.remainder_512]
        call    bi_div_rem_512_256

        mov     rcx, [.ctx]
        lea     rcx, [rcx + MontgomeryContext256.rm]
        lea     rdx, [.remainder_512]
        call    bi_copy_256

        lea     rcx, [.modulus_512]
        mov     rdx, [.modulus]
        call    bi_extend_512_256

        lea	    rcx, [.modulus_512]
        mov     rdx, [.ctx]
        lea	    rdx, [rdx + MontgomeryContext256.r]
        lea	    r8, [.temp_512]
        call    bi_mod_inverse_512                    ;todo: speed up
;todo: euclid extended can give us rm and mod_inv_r at same time

        lea     rcx, [.temp_512]
        mov     rdx, [.ctx]
        lea	    rdx, [rdx + MontgomeryContext256.r]   ; effectively it's zero because of trimming to 256-bit
        mov     r8, [.ctx]
        lea     r8, [r8 + MontgomeryContext256.mod_inv_r]
        call    bi_mod_negate_256

        add     rsp, .locals_end - .locals_start
        ret

end if
