include '../src/math/bigint/cmp/bi_cmp_128_128.inc'
include 'console/write_u128_hex.inc'

if ~ definite bi_assert_equal_128

;Asserts two bi128 values to be equal
;input
; rcx - expected
; rdx - actual
bi_assert_equal_128:
	push	rax rsi
	call	bi_cmp_128_128
	test	rax, rax
	jnz	.fail
	clc
	jmp	.end
.fail:
	lea	rsi, [.msg_1]
	call	Console_WriteString

	push	rcx
	mov	rcx, rdx
	call	Console_WriteUInt128Hex
	pop	rcx

	lea	rsi, [.msg_2]
	call	Console_WriteString

	call	Console_WriteUInt128Hex

	lea	rsi, [.msg_3]
	call	Console_WriteString
	stc
.end:
	pop	rsi rax
	ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi128:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if