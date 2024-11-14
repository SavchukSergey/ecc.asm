;Doubles bi256 value in montgomery form
;input:
;  rcx - pointer to bi256 montgomery value. Modified value
;  rdx - pointer to MontgomeryContext256

bi_mont_ctx_256_double_assign:
        lea     rdx, [rdx + MontgomeryContext256.modulus]
        jmp     bi_mod_double_assign_256
