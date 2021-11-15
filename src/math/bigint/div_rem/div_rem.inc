macro BigIntegerDivRem bits, dbits {

if ~ definite __bi_div_rem_#bits

include '../src/math/bigint/extend_low/extend_low_1.inc'
include '../src/math/bigint/extend_high/extend_high_1.inc'
include '../src/math/bigint/cmp/cmp.inc'
include '../src/math/bigint/shl/shl.inc'
include '../src/math/bigint/bit_set/bit_set.inc'
include '../src/math/bigint/bit_clear/bit_clear.inc'

BigIntegerShl dbits
BigIntegerExtendLow1 bits
BigIntegerExtendHigh1 bits
BigIntegerBitSet bits
BigIntegerBitClear bits

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
        call    __bi_extend_low_#bits

        mov     rax, rbx
        lea     rdi, [.divisor]
        call    __bi_extend_high_#bits
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
        call    __bi_bit_set_#bits
        jmp     .continue
.below:
        mov     rax, rdi
        mov     rbx, __BIG_INTEGER_BITS_#bits
        sub     rbx, rcx
        call    __bi_bit_clear_#bits
.continue:
        loop    .loop


        add     rsp, __BIG_INTEGER_BYTES_#dbits * 2
        pop     rbp
        ret

end if

}