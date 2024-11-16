if ~ definite ec_projective_mont_point_256_sub

;Subtracts to ECProjectiveMontgomeryPoint256 points
;input:
;  rcx - pointer to left ECProjectiveMontgomeryPoint256 point
;  rdx - pointer to right ECProjectiveMontgomeryPoint256 point
;  r8 - pointer to ECProjectiveMontgomeryPoint256 result
ec_projective_mont_point_256_sub:
virtual at rsp
  label .locals_start
  .left rq 1
  .right rq 1
  .result rq 1

  .temp ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_projective_mont_point_256_sub'
    CheckRegAligned rcx, 'ec_projective_mont_point_256_sub rcx'
    CheckRegAligned rdx, 'ec_projective_mont_point_256_sub rdx'
    CheckRegAligned r8, 'ec_projective_mont_point_256_sub r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.right]
        lea     rdx, [.temp]
        call    ec_projective_mont_point_256_negate

        mov     rcx, [.left]
        lea     rdx, [.temp]
        mov     r8, [.result]
        call    ec_projective_mont_point_256_add

        add     rsp, .locals_end - .locals_start
        ret 

end if