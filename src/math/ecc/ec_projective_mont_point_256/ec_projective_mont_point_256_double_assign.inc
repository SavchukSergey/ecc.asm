if ~ definite ec_projective_mont_point_256_double_assign

;Doubles ECProjectiveMontgomeryPoint256 point
;input:
;  rcx - pointer to source ECProjectiveMontgomeryPoint256 point. Modified value
ec_projective_mont_point_256_double_assign:
virtual at rsp
  label .locals_start
  .left rq 1
  .temp ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_projective_mont_point_256_double_assign'
    CheckRegBi256Alignment rcx, 'ec_projective_mont_point_256_double_assign rcx'

        mov     [.left], rcx

        lea     rdx, [.temp]
        call    ec_projective_mont_point_256_double

        mov     rcx, [.left]
        lea     rdx, [.temp]
        call    ec_projective_mont_point_256_copy

        add     rsp, .locals_end - .locals_start
        ret  

end if