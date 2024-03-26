if ~ definite bi_div_rem_256_128_guess

include '../lzcnt/bi_lzcnt_256.inc'
include '../zero/bi_zero_256.inc'
include '../copy/bi_copy_256.inc'
include '../cmp/bi_cmp_256_256.inc'
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
        sub     rsp, .locals_end - .locals_start
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        call    Console_WriteLine
        lea     rsi, [.dividend_msg]
        call    Console_WriteString
        mov     rcx, [.dividend]
        call    Console_WriteUInt256Hex
        call    Console_WriteLine

        lea     rsi, [.divisor_msg]
        call    Console_WriteString
        mov     rcx, [.divisor]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

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


        mov     rcx, [.divisor]
        lea     rdx, [.divisor_shifted]
        mov     r8, [.divisor_lzcnt]
        sub     r8, 128
        call    bi_shl_128

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.divisor_shifted_msg]
        call    Console_WriteString
        lea     rcx, [.divisor_shifted]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

.loop:
if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.loop_msg]
        call    Console_WriteString

        lea     rsi, [.remainder_msg]
        call    Console_WriteString
        mov     rcx, [.remainder]
        call    Console_WriteUInt256Hex
        call    Console_WriteLine
end if

        mov     rcx, [.remainder]
        call    bi_lzcnt_256
        mov     [.remainder_lzcnt], rax

        cmp     rax, [.divisor_lzcnt]
        jae     .recheck_once

        mov     rcx, [.remainder]
        lea     rdx, [.remainder_shifted]
        mov     r8, [.remainder_lzcnt]
        call    bi_shl_256

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.remainder_shifted_msg]
        call    Console_WriteString
        lea     rcx, [.remainder_shifted]
        call    Console_WriteUInt256Hex
        call    Console_WriteLine
end if

        mov     rdx, qword [.divisor_shifted + 8]
        inc     rdx
        jnz     .divisor_not_max
.divisor_max:
        mov     rcx, qword [.remainder_shifted + 24]; divide by 2^64
        mov     qword [.guess_128], rcx
        mov     qword [.guess_128 + 8], 0
        jmp     .divisor_ok
.divisor_not_max:
        lea     rcx, qword [.remainder_shifted + 16]
        lea     r8, [.guess_128]
        call    bi_div_128_64
.divisor_ok:

if definite BI_DEV_REM_256_128_GUESS_DEBUG
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

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.guess_corrected_msg]
        call    Console_WriteString
        lea     rcx, [.guess_128]
        call    Console_WriteUInt128Hex
        call    Console_WriteLine
end if

        mov     rcx, [.divisor]
        lea     rdx, qword [.guess_128 + 0]
        lea     r8, [.delta]
        call    bi_mul_128_128

if definite BI_DEV_REM_256_128_GUESS_DEBUG
        lea     rsi, [.delta_msg]
        call    Console_WriteString
        lea     rcx, [.delta]
        call    Console_WriteUInt256Hex
        call    Console_WriteLine
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
.recheck_once:
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        call    bi_cmp_256_128
        jb      .end
        mov     rcx, [.quotient]
        call    bi_inc_assign_256
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        call    bi_sub_assign_256_128
        jmp     .end

if definite BI_DEV_REM_256_128_GUESS_DEBUG
  .dividend_msg:           db 'dividend:          ', 0
  .divisor_msg:            db 'divisor:           ', 0
  .divisor_shifted_msg:    db 'divisor shifted:   ', 0
  .loop_msg:               db '----------------------------------', 13, 10, 0
  .remainder_msg:          db 'remainder:         ', 0
  .remainder_shifted_msg:  db 'remainder shifted: ', 0
  .guess_msg:              db 'guess:             ', 0
  .guess_corrected_msg:    db 'guess (corrected): ', 0
  .delta_msg:              db 'delta:             ', 0
  .delta_corrected_msg:    db 'delta (corrected): ', 0
  .new_quotient_msg:       db 'new quotient:      ', 0
  .new_remainder_msg:      db 'new remainder:     ', 0

end if

end if