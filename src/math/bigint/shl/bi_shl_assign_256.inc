if ~ definite bi_shl_assign_256

include 'bi_shl_assign_256_128.inc'
include 'bi_shl_assign_128.inc'

; Shifts left
;input
; rcx - value
; rdx - bits
bi_shl_assign_256_avx2:
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

; Shifts left
;input
; rcx - value
; rdx - bits
bi_shl_assign_256_basic:
        push    rbx rsi rdi

        mov     rbx, rcx
        mov     rcx, rdx

        lea     rdi, [rbx + 32 - 8]

        mov     rsi, rcx
        shr     rsi, 6
        test    rsi, rsi
        jz      .shift_64_ok

        shl     rsi, 3
        sub     rsi, rdi
        neg     rsi

.shift_64:
        xor     rax, rax
        cmp     rsi, rbx
        cmovae  rax, [rsi]
        mov     [rdi], rax

        sub     rsi, 8
        sub     rdi, 8
        cmp     rdi, rbx
        jae     .shift_64
.shift_64_ok:

        and     rcx, 0x3f
        jz      .loop_ok

        mov     rax, [rbx + 16]
        shld    [rbx + 24], rax, cl
        mov     rax, [rbx + 8]
        shld    [rbx + 16], rax, cl
        mov     rax, [rbx + 0]
        shld    [rbx + 8], rax, cl
        shl     qword [rbx], cl

.loop_ok:

.end:
        pop     rdi rsi rbx
        ret

if AVX2_ENABLED = 1
  bi_shl_assign_256 = bi_shl_assign_256_avx2
else
  bi_shl_assign_256 = bi_shl_assign_256_basic
end if

end if
