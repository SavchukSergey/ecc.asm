if ~ definite bi_div_rem_128_64

;Divides bi128 by u64
;input:
;   rcx - pointer to bi128 divident
;   rdx - u64 divisor
;   r8 - pointer to bi128 quotient
;   r9 - pointer to bi128 remainder (actual result will be u64)
bi_div_rem_128_64:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

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

        mov     qword [r9 + 0], rdx
        mov     qword [r9 + 8], 0

        add     rsp, .locals_end - .locals_start
        ret
end if