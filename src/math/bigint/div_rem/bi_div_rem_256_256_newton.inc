if ~ definite bi_div_rem_256_256_newton

include '../lzcnt/bi_lzcnt_256.inc'
include '../shl/bi_shl_256.inc'

bi_div_rem_256_256_newton:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rq 1

  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

        mov     rcx, [.divisor]
        call    bi_lzcnt_256
        mov     [.divisor_lzcnt], rax

        mov     rcx, [.divisor]
        lea     rdx, [.divisor_shifted]
        mov     r8, [.divisor_lzcnt]
        call    bi_shl_assign_256

;todo:
        add     rsp, .locals_end - .locals_start
        ret

end if