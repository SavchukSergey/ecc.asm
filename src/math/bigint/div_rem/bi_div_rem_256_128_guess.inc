if ~ definite bi_div_rem_256_128_guess

include 'bi_div_rem_guess_64.inc'

include '../lzcnt/bi_lzcnt_256.inc'
include '../zero/bi_zero_256.inc'
include '../copy/bi_copy_256.inc'
include '../cmp/bi_cmp_128_128.inc'
include '../shl/bi_shl_256.inc'
include '../shl/bi_shl_assign_256.inc'
include '../sub/bi_sub_assign_256_128.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../mul_low/bi_mul_low_256_128.inc'
include '../extend_low/bi_extend_256_128.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_256_64.inc'
include '../inc/bi_inc_assign_256.inc'

;BI_DEV_REM_256_128_GUESS_DEBUG = 1

if definite BI_DEV_REM_256_128_GUESS_DEBUG
  include 'bi_dev_rem_debug.inc'
end if

bi_div_rem_256_128_guess:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_128

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_256

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_256
  .guess_q rb __BIG_INTEGER_BYTES_256
  .correction rq 1
  label .locals_end
end virtual
        DivRemGuess64_Prolog 256, 128

        mov     rcx, [.divisor]
        call    bi_lzcnt_128
        add     rax, 128
        mov     [.divisor_lzcnt], rax

        cmp     rax, 256 - 64
        jb      .divisor_large
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     rdx, [rdx + 0]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_256_64
        jmp     .end
.divisor_large:
        mov     rcx, [.quotient]
        call    bi_zero_256

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        call    bi_copy_256


        DivRemGuess64_ShiftDivisor 256, 128

.loop:
if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.loop_msg]
        call    Console_WriteString

        mov     rcx, [.remainder]
        call    bi_div_rem_dump_remainder_256
end if

        DivRemGuess64_ShiftRemainder 256, 128
        DivRemGuess64_DumpRemainderShifted 256, 128
        DivRemGuess64_Guess 256, 128
        DivRemGuess64_DumpGuess 256, 128
        DivRemGuess64_FixGuess 256, 128

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rcx, qword [.guess_128]
        call    bi_div_rem_dump_guess_corrected_128
end if

        mov     rcx, [.divisor]
        lea     rdx, qword [.guess_128 + 0]
        lea     r8, [.delta]
        call    bi_mul_128_128

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rcx, [.delta]
        call    bi_div_rem_dump_delta_256
end if

        lea     rcx, [.guess_q]
        lea     rdx, [.guess_128]
        call    bi_extend_256_128

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        lea     rcx, [.delta + 0]
        mov     rdx, [.correction]
        call    bi_shl_assign_256

        lea     rcx, [.guess_q]
        mov     rdx, [.correction]
        call    bi_shl_assign_256
.correction_2_ok:

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.delta_corrected_msg]
        call    Console_WriteString
        lea     rcx, [.delta]
        call    Console_WriteUInt256Hex
        call    Console_WriteLine
end if

        mov     rcx, [.remainder]
        lea     rdx, [.delta]
        call    bi_sub_assign_256_256

        mov     rcx, [.quotient]
        lea     rdx, [.guess_q]
        call    bi_add_assign_256_256

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.new_quotient_msg]
        call    Console_WriteString
        mov     rcx, [.quotient]
        call    Console_WriteUInt256Hex
        call    Console_WriteLine

        lea     rsi, [.new_remainder_msg]
        call    Console_WriteString
        mov     rcx, [.remainder]
        call    Console_WriteUInt256Hex
        call    Console_WriteLine
end if

        jmp     .loop
.loop_ok:
.end:
        add     rsp, .locals_end - .locals_start
        ret
        DivRemGuess64_RecheckOnce 256, 128

if definite BI_DEV_REM_256_128_GUESS_DEBUG
  .loop_msg:               db '----------------------------------', 13, 10, 0
  .delta_corrected_msg:    db 'delta (corrected): ', 0
  .new_quotient_msg:       db 'new quotient:      ', 0
  .new_remainder_msg:      db 'new remainder:     ', 0

end if

end if