if ~ definite ec_projective_point_256_is_infinity

;Checks if ECProjectivePoint256 is at infinity
;input:
;  rcx - pointer to ECProjectivePoint256
;output:
;  rax - 1 if point is in infinity, 0 otherwise
;  ZF - 1 if point is in infinity, 0 otherwise

; same signature, same result
ec_projective_point_256_is_infinity = bi_is_zero_512

end if