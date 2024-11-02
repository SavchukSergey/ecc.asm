if ~ definite bi_mod_negate_256

include '../sub/bi_sub_256_256.inc'

;Negates bi256 values modulo
;input:
;  rcx - pointer to left bi256 value.
;  rdx - pointer to modulus bi256 value
;  r8 - pointer to bi256 result
bi_mod_negate_256:
        PrologCheckStackAligned 'bi_mod_negate_256'
        CheckRegBi256Alignment rcx, 'bi_mod_negate_256 rcx'
        CheckRegBi256Alignment rdx, 'bi_mod_negate_256 rdx'
        CheckRegBi256Alignment r8, 'bi_mod_negate_256 r8'

        xchg     rcx, rdx
        call    bi_sub_256_256
        ret
end if