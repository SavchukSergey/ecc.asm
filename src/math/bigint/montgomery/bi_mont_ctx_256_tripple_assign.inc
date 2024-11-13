if ~ definite bi_mont_ctx_256_tripple_assign

bi_mont_ctx_256_tripple_assign:
        lea     r8, [r8 + MontgomeryContext256.modulus]
        jmp    bi_mod_tripple_assign_256

end if
