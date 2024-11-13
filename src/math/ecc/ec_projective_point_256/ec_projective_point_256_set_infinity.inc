if ~ definite ec_projective_point_256_set_infinity

;Sets to point at infinity
;input:
;  rcx - pointer to ECProjectivePoint256
ec_projective_point_256_set_infinity:
    Fast_Zero 512
    add       rcx, ECProjectivePoint256.z
    call      bi_one_256
    sub       rcx, ECProjectivePoint256.z
    ret

end if