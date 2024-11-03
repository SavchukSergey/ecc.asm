include '../../../../src/math/bigint/div_rem/bi_rem_128_128.inc'

include 'bi_rem_test_macro.inc'

__bi_rem_128_128_test_core:
BiRemTestCoreMacro 128, 128

__bi_rem_128_128_test_measure_core:
BiRemTestPerformanceCoreMacro 128, 128

__bi_rem_128_128_test:
        push    rbx

        mov     rbx, __bi_div_rem_128_64_test_cases
        call    __bi_rem_128_128_test_core

        mov     rbx, __bi_div_rem_128_128_test_cases
        call    __bi_rem_128_128_test_measure_core

        pop     rbx
        ret
