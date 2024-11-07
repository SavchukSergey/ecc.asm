if ~ definite bi_mul_320_64

if BMI2_ENABLED = 1
  include 'bi_mul_320_64.bmi2.inc'
  bi_mul_320_64 = bi_mul_320_64_bmi2
else
;  include 'bi_mul_320_64.basic.inc'
;  bi_mul_320_64 = bi_mul_320_64_basic
end if

end if
