if ~ definite bi_mont_ctx_256_sub

bi_mont_ctx_256_sub:
        lea     r8, [r8 + MontgomeryContext256.modulus]
        jmp    bi_mod_sub_256_256

end if
