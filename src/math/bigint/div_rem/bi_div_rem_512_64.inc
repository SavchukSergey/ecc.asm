if ~ definite bi_div_rem_512_64

;Divides bi512 by u64
;input:
;   rcx - pointer to bi512 divident
;   rdx - u64 divisor
;   r8 - pointer to bi512 quotient
;   r9 - pointer to bi512 remainder (actual result will be u64)
bi_div_rem_512_64:
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
        mov     rax, [rax + 56]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 56], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 48]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 48], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 40]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 40], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 32]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 32], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 24]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 24], rax

        mov     rax, [.dividend]
        mov     rax, [rax + 16]
        div     qword [.divisor]
        ;rdx - remainder, rax - quotient
        mov     [r8 + 16], rax

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
        mov     qword [r9 + 16], 0
        mov     qword [r9 + 24], 0
        mov     qword [r9 + 32], 0
        mov     qword [r9 + 40], 0
        mov     qword [r9 + 48], 0
        mov     qword [r9 + 56], 0

        add     rsp, .locals_end - .locals_start
        ret
end if