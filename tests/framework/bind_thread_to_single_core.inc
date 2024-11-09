if TARGET_OS = 'WIN'
  include 'bind_thread_to_single_core.win.inc'
else if TARGET_OS = 'LINUX'
  include 'bind_thread_to_single_core.linux.inc'
end if
