if ~ definite bi_shl_assign_128_1

; Shifts left bi128 by 1 bit
;input
;  rcx - value
bi_shl_assign_128_1:
        shl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        ret

end if