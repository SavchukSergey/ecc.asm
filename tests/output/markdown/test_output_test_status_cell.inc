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

.failed db '![Static Badge](https://img.shields.io/badge/FAILED-red?style=for-the-badge) |', 0
.passed db '![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) |', 0

