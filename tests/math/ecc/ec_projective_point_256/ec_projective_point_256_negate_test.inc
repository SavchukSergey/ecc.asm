__ec_projective_point_256_negate_test:
virtual at rsp
.locals_start:
  .source ECProjectivePoint256
  .target ECProjectivePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start

    lea     rcx, [.source]
    lea     rdx, [.source_hex]
    mov     r8, secp256k1
    call    ec_projective_point_256_try_read_hex

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.source]
    lea     rdx, [.target]
    call    ec_projective_point_256_negate
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    lea     rcx, [.expected_hex]
    lea     rdx, [.target]
    call    ec_projective_point_256_assert_equal_hex

    add     rsp, .locals_end - .locals_start
    ret

align 16
.source_hex:
  db '3ce6ec61299a964dbfd4d5587a14ac30ebb136abb909ea157c3c053acf88582c'
  db 'c4c3a8137d1426ecd61023b120bfea8968a8eb233d0e63b7ae3759df10383b82'
  db 'b4e2d4ab187ef003beb7fb6423ef3429d9153bcb78f5743c5ad6564e35842a1f'

.expected_hex:
  db '3ce6ec61299a964dbfd4d5587a14ac30ebb136abb909ea157c3c053acf88582c'
  db '3b3c57ec82ebd91329efdc4edf401576975714dcc2f19c4851c8a61fefc7c0ad'
  db 'b4e2d4ab187ef003beb7fb6423ef3429d9153bcb78f5743c5ad6564e35842a1f'
