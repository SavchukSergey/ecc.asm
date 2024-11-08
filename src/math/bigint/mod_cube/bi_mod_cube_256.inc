if ~ definite bi_mod_cube_256

;Cubes bi256 with modulus
;input:
;  rcx - pointer to bi256 value.
;  rdx - pointer to bi256 modulus
;  r8 - pointer to bi256 result
bi_mod_cube_256:
virtual at rsp
  label .locals_start
    .temp BigInteger256
    .value rq 1
    .modulus rq 1
    .result rq 1
    AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mod_cube_256'
        CheckRegAligned rcx, 'bi_mod_cube_256 rcx'
        CheckRegAligned rdx, 'bi_mod_cube_256 rdx'
        CheckRegAligned r8, 'bi_mod_cube_256 r8'

        mov     [.value], rcx
        mov     [.modulus], rdx
        mov     [.result], r8

        mov     rcx, [.value]
        mov     rdx, [.modulus]
        lea     r8, [.temp]
        call    bi_mod_square_256

        mov     rcx, [.value]
        lea     rdx, [.temp]
        mov     r8, [.modulus]
        mov     r9, [.result]
        call    bi_mod_mul_256_256

        add     rsp, .locals_end - .locals_start
        ret

end if