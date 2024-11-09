__bi_rem_448_192_test_core:
BiRemTestCoreMacro 448, 192

__bi_rem_448_192_test_measure_core:
BiRemTestPerformanceCoreMacro 448, 192


__bi_rem_448_192_test:
        sub     rsp, 8
        PrologCheckStackAligned '__bi_rem_448_192_test'

        mov     rbx, __bi_div_rem_448_64_test_cases
        call    __bi_rem_448_192_test_core

        mov     rbx, __bi_div_rem_448_128_test_cases
        call    __bi_rem_448_192_test_core

        mov     rbx, __bi_div_rem_448_192_test_cases
        call    __bi_rem_448_192_test_measure_core

        add     rsp, 8

        ret

