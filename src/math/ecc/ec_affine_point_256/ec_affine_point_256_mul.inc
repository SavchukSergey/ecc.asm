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
  .bit rq 1
  .acc ECAffinePoint256
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

        mov     rcx, [.result]
        call    ec_affine_point_256_set_infinity

        lea     rcx, [.acc]
        mov     rdx, [.source]
        call    ec_affine_point_256_copy

        mov     [.bit], 0
.loop:
        mov     rcx, [.multiplier]
        mov     rdx, [.bit]
        call    bi_bit_check_256
        test    rax, rax
        jz      .zero_bit

        mov     rcx, [.result]
        lea     rdx, [.acc]
        call    ec_affine_point_256_add_assign
 .zero_bit:
        lea     rcx, [.acc]
        call    ec_affine_point_256_double_assign

        inc     [.bit]
        cmp     [.bit], 256
        jb      .loop


        add     rsp, .locals_end - .locals_start
        ret

end if