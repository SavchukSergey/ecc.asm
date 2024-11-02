macro CallBiAssertEqualHex bits {
    if bits = 128
      call    bi_assert_equal_hex_128
    else if bits = 192
      call    bi_assert_equal_hex_192
    else if bits = 256
      call    bi_assert_equal_hex_256
    else if bits = 512
      call    bi_assert_equal_hex_512
    else
      display 'unknown CallBiTryReadHex '
      DisplayDec bits
      display 13, 10
      err 
    end if
}