if ~ definite bi_shr_assign_256

include 'bi_shr_assign_256_128.inc'
include 'bi_shr_assign_256_64.inc'
include 'bi_shr_assign_128.inc'

; Shifts left bi256
;input
; rcx - value bi256
; rdx - bits
bi_shr_assign_256:
    CheckRegAligned rcx, 'bi_shr_assign_256 rcx'

        cmp     rdx, 256
        jae     .zero

        cmp     rdx, 128
        jb      .small_128
        call    bi_shr_assign_256_128

        sub     rdx, 128
        call    bi_shr_assign_128
        ret
.small_128:

        cmp     rdx, 64
        jb      .small_64
        call    bi_shr_assign_256_64
        sub     rdx, 64
.small_64:

        xchg    rcx, rdx

        mov     rax, [rdx + 8]
        shrd    [rdx + 0], rax, cl

        mov     rax, [rdx + 16]
        shrd    [rdx + 8], rax, cl

        mov     rax, [rdx + 24]
        shrd    [rdx + 16], rax, cl

        shr     qword [rdx + 24], cl

        xchg    rcx, rdx

        ret

.zero:
        call    bi_zero_256
        ret

end if
