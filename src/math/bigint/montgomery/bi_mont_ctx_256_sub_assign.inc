if ~ definite bi_mont_ctx_256_sub_assign

bi_mont_ctx_256_sub_assign:
        lea     r8, [r8 + MontgomeryContext256.modulus]
        jmp    bi_mod_sub_assign_256_256

end if
