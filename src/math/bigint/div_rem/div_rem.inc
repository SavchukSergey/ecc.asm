include '../extend_low/extend_low.inc'
include '../bit_set/bit_set.inc'
include '../copy/copy.inc'

if ~ definite bi_div_rem_128_128

bi_div_rem_128_128:
;todo:
        ret
end if

if ~ definite bi_div_rem_512_512

bi_div_rem_512_512:
;todo:
        ret
end if


if ~ definite bi_div_rem_256_256

bi_div_rem_256_256:
virtual at rsp
  label .locals_start
  .value rb __BIG_INTEGER_BYTES_512
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1
  .bit rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

        lea     rcx, [.value]
        mov     rdx, [.dividend]
        call    bi_extend_512_256

        mov     rcx, [.quotient]
        call    bi_zero_256

        mov     [.bit], 255

.loop:
        ;todo: shift just 256-bit value with carry like as "rol" opcode where carry is read from dividend
        lea     rcx, [.value]
        call    bi_shl_assign_512_1

        lea     rcx, [.value + 32]
        mov     rdx, [.divisor]
        call    bi_cmp_256_256
        cmp     al, -1
        je      .below
        lea     rcx, [.value + 32]
        mov     rdx, [.divisor]
        call    bi_sub_assign_256_256

        mov     rcx, [.quotient]
        mov     rdx, [.bit]
        call    bi_bit_set_256
.below:
        sub     [.bit], 1
        jnc     .loop

        mov     rcx, [.remainder]
        lea     rdx, [.value + 32]
        call    bi_copy_256

        leave
        ret

end if


