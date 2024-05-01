if ~ definite bi_rem_256_128

include 'bi_div_rem_256_128.inc'


;todo: create optimized version

bi_rem_256_128:
virtual at rsp
  label .locals_start
  BigInteger256 .quotient_256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_rem_256_128'
    CheckRegBi256Alignment rcx, 'bi_rem_256_128 rcx'
    CheckRegBi128Alignment rdx, 'bi_rem_256_128 rdx'
    CheckRegBi256Alignment r8, 'bi_rem_256_128 r8'

        mov     r9, r8
        lea     r8, [.quotient_256]
        call    bi_div_rem_256_128

        add     rsp, .locals_end - .locals_start
        ret

end if