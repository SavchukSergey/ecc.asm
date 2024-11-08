if TARGET_OS = 'WIN'
  include 'write_char.win.inc'
else if TARGET_OS = 'LINUX'
  include 'write_char.linux.inc'
end if
