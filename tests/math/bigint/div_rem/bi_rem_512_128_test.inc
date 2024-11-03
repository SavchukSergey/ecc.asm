include '../../../../src/math/bigint/div_rem/bi_rem_512_128.inc'

include 'bi_rem_test_macro.inc'

__bi_rem_512_128_test_core:
BiRemTestCoreMacro 512, 128

__bi_rem_512_128_test_measure_core:
BiRemTestPerformanceCoreMacro 512, 128


__bi_rem_512_128_test:
        sub     rsp, 8
        PrologCheckStackAligned '__bi_rem_512_128_test'

        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_rem_512_128_test_core

        mov     rbx, __bi_div_rem_512_128_test_cases
        call    __bi_rem_512_128_test_measure_core

        add     rsp, 8

        ret

