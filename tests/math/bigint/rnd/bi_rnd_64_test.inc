__bi_rnd_64_test_core:
BiRndTestCoreMacro 64

__bi_rnd_64_test_measure_core:
BiRndTestPerformanceCoreMacro 64

__bi_rnd_64_test:
        call    __bi_rnd_64_test_core
        call    __bi_rnd_64_test_measure_core
        ret
