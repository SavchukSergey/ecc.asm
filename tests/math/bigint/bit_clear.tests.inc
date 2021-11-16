macro BigIntegerBitClearTests bits {

include '../src/math/bigint/bit_clear/bit_clear.inc'
include '../src/mem/fill_static.inc'

BigIntegerBitClear bits

__bi_bit_clear_first_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        MemoryFillStatic rax, 0xff, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        mov     rbx, 0
        call    __bi_bit_clear_#bits

        lea     rax, [rsp]
        cmp     byte [rax], 0xfe
        jne     .failed

        lea     rax, [rsp]
        mov     rcx, __BIG_INTEGER_BYTES_#bits - 1
.check_loop:
        mov     byte [rax + rcx], 0xff
        loop    .check_loop

.passed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret
.failed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret


__bi_bit_clear_last_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        MemoryFillStatic rax, 0xff, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        mov     rbx,  __BIG_INTEGER_BITS_#bits - 1
        call    __bi_bit_clear_#bits

        lea     rax, [rsp]
        cmp     byte [rax + __BIG_INTEGER_BYTES_#bits - 1], 0x7f
        jne     .failed

        lea     rax, [rsp]
        mov     rcx, __BIG_INTEGER_BYTES_#bits - 1
.check_loop:
        mov     byte [rax + rcx - 1], 0xff
        loop    .check_loop

.passed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret
.failed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret


__bi_bit_clear_middle_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        MemoryFillStatic rax, 0xff, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        mov     rbx, __BIG_INTEGER_BITS_#bits / 2
        call    __bi_bit_clear_#bits

        lea     rax, [rsp]
        cmp     byte [rax + __BIG_INTEGER_BYTES_#bits / 2], 0xff xor (1 shl ( (__BIG_INTEGER_BITS_#bits / 2) mod 8))
        jne     .failed

        lea     rax, [rsp]
        mov     rcx, (__BIG_INTEGER_BYTES_#bits / 2) - 1
.check_loop_1:
        mov     byte [rax + rcx - 1], 0xff
        loop    .check_loop_1

        lea     rax, [rsp + __BIG_INTEGER_BITS_#bits / 2 + 1]
        mov     rcx, (__BIG_INTEGER_BYTES_#bits / 2) - 1
.check_loop_2:
        mov     byte [rax + rcx - 1], 0xff
        loop    .check_loop_2

.passed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret
.failed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret

__bi_bit_clear_twice_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        MemoryFillStatic rax, 0xff, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        mov     rbx, 0
        call    __bi_bit_clear_#bits

        lea     rax, [rsp]
        mov     rbx, 0
        call    __bi_bit_clear_#bits

        lea     rax, [rsp]
        cmp     byte [rax], 0xfe
        jne     .failed

        lea     rax, [rsp]
        mov     rcx, __BIG_INTEGER_BYTES_#bits - 1
.check_loop:
        mov     byte [rax + rcx], 0xff
        loop    .check_loop

.passed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret
.failed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret

}