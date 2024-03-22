if ~ definite bi_div_rem_256_256_guess

include '../lzcnt/bi_lzcnt_256.inc'
include '../zero/bi_zero_256.inc'
include '../copy/bi_copy_256.inc'
include '../shl/bi_shl_assign_256.inc'
include '../mul_low/bi_mul_low_256_128.inc'
include '../extend_low/bi_extend_256_128.inc'
include '../div_rem/bi_div_rem_128_64.inc'

bi_div_rem_256_256_guess:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_256
  .divisor_val rq 1

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_256

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .guess_reminder_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_256
  .guess_q rb __BIG_INTEGER_BYTES_256
  .correction rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

        mov     rcx, [.divisor]
        call    bi_lzcnt_256
        mov     [.divisor_lzcnt], rax

        mov     rcx, [.divisor]
        lea     rdx, [.divisor_shifted]
        mov     r8, [.divisor_lzcnt]
        call    bi_shl_256

        mov     rax, qword [.divisor_shifted + 24]
        inc     rax ; todo: check cases 0xffff_ffff_ffff_ffff
        mov     [.divisor_val], rax
;2^63 < divisor_val < 2^64. Check overflow

        mov     rcx, [.quotient]
        call    bi_zero_256

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        call    bi_copy_256

.loop:
        mov     rcx, [.remainder]
        mov     rdx, [.divisor]
        call    bi_cmp_256_256
        jb      .loop_ok

        mov     rcx, [.remainder]
        call    bi_lzcnt_256
        mov     [.remainder_lzcnt], rax

        mov     rcx, [.remainder]
        lea     rdx, [.remainder_shifted]
        mov     r8, [.remainder_lzcnt]
        call    bi_shl_256


        lea     rcx, qword [.remainder_shifted + 16]
        mov     rdx, [.divisor_val]
        lea     r8, [.guess_128]
        lea     r9, [.guess_reminder_128]
        call    bi_div_rem_128_64 ;todo: benchmark 256_64 over 128_64 over 64_32
;max guess = (2^128 - 1) / 2^63 = 2^64. Check overflow

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

        mov     rcx, [.divisor]
        lea     rdx, qword [.guess_128 + 0]
        lea     r8, [.delta]
        call    bi_mul_low_256_128

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

        mov     rcx, [.remainder]
        lea     rdx, [.delta]
        call    bi_sub_assign_256_256

        mov     rcx, [.quotient]
        lea     rdx, [.guess_q]
        call    bi_add_assign_256_256
        jmp     .loop
.loop_ok:
        leave
        ret

end if