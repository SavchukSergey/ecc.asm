if ~ definite bi_mont_ctx_256_add_assign

bi_mont_ctx_256_add_assign:
        lea     r8, [r8 + MontgomeryContext256.modulus]
        jmp    bi_mod_add_assign_256_256

end if
