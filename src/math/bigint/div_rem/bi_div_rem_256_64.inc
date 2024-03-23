if ~ definite bi_div_rem_256_64

;Divides bi256 by u64
;input:
;   rcx - pointer to bi256 divident
;   rdx - u64 divisor
;   r8 - pointer to bi256 quotient
;   r9 - pointer to bi256 remainder (actual result will be u64)
bi_div_rem_256_64:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

        xor     rdx, rdx

        mov     rax, [.dividend]
        mov     rax, [rax + 24]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     rcx, [.quotient]
        mov     [rcx + 24], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 16]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     rcx, [.quotient]
        mov     [rcx + 16], rax

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

        mov     rcx, [.remainder]
        mov     qword [rcx + 0], rdx
        mov     qword [rcx + 8], 0
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0

        leave
        ret
end if