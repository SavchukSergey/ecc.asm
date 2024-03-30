if ~ definite bi_div_rem_128_128_guess

include 'bi_div_rem_guess_64.inc'

include '../inc/bi_inc_assign_128.inc'
include '../lzcnt/bi_lzcnt_128.inc'
include '../zero/bi_zero_128.inc'
include '../copy/bi_copy_128.inc'
include '../cmp/bi_cmp_128_128.inc'
include '../shl/bi_shl_128.inc'
include '../shl/bi_shl_assign_128.inc'
include '../sub/bi_sub_assign_128_128.inc'
include '../mul_low/bi_mul_low_128_64.inc'
include '../div_rem/bi_div_128_64.inc'

bi_div_rem_128_128_guess:
    DivRemGuess64_Prepare 128, 128
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_128

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_128

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_128
  .correction rq 1
  label .locals_end
end virtual
        DivRemGuess64_Prolog 128, 128
        DivRemGuess64_DivisorLzcnt 128, 128

        cmp     rax, 128 - 64
        jb      .divisor_large
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     rdx, [rdx + 0]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_128_64
        jmp     .end
.divisor_large:
;divisor >= 2^64
;quotient as well as guess will be less than 2^64

        DivRemGuess64_PrepareLoop 128, 128
        DivRemGuess64_ShiftDivisor 128, 128
.loop:
if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.loop_msg]
        call    Console_WriteString
end if
        DivRemGuess64_DumpRemainder 128, 128
        DivRemGuess64_ShiftRemainder 128, 128
        DivRemGuess64_DumpRemainderShifted 128, 128
        DivRemGuess64_Guess 128, 128
        DivRemGuess64_DumpGuess 128, 128
        DivRemGuess64_FixGuess 128, 128
        DivRemGuess64_DumpGuessFixed 128, 128

        DivRemGuess64_CalcDelta 128, 128
        DivRemGuess64_DumpDelta 128, 128

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        DivRemGuess64_ShiftDelta 128, 128
        DivRemGuess64_ShiftGuess 128, 128
.correction_2_ok:

        DivRemGuess64_DumpDeltaShifted 128, 128
        DivRemGuess64_ApplyDelta 128, 128

        DivRemGuess64_DumpNewValues 128, 128

        jmp     .loop
.loop_ok:
.end:
        add     rsp, .locals_end - .locals_start
        ret
        DivRemGuess64_RecheckOnce 128, 128

if definite BI_DEV_REM_128_128_GUESS_DEBUG
  .loop_msg:               db '----------------------------------', 13, 10, 0

end if

end if