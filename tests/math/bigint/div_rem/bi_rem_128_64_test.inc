include '../../../../src/math/bigint/div_rem/bi_rem_128_64.inc'

include 'bi_rem_test_macro.inc'

__bi_rem_128_64_test_measure_core:
BiRemTestPerformanceCoreMacro 128, 64

__bi_rem_128_64_test:
        push    rbx

        mov     rbx, __bi_div_rem_128_64_test_cases
        call    __bi_rem_128_64_test_measure_core

        pop     rbx
        ret
