if definite ECC_TESTS
  CHECK_REG_ALIGNMENT = 0
  CHECK_STACK_ALIGNMENT = 0

  include '../../tests/console/write_u64_hex.inc'
else
  CHECK_REG_ALIGNMENT = 0
  CHECK_STACK_ALIGNMENT = 0
end if

;todo: different alignment 16, 32
macro CheckRegAligned reg, msg {
if CHECK_REG_ALIGNMENT = 1
local .reg_unaligned_msg, .reg_aligned

    test    reg, 0x0f
    jz      .reg_aligned

    push    rsi
    mov     rsi, reg_unaligned_prefix_msg
    call    Console_WriteString

    mov     rsi, .reg_unaligned_msg
    call    Console_WriteString
    pop     rsi

    mov     rcx, reg
    call    Console_WriteUInt64Hex

    call    Console_WriteLine

    int3
.reg_unaligned_msg:
  db msg
  db '=', 0

.reg_aligned:
end if
}

macro CheckRegBi128Alignment reg, msg {
if CHECK_REG_ALIGNMENT = 1
local .reg_unaligned_msg, .reg_aligned

    test    reg, 0x0f
    jz      .reg_aligned

    push    rsi
    mov     rsi, reg_bi128_unaligned_prefix_msg
    call    Console_WriteString

    mov     rsi, .reg_bi128_unaligned_msg
    call    Console_WriteString
    pop     rsi

    mov     rcx, reg
    call    Console_WriteUInt64Hex

    call    Console_WriteLine

    int3
.reg_bi128_unaligned_msg:
  db msg
  db '=', 0

.reg_aligned:
end if
}

macro CheckRegBi192Alignment reg, msg {
if CHECK_REG_ALIGNMENT = 1
local .reg_unaligned_msg, .reg_aligned

    test    reg, 0x0f
    jz      .reg_aligned

    push    rsi
    mov     rsi, reg_bi192_unaligned_prefix_msg
    call    Console_WriteString

    mov     rsi, .reg_bi192_unaligned_msg
    call    Console_WriteString
    pop     rsi

    mov     rcx, reg
    call    Console_WriteUInt64Hex

    call    Console_WriteLine

    int3
.reg_bi192_unaligned_msg:
  db msg
  db '=', 0

.reg_aligned:
end if
}

macro CheckRegBi256Alignment reg, msg {
if CHECK_REG_ALIGNMENT = 1
local .reg_unaligned_msg, .reg_aligned

    test    reg, 0x0f
    jz      .reg_aligned

    push    rsi
    mov     rsi, reg_bi256_unaligned_prefix_msg
    call    Console_WriteString

    mov     rsi, .reg_bi256_unaligned_msg
    call    Console_WriteString
    pop     rsi

    mov     rcx, reg
    call    Console_WriteUInt64Hex

    call    Console_WriteLine

    int3
.reg_bi256_unaligned_msg:
  db msg
  db '=', 0

.reg_aligned:
end if
}

macro CheckRegBi512Alignment reg, msg {
if CHECK_REG_ALIGNMENT = 1
local .reg_unaligned_msg, .reg_aligned

    test    reg, 0x0f
    jz      .reg_aligned

    push    rsi
    mov     rsi, reg_bi512_unaligned_prefix_msg
    call    Console_WriteString

    mov     rsi, .reg_bi512_unaligned_msg
    call    Console_WriteString
    pop     rsi

    mov     rcx, reg
    call    Console_WriteUInt64Hex

    call    Console_WriteLine

    int3
.reg_bi512_unaligned_msg:
  db msg
  db '=', 0

.reg_aligned:
end if
}

macro PrologCheckStackAligned msg {
if CHECK_STACK_ALIGNMENT = 1
    test    rsp, 0x0f
    jz      .stack_aligned

    push    rsi
    mov     rsi, stack_unaligned_msg
    call    Console_WriteString

    mov     rsi, .stack_unaligned_msg
    call    Console_WriteString
    pop     rsi

    int3
.stack_unaligned_msg:
  db msg
  db 13, 10, 0

.stack_aligned:
end if
}

if CHECK_STACK_ALIGNMENT = 1

stack_unaligned_msg db 'stack is unaligned ', 0
reg_unaligned_prefix_msg db 'reg is unaligned ', 0
reg_bi128_unaligned_prefix_msg db 'reg bi128 is unaligned ', 0
reg_bi192_unaligned_prefix_msg db 'reg bi192 is unaligned ', 0
reg_bi256_unaligned_prefix_msg db 'reg bi256 is unaligned ', 0
reg_bi512_unaligned_prefix_msg db 'reg bi512 is unaligned ', 0

end if


macro AlignLocalsStackFrame {
  rb ($ - rsp + 8) mod 16
}
