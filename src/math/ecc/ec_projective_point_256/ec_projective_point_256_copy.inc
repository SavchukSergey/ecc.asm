if ~ definite ec_projective_point_256_copy

;Copies ECProjectivePoint256
;input:
;  rcx - pointer to target ECProjectivePoint256
;  rdx - pointer to source ECProjectivePoint256
ec_projective_point_256_copy:
    Fast_Copy 768
    mov       rax, [rdx + ECProjectivePoint256.curve]
    mov       [rcx + ECProjectivePoint256.curve], rax
    ret

end if