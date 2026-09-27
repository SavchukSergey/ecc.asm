if ~ definite bi_mont_ctx_256_init

bi_mont_ctx_256_init:
virtual at rsp
  label .locals_start
    .temp_512 BigInteger512
    .remainder_512 BigInteger512
    .modulus_512 BigInteger512
    .newton_x BigInteger256
    .newton_t BigInteger256
    .newton_u BigInteger256
    .two BigInteger256
    .modulus rq 1
    .ctx rq 1
    .rounds rq 1
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

;mod_inv_r = -(modulus^-1 mod 2^256), computed with Newton iteration
;x = 1 is the inverse mod 2; each round doubles the precision:
;    x = x * (2 - modulus * x) mod 2^256
;8 rounds reach the full 256 bits and only need low-half multiplications
        lea     rcx, [.newton_x]
        call    bi_one_256

        lea     rcx, [.two]
        call    bi_zero_256
        add     qword [.two], 2

        mov     qword [.rounds], 8
.newton_round:
        ;t = low(modulus * x)
        mov     rcx, [.modulus]
        lea     rdx, [.newton_x]
        lea     r8, [.newton_t]
        call    bi_mul_256_256_low_256

        ;u = 2 - t
        lea     rcx, [.two]
        lea     rdx, [.newton_t]
        lea     r8, [.newton_u]
        call    bi_sub_256_256

        ;x = low(x * u), staged through t
        lea     rcx, [.newton_x]
        lea     rdx, [.newton_u]
        lea     r8, [.newton_t]
        call    bi_mul_256_256_low_256

        lea     rcx, [.newton_x]
        lea     rdx, [.newton_t]
        call    bi_copy_256

        dec     qword [.rounds]
        jnz     .newton_round

        ;mod_inv_r = 0 - x  (mod 2^256)
        lea     rcx, [.newton_t]
        call    bi_zero_256
        lea     rcx, [.newton_t]
        lea     rdx, [.newton_x]
        mov     r8, [.ctx]
        lea     r8, [r8 + MontgomeryContext256.mod_inv_r]
        call    bi_sub_256_256

        add     rsp, .locals_end - .locals_start
        ret

end if
