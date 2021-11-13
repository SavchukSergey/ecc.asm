include '../../debugger/index.inc'

macro BigIntegerReadHexTests bits {

__bi_read_hex_test_#bits:
virtual at rsp
  .value rb __BIG_INTEGER_BYTES_#bits
end virtual
        sub     rsp, __BIG_INTEGER_BYTES_#bits
        mov     rsi, __bi_read_hex_test.src
        lea     rdi, [.value]
        call    __bi_read_hex_#bits

        jc      .fail

        lea     rdi, [.value + __BIG_INTEGER_BYTES_#bits]

        sub      rdi, 4

        cmp     dword [rdi], 0xf48fde75
        jne     .fail
if bits > 32
        sub      rdi, 4
        cmp     dword [rdi], 0x8282cfc7
        jne     .fail
end if
if bits > 64
        sub      rdi, 4
        cmp     dword [rdi], 0xb9eaa543
        jne     .fail
end if
if bits > 96
        sub      rdi, 4
        cmp     dword [rdi], 0x0d7d4b7e
        jne     .fail
end if
if bits > 128
        sub      rdi, 4
        cmp     dword [rdi], 0xe163b92d
        jne     .fail
end if
if bits > 160
        sub      rdi, 4
        cmp     dword [rdi], 0xdb2e9eda
        jne     .fail
end if
if bits > 192
        sub      rdi, 4
        cmp     dword [rdi], 0x9eb7eb7b
        jne     .fail
end if
if bits > 224
        sub      rdi, 4
        cmp     dword [rdi], 0xbfbe7a5a
        jne     .fail
end if
if bits > 256
        sub      rdi, 4
        cmp     dword [rdi], 0x757dc828
        jne     .fail
end if
;75a7fbfffe5b0869bff50623edee8cf79d6a34a3b6ef93f35798a00a
        jmp     .pass
.fail:
        add     rsp, __BIG_INTEGER_BYTES_#bits
        stc
        ret
.pass:
        add     rsp, __BIG_INTEGER_BYTES_#bits
        clc
        ret

}

__bi_read_hex_test:
.src db 'f48fde758282cfc7b9eaa5430d7d4b7ee163b92ddb2e9eda9eb7eb7bbfbe7a5a757dc8285a7fbfffe5b0869bff50623edee8cf79d6a34a3b6ef93f35798a00a7'
