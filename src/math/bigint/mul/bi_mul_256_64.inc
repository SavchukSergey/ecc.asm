if ~ definite bi_mul_256_64

;todo: output - 320 bits, not 512

if BMI2_ENABLED = 1
  include 'bi_mul_256_64.bmi2.inc'
  bi_mul_256_64 = bi_mul_256_64_bmi2
else
  include 'bi_mul_256_64.basic.inc'
  bi_mul_256_64 = bi_mul_256_64_basic
end if

end if
