if ~ definite ec_affine_point_256_add_assign

;Adds to ECAffinePoint256 points
;input:
;  rcx - pointer to left ECAffinePoint256 point
;  rdx - pointer to ECAffinePoint256 result
ec_affine_point_256_add_assign:
virtual at rsp
  label .locals_start
  .left rq 1
  .temp ECAffinePoint256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_affine_point_256_add_assign'
    CheckRegAligned rcx, 'ec_affine_point_256_add_assign rcx'
    CheckRegAligned rdx, 'ec_affine_point_256_add_assign rdx'

        mov     [.left], rcx

        lea     r8, [.temp]
        call    ec_affine_point_256_add

        mov     rcx, [.left]
        lea     rdx, [.temp]
        call    ec_affine_point_256_copy

        add     rsp, .locals_end - .locals_start
        ret  

end if