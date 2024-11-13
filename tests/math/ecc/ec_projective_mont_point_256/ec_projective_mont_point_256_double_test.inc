__ec_projective_mont_point_256_double_test:
virtual at rsp
.locals_start:
  .source ECProjectiveMontgomeryPoint256
  .target ECProjectiveMontgomeryPoint256
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        
        mov     rbx,  __ec_projective_mont_point_256_double_test_cases
.loop:

        lea     rcx, [.source]
        lea     rdx, [rbx]
        mov     r8, secp256k1
        call    ec_projective_mont_point_256_try_read_hex

        call    test_context_start_measure
    .chunk_loop:
        lea     rcx, [.source]
        lea     rdx, [.target]
        call    ec_projective_mont_point_256_double
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_projective_mont_point_256_HEX_DIGITS]
        lea     rdx, [.target]
        call    ec_projective_mont_point_256_assert_equal_hex

        add     rbx, __EC_projective_mont_point_256_HEX_DIGITS * 2
        cmp     rbx, __ec_projective_mont_point_256_double_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_projective_mont_point_256_double_test_cases:
  db '67a90189db61a177ca5ae73135a5c0d4d1c38644db19e5714aa478800d72c47f'
  db '93b629c732ffd156073eaea110ec54a7ab2148d20feb4c620dd81b63169b0924'
  db '625f314aa043b3e11af031b2f5be8e73ff8af39f0d2eb4b7a38e3ce63a809777'
  db '81a2c33443490aa325e881521196975ddd75f3c93d7db450d216b350b4f299c2'
  db '0590c59c54008439fe9766cfa282efb741aee2fa92f1ee918d9f0d1b5980d3a6'
  db '93bd7087b1f807dbd966246b305206908effecc301cb2125512b1a18d63b798e'

  db '81a2c33443490aa325e881521196975ddd75f3c93d7db450d216b350b4f299c2'
  db '0590c59c54008439fe9766cfa282efb741aee2fa92f1ee918d9f0d1b5980d3a6'
  db '93bd7087b1f807dbd966246b305206908effecc301cb2125512b1a18d63b798e'
  db '928509af35d460147ebfb39073fd735c7210a5942b66047bc769d8dc9f1cc156'
  db '425b3857b1432f43f6d9c4ac99f95749eba7ac65df72ca30498d4651394121b8'
  db '8f4191cedb8f946d15a4f7f348d93b723b4293491ade20656b2f351d1fed15b5'
.end: