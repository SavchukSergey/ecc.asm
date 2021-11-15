macro BigIntegerBitClearTests bits {

include '../src/math/bigint/bit_clear/bit_clear.inc'

BigIntegerBitClear bits

__bi_bit_clear_test_#bits:
        sub     rsp, __BIG_INTEGER_BYTES_#bits

        lea     rax, [rsp]
        mov     rcx, __BIG_INTEGER_BYTES_#bits
.init_loop:
        mov     byte [rax + rcx - 1], 0xff
        loop    .init_loop

        lea     rax, [rsp]
        mov     rbx, 40
        call    __bi_bit_clear_#bits

        lea     rax, [rsp]
        mov     rbx, 70
        call    __bi_bit_clear_#bits

        lea     rax, [rsp]
        cmp     dword [rax], 0xffffffff
        jne     .failed
        cmp     dword [rax + 4], 0xfffffeff
        jne     .failed
        cmp     dword [rax + 8], 0xffffffbf
        jne     .failed
        cmp     dword [rax + 12], 0xffffffff
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