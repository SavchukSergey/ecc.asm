if ~ definite bi_mod_div_256_256

bi_mod_div_256_256:
virtual at rsp
  label .locals_start
    .dividend rq 1
    .divisor rq 1
    .modulus rq 1
    .result rq 1
    .inverse BigInteger256
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mod_div_256_256'
    CheckRegAligned rcx, 'bi_mod_div_256_256 rcx'
    CheckRegAligned rdx, 'bi_mod_div_256_256 rdx'
    CheckRegAligned r8, 'bi_mod_div_256_256 r8'
    CheckRegAligned r9, 'bi_mod_div_256_256 r9'

        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.modulus], r8
        mov     [.result], r9

        mov     rcx, [.divisor]
        mov     rdx, [.modulus]
        lea     r8, [.inverse]
        call    bi_mod_inverse_256

        mov     rcx, [.dividend]
        lea     rdx, [.inverse]
        mov     r8, [.modulus]
        mov     r9, [.result]
        call    bi_mod_mul_256_256

        add     rsp, .locals_end - .locals_start
        ret

end if