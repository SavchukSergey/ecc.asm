if ~ definite ec_projective_point_256_copy

;Copies ECProjectivePoint256
;input:
;  rcx - pointer to target ECProjectivePoint256
;  rdx - pointer to source ECProjectivePoint256

; same signature, same result
ec_projective_point_256_copy = bi_copy_768

end if