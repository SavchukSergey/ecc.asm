if ~ definite bi_div_128_64

;Divides bi128 by u64
;input:
;  rcx - pointer to bi128 dividend
;  rdx - u64 divisor
;  r8 - pointer to bi128 quotient
bi_div_128_64:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8

        xor     rdx, rdx
        mov     rax, [.dividend]
        mov     rax, [rax + 8]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     rcx, [.quotient]
        mov     [rcx + 8], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 0]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     rcx, [.quotient]
        mov     [rcx + 0], rax

        add     rsp, .locals_end - .locals_start
        ret
end if