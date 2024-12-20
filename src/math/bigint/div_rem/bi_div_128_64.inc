;Divides bi128 by bi64
;input:
;  rcx - pointer to bi128 dividend
;  rdx - bi64 divisor
;  r8 - pointer to bi128 quotient
bi_div_128_64:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_div_128_64'
    CheckRegBi128Alignment rcx, 'bi_div_128_64 rcx'
    CheckRegBi128Alignment r8, 'bi_div_128_64 r8'

        mov     [.dividend], rcx
        mov     [.divisor], rdx

        xor     rdx, rdx
        mov     rax, [.dividend]
        mov     rax, [rax + 8]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 8], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 0]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 0], rax

        add     rsp, .locals_end - .locals_start
        ret