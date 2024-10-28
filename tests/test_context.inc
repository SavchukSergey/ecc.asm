struc TestContext {
  .measure_start rq 1
  .measure_end rq 1
  .measure_loop rq 1
  .measures_count rq 1
  .measures_total rq 1
  .measures_min rq 1
  .measures_max rq 1
  .measures_avg rq 1
  .assert_fails rq 1
}

TestContextReg equ r12

TEST_MEASURE_CHUNK = 15000

include 'framework/get_cpu_timestamp.inc'
include 'framework/test_context_assert_fail.inc'
include 'framework/test_context_end_measure.inc'
include 'framework/test_context_finalize.inc'
include 'framework/test_context_init.inc'
include 'framework/test_context_measure_dec_chunk.inc'
include 'framework/test_context_start_measure.inc'
