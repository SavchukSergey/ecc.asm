__ec_projective_mont_point_256_mul_test:
virtual at rsp
.locals_start:
   .left ECProjectiveMontgomeryPoint256
   .multiplier BigInteger256
   .result ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_projective_mont_point_256_mul_test'

        mov     rbx,  __ec_projective_mont_point_256_mul_test_cases
.loop:
        lea     rcx, [.left]
        lea     rdx, [rbx + 0]
        mov     r8, secp256k1
        call    ec_projective_mont_point_256_try_read_hex

        lea     rcx, [rbx + __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS]
        lea     rdx, [.multiplier]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.multiplier]
        lea     r8, [.result]
        call    ec_projective_mont_point_256_mul

        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS + __BIG_INTEGER_HEX_DIGITS_256]
        lea     rdx, [.result]
        call    ec_projective_mont_point_256_assert_equal_hex

        add     rbx, __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS * 2 + __BIG_INTEGER_HEX_DIGITS_256
        cmp     rbx, __ec_projective_mont_point_256_mul_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_projective_mont_point_256_mul_test_cases:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'

  db 'b359fbe006c3016490e0bd17dea2fc13a4ac7a5919cd93e4f90f4b1481cb2d6c'

  db '1f8374fb687691e9300f923969edb3db6e297f704502343f80988e46756cd8ff'
  db '33b45405ef6cb837ea56eedf6df40bd594445303c6eb2b38e3cef1f3fc0f4d61'
  db '395a5188e35b33228ea05927880c49e976e44db74a7fa67e0ecbc703c1e18807'

.end: