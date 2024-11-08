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

.failed db TEXT_COLOR_ERROR, ' FAILED ', TEXT_COLOR_DEFAULT, '|', 0
.passed db TEXT_COLOR_SUCCESS, ' PASSED ', TEXT_COLOR_DEFAULT, '|', 0
