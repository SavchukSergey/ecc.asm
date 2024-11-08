__bi_rnd_256_test_core:
BiRndTestCoreMacro 256

__bi_rnd_256_test_measure_core:
BiRndTestPerformanceCoreMacro 256

__bi_rnd_256_test:
        call    __bi_rnd_256_test_core
        call    __bi_rnd_256_test_measure_core
        ret
