if ~ definite ec_affine_point_256_double_assign

;Doubles ECAffinePoint256 point
;input:
;  rcx - pointer to source ECAffinePoint256 point. Modified value
ec_affine_point_256_double_assign:
virtual at rsp
  label .locals_start
  .left rq 1
  .temp ECAffinePoint256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_affine_point_256_double_assign'
    CheckRegBi256Alignment rcx, 'ec_affine_point_256_double_assign rcx'

        mov     [.left], rcx

        lea     rdx, [.temp]
        call    ec_affine_point_256_double

        mov     rcx, [.left]
        lea     rdx, [.temp]
        call    ec_affine_point_256_copy

        add     rsp, .locals_end - .locals_start
        ret  

end if