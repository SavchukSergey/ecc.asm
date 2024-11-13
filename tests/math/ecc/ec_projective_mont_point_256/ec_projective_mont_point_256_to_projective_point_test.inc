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
  db '3ce6ec61299a964dbfd4d5587a14ac30ebb136abb909ea157c3c053acf88582c'
  db 'c4c3a8137d1426ecd61023b120bfea8968a8eb233d0e63b7ae3759df10383b82'
  db 'b4e2d4ab187ef003beb7fb6423ef3429d9153bcb78f5743c5ad6564e35842a1f'
.expected_point_hex:
  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'
.end: