;Adds two bi256 value in montgomery form
;input:
;  rcx - pointer to bi256 left montgomery value. Modified value
;  rdx - pointer to bi256 right montgomery value. 
;   r8 - pointer to MontgomeryContext256

bi_mont_ctx_256_add_assign:
        lea     r8, [r8 + MontgomeryContext256.modulus]
        jmp    bi_mod_add_assign_256_256

