if ~ definite ec_projective_point_256_shl

;Shifts left ECProjectivePoint256 point
;input:
;  rcx - pointer to source ECProjectivePoint256 point
;  rdx - count
;   r8 - pointer to destination ECProjectivePoint256 point
ec_projective_point_256_shl:
virtual at rsp
  label .locals_start
  .source rq 1
  .count rq 1
  .result rq 1

  .ptr_1 rq 1
  .ptr_2 rq 1
  .temp_1 ECProjectivePoint256
  .temp_2 ECProjectivePoint256

  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_projective_point_256_shl'
    CheckRegBi256Alignment rcx, 'ec_projective_point_256_shl rcx'
    CheckRegBi256Alignment r8, 'ec_projective_point_256_shl r8'

        mov     [.source], rcx
        mov     [.count], rdx
        mov     [.result], r8

        lea     rax, [.temp_1]
        mov     [.ptr_1], rax

        lea     rax, [.temp_2]
        mov     [.ptr_2], rax

        lea     rcx, [.temp_1]
        mov     rdx, [.source]
        call    ec_projective_point_256_copy
.loop:
        cmp     [.count], 0
        je      .end
        dec     [.count]

        mov     rcx, [.ptr_1]
        mov     rdx, [.ptr_2]
        call    ec_projective_point_256_double

        mov     rax, [.ptr_1]
        xchg    [.ptr_2], rax
        mov     [.ptr_1], rax

        jmp     .loop
.end:

        mov     rcx, [.result]
        mov     rdx, [.ptr_1]
        call    ec_projective_point_256_copy

        add     rsp, .locals_end - .locals_start
        ret

end if