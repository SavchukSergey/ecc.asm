__ec_projective_point_256_add_test:
virtual at rsp
.locals_start:
   .left ECProjectivePoint256
   .right ECProjectivePoint256
   .result ECProjectivePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__secp256k1_point_add_test'

        mov     rbx,  __ec_projective_point_256_add_test_cases
.loop:
        lea     rcx, [.left]
        lea     rdx, [rbx + 0]
        mov     r8, secp256k1
        call    ec_projective_point_256_try_read_hex

        lea     rcx, [.right]
        lea     rdx, [rbx + __EC_PROJECTIVE_POINT_256_HEX_DIGITS]
        mov     r8, secp256k1
        call    ec_projective_point_256_try_read_hex

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    ec_projective_point_256_add
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_PROJECTIVE_POINT_256_HEX_DIGITS * 2]
        lea     rdx, [.result]
        call    ec_projective_point_256_assert_equal_hex

        add     rbx, __EC_PROJECTIVE_POINT_256_HEX_DIGITS * 3
        cmp     rbx, __ec_projective_point_256_add_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_projective_point_256_add_test_cases:
  db '73c467b2018ef7022c9a162aaf43e4c4b5cb846d4c0c2ec8d1aae52195c8ae53'
  db '1cf6ac2793df7f1d72aa6b5a053956a7e61d6466c96af9b829f657dcc5b5cfc6'
  db '3204bf067b51771a4b3509ec7de9dfb84622b2cd6564dff69735bcb48377a94e'

  db 'a3686c2854ff9781d6bea653742575e0dd55c4c0cf327ce9dde25691749da421'
  db '33287fe75ee2c097b60cb96c6447c559da0bd6fb3d47f607d1cd466db8ec7823'
  db 'e57c04d41bbfc43c1572585271b82169feba725ef83b2dd4a2a3dcb08c0ded40'

  db 'c0c92c4ced50f5ec45ab32357c2310d653ec6b9fe6367930a92bd355a673a176'
  db '10663b5bb6ba9d80d48c14bd32d23d006afa905d3a5a70d79e0e11386e130387'
  db '98ba4d97152caebd8301295404011bbc5b39b298f62d73109cc21b5cd1bd5697'

.end: