struct TestContext
  measure_start rq 1
  measure_end rq 1
ends

get_cpu_timestamp:
        push    rcx rdx
        rdtscp
        shl     rdx, 32
        or      rdx, rax
        mov     rdx, rax
        pop     rdx rcx
        ret

test_context_init:
virtual at r8
  .context TestContext
end virtual
        mov     qword [.context.measure_start], 0
        mov     qword [.context.measure_end], 0
        ret

test_context_start_measure:
virtual at r8
  .context TestContext
end virtual
        push    rax
        pushfq
        call    get_cpu_timestamp
        mov     [.context.measure_start], rax
        popfq
        pop     rax
        ret

test_context_end_measure:
virtual at r8
  .context TestContext
end virtual
        push    rax
        pushfq
        call    get_cpu_timestamp
        mov     [.context.measure_end], rax
        popfq
        pop     rax
        ret

macro ExpectBigIntegerEqualsHex bits {

include '../src/math/bigint/read_hex.inc'
include '../src/math/bigint/dump/dump.inc'
BigIntegerReadHex bits
BigIntegerDump bits

expect_bi_equals_hex_#bits:
        push    rax rbx
virtual at rsp
.locals_start:
        .expected_arg rq 1
        .actual_arg rq 1
        .expected rb __BIG_INTEGER_BYTES_#bits
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.actual_arg], rax
        mov     [.expected_arg], rbx

        mov     rsi, [.expected_arg]
        lea     rdi, [.expected]
        call    __bi_read_hex_#bits

        mov     rax, [.actual_arg]
        lea     rbx, [.expected]
        call    __bi_cmp_#bits
        jne     .failed
.passed:
        leave
        pop     rbx rax
        clc
        ret
.failed:
        call    Console_WriteLine
        mov     rsi, expect_msgs.equals_failed
        call    Console_WriteString

        lea     rax, [.expected]
        call    __bi_dump_#bits
        call    Console_WriteLine

        mov     rax, [.actual_arg]
        call    __bi_dump_#bits
        call    Console_WriteLine
        leave
        pop     rbx rax
        stc
        ret
}

expect_msgs:
  .equals_failed db TEXT_COLOR_ERROR, 'equals failed ', 13, 10, 0

ExpectBigIntegerEqualsHex 128
ExpectBigIntegerEqualsHex 256
ExpectBigIntegerEqualsHex 512
ExpectBigIntegerEqualsHex 1024
