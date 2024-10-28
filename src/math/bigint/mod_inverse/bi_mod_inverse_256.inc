if ~ definite bi_mod_inverse_256

include '../div_rem/bi_div_rem_256_256.inc'
include '../one/bi_one_512.inc'

;Calculates modular inverse
;input:
;  rcx - bi256 value.
;  rdx - bi256 modulus
;  r8 - bi256 result
bi_mod_inverse_256:
virtual at rsp
.locals_start:
  .s0 BigInteger256
  .s1 BigInteger256
  .s2 BigInteger256
  .r0 BigInteger256
  .r1 BigInteger256
  .r2 BigInteger256
  .quotient BigInteger256

  .value rq 1
  .modulus rq 1
  .result rq 1
  .cnt rq 1

  AlignLocalsStackFrame

.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mod_inverse_256'
        CheckRegAligned rcx, 'bi_mod_inverse_256 rcx'
        CheckRegAligned rdx, 'bi_mod_inverse_256 rdx'
        CheckRegAligned r8, 'bi_mod_inverse_256 r8'

        mov     [.value], rcx
        mov     [.modulus], rdx
        mov     [.result], r8

;partial extended eucleadian algorithm where one coeff is calculated
        lea     rcx, [.r0]
        mov     rdx, [.value]
        call    bi_copy_256

        lea     rcx, [.r1]
        mov     rdx, [.modulus]
        call    bi_copy_256

        lea     rcx, [.s0]
        call    bi_one_256
        lea     rcx, [.s1]
        call    bi_zero_256

        mov     [.cnt], 0
.loop:
        lea     rcx, [.r1]
        call    bi_is_zero_256
        test    rax, rax
        jnz     .loop_end

        lea     rcx, [.r0]
        lea     rdx, [.r1]
        lea     r8, [.quotient]
        lea     r9, [.r2]
        call    bi_div_rem_256_256

        lea     rcx, [.quotient]
        lea     rdx, [.s1]
        lea     r8, [.s2]
        call    bi_mul_low_256_256
        lea     rcx, [.s2]
        lea     rdx, [.s0]
        call    bi_add_assign_256_256


        lea     rcx, [.s0]
        lea     rdx, [.s1]
        call    bi_copy_256

        lea     rcx, [.s1]
        lea     rdx, [.s2]
        call    bi_copy_256

        lea     rcx, [.r0]
        lea     rdx, [.r1]
        call    bi_copy_256

        lea     rcx, [.r1]
        lea     rdx, [.r2]
        call    bi_copy_256

        inc     [.cnt]
        jmp     .loop
.loop_end: 
        bt      [.cnt], 0
        jnc     .even
.odd:
        mov     rcx, [.modulus]
        lea     rdx, [.s0]
        mov     r8, [.result]
        call    bi_sub_256_256

        jmp     .end
.even:
        mov     rcx, [.result]
        lea     rdx, [.s0]
        call    bi_copy_256

.end:

        add     rsp, .locals_end - .locals_start
        ret
end if