if ~ definite bi_mod_square_256

;Squares bi256 with modulus
;input:
;  rcx - pointer to bi256 value.
;  rdx - pointer to bi256 modulus
;  r8 - pointer to bi256 result
bi_mod_square_256:
virtual at rsp
  label .locals_start
    .result_512 BigInteger512
    .reminder_512 BigInteger512
    .value rq 1
    .modulus rq 1
    .result rq 1
    AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mod_square_256'
        CheckRegAligned rcx, 'bi_mod_square_256 rcx'
        CheckRegAligned rdx, 'bi_mod_square_256 rdx'
        CheckRegAligned r8, 'bi_mod_square_256 r8'

        mov     [.value], rcx
        mov     [.modulus], rdx
        mov     [.result], r8

        mov     rcx, [.value]
        lea     rdx, [.result_512]
        call    bi_square_256

        lea     rcx, [.result_512]
        mov     rdx, [.modulus]
        lea     r8, [.reminder_512]
        call    bi_rem_512_256

        mov     rcx, [.result]
        lea     rdx, [.reminder_512]
        call    bi_copy_256

        add     rsp, .locals_end - .locals_start
        ret

end if