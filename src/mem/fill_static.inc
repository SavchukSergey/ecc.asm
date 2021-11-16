macro MemoryFillStatic destination, value, count {
        repeat  (count) shr 3
        mov     qword [destination + (% - 1) * 8], (value shl 56) or (value shl 48) or (value shl 40) or (value shl 32) or (value shl 24) or (value shl 16) or (value shl 8) or (value shl 0)
        end repeat

        repeat  ((count) and 0x07) shr 2
        mov     dword [destination + ((count) and 0xfffffff8) + (% - 1) * 4], (value shl 24) or (value shl 16) or (value shl 8) or (value shl 0)
        end repeat

}