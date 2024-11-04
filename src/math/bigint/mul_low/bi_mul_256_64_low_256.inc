if ~ definite bi_mul_256_64_low_256

if BMI2_ENABLED = 1
  include 'bi_mul_256_64_low_256.bmi2.inc'
  bi_mul_256_64_low_256 = bi_mul_256_64_low_256_bmi2
else
  include 'bi_mul_256_64_low_256.basic.inc'
  bi_mul_256_64_low_256 = bi_mul_256_64_low_256_basic
end if

end if
