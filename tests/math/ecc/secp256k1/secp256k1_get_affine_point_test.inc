__secp256k1_get_affine_point_test:
virtual at rsp
.locals_start:
   .left ECAffinePoint256
   .multiplier BigInteger256
   .result ECAffinePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__secp256k1_get_affine_point_test'

        mov     rbx,  __secp256k1_get_affine_point_test_cases
.loop:
        lea     rcx, [rbx]
        lea     rdx, [.multiplier]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.multiplier]
        lea     rdx, [.result]
        call    secp256k1_get_affine_point

        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __BIG_INTEGER_HEX_DIGITS_256]
        lea     rdx, [.result]
        call    ec_affine_point_256_assert_equal_hex

        add     rbx, __BIG_INTEGER_HEX_DIGITS_256 + __EC_AFFINE_POINT_256_HEX_DIGITS
        cmp     rbx, __secp256k1_get_affine_point_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__secp256k1_get_affine_point_test_cases:
  db 'b359fbe006c3016490e0bd17dea2fc13a4ac7a5919cd93e4f90f4b1481cb2d6c'

  db 'd5859b6fda02647f786e1f0e8c62ab657dec000b0e6f82c7f232e4786b4e1744'
  db 'a8737ef78f00432c99bd0948394a9b75fe14a9d3a0d9361e92208a9023f442c2'

.end: