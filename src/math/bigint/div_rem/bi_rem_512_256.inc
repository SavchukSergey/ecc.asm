if ~ definite bi_rem_512_256

include 'bi_div_rem_512_256.inc'

;todo: create optimized version
bi_rem_512_256:
virtual at rsp
  label .locals_start
  .quotient_512 rb __BIG_INTEGER_BYTES_512
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        mov     r9, r8
        lea     r8, [.quotient_512]
        call    bi_div_rem_512_256

        add     rsp, .locals_end - .locals_start
        ret
end if