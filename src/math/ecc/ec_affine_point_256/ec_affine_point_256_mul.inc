if ~ definite ec_affine_point_256_mul

;Muls ECAffinePoint256 point
;input:
;  rcx - pointer to source ECAffinePoint256 point
;  rdx - pointer to bi256 multiplier
;   r8 - pointer to destination ECAffinePoint256 point
ec_affine_point_256_mul:
virtual at rsp
  label .locals_start
  .source rq 1
  .multiplier rq 1
  .result rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_affine_point_256_mul'
    CheckRegBi256Alignment rcx, 'ec_affine_point_256_mul rcx'
    CheckRegBi256Alignment rdx, 'ec_affine_point_256_mul rdx'
    CheckRegBi256Alignment r8, 'ec_affine_point_256_mul r8'

        mov     [.source], rcx
        mov     [.multiplier], rdx
        mov     [.result], r8

        add     rsp, .locals_end - .locals_start
        ret

end if