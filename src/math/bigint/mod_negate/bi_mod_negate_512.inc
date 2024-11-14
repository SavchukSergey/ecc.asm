;Negates bi512 value modulo
;input:
;  rcx - pointer to left bi512 value.
;  rdx - pointer to modulus bi512 value
;  r8 - pointer to bi512 result
bi_mod_negate_512:
        PrologCheckStackAligned 'bi_mod_negate_512'
        CheckRegBi512Alignment rcx, 'bi_mod_negate_512 rcx'
        CheckRegBi512Alignment rdx, 'bi_mod_negate_512 rdx'
        CheckRegBi512Alignment r8, 'bi_mod_negate_512 r8'

        xchg     rcx, rdx
        call    bi_sub_512_512
        ret