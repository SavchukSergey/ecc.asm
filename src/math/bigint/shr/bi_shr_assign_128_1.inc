if ~ definite bi_shr_assign_128_1

; Shifts right
;input
; rcx - value
bi_shr_assign_128_1:
        shr     qword [rcx + 8], 1
        rcr     qword [rcx], 1
        ret

end if


