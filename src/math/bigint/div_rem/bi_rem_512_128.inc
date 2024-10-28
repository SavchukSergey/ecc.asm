if ~ definite bi_rem_512_128

include 'bi_div_rem_512_128.inc'

include 'bi_rem_512_128_dac.inc'

;todo: check why slower then generic Rem macro

bi_rem_512_128_basic:
virtual at rsp
  label .locals_start
  .quotient_512 BigInteger512
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_rem_512_128'
    CheckRegBi512Alignment rcx, 'bi_rem_512_128 rcx'
    CheckRegBi128Alignment rdx, 'bi_rem_512_128 rdx'
    CheckRegBi512Alignment r8, 'bi_rem_512_128 r8'

        mov     r9, r8
        lea     r8, [.quotient_512]
        call    bi_div_rem_512_128

        add     rsp, .locals_end - .locals_start
        ret

bi_rem_512_128 = bi_rem_512_128_dac

end if