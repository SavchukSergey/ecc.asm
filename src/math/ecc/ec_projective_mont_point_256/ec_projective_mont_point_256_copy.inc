if ~ definite ec_projective_mont_point_256_copy

;Copies ECProjectiveMontgomeryPoint256
;input:
;  rcx - pointer to target ECProjectiveMontgomeryPoint256
;  rdx - pointer to source ECProjectiveMontgomeryPoint256
ec_projective_mont_point_256_copy:
    Fast_Copy 768
    mov       rax, [rdx + ECProjectiveMontgomeryPoint256.curve]
    mov       [rcx + ECProjectiveMontgomeryPoint256.curve], rax
    ret

end if