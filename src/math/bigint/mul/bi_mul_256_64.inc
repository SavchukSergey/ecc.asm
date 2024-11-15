;Multiplies bi256 value by bi64 value
;input:
; rcx - pointer to left bi256 value
; rdx - bi64 value
; r8 - pointer to result bi320 value

if ~ definite bi_mul_256_64

if BMI2_ENABLED = 1
  include 'bi_mul_256_64.bmi2.inc'
  bi_mul_256_64 = bi_mul_256_64_bmi2
else
  include 'bi_mul_256_64.basic.inc'
  bi_mul_256_64 = bi_mul_256_64_basic
end if

end if
