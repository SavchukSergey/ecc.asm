if ~ definite bi_shr_assign_512

include 'bi_shr_assign_256.inc'
include 'bi_shr_assign_512_64.inc'
include 'bi_shr_assign_512_128.inc'
include 'bi_shr_assign_512_256.inc'

bi_shr_assign_512:
        cmp     rdx, 512
        jae     .zero

        cmp     rdx, 256
        jb      .small_256
        call    bi_shr_assign_512_256

        sub     rdx, 256
        call    bi_shr_assign_256
        ret
.small_256:

        cmp     rdx, 128
        jb      .small_128
        call    bi_shr_assign_512_128
        sub     rdx, 128
.small_128:

        cmp     rdx, 64
        jb      .small_64
        call    bi_shr_assign_512_64
        sub     rdx, 64
.small_64:

        xchg    rcx, rdx

        mov     rax, [rdx + 8]
        shrd    [rdx + 0], rax, cl

        mov     rax, [rdx + 16]
        shrd    [rdx + 8], rax, cl

        mov     rax, [rdx + 24]
        shrd    [rdx + 16], rax, cl

        mov     rax, [rdx + 32]
        shrd    [rdx + 24], rax, cl

        mov     rax, [rdx + 40]
        shrd    [rdx + 32], rax, cl

        mov     rax, [rdx + 48]
        shrd    [rdx + 40], rax, cl

        mov     rax, [rdx + 56]
        shrd    [rdx + 48], rax, cl

        shr     qword [rdx + 56], cl

        xchg    rcx, rdx

        ret

.zero:
        call    bi_zero_512
        ret

end if

