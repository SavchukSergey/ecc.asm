__bi_rem_256_128_test_core:
BiRemTestCoreMacro 256, 128

__bi_rem_256_128_test_measure_core:
BiRemTestPerformanceCoreMacro 256, 128


__bi_rem_256_128_test:
        push    rbx

        mov     rbx, __bi_div_rem_256_64_test_cases
        call    __bi_rem_256_128_test_core

        mov     rbx, __bi_div_rem_256_128_test_cases
        call    __bi_rem_256_128_test_measure_core

        pop     rbx
        ret
