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

;        mov     rax, __bi_tests_256
;        mov     rsi, .bi256_fixture_name
;        call    run_test_fixture

;        mov     rax, __bi_tests_512
;        mov     rsi, .bi512_fixture_name
;        call    run_test_fixture

        invoke  ExitProcess, 0
        add     rsp, 0x28
        ret
.welcome db 'ecc.js tests', 13, 10, 0
.bi128_fixture_name db 'bi128', 0
.bi256_fixture_name db 'bi256', 0
.bi512_fixture_name db 'bi512', 0

include '../src/console/enable_vt_processing.inc'

run_test_fixture:
        push    rax rbx rsi

        call    Console_WriteString

        mov     rsi, .tests_suffix
        call    Console_WriteString

        call    Console_WriteLine

.loop:
        mov     rbx, [rax]
        test    rbx, rbx
        jz      .end
        add     rax, 8

        mov     rsi, .test_prefix
        call    Console_WriteString

        mov     rsi, rax
        call    Console_WriteString
.test_name_end_loop:
        cmp     byte [rax], 0
        je      .test_name_end
        inc     rax
        jmp     .test_name_end_loop
.test_name_end:
        inc     rax

        mov     rsi, .test_suffix
        call    Console_WriteString

        push    rax
        call    rbx
        jnc      .test_ok
.test_fail:
        mov     rsi, .failed
        call    Console_WriteString
        jmp     .test_end
.test_ok:
        mov     rsi, .passed
        call    Console_WriteString
        jmp     .test_end
.test_end:
        call    Console_WriteLine
        pop     rax

        jmp     .loop
.end:
        pop     rsi rbx rax
        ret

.tests_suffix db ' tests', 0
.test_prefix db '    ', 0
.test_suffix db ' test', 0
.failed db TEXT_COLOR_ERROR, ' FAILED', TEXT_COLOR_DEFAULT, 0
.passed db TEXT_COLOR_SUCCESS, ' PASSED', TEXT_COLOR_DEFAULT, 0

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
