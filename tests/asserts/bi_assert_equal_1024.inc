include '../src/math/bigint/cmp/bi_cmp_1024_1024.inc'
include 'console/write_u1024_hex.inc'

if ~ definite bi_assert_equal_1024

;Asserts two bi1024 values to be equal
;input
; rcx - expected
; rdx - actual
bi_assert_equal_1024:
	push	rax rsi
	call	bi_cmp_1024_1024
	test	rax, rax
	jnz	.fail
	clc
	jmp	.end
.fail:
	lea	rsi, [.msg_1]
	call	Console_WriteString

	push	rcx
	mov	rcx, rdx
	call	Console_WriteUInt1024Hex
	pop	rcx

	lea	rsi, [.msg_2]
	call	Console_WriteString

	call	Console_WriteUInt1024Hex

	lea	rsi, [.msg_3]
	call	Console_WriteString
	stc
.end:
	pop	rsi rax
	ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi1024:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if