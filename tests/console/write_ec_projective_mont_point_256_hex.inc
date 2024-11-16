if ~ definite Console_WriteECProjectiveMontgomeryPoint256Hex

;input
; rcx - pointer to ecp256
Console_WriteECProjectiveMontgomeryPoint256Hex:
virtual at rsp
  label .locals_start
    .value rq 1
    .rsi_backup rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.value], rcx
        mov     [.rsi_backup], rsi

        mov     rsi, .prefix
        call    Console_WriteString

        mov     rcx, [.value]
        call    Console_WriteUInt256Hex

        mov     rsi, .y
        call    Console_WriteString
        mov     rcx, [.value]
        add     rcx, ECProjectiveMontgomeryPoint256.y
        call    Console_WriteUInt256Hex

        mov     rsi, .z
        call    Console_WriteString
        mov     rcx, [.value]
        add     rcx, ECProjectiveMontgomeryPoint256.z
        call    Console_WriteUInt256Hex

        mov     rsi, .suffix
        call    Console_WriteString

        mov     rsi, [.rsi_backup]

        add     rsp, .locals_end - .locals_start
        ret
.prefix db '(X: ', 0
.y db ', Y: ', 0
.z db ', Z: ', 0
.suffix db ')', 0

end if