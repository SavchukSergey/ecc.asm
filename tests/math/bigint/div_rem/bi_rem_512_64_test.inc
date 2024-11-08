__bi_rem_512_64_test_measure_core:
BiRemTestPerformanceCoreMacro 512, 64


__bi_rem_512_64_test:
        push    rbx

        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_rem_512_64_test_measure_core

        pop     rbx
        ret
