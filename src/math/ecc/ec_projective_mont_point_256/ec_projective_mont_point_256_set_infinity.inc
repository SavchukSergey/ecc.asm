;Sets ECProjectiveMontgomeryPoint256 to infinity
;input:
;  rcx - pointer to ECProjectiveMontgomeryPoint256
ec_projective_mont_point_256_set_infinity:
    Fast_Zero 512
    add       rcx, ECProjectiveMontgomeryPoint256.z
    call      bi_one_256
    sub       rcx, ECProjectiveMontgomeryPoint256.z
    ret
