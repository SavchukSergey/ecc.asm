if ~ definite bi_mul_128_128_low_128

if BMI2_ENABLED = 1
  include 'bi_mul_128_128_low_128.bmi2.inc'
  bi_mul_128_128_low_128 = bi_mul_128_128_low_128_bmi2
else
  include 'bi_mul_128_128_low_128.basic.inc'
  bi_mul_128_128_low_128 = bi_mul_128_128_low_128_basic
end if

end if
