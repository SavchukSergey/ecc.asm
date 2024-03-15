include '../src/console/write_u128_hex.inc'
include '../src/console/write_u256_hex.inc'
include '../src/console/write_u512_hex.inc'
include '../src/math/bigint/cmp/cmp.inc'
if ~ definite bi_assert_equal_128

;Zeroes bi value
;input
; rcx - expected
; rdx - actual
bi_assert_equal_128:
        push    rax rsi
        call    bi_cmp_128_128
        test    rax, rax
        jnz     .fail
        jmp     .end
.fail:
        lea     rsi, [.msg_1]
        call    Console_WriteString

        push    rcx
        mov     rcx, rdx
        call    Console_WriteUInt128Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteUInt128Hex

        lea     rsi, [.msg_3]
        call    Console_WriteString
.end:
        pop     rsi rax
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi128:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if


if ~ definite bi_assert_equal_256

;Zeroes bi value
;input
; rcx - expected
; rdx - actual
bi_assert_equal_256:
        push    rax rsi
        call    bi_cmp_256_256
        test    rax, rax
        jnz     .fail
        jmp     .end
.fail:
        lea     rsi, [.msg_1]
        call    Console_WriteString

        push    rcx
        mov     rcx, rdx
        call    Console_WriteUInt256Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteUInt256Hex

        lea     rsi, [.msg_3]
        call    Console_WriteString
.end:
        pop     rsi rax
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi256:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if


if ~ definite bi_assert_equal_512

;Zeroes bi value
;input
; rcx - expected
; rdx - actual
bi_assert_equal_512:
        push    rax rsi
        call    bi_cmp_512_512
        test    rax, rax
        jnz     .fail
        jmp     .end
.fail:
        lea     rsi, [.msg_1]
        call    Console_WriteString

        push    rcx
        mov     rcx, rdx
        call    Console_WriteUInt512Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteUInt512Hex

        lea     rsi, [.msg_3]
        call    Console_WriteString
.end:
        pop     rsi rax
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi512:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if