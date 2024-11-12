if ~ definite ec_affine_point_256_is_infinity

;Checks if ECAffinePoint256 is at infinity
;input:
;  rcx - pointer to ECAffinePoint256
;output:
;  rax - 1 if point is in infinity, 0 otherwise
;  ZF - 1 if point is in infinity, 0 otherwise

; same signature, same result
ec_affine_point_256_is_infinity = bi_is_zero_512

end if