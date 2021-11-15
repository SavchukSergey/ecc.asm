macro MemoryCopyStatic source, destination, count {
        push    rdx

        repeat  (count) shr 3
        mov     rdx, qword [source + (% - 1) * 8]
        mov     qword [destination + (% - 1) * 8], rdx
        end repeat

        repeat  ((count) and 0x07) shr 2
        mov     edx, [source + ((count) and 0xfffffff8) + (% - 1) * 4]
        mov     [destination + ((count) and 0xfffffff8) + (% - 1) * 4], edx
        end repeat

        pop     rdx
}