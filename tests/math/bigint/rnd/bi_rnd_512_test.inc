__bi_rnd_512_test_core:
BiRndTestCoreMacro 512

__bi_rnd_512_test_measure_core:
BiRndTestPerformanceCoreMacro 512

__bi_rnd_512_test:
        call    __bi_rnd_512_test_core
        call    __bi_rnd_512_test_measure_core
        ret
