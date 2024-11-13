if ~ definite ec_affine_point_256_shl_assign

;Shifts left ECAffinePoint256 point. Modified value
;input:
;  rcx - pointer to source ECAffinePoint256 point. Modified value
;  rdx - count
ec_affine_point_256_shl_assign:
virtual at rsp
  label .locals_start
  .source rq 1
  .temp ECAffinePoint256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_affine_point_256_shl_assign'
    CheckRegBi256Alignment rcx, 'ec_affine_point_256_shl_assign rcx'

        mov     [.source], rcx

        lea     r8, [.temp]
        call    ec_affine_point_256_shl

        mov     rcx, [.source]
        lea     rdx, [.temp]
        call    ec_affine_point_256_copy

        add     rsp, .locals_end - .locals_start
        ret  

end if