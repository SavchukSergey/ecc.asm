__bi_rnd_128_test_core:
BiRndTestCoreMacro 128

__bi_rnd_128_test_measure_core:
BiRndTestPerformanceCoreMacro 128

__bi_rnd_128_test:
        call    __bi_rnd_128_test_core
        call    __bi_rnd_128_test_measure_core
        ret
