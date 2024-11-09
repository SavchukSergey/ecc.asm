__bi_rem_384_192_test_core:
BiRemTestCoreMacro 384, 192

__bi_rem_384_192_test_measure_core:
BiRemTestPerformanceCoreMacro 384, 192


__bi_rem_384_192_test:
        sub     rsp, 8
        PrologCheckStackAligned '__bi_rem_384_192_test'

        mov     rbx, __bi_div_rem_384_64_test_cases
        call    __bi_rem_384_192_test_core

        mov     rbx, __bi_div_rem_384_128_test_cases
        call    __bi_rem_384_192_test_core

        mov     rbx, __bi_div_rem_384_192_test_cases
        call    __bi_rem_384_192_test_measure_core

        add     rsp, 8

        ret

