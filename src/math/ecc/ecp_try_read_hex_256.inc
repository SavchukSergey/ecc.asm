if ~ definite ecp_try_read_hex_256

;Reads ECPoint256 as hex string
;input
; rcx - pointer to hex string
; rdx - destination ECPoint256
;output
;  rax - 1 success
;  rax - 0 failure
ecp_try_read_hex_256:
        call    bi_try_read_hex_256
        test    rax, rax
        jz      .failure
        add     rcx, __BIG_INTEGER_BYTES_256 * 2
        add     rdx, ECPoint256.y
        call    bi_try_read_hex_256
        test    rax, rax
        jz      .failure
        ret
.failure:
        ret
end if
