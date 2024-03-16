if ~ definite bi_shl_assign_128_1

; Shifts right
;input
; rcx - value
bi_shl_assign_128_1:
        clc
        rcl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        ret

end if

if ~ definite bi_shl_assign_256_1

; Shifts right
;input
; rcx - value
bi_shl_assign_256_1:
        clc
        rcl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        rcl     qword [rcx + 16], 1
        rcl     qword [rcx + 24], 1
        ret

end if

if ~ definite bi_shl_assign_512_1

; Shifts right
;input
; rcx - value
bi_shl_assign_512_1:
        clc
        rcl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        rcl     qword [rcx + 16], 1
        rcl     qword [rcx + 24], 1
        rcl     qword [rcx + 32], 1
        rcl     qword [rcx + 40], 1
        rcl     qword [rcx + 48], 1
        rcl     qword [rcx + 56], 1
        ret

end if