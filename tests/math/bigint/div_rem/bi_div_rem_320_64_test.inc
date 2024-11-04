include '../../../../src/math/bigint/div_rem/bi_div_rem_320_64.inc'

include 'bi_div_rem_test_macro.inc'

__bi_div_rem_320_64_test_measure_core:
BiDivRemTestPerformanceCoreMacro 320, 64


__bi_div_rem_320_64_test:
        push    rbx

        mov     rbx, __bi_div_rem_320_64_test_cases
        call    __bi_div_rem_320_64_test_measure_core

        pop     rbx
        ret
