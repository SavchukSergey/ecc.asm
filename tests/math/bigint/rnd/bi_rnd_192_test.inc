__bi_rnd_192_test_core:
BiRndTestCoreMacro 192

__bi_rnd_192_test_measure_core:
BiRndTestPerformanceCoreMacro 192

__bi_rnd_192_test:
        call    __bi_rnd_192_test_core
        call    __bi_rnd_192_test_measure_core
        ret
