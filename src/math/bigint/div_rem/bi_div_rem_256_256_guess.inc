if ~ definite bi_div_rem_256_256_guess

include '../lzcnt/bi_lzcnt_256.inc'
include '../zero/bi_zero_256.inc'
include '../copy/bi_copy_256.inc'
include '../shl/bi_shl_assign_256.inc'

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

  .guess_u64 rq 1
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
        call    bi_shl_assign_256
        mov     rax, qword [.divisor_shifted + 24]
        inc     rax ; todo: check cases 0xffff_ffff_ffff_ffff
        mov     [.divisor_val], rax

        mov     rcx, [.quotient]
        call    bi_zero_256

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        call    bi_copy_256

.loop:
        mov     rcx, [.remainder]
        call    bi_lzcnt_256
        mov     [.remainder_lzcnt], rax

        mov     rcx, [.remainder]
        lea     rdx, [.remainder_shifted]
        mov     r8, [.remainder_lzcnt]
        call    bi_shl_assign_256

        mov     rdx, qword [.remainder_shifted + 24]
        mov     rax, qword [.remainder_shifted + 16]
        div     [.divisor_val] ;todo: can cause overflow use bi_div_rem_128_128?
        mov     [.guess_u64], rax

        mov     rax, [.remainder_lzcnt]
        sub     rax, [.divisor_lzcnt]
        add     rax, 64
        mov     [.correction], rax

        cmp     [.correction], 0
        jae     .correction_ok
        mov     rcx, [.correction]
        shr     [.guess_u64], cl
        mov     [.correction], 0
.correction_ok:

        leave
        ret

end if