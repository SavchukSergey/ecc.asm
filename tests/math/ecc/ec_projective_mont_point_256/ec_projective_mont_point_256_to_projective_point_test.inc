__ec_projective_mont_point_256_to_projective_point_test:
virtual at rsp
.locals_start:
   .source_point ECProjectiveMontgomeryPoint256
   .result_point ECProjectivePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_projective_mont_point_256_to_projective_point_test'

        lea     rcx, [.source_point]
        lea     rdx, [.source_point_hex]
        mov     r8, secp256k1
        call    ec_projective_mont_point_256_try_read_hex

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.source_point]
        lea     rdx, [.result_point]
        call    ec_projective_mont_point_256_to_projective_point
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [.expected_point_hex]
        lea     rdx, [.result_point]
        call    ec_projective_point_256_assert_equal_hex

        add     rsp, .locals_end - .locals_start
        ret

align 16
.source_point_hex:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'
.expected_point_hex:
  db '3ce6ec61299a964dbfd4d5587a14ac30ebb136abb909ea157c3c053acf88582c'
  db 'c4c3a8137d1426ecd61023b120bfea8968a8eb233d0e63b7ae3759df10383b82'
  db 'b4e2d4ab187ef003beb7fb6423ef3429d9153bcb78f5743c5ad6564e35842a1f'
.end: