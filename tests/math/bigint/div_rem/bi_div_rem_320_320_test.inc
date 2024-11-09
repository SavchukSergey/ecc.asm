__bi_div_rem_320_320_test_core:
BiDivRemTestCoreMacro 320, 320

__bi_div_rem_320_320_test_measure_core:
BiDivRemTestPerformanceCoreMacro 320, 320


__bi_div_rem_320_320_test:
        sub     rsp, 8
        PrologCheckStackAligned '__bi_div_rem_320_320_test'

        mov     rbx, __bi_div_rem_320_64_test_cases
        call    __bi_div_rem_320_320_test_core

        mov     rbx, __bi_div_rem_320_128_test_cases
        call    __bi_div_rem_320_320_test_core

        mov     rbx, __bi_div_rem_320_192_test_cases
        call    __bi_div_rem_320_320_test_core

        mov     rbx, __bi_div_rem_320_256_test_cases
        call    __bi_div_rem_320_320_test_core

        mov     rbx, __bi_div_rem_320_320_test_cases
        call    __bi_div_rem_320_320_test_measure_core

        add     rsp, 8

        ret

