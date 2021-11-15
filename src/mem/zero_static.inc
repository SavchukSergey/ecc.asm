macro MemoryZeroStatic destination, count {
        repeat  (count) shr 3
        mov     qword [destination + (% - 1) * 8], 0
        end repeat

        repeat  ((count) and 0x07) shr 2
        mov     dword [destination + ((count) and 0xfffffff8) + (% - 1) * 4], 0
        end repeat

}