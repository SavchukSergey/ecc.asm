include '../src/math/bigint/div_rem/bi_div_rem_256_128.inc'

__bi_div_rem_256_128_test:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .dividend rb __BIG_INTEGER_BYTES_256
  .divisor rb __BIG_INTEGER_BYTES_256
  .quotient rb __BIG_INTEGER_BYTES_256
  .remainder rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        lea     rbx, [__bi_div_rem_256_128_test_cases]
.loop:        
        lea     rcx, [rbx]
        lea     rdx, [rbx + 64]
        lea     r8, [rbx + 128]
        lea     r9, [rbx + 192]

        push    rbx
        
        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_256

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_256

        lea     rcx, [.dividend]
        lea     rdx, [.divisor]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    test_context_start_measure
        call    bi_div_rem_256_128
        call    test_context_end_measure

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_256
        jc      .fail

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_256
        jc      .fail

        pop     rbx
        add     rbx, 256
        cmp     rbx, __bi_div_rem_256_128_test_cases.end
        jb      .loop
.pass:
        leave
        clc
        ret
.fail:
        leave
        stc
        ret


__bi_div_rem_256_128_test_cases:
  db '0000000000000000000000000000000000000000000000000000000000000000'
  db '0000000000000000000000000000000000000000000000000000000000000001'
  db '0000000000000000000000000000000000000000000000000000000000000000'
  db '0000000000000000000000000000000000000000000000000000000000000000'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '0000000000000000000000000000000000000000000000000000000000000001'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '0000000000000000000000000000000000000000000000000000000000000000'

  db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '0000000000000000000000000000000000000000000000000000000000000001'
  db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '0000000000000000000000000000000000000000000000000000000000000000'

  db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '0000000000000000000000000000000000000000000000000000000000000003'
  db '447A57675A8C8FD6B1FD377D8E6C9D95F16752EFAC6E5A7300B67F843DFA1FF7'
  db '0000000000000000000000000000000000000000000000000000000000000000'

  db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '0000000000000000000000000000000000000000000000000000000000000006'
  db '223d2bb3ad4647eb58fe9bbec7364ecaf8b3a977d6372d39805b3fc21efd0ffb'
  db '0000000000000000000000000000000000000000000000000000000000000003'


  db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '000000000000000000000000000000000000000000000000000000000000006e'
  db '01de19a80e1b1b3212d160ee7a9340ce8fe49039bc8ea5603a3385ce144ef790'
  db '0000000000000000000000000000000000000000000000000000000000000005'


  db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f5902237e8cb9ee5fe5'
  db '000000000000000000000000000000006e3be8abd2e089ed812475be9b51c3cf'
  db '00000000000000000000000000000001dd15d2c949aeda9ea5c7f77e1c7d2c3b'
  db '000000000000000000000000000000001294f2aac703fc89ac5cb7b3a05bab30'


  .end:

