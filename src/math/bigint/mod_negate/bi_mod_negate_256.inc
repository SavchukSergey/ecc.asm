;Negates bi256 value modulo
;input:
;  rcx - pointer to left bi256 value.
;  rdx - pointer to modulus bi256 value
;  r8 - pointer to bi256 result
bi_mod_negate_256:
        PrologCheckStackAligned 'bi_mod_negate_256'
        CheckRegBi256Alignment rcx, 'bi_mod_negate_256 rcx'
        CheckRegBi256Alignment rdx, 'bi_mod_negate_256 rdx'
        CheckRegBi256Alignment r8, 'bi_mod_negate_256 r8'
        call      bi_is_zero_256
        jz        .zero

        xchg      rcx, rdx
        jmp       bi_sub_256_256
.zero:
        mov       rcx, r8
        Fast_Zero 256
        ret