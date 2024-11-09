bind_thread_to_single_core:
virtual at rsp
  label .locals_start
  .affinity_mask rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
	sub      rsp, .locals_end - .locals_start

    mov      qword [.affinity_mask], 0x1

 	xor      rdi, rdi 	; pid
	mov      rsi, 8     ; mask length
	lea      rdx, [.affinity_mask]
	mov      rax, 203	; sys_sched_setaffinity
	syscall

	add      rsp, .locals_end - .locals_start
	ret