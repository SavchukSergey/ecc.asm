include '../../../../src/math/bigint/div_rem/bi_rem_512_256.inc'

include 'bi_rem_test_macro.inc'

__bi_rem_512_256_test_core:
BiRemTestCoreMacro 512, 256

__bi_rem_512_256_test_measure_core:
BiRemTestPerformanceCoreMacro 512, 256


__bi_rem_512_256_test:
        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_128_test_cases
        call    __bi_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_192_test_cases
        call    __bi_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_256_test_cases
        call    __bi_rem_512_256_test_measure_core

        ret
