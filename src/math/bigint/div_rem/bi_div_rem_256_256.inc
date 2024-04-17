if ~ definite bi_div_rem_256_256

include 'bi_div_rem_256_256_full_bits.inc'
include 'bi_div_rem_256_256_bits.inc'
include 'bi_div_rem_256_256_guess.inc'

;bi_div_rem_256_256 equ bi_div_rem_256_256_bits
bi_div_rem_256_256 equ bi_div_rem_256_256_guess

;todo: there is some performance improvements for bi_mod_inverse but it degrades for bi_dev_rem_256_256

; bi_div_rem_256_256:
; virtual at rsp
;   label .locals_start
;   .dividend rq 1
;   .divisor rq 1
;   .quotient rq 1
;   .remainder rq 1
;   .dividend_lzcnt rq 1
;   .divisor_lzcnt rq 1
;   AlignLocalsStackFrame
;   label .locals_end
; end virtual
;     sub     rsp, .locals_end - .locals_start
;     mov     [.dividend], rcx
;     mov     [.divisor], rdx
;     mov     [.quotient], r8
;     mov     [.remainder], r9

;     mov     rcx, [.divisor]
;     call    bi_lzcnt_256
;     mov     [.divisor_lzcnt], rax

;     cmp     rax, 192
;     jae     .opt_64

;     cmp     rax, 128
;     jae     .opt_128


;     mov     rcx, [.dividend]
;     call    bi_lzcnt_256
;     mov     [.dividend_lzcnt], rax

;     mov     rax, [.divisor_lzcnt]
;     sub     rax, [.dividend_lzcnt]
;     cmp     rax, 128
;     jb      .bits
; .guess:
;     mov     rcx, [.dividend]
;     mov     rdx, [.divisor]
    
;     call    bi_div_rem_256_256_guess

; .end:
;     add     rsp, .locals_end - .locals_start
;     ret
; .bits:
;     mov     rcx, [.dividend]
;     mov     rdx, [.divisor]
    
;     call    bi_div_rem_256_256_bits
;     jmp     .end

; .opt_128:
;     mov     rcx, [.dividend]
;     mov     rdx, [.divisor]
;     call    bi_div_rem_256_128
;     jmp     .end

; .opt_64:
;     mov     rcx, [.dividend]
;     mov     rdx, [.divisor]
;     mov     rdx, [rdx]
;     call    bi_div_rem_256_64
;     jmp     .end

end if