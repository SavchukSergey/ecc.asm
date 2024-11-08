__bi_rnd_320_test_core:
BiRndTestCoreMacro 320

__bi_rnd_320_test_measure_core:
BiRndTestPerformanceCoreMacro 320

__bi_rnd_320_test:
        call    __bi_rnd_320_test_core
        call    __bi_rnd_320_test_measure_core
        ret
