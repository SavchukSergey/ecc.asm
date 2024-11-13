if ~ definite bi_mont_ctx_256_double_assign

bi_mont_ctx_256_double_assign:
        lea     r8, [r8 + MontgomeryContext256.modulus]
        jmp    bi_mod_double_assign_256

end if
