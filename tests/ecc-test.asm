format pe64 console
entry start

include 'win64a.inc'

section '.text' code readable executable
start:
        call    enable_vt_processing

        sub     rsp, 0x28

        call    test_output_start

        call    run_test_calibrate

        mov     rax, __bi_tests_128
        mov     rsi, .bi128_fixture_name
        call    run_test_fixture

        mov     rax, __bi_tests_256
        mov     rsi, .bi256_fixture_name
        call    run_test_fixture

        mov     rax, __bi_tests_512
        mov     rsi, .bi512_fixture_name
        call    run_test_fixture

        mov     rax, __bi_tests_1024
        mov     rsi, .bi1024_fixture_name
        call    run_test_fixture

        call    test_output_end

        invoke  ExitProcess, 0
        add     rsp, 0x28
        ret
.empty_fixture_name db 'calibrate', 0
.bi128_fixture_name db 'bi128', 0
.bi256_fixture_name db 'bi256', 0
.bi512_fixture_name db 'bi512', 0
.bi1024_fixture_name db 'bi1024', 0

include 'console/enable_vt_processing.inc'
include 'console/write_u64.inc'
include 'test_context.inc'
include 'test_output_html.inc'

run_test_calibrate:
virtual at rsp
  .locals_start:
    .result TestContext
  .locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        lea     TestContextReg, [.result]
        call    test_context_init

        mov     [calibration_shift], 0
        mov     rbx, -1
        mov     rcx, 10000
.count_loop:
        push    rbx rcx
        call    [.empty_ref]
        pop     rcx rbx
        loop    .count_loop

        call    test_context_finalize
        mov     rax, [.result.measures_min]
        mov     [calibration_shift], rax

        leave
        ret
.empty:
        call    test_context_start_measure
        call    test_context_end_measure
        ret
.empty_ref dq .empty

run_test_fixture:
        push    rax rbx rsi
virtual at rsp
  .locals_start:
  .test rq 1
  .test_proc rq 1
  .test_count rq 1
  .test_successes rq 1
  .test_failures rq 1
  .result TestContext
  .locals_end:
end virtual
virtual at TestContextReg
  .context TestContext
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.test], rax

        call    test_output_start_chapter

        mov     rcx, rsi
        call    test_output_chapter_title

        call    test_output_start_chapter_table

.loop:
        mov     rax, [.test]
        mov     rbx, [rax]
        test    rbx, rbx
        jz      .end
        mov     [.test_proc], rbx
        add     qword [.test], 8

        call    test_output_start_test

        mov     rcx, [.test]
        call    test_output_test_name_cell

.test_name_end_loop:
        mov     rax, [.test]
        cmp     byte [rax], 0
        je      .test_name_end
        inc     [.test]
        jmp     .test_name_end_loop
.test_name_end:
        inc     [.test]

        mov     qword [.test_count], 0
        mov     qword [.test_successes], 0
        mov     qword [.test_failures], 0

        lea     TestContextReg, [.result]
        call    test_context_init
.count_loop:
        call    [.test_proc]
        jnc      .count_pass
.count_fail:
        inc     qword [.test_failures]
        jmp     .count_continue
.count_pass:
        inc     qword [.test_successes]
        jmp     .count_continue
.count_continue:
        inc     [.test_count]
        cmp     [.test_failures], 0
        jne     .count_loop_end
        cmp     qword [.test_count], 5000
        jb      .count_loop

.count_loop_end:
        call    test_context_finalize

        cmp     [.test_failures], 0x00
        je      .test_ok
.test_fail:
        mov     rcx, 1
        call    test_output_test_status_cell
        jmp     .test_end
.test_ok:
        xor     rcx, rcx
        call    test_output_test_status_cell
        jmp     .test_end
.test_end:
        mov     rcx, [.context.measures_min]
        call    test_output_test_min_ticks_cell

        mov     rcx, [.context.measures_max]
        call    test_output_test_max_ticks_cell

        call    test_output_end_test

        jmp     .loop
.end:
        call    test_output_end_chapter_table

        call    test_output_end_chapter

        leave
        pop     rsi rbx rax
        ret

include '../src/math/bigint.inc'
include 'math/bigint.tests.inc'
include '../src/math/rnd.inc'
include 'console/write_string.inc'
include 'console/write_line.inc'

section '.bss' data readable writeable
calibration_shift rq 1


section '.idata' import data readable writeable

  library kernel,'KERNEL32.DLL'

  import kernel,\
         ExitProcess,'ExitProcess', \
         GetStdHandle, 'GetStdHandle', \
         GetConsoleMode, 'GetConsoleMode', \
         SetConsoleMode, 'SetConsoleMode', \
         WriteFile, 'WriteFile'
