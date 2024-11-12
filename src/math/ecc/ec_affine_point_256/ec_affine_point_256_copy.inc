if ~ definite ec_affine_point_256_copy

;Copies ECAffinePoint256
;input:
;  rcx - pointer to target ECAffinePoint256
;  rdx - pointer to source ECAffinePoint256
ec_affine_point_256_copy:
    Fast_Copy 512
    mov       rax, [rdx + ECAffinePoint256.curve]
    mov       [rcx + ECAffinePoint256.curve], rax
    ret

end if