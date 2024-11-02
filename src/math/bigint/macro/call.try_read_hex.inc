if ~ definite __bi_try_read_hex

__bi_try_read_hex equ 0

macro CallBiTryReadHex bits {
    if bits = 64
      call    bi_try_read_hex_64
    else if bits = 128
      call    bi_try_read_hex_128
    else if bits = 192
      call    bi_try_read_hex_192
    else if bits = 256
      call    bi_try_read_hex_256
    else if bits = 512
      call    bi_try_read_hex_512
    else
      display 'unknown CallBiTryReadHex '
      DisplayDec bits
      display 13, 10
      err 
    end if
}

end if