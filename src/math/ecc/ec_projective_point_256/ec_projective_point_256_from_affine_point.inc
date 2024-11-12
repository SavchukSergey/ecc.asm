
; Converts affine point to projective point
; input:
;  rcx - pointer to destination ECProjectivePoint256
;  rdx - pointer to source ECAffinePoint256
ec_projective_point_256_from_affine_point:
virtual at rsp
.locals_start:
   .source rq 1
   .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.result], rcx
        mov     [.source], rdx

        mov     rax, [rdx + ECAffinePoint256.curve]
        mov     [rcx + ECProjectivePoint256.curve], rax

        mov     rcx, [.result]
        mov     rdx, [.source]
        Fast_Copy 256
  
        mov     rcx, [.result]
        add     rcx, ECProjectivePoint256.y
        mov     rdx, [.source]
        add     rdx, ECAffinePoint256.y
        Fast_Copy 256

        mov     rcx, [.result]
        add     rcx, ECProjectivePoint256.z
        call    bi_one_256

        add     rsp, .locals_end - .locals_start
        ret

