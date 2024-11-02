include '../../../../src/math/bigint/div_rem/bi_div_rem_128_128.inc'

include 'bi_div_rem_test_macro.inc'

__bi_div_rem_128_128_test_core:
BiDivRemTestCoreMacro 128, 128

__bi_div_rem_128_128_test_measure_core:
BiDivRemTestPerformanceCoreMacro 128, 128


__bi_div_rem_128_128_test:
        push    rbx

        mov     rbx, __bi_div_rem_128_64_test_cases
        call    __bi_div_rem_128_128_test_core

        mov     rbx, __bi_div_rem_128_128_test_cases
        call    __bi_div_rem_128_128_test_measure_core

        pop     rbx
        ret
