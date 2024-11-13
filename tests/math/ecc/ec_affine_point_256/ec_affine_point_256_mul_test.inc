__ec_affine_point_256_mul_test:
virtual at rsp
.locals_start:
   .left ECAffinePoint256
   .multiplier BigInteger256
   .result ECAffinePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_affine_point_256_mul_test'

        mov     rbx,  __ec_affine_point_256_mul_test_cases
.loop:
        lea     rcx, [.left]
        lea     rdx, [rbx + 0]
        mov     r8, secp256k1
        call    ec_affine_point_256_try_read_hex

        lea     rcx, [rbx + __EC_AFFINE_POINT_256_HEX_DIGITS]
        lea     rdx, [.multiplier]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.multiplier]
        lea     r8, [.result]
        call    ec_affine_point_256_mul

        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_AFFINE_POINT_256_HEX_DIGITS + __BIG_INTEGER_HEX_DIGITS_256]
        lea     rdx, [.result]
        call    ec_affine_point_256_assert_equal_hex

        add     rbx, __EC_AFFINE_POINT_256_HEX_DIGITS * 2 + __BIG_INTEGER_HEX_DIGITS_256
        cmp     rbx, __ec_affine_point_256_mul_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_affine_point_256_mul_test_cases:
  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'

  db 'b359fbe006c3016490e0bd17dea2fc13a4ac7a5919cd93e4f90f4b1481cb2d6c'

  db '1eb65a6bf5fc5f8e5adbe85b111d5c232abdace60a0b3f57f408c287a867c347'
  db 'fd0dc20576138c748934c1185faa24740c72dd688a0d7d7ed2bead2f10f72411'

.end: