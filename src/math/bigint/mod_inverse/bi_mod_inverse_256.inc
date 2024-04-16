if ~ definite bi_mod_inverse_256

include '../euclid_ext/bi_euclid_ext_256.inc'

;Calculates modular inverse
;input:
;  rcx - left value.
;  rdx - modulus
;  r8 - result
bi_mod_inverse_256:
virtual at rsp
.locals_start:
  .euclid rb BezoutIdentity256.sizeof

  .value rq 1
  .modulus rq 1
  .result rq 1

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

        mov     rcx, [.value]
        mov     rdx, [.modulus]
        lea     r8, [.euclid]
        call    bi_euclid_ext_256

        mov     rcx, [.result]
        lea     rdx, [.euclid + BezoutIdentity256.x]
        call    bi_copy_256

        add     rsp, .locals_end - .locals_start
        ret
end if