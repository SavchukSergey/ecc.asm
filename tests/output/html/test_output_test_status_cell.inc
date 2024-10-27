include '../../console/write_string.inc'

; rcx - non zero if test is failed
test_output_test_status_cell:
    test    rcx, rcx
    je      .test_ok
.test_fail:
    mov     rsi, .failed
    call    Console_WriteString
    ret
.test_ok:
    mov     rsi, .passed
    call    Console_WriteString
    ret
.failed db '    <td class="text-center"><span class="badge text-bg-danger">FAILED</span></td>', 13, 10, 0
.passed db '    <td class="text-center"><span class="badge text-bg-success">PASSED</span></td>', 13, 10, 0