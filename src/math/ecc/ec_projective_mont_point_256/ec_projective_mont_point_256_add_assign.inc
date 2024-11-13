if ~ definite ec_projective_mont_point_256_add_assign

;Adds to ECProjectiveMontgomeryPoint256 points
;input:
;  rcx - pointer to left ECProjectiveMontgomeryPoint256 point
;  rdx - pointer to ECProjectiveMontgomeryPoint256 result
ec_projective_mont_point_256_add_assign:
virtual at rsp
  label .locals_start
  .left rq 1
  .temp ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_projective_mont_point_256_add_assign'
    CheckRegBi256Alignment rcx, 'ec_projective_mont_point_256_add_assign rcx'
    CheckRegBi256Alignment rdx, 'ec_projective_mont_point_256_add_assign rdx'

        mov     [.left], rcx

        lea     r8, [.temp]
        call    ec_projective_mont_point_256_add

        mov     rcx, [.left]
        lea     rdx, [.temp]
        call    ec_projective_mont_point_256_copy

        add     rsp, .locals_end - .locals_start
        ret  

end if