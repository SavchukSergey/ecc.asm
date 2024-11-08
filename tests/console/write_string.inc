if TARGET_OS = 'WIN'
  include 'write_string.win.inc'
else if TARGET_OS = 'LINUX'
  include 'write_string.linux.inc'
end if
