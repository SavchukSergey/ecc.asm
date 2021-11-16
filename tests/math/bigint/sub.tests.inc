macro BigIntegerSubTests bits {

include '../src/math/bigint/sub/sub.inc'
BigIntegerSub bits

__bi_sub_neg_test_#bits:
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
        call    __bi_sub_#bits
        call    test_context_end_measure

        cmp      dword [.result + 0], 0xCDF01234
        jne      .fail
        cmp      dword [.result + 4], 0x456789AA
        jne      .fail
if bits >= 128
        cmp      dword [.result + 8], 0xBBBBBBBC
        jne      .fail
        cmp      dword [.result + 12], 0xBBBBBBBB
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

__bi_sub_pos_test_#bits:
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

        lea     rax, [.right]
        lea     rbx, [.left]
        lea     rdi, [.result]
        call    test_context_start_measure
        call    __bi_sub_#bits
        call    test_context_end_measure

        cmp      dword [.result + 0], 0x320FEDCC
        jne      .fail
        cmp      dword [.result + 4], 0xBA987655
        jne      .fail
if bits >= 128
        cmp      dword [.result + 8], 0x44444443
        jne      .fail
        cmp      dword [.result + 12], 0x44444444
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