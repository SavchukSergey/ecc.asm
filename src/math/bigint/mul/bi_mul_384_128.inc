if ~ definite bi_mul_384_128


;Multiplies bi384 value by bi128 value
;input
;  rcx - left bi384 value
;  rdx - right bi128 value
;  r8 - result bi512 value
bi_mul_384_128:
virtual at rsp
.locals_start:
  .temp BigInteger448
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mul_384_128'
    CheckRegAligned rcx, 'bi_mul_384_128 rcx'
    CheckRegAligned rdx, 'bi_mul_384_128 rdx'
    CheckRegAligned r8, 'bi_mul_384_128 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx]
        mov     r8, [.result]
        mov     qword [r8 + 64], 0
        call    bi_mul_384_64

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx + 8]
        lea     r8, [.temp]
        call    bi_mul_384_64

        mov     rcx, [.result]
        add     rcx, 8
        lea     rdx, [.temp]
        call    bi_add_assign_448_448

        add     rsp, .locals_end - .locals_start
        ret

end if