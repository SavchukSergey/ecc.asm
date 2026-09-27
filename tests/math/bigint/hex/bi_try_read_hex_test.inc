if ~ definite __bi_try_read_hex_256_test_core

; input:
;   rcx - pointer to hex string (NUL-terminated)
;   rdx - expected return code (0 or 1)
;   r8  - pointer to expected value hex string, or 0 to skip value check
__bi_try_read_hex_256_test_core:
virtual at rsp
.locals_start:
  .value BigInteger256
  .hex rq 1
  .expected_rc rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_try_read_hex_256_test_core'
    CheckRegAligned rcx, '__bi_try_read_hex_256_test_core rcx'

        mov     [.hex], rcx
        mov     [.expected_rc], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_256

        mov     rcx, [.expected_rc]
        mov     rdx, rax
        call    bi_assert_equal_64

        cmp     qword [.expected_hex], 0
        je      .no_value_check
        mov     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_256
.no_value_check:

        call    test_context_start_measure
.chunk_loop:
        mov     rcx, [.hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_256
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        add     rsp, .locals_end - .locals_start
        ret

end if

__bi_try_read_hex_256_test:
        sub     rsp, 8

        lea     rcx, [.valid_digits_hex]
        mov     rdx, 1
        lea     r8, [.valid_digits_hex]
        call    __bi_try_read_hex_256_test_core

        lea     rcx, [.valid_zeros_hex]
        mov     rdx, 1
        lea     r8, [.valid_zeros_hex]
        call    __bi_try_read_hex_256_test_core

        lea     rcx, [.valid_max_hex]
        mov     rdx, 1
        lea     r8, [.valid_max_hex]
        call    __bi_try_read_hex_256_test_core

        lea     rcx, [.invalid_zz_hex]
        xor     rdx, rdx
        xor     r8, r8
        call    __bi_try_read_hex_256_test_core

        lea     rcx, [.invalid_trailing_g_hex]
        xor     rdx, rdx
        xor     r8, r8
        call    __bi_try_read_hex_256_test_core

        lea     rcx, [.invalid_empty_hex]
        xor     rdx, rdx
        xor     r8, r8
        call    __bi_try_read_hex_256_test_core

        lea     rcx, [.invalid_short_hex]
        xor     rdx, rdx
        xor     r8, r8
        call    __bi_try_read_hex_256_test_core

        add     rsp, 8
        ret

; error paths must return 0 without corrupting the stack
.invalid_zz_hex          db 'zz', 0
.invalid_trailing_g_hex  db '0123456789abcdef0123456789abcdef0123456789abcdefg0123456789abcde', 0
.invalid_empty_hex       db 0
.invalid_short_hex       db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff', 0

align 16
.valid_digits_hex        db '0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef', 0
.valid_zeros_hex         db '0000000000000000000000000000000000000000000000000000000000000000', 0
.valid_max_hex           db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff', 0
