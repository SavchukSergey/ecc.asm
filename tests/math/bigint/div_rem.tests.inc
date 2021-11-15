macro BigIntegerDivRemTests bits, dbits {

include '../src/math/bigint/div_rem/div_rem.inc'
include '../src/math/bigint/dump/dump.inc'

BigIntegerDivRem bits, dbits
BigIntegerDump bits

__bi_div_rem_test_#bits:
virtual at rbp
.locals_start:
  .divident rb __BIG_INTEGER_BYTES_#bits
  .divisor rb __BIG_INTEGER_BYTES_#bits
  .quotient rb __BIG_INTEGER_BYTES_#bits
  .reminder rb __BIG_INTEGER_BYTES_#bits
.locals_end:
end virtual

        sub   rsp, .locals_end - .locals_start
        mov   rbp, rsp

        mov   rsi, __bi_div_rem_test.divident_#bits
        lea   rdi, [.divident]
        call  __bi_read_hex_#bits

        mov   rsi, __bi_div_rem_test.divisor_#bits
        lea   rdi, [.divisor]
        call  __bi_read_hex_#bits

        lea   rax, [.divident]
        lea   rbx, [.divisor]
        lea   rsi, [.quotient]
        lea   rdi, [.reminder]
        call  __bi_div_rem_#bits

        call    Console_WriteLine
        call    Console_WriteLine

        lea     rax, [.quotient]
        call    __bi_dump_#bits
        call    Console_WriteLine
        lea     rax, [.reminder]
        call    __bi_dump_#bits
        call    Console_WriteLine
        call    Console_WriteLine

        add   rsp, .locals_end - .locals_start
        stc
        ret
}


__bi_div_rem_test:
  .divident_512: db '7c681252935e7dd6efa7cd4d0a8aa053dd738e96180c8faed59d30df3f5404566cab2e724a66e4fa3d4def6d8a006d18f1995d9797f82e28d4c536cf7fdf76c8'
  .divisor_512   db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .quotient_512  db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .reminder_512  db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'

  .divident_256: db '7c681252935e7dd6efa7cd4d0a8aa053dd738e96180c8faed59d30df3f5404566cab2e724a66e4fa3d4def6d8a006d18f1995d9797f82e28d4c536cf7fdf76c8'
  .divisor_256   db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .quotient_256  db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'
  .reminder_256  db '000000000000000000005b68a604312f6dbc97923de9870c1a40c1ef522ff4f03852d05da086282a7bf2d62551c939e161bdb39dc003e50d204bc0ba070adfca'

  .divident_128: db '00000000000000000000000000000064'
  .divisor_128   db '00000000000000000000000000000003'
  .quotient_128  db '82c432f7597d388041e9d8c8dd6a3fe7'
  .reminder_128  db '82c432f7597d388041e9d8c8dd6a3fe7'
