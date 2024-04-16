if ~ definite bi_rem_512_128

include 'bi_div_rem_512_128.inc'

;todo: create optimized version
bi_rem_512_128:
virtual at rsp
  label .locals_start
  .quotient_512 rb __BIG_INTEGER_BYTES_512
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_rem_512_128'
    CheckRegAligned rcx, 'bi_rem_512_128 rcx'
    CheckRegAligned rdx, 'bi_rem_512_128 rdx'
    CheckRegAligned r8, 'bi_rem_512_128 r8'

        mov     r9, r8
        lea     r8, [.quotient_512]
        call    bi_div_rem_512_128

        add     rsp, .locals_end - .locals_start
        ret
end if