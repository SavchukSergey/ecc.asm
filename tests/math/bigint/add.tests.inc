macro BigIntegerAddTests bits {

include '../src/math/bigint/add/add.inc'
BigIntegerAdd bits

__bi_add_test_#bits:
virtual at rsp
  .left rb __BIG_INTEGER_BYTES_#bits
  .right rb __BIG_INTEGER_BYTES_#bits
  .result rb __BIG_INTEGER_BYTES_#bits
end virtual
        sub     rsp, 3 * __BIG_INTEGER_BYTES_#bits
        lea     rax, [.left]
        call    __bi_zero_#bits
        lea     rax, [.right]
        call    __bi_zero_#bits
        lea     rax, [.result]
        call    __bi_zero_#bits

        mov     dword [.left + 0], 0x01234567
        mov     dword [.left + 4], 0x89abcdef
        mov     dword [.right + 0], 0x33333333
        mov     dword [.right + 4], 0x44444444
if bits >= 128
        mov     dword [.left + 8], 0x11111111
        mov     dword [.left + 12], 0x22222222
        mov     dword [.right + 8], 0x55555555
        mov     dword [.right + 12], 0x66666666
end if

        lea     rax, [.left]
        lea     rbx, [.right]
        lea     rdi, [.result]
        call    test_context_start_measure
        call    __bi_add_#bits
        call    test_context_end_measure

        cmp      dword [.result + 0], 0x3456789A
        jne      .fail
        cmp      dword [.result + 4], 0xCDF01233
        jne      .fail
if bits >= 128
        cmp      dword [.result + 8], 0x66666666
        jne      .fail
        cmp      dword [.result + 12], 0x088888888
        jne      .fail
end if

        jmp     .pass

.fail:
        add     rsp, 3 * __BIG_INTEGER_BYTES_#bits
        stc
        ret
.pass:
        add     rsp, 3 * __BIG_INTEGER_BYTES_#bits
        clc
        ret

}