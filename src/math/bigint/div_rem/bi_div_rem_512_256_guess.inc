if ~ definite bi_div_rem_512_256_guess

include 'bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_384_384.inc'
include '../cmp/bi_cmp_256_256.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_512_64.inc'
include '../div_rem/bi_div_rem_512_128.inc'
include '../lzcnt/bi_lzcnt_256.inc'
include '../lzcnt/bi_lzcnt_512.inc'
include '../shl/bi_shl_256.inc'
include '../shl/bi_shl_512.inc'
include '../sub/bi_sub_assign_512_256.inc'
include '../sub/bi_sub_assign_512_512.inc'
include '../inc/bi_inc_assign_384.inc'
include '../mul/bi_mul_256_128.inc'

bi_div_rem_512_256_guess:
    DivRemGuess64_Prepare 512, 256
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_256

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_512

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_512
  .guess_q rb __BIG_INTEGER_BYTES_512
  .correction rq 1
  label .locals_end
end virtual
        DivRemGuess64_Prolog 512, 256
        DivRemGuess64_DivisorLzcnt 512, 256

        cmp     rax, 512 - 128
        jb      .divisor_large
        cmp     rax, 512 - 64
        jb      .divisor_middle
.divisor_small:
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     rdx, [rdx + 0]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_512_64
        jmp     .end
.divisor_middle:
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_512_128
        jmp     .end
.divisor_large:

        DivRemGuess64_PrepareLoop 512, 256
        DivRemGuess64_ShiftDivisor 512, 256
.loop:
if definite BI_DEV_REM_512_256_GUESS_DEBUG
        lea     rsi, [.loop_msg]
        call    Console_WriteString
end if
        DivRemGuess64_DumpRemainder 512, 256
        DivRemGuess64_ShiftRemainder 512, 256
        DivRemGuess64_DumpRemainderShifted 512, 256
        DivRemGuess64_Guess 512, 256
        DivRemGuess64_DumpGuess 512, 256
        DivRemGuess64_FixGuess 512, 256
        DivRemGuess64_DumpGuessFixed 512, 256

        DivRemGuess64_CalcDelta 512, 256
        DivRemGuess64_DumpDelta 512, 256

        lea     rcx, [.guess_q]
        lea     rdx, [.guess_128]
        call    bi_extend_512_128

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        DivRemGuess64_ShiftDelta 512, 256
        DivRemGuess64_ShiftGuess 512, 256
.correction_2_ok:

        DivRemGuess64_DumpDeltaShifted 512, 256
        DivRemGuess64_ApplyDelta 512, 256
        DivRemGuess64_DumpNewValues 512, 256

        jmp     .loop
.loop_ok:
.end:
        add     rsp, .locals_end - .locals_start
        ret
        DivRemGuess64_RecheckOnce 512, 256

if definite BI_DEV_REM_512_256_GUESS_DEBUG
  .loop_msg:               db '----------------------------------', 13, 10, 0

end if

end if