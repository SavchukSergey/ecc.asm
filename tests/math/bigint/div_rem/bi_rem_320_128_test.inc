__bi_rem_320_128_test_core:
BiRemTestCoreMacro 320, 128

__bi_rem_320_128_test_measure_core:
BiRemTestPerformanceCoreMacro 320, 128


__bi_rem_320_128_test:
        push    rbx

        mov     rbx, __bi_div_rem_320_64_test_cases
        call    __bi_rem_320_128_test_core

        mov     rbx, __bi_div_rem_320_128_test_cases
        call    __bi_rem_320_128_test_measure_core

        pop     rbx
        ret
