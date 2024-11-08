__bi_div_rem_512_512_test_core:
BiDivRemTestCoreMacro 512, 512

__bi_div_rem_512_512_test_measure_core:
BiDivRemTestPerformanceCoreMacro 512, 512


__bi_div_rem_512_512_test:
        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_div_rem_512_512_test_core

        mov     rbx, __bi_div_rem_512_128_test_cases
        call    __bi_div_rem_512_512_test_core

        mov     rbx, __bi_div_rem_512_192_test_cases
        call    __bi_div_rem_512_512_test_core

        mov     rbx, __bi_div_rem_512_256_test_cases
        call    __bi_div_rem_512_512_test_core

        mov     rbx, __bi_div_rem_512_512_test_cases
        call    __bi_div_rem_512_512_test_measure_core

        ret
