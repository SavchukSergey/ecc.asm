if ~ definite bi_shr_assign_256_1

; Shifts right
;input
; rcx - value
bi_shr_assign_256_1:
        shr     qword [rcx + 24], 1
        rcr     qword [rcx + 16], 1
        rcr     qword [rcx + 8], 1
        rcr     qword [rcx], 1
        ret

end if
