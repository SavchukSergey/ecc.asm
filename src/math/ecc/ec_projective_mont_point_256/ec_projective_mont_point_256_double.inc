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
  .modulus rq 1
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

        lea     r8, [r8 + ECCurve256.modulus]
        mov     [.modulus], r8

; x2 = X.ModSquare(Modulus)
        mov     rcx, [.source]
;        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.x]
        mov     rdx, [.modulus]
        lea     r8, [.x2]
        call    bi_mod_square_256

; z2 = X.ModSquare(Modulus)
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.z]
        mov     rdx, [.modulus]
        lea     r8, [.z2]
        call    bi_mod_square_256

;az2 = A.ModMul(z2, Modulus)
        mov     rcx, [.curve]
        lea     rcx, [rcx + ECCurve256.a]
        lea     rdx, [.z2]
        mov     r8, [.modulus]
        lea     r9, [.az2]
        call    bi_mod_mul_256_256

;t = x2.ModTriple(Modulus).ModAdd(az2, Modulus)
        lea     rcx, [.t]
        lea     rdx, [.x2]
        Fast_Copy 256
        lea     rcx, [.t]
        mov     rdx, [.modulus]
        call    bi_mod_tripple_assign_256
        lea     rcx, [.t]
        lea     rdx, [.az2]
        mov     r8, [.modulus]
        call    bi_mod_add_assign_256_256


;u = Y.ModMul(Z, Modulus).ModDouble(Modulus)
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        mov     rdx, [.source]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.z]
        mov     r8, [.modulus]
        lea     r9, [.u]
        call    bi_mod_mul_256_256
        lea     rcx, [.u]
        mov     rdx, [.modulus]
        call    bi_mod_double_assign_256

;uy = Y.ModMul(u, Modulus)
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        lea     rdx, [.u]
        mov     r8, [.modulus]
        lea     r9, [.uy]
        call    bi_mod_mul_256_256

;v = X.ModMul(uy, Modulus).ModDouble(Modulus)
        mov     rcx, [.source]
        lea     rdx, [.uy]
        mov     r8, [.modulus]
        lea     r9, [.v]
        call    bi_mod_mul_256_256
        lea     rcx, [.v]
        mov     rdx, [.modulus]
        call    bi_mod_double_assign_256

;t2 = t.ModSquare(Modulus)
        lea     rcx, [.t]
        mov     rdx, [.modulus]
        lea     r8, [.t2]
        call    bi_mod_square_256

;w = t2.ModSub(v.ModDouble(Modulus), Modulus)
        lea     rcx, [.t2]
        lea     rdx, [.v]
        mov     r8, [.modulus]
        lea     r9, [.w]
        call    bi_mod_sub_256_256
        lea     rcx, [.w]
        lea     rdx, [.v]
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256

;resX = u.ModMul(w, Modulus)
        lea     rcx, [.u]
        lea     rdx, [.w]
        mov     r8, [.modulus]
        mov     r9, [.result]
;        lea     r9, [r9 + ECProjectiveMontgomeryPoint256.x]
        call    bi_mod_mul_256_256

;uy2d = uy.ModSquare(Modulus).ModDouble(Modulus)
        lea     rcx, [.uy]
        mov     rdx, [.modulus]
        lea     r8, [.uy2d]
        call    bi_mod_square_256
        lea     rcx, [.uy2d]
        mov     rdx, [.modulus]
        call    bi_mod_double_assign_256

;dvw = v.ModSub(w, Modulus)
        lea     rcx, [.v]
        lea     rdx, [.w]
        mov     r8, [.modulus]
        lea     r9, [.dvw]
        call    bi_mod_sub_256_256

;resY = t.ModMul(dvw, Modulus).ModSub(uy2d, Modulus)
        lea     rcx, [.t]
        lea     rdx, [.dvw]
        mov     r8, [.modulus]
        mov     r9, [.result]
        lea     r9, [r9 + ECProjectiveMontgomeryPoint256.y]
        call    bi_mod_mul_256_256
        mov     rcx, [.result]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        lea     rdx, [.uy2d]
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256

;resZ = u.ModCube(Modulus)
        lea     rcx, [.u]
        mov     rdx, [.modulus]
        mov     r8, [.result]
        lea     r8, [r8 + ECProjectiveMontgomeryPoint256.z]
        call    bi_mod_cube_256

        add     rsp, .locals_end - .locals_start
        ret

end if