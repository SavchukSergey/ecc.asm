__bi_rnd_384_test_core:
BiRndTestCoreMacro 384

__bi_rnd_384_test_measure_core:
BiRndTestPerformanceCoreMacro 384

__bi_rnd_384_test:
        call    __bi_rnd_384_test_core
        call    __bi_rnd_384_test_measure_core
        ret
