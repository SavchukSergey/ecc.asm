__bi_div_rem_448_64_test_measure_core:
BiDivRemTestPerformanceCoreMacro 448, 64


__bi_div_rem_448_64_test:
        push    rbx

        mov     rbx, __bi_div_rem_448_64_test_cases
        call    __bi_div_rem_448_64_test_measure_core

        pop     rbx
        ret
