if ~ definite Console_WriteUInt64Hex

include 'write_char.inc'
include '../src/text/hex_format_digit.inc'

;input
; rcx - i64
Console_WriteUInt64Hex:
    push    rcx
    shr     rcx, 32
    call    Console_WriteUInt32Hex
    pop     rcx
    call    Console_WriteUInt32Hex
    ret


;input
; ecx - i32
Console_WriteUInt32Hex:
	push    rcx
	shr     rcx, 16
	call    Console_WriteUInt16Hex
	pop     rcx
	call    Console_WriteUInt16Hex
	ret

;input
; ecx - i32
Console_WriteUInt16Hex:
	push	rcx
	shr	rcx, 8
	call	Console_WriteUInt8Hex
	pop	rcx
	call	Console_WriteUInt8Hex
	ret

;input
; ecx - i32
Console_WriteUInt8Hex:
	push	rax
	mov	rax, rcx
	shr	rax, 4
	call	hex_format_digit
	call	Console_WriteChar

	mov	rax, rcx
	call	hex_format_digit
	call	Console_WriteChar
	pop	rax
	ret

end if