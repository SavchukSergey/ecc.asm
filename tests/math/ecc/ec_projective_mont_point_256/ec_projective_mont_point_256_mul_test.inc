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
  db '3ce6ec61299a964dbfd4d5587a14ac30ebb136abb909ea157c3c053acf88582c'
  db 'c4c3a8137d1426ecd61023b120bfea8968a8eb233d0e63b7ae3759df10383b82'
  db 'b4e2d4ab187ef003beb7fb6423ef3429d9153bcb78f5743c5ad6564e35842a1f'

  db 'b359fbe006c3016490e0bd17dea2fc13a4ac7a5919cd93e4f90f4b1481cb2d6c'

  db '8b7eba76c0ddd5c559d9bbbd481a14d93e6422c45200d0334fe7a06b021e9744'
  db 'F429631561C12F6BDD26BD90E97D78D45619E978FB604C4C6C67FB8E36CE7DD8'
  db '7E0DC63F26C8BA85DF4B5A39600D042FF65F4EDE35284FAE6BA78DD4B649B437'

.end: