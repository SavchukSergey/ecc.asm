__bi_rnd_448_test_core:
BiRndTestCoreMacro 448

__bi_rnd_448_test_measure_core:
BiRndTestPerformanceCoreMacro 448

__bi_rnd_448_test:
        call    __bi_rnd_448_test_core
        call    __bi_rnd_448_test_measure_core
        ret
