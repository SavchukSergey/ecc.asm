macro BigIntegerBitSetTests bits {

include '../src/math/bigint/bit_set/bit_set.inc'

BigIntegerBitSet bits

__bi_bit_set_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        mov     rcx, __BIG_INTEGER_BYTES_#bits
.init_loop:
        mov     byte [rax + rcx - 1], 0x00
        loop    .init_loop

        lea     rax, [rsp]
        mov     rbx, 40
        call    __bi_bit_set_#bits

        lea     rax, [rsp]
        mov     rbx, 70
        call    __bi_bit_set_#bits

        lea     rax, [rsp]
        cmp     dword [rax], 0x00000000
        jne     .failed
        cmp     dword [rax + 4], 0x00000100
        jne     .failed
        cmp     dword [rax + 8], 0x00000040
        jne     .failed
        cmp     dword [rax + 12], 0x00000000
        jne     .failed


.passed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret
.failed:
        add    rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret

}