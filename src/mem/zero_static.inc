macro MemoryZeroStatic destination, count {
        repeat  (count) shr 3
        mov     qword [destination + (% - 1) * 8], 0
        end repeat
}