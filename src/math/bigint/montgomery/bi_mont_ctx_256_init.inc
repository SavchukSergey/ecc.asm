if ~ definite bi_mont_ctx_256_init

include 'bi_mont_ctx_256.inc';
include '../div_rem/bi_div_rem_512_256.inc';

bi_mont_ctx_256_init:
virtual at rsp
  label .locals_start
    .modulus rq 1
    .ctx rq 1
    BigInteger512 .temp_512
    BigInteger512 .remainder_512
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

;todo:

        add     rsp, .locals_end - .locals_start
        ret

end if
