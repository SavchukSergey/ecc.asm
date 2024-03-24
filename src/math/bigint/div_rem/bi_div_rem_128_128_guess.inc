if ~ definite bi_div_rem_128_128_guess

include '../lzcnt/bi_lzcnt_128.inc'
include '../zero/bi_zero_128.inc'
include '../copy/bi_copy_128.inc'
include '../cmp/bi_cmp_128_128.inc'
include '../shl/bi_shl_128.inc'
include '../shl/bi_shl_assign_128.inc'
include '../mul_low/bi_mul_low_128_128.inc'
include '../div_rem/bi_div_128_64.inc'
include '../inc/bi_inc_assign_128.inc'

;BI_DEV_REM_128_128_GUESS_DEBUG = 1

bi_div_rem_128_128_guess:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_128
  .divisor_val rq 1

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_128

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_128
  .correction rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        call    Console_WriteLine
        lea     rsi, [.dividend_msg]
        call    Console_WriteString
        mov     rcx, [.dividend]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine

        lea     rsi, [.divisor_msg]
        call    Console_WriteString
        mov     rcx, [.divisor]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        mov     rcx, [.divisor]
        call    bi_lzcnt_128
        mov     [.divisor_lzcnt], rax

        cmp     rax, 128 - 64
        jb      .divisor_large
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     rdx, [ rdx + 0]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_128_64
        jmp     .end
.divisor_large:

        mov     rcx, [.divisor]
        lea     rdx, [.divisor_shifted]
        mov     r8, [.divisor_lzcnt]
        call    bi_shl_128

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.divisor_shifted_msg]
        call    Console_WriteString
        lea     rcx, [.divisor_shifted]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if
        mov     rax, qword [.divisor_shifted + 8]
        inc     rax ; todo: check cases 0xffff_ffff_ffff_ffff
        mov     [.divisor_val], rax
;2^63 < divisor_val < 2^64. Check overflow

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.divisor_val_msg]
        call    Console_WriteString
        mov     rcx, [.divisor_val]
        call    Console_WriteUInt64Hex
        call    Console_WriteLine
end if

        mov     rcx, [.quotient]
        call    bi_zero_128

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        call    bi_copy_128

.loop:
if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.loop_msg]
        call    Console_WriteString

        lea     rsi, [.remainder_msg]
        call    Console_WriteString
        mov     rcx, [.remainder]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        call    bi_cmp_128_128
        jb      .loop_ok
        je      .loop_equal

        mov     rcx, [.remainder]
        call    bi_lzcnt_128
        mov     [.remainder_lzcnt], rax

        mov     rcx, [.remainder]
        lea     rdx, [.remainder_shifted]
        mov     r8, [.remainder_lzcnt]
        call    bi_shl_128

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.remainder_shifted_msg]
        call    Console_WriteString
        lea     rcx, [.remainder_shifted]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        lea     rcx, qword [.remainder_shifted + 0]
        mov     rdx, [.divisor_val]
        lea     r8, [.guess_128]
        call    bi_div_128_64

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.guess_msg]
        call    Console_WriteString
        lea     rcx, [.guess_128]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        mov     rax, [.remainder_lzcnt]
        sub     rax, [.divisor_lzcnt]
        add     rax, 64
        mov     [.correction], rax

        cmp     [.correction], 0
        jle     .correction_ok
        lea     rcx, [.guess_128]
        mov     rdx, [.correction]
        call    bi_shr_assign_128
        mov     [.correction], 0
.correction_ok:

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.guess_corrected_msg]
        call    Console_WriteString
        lea     rcx, [.guess_128]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        mov     rcx, [.divisor]
        lea     rdx, qword [.guess_128]
        lea     r8, [.delta]
        call    bi_mul_low_128_128

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.delta_msg]
        call    Console_WriteString
        lea     rcx, [.delta]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        lea     rcx, [.delta + 0]
        mov     rdx, [.correction]
        call    bi_shl_assign_128

        lea     rcx, [.guess_128]
        mov     rdx, [.correction]
        call    bi_shl_assign_128
.correction_2_ok:

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.delta_corrected_msg]
        call    Console_WriteString
        lea     rcx, [.delta]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        mov     rcx, [.remainder]
        lea     rdx, [.delta]
        call    bi_sub_assign_128_128

        mov     rcx, [.quotient]
        lea     rdx, [.guess_128]
        call    bi_add_assign_128_128

if definite BI_DEV_REM_128_128_GUESS_DEBUG
        lea     rsi, [.new_remainder_msg]
        call    Console_WriteString
        mov     rcx, [.remainder]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        jmp     .loop
.loop_ok:
.end:
        leave
        ret
.loop_equal:
        mov     rcx, [.quotient]
        call    bi_inc_assign_128
        mov     rcx, [.remainder]
        call    bi_zero_128
        jmp     .loop_ok

if definite BI_DEV_REM_128_128_GUESS_DEBUG
  .dividend_msg:           db 'dividend:          ', 0
  .divisor_msg:            db 'divisor:           ', 0
  .divisor_shifted_msg:    db 'divisor shifted:   ', 0
  .divisor_val_msg:        db 'divisor val:       ', 0
  .loop_msg:               db '----------------------------------', 13, 10, 0
  .remainder_msg:          db 'remainder:         ', 0
  .remainder_shifted_msg:  db 'remainder shifted: ', 0
  .guess_msg:              db 'guess:             ', 0
  .guess_corrected_msg:    db 'guess (corrected): ', 0
  .delta_msg:              db 'delta:             ', 0
  .delta_corrected_msg:    db 'delta (corrected): ', 0
  .new_remainder_msg:      db 'new remainder:     ', 0

end if

end if