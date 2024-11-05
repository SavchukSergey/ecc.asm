include '../../../../src/math/bigint/div_rem/bi_rem_192_192.inc'

include 'bi_rem_test_macro.inc'

__bi_rem_192_192_test_core:
BiRemTestCoreMacro 192, 192

__bi_rem_192_192_test_measure_core:
BiRemTestPerformanceCoreMacro 192, 192


__bi_rem_192_192_test:
        push    rbx

        mov     rbx, __bi_div_rem_192_64_test_cases
        call    __bi_rem_192_192_test_core

        mov     rbx, __bi_div_rem_192_128_test_cases
        call    __bi_rem_192_192_test_measure_core

        mov     rbx, __bi_div_rem_192_192_test_cases
        call    __bi_rem_192_192_test_measure_core

        pop     rbx
        ret