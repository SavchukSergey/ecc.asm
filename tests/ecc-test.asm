format pe64 console
entry start

include 'win64a.inc'

section '.text' code readable executable
start:
        call    enable_vt_processing

        sub     rsp, 0x28
        mov     rsi, .welcome
        call    Console_WriteString

        mov     rax, __bi_tests_128
        mov     rsi, .bi128_fixture_name
        call    run_test_fixture

        mov     rax, __bi_tests_256
        mov     rsi, .bi256_fixture_name
        call    run_test_fixture

        mov     rax, __bi_tests_512
        mov     rsi, .bi512_fixture_name
        call    run_test_fixture

        invoke  ExitProcess, 0
        add     rsp, 0x28
        ret
.welcome db 'ecc.js tests', 13, 10, 0
.bi128_fixture_name db 'bi128', 0
.bi256_fixture_name db 'bi256', 0
.bi512_fixture_name db 'bi512', 0

include '../src/console/enable_vt_processing.inc'
include '../src/console/write_u64.inc'

get_cpu_timestamp:
        push    rdx
        rdtsc
        shl     rdx, 32
        or      rdx, rax
        mov     rdx, rax
        pop     rdx
        ret

run_test_fixture:
        push    rax rbx rsi
virtual at rsp
  .locals_start:
  .test rq 1
  .test_proc rq 1
  .test_start_timestamp rq 1
  .test_end_timestamp rq 1
  .test_result rq 1
  .locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.test], rax

        call    Console_WriteString

        mov     rsi, .tests_suffix
        call    Console_WriteString

        call    Console_WriteLine

.loop:
        mov     rax, [.test]
        mov     rbx, [rax]
        test    rbx, rbx
        jz      .end
        mov     [.test_proc], rbx
        add     qword [.test], 8

        mov     rsi, .test_prefix
        call    Console_WriteString

        mov     rsi, [.test]
        call    Console_WriteString
.test_name_end_loop:
        mov     rax, [.test]
        cmp     byte [rax], 0
        je      .test_name_end
        inc     [.test]
        jmp     .test_name_end_loop
.test_name_end:
        inc     [.test]

        mov     rsi, .test_suffix
        call    Console_WriteString

        call    get_cpu_timestamp
        mov     [.test_start_timestamp], rax
        call    [.test_proc]
        setc    byte [.test_result]
        call    get_cpu_timestamp
        mov     [.test_end_timestamp], rax

        cmp     byte [.test_result], 0x00
        je      .test_ok
.test_fail:
        mov     rsi, .failed
        call    Console_WriteString
        jmp     .test_end
.test_ok:
        mov     rsi, .passed
        call    Console_WriteString
        jmp     .test_end
.test_end:
        mov     rsi, .time_prefix
        call    Console_WriteString
        mov     rax, [.test_end_timestamp]
        sub     rax, [.test_start_timestamp]
        call    Console_WriteUInt64
        mov     rsi, .time_suffix
        call    Console_WriteString
        call    Console_WriteLine

        jmp     .loop
.end:
        leave
        pop     rsi rbx rax
        ret

.tests_suffix db ' tests', 0
.test_prefix db '    ', 0
.test_suffix db ' test', 0
.failed db TEXT_COLOR_ERROR, ' FAILED', TEXT_COLOR_DEFAULT, 0
.passed db TEXT_COLOR_SUCCESS, ' PASSED', TEXT_COLOR_DEFAULT, 0
.time_prefix db ' (', 0
.time_suffix db ' cpu ticks)', 0

include '../src/math/bigint.inc'
include 'math/bigint.tests.inc'
include '../src/math/rnd.inc'
include '../src/console/write_string.inc'
include '../src/console/write_line.inc'

section '.idata' import data readable writeable

  library kernel,'KERNEL32.DLL'

  import kernel,\
         ExitProcess,'ExitProcess', \
         GetStdHandle, 'GetStdHandle', \
         GetConsoleMode, 'GetConsoleMode', \
         SetConsoleMode, 'SetConsoleMode', \
         WriteFile, 'WriteFile'
