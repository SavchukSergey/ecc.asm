macro BigIntegerDivRemTests bits, dbits {

include '../src/math/bigint/div_rem/div_rem.inc'

BigIntegerDivRem bits, dbits

__bi_div_rem_test_#bits:
virtual at rsp
.locals_start:
  .divident rb __BIG_INTEGER_BYTES_#bits
  .divisor rb __BIG_INTEGER_BYTES_#bits
  .actual_quotient rb __BIG_INTEGER_BYTES_#bits
  .actual_reminder rb __BIG_INTEGER_BYTES_#bits
  .expected_quotient rb __BIG_INTEGER_BYTES_#bits
  .expected_reminder rb __BIG_INTEGER_BYTES_#bits
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov   rsi, __bi_div_rem_test.divident_#bits
        lea   rdi, [.divident]
        call  __bi_read_hex_#bits

        mov   rsi, __bi_div_rem_test.divisor_#bits
        lea   rdi, [.divisor]
        call  __bi_read_hex_#bits

        mov   rsi, __bi_div_rem_test.quotient_#bits
        lea   rdi, [.expected_quotient]
        call  __bi_read_hex_#bits

        mov   rsi, __bi_div_rem_test.reminder_#bits
        lea   rdi, [.expected_reminder]
        call  __bi_read_hex_#bits

        lea   rax, [.divident]
        lea   rbx, [.divisor]
        lea   rdi, [.actual_quotient]
        lea   rsi, [.actual_reminder]
        call  test_context_start_measure
        call  __bi_div_rem_#bits
        call  test_context_end_measure

        lea     rax, [.expected_quotient]
        lea     rbx, [.actual_quotient]
        call    __bi_cmp_#bits
        je     .failed

        lea     rax, [.expected_reminder]
        lea     bx, [.actual_reminder]
        call    __bi_cmp_#bits
        jne     .failed
.passed:
        leave
        clc
        ret
.failed:
        leave
        stc
        ret
}


__bi_div_rem_test:
  .divident_512: db '7c681252935e7dd6efa7cd4d0a8aa053dd738e96180c8faed59d30df3f5404566cab2e724a66e4fa3d4def6d8a006d18f1995d9797f82e28d4c536cf7fdf76c8'
  .divisor_512   db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .quotient_512  db '0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000015C69E7ABD513E06BE959'
  .reminder_512  db '000000000000000000002A515773A0A4EDF99CBEC419428840CB7FDC7F825957CF563C5E5DD9B4C07900DDB317832E49A462E6B66121D630002BC25FDDFACF8E'

  .divident_256: db '7c681252935e7dd6efa7cd4d0a8aa053dd738e96180c8faed59d30df3f5404566cab2e724a66e4fa3d4def6d8a006d18f1995d9797f82e28d4c536cf7fdf76c8'
  .divisor_256   db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .quotient_256  db '000000000000000000000000000000000000000000015C69E7ABD513E06BE959'
  .reminder_256  db '000000000000000000002A515773A0A4EDF99CBEC4198F3020FAC4B0A6696CE6'

  .divident_128: db '8a687e85d66a5db0eccf631fa58a556d'
  .divisor_128   db '000000000259b679bade237c1fc5dd53'
  .quotient_128  db '00000000000000000000003AE2D4A9B9'
  .reminder_128  db '0000000000043DF4132FAB6681B59972'
