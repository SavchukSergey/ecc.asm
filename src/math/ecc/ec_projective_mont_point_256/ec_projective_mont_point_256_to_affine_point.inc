
; Converts projective montgomery point to affine point
; input:
;  rcx - pointer to source ECProjectiveMontgomeryPoint256
;  rdx - pointer to destination ECAffinePoint256
ec_projective_mont_point_256_to_affine_point:
virtual at rsp
.locals_start:
   .source rq 1
   .result rq 1
   .projective ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.source], rcx
        mov     [.result], rdx

        mov     rcx, [.source]
        lea     rdx, [.projective]
        call    ec_projective_mont_point_256_to_projective_point

        lea     rcx, [.projective]
        mov     rdx, [.result]
        call    ec_projective_point_256_to_affine_point

        add     rsp, .locals_end - .locals_start
        ret

