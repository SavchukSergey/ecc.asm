if ~ definite ec_projective_point_256_negate

;Copies ECProjectivePoint256
;input:
;  rcx - pointer to source ECProjectivePoint256
;  rdx - pointer to destination ECProjectivePoint256
ec_projective_point_256_negate:
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

        mov     r9, [rcx + ECProjectivePoint256.curve]
        mov     [rdx + ECProjectivePoint256.curve], r9

        mov     rcx, [.result]
;        lea     rcx, [rcx + ECProjectivePoint256.x]
        mov     rdx, [.source]
;        lea     rdx, [rdx + ECProjectivePoint256.x]
        Fast_Copy 256

        mov     rcx, [.result]
        lea     rcx, [rcx + ECProjectivePoint256.z]
        mov     rdx, [.source]
        lea     rdx, [rdx + ECProjectivePoint256.z]
        Fast_Copy 256

        lea     rcx, [r9 + ECCurve256.modulus]
        mov     rdx, [.source]
        lea     rdx, [rdx + ECProjectivePoint256.y]
        mov     r8, [.result]
        lea     r8, [r8 + ECProjectivePoint256.y]
        call    bi_sub_256_256

        add     rsp, .locals_end - .locals_start
        ret

end if