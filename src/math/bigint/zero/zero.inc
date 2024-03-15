if ~ definite bi_zero_128

;Zeroes bi value
;input
; rcx - integer to result
bi_zero_128:
        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        ret

end if

if ~ definite bi_zero_256

;Zeroes bi value
;input
; rcx - integer to result
bi_zero_256:
        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        ret

end if

if ~ definite bi_zero_512

;Zeroes bi value
;input
; rcx - integer to result
bi_zero_512:
        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        mov     [rcx + 40], rax
        mov     [rcx + 48], rax
        mov     [rcx + 56], rax
        ret

end if