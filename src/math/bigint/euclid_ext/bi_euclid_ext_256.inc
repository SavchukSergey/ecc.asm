if ~ definite bi_euclid_ext_256

;Calculates bezout identity using euclid extended algorithm
;input:
;  rcx - left value
;  rdx - right value
;  r8 - result euclid value
bi_euclid_ext_256:
virtual at rsp
  label .locals_start
  .s0 BigInteger256
  .s1 BigInteger256
  .s2 BigInteger256
  .t0 BigInteger256
  .t1 BigInteger256
  .t2 BigInteger256
  .r0 BigInteger256
  .r1 BigInteger256
  .r2 BigInteger256
  .quotient BigInteger256
  .a rq 1
  .b rq 1
  .result rq 1
  .cnt rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_euclid_ext_256'
    CheckRegBi256Alignment rcx, 'bi_euclid_ext_256 rcx'
    CheckRegBi256Alignment rdx, 'bi_euclid_ext_256 rdx'
    CheckRegBi256Alignment r8, 'bi_euclid_ext_256 r8'

        mov     [.a], rcx
        mov     [.b], rdx
        mov     [.result], r8

        lea     rcx, [.r0]
        mov     rdx, [.a]
        call    bi_copy_256

        lea     rcx, [.r1]
        mov     rdx, [.b]
        call    bi_copy_256

        lea     rcx, [.s0]
        call    bi_one_256
        lea     rcx, [.t0]
        call    bi_zero_256
        lea     rcx, [.s1]
        call    bi_zero_256
        lea     rcx, [.t1]
        call    bi_one_256

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
        call    bi_mul_256_256_low_256
        lea     rcx, [.s2]
        lea     rdx, [.s0]
        call    bi_add_assign_256_256

        lea     rcx, [.quotient]
        lea     rdx, [.t1]
        lea     r8, [.t2]
        call    bi_mul_256_256_low_256
        lea     rcx, [.t2]
        lea     rdx, [.t0]
        call    bi_add_assign_256_256


        lea     rcx, [.s0]
        lea     rdx, [.s1]
        call    bi_copy_256

        lea     rcx, [.s1]
        lea     rdx, [.s2]
        call    bi_copy_256

        lea     rcx, [.t0]
        lea     rdx, [.t1]
        call    bi_copy_256

        lea     rcx, [.t1]
        lea     rdx, [.t2]
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
        mov     rcx, [.result]
        add     rcx, BezoutIdentity256.a
        mov     rdx, [.a]
        call    bi_copy_256
        
        mov     rcx, [.result]
        add     rcx, BezoutIdentity256.b
        mov     rdx, [.b]
        call    bi_copy_256

        bt      [.cnt], 0
        jnc     .even
.odd:
        mov     rcx, [.b]
        lea     rdx, [.s0]
        mov     r8, [.result]
        add     r8, BezoutIdentity256.x
        call    bi_sub_256_256

        mov     rcx, [.result]
        add     rcx, BezoutIdentity256.y
        lea     rdx, [.t0]
        call    bi_copy_256

        jmp     .end
.even:
        mov     rcx, [.result]
        add     rcx, BezoutIdentity256.x
        lea     rdx, [.s0]
        call    bi_copy_256

        mov     rcx, [.a]
        lea     rdx, [.t0]
        mov     r8, [.result]
        add     r8, BezoutIdentity256.y
        call    bi_sub_256_256
        jmp     .end

.end:
        add     rsp, .locals_end - .locals_start
        ret

end if