if ~ definite ec_affine_point_256_copy

;Copies ECAffinePoint256
;input:
;  rcx - pointer to target ECAffinePoint256
;  rdx - pointer to source ECAffinePoint256

; same signature, same result
ec_affine_point_256_copy = bi_copy_512

end if