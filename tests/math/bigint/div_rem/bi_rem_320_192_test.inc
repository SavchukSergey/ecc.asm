__bi_rem_320_192_test_core:
BiRemTestCoreMacro 320, 192

__bi_rem_320_192_test_measure_core:
BiRemTestPerformanceCoreMacro 320, 192


__bi_rem_320_192_test:
        push    rbx

        mov     rbx, __bi_div_rem_320_64_test_cases
        call    __bi_rem_320_192_test_core

        mov     rbx, __bi_div_rem_320_128_test_cases
        call    __bi_rem_320_192_test_core

        mov     rbx, __bi_div_rem_320_192_test_cases
        call    __bi_rem_320_192_test_measure_core

        pop     rbx
        ret
