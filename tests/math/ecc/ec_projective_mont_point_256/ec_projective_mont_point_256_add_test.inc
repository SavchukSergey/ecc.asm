__ec_projective_mont_point_256_add_test:
virtual at rsp
.locals_start:
   .left ECProjectiveMontgomeryPoint256
   .right ECProjectiveMontgomeryPoint256
   .result ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_projective_mont_point_256_add_test'

        mov     rbx,  __ec_projective_mont_point_256_add_test_cases
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
        call    ec_projective_mont_point_256_add
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS * 2]
        lea     rdx, [.result]
        call    ec_projective_mont_point_256_assert_equal_hex

        add     rbx, __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS * 3
        cmp     rbx, __ec_projective_mont_point_256_add_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_projective_mont_point_256_add_test_cases:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'

  db 'd0a9287039b5b1d143e6f6ecf21936dcfb8994292b94fce0f1730f963e82f378'
  db 'a4f4129df588b6c08ffa58d172c136b52d6f855ee3b15a3e9392fe70d08ea32d'
  db '833579bd538e7d654116041a99b4dba37ad1aaa4bef5967137a146afde8e8463'

  db 'a3cf2eab4d1af2fa5361ea6866e2038dc33ad52739764c20a51ae7fdff068b29'
  db '558d35135f8890aabb298ab454c7cc301bd8370169339d93f655a1157c4d32a3'
  db 'a9ee70f267e39c0a0309190a6874754949ee2388913b440f27d5fe348b755e9a'

; same-x cases in montgomery domain: dx == 0 must dispatch to double
; (regression cases; values are montgomery-domain G, scaled G and -G)
  db '9981e643e9089f48979f48c033fd129c231e295329bc66dbd7362e5a487e2097cf3f851fd4a582d670b6b59aac19c1368dfc5d5d1f1dc64db15ea6d2d3dbabe200000000000000000000000000000000000000000000000000000001000003d1'
  db '9981e643e9089f48979f48c033fd129c231e295329bc66dbd7362e5a487e2097cf3f851fd4a582d670b6b59aac19c1368dfc5d5d1f1dc64db15ea6d2d3dbabe200000000000000000000000000000000000000000000000000000001000003d1'
  db '24ca1637c3488d086202962df9d0a797cceab5427b8300f2fdad99371c4bc8c255debb381f4ad034cc27cb48a46449aaa87d43fdb563384b1cd20838e6fddc9f2290df206e28d718e783e5dea02c36c6a03916e163bf0510f35afd8c97bdb501'

; same geometric point, different Z representation
  db '9981e643e9089f48979f48c033fd129c231e295329bc66dbd7362e5a487e2097cf3f851fd4a582d670b6b59aac19c1368dfc5d5d1f1dc64db15ea6d2d3dbabe200000000000000000000000000000000000000000000000000000001000003d1'
  db 'ef10e9cc912dbcc7f5a8579a4910dcc986ee9f61167b7904c8b71f5e789d07511ccd066b0f1ac9ca412b5432e3d653d0b8e7013fc32168d1c9489d674d0d56720000000000000000000000000000000000000000123456be0a69d00f1faced1f'
  db '24ca1637c3488d086202962df9d0a797cceab5427b8300f2fdad99371c4bc8c255debb381f4ad034cc27cb48a46449aaa87d43fdb563384b1cd20838e6fddc9f2290df206e28d718e783e5dea02c36c6a03916e163bf0510f35afd8c97bdb501'

; P + (-P) = infinity (mont infinity: x = 0, y = 0, z = 1)
  db '9981e643e9089f48979f48c033fd129c231e295329bc66dbd7362e5a487e2097cf3f851fd4a582d670b6b59aac19c1368dfc5d5d1f1dc64db15ea6d2d3dbabe200000000000000000000000000000000000000000000000000000001000003d1'
  db '9981e643e9089f48979f48c033fd129c231e295329bc66dbd7362e5a487e209730c07ae02b5a7d298f494a6553e63ec97203a2a2e0e239b24ea1592c2c24504d00000000000000000000000000000000000000000000000000000001000003d1'
  db '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'

.end: