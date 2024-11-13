if ~ definite ec_projective_mont_point_256_double

;Doubles ECAffinePoint256 point
;input:
;  rcx - pointer to source ECProjectiveMontgomeryPoint256 point
;  rdx - pointer to destination ECProjectiveMontgomeryPoint256 point
ec_projective_mont_point_256_double:
virtual at rsp
  label .locals_start
  .source rq 1
  .result rq 1
  .curve rq 1
  .ctx rq 1
  .x2 BigInteger256
  .z2 BigInteger256
  .az2 BigInteger256
  .t BigInteger256
  .u BigInteger256
  .uy BigInteger256
  .uy2d BigInteger256
  .v BigInteger256
  .t2 BigInteger256
  .w BigInteger256
  .dvw BigInteger256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_projective_mont_point_256_double'
    CheckRegBi256Alignment rcx, 'ec_projective_mont_point_256_double rcx'
    CheckRegBi256Alignment rdx, 'ec_projective_mont_point_256_double rdx'

        mov     [.source], rcx
        mov     [.result], rdx

        mov     r8, [rcx + ECProjectiveMontgomeryPoint256.curve]
        mov     [.curve], r8
        mov     [rdx + ECProjectiveMontgomeryPoint256.curve], r8

        mov     rax, [.curve]
        lea     rax, [rax + ECCurve256.mont]
        mov     [.ctx], rax

; x2 = X.ModSquare(ctx)
        mov     rcx, [.source]
;        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.x]
        mov     rdx, [.ctx]
        lea     r8, [.x2]
        call    bi_mont_ctx_256_square

; z2 = X.ModSquare(ctx)
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.z]
        mov     rdx, [.ctx]
        lea     r8, [.z2]
        call    bi_mont_ctx_256_square

;az2 = A.ModMul(z2, ctx)
        mov     rcx, [.curve]
        lea     rcx, [rcx + ECCurve256.a]
        lea     rdx, [.z2]
        mov     r8, [.ctx]
        lea     r9, [.az2]
        call    bi_mont_ctx_256_mul

;t = x2.ModTriple(ctx).ModAdd(az2, ctx)
        lea     rcx, [.t]
        lea     rdx, [.x2]
        Fast_Copy 256
        lea     rcx, [.t]
        mov     rdx, [.ctx]
        call    bi_mont_ctx_256_tripple_assign
        lea     rcx, [.t]
        lea     rdx, [.az2]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_add_assign


;u = Y.ModMul(Z, ctx).ModDouble(ctx)
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        mov     rdx, [.source]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.z]
        mov     r8, [.ctx]
        lea     r9, [.u]
        call    bi_mont_ctx_256_mul
        lea     rcx, [.u]
        mov     rdx, [.ctx]
        call    bi_mont_ctx_256_double_assign

;uy = Y.ModMul(u, ctx)
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        lea     rdx, [.u]
        mov     r8, [.ctx]
        lea     r9, [.uy]
        call    bi_mont_ctx_256_mul

;v = X.ModMul(uy, ctx).ModDouble(ctx)
        mov     rcx, [.source]
        lea     rdx, [.uy]
        mov     r8, [.ctx]
        lea     r9, [.v]
        call    bi_mont_ctx_256_mul
        lea     rcx, [.v]
        mov     rdx, [.ctx]
        call    bi_mont_ctx_256_double_assign

;t2 = t.ModSquare(ctx)
        lea     rcx, [.t]
        mov     rdx, [.ctx]
        lea     r8, [.t2]
        call    bi_mont_ctx_256_square

;w = t2.ModSub(v.ModDouble(ctx), ctx)
        lea     rcx, [.t2]
        lea     rdx, [.v]
        mov     r8, [.ctx]
        lea     r9, [.w]
        call    bi_mont_ctx_256_sub
        lea     rcx, [.w]
        lea     rdx, [.v]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_sub_assign

;resX = u.ModMul(w, ctx)
        lea     rcx, [.u]
        lea     rdx, [.w]
        mov     r8, [.ctx]
        mov     r9, [.result]
;        lea     r9, [r9 + ECProjectiveMontgomeryPoint256.x]
        call    bi_mont_ctx_256_mul

;uy2d = uy.ModSquare(ctx).ModDouble(ctx)
        lea     rcx, [.uy]
        mov     rdx, [.ctx]
        lea     r8, [.uy2d]
        call    bi_mont_ctx_256_square
        lea     rcx, [.uy2d]
        mov     rdx, [.ctx]
        call    bi_mont_ctx_256_double_assign

;dvw = v.ModSub(w, ctx)
        lea     rcx, [.v]
        lea     rdx, [.w]
        mov     r8, [.ctx]
        lea     r9, [.dvw]
        call    bi_mont_ctx_256_sub

;resY = t.ModMul(dvw, ctx).ModSub(uy2d, ctx)
        lea     rcx, [.t]
        lea     rdx, [.dvw]
        mov     r8, [.ctx]
        mov     r9, [.result]
        lea     r9, [r9 + ECProjectiveMontgomeryPoint256.y]
        call    bi_mont_ctx_256_mul
        mov     rcx, [.result]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        lea     rdx, [.uy2d]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_sub_assign

;resZ = u.ModCube(ctx)
        lea     rcx, [.u]
        mov     rdx, [.ctx]
        mov     r8, [.result]
        lea     r8, [r8 + ECProjectiveMontgomeryPoint256.z]
        call    bi_mont_ctx_256_cube

        add     rsp, .locals_end - .locals_start
        ret

end if