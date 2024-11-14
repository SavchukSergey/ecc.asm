__ec_projective_mont_point_256_sub_test:
virtual at rsp
.locals_start:
   .left ECProjectiveMontgomeryPoint256
   .right ECProjectiveMontgomeryPoint256
   .result ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_projective_mont_point_256_sub_test'

        mov     rbx,  __ec_projective_mont_point_256_sub_test_cases
.loop:
        lea     rcx, [.left]
        lea     rdx, [rbx + 0]
        mov     r8, secp256k1
        call    ec_projective_mont_point_256_try_read_hex

        lea     rcx, [.right]
        lea     rdx, [rbx + __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS]
        mov     r8, secp256k1
        call    ec_projective_mont_point_256_try_read_hex

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    ec_projective_mont_point_256_sub
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS * 2]
        lea     rdx, [.result]
        call    ec_projective_mont_point_256_assert_equal_hex

        add     rbx, __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS * 3
        cmp     rbx, __ec_projective_mont_point_256_sub_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_projective_mont_point_256_sub_test_cases:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'

  db 'd0a9287039b5b1d143e6f6ecf21936dcfb8994292b94fce0f1730f963e82f378'
  db 'a4f4129df588b6c08ffa58d172c136b52d6f855ee3b15a3e9392fe70d08ea32d'
  db '833579bd538e7d654116041a99b4dba37ad1aaa4bef5967137a146afde8e8463'

  db 'e8e20737fdb6dbbd482699f8793164304ada8a6eb1ca6fc0d1d10c81f82d0ad1'
  db 'da5b2c1c24ac81a8f0087b006b500df8758d3314d2b6b71ee3e4971e244fa49d'
  db 'a9ee70f267e39c0a0309190a6874754949ee2388913b440f27d5fe348b755e9a'

.end: