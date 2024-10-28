include '../../src/macro/align.inc'
;THREAD_ALL_ACCESS = 0x001F03FF

bind_thread_to_single_core:
virtual at rsp
  label .locals_start
  .shadow rq 4
  .thread_handle rq 1
  .processor_number rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
	sub     rsp, .locals_end - .locals_start

	call	[GetCurrentThread]
	mov		[.thread_handle], rax

	call	[GetCurrentProcessorNumber]
	mov		[.processor_number], rax

	mov		rcx, [.processor_number]
	mov		rdx, 1
	shl		rdx, cl
	mov		rcx, [.thread_handle]
	call	[SetThreadAffinityMask]

	add     rsp, .locals_end - .locals_start
	ret