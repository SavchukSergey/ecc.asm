macro MemoryCopyStatic source, destination, count {
        push    rdx 

        repeat  count shr 3
        mov     rdx, [source + (% - 1) * 8]
        mov     [destination + (% - 1) * 8], rdx
        end repeat

        pop     rdx
}