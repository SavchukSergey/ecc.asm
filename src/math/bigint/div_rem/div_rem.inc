macro BigIntegerDivRem bits, dbits {

if ~ definite __bi_div_rem_#bits

include '../src/math/bigint/extend_low/extend_low_1.inc'
include '../src/math/bigint/extend_high/extend_high_1.inc'
include '../src/math/bigint/cmp/cmp.inc'
include '../src/math/bigint/shl/shl.inc'
include '../src/math/bigint/sub/sub.inc'
include '../src/math/bigint/bit_set/bit_set.inc'
include '../src/math/bigint/bit_clear/bit_clear.inc'

BigIntegerSub dbits
BigIntegerShl dbits
BigIntegerCmp dbits
BigIntegerExtendLow1 dbits
BigIntegerExtendHigh1 dbits
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
  label .locals_start
  .divident rb 2 * __BIG_INTEGER_BYTES_#bits
  .divisor rb 2* __BIG_INTEGER_BYTES_#bits
  .divident_arg rq 1
  .divisor_arg rq 1
  .quotient_arg rq 1
  .reminder_arg rq 1
  label .locals_end
end virtual
        push    rbp
        sub     rsp, .locals_end - .locals_start
        mov     rbp, rsp
        mov     [.divident_arg], rax
        mov     [.divisor_arg], rbx
        mov     [.quotient_arg], rdi
        mov     [.reminder_arg], rsi

        mov     rax, [.divident_arg]
        lea     rdi, [.divident]
        call    __bi_extend_low_#dbits

        mov     rax, [.divisor_arg]
        lea     rdi, [.divisor]
        call    __bi_extend_high_#dbits

        mov     rcx, __BIG_INTEGER_BITS_#bits
.loop:
        lea     rax, [.divident]
        call    __bi_shl_#dbits

        lea     rax, [.divident]
        lea     rbx, [.divisor]
        call    __bi_cmp_#dbits
        jb      .below
 .above:
        lea     rax, [.divident]
        lea     rbx, [.divisor]
        lea     rdi, [.divident]
        call    __bi_sub_#dbits

        mov     rax, [.quotient_arg]
        mov     rbx, rcx
        dec     rbx
        call    __bi_bit_set_#bits
        jmp     .continue
.below:
        mov     rax, [.quotient_arg]
        mov     rbx, rcx
        dec     rbx
        call    __bi_bit_clear_#bits
.continue:
        loop    .loop

        lea     rsi, [.divident + __BIG_INTEGER_BYTES_#bits]
        mov     rdi, [.reminder_arg]
        MemoryCopyStatic rsi, rdi, __BIG_INTEGER_BYTES_#bits ;todo: special shrink method


        add     rsp, .locals_end - .locals_start
        pop     rbp
        ret

end if

}