if ~ definite bi_div_rem_512_128_guess

include 'bi_div_rem_guess_64.inc'

include '../lzcnt/bi_lzcnt_128.inc'
include '../lzcnt/bi_lzcnt_512.inc'
include '../zero/bi_zero_512.inc'
include '../copy/bi_copy_512.inc'
include '../shl/bi_shl_128.inc'
include '../shl/bi_shl_512.inc'
include '../shl/bi_shl_assign_512.inc'
include '../shr/bi_shr_assign_128.inc'
include '../sub/bi_sub_assign_512_128.inc'
include '../add/bi_add_assign_512_512.inc'
include '../sub/bi_sub_assign_512_512.inc'
include '../extend_low/bi_extend_512_128.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_512_64.inc'
include '../inc/bi_inc_assign_512.inc'

;BI_DEV_REM_512_128_GUESS_DEBUG = 1

if definite BI_DEV_REM_512_128_GUESS_DEBUG
  include 'bi_dev_rem_debug.inc'
end if


bi_div_rem_512_128_guess:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_128

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_512

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_512
  .guess_q rb __BIG_INTEGER_BYTES_512
  .correction rq 1
  label .locals_end
end virtual
        DivRemGuess64_Prolog 512, 128

        mov     rcx, [.divisor]
        call    bi_lzcnt_128
        add     rax, 384
        mov     [.divisor_lzcnt], rax

        cmp     rax, 512 - 64
        jb      .divisor_large
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     rdx, [rdx + 0]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_512_64
        jmp     .end
.divisor_large:
        mov     rcx, [.quotient]
        call    bi_zero_512

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        call    bi_copy_512

        DivRemGuess64_ShiftDivisor 512, 128
        DivRemGuess64_Prepare 512, 128
.loop:
if definite BI_DEV_REM_512_128_GUESS_DEBUG
        lea     rsi, [.loop_msg]
        call    Console_WriteString
end if
        DivRemGuess64_DumpRemainder 512, 128
        DivRemGuess64_ShiftRemainder 512, 128
        DivRemGuess64_DumpRemainderShifted 512, 128
        DivRemGuess64_Guess 512, 128
        DivRemGuess64_DumpGuess 512, 128
        DivRemGuess64_FixGuess 512, 128

if definite BI_DEV_REM_512_128_GUESS_DEBUG
        lea     rcx, qword [.guess_128]
        call    bi_div_rem_dump_guess_corrected_128
end if

        lea     rcx, [.delta]
        call    bi_zero_512

        DivRemGuess64_CalcDelta 512, 128
        DivRemGuess64_DumpDelta 512, 128

        lea     rcx, [.guess_q]
        lea     rdx, [.guess_128]
        call    bi_extend_512_128 ;todo: guess_q and guess_128 can be combined if guess_q is cleared at start. Check everywhere

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        DivRemGuess64_ShiftDelta 512, 128

        lea     rcx, [.guess_q]
        mov     rdx, [.correction]
        call    bi_shl_assign_512 ; shl_assign_384?
.correction_2_ok:

        DivRemGuess64_DumpDeltaShifted 512, 128
        DivRemGuess64_ApplyDelta 512, 128
        DivRemGuess64_DumpNewValues 512, 128

        jmp     .loop
.loop_ok:
.end:
        add     rsp, .locals_end - .locals_start
        ret
        DivRemGuess64_RecheckOnce 512, 128

if definite BI_DEV_REM_512_128_GUESS_DEBUG
  .loop_msg:               db '----------------------------------', 13, 10, 0
end if

end if