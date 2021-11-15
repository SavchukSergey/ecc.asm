macro BigIntegerDivRem bits, dbits {

if ~ definite __bi_div_rem_#bits

include '../src/math/bigint/extend_low/extend_low.inc'
include '../src/math/bigint/extend_high/extend_high.inc'
include '../src/math/bigint/cmp/cmp.inc'
include '../src/math/bigint/shl/shl.inc'

BigIntegerShl dbits

;Divides two bi values
;input
; rax - divident value
; rbx - divisor value
; rdi - quotient value
; rsi - reminder value
__bi_div_rem_#bits:
virtual at rbp
  .divident rb __BIG_INTEGER_BYTES_#dbits
  .divisor rb __BIG_INTEGER_BYTES_#dbits
end virtual
        push    rbp
        sub     rsp, __BIG_INTEGER_BYTES_#dbits * 2
        mov     rbp, rsp

        push    rdi
        lea     rdi, [.divident]
        call    __bi_extend_low_#dbits

        mov     rax, rbx
        lea     rdi, [.divisor]
        call    __bi_extend_high_#dbits
        pop     rdi

        mov     rcx, __BIG_INTEGER_BITS_#bits
.loop:
        lea     rax, [.divident]
        call    __bi_shl_#dbits

        lea     rax, [.divident]
        lea     rbx, [.divisor]
        call    __bi_cmp_#bits
        jc      .below
 .above:
        mov     rax, rdi
        mov     rbx, __BIG_INTEGER_BITS_#bits
        sub     rbx, rcx
        call    __bi_set_bit_#bits
        jmp     .continue
.below:
        mov     rax, rdi
        mov     rbx, __BIG_INTEGER_BITS_#bits
        sub     rbx, rcx
        call    __bi_clear_bit_#bits
.continue:
        loop    .loop


        add     rsp, __BIG_INTEGER_BYTES_#dbits * 2
        pop     rbp
        ret

end if

}