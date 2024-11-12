if ~ definite ec_affine_point_256_try_read_hex

;Reads ECAffinePoint256 from hex string
;input
; rcx - pointer to destination ECAffinePoint256
; rdx - pointer to hex string
;  r8 - pointer to ECCurve256
;output
;  rax - 1 success
;  rax - 0 failure
ec_affine_point_256_try_read_hex:
virtual at rsp
.locals_start:
   .point rq 1
   .hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.point], rcx
        mov     [.hex], rdx

        mov     [rcx + ECAffinePoint256.curve], r8

;x
        mov     rcx, [.hex]
        mov     rdx, [.point]
        call    bi_try_read_hex_256
        test    rax, rax
        jz      .failure

;y
        mov     rcx, [.hex]
        add     rcx, __BIG_INTEGER_HEX_DIGITS_256
        mov     rdx, [.point]
        add     rdx, ECAffinePoint256.y
        call    bi_try_read_hex_256
        test    rax, rax
        jz      .failure

        add     rsp, .locals_end - .locals_start
        ret
.failure:
        add     rsp, .locals_end - .locals_start
        ret
end if
