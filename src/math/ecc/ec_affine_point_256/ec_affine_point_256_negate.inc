if ~ definite ec_affine_point_256_negate

;Negates ECAffinePoint256
;input:
;  rcx - pointer to source ECAffinePoint256
;  rdx - pointer to destination ECAffinePoint256
ec_affine_point_256_negate:
virtual at rsp
.locals_start:
   .source rq 1
   .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.source], rcx
        mov     [.result], rdx

        mov     r9, [rcx + ECAffinePoint256.curve]
        mov     [rdx + ECAffinePoint256.curve], r9

        mov     rcx, [.result]
;        lea     rcx, [rcx + ECAffinePoint256.x]
        mov     rdx, [.source]
;        lea     rdx, [rdx + ECAffinePoint256.x]
        Fast_Copy 256

        mov     rcx, [.source]
        lea     rcx, [rcx + ECAffinePoint256.y]
        lea     rdx, [r9 + ECCurve256.modulus]
        mov     r8, [.result]
        lea     r8, [r8 + ECAffinePoint256.y]
        call    bi_mod_negate_256

        add     rsp, .locals_end - .locals_start
        ret

end if