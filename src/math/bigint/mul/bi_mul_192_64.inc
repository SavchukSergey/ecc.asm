;Multiplies bi192 by bi64
;input:
;   rcx - pointer to bi192 left value
;   rdx - bi64 right value
;   r8 - pointer to bi256 result value

if BMI2_ENABLED = 1
  include 'bi_mul_192_64.bmi2.inc'
  bi_mul_192_64 = bi_mul_192_64_bmi2
else
  include 'bi_mul_192_64.basic.inc'
  bi_mul_192_64 = bi_mul_192_64_basic
end if
