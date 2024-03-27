if ~ definite bi_div_rem_256_256_guess

include '../lzcnt/bi_lzcnt_256.inc'
include '../zero/bi_zero_256.inc'
include '../copy/bi_copy_256.inc'
include '../cmp/bi_cmp_256_256.inc'
include '../shl/bi_shl_256.inc'
include '../shl/bi_shl_assign_256.inc'
include '../mul_low/bi_mul_low_256_128.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_256_128.inc'
include '../div_rem/bi_div_rem_256_64.inc'
include '../inc/bi_inc_assign_256.inc'

;BI_DEV_REM_256_256_GUESS_DEBUG = 1

if definite BI_DEV_REM_256_256_GUESS_DEBUG
  include 'bi_dev_rem_debug.inc'
end if

bi_div_rem_256_256_guess:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_256

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_256

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_256
  .correction rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

if definite BI_DEV_REM_256_256_GUESS_DEBUG
        call    Console_WriteLine

        mov     rcx, [.dividend]
        call    bi_div_rem_dump_dividend_256

        mov     rcx, [.divisor]
        call    bi_div_rem_dump_divisor_256

end if

        mov     rcx, [.divisor]
        call    bi_lzcnt_256
        mov     [.divisor_lzcnt], rax

        cmp     rax, 256 - 128
        jb      .divisor_large
        cmp     rax, 256 - 64
        jb      .divisor_middle
.divisor_small:
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     rdx, [rdx + 0]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_256_64
        jmp     .end
.divisor_middle:
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_256_128
        jmp     .end
.divisor_large:
;divisor >= 2^128
;quotient as well as guess will be less than 2^128

        mov     rcx, [.quotient]
        call    bi_zero_256

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        call    bi_copy_256


        mov     rcx, [.divisor]
        lea     rdx, [.divisor_shifted]
        mov     r8, [.divisor_lzcnt]
        call    bi_shl_256

if definite BI_DEV_REM_256_256_GUESS_DEBUG
        lea     rcx, [.divisor_shifted]
        call    bi_div_rem_dump_divisor_shifted_256
end if

.loop:
if definite BI_DEV_REM_256_256_GUESS_DEBUG
        lea     rsi, [.loop_msg]
        call    Console_WriteString

        mov     rcx, [.remainder]
        call    bi_div_rem_dump_remainder_256
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

if definite BI_DEV_REM_256_256_GUESS_DEBUG
        lea     rcx, [.remainder_shifted]
        call    bi_div_rem_dump_remainder_shifted_256
end if

        mov     rdx, qword [.divisor_shifted + 24]
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

if definite BI_DEV_REM_256_256_GUESS_DEBUG
        lea     rcx, [.guess_128]
        call    bi_div_rem_dump_guess_128
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

if definite BI_DEV_REM_256_256_GUESS_DEBUG
        lea     rcx, qword [.guess_128]
        call    bi_div_rem_dump_guess_corrected_128
end if

        mov     rcx, [.divisor]
        lea     rdx, qword [.guess_128 + 0]
        lea     r8, [.delta]
        call    bi_mul_low_256_128

if definite BI_DEV_REM_256_256_GUESS_DEBUG
        lea     rcx, [.delta]
        call    bi_div_rem_dump_delta_256
end if

        cmp     [.correction], 0
        jz     .correction_2_ok
        neg     [.correction]

        lea     rcx, [.delta + 0]
        mov     rdx, [.correction]
        call    bi_shl_assign_256

        lea     rcx, [.guess_128]
        mov     rdx, [.correction]
        call    bi_shl_assign_128
.correction_2_ok:

if definite BI_DEV_REM_256_256_GUESS_DEBUG
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
        lea     rdx, [.guess_128]
        call    bi_add_assign_128_128

if definite BI_DEV_REM_256_256_GUESS_DEBUG
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
        call    bi_cmp_256_256
        jb      .end
        mov     rcx, [.quotient]
        call    bi_inc_assign_128
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        call    bi_sub_assign_256_256
        jmp     .end

if definite BI_DEV_REM_256_256_GUESS_DEBUG
  .loop_msg:               db '----------------------------------', 13, 10, 0
  .delta_corrected_msg:    db 'delta (corrected): ', 0
  .new_quotient_msg:       db 'new quotient:      ', 0
  .new_remainder_msg:      db 'new remainder:     ', 0

end if

end if