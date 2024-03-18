include '../src/math/bigint/zero/bi_zero_128.inc'

__bi_zero_128_test:
        sub     rsp, __BIG_INTEGER_BYTES_128
        mov     rcx, rsp
        mov     dword [rcx], 0x01234567
        mov     dword [rcx + 4], 0x89abcdef
        call    test_context_start_measure
        mov     rcx, rsp
        call    bi_zero_128
        call    test_context_end_measure

        mov     rcx, rsp
        cmp     qword [rcx + 0], 0
        jne     .fail

.pass:
        add     rsp, __BIG_INTEGER_BYTES_128
        clc
        ret
.fail:
        add     rsp, __BIG_INTEGER_BYTES_128
        stc
        ret


