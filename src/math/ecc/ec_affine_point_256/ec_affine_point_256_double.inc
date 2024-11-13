if ~ definite ec_affine_point_256_double

;Doubles ECAffinePoint256 point
;input:
;  rcx - pointer to source ECAffinePoint256 point
;  rdx - pointer to destination ECAffinePoint256 point
ec_affine_point_256_double:
virtual at rsp
  label .locals_start
  .m BigInteger256
  .m2 BigInteger256
  .temp BigInteger256
  .source rq 1
  .result rq 1
  .curve rq 1
  .modulus rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_affine_point_256_double'
    CheckRegBi256Alignment rcx, 'ec_affine_point_256_double rcx'
    CheckRegBi256Alignment rdx, 'ec_affine_point_256_double rdx'

        mov     [.source], rcx
        mov     [.result], rdx

        mov     r8, [rcx + ECAffinePoint256.curve]
        mov     [.curve], r8
        mov     [rdx + ECAffinePoint256.curve], r8

        lea     r8, [r8 + ECCurve256.modulus]
        mov     [.modulus], r8

        mov     rcx, [.source]
        call    ec_affine_point_256_is_infinity
        jz      .use_zero

;           3 * (source.x ^ 2) + curve.A
; m =    ---------------------------------
;                   2 * source.y
        mov     rcx, [.source]
        mov     rdx, [.modulus]
        lea     r8, [.temp]
        call    bi_mod_square_256

        lea     rcx, [.temp]
        mov     rdx, [.modulus]
        call    bi_mod_tripple_assign_256

        lea     rcx, [.temp]
        mov     rdx, [.curve]
        lea     rdx, [rdx + ECCurve256.a]
        mov     r8, [.modulus]
        call    bi_mod_add_assign_256_256

        lea     rcx, [.temp]
        mov     rdx, [.source]
        add     rdx, ECAffinePoint256.y
        mov     r8, [.modulus]
        lea     r9, [.m]
        call    bi_mod_div_256_256

        lea     rcx, [.m]
        mov     rdx, [.modulus]
        call    bi_mod_half_assign_256

.got_m:
; m2 = m ^ 2
        lea     rcx, [.m]
        mov     rdx, [.modulus]
        lea     r8, [.m2]
        call    bi_mod_square_256

;result.x = m2 - source.x - source.x
        lea     rcx, [.m2]
        mov     rdx, [.source]
        mov     r8, [.modulus]
        mov     r9, [.result]
        call    bi_mod_sub_256_256

        mov     rcx, [.result]
        mov     rdx, [.source]
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256


;result.y = m * (source.x - result.x) - source.y
        mov     rcx, [.source]
        mov     rdx, [.result]
        mov     r8, [.modulus]
        lea     r9, [.temp]
        call    bi_mod_sub_256_256

        lea     rcx, [.temp]
        lea     rdx, [.m]
        mov     r8, [.modulus]
        mov     r9, [.result]
        add     r9, ECAffinePoint256.y
        call    bi_mod_mul_256_256

        mov     rcx, [.result]
        add     rcx, ECAffinePoint256.y
        mov     rdx, [.source]
        add     rdx, ECAffinePoint256.y
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256
        add     rsp, .locals_end - .locals_start
        ret

.use_zero:
        mov     rcx, [.result]
        call    ec_affine_point_256_set_infinity
        add     rsp, .locals_end - .locals_start
        ret

end if