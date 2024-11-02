include '../../../../src/math/bigint/div_rem/bi_div_rem_512_256.inc'

include 'bi_div_rem_test_macro.inc'

__bi_div_rem_512_256_test_core:
BiDivRemTestCoreMacro 512, 256

__bi_div_rem_512_256_test_measure_core:
BiDivRemTestPerformanceCoreMacro 512, 256


__bi_div_rem_512_256_test:
        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_div_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_128_test_cases
        call    __bi_div_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_192_test_cases
        call    __bi_div_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_256_test_cases
        call    __bi_div_rem_512_256_test_measure_core

        ret
