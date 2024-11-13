if ~ definite ec_affine_point_256_negate

;Copies ECAffinePoint256
;input:
;  rcx - pointer to source ECAffinePoint256
;  rdx - pointer to destination ECAffinePoint256
ec_affine_point_256_negate:
        mov     r9, [rcx + ECAffinePoint256.curve]
        mov     [rdx + ECAffinePoint256.curve], r9

        xchg    rcx, rdx
        Fast_Copy 256

        lea     r8, [rcx + ECAffinePoint256.y]
        lea     rdx, [rdx + ECAffinePoint256.y]
        lea     rcx, [r9 + ECCurve256.modulus]
        call    bi_sub_256_256

        ret

end if