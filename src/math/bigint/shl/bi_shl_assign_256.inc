if ~ definite bi_shl_assign_256

include 'bi_shl_assign_256_128.inc'
include 'bi_shl_assign_256_64.inc'
include 'bi_shl_assign_128.inc'

; Shifts left bi256
;input
; rcx - value bi256
; rdx - bits
bi_shl_assign_256:
    CheckRegAligned rcx, 'bi_shl_assign_256 rcx'

        cmp     rdx, 256
        jae     .zero

        cmp     rdx, 128
        jb      .small_128
        call    bi_shl_assign_256_128

        sub     rdx, 128
        add     rcx, 16
        call    bi_shl_assign_128
        ret
.small_128:

        cmp     rdx, 64
        jb      .small_64
        call    bi_shl_assign_256_64
        sub     rdx, 64
.small_64:

        xchg    rcx, rdx

        mov     rax, [rdx + 16]
        shld    [rdx + 24], rax, cl
        mov     rax, [rdx + 8]
        shld    [rdx + 16], rax, cl
        mov     rax, [rdx + 0]
        shld    [rdx + 8], rax, cl
        shl     qword [rdx], cl

        xchg    rcx, rdx

        ret

.zero:
        call    bi_zero_256
        ret

end if
