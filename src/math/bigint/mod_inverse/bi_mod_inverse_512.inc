;Calculates modular inverse of bi512
;input:
;  rcx - pointer to bi512 value.
;  rdx - pointer to bi512 modulus
;  r8 - pointer bi512 result
bi_mod_inverse_512:
virtual at rsp
.locals_start:
  .s0 BigInteger512
  .s1 BigInteger512
  .s2 BigInteger512
  .r0 BigInteger512
  .r1 BigInteger512
  .r2 BigInteger512
  .quotient BigInteger512

  .value rq 1
  .modulus rq 1
  .result rq 1
  .cnt rq 1

  AlignLocalsStackFrame

.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mod_inverse_512'
        CheckRegBi512Alignment rcx, 'bi_mod_inverse_512 rcx'
        CheckRegBi512Alignment rdx, 'bi_mod_inverse_512 rdx'
        CheckRegBi512Alignment r8, 'bi_mod_inverse_512 r8'

        mov     [.value], rcx
        mov     [.modulus], rdx
        mov     [.result], r8

;partial extended eucleadian algorithm where one coeff is calculated
        lea     rcx, [.r0]
        mov     rdx, [.value]
        call    bi_copy_512

        lea     rcx, [.r1]
        mov     rdx, [.modulus]
        call    bi_copy_512

        lea     rcx, [.s0]
        call    bi_one_512
        lea     rcx, [.s1]
        call    bi_zero_512

        mov     [.cnt], 0
.loop:
        lea     rcx, [.r1]
        call    bi_is_zero_512
        test    rax, rax
        jnz     .loop_end

        lea     rcx, [.r0]
        lea     rdx, [.r1]
        lea     r8, [.quotient]
        lea     r9, [.r2]
        call    bi_div_rem_512_512

        lea     rcx, [.quotient]
        lea     rdx, [.s1]
        lea     r8, [.s2]
        call    bi_mul_512_512_low_512
        lea     rcx, [.s2]
        lea     rdx, [.s0]
        call    bi_add_assign_512_512


        lea     rcx, [.s0]
        lea     rdx, [.s1]
        call    bi_copy_512

        lea     rcx, [.s1]
        lea     rdx, [.s2]
        call    bi_copy_512

        lea     rcx, [.r0]
        lea     rdx, [.r1]
        call    bi_copy_512

        lea     rcx, [.r1]
        lea     rdx, [.r2]
        call    bi_copy_512

        inc     [.cnt]
        jmp     .loop
.loop_end: 
        bt      [.cnt], 0
        jnc     .even
.odd:
        mov     rcx, [.modulus]
        lea     rdx, [.s0]
        mov     r8, [.result]
        call    bi_sub_512_512

        jmp     .end
.even:
        mov     rcx, [.result]
        lea     rdx, [.s0]
        call    bi_copy_512

.end:

        add     rsp, .locals_end - .locals_start
        ret