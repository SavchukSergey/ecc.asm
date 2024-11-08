if ~ definite ecpoint256_copy

;Copies ecpoint
;input:
;  rcx - pointer to target ecpoint256
;  rdx - pointer to source ecpoint256

; same signature, same result
ecpoint256_copy = bi_copy_512

end if