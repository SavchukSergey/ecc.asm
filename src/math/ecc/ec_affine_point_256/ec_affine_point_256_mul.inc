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
  .zeroes rq 1
  .ones rq 1
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

        mov     [.zeroes], 0
        mov     [.ones], 0
        mov     [.bit], 0
.loop:
        cmp     [.bit], 256
        jae     .zero_bit
        mov     rcx, [.multiplier]
        mov     rdx, [.bit]
        call    bi_bit_check_256
        test    rax, rax
        jz      .zero_bit
.one_bit:
        inc     [.ones]
        jmp     .continue
.zero_bit:
        inc     [.zeroes]
        cmp     [.ones], 0
        je      .continue

;first perform pending boost of accumulator
        lea     rcx, [.acc]
        mov     rdx, [.zeroes]
        dec     rdx
        call    ec_affine_point_256_shl_assign

;we start getting profit only if ones >= 3

;if have two ones i.e. pattern 011
;using simple bit approach: we need one double, two adds
;using RLE bit approach: we need two doubles and one sub

;if have three ones i.e. pattern 0111
;using simple bit approach: we need two double, three adds
;using RLE bit approach: we need four doubles and one sub

        cmp     [.ones], 3
        jae     .optimized
.simple:
        mov     rcx, [.result]
        lea     rdx, [.acc]
        call    ec_affine_point_256_add_assign

        lea     rcx, [.acc]
        call    ec_affine_point_256_double_assign

        dec     [.ones]
        jnz     .simple
        mov     [.zeroes], 1
        jmp     .continue
.optimized:
        mov     rcx, [.result]
        lea     rdx, [.acc]
        call    ec_affine_point_256_sub_assign

        lea     rcx, [.acc]
        mov     rdx, [.ones]
        call    ec_affine_point_256_shl_assign
        mov     [.ones], 0

        mov     rcx, [.result]
        lea     rdx, [.acc]
        call    ec_affine_point_256_add_assign

        mov     [.zeroes], 1

.continue:
        inc     [.bit]
        cmp     [.bit], 256 + 1
        jb      .loop


        add     rsp, .locals_end - .locals_start
        ret

end if