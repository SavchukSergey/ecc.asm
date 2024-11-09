__bi_rem_256_256_test_core:
BiDivRemTestCoreMacro 256, 256

__bi_rem_256_256_test_measure_core:
BiDivRemTestPerformanceCoreMacro 256, 256


__bi_rem_256_256_test:
        push    rbx

        mov     rbx, __bi_div_rem_256_64_test_cases
        call    __bi_rem_256_256_test_core

        mov     rbx, __bi_div_rem_256_128_test_cases
        call    __bi_rem_256_256_test_core

        mov     rbx, __bi_div_rem_256_192_test_cases
        call    __bi_rem_256_256_test_core

        mov     rbx, __bi_div_rem_256_256_test_cases
        call    __bi_rem_256_256_test_measure_core

        pop     rbx
        ret
