if ~ definite bi_square_128

include '../zero/bi_zero_256.inc'
include '../add/bi_add_assign_128_128.inc'
include '../add/bi_add_assign_192_128.inc'
include 'bi_square_64.inc'

;Squares bi128 value
;input
; rcx - pointer to bi128 value
; rdx - pointer to bi256 result
bi_square_128:
        mov     r8, rdx

        mov     rax, [rcx + 0]
        mul     qword [rcx + 0]
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx
        
        mov     qword [r8 + 16], 0
        mov     qword [r8 + 24], 0

        mov     rax, [rcx + 0]
        mul     qword [rcx + 8]
        add     [r8 + 8], rax
        adc     [r8 + 16], rdx
        adc     qword [r8 + 24], 0
        add     [r8 + 8], rax
        adc     [r8 + 16], rdx
        adc     qword [r8 + 24], 0

        mov     rax, [rcx + 8]
        mul     qword [rcx + 8]
        add     [r8 + 16], rax
        adc     [r8 + 24], rdx

        ret

end if