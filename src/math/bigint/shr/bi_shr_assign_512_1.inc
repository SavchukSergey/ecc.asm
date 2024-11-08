if ~ definite bi_shr_assign_512_1

; Shifts right
;input
; rcx - value
bi_shr_assign_512_1:
        shr     qword [rcx + 56], 1
        rcr     qword [rcx + 48], 1
        rcr     qword [rcx + 40], 1
        rcr     qword [rcx + 32], 1
        rcr     qword [rcx + 24], 1
        rcr     qword [rcx + 16], 1
        rcr     qword [rcx + 8], 1
        rcr     qword [rcx], 1
        ret

end if