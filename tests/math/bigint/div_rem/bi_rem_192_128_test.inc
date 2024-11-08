__bi_rem_192_128_test_core:
BiRemTestCoreMacro 192, 128

__bi_rem_192_128_test_measure_core:
BiRemTestPerformanceCoreMacro 192, 128


__bi_rem_192_128_test:
        push    rbx

        mov     rbx, __bi_div_rem_192_64_test_cases
        call    __bi_rem_192_128_test_core

        mov     rbx, __bi_div_rem_192_128_test_cases
        call    __bi_rem_192_128_test_measure_core

        pop     rbx
        ret
