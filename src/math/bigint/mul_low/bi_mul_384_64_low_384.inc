if ~ definite bi_mul_384_64_low_384

if BMI2_ENABLED = 1
  include 'bi_mul_384_64_low_384.bmi2.inc'
  bi_mul_384_64_low_384 = bi_mul_384_64_low_384_bmi2
else
 ; include 'bi_mul_384_64_low_384.basic.inc'
 ; bi_mul_384_64_low_384 = bi_mul_384_64_low_384_basic
end if

end if
