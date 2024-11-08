if ~ definite bi_one_128

;Sets 1 to bi128 value
;input
; rcx - pointer to result
bi_one_128:
        mov     qword [rcx], 1
        mov     qword [rcx + 8], 0
        ret

end if