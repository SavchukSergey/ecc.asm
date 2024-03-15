
if ~ definite bi_mul_128_128

;Multiplies two bi128 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
bi_mul_128_128:
        mov     rax, rcx
        mul     rdx
        mov     [r8], rax
        mov     [r8 + 8], rdx

        ret
end if

if ~ definite bi_mul_256_256

;Multiplies two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
bi_mul_256_256:
        mov     rax, rcx
        mul     rdx
        mov     [r8], rax
        mov     [r8 + 8], rdx

        ret
end if


macro BigIntegerMul bits, dbits {

if ~ definite __bi_mul_#bits

include '../src/math/bigint/bit_check/bit_check.inc'
include '../src/math/bigint/zero/zero.inc'
include '../src/math/bigint/add/add.inc'

BigIntegerBitCheck bits
BigIntegerZero dbits
BigIntegerAdd dbits





;Multiplies two bi values
;input
; rax - left value
; rbx - right value
; rdi - result value
__bi_mul_#bits:
virtual at rsp
.locals_start:
  .left_arg rq 1
  .right_arg rq 1
  .result_arg rq 1
  .walker rb __BIG_INTEGER_BYTES_#dbits
.locals_end:
end virtual
        push    rbx rcx rdi
        enter   .locals_end - .locals_start, 0

        mov     [.left_arg], rax
        mov     [.right_arg], rbx
        mov     [.result_arg], rdi

        mov     rax, [.result_arg]
        call    __bi_zero_#dbits

        mov     rax, [.right_arg]
        lea     rdi, [.walker]
        call    __bi_extend_low_#dbits

        mov     rcx, 0
.loop:
        mov     rax, [.left_arg]
        bt      [rax], rcx
;        call    __bi_bit_check_#bits
        jnc     .no_add

        mov     rax, [.result_arg]
        lea     rbx, qword [.walker]
        call    __bi_add_assign_#dbits
.no_add:
        lea     rax, qword [.walker]
        call    __bi_shl_#dbits

        inc     rcx
        cmp     rcx, __BIG_INTEGER_BITS_#bits
        jb      .loop

        leave
        pop     rdi rcx rbx
        ret

end if

}
