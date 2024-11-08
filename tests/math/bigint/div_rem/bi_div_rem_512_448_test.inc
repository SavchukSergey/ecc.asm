__bi_div_rem_512_448_test_core:
BiDivRemTestCoreMacro 512, 448

__bi_div_rem_512_448_test_measure_core:
BiDivRemTestPerformanceCoreMacro 512, 448


__bi_div_rem_512_448_test:
        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_div_rem_512_448_test_core

        mov     rbx, __bi_div_rem_512_128_test_cases
        call    __bi_div_rem_512_448_test_core

        mov     rbx, __bi_div_rem_512_192_test_cases
        call    __bi_div_rem_512_448_test_core

        mov     rbx, __bi_div_rem_512_256_test_cases
        call    __bi_div_rem_512_448_test_core

        mov     rbx, __bi_div_rem_512_384_test_cases
        call    __bi_div_rem_512_448_test_core

        mov     rbx, __bi_div_rem_512_448_test_cases
        call    __bi_div_rem_512_448_test_measure_core

        ret
