if ~ definite guard

guard equ 0

include '../console/consts.inc'

macro GuardPreField {
 .guard_pre rq 1
}

macro GuardPostField {
 .guard_post rq 1
}

macro GuardInit {
    mov     rax, [guard_const]
    mov     [.guard_pre], rax
    mov     [.guard_post], rax
}

macro GuardCheck {
    mov     rax, [guard_const]
    cmp     [.guard_pre], rax
    je      .guard_pre_ok
    call     test_context_assert_fail
    lea     rsi, [guard_pre_failed_msg]
    call    Console_WriteString
.guard_pre_ok:

    mov     rax, [guard_const]
    cmp     [.guard_post], rax
    je      .guard_post_ok
    call     test_context_assert_fail
    lea     rsi, [guard_post_failed_msg]
    call    Console_WriteString
.guard_post_ok:
}

align 16

guard_const:
  dq 0x0123456789abcdef

guard_pre_failed_msg db TEXT_COLOR_ERROR, 'Guard prefix failed', 13, 10, 0
guard_post_failed_msg db TEXT_COLOR_ERROR, 'Guard suffix failed', 13, 10, 0

end if