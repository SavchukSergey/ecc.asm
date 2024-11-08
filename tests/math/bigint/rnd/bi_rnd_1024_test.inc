__bi_rnd_1024_test_core:
BiRndTestCoreMacro 1024

__bi_rnd_1024_test_measure_core:
BiRndTestPerformanceCoreMacro 1024

__bi_rnd_1024_test:
        call    __bi_rnd_1024_test_core
        call    __bi_rnd_1024_test_measure_core
        ret
